
#ifndef __ESSENTIAL_CPP_CHAPTER_03_H__
#define __ESSENTIAL_CPP_CHAPTER_03_H__

#include <vector>
#include <functional>
#include <iostream>

void Chapter_03();

void Practice_3_1();
void Practice_3_6();
void Practice_3_9();

void Homework_3_1();
void Homework_3_2();
void Homework_3_3();
void Homework_3_4();

extern const int* FindVec(const std::vector<int> &vec, int val);

template <typename T>
const T* FindVer1(const std::vector<T> &vec, T &val)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == val)
            return &vec[i];
    
    return 0;
}

template <typename T>
const T* FindVer2(const T *array, int size, const T &val)
{
    if (!array || size < 1)
        return 0;

    for (int ix = 0; ix < size; ix++)
        if (array[ix] == val)
            return &array[ix];
            
    return 0;
}

template <typename T>
const T* FindVer3(const T *array, int size, const T &val)
{
    if (!array || size < 1)
        return 0;

    for (int ix = 0; ix < size; ix++, ++array)
        if (*array == val)
            return array;
            
    return 0;
}

template <typename T>
const T* FindVer4(const T *first, const T *last, T &val)
{
    if (!first || !last)    
        return 0;

    for (;first != last; ++first)
        if (*first == val)
            return first;
    
    return 0;
}

template <typename T>
inline const T* Begin(const std::vector<T> &vec)
{
    return vec.empty() ? 0 : &vec[0];
}

template <typename T>
inline const T* End(const std::vector<T> &vec)
{
    return vec.empty() ? 0 : &vec[vec.size()];
}

template <typename T, typename Y>
T FindVer5(T first, T last, const Y &val)
{
    for (; first != last; ++first)
        if (val == *first)
            return first;

    return last;
}


std::vector<int> FilterVer1(const std::vector<int> &vec, int filter_val, bool (*pred)(int, int));
//std::vector<int> FilterVer2(const std::vector<int> &vec, int val, const std::less<int> &lt)

template <typename InputIterator, typename OutputIterator,
		  typename ElemType,      typename Comp>
OutputIterator FilterVer3( InputIterator first, InputIterator last,
             OutputIterator at, const ElemType &val, Comp pred )
{
    while (( first = find_if( first, last, bind2nd( pred, val ))) != last )
    {
        std::cout << "found val: " << *first << std::endl;
        *at++ = *first++;
    }

    return at;
}

template <typename InputIterator, typename OutputIterator,
		  typename ElemType,      typename Comp>
OutputIterator FilterVer4(InputIterator first, InputIterator last,
             OutputIterator at, const ElemType &val, Comp pred)
{
    //std::vector<ElemType> loca_vec(first, last);
    //sort(loca_vec.begin(), loca_vec.end());
    // sort(first, last);
    // auto iter = find_if(first, last, bind2nd(pred, val));
    
    // loca_vec.erase(iter, last);
    return first;
}
#endif //
