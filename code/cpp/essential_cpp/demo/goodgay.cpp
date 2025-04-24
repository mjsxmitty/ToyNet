
#include "goodgay_build.h"

GoodGay::GoodGay()
{
	building = new Building;
}

GoodGay::~GoodGay()
{
	if(building!=NULL)
	{
		delete building;
		building = NULL;
	}

}

void GoodGay::visit1()
{
	cout << "好基友正在访问：" << building->sitting_room_ << endl;
	cout << "好基友正在访问：" << building->bed_room_ << endl;
}

void GoodGay::visit2()
{
	cout << "好基友正在访问：" << building->sitting_room_ << endl;
	//不是友元，会报错
//	cout << "好基友正在访问：" << building->m_BedRoom << endl;
}

