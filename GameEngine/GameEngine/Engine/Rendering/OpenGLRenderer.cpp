#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer()
{
	width = 0;
	height = 0;
	window = nullptr;
}

OpenGLRenderer::~OpenGLRenderer()
{
	OnDestroy();
}

SDL_Window* OpenGLRenderer::OnCreate(std::string name_, int width_, int height_)
{

	//call to set the pre attributes
	SetPreAttributes();

	//call to create window
	SDL_Window* window = SDL_CreateWindow(name_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	//verify window created properly, if not make sure to return nullptr
	if (!window)// window == nullptr
	{
		Debug::Error("Failed to Create Window", "OpenGLRenderer.cpp", __LINE__);
		return nullptr;
	}
	
	//create context and set post attributes
	context = SDL_GL_CreateContext(window);
	SetPostAttributes();

	//set up GLEW
	GLenum error = glewInit();

	if (error != GLEW_OK)
	{
		Debug::Error("Failed to initialize GLEW", "Window.cpp", __LINE__);
		return nullptr;
	}

	//call to enable Depth Testing
	glEnable(GL_DEPTH_TEST);

	//call to set up the opengl viewport
	glViewport(0, 0, width, height);

	return 0;
}

void OpenGLRenderer::OnDestroy()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	window = nullptr;
}

void OpenGLRenderer::SetPreAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetSwapInterval(1);

	glewExperimental = GL_TRUE;
}

void OpenGLRenderer::SetPostAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
}