//#ifndef AUDIOHANDLER_H
//#define AUDIOHANDLER_H
//
//#include <string>
//#include <map>
//#include <memory>
//#include <fmod.hpp>
//#include <glm/glm.hpp>
//#include "../Core/Debug.h"
//#include "AudioSource.h"
//
//class AudioHandler
//{
//public:
//	AudioHandler(const AudioHandler&) = delete;
//	AudioHandler(AudioHandler&&) = delete;
//
//	AudioHandler& operator = (const AudioHandler&) = delete;
//	AudioHandler& operator = (const AudioHandler&&) = delete;
//
//	static AudioHandler* GetInstance();
//	bool Initialize(glm::vec3 pos_, glm::vec3 vel_, glm::vec3 forward_, glm::vec3 up_);
//	void OnDestroy();
//
//private:
//	AudioHandler();
//	~AudioHandler();
//
//	static std::unique_ptr<AudioHandler> audioInstnace;
//	friend std::default_delete<AudioHandler>;
//
//	FMOD::System* fmodSystem;
//	static std::map<std::string, FMOD::Sound*> soundMap;
//	static std::map<int, FMOD::Channel*> channelMap;
//	int channels;
//
//	FMOD_VECTOR glmToFmod(glm::vec3 vector_);
//	void loadSound(std::string name_, bool loop_, bool is3d_, bool howPlay_);
//	FMOD::Sound* getSound(std::string name_);
//	int playSound(std::string name_, glm::vec3 pos_, glm::vec3 vel_, float volume);
//	void Update(int channelID_, glm::vec3 pos_, glm::vec3 vel_);
//	bool isPlaying(int channelID_);
//
//	friend class AudioSource;
//
//};
//
//#endif // !AUDIOHANDLER_H