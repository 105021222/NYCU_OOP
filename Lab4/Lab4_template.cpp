#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class matrix
{
public:
	vector<vector<int> > M;
	
	
	matrix()
	{
		//Initialize a matrix of size 3 * 3 to be I
		M.resize(3, vector<int>(3, 0));
		for(int i=0;i<3;i++){
			M[i][i]=1;
		}
	}
	
	matrix(vector<vector<int> >& m)
	{
		M = m;
	}
	
	void print(){	
		//  print a matrix
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout<<M[i][j]<<" ";
			}
			cout<<endl;
		}
	}
		
	matrix multiply(matrix m){
		//  a function to multiply two matrices,and return the product matrix
		vector<vector<int> > p(3, vector<int>(3, 0));
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					p[i][j]+=M[i][k]*m.M[k][j];
				}
			}
		}
		matrix product(p);
		return product;
	}
	
	int cofactor(int row,int col){
		// a function to calculate c(row,col) ,where c is the cofactor matrix 
		vector<int> c(0);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i!=row&&j!=col){
					c.push_back(M[i][j]);
				}
			}
		}
		int sign = ((row+col)%2==0)? 1: -1;
		return sign*(c[0]*c[3]-c[1]*c[2]);
	}
	
	matrix adjoint(){
		//  a function to calculate the classic adjoint matrix ,and return it.
		vector<vector<int> > m(3, vector<int>(3, 0));
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				m[j][i]=cofactor(i,j);
			}
		}
		matrix adj(m);
		return adj;
	}
	
	void determinant(){
		// a function to calculate the determinant.
		cout<<"The determinant of matrix M is:"<<matrix::multiply(adjoint()).M[0][0]<<endl;
	}
	
};

int main() 
{
	fstream fin;
	
	fin.open("data.txt", ios::in);
	if (!fin) {
		cout << "File is not opened" << endl;
		exit(0);
		system("pause");
	}
	
	int n;
	fin >> n;
	vector<vector<int> > m(3,vector<int>(3));
	for(int i=0; i<n; i++) {
		// read the input 
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				fin>>m[i][j];
			}
		}
		matrix M(m); //construct matrix M
		M.determinant();
		//M.print();
		//M.adjoint().print();
		//M.multiply(M.adjoint()).print();
		
	}

	system("pause");
	return 0;
}
