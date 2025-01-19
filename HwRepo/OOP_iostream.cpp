#include <ios>
#include <ostream> // output stream <<
#include <istream> // input stream >>
#include <iostream>
#include <fstream>
// #include <sstream>

// ����

int main()
{
	/*
	-------------------------------- �������� ������ ����� / ������ � �++ --------------------------------

	1. std::cout - �� ����������� ���� ������, ���� ��������������� ��� ����������� ������ ���������� � �������.
	³� ������������, �� ������, �� ���� ����������� � ���'�� ����� �� ����������� � �������/�������.
	�� ���� ��������� ��������������, ������� ����� ��������� ������ ����� ��'������ � ���� ��������.

	2. std::cerr - �� ����������� ���� ������ �������, ���� ��������������� ��� ���������� ��� �������
	�� ������������� ���������. ³� �� ������������, �� ������, �� ���� ������������ ������������� �� �������
	��� �������, �� ����� ���� �����������. �� �������, �� ����������� ��� ������� ������������� ������
	�� �� ����������� � ��� ���� ��������.

	3. std::clog - �� ����������� ���� ���������, ���� ��������������� ��� ��������� ����������.
	³� ������������ �� std::cout, ��� �������� ��������������� ��� ��������� ����������,
	��� �� � ��������� ��� ������ ��������.

	-------------------------------------------------------------------------------------------------------
	*/

	/*
	-------------------------------------------------------------------------------------------------------

	���������� �� ������� ���� ����� ����. � ��������� ������ �����/������ � �� ���� fstream (file stream).
	� ����� ���� ���������� ����� 3 �����:
	1. ifstream (input file stream) ����, ���� ������� �� ���������� ����� � �����.
	2. ofstream (output file stream) ����, ���� ������� �� ����� ����� � ����.
	3. fstream (file stream) ����, ���� � ��'�������� ���� ����� ifstream �� ofstream

	���� ifstream ���������� �� basic_istream, � ���� �� ��� ����� ��������� + �������
	����� ������ ��� ������ ��������� � ������� (��������� ����, is_open).

	��������� �������� � ������ ofstream. ³� ���������� �� basic_ostream.

	���� fstream ���������� �� ����� basic_iostream � ������ � ��� ��� �� ���� ���������� � ����� �� � ����.

	-------------------------------------------------------------------------------------------------------
	*/

	// ------------------------------ �� �������� ���� ? ------------------------------
	// � ������� ���� � ���� �������� � ����, ��� ���������� _Mystate. ���� �� ��� int � ������� �� ���� ������.
	// ���� ���� ���� ������ (������������ / � ���� ����� ���������) ��� ������� (���� ����� ��� ����������
	// ��� ��������� � ��� ���������). � ����� ���������� ���� � 4 �������� �������:
	// 1. std::ios::goodbit	-	������� �� ��, �� ����� ������ ���������. �������������� �� �������������
	//							��� ��������� ������.
	// 2. std::ios::eofbit	-	�������������� ���, ���� ��� ���������� ����� � ������ �� ������� ����� �����
	// 3. std::ios::failbit	-	�������������� ���, ���� �������� �������, ��� ����� ���������.
	//							�������� ���� ���� �� ���� ������ �� ���������� ���� �� - �� �����������
	//							���� � ����� �� ���� �� ���������� ������������ �������.
	// 4. std::ios::badbit	-	�������������� ���, ���� �������� �������, ��� �� ����� ���������.
	//							��������� ���� ���� �� ���� ��������� / ���������� ���� �� - �� ���������� ����,
	//							�� ���� ����������� ��������.
	// 
	// 
	// ��� ��������� ���� ������, ������� 4 ������: good(), eof(), fail(), bad().
	// ���� ���������� true, ���� ������������ ���� � 4 ���.
	//
	// ��� ������� �� �������� ��� ���:

	{
		std::cout << "Enter a number: ";
		int number;
		std::cin >> number;
		if (std::cin.good())
		{
			std::cout << "Your number = " << number << std::endl;
		}
		else
		{
			std::cout << "Oops. Something went wrong.\n";
			if (std::cin.bad())
			{
				std::cout << "cin.bad() = true.\n";
			}
			else if (std::cin.fail())
			{
				std::cout << "cin.fail() = true.\n";
			}
			else if (std::cin.eof())
			{
				std::cout << "cin.eof() = true.\n";
			}
		}
	}

	//system("pause");

	// ------------------------------ �� ���������� ���� ? ------------------------------
	// 1. ���� ���� ������ �� �������� std::ios::eofbit, �� � ������ �������
	//	  ���� ����� �� ���� ������ / ���������� � ��� ����� ���� ������� �� ������ �������.
	//    �������� �� �������� close �� ����.�� ���������� �������� ��� ����� � �������.
	//
	// 2. ���� ���� ������ �� �������� std::ios::failbit, ?� � ������ �������
	//    �� ������ �������� ��������� ����� clear(), ���� ���������� ���� ������
	//    ������ � �������� std::ios::goodbit, � ���� ��������� ���� ������� ignore(),
	//    ���� ������� ����� �������, ��� �� ������ �� � ����(��� �� ������ �� ���������).
	//    ϳ��� ����� ����� ���������� ������.
	// 
	// 3. ���� ���� ������ �� �������� std:: ios::badbit, �� � ������ �������
	//    �� ������ ��������� ����� clear(), ��� �� �� �������, �� ���� ����� ������� ��������� ���,
	//    ��� �� ����� �� �������������� � "�����������" ���������. ��� ������������� �����
	//    �� ��������� � �������, � ������� ����� (��� ������� � ������� ���).
	//
	// ������� ������������:
	{
		std::cout << "Enter a number: ";
		int number;
		std::cin >> number;
		while (!std::cin.good() && !std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Your entered incorrect value. Enter only integer number.\n";
			std::cin.ignore(LLONG_MAX, '\n');
			std::cout << "Enter a number: ";
			std::cin >> number;
		}
	}

	// ------------------------------ ������ �������� ����� ------------------------------
	// 1. std::ios::in		-	������� ���� ��� �������. ���� ����� �� ���� - ���� "��������".
	// 2. std::ios::out		-	������� ���� ��� ������. ���� ���� ���� - ���� ���� ���������(�������).
	//							���� �� ���� -  ���� �����������.
	// 3. std::ios::app		-	������� ���� ��� ������ � �����. ���� ����� �� ���� - �� �����������.
	// 4. std::ios::trunc	-	��������������� � ������� out. ����� ���� ����������, ����
	//							� ����� ���� ���� �� ��������.
	// 5. std::ios:ate		-	��������������� � ������ ��������. ������� �������� ���������� � ����� �����.
	// 6. std::ios::binary	-	������� ���� � �������� �����. ��������������� � ������ ��������.

	// ------------------------------ �������� �������� ------------------------------
	// 
	// peek() - ������� ��������� ������ ������� ������� ������� �� ������� ������
	// tellp(), tellg() - ���������� ������� ������� � ����.
	// 
	// tellg() - ������� ������� ������� �������.	(ifstream)
	// tellp() - ������� ������� ������� �����.	(ofstream)
	// 
	// 
	// ������ seekp()/seekg() ��������� ��� ���������: ������� ����� (origin), �� ������� �� �� (offset)
	// 
	// seekg() - ���������� ������� ������� �������.
	// seekp() - ���������� ������� ������� ������.
	// 
	// ������ �� ������� ������ �������:
	// 
	// ignore()		- �������� ������� ������� ������� � ������, ������� ������ �� n �������.
	// get()		- ���� ���� ������ � ���� ������ �� ���� ���� ������.
	// getline()	- ����� ����� � ���� ������ �� ��������� �����.
	// read()		- ���� n ����� � ���� ������ ������� �� n ����� ������.
	// putback()
	// unget()
	// 
	// ������ �� ������� ������ ������:
	// 
	// put()
	// write()
	//
	{
		//std::fstream fileStream()

		std::fstream fileStream("test.txt", std::ios::app);
		if (fileStream.is_open())
		{
			std::streampos tellp_pos = fileStream.tellp();

			std::string str("Hello");

			fileStream << str << " Hello";

			fileStream.seekp(std::ios::beg);
			fileStream.seekp(std::ios::cur);
			fileStream.seekp(std::ios::end);

			// fileStream.seekp(std::ios::beg).seekp(std::ios::cur).seekp(std::ios::end);

			fileStream.seekp(std::ios::beg, -5);
			fileStream.seekp(std::ios::cur, -3);
			fileStream.seekp(std::ios::end, -16);
		}
	}

	return 0;
}