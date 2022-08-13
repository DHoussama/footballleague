
#include "human.h"


human::human()
{
	name = " ";
	age = 0;
	basesalary = 0;
}

human::human(const human& x)
{
	name = x.name;
	age = x.age;
	basesalary = x.basesalary;
}

void human::print()
{
	cout << "The name is " << name << " ///The age is " << age <<  " ///The basesalary is " << basesalary ;
	
}
