#include "Stack.h"

bool isBracket(char ch)
{
	return ch == '(' || ch == '[' || ch == '{' || ch == ')' || ch == ']' || ch == '}';
}

void isBracketsCorrect(const char* str)
{
	Stack<char> stack;
	char ch = 0;
	int i = 0;
	bool breakpoint = false;
	size_t size = strlen(str);
	while (ch != ';' && i != size && breakpoint == false)
	{
		char ch = str[i];
		std::cout << "ch - " << ch << std::endl;
		if (isBracket(ch))
		{
			char ch2 = stack.Top();
			std::cout << "ch2 - " << ch2 << std::endl;
			switch (ch)
			{
			case ')':
				if (ch2 == '('){ stack.Pop(); }
				else { breakpoint = true; }
				break;
			case ']':
				if (ch2 == '['){ stack.Pop(); }
				else { breakpoint = true; }
				break;
			case '}':
				if (ch2 == '{'){ stack.Pop(); }
				else { breakpoint = true; }
				break;
			default:
				stack.Push(ch);
				break;
			}
		}
		i++;
		ch = str[i];
	}
	if (stack.GetSize() > 0)
	{
		std::cout << "incorrect";
		fwrite(str, sizeof(char), i, stdout);
	}
	else {
		std::cout << "correct";
	}
}


int main()
{
	isBracketsCorrect("() { {} []");

}