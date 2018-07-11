#include "Scenegraph.h"



Scenegraph::Scenegraph()
{
	cameras[0] = new Camera(createOrthoProjectionMatrix(1.5f, -1.5f, 1.5f, -1.5f, 0.1f, 20).transpose(), createViewMatrix(5, 0, 5, 0, 0, 0, 0, 1, 0).transpose());
	cameras[1] = new Camera(createPerspectiveProjection(30, 640 / 480, 0.1f, 10).transpose(), createViewMatrix(0, 0, 8, 0, 0, 0, 0, 1, 0).transpose());
	activeCamera = cameras[1];
	cameraIndex = PERSPECTIVE;
	root = new SceneNode();
	root->setViewMatrix(activeCamera->getView());
	root->setProjectionMatrix(activeCamera->getProjection());
}

SceneNode * Scenegraph::createSceneNode()
{
	SceneNode* node = new SceneNode();
	node->setProjectionMatrix(activeCamera->getProjection());
	node->setViewMatrix(activeCamera->getView());
	node->setModelMatrix(createTranslation(0.0f, 0.0f, 0.0f));
	return node;
}

Camera * Scenegraph::getActiveCamera()
{
	return activeCamera;
}

SceneNode * Scenegraph::getRoot()
{
	return root;
}

void Scenegraph::changeActiveCamera()
{
	if (cameraIndex) {
		activeCamera = cameras[ORTHO];
		cameraIndex = ORTHO;
	}
	else {
		activeCamera = cameras[PERSPECTIVE];
		cameraIndex = PERSPECTIVE;
	}
}

void Scenegraph::setViewMatrix(Matrix4x4 newView)
{
	cameras[0]->setView(newView);
	cameras[1]->setView(newView);
	root->setViewMatrix(newView);
}


void Scenegraph::draw()
{
	root->drawNode();
}

Scenegraph::~Scenegraph()
{
}
