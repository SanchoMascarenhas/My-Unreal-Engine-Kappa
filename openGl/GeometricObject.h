#pragma once
#include "Matrix4x4.h"
#include "Vector4.h"
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "ShaderProgram.h"

class GeometricObject
{
public:
	GeometricObject();
	virtual float *getVertices();
	virtual int getNumVertices();
	~GeometricObject();

};

