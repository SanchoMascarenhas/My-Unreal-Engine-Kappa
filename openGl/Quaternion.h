#pragma once
#include "Vector3.h"
#include "Matrix4x4.h"
#include "Matrix3x3.h"


#define DEGREES_TO_RADIANS 0.01745329251994329547
#define RADIANS_TO_DEGREES 57.29577951308232185913
const float qThreshold = (float)1.0e-5;

class Quaternion
{
public:
	Quaternion();
	Quaternion(float newT, float newX, float newY, float newZ);
	Quaternion(float newT, Vector3 newV);
	float quadrance();
	Quaternion normalize();
	Quaternion conjugate();
	Quaternion inverse();
	void clean();
	friend Quaternion operator*(Quaternion &q, float s);
	friend Quaternion operator*(float s, Quaternion &q);
	friend Quaternion operator*(Quaternion &q1, Quaternion &q2);
	friend Quaternion operator+(Quaternion &q1, Quaternion &q2);
	Matrix4x4 toMatrix4x4();
	float norm();
	float getX();
	float getY();
	float getZ();
	~Quaternion();


private:
	float t;
	Vector3 v;
};

