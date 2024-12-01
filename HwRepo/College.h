#pragma once
#include "contact.h"
class College
{
private:
	Contact _contact;
	char* _name;
public:
	College(Contact contactt, char* name);
	College(College& other);
	College(College&& other) noexcept;
	~College();
};

