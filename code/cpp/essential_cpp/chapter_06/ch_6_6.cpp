
#include <iostream>

#include "fibonacci_ver3.h"
#include "num_sequence_ver3.h"
#include "num_sequence_ver4.h"

using namespace std;

void fibonacci(int pos, std::vector<int> &seq)
{
    if (seq.empty())
    {
        seq.push_back(1);
        seq.push_back(1);
    }

    if(seq.size() <= pos)
    {
        int ix = seq.size();
        int n2 = seq[ix - 2];
        int n1 = seq[ix - 1];

        for ( ; ix < pos; ++ix)
        {
            int elem = n1 + n2;
            seq.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}

int main()
{
    {
        using namespace chapter_06::ver3;
        Fibonacci<8>        fib1;
        Fibonacci<8, 8>     fib2;
        Fibonacci<12, 8>    fib3;

        cout << "fib1: " << fib1 << endl;
        cout << "fib2: " << fib2 << endl;
        cout << "fib3: " << fib3 << endl;
    }

    {
        using namespace chapter_06::ver4;
        NumSequence<fibonacci> nf1(1);
        NumSequence<fibonacci> nf2(12, 1);
        cout << "nf1: " << nf1 << endl;
        cout << "nf2: " << nf2 << endl;
    }

    return 0;
}
