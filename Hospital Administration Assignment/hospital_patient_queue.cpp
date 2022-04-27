
#include "hospital_patient_queue.h"

hospital_patient_queue::hospital_patient_queue()
: treated_patients(std::vector<patient>()),
untreated_patients(std::priority_queue<patient, std::vector<patient>, std::less<>>()) {}


const patient& hospital_patient_queue::get_next() const {

    return untreated_patients.top();
}
void hospital_patient_queue::add(patient& added_patient) {

    patient new_patient (added_patient);

    if (!new_patient.isTreated()) {
        untreated_patients.push(new_patient);
        logger::get_logger().log("patient " + new_patient.get_full_name() + " added to untreated "
                                                                            "patient queue.");
    }
    else {
        treated_patients.push_back(new_patient);
        logger::get_logger().log("patient " + new_patient.get_full_name() + " added to list of treated patients.");
    }
}
void hospital_patient_queue::add_from_file(std::string source_file_name) {

    logger::get_logger().log("Adding patients from file " + source_file_name + ".");

    std::ifstream source_file (source_file_name);

    if (!source_file.bad()) {

        bool file_complete = false;
        int number_of_patients_added = 0;

        while (!file_complete) {

            bool single_patient_input_complete = false;

            std::string first_name;
            std::string middle_name;
            std::string last_name;
            std::string name_suffix;
            std::vector<std::string> ailments = std::vector<std::string>();
            std::string doctor;
            int priority;
            bool treated;

            while (!single_patient_input_complete) {

                std::string input_line;
                getline(source_file, input_line);

                int start = 0;
                int end = input_line.find(':');
                if (end != -1) {

                    std::string patient_member = input_line.substr(start, end - start);

                    if (patient_member == "firstName")
                        first_name = input_line.substr(end + 1, input_line.size() - 1);

                    else if (patient_member == "middleName")
                        middle_name = input_line.substr(end + 1, input_line.size() - 1);

                    else if (patient_member == "lastName")
                        last_name = input_line.substr(end + 1, input_line.size() - 1);

                    else if (patient_member == "suffix")
                        name_suffix = input_line.substr(end + 1, input_line.size() - 1);

                    else if (patient_member == "ailment")
                        ailments.push_back(input_line.substr(end + 1, input_line.size() - 1));

                    else if (patient_member == "doctor")
                        doctor = input_line.substr(end + 1, input_line.size() - 1);

                    else if (patient_member == "priority")
                        priority = std::stoi(input_line.substr(end + 1, input_line.size() - 1));

                    else if (patient_member == "treated")
                        treated = std::stoi(input_line.substr(end + 1, input_line.size() - 1));
                }

                else {
                    single_patient_input_complete = true;
                    patient new_patient = patient(first_name, middle_name, last_name, name_suffix, ailments,
                                                  doctor, priority, treated);
                    add(new_patient);
                    number_of_patients_added++;
                    single_patient_input_complete = true;
                }
            }

            if (!source_file.eof())
                single_patient_input_complete = false;

            else {
                file_complete = true;
                logger::get_logger().log("Finished reading file " + source_file_name + ". " +
                                         std::to_string(number_of_patients_added) + " patients were added.");
            }
        }
    }

    else
        logger::get_logger().log("File " + source_file_name + " could not be read.");

}
void hospital_patient_queue::treat_all() {

    logger::get_logger().log("Treating all patients in untreated patient queue.");
    int patients_treated = 0;

    while (!untreated_patients.empty()) {
        treat_next();
        patients_treated++;
    }
    logger::get_logger().log("Finished treating all patients in untreated patient queue. "
                             + std::to_string(patients_treated) + " patients were treated.");
}
void hospital_patient_queue::treat_next() {

    patient treated_patient = untreated_patients.top();
    untreated_patients.pop();
    logger::get_logger().log("Treating next patient " + treated_patient.get_full_name() + ".");
    treated_patient.set_treated(true);
    treated_patients.push_back(treated_patient);
    logger::get_logger().log("patient " + treated_patient.get_full_name() + " added to list of treated patients.");
}
