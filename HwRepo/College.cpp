#include "College.h"
#include <iostream>


College::College(Contact contactt, char* name)
	: _contact(contactt)
{
	_name = new char[strlen(name)];
	strcpy_s(_name, strlen(name), name);

}

College::College(College& other)
	: _contact(other._contact)
{
	_name = new char[strlen(other._name)];
	strcpy_s(_name, strlen(other._name), other._name);
}

College::College(College&& other) noexcept
	: _contact(std::move(other._contact))
{
	_name = new char[strlen(other._name)];
	strcpy_s(_name, strlen(other._name), other._name);
	other._name = nullptr;
}

College::~College()
{
	delete[] _name;
}
