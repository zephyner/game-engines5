#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <string>
#include <iostream>
#include "../Core/Debug.h"

//enum class for different renderer types that the engine can support
enum class API
{
	OpenGL = 0, None = 1
};

class Renderer
{
public:

	Renderer();
	virtual ~Renderer();
	virtual bool OnCreate(std::string name_, int width_, int height_)
	{
		width = width_;
		height = height_;

		window = SDL_CreateWindow(name_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

		return window;
	}

	//API stored in static state
	static API s_API;
	
private:

	int width, height;
	SDL_Window* window;
};

#endif // !RENDERER_H



