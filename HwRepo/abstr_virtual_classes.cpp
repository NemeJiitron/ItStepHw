#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>

class Shape
{
public:
	Shape() {};
	virtual void Show() = 0;
	virtual void Save(const char* filename) = 0;
	virtual void Save(std::fstream& stream) = 0;
	virtual void Load(const char* filename) = 0;
	virtual void Load(std::fstream& stream) = 0;
	~Shape() {};

private:

};

class Square : virtual public Shape
{
private:
	int width;
public:
	Square(int w)
		:Shape(), width(w){};
	void Show() {
		std::cout << "Square: " << std::endl;
		std::cout << "Width - " << width << std::endl;
	};
	void Save(const char* filename) override {
		std::fstream stream(filename, std::ios::out);
		if (stream.is_open())
		{
			stream.write(reinterpret_cast<char*>(&width), sizeof(int));
		}
	};
	void Save(std::fstream& stream) override {
		if (stream.is_open())
		{
			stream.write(reinterpret_cast<char*>(&width), sizeof(int));
		}
	};
	void Load(const char* filename) override {
		std::fstream stream(filename, std::ios::in);
		if (stream.is_open())
		{
			width = 0;
			stream.read(reinterpret_cast<char*>(&width), sizeof(int));
		}
	};
	void Load(std::fstream& stream) override {
		width = 0;
		if (stream.is_open())
		{
			stream.read(reinterpret_cast<char*>(&width), sizeof(int));
		}
	};
	~Square() {};
};

class Rectangle : virtual public Shape
{
private:
	int height;
	int width;
	int position;
public:
	Rectangle(int h, int w, int pos)
		:Shape::Shape(), height(h), width(w), position(pos){};
	void Show() {
		std::cout << "Rect: " << std::endl;
		std::cout << "Height - " << height << std::endl;
		std::cout << "Width - " << width << std::endl;
		std::cout << "Position - " << position << std::endl;
	};
	void Save(const char* filename) override {
		std::fstream stream(filename, std::ios::app);
		if (stream.is_open())
		{
			stream.write(reinterpret_cast<char*>(&height), sizeof(int));
			stream.write(reinterpret_cast<char*>(&width), sizeof(int));
			stream.write(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};
	void Save(std::fstream& stream) override {
		if (stream.is_open())
		{
			stream.write(reinterpret_cast<char*>(&height), sizeof(int));
			stream.write(reinterpret_cast<char*>(&width), sizeof(int));
			stream.write(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};
	void Load(const char* filename) override {
		std::fstream stream(filename, std::ios::in);
		if (stream.is_open())
		{
			height = 0;
			width = 0;
			position = 0;
			stream.read(reinterpret_cast<char*>(&height), sizeof(int));
			stream.read(reinterpret_cast<char*>(&width), sizeof(int));
			stream.read(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};
	void Load(std::fstream& stream) override {
		if (stream.is_open())
		{
			height = 0;
			width = 0;
			position = 0;
			stream.read(reinterpret_cast<char*>(&height), sizeof(int));
			stream.read(reinterpret_cast<char*>(&width), sizeof(int));
			stream.read(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};
};

class Circle : virtual public Shape
{
private:
	int radius;
	int position;
public:
	Circle(int radius, int position)
		:Shape::Shape(), radius(radius), position(position){};
	void Show() {
		std::cout << "Circle: " << std::endl;
		std::cout << "Radius - " << radius << std::endl;
		std::cout << "Position - " << position << std::endl;
	};
	void Save(const char* filename) override {
		std::fstream stream(filename, std::ios::out);
		if (stream.is_open())
		{
			stream.write(reinterpret_cast<char*>(&radius), sizeof(int));
			stream.write(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};
	
	void Save(std::fstream& stream) override {
		if (stream.is_open())
		{
			stream.write(reinterpret_cast<char*>(&radius), sizeof(int));
			stream.write(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};

	void Load(const char* filename) override {
		std::fstream stream(filename, std::ios::in);
		if (stream.is_open())
		{
			radius = 0;
			position = 0;
			stream.read(reinterpret_cast<char*>(&radius), sizeof(int));
			stream.read(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};

	void Load(std::fstream& stream) override {
		if (stream.is_open())
		{
			radius = 0;
			position = 0;
			stream.read(reinterpret_cast<char*>(&radius), sizeof(int));
			stream.read(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};
	
};

class Ellipse : virtual public Shape
{
private:
	int height;
	int width;
	int position;
public:
	Ellipse(int h, int w, int pos)
		:Shape::Shape(), height(h), width(w), position(pos) {};

	void Show() {
		std::cout << "Ellipse: " << std::endl;
		std::cout << "Height - " << height << std::endl;
		std::cout << "Width - " << width << std::endl;
		std::cout << "Position - " << position << std::endl;
	};
	void Save(const char* filename) override {
		std::fstream stream(filename, std::ios::out);
		if (stream.is_open())
		{
			stream.write(reinterpret_cast<char*>(&height), sizeof(int));
			stream.write(reinterpret_cast<char*>(&width), sizeof(int));
			stream.write(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};

	void Save(std::fstream& stream) override {
		if (stream.is_open())
		{
			stream.write(reinterpret_cast<char*>(&height), sizeof(int));
			stream.write(reinterpret_cast<char*>(&width), sizeof(int));
			stream.write(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};

	void Load(const char* filename) override {
		std::fstream stream(filename, std::ios::in);
		if (stream.is_open())
		{
			width = 0;
			height = 0;
			position = 0;
			stream.read(reinterpret_cast<char*>(&height), sizeof(int));
			stream.read(reinterpret_cast<char*>(&width), sizeof(int));
			stream.read(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};

	void Load(std::fstream& stream) override {
		if (stream.is_open())
		{
			width = 0;
			height = 0;
			position = 0;
			stream.read(reinterpret_cast<char*>(&height), sizeof(int));
			stream.read(reinterpret_cast<char*>(&width), sizeof(int));
			stream.read(reinterpret_cast<char*>(&position), sizeof(int));
		}
	};

};



int main()
{
	/*
	Rectangle rect(10, 30, 15);
	rect.Show();
	rect.Save("sqr1.txt");
	Rectangle rect2(23, 100, 110);
	rect2.Show();
	rect2.Load("sqr1.txt");
	rect2.Show();
	*/

	/*Square sqr(10);
	Rectangle rect(15, 7, 40);
	Circle circ(4, 30);
	Ellipse ell(11, 12, 13);
	Shape* arr[4]{ &sqr, &rect, &circ, &ell };
	arr[0]->Save("sqrArr.txt");
	std::fstream stream("sqrArr.txt", std::ios::app);
	arr[1]->Save(stream);
	arr[2]->Save(stream);
	arr[3]->Save(stream);*/

	Square sqr2(1);
	Rectangle rect2(51, 1, 4);
	Circle circ2(1, 3);
	Ellipse ell2(11, 21, 31);
	Shape* arr2[4]{ &sqr2, &rect2, &circ2, &ell2 };
	std::fstream stream2("sqrArr.txt", std::ios::in);
	arr2[0]->Load(stream2);
	arr2[1]->Load(stream2);
	arr2[2]->Load(stream2);
	arr2[3]->Load(stream2);
	arr2[0]->Show();
	arr2[1]->Show();
	arr2[2]->Show();
	arr2[3]->Show();

	return 0;
}

