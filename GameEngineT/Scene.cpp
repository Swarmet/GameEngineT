#include "Scene.h"
#include "InputSys.h"


std::vector<GameObject *>* Scene::getChildren(){

	return _children;

}

Scene::Scene()
{

	_children = new std::vector<GameObject *>();
	_resourceManager = &ResourceManager::getResourceManage();

	Vector3 pos = makeVector3(0.0f, 0.0f, 0.0f);
	GameObject *socketb = new GameObject("socket", _resourceManager->getVertexBufferArray()->at(0), makeVector3(-5.0f, .0f, .0f));
	socketb->setCamVector(normalizeVector3(makeVector3(0.0f, 0.0f, -5.0f)));
	_children->push_back(socketb);
	for (int i = 0; i < 100; ++i) {

		pos.x = 0.0f;
		for (int j = 0; j < 20; ++j){
			GameObject *socketa = new GameObject("socket", _resourceManager->getVertexBufferArray()->at(0), pos);
			socketa->setCamVector(normalizeVector3(makeVector3(0.0f, 0.0f, -1.0f)));
			_children->push_back(socketa);

			pos.x += 1.2f;
		}

		pos.y += 1.2f;
	}
	



	GameObject *camera = new GameObject("camera", NULL, makeVector3(0.0f, 0.0f, 15.0f));
	camera->setCamVector(makeVector3(0.0f, 0.0f, -16.0f));
	
	InputSys *inputsystem = &InputSys::getInputSys();
	inputsystem->setCurrentSelected(socketb);

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
