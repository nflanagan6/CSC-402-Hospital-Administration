
#include "Patient.h"

Patient::Patient(std::string first_name, std::string last_name, std::string middle_name, std::string name_suffix,
                 std::vector<std::string>& ailments, std::string doctor, int priority, bool treated)
                 : first_name(first_name), last_name(last_name), middle_name(middle_name), name_suffix(name_suffix),
                 doctor(doctor), priority(priority), treated(treated) {

                    this->ailments = std::vector<std::string>();
                    for (std::string ailment : ailments)
                        this->ailments.push_back(ailment);
                 }

Patient::Patient(std::string last_name, std::vector<std::string>& ailments, std::string doctor, int priority,
                 bool treated) : last_name(last_name), doctor(doctor), priority(priority) {

                this->ailments = std::vector<std::string>();
                for (std::string ailment : ailments)
                    this->ailments.push_back(ailment);
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
    for (std::string ailment : ailments)
        this->ailments.push_back(ailment);
}
void Patient::set_doctor(std::string doctor) {

    this->doctor = doctor;
}
void Patient::set_first_name(std::string first_name) {

    this->first_name = first_name;
}
void Patient::set_last_name(std::string last_name) {

    this->last_name = last_name;
}
void Patient::set_middle_name(std::string middle_name) {

    this->middle_name = middle_name;
}
void Patient::set_name_suffix(std::string name_suffix) {

    this->name_suffix = name_suffix;
}
void Patient::set_priority(int priority) {

    this->priority = priority;
}
void Patient::set_treated(bool isTreated) {

    this->treated = isTreated;
}