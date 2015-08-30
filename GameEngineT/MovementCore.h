#pragma once
#include "GameObject.h"
#include "Vector3.h"
#include <GLFW\glfw3.h>

class MovementCore
{
private:

	MovementCore();
	~MovementCore();


public:
	void update(std::vector<GameObject *> *gameobjectArray);

	static MovementCore& getMovement();
	static void TerminateMovement();
	
};

