#pragma once
class Matrix2x2
{
public:
	Matrix2x2();
	Matrix2x2(float x1, float y1, float x2, float y2);
	friend Matrix2x2 operator-(Matrix2x2 &v);
	friend Matrix2x2 operator-(Matrix2x2 &v1, Matrix2x2 &v2);
	friend Matrix2x2 operator+(Matrix2x2 &v1, Matrix2x2 &v2);
	friend Matrix2x2 operator*(Matrix2x2 &v1, float scalar);
	friend Matrix2x2 operator*(float scalar, Matrix2x2 &v1);
	Matrix2x2 asterisk();
	Matrix2x2 transpose();
	Matrix2x2 inverse();
	float calcDeterminant();
	float getX1();
	float getY1();
	float getX2();
	float getY2();
	float getDet();
	~Matrix2x2();


private:
	float x1;
	float y1;
	float x2;
	float y2;
	float determinant;
};

