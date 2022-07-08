#include <controllers/IoWriteController.h>

bool IoWriteController::writeTextToFile (const std::string & filePath, const std::string & content)
{
    bool success = false;
    std::ofstream output(filePath);

    if (output) {
        output << content;
        output.close();
        success = true;
    }

    return success;
}

bool IoWriteController::appendTextToFile (const std::string & filePath, const std::string & content)
{
    bool success = false;
    std::ofstream output(filePath, std::ios_base::app);

    if (output) {
        output << content;
        output.close();
        success = true;
    }

    return success;
}