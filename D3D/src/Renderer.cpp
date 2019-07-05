#include "PCH.h"
#include "Renderer.h"

#include <gl/wglext.h>

PFNWGLCREATECONTEXTATTRIBSARBPROC
wglCreateContextAttribsARB = nullptr;

PFNWGLSWAPINTERVALEXTPROC
wglSwapInterval = nullptr;

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << "\n";
		return false;
	}

	return true;
}

bool InitializeOpenGL(const HDC& hDc, HGLRC& bootstrap, HGLRC& modern)
{
	typedef PIXELFORMATDESCRIPTOR PFD;

	PFD DesiredPixelFormat				= { 0 };
	DesiredPixelFormat.nSize			= sizeof(DesiredPixelFormat);
	DesiredPixelFormat.nVersion			= 1;
	DesiredPixelFormat.dwFlags			= PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
	DesiredPixelFormat.cColorBits		= 32;
	DesiredPixelFormat.cRedBits			= 8;
	DesiredPixelFormat.cGreenBits		= 8;
	DesiredPixelFormat.cBlueBits		= 8;
	DesiredPixelFormat.cAlphaBits		= 8;
	DesiredPixelFormat.cStencilBits		= 8;
	//(NOTE): This is no longer used according to MSDN.
		//DesiredPixelFormat.iLayerType		= PFD_MAIN_PLANE;

	PFD SuggestedPixelFormat = { 0 };
	int SuggestedPixelFormatIndex = ChoosePixelFormat(hDc, &DesiredPixelFormat);
	DescribePixelFormat(hDc, SuggestedPixelFormatIndex, sizeof(SuggestedPixelFormat), &SuggestedPixelFormat);
	if (!SetPixelFormat(hDc, SuggestedPixelFormatIndex, &SuggestedPixelFormat))
	{
		std::cout << "Error setting Pixel Format!\n";
		return(false);
	}

	int attribs[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0,
	};

	bootstrap = wglCreateContext(hDc);
	if (!wglMakeCurrent(hDc, bootstrap))
	{
		std::cout << "Error creating OpenGL Context\n";
		return(false);
	}
	else
	{
		wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
		wglSwapInterval = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
		modern = wglCreateContextAttribsARB(hDc, bootstrap, attribs);
		if (!wglMakeCurrent(hDc, modern))
		{
			std::cout << "Error creating OpenGL Context with Attribs!\n";
			return(false);
		}

		wglDeleteContext(bootstrap);
		bootstrap = nullptr;
	}

	wglSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error starting GLEW!\n";
		return(false);
	}

#ifdef _DEBUG
	std::cout << "OpenGL: " << glGetString(GL_VERSION) << "\n";
#endif

	return(true);
}

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}