
#include "Patient.h"
#include <queue>

#ifndef HOSPITAL_ADMINISTRATION_ASSIGNMENT_HOSPITAL_PATIENT_QUEUE_H
#define HOSPITAL_ADMINISTRATION_ASSIGNMENT_HOSPITAL_PATIENT_QUEUE_H

class hospital_patient_queue {

private:

    std::vector<Patient> treated_patients;
    std::priority_queue<Patient> untreated_patients;

public:

    [[nodiscard]] const Patient& get_next() const;
    [[nodiscard]] std::string get_report(Patient& patient) const;
    [[nodiscard]] std::string get_report_all_treated() const;

    void add(Patient& patient);
    void add_from_file(std::string source_file_name);
    void treat_all();
    void treat_next();

};

#endif //HOSPITAL_ADMINISTRATION_ASSIGNMENT_HOSPITAL_PATIENT_QUEUE_H
