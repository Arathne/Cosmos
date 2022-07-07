#include <IoController.h>

bool IoController::writeFile (const std::string filePath, const std::string content) 
{
    std::ofstream output(filePath);

    if (!output)
        return false;

    output << content;
    output.close();

    return true;
}

bool IoController::appendFile (const std::string filePath, const std::string content)
{
    std::ofstream output(filePath, std::ios_base::app);

    if (!output)
        return false;

    output << content;
    output.close();

    return true;
}

bool IoController::deleteFile (const std::string filePath)
{
    return sceIoRemove(filePath.c_str()) == 0 ? true : false;
}

bool IoController::createDirectory (const std::string filePath)
{
    return sceIoMkdir(filePath.c_str(), 0777) == 0 ? true : false;
}

bool IoController::deleteDirectory (const std::string filePath)
{
    return sceIoRmdir(filePath.c_str()) == 0 ? true : false;
}

bool IoController::isDirectory (const std::string filePath)
{
    bool directory = false;
    
    SceIoStat stats;
    int success = sceIoGetstat(filePath.c_str(), &stats);

    if (success == 0) {
        SceMode mode = stats.st_mode;
        if ((mode & SCE_S_IFDIR) == SCE_S_IFDIR) { // check to see if directory flag set
            directory = true;
        }
    }

    return directory;
}