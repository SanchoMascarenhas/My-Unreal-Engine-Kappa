#pragma once
#include "Matrix4x4.h"
#include "Quaternion.h"



float DegToRad(float degrees);

Matrix4x4 createRotation(float angleX, float angleY, float angleZ);
Matrix4x4 createTranslation(float transX, float transY, float transZ);
Matrix4x4 createScale(float scaleX, float scaleY, float scaleZ);

Matrix4x4 createOrthoProjectionMatrix(float right, float left, float top, float bottom, float n, float f);
Matrix4x4 createPerspectiveProjection(float fovy, float aspect, float znear, float zfar);
Matrix4x4 createModelFromMatrix(Matrix4x4 scale, Matrix4x4 rotation, Matrix4x4 translation);
Matrix4x4 createModelMatrix(float angleX, float angleY, float angleZ, float transX, float transY, float transZ, float scaleX, float scaleY, float scaleZ);
Matrix4x4 createViewMatrix(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
Matrix4x4 createViewMatrixQuat(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ, Quaternion q1, Quaternion q2);