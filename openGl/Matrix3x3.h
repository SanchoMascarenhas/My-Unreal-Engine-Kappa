#pragma once
#include "Vector3.h"
class Matrix3x3
{
public:
	Matrix3x3();
	Matrix3x3(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	Matrix3x3(Vector3 v1, Vector3 v2, Vector3 v3);
	friend Matrix3x3 operator-(Matrix3x3 &v);
	friend Matrix3x3 operator-(Matrix3x3 &v1, Matrix3x3 &v2);
	friend Matrix3x3 operator+(Matrix3x3 &v1, Matrix3x3 &v2);
	friend Matrix3x3 operator*(Matrix3x3 &v1, float scalar);
	friend Matrix3x3 operator*(float scalar, Matrix3x3 &v1);
	friend Matrix3x3 operator*(Matrix3x3 &m1, Matrix3x3 &m2);
	friend Vector3 operator*(Vector3 &m2, Matrix3x3 &m1);
	friend Vector3 operator*(Matrix3x3 &m1, Vector3 &m2);
	float *toFloatArray();
	Matrix3x3 asterisk();
	Matrix3x3 transpose();
	Matrix3x3 inverse();
	float calcDeterminant();
	float getX1();
	float getY1();
	float getZ1();
	float getX2();
	float getY2();
	float getZ2();
	float getX3();
	float getY3();
	float getZ3();
	float getDet();
	~Matrix3x3();

private:
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;
	float x3;
	float y3;
	float z3;
	float determinant;
};

