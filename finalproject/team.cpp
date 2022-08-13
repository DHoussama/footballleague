#include "team.h"
#include <iostream>
using namespace std;
#include <string>
#include "league.h"

team::team()
{
	
		name = "";
		yearoffoundation = 0;
		nofhumans = 0;
        points = 0;
	
}

team::team(const team& h)
{
	      name = h.name;
	     yearoffoundation = h.yearoffoundation;
		 nofhumans = h.nofhumans;
	
		  points = h.points;

}

team::~team()
{
	 name = "";
     yearoffoundation=0;
	 nofhumans=0;
	 points=0;

}


const bool& team::operator>(const team& a) const
{
	if (points > a.points) {
		return true;
	}
	else {
		return false;
	}
}

const bool& team::operator==(const team& a) const
{
	if (points == a.points) {
		return true;
	}
	else { return false; }
}


std::ostream& operator<<(std::ostream& os, const team& v)
{
	os <<"Name of team " <<" : " << v.name << endl;
	os << "year of foundation " << " : " << v.yearoffoundation <<  endl;
	os << "number of humans " << " : " << v.nofhumans << endl;
	os << "number of points "  << " : " << v.points <<  endl ;

	os << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is,  team& v)
{
	cout << "Create team " << endl;
	cout << "write the name of your team: ";
	is >> v.name;
	cout << endl;
	cout << "write the yearoffoundation:";
	is >> v.yearoffoundation;
	cout << endl;
	cout << "write nofhumans";
	is >> v.nofhumans;
	cout << endl;
	cout << "write the points :";
	is >> v.points;
	cout << endl;

	return is;
}


