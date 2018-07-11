#include "GeometryLib.h"

/*

void createCube(GeometricObject* object) {
	
	glGenVertexArrays(1, object->getObjectVaoPosition());
	glBindVertexArray(object->getObjectVao());

	GLuint buffers[3];
	glGenBuffers(3, buffers);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(CubeVertices), CubeVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VERTICES);
	glVertexAttribPointer(VERTICES, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(CubeVertices), object->getColorArray(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(COLORS);
	glVertexAttribPointer(COLORS, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_UNIFORM_BUFFER, buffers[2]);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(GLfloat) * 16 * 2, 0, GL_STREAM_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, UBO++, buffers[2]);

	
	// unbind the VAO
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(VERTICES);
	glDisableVertexAttribArray(COLORS);
	
}

void createTriPrism(GeometricObject* object) {

	glGenVertexArrays(1, object->getObjectVaoPosition());
	glBindVertexArray(object->getObjectVao());

	GLuint buffers[2];
	glGenBuffers(2, buffers);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(PrismVertices) * 2, PrismVertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(VERTICES);
	glVertexAttribPointer(VERTICES, 4, GL_FLOAT, 0, 0, 0);

	glEnableVertexAttribArray(COLORS);
	glVertexAttribPointer(COLORS, 4, GL_FLOAT, GL_FALSE, sizeof(object->getColorArray()), 0);

	glBindBuffer(GL_UNIFORM_BUFFER, buffers[1]);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(GLfloat) * 16 * 2, 0, GL_STREAM_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, UBO++, buffers[1]);


	// unbind the VAO
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(VERTICES);
	glDisableVertexAttribArray(COLORS);

}

void createRhomboHedron(GeometricObject* object) {

	glGenVertexArrays(1, object->getObjectVaoPosition());
	glBindVertexArray(object->getObjectVao());

	GLuint buffers[2];
	glGenBuffers(2, buffers);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(RhombohedronVertices) * 2, RhombohedronVertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(VERTICES);
	glVertexAttribPointer(VERTICES, 4, GL_FLOAT, 0, 0, 0);

	glEnableVertexAttribArray(COLORS);
	glVertexAttribPointer(COLORS, 4, GL_FLOAT, GL_FALSE, sizeof(object->getColorArray()), (GLvoid *)sizeof(object->getColorArray()));

	glBindBuffer(GL_UNIFORM_BUFFER, buffers[1]);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(GLfloat) * 16 * 2, 0, GL_STREAM_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, UBO++, buffers[1]);


	// unbind the VAO
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(VERTICES);
	glDisableVertexAttribArray(COLORS);

}

*/