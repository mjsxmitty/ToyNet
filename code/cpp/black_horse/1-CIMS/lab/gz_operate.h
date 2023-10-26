
#ifndef __GZ_OPERATE_HPP__
#define __GZ_OPERATE_HPP__

#include <string>
#include "gz_person.h"

void AddPerson(AddressBooks* abs);

void ShowPerson(AddressBooks* abs);

void DeletePerson(AddressBooks* abs);

void FindPerson(AddressBooks* abs);

void ModifyPerson(AddressBooks* abs);

void CleanPerson(AddressBooks* abs);

int IsExist(AddressBooks* abs, std::string name);

#endif // __GZ_OPERATE_HPP__
