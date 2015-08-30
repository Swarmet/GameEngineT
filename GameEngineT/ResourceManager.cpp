#include "ResourceManager.h"
#include "CubeVertices.h"
#include "TriangleVertices.h"


std::vector <ShaderInterface *> *ResourceManager::getShaderArray(){

	return _shaderArray;

}



std::vector <VertexBuffer *> *ResourceManager::getVertexBufferArray(){

	return _vertexBufferArray;

}

ResourceManager::ResourceManager()
{

	_shaderArray = new std::vector<ShaderInterface *>();
	ShaderInterface *shader = new ShaderInterface("ColorShader.vsh", "ColorShader.fsh");
	_shaderArray->push_back(shader);
	ShaderInterface *lightShader = new ShaderInterface("SimpleLightShader.vsh", "SimpleLightShader.fsh");
	_shaderArray->push_back(lightShader);


	shaderData = new ShaderData(makeVector4(0.5f, 0.5f, 0.8f, 1.0f), makeVector3(0.0f, 0.0f, 0.0f));


	_vertexBufferArray = new std::vector<VertexBuffer *>();
	
	VertexBuffer *cubeVertexBuffert = new VertexBuffer(cubeVertices,
		sizeof(cubeVertices),
		GL_TRIANGLES,
		36,
		sizeof(VertexDataPN),
		_shaderArray->at(1),
		shaderData,
		(GLvoid *)(offsetof(VertexDataPN, positionCoordinates)),
		(GLvoid *)(offsetof(VertexDataPN, normalCoordinates))
		);
	_vertexBufferArray->push_back(cubeVertexBuffert);

	VertexBuffer *cubeVertexBuffer = new VertexBuffer(cubeVertices,
		sizeof(cubeVertices),
		GL_TRIANGLES,
		36,
		sizeof(VertexDataPN),
		_shaderArray->at(1),
		shaderData,
		(GLvoid *)(offsetof(VertexDataPN, positionCoordinates)),
		(GLvoid *)(offsetof(VertexDataPN, normalCoordinates))
		);
	_vertexBufferArray->push_back(cubeVertexBuffer);

	VertexBuffer *cubeVertexBuffera = new VertexBuffer(cubeVertices,
		sizeof(cubeVertices),
		GL_TRIANGLES,
		36,
		sizeof(VertexDataPN),
		_shaderArray->at(1),
		shaderData,
		(GLvoid *)(offsetof(VertexDataPN, positionCoordinates)),
		(GLvoid *)(offsetof(VertexDataPN, normalCoordinates))
		);
	_vertexBufferArray->push_back(cubeVertexBuffera);

}


ResourceManager::~ResourceManager()
{
	for (std::vector<ShaderInterface *>::iterator iterator = _shaderArray->begin(); iterator != _shaderArray->end(); ++iterator){

		delete *iterator;

	}
	delete _shaderArray;

	for (std::vector<VertexBuffer *>::iterator iterator = _vertexBufferArray->begin(); iterator != _vertexBufferArray->end(); ++iterator){
		
		delete *iterator;

	}
	delete shaderData;

	delete _vertexBufferArray;
		
}


ResourceManager& ResourceManager::getResourceManage(){

	static ResourceManager *resourceManager = NULL;

	if (resourceManager == NULL) {

		resourceManager = new ResourceManager();

	}

	return *resourceManager;

}

void ResourceManager::destroyResourcemanager(){

	ResourceManager *resourceManager = &getResourceManage();
	delete resourceManager;

}
