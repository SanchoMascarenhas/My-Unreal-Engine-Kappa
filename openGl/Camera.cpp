#include "Camera.h"



Camera::Camera()
{
}

Camera::Camera(Matrix4x4 newProj, Matrix4x4 newView)
{
	projection = newProj;
	view = newView;
}

void Camera::setProjection(Matrix4x4 newP)
{
	projection = newP;
}

Matrix4x4 Camera::getProjection()
{
	return projection;
}


Matrix4x4 Camera::getView()
{
	return view;
}

void Camera::setView(Matrix4x4 newView)
{
	view = newView;
}

Camera::~Camera()
{
}
