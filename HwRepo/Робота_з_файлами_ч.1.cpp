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
	if (input && output)
	{
		fseek(input, 0, SEEK_END);
		int fileSize = ftell(input) - 1;
		fseek(input, 0, SEEK_SET);
		char* buf = new char[fileSize] {};
		fread(buf, sizeof(char), fileSize, input);
		bool space = false;
		int spacepos = fileSize;
		int j = 0;
		std::cout << buf;
		for (int i = 0; i <= fileSize; i++)
		{
			
			if (buf[i] == '\n')
			{
				if (space == false)
				{
					spacepos = i;
				}
				space = false;
			}
			if (buf[i] == ' ') {
				space = true;
			}
			j++;
		}
		char tmp[] = "\n------------\n";
		fwrite(buf, sizeof(char), spacepos, output);
		fwrite(tmp, sizeof(char), 14, output);
		if (spacepos != fileSize) {
			fseek(input, 0, SEEK_END);
			fwrite(&buf[spacepos+1], sizeof(char), ftell(input) - spacepos, output);
		}
		delete[] buf;
	}
	fclose(input);
	fclose(output);
}

void Compare(char* source, char* source2)
{
	FILE* input;
	FILE* input2;
	fopen_s(&input, source, "r");
	fopen_s(&input2, source2, "r");
	
	if (input && input2)
	{
		fseek(input, 0, SEEK_END);
		int fileSize = ftell(input);
		fseek(input, 0, SEEK_SET);
		char* buf = new char[fileSize] {};
		fread(buf, sizeof(char), fileSize, input);
		fseek(input2, 0, SEEK_END);
		int fileSize2 = ftell(input2);
		fseek(input2, 0, SEEK_SET);
		char* buf2 = new char[fileSize2] {};
		fread(buf2, sizeof(char), fileSize2, input2);
		int i{}, j{};
		int tmp{}, tmp2{};
		bool isEql = true;
		while (buf[i] != EOF && buf2[j] != EOF)
		{
			if (isEql)
			{
				if (buf[i] != buf2[j])
				{
					isEql = false;
				}
			}
			if (buf[i] != '\n')
			{
				i++;
				tmp++;
			}
			if (buf2[j] != '\n')
			{
				j++;
				tmp2++;
			}
			if (buf[i] == '\n' && buf2[j] == '\n')
			{
				if (isEql)
				{
					std::cout << source << " index - " << i << std::endl;
					std::cout << source2 << " index - " << j << std::endl;
					std::cout << "Is Equal" << std::endl;
				}
				else
				{
					std::cout << source << " index - " << i << std::endl;
					fwrite(&buf[i - tmp], sizeof(char), tmp - 1, stdout);
					std::cout << std::endl;
					std::cout << source2 << " index - " << j << std::endl;
					fwrite(&buf2[j - tmp2], sizeof(char), tmp2 - 1, stdout);
					std::cout << std::endl;
				}
				i++;
				j++;

				tmp = tmp2 = 0;
				isEql = true;
			}
		}
	}
	fclose(input);
	fclose(input2);
}

bool isGolosna(char ch)
{
	switch (ch)
	{
	case 65:
	case 69:
	case 73:
	case 79:
	case 85:
	case 89:
	case 65 + 32:
	case 69 + 32:
	case 73 + 32:
	case 79 + 32:
	case 85 + 32:
	case 89 + 32:
		return true;
		break;
	default:
		return false;
		break;
	}
}

char* convertnumInchar(int num, int& size)
{
	int temp = num;
	while (temp != 0)
	{
		temp /= 10;
		size++;
	}
	size++;

	temp = num;
	char* ptr = new char[size];
	for (int i = size - 2; i >= 0; i--)
	{
		int lastnum = temp % 10;
		temp /= 10;
		switch (lastnum)
		{
		case 0:
			ptr[i] = 48;
			break;
		case 1:
			ptr[i] = 49;
			break;
		case 2:
			ptr[i] = 50;
			break;
		case 3:
			ptr[i] = 51;
			break;
		case 4:
			ptr[i] = 52;
			break;
		case 5:
			ptr[i] = 53;
			break;
		case 6:
			ptr[i] = 54;
			break;
		case 7:
			ptr[i] = 55;
			break;
		case 8:
			ptr[i] = 56;
			break;
		case 9:
			ptr[i] = 57;
			break;
		default:
			break;
		}
	}
	ptr[size - 1] = '\0';
	return ptr;
}

void GetInfo(char* source, char* dest)
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
		int i = 0;
		int strs{}, chars{}, golosn{}, prigolosn{}, nums{};
		while (i < fileSize)
		{
			if (buf[i] == '\n')
			{
				strs++;
			}
			else if (buf[i] == ' ') {}
			else
			{
				chars++;
				if (buf[i] >= 48 && buf[i] <= 57) {
					nums++;
				}
				else if (isGolosna(buf[i]))
				{
					golosn++;
				}
				else
				{
					prigolosn++;
				}
			}
			i++;
		}
		char tmp[] = "Number of strings - ";
		fwrite(tmp, sizeof(char), 21, output);
		int tmpsize = 0;
		char* ptrtmp = convertnumInchar(strs, tmpsize);
		fwrite(ptrtmp, sizeof(char), tmpsize, output);
		putc('\n', output);
		delete[] ptrtmp;
		char tmp2[] = "Number of chars - ";
		fwrite(tmp2, sizeof(char), 19, output);
		tmpsize = 0;
		ptrtmp = convertnumInchar(chars, tmpsize);
		fwrite(ptrtmp, sizeof(char), tmpsize, output);
		putc('\n', output);
		delete[] ptrtmp;
		char tmp3[] = "Number of nums - ";
		fwrite(tmp3, sizeof(char), 18, output);
		tmpsize = 0;
		ptrtmp = convertnumInchar(nums, tmpsize);
		fwrite(ptrtmp, sizeof(char), tmpsize, output);
		putc('\n', output);
		delete[] ptrtmp;
		char tmp4[] = "Number of golosn - ";
		fwrite(tmp4, sizeof(char), 20, output);
		tmpsize = 0;
		ptrtmp = convertnumInchar(golosn, tmpsize);
		fwrite(ptrtmp, sizeof(char), tmpsize, output);
		putc('\n', output);
		delete[] ptrtmp;
		char tmp5[] = "Number of prigolosn - ";
		fwrite(tmp5, sizeof(char), 23, output);
		tmpsize = 0;
		ptrtmp = convertnumInchar(prigolosn, tmpsize);
		fwrite(ptrtmp, sizeof(char), tmpsize, output);
		putc('\n', output);
		delete[] ptrtmp;
	}
}

int main()
{
	char source[] = "input.txt";
	char source2[] = "input2.txt";
	char dest[] = "output.txt";

	NoSpace(source, dest);

	return 0;
}