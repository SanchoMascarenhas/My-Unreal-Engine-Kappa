#include "Matrix4x4.h"



Matrix4x4::Matrix4x4()
{
}

Matrix4x4::Matrix4x4(float newx1, float newy1, float newz1, float neww1,
					float newx2, float newy2, float newz2, float neww2,
					float newx3, float newy3, float newz3, float neww3,
					float newx4, float newy4, float newz4, float neww4)
{
	array[0] = x1 = newx1;
	array[1] = y1 = newy1;
	array[2] = z1 = newz1;
	array[3] = w1 = neww1;
	array[4] = x2 = newx2;
	array[5] = y2 = newy2;
	array[6] = z2 = newz2;
	array[7] = w2 = neww2;
	array[8] = x3 = newx3;
	array[9] = y3 = newy3;
	array[10] = z3 = newz3;
	array[11] = w3 = neww3;
	array[12] = x4 = newx4;
	array[13] = y4 = newy4;
	array[14] = z4 = newz4;
	array[15] = w4 = neww4;
}

Matrix4x4::Matrix4x4(Vector3 v1, Vector3 v2, Vector3 v3) {
	x1 = v1.getX();
	y1 = v1.getY();
	z1 = v1.getZ();
	w1 = 0;
	x2 = v2.getX();
	y2 = v2.getY();
	z2 = v2.getZ();
	w2 = 0;
	x3 = v3.getX();
	y3 = v3.getY();
	z3 = v3.getZ();
	w3 = 0;
	x4 = 0;
	y4 = 0;
	z4 = 0;
	w4 = 1;
}

Matrix4x4 Matrix4x4::transpose()
{
	return Matrix4x4(x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4);
}

Matrix4x4 operator-(Matrix4x4 &v) {
	return Matrix4x4(-v.getX1(), -v.getY1(), -v.getZ1(), -v.getW1(),
					-v.getX2(), -v.getY2(), -v.getZ2(), -v.getW2(),
					-v.getX3(), -v.getY3(), -v.getZ3(), -v.getW3(),
					-v.getX4(), -v.getY4(), -v.getZ4(), -v.getW4());
}

Matrix4x4 operator-(Matrix4x4 &v1, Matrix4x4 &v2) {
	float newx1 = v1.getX1() - v2.getX1();
	float newy1 = v1.getY1() - v2.getY1();
	float newz1 = v1.getZ1() - v2.getZ1();
	float neww1 = v1.getW1() - v2.getW1();
	float newx2 = v1.getX2() - v2.getX2();
	float newy2 = v1.getY2() - v2.getY2();
	float newz2 = v1.getZ2() - v2.getZ2();
	float neww2 = v1.getW2() - v2.getW2();
	float newx3 = v1.getX3() - v2.getX3();
	float newy3 = v1.getY3() - v2.getY3();
	float newz3 = v1.getZ3() - v2.getZ3();
	float neww3 = v1.getW3() - v2.getW3();
	float newx4 = v1.getX4() - v2.getX4();
	float newy4 = v1.getY4() - v2.getY4();
	float newz4 = v1.getZ4() - v2.getZ4();
	float neww4 = v1.getW4() - v2.getW4();

	return Matrix4x4(newx1, newy1, newz1, neww1, 
					newx2, newy2, newz2, neww2,
					newx3, newy3, newz3, neww3,
					newx4, newy4, newz4, neww4);
}

Matrix4x4 operator+(Matrix4x4 &v1, Matrix4x4 &v2) {
	float newx1 = v1.getX1() + v2.getX1();
	float newy1 = v1.getY1() + v2.getY1();
	float newz1 = v1.getZ1() + v2.getZ1();
	float neww1 = v1.getW1() + v2.getW1();
	float newx2 = v1.getX2() + v2.getX2();
	float newy2 = v1.getY2() + v2.getY2();
	float newz2 = v1.getZ2() + v2.getZ2();
	float neww2 = v1.getW2() + v2.getW2();
	float newx3 = v1.getX3() + v2.getX3();
	float newy3 = v1.getY3() + v2.getY3();
	float newz3 = v1.getZ3() + v2.getZ3();
	float neww3 = v1.getW3() + v2.getW3();
	float newx4 = v1.getX4() + v2.getX4();
	float newy4 = v1.getY4() + v2.getY4();
	float newz4 = v1.getZ4() + v2.getZ4();
	float neww4 = v1.getW4() + v2.getW4();

	return Matrix4x4(newx1, newy1, newz1, neww1,
					newx2, newy2, newz2, neww2,
					newx3, newy3, newz3, neww3,
					newx4, newy4, newz4, neww4);
}

