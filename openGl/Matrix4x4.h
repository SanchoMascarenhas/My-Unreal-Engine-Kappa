#pragma once
#include "Vector3.h"
class Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(float x1, float y1, float z1, float w1 ,
		float x2, float y2, float z2, float w2,
		float x3, float y3, float z3, float w3,
		float x4, float y4, float z4, float w4);
	Matrix4x4(Vector3 v1, Vector3 v2, Vector3 v3);
	Matrix4x4 transpose();
	float *toFloatArray();
	friend Matrix4x4 operator-(Matrix4x4 &v);
	friend Matrix4x4 operator-(Matrix4x4 &v1, Matrix4x4 &v2);
	friend Matrix4x4 operator+(Matrix4x4 &v1, Matrix4x4 &v2);
	friend Matrix4x4 operator*(Matrix4x4 &v1, float scalar);
	friend Matrix4x4 operator*(float scalar, Matrix4x4 &v1);
	friend Matrix4x4 operator*(Matrix4x4 &m1, Matrix4x4 &m2);

	float getX1();
	float getY1();
	float getZ1();
	float getW1();
	float getX2();
	float getY2();
	float getZ2();
	float getW2();
	float getX3();
	float getY3();
	float getZ3();
	float getW3();
	float getX4();
	float getY4();
	float getZ4();
	float getW4();

	float getDet();
	~Matrix4x4();

private:
	float x1;
	float y1;
	float z1;
	float w1;
	float x2;
	float y2;
	float z2;
	float w2;
	float x3;
	float y3;
	float z3;
	float w3;
	float x4;
	float y4;
	float z4;
	float w4;
	float array[16];
};

