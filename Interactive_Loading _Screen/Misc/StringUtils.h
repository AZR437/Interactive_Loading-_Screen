#pragma once
#include "string"
#include "vector"
#include "sstream"
namespace misc
{
	class StringUtils
	{
	public:
		static std::vector<std::string> split(const std::string& s, char delimiter);
	};
}
