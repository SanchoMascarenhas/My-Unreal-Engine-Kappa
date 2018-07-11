#include "Matrix3x3.h"
#include "Matrix2x2.h"



Matrix3x3::Matrix3x3()
{
}

Matrix3x3::Matrix3x3(Vector3 v1, Vector3 v2, Vector3 v3){
	x1 = v1.getX();
	y1 = v1.getY();
	z1 = v1.getZ();
	x2 = v2.getX();
	y2 = v2.getY();
	z2 = v2.getZ();
	x3 = v3.getX();
	y3 = v3.getY();
	z3 = v3.getZ();
	determinant = calcDeterminant();
}

Matrix3x3::Matrix3x3(float newx1, float newy1, float newz1, 
		float newx2, float newy2, float newz2, 
		float newx3, float newy3, float newz3){

	x1 = newx1;
	y1 = newy1;
	z1 = newz1;
	x2 = newx2;
	y2 = newy2;
	z2 = newz2;
	x3 = newx3;
	y3 = newy3;
	z3 = newz3;
	determinant = calcDeterminant();
}


float * Matrix3x3::toFloatArray()
{
	float floatArray[] = { x1, y1, z1, x2, y2, z2, x3, y3, z3 };
	return floatArray;
}

Matrix3x3 Matrix3x3::asterisk()
{
	return Matrix3x3();
}

Matrix3x3 Matrix3x3::transpose()
{
	return Matrix3x3(x1, x2, x3, y1, y2, y3, z1, z2, z3);
}
///////////////////////////////////////////////////////////////////////////
Matrix3x3 Matrix3x3::inverse()
{

	float A = y2*z3 - z2*y3;
	float B = -(x2*z3 - z2*x3);
	float C = x2*y3 - y2*x3;
	float D = -(y1*z3 - z1*y3);
	float E = x1*z3 - z1*x3;
	float F = -(x1*y3 - y1*x3);
	float G = y1*z2 - z1*y2;
	float H = -(x1*z2 - z1*x2);
	float I = x1*y2 - y1*x2;

	Matrix3x3 cofaMatrix = Matrix3x3(A, B, C, D, E, F, G, H, I);
	Matrix3x3 adjMatrix = cofaMatrix.transpose();

	return (1 / determinant) * adjMatrix;
}

float Matrix3x3::calcDeterminant()
{
	return x1*y2*z3 + x2*y3*z1 + x3*y1*z2 - z1*y2*x3 - z2*y3*x1 - z3*y1*x2;
}

Matrix3x3 operator-(Matrix3x3 &v) {
	return Matrix3x3(-v.getX1(), -v.getY1(), -v.getZ1(), -v.getX2(), -v.getY2(), -v.getZ2(), -v.getX3(), -v.getY3(), -v.getZ3());
}

Matrix3x3 operator-(Matrix3x3 &v1, Matrix3x3 &v2) {
	float newx1 = v1.getX1() - v2.getX1();
	float newy1 = v1.getY1() - v2.getY1();
	float newz1 = v1.getZ1() - v2.getZ1();
	float newx2 = v1.getX2() - v2.getX2();
	float newy2 = v1.getY2() - v2.getY2();
	float newz2 = v1.getZ2() - v2.getZ2();
	float newx3 = v1.getX3() - v2.getX3();
	float newy3 = v1.getY3() - v2.getY3();
	float newz3 = v1.getZ3() - v2.getZ3();

	return Matrix3x3(newx1, newy1, newz1, newx2, newy2, newz2, newx3, newy3, newz3);
}

Matrix3x3 operator+(Matrix3x3 &v1, Matrix3x3 &v2) {
	float newx1 = v1.getX1() + v2.getX1();
	float newy1 = v1.getY1() + v2.getY1();
	float newz1 = v1.getZ1() + v2.getZ1();
	float newx2 = v1.getX2() + v2.getX2();
	float newy2 = v1.getY2() + v2.getY2();
	float newz2 = v1.getZ2() + v2.getZ2();
	float newx3 = v1.getX3() + v2.getX3();
	float newy3 = v1.getY3() + v2.getY3();
	float newz3 = v1.getZ3() + v2.getZ3();

	return Matrix3x3(newx1, newy1, newz1, newx2, newy2, newz2, newx3, newy3, newz3);
}

