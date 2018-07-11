#pragma once
#include "GL/glew.h"
#include "GL/freeglut.h"

#include "TriPrism.h"
#include "Cube.h"
#include "Rhombohedron.h"
#include "GeometricObject.h"


#define VERTICES 0
#define COLORS 1

static int UBO = 3;

void createCube(GeometricObject* object);
void createTriPrism(GeometricObject* object);
void createRhomboHedron(GeometricObject* object);




