#include "PCH.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const GLuint* data, GLuint count) :
	mCount(count), mData(data)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));

	GLuint Indices[] =
	{
		0, 1, 2,	//right
		0, 2, 3,	//bottom
		0, 3, 4,	//left
		0, 4, 1		//top
	};

	mIndices = *Indices;

	glGenBuffers(1, &mRendererID);
}

IndexBuffer::IndexBuffer()
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));

	glGenBuffers(1, &mRendererID);

	const GLuint Indices[] =
	{
		0, 1, 2,	//right
		0, 2, 3,	//bottom
		0, 3, 4,	//left
		0, 4, 1		//top
	};

	mIndices = *Indices;
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &mRendererID);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 12 * sizeof(GLuint), &mIndices, GL_STATIC_DRAW);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::Draw()
{
	GLCall(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr));
}