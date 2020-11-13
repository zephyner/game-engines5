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
	OpenGL = 0
};

class Renderer
{
public:

	Renderer();
	virtual ~Renderer();
	SDL_Window* OnCreate(std::string name_, int width_, int height_);

private:

	int width, height;
};

#endif // !RENDERER_H



