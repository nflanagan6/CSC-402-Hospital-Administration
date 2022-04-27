
#include "patient.h"
#include <queue>
#include <fstream>

#ifndef HOSPITAL_ADMINISTRATION_ASSIGNMENT_HOSPITAL_PATIENT_QUEUE_H
#define HOSPITAL_ADMINISTRATION_ASSIGNMENT_HOSPITAL_PATIENT_QUEUE_H

class hospital_patient_queue {

private:

    std::vector<patient> treated_patients;
    std::priority_queue<patient, std::vector<patient>, std::less<>> untreated_patients;

public:

    hospital_patient_queue();

    [[nodiscard]] const patient& get_next() const;
    [[nodiscard]] std::string get_report_all_treated() const;

    void add(patient& patient);
    void add_from_file(std::string source_file_name);
    void treat_all();
    void treat_next();

};

#endif //HOSPITAL_ADMINISTRATION_ASSIGNMENT_HOSPITAL_PATIENT_QUEUE_H
