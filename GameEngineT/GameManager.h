

#include <GL\glew.h>
#include "GameObject.h"
#include "RenderSystem.h"
#include "ResourceManager.h"
#include "MovementCore.h"
#include "CameraClass.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include "Scene.h"
#include "InputSys.h"

class GameManager
{
private:
    
    bool _running;
	float uFPS = 60.0f;
    RenderSystem *_renderSystem;
	ResourceManager *_resourceManager;
	CameraClass *_cameraClass;
	GLFWwindow *_window;
	MovementCore *_movement;
	Scene *scene;
	InputSys *_inputsystem;
    GameManager(bool running);
    ~GameManager();

public:

    void Loop();
    
    static GameManager& getGameManager();
    static void destroyGameManager();
    
};

