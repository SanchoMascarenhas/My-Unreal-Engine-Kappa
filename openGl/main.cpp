#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "GL/glew.h"
#include "GL/freeglut.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
#include "MyMathLib.h"
#include "GeometricCube.h"
#include "GeometricPrism.h"
#include "GeometricHedron.h"
#include "Scenegraph.h"

#define CAPTION "  VERY Unreal Engine!  "

int WinX = 640, WinY = 480;
int WindowHandle = 0;
unsigned int FrameCount = 0;

#define VERTICES 0
#define COLORS 1
#define ORTHO 0
#define PERSPECTIVE 1
#define ON 1
#define OFF 0


// Camera Spherical Coordinates
float alpha = 0.0f, beta = 0.0f;
float r = 8.0f;

// Camera Position
float camX, camY, camZ;

// Mouse Tracking Variables
int startX, startY, startZ, tracking = 0;
int deltaX, deltaY;
float alphaAux, betaAux = 1.0f;

//Quaternion q0 = Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
int perspective = ORTHO;
int gimbalLock = ON;

int LastMousePositionX, LastMousePositionY;
float RotationAngleX = 0.0f;
float RotationAngleY = 0.0f;

/////////////////////////////////////////////////////////////////////// ERRORS

bool isOpenGLError() {
	bool isError = false;
	GLenum errCode;
	const GLubyte *errString;
	while ((errCode = glGetError()) != GL_NO_ERROR) {
		isError = true;
		errString = gluErrorString(errCode);
		std::cerr << "OpenGL ERROR [" << errString << "]." << std::endl;
	}
	return isError;
}

void checkOpenGLError(std::string error)
{
	if (isOpenGLError()) {
		std::cerr << error << std::endl;
		exit(EXIT_FAILURE);
	}
}

/////////////////////////////////////////////////////////////////////// SCENE

GeometricCube* cube = new GeometricCube();
GeometricPrism* prism = new GeometricPrism();
GeometricHedron* hedron = new GeometricHedron();
Scenegraph* graph;
SceneNode *root, *Tangram, *rhombohedron, *yellowPrism, *cianPrism, *magentaPrism, *orangePrism, *greenPrism, *redCube, *table;

void createGraph() {

	graph = new Scenegraph();
	root = graph->getRoot();
	
			
	Tangram = root->createNode(root);
	Tangram->setModelMatrix(createTranslation(0.0f, 0.0f, 0.0f));
	/**/
	yellowPrism = Tangram->createNode(Tangram);
	yellowPrism->setColor(Vector4(0.9f, 0.9f, 0.0f));
	yellowPrism->setMesh(prism);
	yellowPrism->createBuffers();
	yellowPrism->setModelMatrix(createTranslation(0.0f, 0.0f, 0.0f) *
		createRotation(0.0f, 0.0f, -90.0f) *
		createScale(0.5f, 0.5f, 0.5f));
	/**/
	cianPrism = Tangram->createNode(Tangram);
	cianPrism->setColor(Vector4(0.0f, 0.9f, 0.9f));
	cianPrism->setMesh(prism);
	cianPrism->createBuffers();
	cianPrism->setModelMatrix(createTranslation(0.0f, 0.0f, 0.0f) *
		createRotation(0.0f, 0.0f, 180.0f) *
		createScale(0.5f, 0.5f, 0.5f));
	/**/
	magentaPrism = Tangram->createNode(Tangram);
	magentaPrism->setColor(Vector4(0.9f, 0.0f, 0.9f));
	magentaPrism->setMesh(prism);
	magentaPrism->createBuffers();
	magentaPrism->setModelMatrix(createTranslation(0.5f, -0.5f, 0.0f) *
		createRotation(0.0f, 0.0f, 225.0f) *
		createScale(0.35f, 0.35f, 0.5f));
	/**/
	orangePrism = Tangram->createNode(Tangram);
	orangePrism->setColor(Vector4(0.9f, 0.5f, 0.0f));
	orangePrism->setMesh(prism);
	orangePrism->createBuffers();
	orangePrism->setModelMatrix(createTranslation(0.0f, 0.0f, 0.0f) *
		createRotation(0.0f, 0.0f, 90.0f) *
		createScale(0.25f, 0.25f, 0.5f));
	/**/
	greenPrism = Tangram->createNode(Tangram);
	greenPrism->setColor(Vector4(0.0f, 0.9f, 0.0f));
	greenPrism->setMesh(prism);
	greenPrism->createBuffers();
	greenPrism->setModelMatrix(createTranslation(-0.25f, -0.25f, 0.0f) *
		createRotation(0.0f, 0.0f, 0.0f) *
		createScale(0.25f, 0.25f, 0.5f));
	/**/
	redCube = Tangram->createNode(Tangram);
	redCube->setColor(Vector4(0.9f, 0.0f, 0.0f));
	redCube->setMesh(cube);
	redCube->createBuffers();
	redCube->setModelMatrix(createTranslation(0.0f, 0.0f, 0.0f) *
		createRotation(0.0f, 0.0f, -135.0f) *
		createScale(0.35f, 0.35f, 0.5f));
	/**/
	rhombohedron = Tangram->createNode(Tangram);
	rhombohedron->setColor(Vector4(0.7f, 0.0f, 0.4f));
	rhombohedron->setMesh(hedron);
	rhombohedron->createBuffers();
	rhombohedron->setModelMatrix(createTranslation(0.5f, 0.5f, 0.5f) *
			createRotation(0.0f, 180.0f, 90.0f) *
			createScale(0.5f, 0.25f, 0.5f));
	/**/
	table = root->createNode(root);
	table->setColor(Vector4(0.6f, 0.29f, 0.0f));
	table->setMesh(cube);
	table->createBuffers();
	table->setModelMatrix(createTranslation(-1.0f, -1.0f, -0.3f) *
		createScale(2.0f, 2.0f, 0.3f));
	/**/
}

