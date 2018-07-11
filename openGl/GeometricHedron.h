#pragma once
#include "GeometricObject.h"
#include "Rhombohedron.h"
class GeometricHedron :
	public GeometricObject
{
public:
	GeometricHedron();
	float *getVertices();
	int getNumVertices();
	~GeometricHedron();

private:
	float vertices[144];
};

