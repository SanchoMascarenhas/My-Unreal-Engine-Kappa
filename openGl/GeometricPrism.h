#pragma once
#include "GeometricObject.h"
#include "TriPrism.h"
class GeometricPrism :
	public GeometricObject
{
public:
	GeometricPrism();
	float *getVertices();
	int getNumVertices();
	~GeometricPrism();


private:
	float vertices[96];
};

