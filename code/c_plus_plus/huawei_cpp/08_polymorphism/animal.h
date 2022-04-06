

#ifndef __HUAWEI_CHAPTER_08_POLYMORPHISM_ANIMAL_H__
#define __HUAWEI_CHAPTER_08_POLYMORPHISM_ANIMAL_H__


class Animal
{
public:
    Animal();
    virtual ~Animal();
public:
    virtual void Voice() = 0;
};

class Dog : public Animal
{
public:
    Dog();
    ~Dog();
public:
    void Voice();
};


class Cat : public Animal
{
public:
    Cat();
    ~Cat();
public:
    void Voice();
};
#endif // __HUAWEI_CHAPTER_08_POLYMORPHISM_ANIMAL_H__
