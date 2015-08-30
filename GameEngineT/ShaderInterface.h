#ifndef __ShaderInterface__
#define __ShaderInterface__

#include <string>
#include <iostream>
#include <fstream>
#include "ShaderLoader.h"

class ShaderInterface
{
private:
    
    ShaderLoader *shader;
	
    GLint _aPositionVertex;
	GLint _aPositionNormal;
    GLint _uColor;
	GLint _uLightPosition;
    
	
    
	std::string loadTextFromFile(std::string shader_file);
    
public:
    
    GLuint getProgramHandle();
    GLint get_aPositionVertex();
	GLint get_aPositionNormal();
    GLint get_uColor();
	GLint get_uLightPosition();
    
	ShaderInterface(std::string VS, std::string FS);
    ~ShaderInterface();

};
#endif