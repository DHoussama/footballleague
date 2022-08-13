#ifndef COACH_H
#define COACH_H

#include <iostream>
#include <string>
using namespace std;
#include "human.h"
#include "player.h"
#include "human.h"
#include "coach.h"

class coach : public human {
	int specialcoachsalary;
	int experience;
public:
	coach() : human(), specialcoachsalary(0), experience(0) {};
	~coach() {};
	coach(string x, int a, int b, int c,int l ) : human( x,  a,  b), specialcoachsalary(c),experience(l) {};
	string getname() { return human::getname(); }
	int getage() { return human::getage(); }

	int getbasesalary() { return human::getbasesalary(); }
	// display the total salary which is basesalary + specialsalary.
	int displaysalary();
	int getexperience() { return experience; };
	void print();



};
#endif /*COACH_H */#pragma once
#pragma once
