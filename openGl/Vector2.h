#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	Vector2 plus(Vector2 addVector);
	Vector2 minus(Vector2 subtractVector);
	float norm();
	float dot(Vector2 dotVector);
	Vector2 mult(float scalar);
	float cross(Vector2 v);
	int getSize();
	float getX();
	float getY();
	~Vector2();

private:
	float x;
	float y;
	int size;
	void init(float newx, float newy);
};

