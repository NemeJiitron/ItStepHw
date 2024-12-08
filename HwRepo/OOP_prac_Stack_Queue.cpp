#include "Stack.h"
#include "Queue.h"

int main()
{
	Stack<char> stk;
	stk.Push(40);
	stk.Push(67);
	std::cout << stk.Top() << std::endl;
	stk.Pop();
	std::cout << stk.Top() << std::endl;

	Queue que;
	que.Push(8);
	que.Push(10);
	std::cout << que.Top() << std::endl;
	que.Pop();
	std::cout << que.Top() << std::endl;

	return 0;
}