void setViewMatrix() {
	graph->setViewMatrix(createViewMatrix(camX, camY, camZ, 0, 0, 0, 0, 1, 0).transpose());
}

void updateModels(Matrix4x4 model) {
	for each(SceneNode* n in root->getChildren()) {
		n->updateModelMatrix(model);
	}
}


void drawScene() {
	setViewMatrix();
	graph->draw();
}


// ------------------------------------------------------------
//
// Mouse Events
//

void processMouseButtons(int button, int state, int xx, int yy)
{
	// start tracking the mouse
	if (state == GLUT_DOWN) {
		startX = xx;
		startY = yy;
		if (button == GLUT_LEFT_BUTTON)
			tracking = 1;
		else if (button == GLUT_RIGHT_BUTTON)
			tracking = 2;
	}

	//stop tracking the mouse
	else if (state == GLUT_UP) {
		if (tracking == 1) {
			alpha -= (xx - startX);
			beta += (yy - startY);
		}
		else if (tracking == 2) {
			alpha -= (xx - startX);
			beta += (yy - startY);
		}
		tracking = 0;
	}
}

// Track mouse motion while buttons are pressed

void processMouseMotion(int xx, int yy)
{
	float rAux;

	deltaX = -xx + startX;
	deltaY = yy - startY;
	rAux = r;

	alphaAux = (alpha + deltaX);
	betaAux = (beta + deltaY);

	// left mouse button: move camera

	if (tracking == 1) {
		if (betaAux > 90.0f)
			betaAux = 90.0f;
		else if (betaAux < -90.0f)
			betaAux = -90.0f;
	}

	// right mouse button: zoom
	else if (tracking == 2) {
	}

	camX = rAux * sin(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
	camZ = rAux * cos(alphaAux * 3.14f / 180.0f) * cos(betaAux * 3.14f / 180.0f);
	camY = rAux *   						       sin(betaAux * 3.14f / 180.0f);

}

void mouse(int button, int state, int x, int y)
{
	LastMousePositionX = x;
	LastMousePositionY = y;

	if (state == GLUT_UP) {
		printf("up\n");
		RotationAngleX = RotationAngleY = 0.0f;
	}

}

void mouseMotion(int x, int y)
{
	float rAux;
	rAux = r;

	RotationAngleX = (float)(y - LastMousePositionY);
	LastMousePositionY = y;
	RotationAngleY = (float)(x - LastMousePositionX);
	LastMousePositionX = x;
	printf("rotationX: %f\nrotationY: %f\n", RotationAngleX, RotationAngleY);
	camX = rAux * sin(RotationAngleX * 3.14f / 180.0f) * cos(RotationAngleY * 3.14f / 180.0f);
	camZ = rAux * cos(RotationAngleX * 3.14f / 180.0f) * cos(RotationAngleY * 3.14f / 180.0f);
	camY = rAux *   									 sin(RotationAngleY * 3.14f / 180.0f);
	printf("camX: %f\ncamY: %f\ncamZ: %f\n", camX, camY, camZ);
}

void processKeys(unsigned char key, int xx, int yy)
{
	switch (key) {

	case 27:
		glutLeaveMainLoop();
		break;

	case 'p':
		if (perspective == ORTHO) {
			perspective = PERSPECTIVE;
		}
		else {
			perspective = ORTHO;
		}
		break;
	case 'g':
		if (gimbalLock == ON)
			gimbalLock = OFF;
		else
			gimbalLock = ON;
		break;
	case 'w':
		updateModels(createTranslation(0.0f, 0.1f, 0.0f));
		break;
	case 's':
		updateModels(createTranslation(0.0f, -0.1f, 0.0f));
		break;
	case 'a':
		updateModels(createTranslation(-0.1f, 0.0f, 0.0f));
		break;
	case 'd':
		updateModels(createTranslation(0.1f, 0.0f, 0.0f));
		break;
	}
}


/////////////////////////////////////////////////////////////////////// CALLBACKS

void cleanup()
{/*
	destroyShaderProgram();
	destroyBufferObjects();
	*/
}

void display()
{
	++FrameCount;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawScene();
	glutSwapBuffers();
}

void idle()
{
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	WinX = w;
	WinY = h;
	glViewport(0, 0, WinX, WinY);
}

void timer(int value)
{
	std::ostringstream oss;
	oss << CAPTION << ": " << FrameCount << " FPS @ (" << WinX << "x" << WinY << ")";
	std::string s = oss.str();
	glutSetWindow(WindowHandle);
	glutSetWindowTitle(s.c_str());
	FrameCount = 0;
	glutTimerFunc(1000, timer, 0);
}

/////////////////////////////////////////////////////////////////////// SETUP

void setupCallbacks()
{
	glutKeyboardFunc(processKeys);
	glutCloseFunc(cleanup);
	glutDisplayFunc(display);
	/**/
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);
	/** /
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	/ **/
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
}

