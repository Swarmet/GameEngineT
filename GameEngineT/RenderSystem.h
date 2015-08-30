

#ifndef __RenderSystem__
#define __RenderSystem__

#include "GameObject.h"
#include "CameraClass.h"
#include <GL\GL.h>
#include <GL\GLU.h>
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>


class RenderSystem
{
private:
    
	CameraClass *_cameraClass;
	GameObject *camera;
    GLFWwindow *_window;

    RenderSystem();
    ~RenderSystem();
    
public:
    

    
    void render(std::vector<GameObject*> *gameobjectArray);
    
    static RenderSystem& getRenderSystem();
    static void destroyRenderSystem();
    
};

#endif 
