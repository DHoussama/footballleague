#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;
#include "human.h"
#include "coach.h"

class player : public human {

	int specialplayersalary;
    int goals;
    public:
        player() : human(), specialplayersalary(0), goals(0) {};
        ~player() {};
       player(string x, int a, int b, int c,int l) : human( x,  a, b), specialplayersalary(c), goals(l) {}; 
       string getname() { return human::getname(); }
       int getage() { return human::getage(); }
       int getbasesalary() { return human::getbasesalary(); }     
       int getgoals() { return goals; };
       // display the total salary which is basesalary + specialsalary.
       int displaysalary();
        void print() ;





};
#endif /*PLAYER_H */#pragma once
#pragma once


