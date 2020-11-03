#ifndef AUDIOSOURCE_H
#define AUDIOSOURCE_H
#include "../Rendering/3D/Component.h"
class AudioSource : public Component
{
public:

	AudioSource(std::string name_, bool loop_, bool is3d_, bool howPlay_);
	~AudioSource();
	void OnCreate();
	void Update();

	int PlaySound();
	bool IsPlaying();


private:


};

#endif // !AUDIOSOURCE_H