#ifndef IO_READ_CONTROLLER_H
#define IO_READ_CONTROLLER_H

#include <psp2/io/stat.h> 
#include <string>

class IoReadController 
{
    public:
        /* @name: isDirectory
         * @description: "decides if path is a directory"
         * @params: [
                directoryPath  string  "full path to directory"
            ]
         * @return: bool
                true   "path is a directory"
                false  "path is not a directory"
        */
        static bool isDirectory (const std::string & directoryPath);

        /* @name: isDirectory
         * @description: "decides if path is a directory"
         * @params: [
                directoryPath  SceMode  "low level file information"
            ]
         * @return: bool
                true   "path is a directory"
                false  "path is not a directory"
        */
        static bool isDirectory (const SceMode & mode);
};

#endif