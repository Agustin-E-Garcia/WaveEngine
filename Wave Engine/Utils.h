#pragma once
#include <fstream>
#include <vector>

namespace Utils
{
	static std::vector<char> ReadFile(const std::string& filename)
	{
		std::vector<char> buffer;
		std::ifstream file(filename, std::ios::ate | std::ios::binary);

		if (!file.is_open()) return buffer;

		size_t fileSize = (size_t)file.tellg();
		buffer.reserve(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}
};