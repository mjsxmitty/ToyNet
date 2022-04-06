
#include <iostream>
#include <cmath>

#include "point.h"

using namespace std;

Point::Point(double xx, double yy) : x(xx), y(yy) {}

void Point::GetXY()
{
    cout << "( " << x << ", " << y << " )" << endl;
}

double Distance(const Point &a, const Point &b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

/* TODO 分离式编译探究 ...*/
double ManagerPoint::Distance(const Point &a, const Point &b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

Point2D::Point2D(double xx, double yy) : x(xx), y(yy) {}
void Point2D::Dis()
{
    cout << "( " << x << ", " << y << " )" << endl;
}

Point3D::Point3D(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}

Point3D::Point3D(const Point2D &rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = 0;
}

void Point3D::Dis()
{
    cout << "( " << x << ", " << y << ", " << z << " )" << endl;
}
