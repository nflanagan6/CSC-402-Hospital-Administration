
#include <iostream>
#include "Patient.h"
#include "hospital_patient_queue.h"

int main() {

    std::vector<std::string> testing_ailments = std::vector<std::string>();
    testing_ailments.push_back("Allergies");

    Patient testing_patient = Patient("Nathan", "Flanagan", "Benjamin",
                                      "", testing_ailments, "L", 4, false);

    testing_ailments.clear();
    testing_ailments.push_back("Nausea");
    testing_ailments.push_back("Fatigue");
    testing_ailments.push_back("Confusion");

    testing_patient.set_first_name("Nate");
    testing_patient.set_middle_name("B.");
    testing_patient.set_last_name("Flanagan");
    testing_patient.set_doctor("Gaga");
    testing_patient.set_ailments(testing_ailments);
    testing_patient.set_priority(2);
    testing_patient.set_treated(true);
    testing_patient.set_treated(false);

    std::vector<std::string> testing_ailments_2 = std::vector<std::string>();
    testing_ailments_2.push_back("The Plague");
    testing_ailments_2.push_back("Hearing voices");


    Patient testing_patient_2 = Patient("James", "Holden", "", "",
                                        testing_ailments_2, "AAA", 4, false);
    Patient testing_patient_3 = Patient("Bob", "Roberts", "Roberto", "III",
                                        testing_ailments, "AAAAAA", 7, false);

    hospital_patient_queue queue = hospital_patient_queue();
    queue.add(testing_patient);
    queue.add(testing_patient_2);
    queue.add(testing_patient_3);

    testing_patient.set_priority(100);
    testing_patient_2.set_priority(1);
    testing_patient_3.set_priority(35);

    for (int i = 1; i <= 3; i++) {
        std::cout << "Next patient to be treated: " << queue.get_next().get_full_name() << std::endl;
        queue.treat_next();
    }


    queue.add_from_file("patients.txt");
    queue.treat_all();

}

// TODO - Pull the path to files out and put it in a #define you can set (in Logger.h?)

