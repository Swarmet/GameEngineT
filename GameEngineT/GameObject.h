#pragma once
#include <iostream>
#include <string>
#include "VertexBuffer.h"
#include "Vector3.h"
#include <vector>



class GameObject
{
private:

	std::string _tag;

	VertexBuffer *_vertexBuffer;

	Vector3 _position;
	Vector3 _scale;
	Vector3 _rotation;

	Vector3 _velocity;
	Vector3 _scaleVelocity;
	Vector3 _rotationVelocity;

	Vector3 _camVector;
	Vector3 _upVector;

	


public:

	std::string getTag();
	void setTag(std::string newTag);

	VertexBuffer *getVertexBuffer();
	void setVertexBuffer(VertexBuffer *newVertexBuffer);

	Vector3 getPosition();
	void setPosition(Vector3 newPosition);

	Vector3 getScale();
	void setScale(Vector3 newScale);

	Vector3 getRotation();
	void setRotation(Vector3 newRotation);

	Vector3 getVelocity();
	void setVelocity(Vector3 newVelocity);

	Vector3 getScaleVelocity();
	void setScaleVelocity(Vector3 newScaleVelocity);

	Vector3 getRotationVelocity();
	void setRotationVelocity(Vector3 newRotationVelocity);

	Vector3 getCamVector();
	void setCamVector(Vector3 newCamVector);

	Vector3 getUpVector();
	void setUpVector(Vector3 newUpVector);

	GameObject(std::string tag, VertexBuffer *vertexBuffer, Vector3 position);
	~GameObject();
};