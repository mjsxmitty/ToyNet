
#include "stack_ver1.h"

using namespace std;

namespace chapter_05
{

namespace ver1
{

ostream& operator<<(ostream &os, const Stack &rhs)
{
    rhs.print(os);
    return os;
}

}

}
