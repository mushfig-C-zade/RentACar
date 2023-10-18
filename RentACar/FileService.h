#pragma once
#include <string>

#ifndef FILESERVICE
#define FILESERVICE

template<typename T>
class FileService
{
public:

	void Write(std::string path, T obj);

	T** Read(std::string path);
};

#endif
