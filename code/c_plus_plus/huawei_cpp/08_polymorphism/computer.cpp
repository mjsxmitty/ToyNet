#include "computer.h"



void Computer::Work()
{
    cpu->run();
    disk->run();
    mem->run();
}
