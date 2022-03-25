#include "lab1_Q1.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void QUADRATIC::print()
{
	cout<<a<<"x^2";
	if(b>=0)
		cout<<"+";
	cout<<b<<"x";
	if(c>=0)
		cout<<"+";
	cout<<c<<endl;
}

void QUADRATIC::add(QUADRATIC q)
{
	a+=q.a;
	b+=q.b;
	c+=q.c;
}

void QUADRATIC::discriminant()
{
	double d; //determinant
	d=b*b-4*a*c;
	if(d>0){
		double root1,root2;
		root1=(-b+sqrt(d))/(2*a);
		root2=(-b-sqrt(d))/(2*a);
		cout<<"There are two roots:"<<root1<<","<<root2<<endl;
	}
	else if(d<0){
		double re_root,im_root; //real part and imaginary part
		re_root=(-b)/(2*a);
		im_root=sqrt(-d)/(2*a);
		cout<<"There are two complex roots:";
		cout<<re_root<<"+"<<im_root<<"i";
		cout<<",";
		cout<<re_root<<"-"<<im_root<<"i"<<endl;
	}
	else{
		double root1;
		root1=(-b)/2*a;
		cout<<"There is a double root:"<<root1<<endl;
	}
}
