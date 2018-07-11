#pragma once
#include "Matrix4x4.h"

class Camera
{
public:
	Camera();
	Camera(Matrix4x4 newProj, Matrix4x4 newView);
	void setProjection(Matrix4x4 newP);
	Matrix4x4 getProjection();
	Matrix4x4 getView();
	void setView(Matrix4x4 newView);
	~Camera();

private:
	Matrix4x4 projection;
	Matrix4x4 view;
};

