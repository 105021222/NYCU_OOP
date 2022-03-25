#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Roll_Call_System {

private:
	vector<string> studentNames{};
	vector<string> pickedStudentNames{};
	int seed;
	int a;
	int c;
	int m;

public:
	fstream fin;

	void OpenFile() {
		//open the file student.txt
		fin.open("student.txt");
		cout<<"Filename: student.txt"<<endl;
	}

	void AddNames() {
		// add name to vector studentNames
		int num=0;//number of students
		fin>>num;
		string str;
		for(int i=0;i<num;i++){
			fin>>str;
			studentNames.push_back(str);
		}
			
	}

	int GenerateRandomNumber() {
		// compute Xn
		return ((a*seed+c)%m);
	}

	void PickNames() {
		vector <string>().swap(pickedStudentNames);
		int pick_num;
		fin>>seed>>a>>c>>m>>pick_num;
		for(int i=0;i<pick_num;i++){
			seed=GenerateRandomNumber();
			pickedStudentNames.push_back(studentNames[seed]);
		}
	}

	void PrintPickedStudentNames() {
		cout<<"Picked Name:"<<endl;
		for(int i=0;i<pickedStudentNames.size();i++){
			cout<<pickedStudentNames[i]<<endl;
		}
	}

	void CaculateAlphabets(){
		set<char> s;
		for(int j=0;j<pickedStudentNames.size();j++){
			for(int k=0;k<pickedStudentNames[j].size();k++){
				s.insert(tolower(pickedStudentNames[j][k]));
			}
		}
		cout<<"Total alphabets: "<<s.size()<<endl<<endl;
	}

/*	Other method to caculate different Alphabets
	void CaculateAlphabets() {
		int num=0;//different alphabets
		for(int i=0;i<26;i++){
			int tag=0;
			for(int j=0;j<pickedStudentNames.size();j++){
				for(int k=0;k<pickedStudentNames[j].size();k++){
					if(pickedStudentNames[j][k]==97+i||pickedStudentNames[j][k]==65+i){ //ASCII code of 'A' is 65 and 'a' is 97
						tag=1;
					}	
				}
			}
			if(tag==1){
				num++;
			}
		}
		cout<<"Total alphabets: "<<num<<endl<<endl;
	}
*/	
};

int main() {
	
	Roll_Call_System rcs;
	rcs.OpenFile();
	rcs.AddNames();

	int times;
	rcs.fin >> times;
	while (times--) {
		rcs.PickNames();
		rcs.PrintPickedStudentNames();
		rcs.CaculateAlphabets();
	}
	
	system("PAUSE");
	return 0;

}
