
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

#ifndef HOSPITAL_ADMINISTRATION_ASSIGNMENT_LOGGER_H
#define HOSPITAL_ADMINISTRATION_ASSIGNMENT_LOGGER_H

class logger {

private:

    logger();
    logger(const logger & rhs);
    const logger& operator=(const logger & rhs);

    bool debug_mode = false;
    std::ofstream log_file;

public:

    [[nodiscard]] static logger& get_logger();
    [[nodiscard]] bool in_debug_mode() const;
    void log(std::string message_to_log);
    void set_debug_mode(bool debug_mode);
    void set_log_file(std::string file_name);
    void set_log_file();

};

#endif //HOSPITAL_ADMINISTRATION_ASSIGNMENT_LOGGER_H
