
#include "Patient.h"

Patient::Patient(std::string first_name, std::string last_name, std::string middle_name, std::string name_suffix,
                 std::vector<std::string>& ailments, std::string doctor, int priority, bool treated)
                 : first_name(first_name), last_name(last_name), middle_name(middle_name), name_suffix(name_suffix),
                 doctor(doctor), priority(priority), treated(treated) {

                    this->ailments = std::vector<std::string>();
                    for (std::string ailment : ailments)
                        this->ailments.push_back(ailment);

                    Logger::get_Logger().log("Added new patient " + first_name + " " + middle_name + " "
                    + last_name + " " + name_suffix + " to the system with priority " + std::to_string(priority));
                 }
Patient::Patient(std::string last_name, std::vector<std::string>& ailments, std::string doctor, int priority,
                 bool treated) : last_name(last_name), doctor(doctor), priority(priority) {

                this->ailments = std::vector<std::string>();
                for (std::string ailment : ailments)
                    this->ailments.push_back(ailment);

                Logger::get_Logger().log("Added new patient Mr./Ms./Mrs. " + last_name
                + " to the system with priority " + std::to_string(priority));
}

std::vector<std::string>& Patient::get_ailments() { return ailments; }
std::string Patient::get_doctor() { return doctor; }
std::string Patient::get_first_name() { return first_name; }
std::string Patient::get_last_name() { return last_name; }
std::string Patient::get_middle_name() { return middle_name; }
std::string Patient::get_name_suffix() { return name_suffix; }
int Patient::get_priority() { return priority; }
bool Patient::isTreated() { return treated; }

void Patient::set_ailments(std::vector<std::string> &ailments) {

    this->ailments = std::vector<std::string>();
    std::string ailment_log_string = "";

    for (int i = 0; i < ailments.size(); i++) {

        this->ailments.push_back(ailments.at(i));
        if (i < ailments.size() - 2)
            ailment_log_string.append(ailments.at(i) + ", ");
        else if (i == ailments.size() - 2)
            ailment_log_string.append(ailments.at(i) + ", and");
        else
            ailment_log_string.append(ailments.at(i));
    }

    Logger::get_Logger().log("Updated patient " + first_name + " " + middle_name + " " + last_name
                             + " " + name_suffix + "'s ailments to " + ailment_log_string);
}
void Patient::set_doctor(std::string doctor) {

    Logger::get_Logger().log("Updated patient " + first_name + " " + middle_name + " " + last_name
                             + " " + name_suffix + "'s attending doctor from " + this->doctor + " to "
                             + doctor);
    this->doctor = doctor;
}
void Patient::set_first_name(std::string first_name) {

    Logger::get_Logger().log("Updated patient " + first_name + " " + middle_name + " " + last_name
                             + " " + name_suffix + "'s first name from " + this->first_name + " to "
                             + first_name);
    this->first_name = first_name;
}
void Patient::set_last_name(std::string last_name) {

    Logger::get_Logger().log("Updated patient " + first_name + " " + middle_name + " " + last_name
                             + " " + name_suffix + "'s last name from " + this->last_name + " to "
                             + last_name);
    this->last_name = last_name;
}
void Patient::set_middle_name(std::string middle_name) {

    Logger::get_Logger().log("Updated patient " + first_name + " " + middle_name + " " + last_name
                             + " " + name_suffix + "'s middle name from " + this->middle_name + " to "
                             + middle_name);
    this->middle_name = middle_name;
}
void Patient::set_name_suffix(std::string name_suffix) {

    Logger::get_Logger().log("Updated patient " + first_name + " " + middle_name + " " + last_name
                             + " " + name_suffix + "'s name suffix from " + this->name_suffix + " to " + name_suffix);
    this->name_suffix = name_suffix;
}
void Patient::set_priority(int priority) {

    Logger::get_Logger().log("Updated patient " + first_name + " " + middle_name + " " + last_name
                             + " " + name_suffix + "'s priority rating from " + std::to_string(this->priority)
                             + " to " + std::to_string(priority));
    this->priority = priority;
}
void Patient::set_treated(bool isTreated) {

    if (this->treated == false && isTreated == true)
        Logger::get_Logger().log("Marked patient " + first_name + " " + middle_name + " " + last_name
        + " " + name_suffix + " as treated");

    if (this->treated == true && isTreated == false)
        Logger::get_Logger().log("Updated patient " + first_name + " " + middle_name + " " + last_name
                                 + " " + name_suffix + "'s status from treated to untreated");

    this->treated = isTreated;
}