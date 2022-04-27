
#include <iostream>
#include "patient.h"
#include "hospital_patient_queue.h"

int main() {

    logger::get_logger().set_debug_mode(true);

    std::vector<std::string> testing_ailments = std::vector<std::string>();
    testing_ailments.push_back("Disease");
    patient patient_1 = patient ("patient", "Number", "One", "", testing_ailments, "Gaga", 4, false);

    testing_ailments.clear();
    testing_ailments.push_back("Infection");
    patient patient_2 = patient ("patient", "Number", "Two", "", testing_ailments, "Gaga", 17, false);

    testing_ailments.clear();
    testing_ailments.push_back("Illness");
    patient patient_3 = patient ("patient", "Number", "Three", "", testing_ailments, "Gaga", 2, false);

    hospital_patient_queue queue {};
    queue.add(patient_1);
    queue.add(patient_2);
    queue.add(patient_3);
    queue.treat_all();

}

// TODO - Pull the path to files out and put it in a #define you can set (in logger.h?)

