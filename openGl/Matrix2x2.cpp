#include "Matrix2x2.h"



Matrix2x2::Matrix2x2()
{
}

Matrix2x2::Matrix2x2(float newx1, float newy1, float newx2, float newy2)
{
	x1 = newx1;
	y1 = newy1;
	x2 = newx2;
	y2 = newy2;
	determinant = calcDeterminant();
}

Matrix2x2 Matrix2x2::asterisk()
{
	return Matrix2x2();
}

Matrix2x2 Matrix2x2::transpose()
{
	return Matrix2x2(x1, x2, y1, y2);
}

Matrix2x2 Matrix2x2::inverse()
{
	return (1/determinant) * Matrix2x2(x1, x2, y1, y2);
}

float Matrix2x2::calcDeterminant()
{
	return x1 * y2 - x2 * y1;
}

Matrix2x2 operator-(Matrix2x2 &v) {
	return Matrix2x2(-v.getX1(), -v.getY1(), -v.getX2(), -v.getY2());
}

Matrix2x2 operator-(Matrix2x2 &v1, Matrix2x2 &v2) {
	float newx1 = v1.getX1() - v2.getX1();
	float newy1 = v1.getY1() - v2.getY1();
	float newx2 = v1.getX2() - v2.getX2();
	float newy2 = v1.getY2() - v2.getY2();

	return Matrix2x2(newx1, newy1, newx2, newy2);
}

Matrix2x2 operator+(Matrix2x2 &v1, Matrix2x2 &v2) {
	float newx1 = v1.getX1() + v2.getX1();
	float newy1 = v1.getY1() + v2.getY1();
	float newx2 = v1.getX2() + v2.getX2();
	float newy2 = v1.getY2() + v2.getY2();

	return Matrix2x2(newx1, newy1, newx2, newy2);
}

Matrix2x2 operator*(Matrix2x2 &v1, float scalar) {
	return Matrix2x2(scalar * v1.getX1(), scalar * v1.getY1(), scalar * v1.getX2(), scalar * v1.getY2());
}

Matrix2x2 operator*(float scalar, Matrix2x2 &v1) {
	return Matrix2x2(scalar * v1.getX1(), scalar * v1.getY1(), scalar * v1.getX2(), scalar * v1.getY2());
}

float Matrix2x2::getX1()
{
	return x1;
}

float Matrix2x2::getY1()
{
	return y1;
}

float Matrix2x2::getX2()
{
	return x2;
}

float Matrix2x2::getY2()
{
	return y2;
}

float Matrix2x2::getDet() {
	return determinant;

}


Matrix2x2::~Matrix2x2()
{
}
