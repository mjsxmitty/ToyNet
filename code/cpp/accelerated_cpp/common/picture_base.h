
#ifndef _ACCELERATED_CPP_PICTURE_BASE_H__
#define _ACCELERATED_CPP_PICTURE_BASE_H__

#include <vector>
#include <string>
#include <iostream>

class PictureBase
{
    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type  wd_sz;

    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void dispaly(std::ostream &, ht_sz, bool) const = 0;
};

#endif // _ACCELERATED_CPP_PICTURE_BASE_H__
