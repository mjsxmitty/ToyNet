
#include "ch_02.h"
#include "who1.h"
#include "who2.h"
#include "cp.h"
#include "logout.h"

void ch_02(int argc, char** argv) {

    who1();

    //cp(argc, argv);

    who2();

    logout(argv[1]);
}
