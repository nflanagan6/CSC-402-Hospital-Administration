
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

#ifndef HOSPITAL_ADMINISTRATION_ASSIGNMENT_LOGGER_H
#define HOSPITAL_ADMINISTRATION_ASSIGNMENT_LOGGER_H

class Logger {

private:

    Logger();
    Logger(const Logger & rhs);
    const Logger& operator=(const Logger & rhs);

    bool debug_mode = false;
    std::ofstream log_file;

public:

    [[nodiscard]] static Logger& get_Logger();
    [[nodiscard]] bool in_debug_mode() const;
    void log(std::string message_to_log);
    void set_debug_mode(bool debug_mode);
    void set_log_file(std::string file_name);
    void set_log_file();

};

#endif //HOSPITAL_ADMINISTRATION_ASSIGNMENT_LOGGER_H
