#pragma once
#include "College.h"
class Student
{
private:
	String _name;
	String _dateOfB;
	Contact _contact;
	College _college;
public:
	Student(String& name, String& dateOfB, Contact& contact, College& college);
	Student(Student&& other) noexcept;
	Student& operator=(Student&& other);
	~Student();
	void Show();
};

