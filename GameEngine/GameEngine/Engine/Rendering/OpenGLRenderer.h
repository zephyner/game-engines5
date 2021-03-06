#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Renderer.h"

class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	SDL_Window* OnCreate(std::string name_, int width_, int height_);
	void OnDestroy();

private:
	void SetPreAttributes();
	void SetPostAttributes();
	int width, height;
	SDL_Window* window;
	SDL_GLContext context;
};

#endif // !OPENGLRENDERER_H



