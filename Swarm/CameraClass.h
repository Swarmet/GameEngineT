#pragma once

#include "GameObject.h"


class CameraClass
{
private:

	GameObject *_Camera;
	CameraClass();
	~CameraClass();

public:

	GameObject *getCamera();
	void setCamera(GameObject *newCam);

	static CameraClass& getCameraClass();
	static void TerminateCamera();
	
};

