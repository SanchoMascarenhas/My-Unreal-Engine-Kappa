#include "GeometricHedron.h"



GeometricHedron::GeometricHedron()
{
	for (int i = 0; i < 144; i++) {
		vertices[i] = RhombohedronVertices[i];
	}
}

float * GeometricHedron::getVertices()
{
	return vertices;
}


int GeometricHedron::getNumVertices()
{
	return 36;
}

GeometricHedron::~GeometricHedron()
{
}
