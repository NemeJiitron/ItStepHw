#pragma once
#include "College.h"
class Student
{
private:
	char* _name;
	char* _dateOfB;
	Contact _contact;
	College _college;
public:
	Student(char* name, char* dateOfB, Contact& contact, College& college);
	Student(Student&& other) noexcept;
	~Student();
	void Show();
};

