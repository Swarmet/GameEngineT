#include "VertexBuffer.h"

GLuint VertexBuffer::getVertexBufferID()
{
    return _vertexBufferID;
}

ShaderInterface *VertexBuffer::getShader()
{
    return _shader;
}

ShaderData *VertexBuffer::getShaderData()
{
	return _shaderData;
}

VertexBuffer::VertexBuffer(const GLvoid *data,
							GLsizeiptr size,
							GLenum mode,
							GLsizei count,
							GLsizei stride,
							ShaderInterface *shader,
							ShaderData *shaderData,
							GLvoid *positionOffset,
							GLvoid *normalOffset):
							_mode(mode), _count(count), _stride(stride), _shader(shader), _shaderData(shaderData),
	_positionOffset(positionOffset), _normalOffset(normalOffset)
{
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &_vertexBufferID);
    _vertexBufferID = 0;
}

void VertexBuffer::configureVertexAttributes()
{
		

		GLuint vao = _shader->getProgramHandle();
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);

		glEnableVertexAttribArray(_shader->get_aPositionVertex());
		glVertexAttribPointer(_shader->get_aPositionVertex(), 3, GL_FLOAT, GL_FALSE, _stride, _positionOffset);

		glVertexAttribPointer(_shader->get_aPositionNormal(), 3, GL_FLOAT, GL_FALSE, _stride, _normalOffset);
		glEnableVertexAttribArray(_shader->get_aPositionNormal());
	
	



}

void VertexBuffer::renderVertexBuffer()
{
	glBindVertexArray(_shader->getProgramHandle());
    glDrawArrays(_mode, 0, _count);

}