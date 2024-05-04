#pragma once
#include "glm/glm.hpp"

namespace Components 
{
	struct Transform
	{
		glm::vec3 position;

		Transform() : position(glm::vec3(0.0f, 0.0f, 0.0f)) {}
	};

	struct Camera 
	{
		Camera() {}
	};

	struct Mesh 
	{
	};
}