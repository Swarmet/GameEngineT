#include "MovementCore.h"
#include <math.h>

void MovementCore::update(std::vector<GameObject *> *gameobjectArray){


	for (std::vector<GameObject *>::iterator iterator = gameobjectArray->begin(); iterator != gameobjectArray->end(); ++iterator) {

		GameObject *gameobject = *iterator;
		 if (gameobject->getTag() == "socket"){

			// std::cout << gameobject->getPosition().x << ',' << gameobject->getPosition().y << std::endl;
			


		}


	}

}




MovementCore& MovementCore::getMovement(){

	static MovementCore* movement = NULL;
	if (!movement){

		movement = new MovementCore();
	
	}

	return *movement;

}
void MovementCore::TerminateMovement(){

	MovementCore *movement = &getMovement();

	delete movement;

}

MovementCore::MovementCore()
{
}


MovementCore::~MovementCore()
{
}
