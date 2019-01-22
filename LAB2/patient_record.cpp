//Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#include <stdlib.h>
#include <iostream>

#include "patient_record.hpp"

using namespace std;

PatientRecord::PatientRecord() {
	catID = patID = -1;
	name = address = DOB = "";
}

PatientRecord::PatientRecord(unsigned int newCatID, unsigned int newPatID, string newName, string newAddress, string newDOB) {
	catID = newCatID;
	patID = newPatID;
	name = newName;
	address = newAddress;
	DOB = newDOB;
}

unsigned int PatientRecord::getCatID() {
	return catID;
}

unsigned int PatientRecord::getPatID() {
	return patID;
}

string PatientRecord::getName() {
	return name;
}

string PatientRecord::getAddress() {
	return address;
}

string PatientRecord::getDOB() {
	return DOB;
}

void PatientRecord::setCatID(unsigned int newCatID) {
	catID = newCatID;
}

void PatientRecord::setPatID(unsigned int newPatID) {
	patID = newPatID;
}

void PatientRecord::setName(string newName) {
	name = newName;
}

void PatientRecord::setAddress(string newAddress) {
	address = newAddress;
}

void PatientRecord::setDOB(string newDOB) {
	DOB = newDOB;
}

void PatientRecord::print(){
	cout << "Category ID:  " << catID << endl
		 << "Patient ID:   " << patID << endl
		 << "Patient Name: " << name  << endl
		 << "Address:      " << address << endl
		 << "DOB:          " << DOB << endl << endl;
}

void PatientRecord::printAsJSON(){
	cout << "\t{" << endl
	 	 << "\t\tCategory ID: " << catID << "," << endl
		 << "\t\tPatient ID: " << patID << "," << endl
		 << "\t\tPatient Name: \"" << name << "\"," << endl
		 << "\t\tAddress: \"" << address << "\"," << endl
		 << "\t\tDOB: \"" << DOB << "\"," << endl
		 << "\t}";
}

void PatientRecord::operator = (const PatientRecord &patientRecord) {
	catID = patientRecord.catID;
	patID = patientRecord.patID;
	name = patientRecord.name;
	address = patientRecord.address;
	DOB = patientRecord.DOB;
}
