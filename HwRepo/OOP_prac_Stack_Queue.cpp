#include "Stack.h"

int main()
{
	Stack stk;
	stk.Push(8);
	stk.Push(10);
	std::cout << stk.Top() << std::endl;
	stk.Pop();
	std::cout << stk.Top() << std::endl;

	return 0;
}