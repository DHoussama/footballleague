#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
using namespace std;


class human {

	string name;
	int age;
	int basesalary;

   public :
	   human();
	   ~human() {};
	   human(string x, int y, int z) : name(x), age(y), basesalary(z) {} 
	   human(const human& x);
	   virtual string getname() { return name;   }
	   virtual int getage() { return age; }
       virtual int getbasesalary() { return basesalary; }
	   virtual int displaysalary() { return basesalary; }
	   virtual void print() ;
	   


};
#endif /*HUMAN_H */#pragma once
#pragma once
