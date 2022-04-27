
#include <string>
#include <vector>
#include "logger.h"

#ifndef HOSPITAL_ADMINISTRATION_ASSIGNMENT_PATIENT_H
#define HOSPITAL_ADMINISTRATION_ASSIGNMENT_PATIENT_H

class patient {

private:
    std::string first_name;
    std::string last_name;
    std::string middle_name;
    std::string name_suffix;

    std::vector<std::string> ailments;
    std::string doctor;
    int priority;
    bool treated;

public:
    patient (std::string first_name, std::string middle_name, std::string last_name, std::string name_suffix,
             std::vector<std::string>& ailments, std::string doctor, int priority, bool treated);
    patient (std::string last_name, std::vector<std::string>& ailments, std::string doctor, int priority, bool treated);
    patient();

    [[nodiscard]] const std::vector<std::string>& get_ailments() const;     // TODO - is just a vector of std::string find since
    [[nodiscard]] std::string get_doctor() const;                     // it's not huge, or should it be std::string*?
    [[nodiscard]] std::string get_first_name() const;
    [[nodiscard]] std::string get_full_name() const;
    [[nodiscard]] std::string get_last_name() const;
    [[nodiscard]] std::string get_middle_name() const;
    [[nodiscard]] std::string get_name_suffix() const;
    [[nodiscard]] int get_priority() const;
    [[nodiscard]] std::string get_report() const;
    [[nodiscard]] bool isTreated() const;

    void set_ailments(std::vector<std::string>& ailments);
    void set_doctor(std::string doctor);
    void set_first_name(std::string first_name);
    void set_last_name(std::string last_name);
    void set_middle_name(std::string middle_name);
    void set_name_suffix(std::string name_suffix);
    void set_priority(int priority);
    void set_treated(bool isTreated);

    bool operator<(const patient &rhs) const;
    bool operator>(const patient &rhs) const;
    bool operator<=(const patient &rhs) const;
    bool operator>=(const patient &rhs) const;
};

#endif //HOSPITAL_ADMINISTRATION_ASSIGNMENT_PATIENT_H
