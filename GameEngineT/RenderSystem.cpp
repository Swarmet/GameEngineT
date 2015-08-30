
#include "RenderSystem.h"


RenderSystem::RenderSystem() : _window(glfwGetCurrentContext()), _cameraClass(&CameraClass::getCameraClass())
{
	
}

RenderSystem::~RenderSystem()
{
	
}

void RenderSystem::render(std::vector<GameObject *> *gameobjectArray)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	for (std::vector<GameObject *>::iterator iterator = gameobjectArray->begin(); iterator != gameobjectArray->end(); ++iterator)
	{
		GameObject *gameobject = *iterator;
		
		if (gameobject->getVertexBuffer() != NULL){
			
			glUseProgram(gameobject->getVertexBuffer()->getShader()->getProgramHandle()); 
			
			
			glTranslatef(gameobject->getPosition().x, gameobject->getPosition().y, gameobject->getPosition().z);
			glRotatef(gameobject->getRotation().x, 0.0f, 0.0f, 1.0f);
			glRotatef(gameobject->getRotation().y, 0.0f, 1.0f, 0.0f);
			glRotatef(gameobject->getRotation().z, 1.0f, 0.0f, 0.0f);

			glScalef(gameobject->getScale().x, gameobject->getScale().y, gameobject->getScale().z);

			glUniform4f((gameobject->getVertexBuffer()->getShader())->get_uColor(),
				(gameobject->getVertexBuffer()->getShaderData())->get_uColorValue().x,
				(gameobject->getVertexBuffer()->getShaderData())->get_uColorValue().y,
				(gameobject->getVertexBuffer()->getShaderData())->get_uColorValue().z,
				(gameobject->getVertexBuffer()->getShaderData())->get_uColorValue().w
				);

			glUniform3f((gameobject->getVertexBuffer()->getShader())->get_uLightPosition(),
				(gameobject->getVertexBuffer()->getShaderData())->get_uLightPosition().x,
				(gameobject->getVertexBuffer()->getShaderData())->get_uLightPosition().y,
				(gameobject->getVertexBuffer()->getShaderData())->get_uLightPosition().z);



			gameobject->getVertexBuffer()->configureVertexAttributes();
			gameobject->getVertexBuffer()->renderVertexBuffer();

		}
		else {

			camera = _cameraClass->getCamera();

			glLoadIdentity();

			gluLookAt(
				camera->getPosition().x, camera->getPosition().y, camera->getPosition().z,
				camera->getCamVector().x, camera->getCamVector().y, camera->getCamVector().z,
				camera->getUpVector().x, camera->getUpVector().y, camera->getUpVector().z );
			glfwSwapBuffers(_window);
		}

		
		glfwPollEvents();
	}
	
}

RenderSystem& RenderSystem::getRenderSystem()
{
    static RenderSystem *renderSystem = NULL;
    
    if (renderSystem == NULL) {
        renderSystem = new RenderSystem();
		
        glClearColor(0.3f, 0.5f, 0.0f, 1.0f);
        
        glMatrixMode(GL_PROJECTION);
        gluPerspective(65.0f, 1280.0f/720.0f, 0.01f, 1000);
        glViewport(0.0f, 0.0f, 1280.0f, 720.0f);
        glMatrixMode(GL_MODELVIEW);
        
		glEnable(GL_CULL_FACE);
		
		
    }
    
    return *renderSystem;
}

void RenderSystem::destroyRenderSystem()
{
    RenderSystem *renderSystem = &getRenderSystem();
    delete renderSystem;
}
