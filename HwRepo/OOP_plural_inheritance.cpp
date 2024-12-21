#include <iostream>
#include <string>

class Figure
{
	protected:
		std::string _color;
	public:
		Figure();
		Figure(const char* color);
		~Figure();
};

Figure::Figure()
{
	_color = "Black";
}

Figure::Figure(const char* color)
{
	_color = color;
}

Figure::~Figure()
{
}


class Square : virtual Figure
{
protected:
	size_t width;
public:
	Square();
	Square(const char* color,  size_t w);
	~Square();

private:

};

Square::Square() : Figure()
{
	width =	0;
}

Square::Square(const char* color, size_t w) : Figure(color)
{
	width = w;
}

Square::~Square()
{
}


class Circle : virtual Figure
{
protected:
	size_t radius;
public:
	Circle();
	Circle(const char* color, size_t r);
	~Circle();

private:

};

Circle::Circle() : Figure()
{
	radius = 0;
}

Circle::Circle(const char* color, size_t r) : Figure(color)
{
	radius = r;
}

Circle::~Circle()
{
}

class InscribedCircle
{
protected:
	Square square;
	Circle circle;
public:
	InscribedCircle();
	InscribedCircle(const char* color, size_t h, size_t r);
	~InscribedCircle();

private:

};

InscribedCircle::InscribedCircle() : square(), circle()
{
}

InscribedCircle::InscribedCircle(const char* color, size_t h, size_t r) : square(color, h), circle(color, r)
{
}

InscribedCircle::~InscribedCircle()
{
}


int main()
{


	return 0;
}