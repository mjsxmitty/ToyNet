#include<iostream>
using namespace std;

class Building;
class GoodGay
{
public:
	GoodGay();
	~GoodGay();
	void visit1();//让他可以访问Building的私有成员
	void visit2();//让他不可以访问Building的私有成员
private:
	Building* building;
};

class Building
{
	friend void GoodGay::visit1();
public:
	Building();
public:
	string sitting_room_;
private:
	string bed_room_;
};


