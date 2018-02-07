#pragma once
#include<GL\glew.h>
#include <string>

using namespace std;
class Shader
{
public:
	Shader();
	~Shader();
	//Compiles the shaders from GLSL and makes them usable in OpenGL
	void shaderCompiler(const string& vertShaderPath, const string& fragShaderPath);
	//Links the shaders together into the program
	void shaderLinker();
	//Used to bind attributes such as vertex positions and colours etc.
	void createAttribute(const string& attributeName);
	//Allows for a program to be bound
	void bindShader();
	//Allows for a program to be unbound... wow!
	void unbindShader();
private:
	//Stores how many attributes the program currently has
	int _numAttributes;
	//A generic way to compile multiple types of shaders
	void compileShader(const string& shaderFilePath, GLuint id);
	//This stores the final shader program
	GLuint _program;
	//This stores the vertex shader
	GLuint _vertShader;
	//This stores the fragment shader
	GLuint _fragShader;
};
