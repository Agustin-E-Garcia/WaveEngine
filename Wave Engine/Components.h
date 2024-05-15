#pragma once
#include "glm/glm.hpp"
#include <vector>
#include "glm/gtc/matrix_transform.hpp"

namespace Components 
{
	struct Transform
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
		Transform() : position(glm::vec3(0.0f, 0.0f, 0.0f)), rotation(glm::vec3(0.0f, 0.0f, 0.0f)), scale(glm::vec3(0.0f, 0.0f, 0.0f)) {}

		glm::mat4 GetModelMatrix() { return glm::translate(glm::mat4(1.0f), position); }
	};

	struct Camera 
	{
		Camera() {}
	};

	struct Mesh 
	{
		const char* modelName;

		std::vector<float> _vertices;
		std::vector<uint16_t> _indices;
		std::vector<float> _uvs;

		Mesh(const char* name)
		{
			modelName = name;

			_vertices = 
			{
				-0.5f, -0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				0.5f, 0.5f, 0.0f,
				-0.5f, 0.5f, 0.0f,
				
				//-0.5f, -0.5f, 1.0f,
				//0.5f, -0.5f, 1.0f,
				//0.5f, 0.5f, 1.0f,
				//-0.5f, 0.5f, 1.0f,
			};

			_indices =
			{
				0, 1, 2,
				2, 3, 0,
				//4, 5, 6,
				//6, 7, 4
			};

			_uvs = {};
		}
	};
}