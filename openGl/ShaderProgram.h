#pragma once
#include <string>
#include "GL/glew.h"
class ShaderProgram
{
public:

	enum ShaderType {
		VERTEX_SHADER,
		GEOMETRY_SHADER,
		TESS_CONTROL_SHADER,
		TESS_EVAL_SHADER,
		FRAGMENT_SHADER,
		COUNT_SHADER_TYPE
	};

	bool pInited;
	GLuint pShader[ShaderProgram::COUNT_SHADER_TYPE];
	GLuint pProgram;
	static GLenum spGLShaderTypes[ShaderProgram::COUNT_SHADER_TYPE];

	void loadShader(ShaderProgram::ShaderType st, std::string fileName);
	void destroyShaderProgram();
	void addAttribute(const GLchar* attribute, GLuint index);
	char *textFileRead(std::string fileName);
	GLuint getProgramIndex();

	void init();
	ShaderProgram();
	~ShaderProgram();
};

