#pragma once
class Vector4
{
public:
	Vector4();
	Vector4(float x, float y, float z);
	int getSize();
	float getX();
	float getY();
	float getZ();
	float *toFloatArray();
	~Vector4();

private:

	float x;
	float y;
	float z;
	float w;
	int size;
	void init(float newx, float newy, float newz);
	float array[4];
};

