#include "FileService.h"
#include <fstream>
#include <string>

template<typename T>
void FileService<T>::Write(std::string path, T obj)
{
	std::ofstream fout(path, std::ios_base::binary);

	if (fout.is_open())
	{
		fout.write(obj, sizeof(obj));
	}
}

template<typename T>
T** FileService<T>::Read(std::string path) {}