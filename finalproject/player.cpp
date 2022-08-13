#include "player.h"
#include <iostream>
using namespace std;
#include <string>



int player::displaysalary()
{
	return specialplayersalary + getbasesalary();
}

void player::print()
{
	human::print();
	cout << "///the special player salary is " << specialplayersalary << "///his number of goals is" << goals << endl;
}
