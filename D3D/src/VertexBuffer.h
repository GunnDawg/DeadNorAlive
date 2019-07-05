#pragma once

class VertexBuffer
{
public:
	VertexBuffer();
	VertexBuffer(const void* data, GLuint size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

private:
	GLuint mRendererID = 0;
	const void* mData;
	GLuint mSize;
	GLfloat* mVertices;
};