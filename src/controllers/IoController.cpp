#include <controllers/IoController.h>

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

bool IoController::isDirectory (const std::string filePath)
{
    bool directory = false;
    
    SceIoStat stats;
    int success = sceIoGetstat(filePath.c_str(), &stats);

    return IoController::isDirectory(stats.st_mode);

    /*if (success == 0) {
        SceMode mode = stats.st_mode;

        if ((mode & SCE_S_IFDIR) == SCE_S_IFDIR) { // check to see if directory flag set
            directory = true;
        }
    }

    return directory;*/
}

bool IoController::isDirectory (const SceMode & mode) 
{
    bool directory = false;

    if ((mode & SCE_S_IFDIR) == SCE_S_IFDIR) // check to see if directory flag set
        directory = true;

    return directory;
}

void IoController::deleteDirectory (const std::string directoryPath)
{
    if (IoController::isDirectory(directoryPath))
    {
        IoController::deleteDirectoryRecursively(directoryPath);
    }
}

void IoController::deleteDirectoryRecursively (std::string directoryPath) 
{
    SceUID directoryId = sceIoDopen(directoryPath.c_str());

    SceIoDirent currentFile;
    while (sceIoDread(directoryId, &currentFile) > 0)
	{
        std::string fullPath = directoryPath + "/" + std::string(currentFile.d_name);

        if (IoController::isDirectory(currentFile.d_stat.st_mode)) 
        {
            deleteDirectoryRecursively(fullPath);
        }
        else
            IoController::deleteFile(fullPath);
    }

    sceIoDclose(directoryId);
    sceIoRmdir(directoryPath.c_str());
}