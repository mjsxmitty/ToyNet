
#include "zg_base.h"

void ZGBase::Statmem()
{

}

void ZGDerived::f(const ZGDerived &derived_obj)
{
    ZGBase::Statmem();
    ZGDerived::Statmem();

    derived_obj.Statmem();
    Statmem();
}
