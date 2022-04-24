cmake_minimum_required(VERSION 3.22)
project(Hospital_Administration_Assignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hospital_Administration_Assignment main.cpp Patient.cpp Patient.h Logger.cpp Logger.h hospital_patient_queue.cpp hospital_patient_queue.h)
