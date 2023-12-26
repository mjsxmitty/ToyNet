
#ifndef _ACCELERATED_CPP_PICTURE_H__
#define _ACCELERATED_CPP_PICTURE_H__

#include <vector>
#include <string>

#include "handle.hpp"
#include "picture_base.h"

class Picture
{
public:
    Picture(const std::vector<std::string> &vs = std::vector<std::string>());
private:
    Ptr<PictureBase> ppb_;
};

#endif // _ACCELERATED_CPP_PICTURE_H__
