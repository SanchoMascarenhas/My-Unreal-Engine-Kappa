#include "Vector4.h"



Vector4::Vector4()
{
}

Vector4::Vector4(float x, float y, float z) {
	init(x, y, z);
}



int Vector4::getSize() {
	return size;
}

float Vector4::getX() {
	return x;
}

float Vector4::getY() {
	return y;
}

float Vector4::getZ() {
	return z;
}

float * Vector4::toFloatArray()
{
	return array;
}

Vector4::~Vector4() {
}

void Vector4::init(float newx, float newy, float newz) {
	array[0] = x = newx;
	array[1] = y = newy;
	array[2] = z = newz;
	array[3] = w = 1;
	size = 4;
}