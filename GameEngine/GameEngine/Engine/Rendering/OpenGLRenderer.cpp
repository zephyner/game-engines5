#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer()
{
	
}

OpenGLRenderer::~OpenGLRenderer()
{
	OnDestroy();
}

bool OpenGLRenderer::OnCreate(std::string name_, int width_, int height_)
{
	return false;
}

void OpenGLRenderer::OnDestroy()
{
	
}

void Window::SetPreAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetSwapInterval(1);

	glewExperimental = GL_TRUE;
}

void Window::SetPostAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
}