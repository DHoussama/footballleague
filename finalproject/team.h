#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
using namespace std;

class team  {

	string name;
	int yearoffoundation;
	int nofhumans;
	mutable int points;

   public :
	   team();
       team(string x, int a, int b, int d) : name(x), yearoffoundation(a), nofhumans(b),  points(d) {}
       team(const team& x);
	   ~team();
	   int numberofplayers() const { return nofhumans; }
       int thepoints() const { return points; }
       string getname()const { return name; }
	   // if a team wins we add to its points 3 points
       void get3points() const { points = points + 3; };
	   //if the match is draw then we add only one point to both teams
	   void get1points() const { points = points + 1; };
	   // two operators to compare two teams 
        const bool& operator >(const team&a)const;
	   const bool& operator ==(const team& a)const;
	   // global friend operator for printing  data
	   friend std::ostream& operator << (std::ostream& os, const team& v);
	   friend std::istream& operator >> (std::istream& is,  team& v);


};

// global function for printing  data
std::ostream& operator << (std::ostream& os, const team& v);
std::istream& operator >> (std::istream& is,  team& v);
#endif /*TEAM_H */#pragma once
