#include "Vector2.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <sstream>
#include <string>



Vector2::Vector2(){
}

Vector2::Vector2(float x, float y){
	init(x, y);
}

Vector2 Vector2::plus(Vector2 addVector){
	return Vector2(x + addVector.getX(), y + addVector.getY());
}

Vector2 Vector2::minus(Vector2 subtractVector){
	return Vector2(x - subtractVector.getX(), y - subtractVector.getY());
}

float Vector2::dot(Vector2 dotVector){
	return x * dotVector.getX() + y * dotVector.getY();
}

Vector2 Vector2::mult(float scalar){
	return Vector2(scalar * x, scalar * y);
}

float Vector2::cross(Vector2 v) {
	printf("Cross: %f - %f = %f\n", x*v.getY(), y*getX(), x*v.getY() - y*v.getX());
	return x*v.getY() - y*v.getX();
}

float Vector2::norm() {
	return sqrt(x*x + y*y);
}

int Vector2::getSize(){
	return size;
}

float Vector2::getX() {
	return x;
}

float Vector2::getY() {
	return y;
}




Vector2::~Vector2(){
}

void Vector2::init(float newx, float newy){
	x = newx;
	y = newy;
	size = 2;
}
