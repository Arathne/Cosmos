#ifndef IO_WRITE_CONTROLLER_H
#define IO_WRITE_CONTROLLER_H

#include <fstream>

class IoWriteController 
{
    public:
        /* @name: writeTextToFile
         * @description: "write text to a file"
         * @params: [
                filePath  string  "full path to directory"
                content   string  "text to be written into a file"
            ]
         * @return: bool
                true   "writing to file successful"
                false  "writing to file failed"
        */
        static bool writeTextToFile (const std::string & filePath, const std::string & content);

        /* @name: appendTextToFile
         * @description: "append text to a file"
         * @params: [
                filePath  string  "full path to directory"
                content   string  "text to be append to a file"
            ]
         * @return: bool
                true   "appending to file successful"
                false  "appending to file failed"
        */
        static bool appendTextToFile (const std::string & filePath, const std::string & content);
};

#endif