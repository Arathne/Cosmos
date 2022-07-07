#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <controllers/IoController.h>

class Logger {
    public:
        Logger ();
        Logger (size_t max_size);
        ~Logger ();
        
        void add (std::string message);
        void writeToFile (std::string path);

    private:
        std::vector<std::string> log_;
        size_t size_;

        std::string toString (void) const;
};

#endif