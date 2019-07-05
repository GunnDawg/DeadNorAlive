#pragma once

class IndexBuffer
{
public:
	IndexBuffer();
	IndexBuffer(const GLuint* data, GLuint count);
	~IndexBuffer();

	void Bind() const ;
	void Unbind() const;

	void Draw();

	inline GLuint GetCount() const { return mCount; }

private:
	GLuint mRendererID = 0;
	GLuint mCount = 0;
	const GLuint* mData = nullptr;

	GLuint mIndices;
};