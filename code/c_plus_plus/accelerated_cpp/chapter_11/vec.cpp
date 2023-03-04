
#include "chapter11_vec.h"

#include <algorithm>

using std::max;

namespace chapter11
{
    template<typename T>
    void Vec<T>::Create()
    {
        data = avail = limit = 0;
    }

    template<typename T>
    void Vec<T>::Create(size_type n, const T &val)
    {
        data = Alloc.allocate(n);
        limit = avail = data + n;
        std::uninitialized_fill(data, limit, val);
    }

    template<typename T>
    void Vec<T>::Create(const_iterator i, const_iterator j)
    {
        data = Alloc.allocate(j - i);
        limit = avail = std::uninitialized_copy(i, j, data);
    }

    template<typename T>
    void Vec<T>::UnCreate()
    {
        if (data) {
            iterator it = avail;
            while (it != data) {
                Alloc.destroy(--it);
            }
            Alloc.destroy(data, limit - data);
        }
        data = avail = limit = 0;
    }

    template<typename T>
    void Vec<T>::Grow()
    {
        size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
        iterator new_data = Alloc.allocate(new_size);
        iterator new_avail = std::uninitialized_copy(data, avail, new_data);

        UnCreate();

        data = new_data;
        avail = new_avail;
        limit = new_data + new_size;
    }

    template<typename T>
    void Vec<T>::UncheckedAppend(const T &val)
    {
        Alloc.construct(avail++, val);
    }

    template<typename T>
    Vec<T>& Vec<T>::operator=(const Vec &rhs)
    {
        if (&rhs != this) {
            UnCreate();
            Create(rhs.Begin(), rhs.End());
        }
        return *this;
    }

    template<typename T>
    void Vec<T>::PushBack(const T &val)
    {
        if (avail == limit) {
            Grow();
        }
        
        UncheckedAppend();
    }
} // namespace chapter11
