
#include "common.h"
#include "num_sequence.h"

#include <ostream>
#include <vector>

namespace common
{
#if 0
bool FibonElem(int pos, int &elem)
{
    // 无效位置
    if (pos <= 0 || pos > 1024)
    {
        std::cerr << "invalid position: " << pos << std::endl;

        elem = 0;
        return false;
    }

    elem = 1;
    int val1 = 1, val2 = 1;

    for (int i = 3; i <= pos; i++)
    {
        elem = val2 + val1;
        val2 = val1;
        val1 = elem;
    }

    return true;
}
#endif

bool PrintFibon(int pos)
{
    if (pos <= 0 || pos > 1024)
    {
        std::cerr << "invalid position: " << pos
                    << std::endl;
        return false;
    }

    std::cout << "the fibonacci sequence for "
                << pos << " positions: \n\t";

    switch (pos)
    {
        default:
        case 2:
            std::cout << "1 ";
        case 1:
            std::cout << "1 ";
            break;
    }

    int elem;
    int val1 = 1, val2 = 1;
    for (int i = 3; i <= pos; i++)
    {
        elem = val1 + val2;
        val2 = val1;
        val1 = elem;
        std::cout << elem << (!(i % 10) ? "\n\t" : " ");
    }

    std::cout << std::endl;
    return true;
}

void Display(const std::vector<int> *vec, std::ostream *out)
{
    std::ostream &os = (out == 0) ? std::cout : *out;
    if (vec == 0)
    {
        os << "Display(): the vec point to 0.\n";
        return ;
    }

    for (unsigned int i = 0; i < vec->size(); i++)
        os << (*vec)[i] << ' ';

    os << std::endl;
}

void Display(const std::vector<int> &vec, std::ostream &out)
{
    for (unsigned int i = 0; i < vec.size(); i++)
        out << vec[i] << ' ';

    out << std::endl;
}

void Swap(int &val1, int &val2, std::ostream &out)
{
    out << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    out << "after swap: val1: " << val1
        << ", val2: " << val2 << std::endl;
}

void Swap(int &val1, int &val2, std::ostream *out)
{
    if (out != 0)
        (*out) << "swap ( " << val1 << ", " << val2 << " )\n";

    int temp = val1;
    val1 = val2;
    val2 = temp;

    if (out != 0)
        (*out) << "after swap: val1: " << val1
                << ", val2: " << val2 << std::endl;
}

void BubbleSort(std::vector<int> &vec, std::ostream &out)
{
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
        for (unsigned int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                out << "call swap()! position : " << i
                    << ", and position: " << j
                    << " swapping: " << vec[i]
                    << ", with: " << vec[j]
                    << std::endl;

                Swap(vec[i], vec[j], out);

                out << "after swap std::vector element: ";
                Display(vec, out);
            }
        }
    }
}

void BubbleSort(std::vector<int> *vec, std::ostream *out)
{
    if (vec == 0)
    {
        std::cout << "Bubble(): the point to vec is 0.\n";
        return ;
    }

    for (unsigned int i = 0; i < vec->size(); ++i)
    {
        for (unsigned int j = i + 1; j < vec->size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                if (out != 0)
                    *out << "call swap()! position : " << i
                        << ", and position: " << j << " swapping: "
                        << (*vec)[i] << ", with: " << (*vec)[j] << std::endl;


                Swap((*vec)[i], (*vec)[j], out);

                if (out != 0)
                {
                    *out << "after swap std::vector element: ";
                    Display(vec, out);
                }
            }
        }
    }
}

#if 0
const std::vector<int>* FibonSeq1(int size)
{
    static std::vector<int> elems;
    const int               max_elems = 1024;

    if (size <= 0 || size > max_elems)
    {
        std::cerr << "invalid size: " << size << std::endl;
        return 0;
    }

    for (int ix = elems.size(); ix < size; ++ix)
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 2] + elems[ix - 1]);

    return &elems;
}

#endif

const std::vector<int>* FibonSeq(int size)
{
    static std::vector<int>  elems;

    if (!IsSizeOk(size))
        return 0;

    for (int ix = elems.size(); ix < size; ++ix)
        if (ix == 0 || ix == 1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix - 2] + elems[ix - 1]);

    return &elems;
}

bool FibonElem(int size, int &elem)
{
    const std::vector<int> *pseq = FibonSeq(size);
    if (!pseq)
    {
        elem = 0;
        return false;
    }

    elem = (*pseq)[size - 1];
    return true;
}

void DisplayMsg(const std::string &msg)
{
    std::cerr << msg << std::endl;
}

void DisplayMsg(const std::string &msg, int size)
{
    std::cerr << msg << ", size: " << size << std::endl;
}

bool SeqElem(int size, int &elem, const std::vector<int>* (*seq_ptr)(int))
{
    const std::vector<int> *pseq = seq_ptr(size);
    if (!pseq)
    {
        elem = 0;
        DisplayMsg("oops: sequence ptr is point to null.");
        return false;
    }

    elem = (*pseq)[size - 1];
    return true;
}

}
