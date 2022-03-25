#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class PrimeFactorization {
private:
	int num1, num2;
	vector<int> num1_factor, num2_factor;
	
public:
	PrimeFactorization() {
	}
	PrimeFactorization(int _a, int _b) {
		num1=_a;
		num2=_b;
	}
	void Prime_Factorization(int num,vector<int> &num_factor){
		while(num%2==0){
			num_factor.push_back(2);
			num/=2;
		}
		for(int i=3;i<=num;i+=2){
			while(num%i==0){
				num_factor.push_back(i);
				num/=i;
			}
		}
	}
	void Get_Prime_Factorization() {
		Prime_Factorization(num1,num1_factor);
		Prime_Factorization(num2,num2_factor);
	}

	void Print_Prime_Factorization() {
		cout<<"num1_Prime_factor:\"";
		for(int i=0;i<num1_factor.size();i++){
			cout<<num1_factor[i]<<" ";
		}
		cout<<"\""<<endl;
		cout<<"num2_Prime_factor:\"";
		for(int i=0;i<num2_factor.size();i++){
			cout<<num2_factor[i]<<" ";
		}
		cout<<"\""<<endl;
	}

	void Print_GCD() {
		int gcd=1;
		while(!(num1_factor.empty()||num2_factor.empty())){
			if(num1_factor.back()>num2_factor.back()){
				num1_factor.pop_back();
			}
			else if(num1_factor.back()<num2_factor.back()){
				num2_factor.pop_back();
			}
			else{
				gcd*=num1_factor.back();
				num1_factor.pop_back();
				num2_factor.pop_back();
			}
		}
		cout<<"GCD:"<<gcd<<endl;
		
	}

};

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		cout << "num1 = " << a << endl;
		cout << "num2 = " << b << endl;

		PrimeFactorization PF(a, b);

		PF.Get_Prime_Factorization();
		PF.Print_Prime_Factorization();
		PF.Print_GCD();

		cout << endl;

	}

	system("PAUSE");
	return 0;
}
