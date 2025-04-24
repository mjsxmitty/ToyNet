
#include "goodgay_build.h"

Building::Building()
{
	bed_room_ = "卧室1";
	sitting_room_ = "客厅1";
}


void test01()
{
	GoodGay gg;
	gg.visit1();
	gg.visit2();

}
int main() {

	test01();
	return 0;
}