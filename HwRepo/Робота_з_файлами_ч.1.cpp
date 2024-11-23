#include <iostream>
#include <direct.h>


bool isChar(int ch)
{
	return ch != ' ' && ch != ',' && ch != '.' && ch != '!' && ch != '?' && ch != EOF;
}

void copyWords(char* name1, char* name2)
{
	FILE* input;
	FILE* output;
	fopen_s(&input, name1, "r");
	fopen_s(&output, name2, "w");

	if (input && output)
	{
		fseek(input, 0, SEEK_END);
		size_t fileSize = ftell(input);
		rewind(input);
		if (fileSize)
		{
			char* buf = new char[fileSize] {};
			fread(buf, sizeof(char), fileSize, input);
			int count = 0;
			int wordsCursor = 0;
			const size_t buffer_size = fileSize;
			char* wbuf = new char[buffer_size];

			for (size_t i = 0; i <= fileSize; i++)
			{
				if (isChar(buf[i]))
				{
					count++;
				}
				else {
					if (count >= 7)
					{
						for (size_t j = 0; j < count; j++)
						{
							wbuf[wordsCursor++] = buf[i - (count)+j];
						}
						wbuf[wordsCursor++] = '\n';
					}
					count = 0;
				}
			}
			fwrite(wbuf, sizeof(char), wordsCursor, output);
			delete[] wbuf;
		}
	}
}

void copyLines(char* source, char* dest)
{
	FILE* input;
	FILE* output;
	fopen_s(&input, source, "r");
	fopen_s(&output, dest, "w");

	if (input && output)
	{
		fseek(input, 0, SEEK_END);
		int temp = ftell(input);
		fseek(input, 0, SEEK_SET);
		char* str = new char[temp];
		fread(str, sizeof(char), temp, input);
		fwrite(str, sizeof(char), temp, output);
		delete[] str;
	}
	fclose(input);
	fclose(output);
}

void copyLinesRev(char* source, char* dest)
{
	FILE* input;
	FILE* output;
	fopen_s(&input, source, "r");
	fopen_s(&output, dest, "w");
	char ch = 0;
	int temp = 0;
	int pos = 0;
	if (input && output)
	{
		fseek(input, 0, SEEK_END);
		int fileSize = ftell(input);
		fseek(input, 0, SEEK_SET);
		char* buf = new char[fileSize] {};
		fread(buf, sizeof(char), fileSize, input);
		int j = 0;
		for (int i = fileSize - 1; 0 <= i; i--)
		{
			if (buf[i] == '\n')
			{
				fwrite(&buf[i+1], sizeof(char), j, output);
				putc('\n', output);
				j = 0;
				continue;
			}
			j++;
		}
		fwrite(&buf[0], sizeof(char), j, output);
		delete[] buf;
	}
	fclose(input);
	fclose(output);
}

void NoSpace(char* source, char* dest)
{
	FILE* input;
	FILE* output;
	fopen_s(&input, source, "r");
	fopen_s(&output, dest, "w");
	char ch = 0;
	int temp = 0;
	int pos = 0;
	if (input && output)
	{
		fseek(input, 0, SEEK_END);
		int fileSize = ftell(input);
		fseek(input, 0, SEEK_SET);
		char* buf = new char[fileSize] {};
		fread(buf, sizeof(char), fileSize, input);
		bool space = false;
		int j = 0;
		for (int i = 0; i <= fileSize; i++)
		{
			
			if (buf[i] == '\n')
			{

				if (space)
				{
					fwrite(&buf[i - j], sizeof(char), j, output);
					putc('\n', output);
					j = 0;
					continue;
				}

			}
			j++;
		delete[] buf;
		}
		fwrite(&buf[(fileSize - j) + 1], sizeof(char), j, output);

		
	}
	fclose(input);
	fclose(output);
}

int main()
{
	char source[] = "input.txt";
	char dest[] = "output.txt";

	copyLinesRev(source, dest);

	return 0;
}