Matrix3x3 operator*(Matrix3x3 &m1, Matrix3x3 &m2) {
	float newx1 = m1.getX1()*m2.getX1() + m1.getY1()*m2.getX2() + m1.getZ1()*m2.getX3();
	float newy1 = m1.getX1()*m2.getY1() + m1.getY1()*m2.getY2() + m1.getZ1()*m2.getY3();
	float newz1 = m1.getX1()*m2.getZ1() + m1.getY1()*m2.getZ2() + m1.getZ1()*m2.getZ3();
	float newx2 = m1.getX2()*m2.getX1() + m1.getY2()*m2.getX2() + m1.getZ2()*m2.getX3();
	float newy2 = m1.getX2()*m2.getY1() + m1.getY2()*m2.getY2() + m1.getZ2()*m2.getY3();
	float newz2 = m1.getX2()*m2.getZ1() + m1.getY2()*m2.getZ2() + m1.getZ2()*m2.getZ3();
	float newx3 = m1.getX3()*m2.getX1() + m1.getY3()*m2.getX2() + m1.getZ3()*m2.getX3();
	float newy3 = m1.getX3()*m2.getY1() + m1.getY3()*m2.getY2() + m1.getZ3()*m2.getY3();
	float newz3 = m1.getX3()*m2.getZ1() + m1.getY3()*m2.getZ2() + m1.getZ3()*m2.getZ3();

	return Matrix3x3(newx1, newy1, newz1, newx2, newy2, newz2, newx3, newy3, newz3);
}

Vector3 operator*(Matrix3x3 &m1, Vector3 &m2) {
	float newx = m1.getX1()*m2.getX() + m1.getY1()*m2.getY() + m1.getZ1()*m2.getZ();
	float newy = m1.getX2()*m2.getX() + m1.getY2()*m2.getY() + m1.getZ2()*m2.getZ();
	float newz = m1.getX3()*m2.getX() + m1.getY3()*m2.getY() + m1.getZ3()*m2.getZ();

	return Vector3(newx, newy, newz);
}

Vector3 operator*(Vector3 &m2, Matrix3x3 &m1) {
	float newx = m1.getX1()*m2.getX() + m1.getY1()*m2.getY() + m1.getZ1()*m2.getZ();
	float newy = m1.getX2()*m2.getX() + m1.getY2()*m2.getY() + m1.getZ2()*m2.getZ();
	float newz = m1.getX3()*m2.getX() + m1.getY3()*m2.getY() + m1.getZ3()*m2.getZ();

	return Vector3(newx, newy, newz);
}

Matrix3x3 operator*(Matrix3x3 &v, float scalar) {
	return Matrix3x3(v.getX1() *scalar, v.getY1()*scalar, v.getZ1()*scalar, v.getX2()*scalar, v.getY2()*scalar, v.getZ2()*scalar, v.getX3()*scalar, v.getY3()*scalar, v.getZ3()*scalar);
}

Matrix3x3 operator*(float scalar, Matrix3x3 &v) {
	return Matrix3x3(v.getX1() *scalar, v.getY1()*scalar, v.getZ1()*scalar, v.getX2()*scalar, v.getY2()*scalar, v.getZ2()*scalar, v.getX3()*scalar, v.getY3()*scalar, v.getZ3()*scalar);
}

float Matrix3x3::getX1()
{
	return x1;
}

float Matrix3x3::getY1()
{
	return y1;
}

float Matrix3x3::getZ1()
{
	return z1;
}

float Matrix3x3::getX2()
{
	return x2;
}

float Matrix3x3::getY2()
{
	return y2;
}

float Matrix3x3::getZ2()
{
	return z2;
}

float Matrix3x3::getX3()
{
	return x3;
}

float Matrix3x3::getY3()
{
	return y3;
}

float Matrix3x3::getZ3()
{
	return z3;
}

float Matrix3x3::getDet() {
	return determinant;
}



Matrix3x3::~Matrix3x3()
{
}
