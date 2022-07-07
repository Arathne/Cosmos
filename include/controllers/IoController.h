#ifndef IO_CONTROLLER_H
#define IO_CONTROLLER_H

#include <psp2/io/fcntl.h> 
#include <psp2/io/stat.h> 
#include <psp2/io/dirent.h> 

#include <fstream>

class IoController {
    public:
        static bool writeFile (const std::string filePath, const std::string content);
        static bool appendFile (const std::string filePath, const std::string content);

        static bool deleteFile (const std::string filePath);
        static bool createDirectory (const std::string filePath);
        static void deleteDirectory (const std::string filePath);

        static bool isDirectory (const std::string filePath);
        static bool isDirectory (const SceMode & mode);

    private:
        static void deleteDirectoryRecursively (std::string directoryPath);
};

#endif