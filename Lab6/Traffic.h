#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <iostream>
#include <string>

using namespace std;

class Traffic:public Student 
{
	public:
		Traffic(){}
		Traffic(string ID, int score, int money,float background){
			this->ID=ID;
			this->score=score;
			this->money=money;
			this->background=background;
		}
		virtual void ShowSchool(){
			cout<<"Student "<<ID<<" is Traffic student."<<endl;
		}
		
};



#endif
