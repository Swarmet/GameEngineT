#include "GameObject.h"

std::string GameObject::getTag() {

	return _tag;

}

void GameObject::setTag(std::string newTag){

	_tag = newTag;

}

VertexBuffer *GameObject::getVertexBuffer()
{
	return _vertexBuffer;
}

void GameObject::setVertexBuffer(VertexBuffer *newVertexBuffer)
{
	_vertexBuffer = newVertexBuffer;
}

Vector3 GameObject::getPosition()
{
	return _position;
}

void GameObject::setPosition(Vector3 newPosition)
{
	_position = newPosition;
}

Vector3 GameObject::getScale()
{
	return _scale;
}

void GameObject::setScale(Vector3 newScale)
{
	_scale = newScale;
}

Vector3 GameObject::getRotation()
{
	return _rotation;
}

void GameObject::setRotation(Vector3 newRotation)
{
	_rotation = newRotation;
}

Vector3 GameObject::getVelocity()
{
	return _velocity;
}

void GameObject::setVelocity(Vector3 newVelocity)
{
	_velocity = newVelocity;
}

Vector3 GameObject::getScaleVelocity()
{
	return _scaleVelocity;
}

void GameObject::setScaleVelocity(Vector3 newScaleVelocity)
{
	_scaleVelocity = newScaleVelocity;
}

Vector3 GameObject::getRotationVelocity()
{
	return _rotationVelocity;
}

void GameObject::setRotationVelocity(Vector3 newRotationVelocity)
{
	_rotationVelocity = newRotationVelocity;
}

Vector3 GameObject::getCamVector()
{
	return _camVector;
}

void GameObject::setCamVector(Vector3 newCamVector)
{
	_camVector = newCamVector;
}

Vector3 GameObject::getUpVector()
{
	return _upVector;
}

void GameObject::setUpVector(Vector3 newUpVector)
{
	_upVector = newUpVector;
}

GameObject::GameObject(std::string tag, VertexBuffer *vertexBuffer, Vector3 position) : _tag(tag), _vertexBuffer(vertexBuffer), _position(position),
_scale(makeVector3(1.0f, 1.0f, 1.0f)), _rotation(makeVector3(0.0f, 0.0f, 0.0f)),
_velocity(makeVector3(0.0f, 0.0f, 0.0f)), _scaleVelocity(makeVector3(0.0f, 0.0f, 0.0f)),
_rotationVelocity(makeVector3(0.0f, 0.0f, 0.0f)), _camVector(makeVector3(0.0f, 0.0f, -1.0f)),
_upVector(makeVector3(0.0f, 1.0f, 0.0f))
{
}

GameObject::~GameObject()
{

}
