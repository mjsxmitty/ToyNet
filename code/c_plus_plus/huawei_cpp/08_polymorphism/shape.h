
#ifndef __HUAWEI_CHAPTER_08_POLYMORPHISM_SHAPE_H__
#define __HUAWEI_CHAPTER_08_POLYMORPHISM_SHAPE_H__

class Shape
{
public:
    Shape(int x, int y) : x_(x), y_(y) {}
    virtual ~Shape(){}
public:
    virtual void Draw() = 0;
protected:
    int     x_;
    int     y_;
};

class Circle : public Shape
{
public:
    Circle(int x, int y, int r) : Shape(x ,y), r_(r) {}
    ~Circle(){}
public:
    void Draw();
protected:
    int     r_;
};


class Rect : public Shape
{
public:
    Rect(int x, int y, int len, int wid) : Shape(x ,y), len_(len), wid_(wid) {}
    ~Rect(){}
private:
    void Draw();
protected:
    int     len_;
    int     wid_;
};

#endif // __HUAWEI_CHAPTER_08_POLYMORPHISM_SHAPE_H__
