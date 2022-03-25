#ifndef TAIWANNUMBER1_H
#define TAIWANNUMBER1_H

#include <iostream>
#include <string>

using namespace std;

class TaiwanNumber1:public Student 
{
	public:
		TaiwanNumber1(){}
		TaiwanNumber1(string ID, int score, int money,float background){
			this->ID=ID;
			this->score=score;
			this->money=money;
			this->background=background;
		}
		virtual void ShowSchool(){
			cout<<"Student "<<ID<<" is TaiwanNumber1 student."<<endl;
		}
		
};

#endif
