#pragma once
#include <vector>
#include "GeometricObject.h"
#include "Matrix4x4.h"
#include "ShaderProgram.h"
#include "Vector4.h"

static GLuint UBO_BP = 0;

class SceneNode
{
public:
	SceneNode();
	void setMesh(GeometricObject* newMesh);
	void setModelMatrix(Matrix4x4 newMatrix);
	void setProjectionMatrix(Matrix4x4 newProjection);
	void setViewMatrix(Matrix4x4 newView);
	void setColor(Vector4 newcolor);
	void setParent(SceneNode* newParent);
	void setProgram(ShaderProgram* shaders);
	void updateModelMatrix(Matrix4x4 model);
	ShaderProgram * getShaderProgram();
	SceneNode* createNode(SceneNode* newParent);
	Matrix4x4 getViewMatrix();
	Matrix4x4 getProjectionMatrix();
	std::vector<SceneNode*> getChildren();
	void createShaderProgram();
	void createBuffers();
	void destroyBufferObjects();
	void drawNode();
	void draw();
	void drawChildren();
	~SceneNode();

private:
	SceneNode *parent;
	std::vector<SceneNode*> children;
	GeometricObject* mesh;
	GLint UboId, UniformId;
	GLuint VaoId, VboId[3];
	Matrix4x4 modelMatrix;
	Matrix4x4 viewMatrix;
	Matrix4x4 projectionMatrix;
	ShaderProgram* program;
	Vector4 color;
};

