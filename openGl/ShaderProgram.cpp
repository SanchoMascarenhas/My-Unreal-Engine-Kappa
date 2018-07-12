#include <stdio.h>
#include <stdlib.h>
#include "ShaderProgram.h"
#include "GL/glew.h"
#include <assert.h>


GLenum ShaderProgram::spGLShaderTypes[ShaderProgram::COUNT_SHADER_TYPE] = {
	GL_VERTEX_SHADER,
	GL_GEOMETRY_SHADER,
	GL_TESS_CONTROL_SHADER,
	GL_TESS_EVALUATION_SHADER,
	GL_FRAGMENT_SHADER 
};

void ShaderProgram::init() {

	pInited = true;
	pProgram = glCreateProgram();
}

void ShaderProgram::loadShader(ShaderProgram::ShaderType st, std::string fileName){
	assert(pInited == true);

	char *s = NULL;

	s = textFileRead(fileName);

	if (s != NULL) {
		const char * ss = s;

		pShader[st] = glCreateShader(spGLShaderTypes[st]);
		glShaderSource(pShader[st], 1, &ss, NULL);
		glAttachShader(pProgram, pShader[st]);
		glCompileShader(pShader[st]);

		free(s);
	}
}

void ShaderProgram::destroyShaderProgram()
{
	glUseProgram(0);
	glDetachShader(pProgram, pShader[VERTEX_SHADER]);
	glDetachShader(pProgram, pShader[FRAGMENT_SHADER]);

	glDeleteShader(pShader[FRAGMENT_SHADER]);
	glDeleteShader(pShader[VERTEX_SHADER]);
	glDeleteProgram(pProgram);

	//checkOpenGLError("ERROR: Could not destroy shaders.");
}

void ShaderProgram::addAttribute(const GLchar* attribute, GLuint index) {
	glBindAttribLocation(pProgram, index, attribute);
	glLinkProgram(pProgram);
}


char * ShaderProgram::textFileRead(std::string fileName)
{
	FILE *fp = NULL;
	char *content = NULL;

	int count = 0;

	if (fileName != "") {
		fopen_s(&fp,fileName.c_str(), "rt");

		if (fp != NULL) {

			fseek(fp, 0, SEEK_END);
			count = ftell(fp);
			rewind(fp);

			if (count > 0) {
				content = (char *)malloc(sizeof(char) * (count + 1));
				count = fread(content, sizeof(char), count, fp);
				content[count] = '\0';
			}
			fclose(fp);
		}
	}
	return content;
}

GLuint ShaderProgram::getProgramIndex() {
	return pProgram;
}

ShaderProgram::ShaderProgram(){
}


ShaderProgram::~ShaderProgram(){
	/*
	if (pProgram)
		glDeleteProgram(pProgram);

	for (int i = 0; i < ShaderProgram::COUNT_SHADER_TYPE; ++i) {
		if (pShader[i]) {
			glAttachShader(pProgram, pShader[i]);
			glDeleteShader(pShader[i]);
		}
	}
	*/
}
