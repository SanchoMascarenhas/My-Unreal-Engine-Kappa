#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "MyMathLib.h"




#define M_PI       3.14159265358979323846f


Quaternion q0;

float DegToRad(float degrees){
	return (float)(degrees * (M_PI / 180.0f));
}

Matrix4x4 createOrthoProjectionMatrix(float right, float left, float top, float bottom, float n, float f) {

	Matrix4x4 T = Matrix4x4(1, 0, 0, -(left + right) / 2,
							0, 1, 0, -(top + bottom) / 2,
							0, 0, 1, -(n + f) / 2,
							0, 0, 0, 1);

	Matrix4x4 S = Matrix4x4(2 / (right - left), 0.0f, 0.0f, 0.0f,
							0.0f, 2 / (top - bottom), 0.0f, 0.0f,
							0.0f, 0.0f, 2 / (f - n), 0.0f,
							0.0f, 0.0f, 0.0f, 1.0f);

	Matrix4x4 I = Matrix4x4(1.0f, 0.0f, 0.0f, 0.0f,
							0.0f, 1.0f, 0.0f, 0.0f,
							0.0f, 0.0f, -1.0f, 0.0f,
							0.0f, 0.0f, 0.0f, 1.0f);

	return S*T*I;
}

Matrix4x4 createPerspectiveProjection(float fovy, float aspect, float znear, float zfar) {

	float theta = DegToRad(fovy/2);
	float d = 1 / tan(theta);

	return Matrix4x4(d / aspect, 0.0f, 0.0f, 0.0f,
		0.0f, d, 0.0f, 0.0f,
		0.0f, 0.0f, (znear + zfar) / (znear - zfar), 2 * znear*zfar / (znear - zfar),
		0.0f, 0.0f, -1, 1.0f);
}

Matrix4x4 createViewMatrix(float eyeX, float eyeY, float eyeZ,
	float centerX, float centerY, float centerZ,
	float upX, float upY, float upZ) {

	Vector3 View = Vector3(centerX - eyeX, centerY - eyeY, centerZ - eyeZ);
	Vector3 Up = Vector3(upX, upY, upZ);

	Vector3 V = View*(1 / View.norm());
	Vector3 Side = V.cross(Up);
	Vector3 S = Side*(1 / Side.norm());
	Vector3 U = S.cross(V);
	Matrix4x4 R = Matrix4x4(S, U, -V);
	Matrix4x4 M = R* Matrix4x4(1.0f, 0.0f, 0.0f, -eyeX,
		0.0f, 1.0f, 0.0f, -eyeY,
		0.0f, 0.0f, 1.0f, -eyeZ,
		0.0f, 0.0f, 0.0f, 1.0f);
	return M;
}

Matrix4x4 createViewMatrixQuat(float eyeX, float eyeY, float eyeZ,
	float centerX, float centerY, float centerZ,
	float upX, float upY, float upZ,
	Quaternion q1, Quaternion q2) {

	Matrix4x4 translation = Matrix4x4(1.0f, 0.0f, 0.0f, eyeX,
										0.0f, 1.0f, 0.0f, eyeY,
										0.0f, 0.0f, 1.0f, -eyeZ,
										0.0f, 0.0f, 0.0f, 1.0f);

	Quaternion multResult = q1 * q2;
	q0 = multResult * q0;

	Matrix4x4 result = translation * q0.toMatrix4x4();

	return result;

}

Matrix4x4 createRotation(float angleX, float angleY, float angleZ)
{
	float radX = DegToRad(angleX);
	Matrix4x4 rotationX = Matrix4x4(1, 0.0f, 0.0f, 0.0f,
		0.0f, cos(radX), -sin(radX), 0.0f,
		0.0f, sin(radX), cos(radX), 0.0f,
		0.0f, 0.0f, 0.0f, 1);

	float radY = DegToRad(angleY);
	Matrix4x4 rotationY = Matrix4x4(cos(radY), 0, sin(radY), 0.0f,
		0.0f, 1, 0.0f, 0.0f,
		-sin(radY), 0.0f, cos(radY), 0.0f,
		0.0f, 0.0f, 0.0f, 1);

	float radZ = DegToRad(angleZ);
	Matrix4x4 rotationZ = Matrix4x4(cos(radZ), -sin(radZ), 0.0f, 0.0f,
		sin(radZ), cos(radZ), 0.0f, 0.0f,
		0.0f, 0.0f, 1, 0.0f,
		0.0f, 0.0f, 0.0f, 1);

	return rotationZ*rotationY*rotationX;
}

Matrix4x4 createTranslation(float transX, float transY, float transZ){
	return Matrix4x4(1.0f, 0.0f, 0.0f, transX,
					0.0f, 1.0f, 0.0f, transY,
					0.0f, 0.0f, 1.0f, transZ,
					0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 createScale(float scaleX, float scaleY, float scaleZ){
	return Matrix4x4(scaleX,  0.0f,  0.0f,  0.0f,
					0.0f,  scaleY,  0.0f,  0.0f,
					0.0f,  0.0f,  scaleZ,  0.0f,
					0.0f,  0.0f,  0.0f,  1.0f );

}

Matrix4x4 createModelMatrix(float angleX, float angleY, float angleZ,
							float transX, float transY, float transZ,
							float scaleX, float scaleY, float scaleZ) {

	float radX = angleX*3.1415f / 180.0f;
	Matrix4x4 rotationX = Matrix4x4(1, 0.0f, 0.0f, 0.0f,
	0.0f, cos(radX), -sin(radX), 0.0f,
	0.0f, sin(radX), cos(radX), 0.0f,
	0.0f, 0.0f, 0.0f, 1);

	float radY = angleY*3.1415f / 180.0f;
	Matrix4x4 rotationY = Matrix4x4(cos(radY), 0, sin(radY), 0.0f,
	0.0f, 1, 0.0f, 0.0f,
	-sin(radY), 0.0f, cos(radY), 0.0f,
	0.0f, 0.0f, 0.0f, 1);

	float radZ = angleZ*3.1415f / 180.0f;
	Matrix4x4 rotationZ = Matrix4x4(cos(radZ), -sin(radZ), 0.0f, 0.0f,
	sin(radZ), cos(radZ), 0.0f, 0.0f,
	0.0f, 0.0f, 1 ,0.0f,
	0.0f, 0.0f, 0.0f, 1);

	Matrix4x4 rotation = rotationZ*rotationY*rotationX;

	Matrix4x4 translation = Matrix4x4(1.0f, 0.0f, 0.0f, transX,
	0.0f, 1.0f, 0.0f, transY,
	0.0f, 0.0f, 1.0f, transZ,
	0.0f, 0.0f, 0.0f, 1.0f);

	Matrix4x4 scale = Matrix4x4(scaleX,  0.0f,  0.0f,  0.0f,
	0.0f,  scaleY,  0.0f,  0.0f,
	0.0f,  0.0f,  scaleZ,  0.0f,
	0.0f,  0.0f,  0.0f,  1.0f );

	return translation*rotation*scale;

}

Matrix4x4 createModelFromMatrix(Matrix4x4 scale, Matrix4x4 rotation, Matrix4x4 translation){
	return translation*rotation*scale;
}

