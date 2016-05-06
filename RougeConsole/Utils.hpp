#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

std::vector<std::string> slice(std::string line, char delim)
{
	std::vector<std::string> tokens;

	size_t pos = 0;
	while ((pos = line.find(delim)) != std::string::npos) {
		tokens.push_back(line.substr(0, pos));
		line.erase(0, pos + 1);
	}

	return tokens;
}

#endif