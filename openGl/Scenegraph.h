#pragma once
#include "SceneNode.h"
#include "Camera.h"
#include "MyMathLib.h"


enum CameraType {
	ORTHO,
	PERSPECTIVE
};


class Scenegraph
{
	
	
public:

	Scenegraph();
	SceneNode *createSceneNode();
	Camera *getActiveCamera();
	SceneNode *getRoot();
	void changeActiveCamera();
	void setViewMatrix(Matrix4x4 newView);
	void draw();
	~Scenegraph();

private:
	SceneNode *root;
	Camera *cameras[2];
	Camera *activeCamera;
	int cameraIndex;
};

