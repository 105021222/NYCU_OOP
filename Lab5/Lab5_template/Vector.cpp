#include "Vector.h"

//TODO: constructor
Vector::Vector() {
	x=0;
	y=0;
	z=0;
}
Vector::Vector(float _x, float _y, float _z) {
	x=_x;
	y=_y;
	z=_z;
}
 
Vector Vector::operator+(Vector v)
{
	//TODO: Overload the plus operator +.
	//Then we can use more intuitively way to add our vector (like v1 + v2).
	//Return the result of v1 + v2
	Vector result;
	result.x=x+v.x;
	result.y=y+v.y;
	result.z=z+v.z;
	return result;
	
}

Vector Vector::operator-(Vector v)
{
	//TODO: Overload the subtract operator -.
	//Then we can use more intuitively way to subtract out vector (like v1 - v2).
	//Return the result of v1 - v2
	Vector result;
	result.x=x-v.x;
	result.y=y-v.y;
	result.z=z-v.z;
	return result;
}


float Vector::operator*(Vector v)
{
	//TODO: Overload the operator * as dot product.
	//Return the dot product result of two vector
	float num=0;
	num=x*v.x+y*v.y+z*v.z;
	return num;
}

Vector Vector::operator/(Vector v)
{
	//TODO: Overload the operator / as cross product.
	//Return the cross product result of v1 / v2
	Vector result;
	result.x=y*v.z-z*v.y;
	result.y=z*v.x-x*v.z;
	result.z=x*v.y-y*v.x;
	return result;
}

Vector Vector::operator-()
{
	//TODO: Overload the negate operator -.
	//Then we can use more intuitively way to negate a vector -v1.
	//Return the result of -v1
	Vector result;
	result.x=-x;
	result.y=-y;
	result.z=-z;
	return result;
}

bool Vector::operator>(Vector v) {
	//TODO: Overload the ">" operator.
	//Then we can use more intuitively way to
	//compare the length from the original point(0,0,0) of two vectors (v1 > v2).
	//Return true if the length of v1 is greater than that of v2, return false otherwise. 
	float len_vec1,len_vec2;
	len_vec1=x*x+y*y+z*z;
	len_vec2=v.x*v.x+v.y*v.y+v.z*v.z;
	return (len_vec1>len_vec2);
}


ifstream& operator>>(ifstream& in, Vector& v)
{
	//TODO: Overload the >> operator.
	//Read the input.txt file and store vector in v
	in>>v.x;
	in>>v.y;
	in>>v.z;
	return in;
}

ostream& operator<<(ostream& out, const Vector& v)
{
	//TODO: Overload the << operator.
	//Output the vector v
	out <<"("<<v.x<<","<<v.y<<","<<v.z<<")";
	return out;
}
