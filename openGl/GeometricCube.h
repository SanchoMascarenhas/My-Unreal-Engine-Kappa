#pragma once
#include "GeometricObject.h"
#include "GeometryLib.h"
#include "Cube.h"

class GeometricCube :
	public GeometricObject
{
public:
	GeometricCube();
	float *getVertices();
	int getNumVertices();
	~GeometricCube();

private:
	float vertices[144];
};

