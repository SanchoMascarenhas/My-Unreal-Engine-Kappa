#include "GeometricCube.h"



GeometricCube::GeometricCube()
{
	for (int i = 0; i < 144; i++) {
		vertices[i] = CubeVertices[i];
	}
}




float * GeometricCube::getVertices()
{
	return vertices;
}

int GeometricCube::getNumVertices()
{
	return 36;
}


GeometricCube::~GeometricCube()
{
}
