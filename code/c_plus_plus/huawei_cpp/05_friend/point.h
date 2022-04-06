
#ifndef __HUAWEI_CHAPTER_05_FRIEND_POINT_H__
#define __HUAWEI_CHAPTER_05_FRIEND_POINT_H__

class Point;
class ManagerPoint
{
public:
    double Distance(const Point &a, const Point &b);
};

class Point
{
    friend double Distance(const Point &a, const Point &b);
    //friend double ManagerPoint::Distance(const Point &a, const Point &b);
    friend class ManagerPoint;  //友元类
public:
    Point(double xx, double yy);
public:
    void GetXY();
private:
    double  x, y;
};

double Distance(const Point &a, const Point &b);

class Point3D;
class Point2D
{
    friend class Point3D;
public:
    Point2D(double xx, double yy);
public:
    void Dis();
private:
    double  x, y;
};

class Point3D
{
public:
    Point3D(double xx, double yy, double zz);
    explicit Point3D(const Point2D &rhs);
public:
    void Dis();
private:
    double  x, y, z;
};

#endif // __HUAWEI_CHAPTER_05_FRIEND_POINT_H__
