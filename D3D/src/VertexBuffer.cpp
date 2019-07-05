#include "PCH.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, GLuint size) :
	mData(&data), mSize(size)
{
	glGenBuffers(1, &mRendererID);

	GLfloat Vertices[] =
	{	//POSITION(0)			//COLOR(1)
		 0.0f,  0.0f, 0.0f,		1.0f, 0.0f, 0.0f,	//0 - center
		 0.5f,  0.5f, 0.0f,		1.0f, 1.0f, 1.0f,	//1
		 0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 1.0f,	//2
		-0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 1.0f,	//3
		-0.5f,  0.5f, 0.0f,		1.0f, 1.0f, 1.0f	//4
	};

	mVertices = Vertices;
}

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &mRendererID);

	GLfloat Vertices[] =
	{	//POSITION(0)			//COLOR(1)
		 0.0f,  0.0f, 0.0f,		1.0f, 0.0f, 0.0f,	//0 - center
		 0.5f,  0.5f, 0.0f,		1.0f, 1.0f, 1.0f,	//1
		 0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 1.0f,	//2
		-0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 1.0f,	//3
		-0.5f,  0.5f, 0.0f,		1.0f, 1.0f, 1.0f	//4
	};

	mVertices = Vertices;
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &mRendererID);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, mRendererID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}