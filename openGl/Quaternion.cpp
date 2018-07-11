#include "Quaternion.h"
#include <sstream>


Quaternion::Quaternion()
{
}

Quaternion::Quaternion(float newT, float newX, float newY, float newZ){
	Vector3 axisn = Vector3(newX, newY, newZ).normalize();
	float a = newT * (float)DEGREES_TO_RADIANS;
	t = cos(a / 2.0f);
	float s = sin(a / 2.0f);
	v = axisn*s;
	clean();
}


Quaternion::Quaternion(float newT, Vector3 newV)
{
	Vector3 nv = newV.normalize();
	float a = newT * (float)DEGREES_TO_RADIANS;
	t = cos(a / 2.0f);
	float s = sin(a / 2.0f);
	v = nv*s;
	clean();
}

float Quaternion::quadrance()
{
	return t*t + v.getX()*v.getX() + v.getY()*v.getY() + v.getZ()*v.getZ();
}

Quaternion Quaternion::normalize()
{
	float s = 1 / norm();
	return Quaternion(t * s, v*s);
}

Quaternion Quaternion::conjugate()
{
	return Quaternion(t, -v);
}

Quaternion Quaternion::inverse()
{
	return Quaternion();
}

void Quaternion::clean()
{
	if (fabs(t) < qThreshold) t = 0.0f;
	if (fabs(v.getX()) < qThreshold) v.x = 0.0f;
	if (fabs(v.getY()) < qThreshold) v.y = 0.0f;
	if (fabs(v.getZ()) < qThreshold) v.z = 0.0f;
}

Matrix4x4 Quaternion::toMatrix4x4()
{
	Quaternion qn = normalize();
	float xx = qn.getX() * qn.getX();
	float xy = qn.getX() * qn.getY();
	float xz = qn.getX() * qn.getZ();
	float xt = qn.getX() * qn.t;
	float yy = qn.getY() * qn.getY();
	float yz = qn.getY() * qn.getZ();
	float yt = qn.getY() * qn.t;
	float zz = qn.getZ() * qn.getZ();
	float zt = qn.getZ() * qn.t;
	
	return Matrix4x4(1.0f - 2.0f * (yy + zz), 2.0f * (xy + zt), 2.0f * (xz - yt), 0.0f,
		2.0f * (xy - zt), 1.0f - 2.0f * (xx + zz), 2.0f * (yz + xt), 0.0f,
		2.0f * (xz + yt), 2.0f * (yz - xt), 1.0f - 2.0f * (xx + yy), 0.0f,
		0.0f			, 0.0f				, 0.0f					, 1.0f);
					
}

float Quaternion::norm()
{
	return sqrt(quadrance());
}

float Quaternion::getX()
{
	return v.getX();
}

float Quaternion::getY()
{
	return v.getY();
}

float Quaternion::getZ()
{
	return v.getZ();
}

Quaternion operator+(Quaternion &q0, Quaternion &q1) {
	return Quaternion(q0.t + q1.t, q0.v + q1.v);
}

Quaternion operator*(Quaternion &q0, Quaternion &q1) {
	float newT = q0.t * q1.t - q0.getX() * q1.getX() - q0.getY() * q1.getY() - q0.getZ() * q1.getZ();
	float newX = q0.t * q1.getX() + q0.getX() * q1.t + q0.getY() * q1.getZ() - q0.getZ() * q1.getY();
	float newY = q0.t * q1.getY() + q0.getY() * q1.t + q0.getZ() * q1.getX() - q0.getX() * q1.getZ();
	float newZ = q0.t * q1.getZ() + q0.getZ() * q1.t + q0.getX() * q1.getY() - q0.getY() * q1.getX();

	return Quaternion(newT, newX, newY, newZ);
}

Quaternion operator*(Quaternion &q, float s) {
	return Quaternion(q.t*s, q.v*s);
}

Quaternion operator*(float s, Quaternion &q) {
	return Quaternion(q.t*s, q.v*s);
}


Quaternion::~Quaternion()
{
}
