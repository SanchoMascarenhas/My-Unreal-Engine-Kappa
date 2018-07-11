#include "GeometricPrism.h"



GeometricPrism::GeometricPrism()
{
	for (int i = 0; i < 96; i++) {
		vertices[i] = PrismVertices[i];
	}
}

float * GeometricPrism::getVertices()
{
	return vertices;
}

int GeometricPrism::getNumVertices()
{
	return 24;
}


GeometricPrism::~GeometricPrism()
{
}
