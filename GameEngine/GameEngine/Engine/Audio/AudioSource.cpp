#include "AudioSource.h"
#include "AudioHandler.h"

AudioSource::AudioSource(std::string name_, bool loop_, bool is3d_, bool howPlay_)
{
	int channelId = -1;



}

AudioSource::~AudioSource()
{

}

bool AudioSource::OnCreate(GameObject* gameObject_)
{
	return 0;
}

void AudioSource::Update(const float deltaTime_)
{

}

int AudioSource::PlaySound()
{
	return 0;
}

bool AudioSource::IsPlaying()
{
	return false;
}
