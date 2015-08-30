#pragma once
#include "GameObject.h"
#include <vector>;
#include "CameraClass.h";
#include "ResourceManager.h"

class Scene
{

private:

	ResourceManager *_resourceManager;
	std::vector<GameObject *> *_children;

public:

	std::vector<GameObject *> *getChildren();

	Scene();
	~Scene();
};

