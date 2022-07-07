#ifndef IOCONTROLLER_H
#define IOCONTROLLER_H

#include <psp2/io/fcntl.h> 
#include <psp2/io/stat.h> 

#include <fstream>

class IoController {
    public:
        static bool writeFile (const std::string filePath, const std::string content);
        static bool appendFile (const std::string filePath, const std::string content);
        static bool deleteFile (const std::string filePath);

        static bool createDirectory (const std::string filePath);
        static bool deleteDirectory (const std::string filePath);
        static bool isDirectory (const std::string filePath);
};

#endif