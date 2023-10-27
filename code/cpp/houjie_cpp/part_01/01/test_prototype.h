
#include <iostream>
#include <string>

#include "my_prototype_model.h"

#define NUM 3

std::string type[NUM] = {"apple", "orange", "apple"};


int TestPrototypeModel()
{
    Fruit* fruits[NUM];
    
    for (int i = 0; i < NUM; i++) {
        fruits[i] = Fruit::FindAndClone(type[i]);
    }

    for (int i = 0; i < NUM; i++) {
        fruits[i]->PrintObj();
        //std::cout << std::endl;
    }
    
    for (int i = 0; i < NUM; i++) {
        delete fruits[i];
    }
    
    return 0;
}


