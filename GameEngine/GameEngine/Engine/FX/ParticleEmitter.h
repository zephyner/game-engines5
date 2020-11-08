#ifndef ParticleEmitter_H
#define ParticleEmitter_H

#include "Particle.h";



class ParticleEmitter
{
public:
	//not using texture ID
	int numberOfParticles;
	GLuint shaderProgramName;
	ParticleEmitter(int numberOfParticles_, std::string shaderProgramName_);
	void RNG();
};

#endif

