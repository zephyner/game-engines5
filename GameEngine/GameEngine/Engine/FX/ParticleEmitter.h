#ifndef ParticleEmitter_H
#define ParticleEmitter_H
#include "../Math/Randomizer.h";
#include "../Rendering/SceneGraph.h";
#include "Particle.h";




class ParticleEmitter
{
public:

    //not using texture ID
    int numberOfParticles;
    float lowNumber, highNumber;
    GLuint shaderProgramName;
    ParticleEmitter(int numberOfParticles_, std::string shaderProgramName_);
    float RNG();
private:
    std::vector<Particle*> VectorParticles;
};

#endif