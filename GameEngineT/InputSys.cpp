#include "InputSys.h"

void InputSys::keyCallback(GLFWwindow *widnow, int key, int scancode, int action, int mods){

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
		if (GLFW_CURSOR_DISABLED == glfwGetInputMode(glfwGetCurrentContext(), GLFW_CURSOR)){

			glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);

		}
		else {
			glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
	}

	Vector2 currentMousePosition;
	glfwGetCursorPos(_window, &currentMousePosition.x, &currentMousePosition.y);
	std::cout << "test" << scancode << std::endl;

}

void InputSys::keyCallbackFun(GLFWwindow *widnow, int key, int scancode, int action, int mods){

	InputSys *inputsys = &getInputSys();
	inputsys->keyCallback(widnow, key, scancode, action, mods);

}

InputSys& InputSys::getInputSys(){

	static InputSys *inputsys = NULL;
	if (!inputsys){

		glfwSetKeyCallback(glfwGetCurrentContext(), *keyCallbackFun);
		glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		inputsys = new InputSys();

	}

	return *inputsys;

}

void InputSys::setCurrentSelected(GameObject *newSelected){

	_currentSelected = newSelected;
	_CamVector = normalizeVector3(newSelected->getCamVector());

}


void InputSys::update(){

	if (_currentSelected != NULL && glfwGetInputMode(glfwGetCurrentContext(), GLFW_CURSOR) == GLFW_CURSOR_DISABLED){

		if (glfwGetKey(_window, GLFW_KEY_W)){
			//_currentSelected->setPosition(addVector3(_currentSelected->getPosition(), scalerMultiplyVector3(_CamVector, 0.07f)));
			_currentSelected->setPosition(subtractVector3(_currentSelected->getPosition(), scalerMultiplyVector3(crossProductVector3(_CamVector, makeVector3(1.0f, 0.0f, 0.0f)), 0.007f)));
		}

		if (glfwGetKey(_window, GLFW_KEY_S)){
			//_currentSelected->setPosition(subtractVector3(_currentSelected->getPosition(), scalerMultiplyVector3(_CamVector, 0.07f)));
			_currentSelected->setPosition( addVector3(_currentSelected->getPosition(), scalerMultiplyVector3(crossProductVector3(_CamVector, makeVector3(1.0f, 0.0f, 0.0f)), 0.007f)));
		}

		if (glfwGetKey(_window, GLFW_KEY_A)){
			_currentSelected->setPosition(subtractVector3(_currentSelected->getPosition(), scalerMultiplyVector3(crossProductVector3(_CamVector, makeVector3(0.0f, 1.0f, 0.0f)), 0.007f)));

		}

		if (glfwGetKey(_window, GLFW_KEY_D)){
			_currentSelected->setPosition(addVector3(_currentSelected->getPosition(), scalerMultiplyVector3(crossProductVector3(_CamVector, makeVector3(0.0f, 1.0f, 0.0f)), 0.007f)));

		}
		/*
		Vector2 currentMousePosition;
		glfwGetCursorPos(_window, &currentMousePosition.x, &currentMousePosition.y);

		_CamVector = transformVector3(_CamVector, makeRotationMatrix3((3.14f / (4.0f*45.0f))*-(currentMousePosition.x - _lastMousePosition.x), 1.0f, 0.0f, 0.0f));

		glfwGetCursorPos(_window, &_lastMousePosition.x, &_lastMousePosition.y);

		*/
		_currentSelected->setCamVector(addVector3(_currentSelected->getPosition(), _CamVector));
	
	}

}


void InputSys::TerminateInputSys(){


}


InputSys::InputSys() : _window(glfwGetCurrentContext())
{
	glfwGetCursorPos(_window, &_lastMousePosition.x, &_lastMousePosition.y);
}


InputSys::~InputSys()
{
}
