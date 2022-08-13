#ifndef LEAGUE_H
#define LEAGUE_H

#include <iostream>
#include <string>
#include "team.h"
using namespace std;
class league {
	string name;
	int yearofstart;
	int numberofteams;
	team* p;
public :
	// Constructors, destructor
	league() { name = "" ; yearofstart = 0; numberofteams = 0; p = NULL; }
	league(string  ch, int y, int x, team*n);
	league(const league& theOther);
	~league() { numberofteams = 0;
	delete[]p; }
	// size() return the number of teams in the league
	int  size()const { return numberofteams; }
	// erases (deletes) the team with the given points ;
	void erase(int points);
    void insert(const team& a);
    void updaterank();
	int getnumberofteams() const { return numberofteams; }
	team team1(int x) {return p[x];}
	friend std::ostream& operator << (std::ostream& os, const league& l);
	void updatepointsofteams(team & a, int a1, team& b, int b1);

	



};

std::ostream& operator << (std::ostream& os, const league& l);

#endif /*LEAGUE_H */#pragma once