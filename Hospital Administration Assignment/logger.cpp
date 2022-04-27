
#include "logger.h"

logger& logger::get_logger() {

    static logger logger;
    return logger;
}

logger::logger() = default;

bool logger::in_debug_mode() const {

    return debug_mode;
}

void logger::log(std::string message_to_log) {

    auto now = std::chrono::system_clock::now();
    std::time_t log_time_t = std::chrono::system_clock::to_time_t(now);
    std::string string_log_time = std::ctime(&log_time_t);
    string_log_time.pop_back();

    if (debug_mode) {

        std::cout << string_log_time << " " << message_to_log << std::endl;
    }

    else {      // TODO - Should file be closed and reopened, or just left open while running?
                // Maybe have a time_since_last_log and open a new file if needed?

        if (log_file.is_open()) {

            log_file << string_log_time << ";" << message_to_log << "\n";
            log_file.flush();
        }

        else {

            set_log_file();
            log_file << string_log_time << ";" << message_to_log << "\n";
            log_file.flush();
        }
    }
}

void logger::set_debug_mode(bool debug_mode) {

    if (this->debug_mode == false && debug_mode == true) {

        log("Moving to debug mode - file will be closed");
        log_file.flush();
        log_file.close();
    }

    this->debug_mode = debug_mode;

    if (this->debug_mode == true && debug_mode == false) {

        set_log_file();
        log("Exited debug mode");
        log_file.flush();
    }
}

void logger::set_log_file(std::string file_name) {

    std::string full_file_name = "/Users/nateflanagan/Library/Mobile Documents/"
                                                         "com~apple~CloudDocs/Documents/NKU/NKU Spring 2022/CSC 402/"
                                                         "Hospital Administration Assignment/Hospital Administration Assignment/"
                                                         "Logs/Log ";
    full_file_name.append("/");
    full_file_name.append(file_name);
    log_file.open(full_file_name);
    log_file << "sep=;" << "\n";
    log_file << "Time" << ";" << "Operation" << "\n";
}

void logger::set_log_file() {

    auto now = std::chrono::system_clock::now();
    std::time_t log_time = std::chrono::system_clock::to_time_t(now);

    std::string file_name = "/Users/nateflanagan/Library/Mobile Documents/"
                            "com~apple~CloudDocs/Documents/NKU/NKU Spring 2022/CSC 402/"
                            "Hospital Administration Assignment/Hospital Administration Assignment/"
                            "Logs/Log ";

    std::string time = "";
    time.append(std::ctime(&log_time));
    time.pop_back();
    file_name.append(time);
    file_name.append(".csv");
    log_file.open(file_name);
    log_file << "sep=;" << "\n";
    log_file << "Time" << ";" << "Operation" << "\n";
}
