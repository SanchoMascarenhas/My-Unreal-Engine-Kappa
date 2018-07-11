#include "SceneNode.h"


#define VERTICES 0
#define COLORS 1

SceneNode::SceneNode()
{
	program = new ShaderProgram();
	createShaderProgram();
}

SceneNode* SceneNode::createNode(SceneNode* newParent)
{
	SceneNode *n = new SceneNode();
	n->setParent(newParent);

	//n->setProgram(newParent->getShaderProgram());
	n->setProjectionMatrix(newParent->getProjectionMatrix());
	n->setViewMatrix(newParent->getViewMatrix());
	children.push_back(n);
	return n;
}

void SceneNode::setMesh(GeometricObject * newMesh)
{
	mesh = newMesh;

}

void SceneNode::setModelMatrix(Matrix4x4 newMatrix)
{
	modelMatrix = newMatrix;
}


void SceneNode::setProjectionMatrix(Matrix4x4  newProjection)
{
	projectionMatrix = newProjection;
}

void SceneNode::setViewMatrix(Matrix4x4  newView)
{
	viewMatrix = newView;
	for each(SceneNode* n in children) {
		n->setViewMatrix(newView);
	}
}

void SceneNode::setColor(Vector4 newcolor)
{
	color = newcolor;
}

void SceneNode::setParent(SceneNode * newParent)
{
	parent = newParent;
}

void SceneNode::setProgram(ShaderProgram * shaders)
{
	program = shaders;
}

void SceneNode::updateModelMatrix(Matrix4x4 model)
{
	modelMatrix = model * modelMatrix;
	for each(SceneNode* n in children) {
		n->updateModelMatrix(model);
	}
}

ShaderProgram * SceneNode::getShaderProgram()
{
	return program;
}


Matrix4x4  SceneNode::getViewMatrix()
{
	return viewMatrix;
}

Matrix4x4  SceneNode::getProjectionMatrix()
{
	return projectionMatrix;
}

std::vector<SceneNode*> SceneNode::getChildren()
{
	return children;
}

void SceneNode::createShaderProgram()
{
	program->init();
	program->loadShader(ShaderProgram::VERTEX_SHADER, "Shaders/SimpleVertexShader.vert");
	program->loadShader(ShaderProgram::FRAGMENT_SHADER, "Shaders/SimpleFragmentShader.frag");
	program->addAttribute("in_Position", VERTICES);
	program->addAttribute("in_Color", COLORS);
	glLinkProgram(program->getProgramIndex());
	UniformId = glGetUniformLocation(program->getProgramIndex(), "ModelMatrix");
	UboId = glGetUniformBlockIndex(program->getProgramIndex(), "SharedMatrices");
	glUniformBlockBinding(program->getProgramIndex(), UboId, UBO_BP);
}

void SceneNode::createBuffers(){
	glGenVertexArrays(1, &VaoId);

		glBindVertexArray(VaoId);
		{
			glGenBuffers(3, VboId);

			glBindBuffer(GL_ARRAY_BUFFER, VboId[0]);
			glBufferData(GL_ARRAY_BUFFER, 4 * 4 * mesh->getNumVertices(), mesh->getVertices(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(VERTICES);
			glVertexAttribPointer(VERTICES, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *)0);

			const int arraySize = mesh->getNumVertices() * 4;
			float* colorArray = new float[arraySize];
			for (int i = 0; i < arraySize; i += 4) {
				colorArray[0 + i] = color.getX();
				colorArray[1 + i] = color.getY();
				colorArray[2 + i] = color.getZ();
				colorArray[3 + i] = 1.0f;
			}
			glBindBuffer(GL_ARRAY_BUFFER, VboId[1]);
			glBufferData(GL_ARRAY_BUFFER, 4 * arraySize, colorArray, GL_STATIC_DRAW);
			glEnableVertexAttribArray(COLORS);
			glVertexAttribPointer(COLORS, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *)0);
			
			glBindBuffer(GL_UNIFORM_BUFFER, VboId[2]);
			glBufferData(GL_UNIFORM_BUFFER,  16 * 4 * 2, 0, GL_STREAM_DRAW);
			glBindBufferBase(GL_UNIFORM_BUFFER, UBO_BP, VboId[2]);
		}

		//checkOpenGLError("ERROR: Could not create VAOs and VBOs.");
}

void SceneNode::destroyBufferObjects()
{
	 glBindVertexArray(VaoId);
	 glDisableVertexAttribArray(VERTICES);
	 glDisableVertexAttribArray(COLORS);
	 glDeleteBuffers(3, VboId);
	 glDeleteVertexArrays(1, &VaoId);
	 glBindBuffer(GL_ARRAY_BUFFER, 0);
	 glBindBuffer(GL_UNIFORM_BUFFER, 0);
	 glBindVertexArray(0);

	 //checkOpenGLError("ERROR: Could not destroy VAOs and VBOs.");
 
}



void SceneNode::drawNode()
{
	if (mesh != NULL)
		draw();
	if (!children.empty())
		drawChildren();
	
}

void SceneNode::draw()
{
	glUseProgram(program->getProgramIndex());
	glBindBuffer(GL_UNIFORM_BUFFER, VboId[2]);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, 16*4, viewMatrix.toFloatArray());
	glBufferSubData(GL_UNIFORM_BUFFER, 16*4, 16*4, projectionMatrix.toFloatArray());
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	
	glBindVertexArray(VaoId);
	glUniformMatrix4fv(UniformId, 1, GL_FALSE, modelMatrix.transpose().toFloatArray());
	glDrawArrays(GL_TRIANGLES, 0, mesh->getNumVertices());
	glBindVertexArray(0);

	glUseProgram(0);
	glBindVertexArray(0);
}



void SceneNode::drawChildren()
{
	for each(SceneNode* n in children) {
		n->drawNode();
	}
}

SceneNode::~SceneNode()
{
}
