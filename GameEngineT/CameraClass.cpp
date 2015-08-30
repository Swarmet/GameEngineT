#include "CameraClass.h"


GameObject *CameraClass::getCamera(){

	return _Camera;

}
void CameraClass::setCamera(GameObject *newCam){
	_Camera = newCam;
}

CameraClass& CameraClass::getCameraClass(){
	static CameraClass *camera = NULL;
	if (!camera){
		camera = new CameraClass();
	}

	return *camera;

}

void CameraClass::TerminateCamera(){

	CameraClass *cameraClass = &getCameraClass();
	delete cameraClass;

}


CameraClass::CameraClass()
{
}


CameraClass::~CameraClass()
{
}


