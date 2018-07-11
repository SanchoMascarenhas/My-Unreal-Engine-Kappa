#include "Vector3.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <sstream>
#include <string>


using namespace std;


Vector3::Vector3()
{
}

Vector3::Vector3(float x, float y, float z) {
	init(x, y, z);
}

float Vector3::dot(Vector3 dotVector) {
	return x * dotVector.getX() + y * dotVector.getY() + z* dotVector.getZ();
}

float Vector3::norm() {
	return sqrt(x*x + y*y + z*z);
}

Vector3 Vector3::normalize(){
	float norm = sqrt(x*x + y*y + z*z);
	if (norm == 0)
		return Vector3(0.0f, 0.0f, 0.0f);
	float newX = x / norm;
	float newY = y / norm;
	float newZ = z / norm;
	return Vector3(newX, newY, newZ);
}


Vector3 Vector3::mult(float scalar) {
	return Vector3(scalar * x, scalar * y, scalar * z);
}

Vector3 Vector3::cross(Vector3 v) {
	
	float newX = y*v.getZ() - v.getY()*z;	//	a[1] * b[2] - b[1] * a[2];
	float newY = z*v.getX() - v.getZ()*x;	//	a[2] * b[0] - b[2] * a[0];
	float newZ = x*v.getY() - v.getX()*y;	//	a[0] * b[1] - b[0] * a[1];

	return Vector3(newX, newY, newZ);
}

Vector3 Vector3::plus(Vector3 addVector) {
	return Vector3(x + addVector.getX(), y + addVector.getY(), z + addVector.getZ());
}

Vector3 Vector3::minus(Vector3 subVector) {
	return Vector3(x - subVector.getX(), y - subVector.getY(), z - subVector.getZ());
}

Vector3 operator*(float scalar, Vector3 &v2) {
	return Vector3(v2.getX() * scalar, v2.getY() * scalar, v2.getZ() * scalar);
}
Vector3 operator*(Vector3 &v1, float scalar) {
	return Vector3(v1.getX() * scalar, v1.getY() * scalar, v1.getZ() * scalar);
}

Vector3 operator-( Vector3 &v) 
{
	return Vector3(-v.getX(), -v.getY(), -v.getZ());
}

Vector3 operator-(Vector3 &v1, Vector3 &v2) {
	float newx = v1.getX() - v2.getX();
	float newy = v1.getY() - v2.getY();
	float newz = v1.getZ() - v2.getZ();

	return Vector3(newx, newy, newz);
}

Vector3 operator+(Vector3 &v1, Vector3 &v2) {
	float newx = v1.getX() + v2.getX();
	float newy = v1.getX() + v2.getY();
	float newz = v1.getX() + v2.getZ();
	return Vector3(newx, newy, newz);
}


int Vector3::getSize() {
	return size;
}

float Vector3::getX() {
	return x;
}

float Vector3::getY() {
	return y;
}

float Vector3::getZ() {
	return z;
}

Vector3::~Vector3() {
}

void Vector3::init(float newx, float newy, float newz) {
	x = newx;
	y = newy;
	z = newz;
	size = 3;
}
