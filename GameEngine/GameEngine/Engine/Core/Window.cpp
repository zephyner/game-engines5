#include "Window.h"

Window::Window() 
{
	width = 0;
	height = 0;
	window = nullptr;


}

Window::~Window()
{
	OnDestroy();
}

bool Window::OnCreate(std::string name_, int width_, int height_)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Debug::FatalError("Failed to initialize SDL", "Window.cpp", __LINE__);
		return false;
	}

	

	width = width_;
	height = height_;

	////call to set the pre attributes
	//SetPreAttributes();

	////call to create window
	//window = SDL_CreateWindow(name_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	////verify window created properly, if not make sure to return nullptr
	//if (!window)// window == nullptr
	//{
	//	Debug::Error("Failed to Create Window", "OpenGLRenderer.cpp", __LINE__);
	//	return false;
	//}

	////create context and set post attributes
	//context = SDL_GL_CreateContext(window);
	//SetPostAttributes();

	////set up GLEW
	//GLenum error = glewInit();

	//if (error != GLEW_OK)
	//{
	//	Debug::Error("Failed to initialize GLEW", "Window.cpp", __LINE__);
	//	return false;
	//}

	////call to enable Depth Testing
	//glEnable(GL_DEPTH_TEST);

	////call to set up the opengl viewport
	//glViewport(0, 0, width, height);

	return true;
}
void Window:: OnDestroy()
{
	//SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	window = nullptr;
}
int Window::GetWidth()
{
	return width;
}

int Window :: GetHeight()
{
	return height;
}


SDL_Window* Window::GetWindow() const
{
	
	return window;
}

//void Window::SetPreAttributes()
//{
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
//	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
//	SDL_GL_SetSwapInterval(1);
//
//	glewExperimental = GL_TRUE;
//}
//
//void Window::SetPostAttributes()
//{
//	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
//}