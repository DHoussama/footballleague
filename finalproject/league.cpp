#include "league.h"
#include <string>
#include "team.h"
using namespace std;




league::league(string ch, int y, int x,  team* n)
{
		name = ch;
		yearofstart = y;
		numberofteams = x;
		p = new team[x];
		for (int i = 0; i < numberofteams; i++) {
			p[i] = n[i];
		}
	

}

league::league(const league& theOther)
{
	name = theOther.name;
	yearofstart = theOther.yearofstart;
	numberofteams = theOther.numberofteams;

	p = new team[numberofteams];

	for (int i = 0; i < numberofteams; i++) {
		p[i] = theOther.p[i];

	}
}

void league::erase( int points)
{

	team* temp = new team[numberofteams - 1];
	for (int i = 0, j = 0; i < numberofteams; i++) {
		if (p[i].thepoints() != points) {
			*(temp+j) = p[i];
			j++;
		}

	}
	delete[] p;
	p = temp;
	numberofteams--;

}

void league::insert(const team& a)
{
	team* temp = new team[numberofteams + 1];

	for (int i = 0; i < numberofteams; i++) {
		temp[i] = p[i];
	}
	temp[numberofteams] = a;
	
	delete[]p;
	p = temp;
	numberofteams++;
}

void league::updaterank()
{
	int b = 0;
	while (b == 0) {
		b = 1;
		for (int i = 0; i < numberofteams-1; i++) {
			if (p[i+1] > p[i]) {
				team max = p[i];
				p[i] = p[i + 1];
				p[i + 1] = max;
				b = 0;
			}
		}
	}
}

void league::updatepointsofteams(team& a, int a1, team& b, int b1)
{
	if (a1 > b1) {
		a.get3points();
	}
	else if (a1 < b1) {
		b.get3points();
	}
	else {
		a.get1points();
		b.get1points();
	}
}


std::ostream& operator <<(std::ostream& os, const league& l)
{
	os << "Name of league " << " : " << l.name << endl;
	os << "yearofstart " << " : " << l.yearofstart << endl;
	os << "numberofteams " << " : " << l.numberofteams << endl;
	os << std::endl;
	/*	for (int i = 0; i < l.numberofteams; i++) {
			os << "Team" << " " << i <<" "<< l.p[i] << endl;
		}
		os << std::endl; */
		return os;
}