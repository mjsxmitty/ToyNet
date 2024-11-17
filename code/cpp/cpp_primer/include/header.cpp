
#include "header.h"

int fcn() { return 1024; }

extern const int buf_size = fcn();
//extern const int buf_size = 1024;