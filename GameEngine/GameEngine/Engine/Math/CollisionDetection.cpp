#include "CollisionDetection.h"
#include "Ray.h"
#include "../Core/CoreEngine.h"
CollisionDetection::~CollisionDetection()
{

}

Ray CollisionDetection::ScreenPosToWorldRay(glm::vec2 mouseCoords_, glm::vec2 screenSize_, Camera* camera_)
{
	glm::vec4 rayStart_NDC((mouseCoords_.x / screenSize_.x - 0.5f) * 2.0f, (mouseCoords_.y / screenSize_.y - 0.5f) * 2.0f,
		-1.0f, 1.0f);
	glm::vec4 rayEnd_NDC((mouseCoords_.x / screenSize_.x - 0.5f) * 2.0f, (mouseCoords_.y / screenSize_.y - 0.5f) * 2.0f,
		0.0f, 1.0f);

	glm::mat4 inverse = glm::inverse(camera_->GetPrespective() * camera_->GetView());

	glm::vec4 rayStart_World = inverse * rayStart_NDC;
	rayStart_World /= rayStart_World.w;

	glm::vec4 rayEnd_World = inverse * rayEnd_NDC;
	rayEnd_World /= rayEnd_World.w;

	glm::vec3 rayDir_World(rayEnd_World - rayStart_World);
	rayDir_World = glm::normalize(rayDir_World);

	return Ray(glm::vec3(rayStart_World), rayDir_World);
}
bool CollisionDetection::RayOBBIntersection(Ray* ray_, BoundingBox* box_)
{

	float tMax = CoreEngine::GetInstance()->GetCamera()->GetClippingPlanes().y;
	float tMin = CoreEngine::GetInstance()->GetCamera()->GetClippingPlanes().x;

	glm::vec3 OBBposition_World(box_->transform[3].x, box_->transform[3].y, box_->transform[3].z);
	glm::vec3 delta = OBBposition_World - ray_->origin;

	//X AXIS
	glm::vec3 xAxis(box_->transform[0].x, box_->transform[0].y, box_->transform[0].z);
	float e = glm::dot(xAxis, delta);
	float f = glm::dot(ray_->direction, xAxis);

	if (fabs(f) > 0.001f)
	{
		float t1 = (e + box_->minVert.x) / f;
		float t2 = (e + box_->maxVert.x) / f;

		if (t1 > t2)
		{
			float tmp = t1;
			t1 = t2;
			t2 = tmp;
		}

		if (t2 < tMax)
		{
			tMax = t2;
		}

		if (t1 > tMin)
		{
			tMin = t1;
		}

		if (tMax < tMin)
		{
			return false;
		}
	}
	else
	{
		if (-e + box_->minVert.x > 0.0f || -e + box_->maxVert.x < 0.0f)
		{
			return false;
		}
	}

	//HOMEWORK
//Y Axis
	glm::vec3 yAxis(box_->transform[1].x, box_->transform[1].y, box_->transform[1].z);
	float e1 = glm::dot(yAxis, delta);
	float f1= glm::dot(ray_->direction, yAxis);

	if (fabs(f1) > 0.001f)
	{
		float t3 = (e1 + box_->minVert.y) / f1;
		float t4 = (e1 + box_->maxVert.y) / f1;

		if (t3 > t4)
		{
			float tmp = t3;
			t3 = t4;
			t4 = tmp;
		}

		if (t4 < tMax)
		{
			tMax = t4;
		}

		if (t3 > tMin)
		{
			tMin = t3;
		}

		if (tMax < tMin)
		{
			return false;
		}
	}
	else
	{
		if (-e1 + box_->minVert.y > 0.0f || -e1 + box_->maxVert.y < 0.0f)
		{
			return false;
		}
	}
//Z Axis
	glm::vec3 zAxis(box_->transform[2].x, box_->transform[2].y, box_->transform[2].z);
	float e2 = glm::dot(zAxis, delta);
	float f2 = glm::dot(ray_->direction, zAxis);

	if (fabs(f2) > 0.001f)
	{
		float t5 = (e2 + box_->minVert.z) / f2;
		float t6 = (e2 + box_->maxVert.z) / f2;

		if (t5 > t6)
		{
			float tmp = t5;
			t5 = t6;
			t6 = tmp;
		}

		if (t6 < tMax)
		{
			tMax = t6;
		}

		if (t5 > tMin)
		{
			tMin = t5;
		}

		if (tMax < tMin)
		{
			return false;
		}
	}
	else
	{
		if (-e2 + box_->minVert.z > 0.0f || -e2 + box_->maxVert.z < 0.0f)
		{
			return false;
		}
	}
	ray_->intersectionDistance = tMin;
	return true;
}