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

class Figure
{
protected:
	const float P = 3.14;
public:
	virtual float Area() = 0;
};

class Rectangle : public Figure
{
private:
	int height;
	int width;
public:
	Rectangle(int h, int w) {
		height = h;
		width = w;
	}
	float Area()
	{
		return height * width;
	}
};

class Cirlce : public Figure
{
private:
	int radius;
public:
	Cirlce(int r) {
		radius = r;
	}
	float Area()
	{
		return 3.14 * (radius * radius);
	}
};

class Triangle : public Figure
{
private:
	int cathetus1;
	int cathetus2;
	int hypotenuse;
public:
	Triangle(int c1, int c2, int h) {
		cathetus1 = c1;
		cathetus2 = c2;
		hypotenuse = h;
	}
	float Area()
	{
		return (cathetus1 * cathetus2) / 2;
	}
};

class Trapeze : public Figure
{
private:
	int height;
	int a;
	int b;
public:
	Trapeze(int h, int a, int b) {
		height = h;
		this->a = a;
		this->b = b;
	}
	float Area()
	{
		return height * ((a * b) / 2);
	}
};

int main()
{
	/*Employer* emplPtr;
	emplPtr = new President("Kanye West");
	emplPtr->Print();
	delete emplPtr;
	emplPtr = new Manager("Kanye");
	emplPtr->Print();
	delete emplPtr;
	emplPtr = new President("West");
	emplPtr->Print();
	delete emplPtr;
	return 0;*/

	Figure** arr = new Figure*[4];
	arr[0] = new Rectangle(4, 6);
	arr[1] = new Cirlce(10);
	arr[2] = new Triangle(4, 6, 10);
	arr[3] = new Trapeze(6, 8, 4);
	std::cout << arr[0]->Area() << " " << arr[1]->Area() << " " << arr[2]->Area() << " " << arr[3]->Area();
}