void setupOpenGL() {
	std::cerr << "CONTEXT: OpenGL v" << glGetString(GL_VERSION) << std::endl;
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);
	glDepthRange(0.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
}

void setupGLEW() {
	glewExperimental = GL_TRUE;
	GLenum result = glewInit();
	if (result != GLEW_OK) {
		std::cerr << "ERROR glewInit: " << glewGetString(result) << std::endl;
		exit(EXIT_FAILURE);
	}
	GLenum err_code = glGetError();
}

void setupGLUT(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitContextVersion(3, 3);
	glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitWindowSize(WinX, WinY);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	WindowHandle = glutCreateWindow(CAPTION);
	if (WindowHandle < 1) {
		std::cerr << "ERROR: Could not create a new rendering window." << std::endl;
		exit(EXIT_FAILURE);
	}
}

void init(int argc, char* argv[])
{
	// set the camera position based on its spherical coordinates
	camX = r * sin(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f);
	camZ = r * cos(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f);
	camY = r *   						     sin(beta * 3.14f / 180.0f);

	setupGLUT(argc, argv);
	setupGLEW();
	setupOpenGL();
	createGraph();
	setupCallbacks();

}

int main(int argc, char* argv[])
{
	srand(1);
	init(argc, argv);
	glutMainLoop();
	exit(EXIT_SUCCESS);
}

///////////////////////////////////////////////////////////////////////