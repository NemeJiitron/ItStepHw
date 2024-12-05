#include <iostream>

void GetChars(char* source)
{
	FILE* input;
	fopen_s(&input, source, "r");
	if (input)
	{
		fseek(input, 0, SEEK_END);
		int fileSize = ftell(input);
		fseek(input, 0, SEEK_SET);
		char* buf = new char[fileSize] {};
		fread(buf, sizeof(char), fileSize, input);
		int i = 0;
		int chars{};
		while (i < fileSize)
		{
			if (buf[i] != ' ' && buf[i] != '\n')
			{
				chars++;
			}
			i++;
		}
		std::cout << "Number of chars: " << chars << std::endl;
	}
	fclose(input);
}

void copyLinesMin(char* source, char* dest)
{
	FILE* input;
	FILE* output;
	fopen_s(&input, source, "r");
	fopen_s(&output, dest, "w");
	if (input && output)
	{
		fseek(input, 0, SEEK_END);
		int fileSize = ftell(input);
		fseek(input, 0, SEEK_SET);
		char* buf = new char[fileSize] {};
		fread(buf, sizeof(char), fileSize, input);
		int j = 0;
		for (int i = 0; i < fileSize; i++)
		{
			if (buf[i] == '\n')
			{
				fwrite(&buf[i] - j, sizeof(char), j, output);
				putc('\n', output);
				j = 0;
				continue;
			}
			j++;
		}
	}
	fclose(input);
	fclose(output);
}

void insertWord(char* source)
{
	FILE* input;
	fopen_s(&input, source, "r+");
	char word1[20];
	char word2[20];
	std::cout << "Word to find - ";
	gets_s(word1);
	int w1_size = strlen(word1);
	std::cout << "Word to insert - ";
	gets_s(word2);
	int w2_size = strlen(word2);
	if (input)
	{
		fseek(input, 0, SEEK_END);
		int fileSize = ftell(input);
		fseek(input, 0, SEEK_SET);
		char* buf = new char[fileSize] {};
		fread(buf, sizeof(char), fileSize, input);
		for (int i = 0; i < fileSize; i++)
		{
			if (buf[i] == ' ' && buf[i + 1] == word1[0])
			{
				bool iseql = true;
				for (int j = 0; j < w1_size; j++)
				{
					if (buf[i + 1 + j] != word1[j])
					{
						iseql = false;
						break;
					}
				}
				if (iseql)
				{
					fseek(input, i + 1, SEEK_SET);
					putc(' ', input);
					fwrite(word2, sizeof(char), w2_size, input);
					fwrite(&buf[i + w1_size + 1], sizeof(char), fileSize - (i + w1_size), input);
					break;
				}
			}
		}
	}
	fclose(input);
}

void countwords(char* source)
{
	FILE* input;
	fopen_s(&input, source, "r");
	char ch;
	std::cin >> ch;
	if (input)
	{
		fseek(input, 0, SEEK_END);
		int fileSize = ftell(input);
		fseek(input, 0, SEEK_SET);
		char* buf = new char[fileSize] {};
		fread(buf, sizeof(char), fileSize, input);
		int i = 0;
		int words{};
		while (i < fileSize)
		{
			if (buf[i] == ' ' && buf[i + 1] == ch)
			{
				words++;
			}
			i++;
		}
		if (buf[0] == ch)
		{
			words++;
		}
		std::cout << words;
	}
	fclose(input);
}

int main()
{
	char source[] = "2_input.txt";
	char dest[] = "2_output.txt";

	countwords(source);

	return 0;
}