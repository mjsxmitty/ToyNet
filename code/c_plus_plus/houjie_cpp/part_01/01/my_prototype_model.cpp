
#include <iostream>
#include <vector>
#include <string>

#include "my_prototype_model.h"

std::vector<Fruit*> Fruit::fruit_types_;
int Fruit::num_types_ = 0;

/**
 * 子类的默认构造函数自动调用
 * 子类的static会自动调用默认构造函数
 * 后续的Clone不会调用此函数
 * 只有新创建子类的实例的时候才会调用
*/
void Fruit::AddFruitType(Fruit *fruit)
{
    ++num_types_;
    fruit_types_.push_back(fruit);
}

Fruit* Fruit::FindAndClone(std::string type)
{
    for (int i = 0; i < num_types_; i++) {
        if (fruit_types_[i]->ReturnType() == type) {
            return fruit_types_[i]->Clone();
        }
    }
    
    return nullptr;
}


Apple   Apple::apple_;
int     Apple::counts_ = 0;


Apple::Apple()
{
    std::cout << "create new Apple type obj." << std::endl;
    AddFruitType(this);
}

Apple::Apple(int i)
{
    std::cout << "create a new Apple obj." << std::endl;
    id_ = ++counts_;
}

void Apple::PrintObj()
{
    std::cout << "Apple obj, No: " << id_ << std::endl;
}

std::string Apple::ReturnType() const 
{
    return "apple";
}

Fruit* Apple::Clone() 
{
    return new Apple(1);
}



Orange  Orange::orange_;
int     Orange::counts_ = 0;


Orange::Orange()
{
    std::cout << "create new Orange type obj." << std::endl;
    AddFruitType(this);
}

Orange::Orange(int i)
{
    std::cout << "create a new Orange obj." << std::endl;
    id_ = ++counts_;
}

void Orange::PrintObj()
{
    std::cout << "Orange obj, No: " << id_ << std::endl;
}

std::string Orange::ReturnType() const 
{
    return "orange";
}

Fruit* Orange::Clone() 
{
    return new Orange(1);
}

