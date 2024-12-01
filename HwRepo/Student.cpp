#include "Student.h"
#include <iostream>

Student::Student(char* name, char* dateOfB, Contact contact, College college)
	:_contact(contact), _college(college)
{
	_name = new char[strlen(name)];
	strcpy_s(_name, strlen(name), name);
	_dateOfB = new char[strlen(dateOfB)];
	strcpy_s(_dateOfB, strlen(dateOfB), dateOfB);
}

Student::Student(Student&& other)
	: _contact(std::move(other._contact)), _college(std::move(other._college))
{
	_name = other._name;
	_dateOfB = other._dateOfB;
}


Student::~Student()
{
	delete[] _name;
	delete[] _dateOfB;
}


