#include <iostream>
#include "Contact.h"

int main()
{

	char pnum[] = "099090";
	char cntry[] = "Ukr";
	char city[] = "Odesa";
	Contact matt(pnum, cntry, city);
	matt.Show();

	char pnum2[] = "90803";
	char cntry2[] = "Greece";
	Contact Stiu(pnum2, cntry2);
	Stiu.Show();

	char pnum3[] = "099090";
	Contact jo(pnum3);
	jo.Show();
}