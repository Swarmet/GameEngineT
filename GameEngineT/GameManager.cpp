#include "GameManager.h"
#include <glm.hpp>

GameManager::GameManager(bool running) : _running(running), _window(glfwGetCurrentContext()), _renderSystem(&RenderSystem::getRenderSystem()), _resourceManager(&ResourceManager::getResourceManage()), _movement(&MovementCore::getMovement()), _cameraClass(&CameraClass::getCameraClass()), _inputsystem(&InputSys::getInputSys())
{

	scene = new Scene();
	
}

GameManager::~GameManager()
{
  
	CameraClass::TerminateCamera();
	ResourceManager::destroyResourcemanager();
    RenderSystem::destroyRenderSystem();
	InputSys::TerminateInputSys();

}

void GameManager::Loop()
{
    
	float prevTime = glfwGetTime();
	float deltaTime = 0.0f;

	while (_running) {

		float nowTime = glfwGetTime();
		deltaTime += (nowTime - prevTime) * uFPS;
		prevTime = nowTime;
		
		while (deltaTime >= 1.0f) {
			
			_running = !glfwWindowShouldClose(_window);
			_inputsystem->update();
			_movement->update(scene->getChildren());
			

			--deltaTime;

		}

		_renderSystem->render(scene->getChildren());
	}

}

GameManager& GameManager::getGameManager()
{

    static GameManager *gameManager = NULL;
    
    if (gameManager == NULL) {
		glfwInit();
      
        
        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);
        glfwWindowHint(GLFW_SAMPLES, 32);

        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        GLFWwindow *window = glfwCreateWindow(1280, 720, "Simple FPS", NULL, NULL);
        glfwMakeContextCurrent(window);
        
		
		glewExperimental = GL_TRUE;
		glewInit();

        gameManager = new GameManager(true);
        
        std::cout << "GameManager created" << std::endl;
    }
    
    return *gameManager;

}

void GameManager::destroyGameManager()
{

    GameManager *gameManager = &getGameManager();
    delete gameManager;
    
    std::cout << "GameManager destroyed" << std::endl;
    
    GLFWwindow *window = glfwGetCurrentContext();
    glfwDestroyWindow(window);
    
    glfwTerminate();
    
}