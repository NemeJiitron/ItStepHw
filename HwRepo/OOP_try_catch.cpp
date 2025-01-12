#include <iostream>
#include "Stack.h"


int transmute(const char* str)
{
	int size = strlen(str);
	int i = size - 1;
	int num = 0;
	long long cap = 0;
	while (i >= 0)
	{
		switch (str[i])
		{
		case 48:
			cap = num * 10;
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += cap;
			break;
		case 49:
			cap = num + pow(10, size - (i + 1));
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += pow(10, size - (i + 1));
			break;
		case 50:
			cap = num + (2 * pow(10, size - (i + 1)));
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += (2 * pow(10, size - (i + 1)));
			break;
		case 51:
			cap = num + (3 * pow(10, size - (i + 1)));
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += (3 * pow(10, size - (i + 1)));
			break;
		case 52:
			cap = num + (4 * pow(10, size - (i + 1)));
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += (4 * pow(10, size - (i + 1)));
			break;
		case 53:
			cap = num + (5 * pow(10, size - (i + 1)));
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += (5 * pow(10, size - (i + 1)));
			break;
		case 54:
			cap = num + (6 * pow(10, size - (i + 1)));
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += (6 * pow(10, size - (i + 1)));

			break;
		case 55:
			cap = num + (7 * pow(10, size - (i + 1)));
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += (7 * pow(10, size - (i + 1)));
			break;
		case 56:
			cap = num + (8 * pow(10, size - (i + 1)));
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += (8 * pow(10, size - (i + 1)));
			break;
		case 57:
			cap = num + (9 * pow(10, size - (i + 1)));
			if (cap > INT_MAX)
			{
				throw std::exception("Error. Num is too big for int");
			}
			num += (9 * pow(10, size - (i + 1)));
			break;
		default:
			throw std::exception("Incorrect input");
		}
		i--;
	}
	return num;
}


int main()
{
	try
	{
		std::cout << transmute("99314432") << std::endl;
		
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
	try 
	{
		Stack<int> stack(5);
		/*stack.Pop();*/
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
		stack.Push(1);
	}
	catch (const std::exception& ex2)
	{
		std::cout << ex2.what();
	}

	return 0;
}