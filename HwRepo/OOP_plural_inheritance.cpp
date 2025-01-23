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
		virtual void Show();
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

void Figure::Show()
{
	std::cout << "Figure color: " << _color << std::endl;
}


class Rect : public virtual Figure
{
protected:
	size_t width;
	size_t height;
public:
	Rect();
	Rect(const char* color,  size_t w, size_t h);
	~Rect();
	void Show();
private:

};

Rect::Rect() : Figure()
{
	width = 0;
	height = 0;
}

Rect::Rect(const char* color, size_t w, size_t h) : Figure(color)
{
	width = w;
	height = h;
}

Rect::~Rect()
{
}

void Rect::Show()
{
	Figure::Show();
	std::cout << "Rect h: " << height << ". Width: " << width << std::endl;
}


class Circle : public virtual Figure
{
protected:
	size_t radius;
public:
	Circle();
	Circle(const char* color, size_t r);
	~Circle();
	void Show();

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

void Circle::Show()
{
	Figure::Show();
	std::cout << "Circle r: " << radius << std::endl;
}

class InscribedCircle : public virtual Circle, public virtual Rect
{
public:
	InscribedCircle();
	InscribedCircle(const char* color, size_t w, size_t h, size_t r);
	~InscribedCircle();
	void Show();

private:

};

InscribedCircle::InscribedCircle() : Circle(), Rect(), Figure::Figure()
{
}

InscribedCircle::InscribedCircle(const char* color, size_t w, size_t h, size_t r) : Rect(color, w, h), Circle(color, r), Figure::Figure(color)
{
}

InscribedCircle::~InscribedCircle()
{
}

void InscribedCircle::Show()
{
	Circle::Show();
	Rect::Show();
}


template<typename T> 
class base {
public:
	base();
	base(T v1, T v2);
	void Show();
protected:
	T val1;
	T val2;
};

template<typename T>
base<T>::base() : val1(0), val2(0)
{
}

template<typename T>
base<T>::base(T v1, T v2) : val1(v1), val2(v2)
{
}


template<typename T>
void base<T>::Show()
{
	std::cout << "Val1 - " << val1 << ". Val2 - " << val2 << std::endl;
}

template<typename T>
class child : base<T> {
public:
	child();
	child(T v1, T v2, T v3, T v4);
	void Show();
protected:
	T val3;
	T val4;
};

template<typename T>
child<T>::child() : base<T>(), val3(0), val4(0)
{
}

template<typename T>
child<T>::child(T v1, T v2, T v3, T v4) : base<T>(v1, v2), val3(v3), val4(v4)
{
}


template<typename T>
void child<T>::Show()
{
	base<T>::Show();
	std::cout << "Val3 - " << val3 << ". Val4 - " << val4 << std::endl;
}

template<typename T>
class child2 : child<T> {
public:
	child2();
	child2(T v1, T v2, T v3, T v4, T v5, T v6);
	void Show();
protected:
	T val5;
	T val6;
};

template<typename T>
child2<T>::child2() : child<T>(), val5(0), val6(0)
{
}

template<typename T>
child2<T>::child2(T v1, T v2, T v3, T v4, T v5, T v6) : child<T>(v1, v2, v3, v4), val5(v5), val6(v6)
{
}


template<typename T>
void child2<T>::Show()
{
	child<T>::Show();
	std::cout << "Val5 - " << val5 << ". Val6 - " << val6 << std::endl;

}


void func(Figure& f)
{
	f.Show();
}

int main()
{
	InscribedCircle rectcircle("Red", 20, 30, 15);
	rectcircle.Show();
	std::cout << std::endl;
	Rect rectangle;
	Circle circ;
	func(rectangle);
	std::cout << std::endl;
	func(circ);
	std::cout << std::endl;
	func(rectcircle);

	/*child2<double> test(1, 2, 3, 4, 5, 6);
	test.Show();*/
	return 0;
}

