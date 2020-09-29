#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "../FX/LightSource.h"
class Camera
{
public:
	Camera();
	~Camera();
	glm::vec3 GetPosition();
	void SetPosition(glm::vec3 position_);
	void SetRotation(float yaw_, float pitch_);

	glm::mat4 GetView() const;
	glm::mat4 GetPrespective() const;
	glm::mat4 getOrthographic() const;

	void ProcessMouseMovement(glm::vec2 offset_);
	void ProcessMouseZoom(int y_);

	void AddLightSources(LightSource* light_);
	std::vector<LightSource*> GetLightSource();

	glm::vec2 GetClippingPlanes() const;

	void OnDestroy();
private:
	void UpdateCameraVector();
	glm::vec3 position;
	glm::mat4 perspective, orthographic;
	float fieldOfView;
	float yaw, pitch;
	float nearPlane, farPlane;
	glm::vec3 forward, up, right, worldUp;

	std::vector<LightSource*> lightSources;

};
#endif // !CAMERA_H


