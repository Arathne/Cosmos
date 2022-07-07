#include <Logger.h>

Logger::Logger ():
    size_((size_t)-1)
{}

Logger::Logger (size_t max_size):
    size_(max_size)
{}

Logger::~Logger () {}

void Logger::add (std::string message)
{
    log_.push_back(message);

    if (log_.size() > size_)
        log_.erase (log_.begin());
}

void Logger::writeToFile (std::string path)
{
    IoController::writeFile(path, Logger::toString());
}

std::string Logger::toString (void) const
{
    std::string output = "";
    
    for (int i = 0; i < log_.size(); i++) 
    {
        output += log_.at(i) + "\n";
    }

    return output;
}
