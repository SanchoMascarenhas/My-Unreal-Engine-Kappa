#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	Vector3 plus(Vector3 addVector);
	Vector3 minus(Vector3 subtractVector);
	float norm();
	float dot(Vector3 dotVector);
	Vector3 normalize();
	Vector3 mult(float scalar);
	Vector3 cross(Vector3 v);
	friend Vector3 operator-(Vector3 &v);
	friend Vector3 operator-(Vector3 &v1, Vector3 &v2);
	friend Vector3 operator*(float scalar, Vector3 &v2);
	friend Vector3 operator*(Vector3 &v1, float scalar);
	friend Vector3 operator+(Vector3 &v1, Vector3 &v2);
	int getSize();
	float getX();
	float getY();
	float getZ();
	~Vector3();


	float x;
	float y;
	float z;

private:

	int size;
	void init(float newx, float newy, float newz);
};

