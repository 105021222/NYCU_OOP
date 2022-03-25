#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct info {
	int height;
	int weight;

	// don't change this
	bool operator<(const info& other) const {
		return height < other.height;
	}
};

//TODO: implement three comparsion function 
//example: 
//bool functionName(const dataType& p1, const dataType& p2) {
//	return p1 > p2;
//}

//1.implement compare by height here

bool H_sort(const pair<string, info>& p1, const pair<string, info>& p2) {
	return p1.second.height < p2.second.height;
}

//2.implement compare by weight here

bool W_sort(const pair<string, info>& p1, const pair<string, info>& p2) {
	return p1.second.weight < p2.second.weight;
}

//3.implement compare by height and weight here

bool HW_sort(const pair<string, info>& p1, const pair<string, info>& p2) {
	if(p1.second.height == p2.second.height) return p1.second.weight < p2.second.weight;
	else return p1.second.height < p2.second.height;
}



class Map
{
public:
	Map()
	{
		people.clear();
	}

	void readFile() {
		fstream file;
		file.open("test.txt", ios::in);
		int cmdNum;
		file >> cmdNum;

		while (cmdNum--) {
			char cmd;
			file >> cmd;
			switch (cmd) {
				case 'a':
				{
					string name;
					file >> name;
					info ii;
					file >> ii.height >> ii.weight;
					add(name, ii);
					break;
				}
				case 'f':
				{
					string name;
					file >> name;
					find(name);
					break;
				}
				case 'e':
				{
					string name;
					file >> name;
					erase(name);
					break;
				}
			}
		}

		file.close();
	}

	void add(string name, info& _info) {
		//TODO: implement add function add new data into the map(vector<pair<...>>)
		//If the name is already in the map, override his/her data
		int num=-1;
		for(int i=0;i<people.size();i++){
			if(name==people[i].first) num=i;
		}
		if(num==-1){
			people.push_back(make_pair(name,_info));
		}
		else{
			cout<<name<<"'s h:"<<people[num].second.height<<" and w:"<<people[num].second.weight;
			people[num].second=_info;
			cout<<" is changed to h:"<<people[num].second.height<<" and w:"<<people[num].second.weight<<endl;
		}
	}

	void find(string name) {
		//TODO: implement find function to get the information of the given name if the name exist
		//otherwise, print "name is not found"
		//you must use iterator to implement
		bool found=false;
		vector<pair<string, info>>::iterator p;
		for(p=people.begin();p!=people.end();p++){
			if(p->first==name){
				cout<<name<<" is found! ";
				cout<<"h:"<<p->second.height<<" and w:"<<p->second.weight<<endl;
				found=true;
			}
		}
		if(!found) cout<<name<<" is not found!"<<endl;
	}

	void erase(string name) {
		//TODO: implement erase function to delete the element of the given name if the name exist
		//otherwise, print "name is not found"
		//you must use iterator to implement
		int found=0;
		vector<pair<string, info>>::iterator p;
		for(p=people.begin();p!=people.end();p++){
			if(p->first==name){
				found=1;
				people.erase(p);
			}
		}
		if(found) {
			cout<<name<<" is erased!"<<endl;
		}
		else cout<<name<<" is not found!"<<endl;
	}

	void sortByName() {
		//TODO: call sort() function (default one)
		sort(people.begin(),people.end());
	}

	void sortByInfo(const char* type) {

		if (type == "H") {
			//TODO: call sort() function and compare by height
			sort(people.begin(),people.end(),H_sort);
		}
		else if (type == "W") {
			//TODO: call sort() function and compare by weight
			sort(people.begin(),people.end(),W_sort);
		}
		else if (type == "HW") {
			//TODO: call sort() function and compare by height and weight
			sort(people.begin(),people.end(),HW_sort);
		}
	}

	void write(fstream& file) {
		//TODO: Write all elements in the map to the file
		//you must use iterator to implement
		
		vector<pair<string, info>>::iterator p;
		for(p=people.begin();p!=people.end();p++){
			file<<p->first<<":\t"<<p->second.height<<", "<<p->second.weight<<"\n";
		}
		file<<"\n";
	}

	void writeFile() {
		fstream file;
		file.open("lab7.txt", ios::out);

		file << "Sort By Name\n";
		sortByName();
		write(file);
		file << "Sort By Height\n";
		sortByInfo("H");
		write(file);
		file << "Sort By Weight\n";
		sortByInfo("W");
		write(file);
		file << "Sort By Height&Weight\n";
		sortByInfo("HW");
		write(file);

		cout << "File lab7.txt saved!\n";
		file.close();
	}

private:
	vector<pair<string, info>> people;
};

int main() {
	Map myMap;

	myMap.readFile();
	myMap.writeFile();

	system("pause");
	return 0;
}
