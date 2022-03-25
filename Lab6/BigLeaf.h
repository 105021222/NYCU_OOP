#ifndef BIGLEAF_H
#define BIGLEAF_H

#include <iostream>
#include <string>

using namespace std;

class BigLeaf:public Student 
{
	public:
		BigLeaf(){}
		BigLeaf(string ID, int score, int money,float background){
			this->ID=ID;
			this->score=score;
			this->money=money;
			this->background=background;
		}
		void ShowSchool(){
			cout<<"Student "<<ID<<" is BigLeaf student."<<endl;
		}
		
};



#endif
