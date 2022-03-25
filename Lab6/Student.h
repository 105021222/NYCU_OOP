#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student 
{
	public:
		string ID;
		int score,money;
		float background;
		Student(){}
		
		void printAllInfo(){
			cout<<"ID : "<<ID<<endl;
			cout<<"Score : "<<score<<endl;
			cout<<"Money : "<<money<<endl;
			cout<<"Background : "<<background<<endl;
		}
		string getID(){
			return ID;
		}
		virtual void ShowSchool(){
			
		}
};


#endif
