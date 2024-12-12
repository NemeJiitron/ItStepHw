#pragma once
#include "contact.h"
class College
{
private:
	Contact _contact;
	String _name;
public:
	College(Contact& contactt, String& name);
	College(College& other);
	College(College&& other) noexcept;
	College& operator=(College&& other);
	~College();
	void Show();
};

