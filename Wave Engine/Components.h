#pragma once
#include "glm/glm.hpp"
#include <vector>

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
		std::vector<float> _vertices;
		std::vector<uint16_t> _indices;
		std::vector<float> _uvs;

		Mesh() 
		{
			_vertices = 
			{
				-0.5f, -0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				0.5f, 0.5f, 0.0f,
				-0.5f, 0.5f, 0.0f,
				
				-0.5f, -0.5f, 1.0f,
				0.5f, -0.5f, 1.0f,
				0.5f, 0.5f, 1.0f,
				-0.5f, 0.5f, 1.0f,
			};

			_indices =
			{
				0, 1, 2,
				2, 3, 0,
				4, 5, 6,
				6, 7, 4
			};

			_uvs = {};
		}
	};
}