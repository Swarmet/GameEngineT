#include "Scene.h"
#include "InputSys.h"


std::vector<GameObject *>* Scene::getChildren(){

	return _children;

}

Scene::Scene()
{

	_children = new std::vector<GameObject *>();
	_resourceManager = &ResourceManager::getResourceManage();

	Vector3 pos = makeVector3(.0f, .0f, .0f);

	
	GameObject *socketa = new GameObject("socket", _resourceManager->getVertexBufferArray()->at(0), pos );
	socketa->setCamVector(normalizeVector3(makeVector3(0.0f, 0.0f, -1.0f)));

	InputSys *inputsystem = &InputSys::getInputSys();
	inputsystem->setCurrentSelected(socketa);

	_children->push_back(socketa);

	GameObject *socketb = new GameObject("socket", _resourceManager->getVertexBufferArray()->at(1), makeVector3(1.8f, 1.0f, 0.0f));
	socketb->setCamVector(normalizeVector3(makeVector3(0.0f, 0.0f, -1.0f)));
	_children->push_back(socketb);
	
	GameObject *socketc = new GameObject("socket", _resourceManager->getVertexBufferArray()->at(2), makeVector3(1.8f,1.0f,0.0f));
	socketc->setCamVector(normalizeVector3(makeVector3(0.0f, 0.0f, -1.0f)));
	_children->push_back(socketc);

	
	GameObject *camera = new GameObject("camera", NULL, makeVector3(3.0f, 3.0f, 15.0f));
	camera->setCamVector(normalizeVector3(makeVector3(0.0f, 0.0f, -1.0f)));

	CameraClass *_cameraClass = &CameraClass::getCameraClass();
	_cameraClass->setCamera(camera);

	_children->push_back(camera);

}


Scene::~Scene()
{
	for (std::vector<GameObject *>::iterator iterator = _children->begin(); iterator != _children->end(); ++iterator)
	{
		delete *iterator;
	}
	delete _children;
}
