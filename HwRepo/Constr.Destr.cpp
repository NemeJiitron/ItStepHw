#include "Student.h"

int main()
{
	char num[] = "09901902";
	char country[] = "Ukraine";
	char city[] = "Odesa";
	Contact college_cont(num, country, city);
	college_cont.Show();
	char col_name[] = "Tech College";
	College matt_college(college_cont, col_name);
	matt_college.Show();
	char st_name[] = "Matthew Matthewski Matthewic";
	char bdate[] = "01.01.1991";
	char st_num	[] = "999111111";
	Contact st_cont(st_num, country, city);
	Student st1(st_name, bdate, st_cont, matt_college);
	st1.Show();
	return 0;
}