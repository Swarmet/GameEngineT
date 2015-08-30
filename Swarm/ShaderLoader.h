#ifndef __ShaderLoader__
#define __ShaderLoader__


#include <iostream>
#include <GL/glew.h>

class ShaderLoader {
private:
    
    GLuint _programHandle;
    
    GLuint compileShader(GLenum shader, const  char *source);
    
public:
    
    GLuint getProgramHandle();
    
    ShaderLoader(const char *sourceVS, const char *sourceFS);
    ~ShaderLoader();

};
#endif