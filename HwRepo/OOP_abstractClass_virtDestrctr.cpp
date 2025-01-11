#include <iostream>

class Employer 
{
protected:
	std::string _name;
public:
	Employer(const char* name)
	{
		_name = name;
	}
	virtual void Print() = 0;

	virtual ~Employer() = 0;
};

void Employer::Print()
{
	std::cout << "Employer name: " << _name << std::endl;
}

Employer::~Employer()
{
	std::cout << "Employer dctor" << std::endl;
}

class President : public Employer
{
public:
	President(const char* name)
		:Employer(name){}
	void Print()
	{
		Employer::Print();
		std::cout << "Occupation: President" << std::endl;
	}
};

class Manager : public Employer
{
public:
	Manager(const char* name)
		:Employer(name) {}
	void Print()
	{
		Employer::Print();
		std::cout << "Occupation: Manager" << std::endl;
	}
};

class Worker : public Employer
{
public:
	Worker(const char* name)
		:Employer(name) {}
	void Print()
	{
		Employer::Print();
		std::cout << "Occupation: Worker" << std::endl;
	}
};

int main()
{
	Employer* emplPtr;
	emplPtr = new President("Kanye West");
	emplPtr->Print();
	delete emplPtr;
	emplPtr = new Manager("Kanye");
	emplPtr->Print();
	delete emplPtr;
	emplPtr = new President("West");
	emplPtr->Print();
	delete emplPtr;
	return 0;
}

