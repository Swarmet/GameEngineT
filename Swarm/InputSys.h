#pragma once
#include <iostream>
#include "GameObject.h"
#include "Vector2.h"
#include <GLFW\glfw3.h>


class InputSys
{

	InputSys();
	~InputSys();
	
	Vector2 _lastMousePosition;
	Vector3 _CamVector;

	GameObject *_currentSelected;
	GLFWwindow *_window;
	void keyCallback(GLFWwindow *widnow, int key, int secancode, int action, int mods);

public:

	void setCurrentSelected(GameObject *newSelected);

	void update();
	static InputSys& getInputSys();
	static void TerminateInputSys();

	static void keyCallbackFun(GLFWwindow *widnow, int key, int secancode, int action, int mods);
	
};

