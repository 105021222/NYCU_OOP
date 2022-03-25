#pragma once
#ifndef PORKBALL_H
#include "Student.h"
#include "Traffic.h"
#include <string>
using namespace std;

class PorkBall {
public:
	PorkBall(string name, float speed) {	
		this->name=name;
		this->speed=speed;
	}

	bool canRide(Student* student) {
		// use isTraffic to check whether the student can ride the porkball.
		return isTraffic(student);
	}

private:
	string name;
	float speed;
	bool isTraffic(Student* student) {
		// use dynamic casting to check whether the student is a Traffic student. 
		Traffic* p=dynamic_cast<Traffic*>(student);
		if(p){
			cout<<student->ID<<" can ride porkball "<<name<<" ,the speed is "<<speed<<endl;
		}
		else{
			cout<<"error bad_cast"<<endl;
		}
		return p;
	}
};
#endif
