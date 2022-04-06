
#ifndef __MY_PROTOTYPE_MODEL_H__
#define __MY_PROTOTYPE_MODEL_H__

#include <vector>
#include <string>
#include <iostream>

const int NUM = 8;

// enum FruitType 
// {
//     APPLE,
//     ORANGE
// };

class Fruit
{
public:
	static Fruit* FindAndClone(std::string);	//根据子类型返回类型实例
	virtual void PrintObj() = 0;
protected:
	virtual void AddFruitType(Fruit*);		//子类的构造函数调用
	virtual Fruit* Clone() = 0;				//返回子类的具体实例
	virtual std::string ReturnType() const = 0;
private:
	static std::vector<Fruit*> 	fruit_types_;
	static int					num_types_;
};


class Apple : public Fruit
{
public:
	void PrintObj();
	std::string ReturnType() const;
	Fruit* Clone();
private:
	Apple();
protected:
	Apple(int i);
private:
	static int 		counts_;		//子类实例个数
	static Apple 	apple_;
	int				id_;
};


class Orange : public Fruit
{
public:
	void PrintObj();
	std::string ReturnType() const;
	Fruit* Clone();
private:
	Orange();
protected:
	Orange(int i);
private:
	static int 		counts_;		//子类实例个数
	static Orange 	orange_;
	int				id_;
};


#endif //__MY_PROTOTYPE_MODEL_H__