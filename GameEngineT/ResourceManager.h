#pragma once
#include <iostream>
#include <vector>
#include "ShaderInterface.h"
#include "VertexBuffer.h"
#include "ShaderData.h"

class ResourceManager
{

private:

	std::vector <ShaderInterface *> *_shaderArray;
	std::vector <VertexBuffer *> *_vertexBufferArray;
	ShaderData *shaderData;


	ResourceManager();
	~ResourceManager();


public:
	
	std::vector <ShaderInterface *> *getShaderArray();
	std::vector <VertexBuffer *> *getVertexBufferArray();

	static ResourceManager& getResourceManage();
	static void destroyResourcemanager();
};