Matrix4x4 operator*(Matrix4x4 &m1, Matrix4x4 &m2) {
	float newx1 = m1.getX1()*m2.getX1() + m1.getY1()*m2.getX2() + m1.getZ1()*m2.getX3() + m1.getW1()*m2.getX4();
	float newy1 = m1.getX1()*m2.getY1() + m1.getY1()*m2.getY2() + m1.getZ1()*m2.getY3() + m1.getW1()*m2.getY4();
	float newz1 = m1.getX1()*m2.getZ1() + m1.getY1()*m2.getZ2() + m1.getZ1()*m2.getZ3() + m1.getW1()*m2.getZ4();
	float neww1 = m1.getX1()*m2.getW1() + m1.getY1()*m2.getW2() + m1.getZ1()*m2.getW3() + m1.getW1()*m2.getW4();

	float newx2 = m1.getX2()*m2.getX1() + m1.getY2()*m2.getX2() + m1.getZ2()*m2.getX3() + m1.getW2()*m2.getX4();
	float newy2 = m1.getX2()*m2.getY1() + m1.getY2()*m2.getY2() + m1.getZ2()*m2.getY3() + m1.getW2()*m2.getY4();
	float newz2 = m1.getX2()*m2.getZ1() + m1.getY2()*m2.getZ2() + m1.getZ2()*m2.getZ3() + m1.getW2()*m2.getZ4();
	float neww2 = m1.getX2()*m2.getW1() + m1.getY2()*m2.getW2() + m1.getZ2()*m2.getW3() + m1.getW2()*m2.getW4();

	float newx3 = m1.getX3()*m2.getX1() + m1.getY3()*m2.getX2() + m1.getZ3()*m2.getX3() + m1.getW3()*m2.getX4();
	float newy3 = m1.getX3()*m2.getY1() + m1.getY3()*m2.getY2() + m1.getZ3()*m2.getY3() + m1.getW3()*m2.getY4();
	float newz3 = m1.getX3()*m2.getZ1() + m1.getY3()*m2.getZ2() + m1.getZ3()*m2.getZ3() + m1.getW3()*m2.getZ4();
	float neww3 = m1.getX3()*m2.getW1() + m1.getY3()*m2.getW2() + m1.getZ3()*m2.getW3() + m1.getW3()*m2.getW4();

	float newx4 = m1.getX4()*m2.getX1() + m1.getY4()*m2.getX2() + m1.getZ4()*m2.getX3() + m1.getW4()*m2.getX4();
	float newy4 = m1.getX4()*m2.getY1() + m1.getY4()*m2.getY2() + m1.getZ4()*m2.getY3() + m1.getW4()*m2.getY4();
	float newz4 = m1.getX4()*m2.getZ1() + m1.getY4()*m2.getZ2() + m1.getZ4()*m2.getZ3() + m1.getW4()*m2.getZ4();
	float neww4 = m1.getX4()*m2.getW1() + m1.getY4()*m2.getW2() + m1.getZ4()*m2.getW3() + m1.getW4()*m2.getW4();

	return Matrix4x4(newx1, newy1, newz1, neww1,
					newx2, newy2, newz2, neww2,
					newx3, newy3, newz3, neww3,
					newx4, newy4, newz4, neww4);
}

Matrix4x4 operator*(Matrix4x4 &v, float scalar) {
	return Matrix4x4(v.getX1() *scalar, v.getY1()*scalar, v.getZ1()*scalar, v.getW1()*scalar,
					v.getX2()*scalar, v.getY2()*scalar, v.getZ2()*scalar, v.getW2()*scalar,
					v.getX3()*scalar, v.getY3()*scalar, v.getZ3()*scalar, v.getW3()*scalar, 
					v.getX4()*scalar, v.getY4()*scalar, v.getZ4()*scalar, v.getW4()*scalar);
}

Matrix4x4 operator*(float scalar, Matrix4x4 &v) {
	return Matrix4x4(v.getX1() *scalar, v.getY1()*scalar, v.getZ1()*scalar, v.getW1()*scalar,
					v.getX2()*scalar, v.getY2()*scalar, v.getZ2()*scalar, v.getW2()*scalar,
					v.getX3()*scalar, v.getY3()*scalar, v.getZ3()*scalar, v.getW3()*scalar,
					v.getX4()*scalar, v.getY4()*scalar, v.getZ4()*scalar, v.getW4()*scalar);
}

float * Matrix4x4::toFloatArray()
{
	return array;
}

float Matrix4x4::getX1() {
	return x1;
}
float Matrix4x4::getY1()
{
	return y1;
}

float Matrix4x4::getZ1()
{
	return z1;
}

float Matrix4x4::getW1()
{
	return w1;
}

float Matrix4x4::getX2()
{
	return x2;
}

float Matrix4x4::getY2()
{
	return y2;
}

float Matrix4x4::getZ2()
{
	return z2;
}

float Matrix4x4::getW2()
{
	return w2;
}

float Matrix4x4::getX3()
{
	return x3;
}

float Matrix4x4::getY3()
{
	return y3;
}

float Matrix4x4::getZ3()
{
	return z3;
}

float Matrix4x4::getW3()
{
	return w3;
}


float Matrix4x4::getX4()
{
	return x4;
}

float Matrix4x4::getY4()
{
	return y4;
}

float Matrix4x4::getZ4()
{
	return z4;
}

float Matrix4x4::getW4()
{
	return w4;
}

Matrix4x4::~Matrix4x4()
{
}
