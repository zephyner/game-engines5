#include "ParticleEmitter.h"


ParticleEmitter::ParticleEmitter(int numberOfParticles_, std::string shaderProgramName_)
{
	numberOfParticles = numberOfParticles_;
	shaderProgramName = ShaderHandler::GetInstance()->GetShader(shaderProgramName_);

	if (ShaderHandler::GetInstance()->GetShader(shaderProgramName_) == 0)
	{
		std::cout << "Particles not rendered because no shader found";
		return;
	}
	else
	{
		std::vector<int> Particles;
		Particles.reserve(numberOfParticles_);
		for (int i = 0; i < numberOfParticles; i++)
		{
			 new Particle(shaderProgramName);
		

		}
	}
}

void ParticleEmitter::RNG()
{
	
}

