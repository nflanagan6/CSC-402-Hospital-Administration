
#include <iostream>
#include "Patient.h"


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


}

// TODO - figure out where the & goes and put it there everywhere
// TODO - figure out how to include , literals in a .csv
// TODO - Pull the path to files out and put it in a #define you can set (in Logger.h?)

