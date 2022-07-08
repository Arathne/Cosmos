#ifndef LOGGER_H
#define LOGGER_H

#include <controllers/IoWriteController.h>
#include <vector>

class Logger {
    public:
        Logger (void);
        Logger (size_t max_size);
        
        void add (const std::string & message);
        void writeToFile (const std::string & path);

    private:
        std::vector<std::string> log_;
        size_t size_;

        std::string toString (void) const;
};

#endif