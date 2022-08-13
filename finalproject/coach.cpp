#include "coach.h"
#include <iostream>
using namespace std;
#include <string>
#include "player.h"
#include "human.h"



int coach::displaysalary()
{
	return specialcoachsalary + getbasesalary() ;
}

void coach::print()
{
	human::print();
	cout << "///the special coach salary is " << specialcoachsalary << "///years of experience are " << experience << endl;
}
