#include "Student.h"

int main()
{
	char num[] = "09901902";
	char country[] = "Ukraine";
	char city[] = "Odesa";
	Contact college_cont(num, country, city);
	college_cont.Show();

	return 0;
}