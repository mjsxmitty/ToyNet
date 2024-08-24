

#include <iostream>

class MyClass
{
public:
    void ShowClassName() {
        std::cout << " My Class " << std::endl;
    }

    void ShowClassNum(){
        if (this == NULL){
            return ;
        }
        std::cout << "num: " << m_int << std::endl;
    }
private:
    int m_int = 100;
};

void testClass(){
    MyClass *p = NULL;
    p->ShowClassName();
    p->ShowClassNum();
}