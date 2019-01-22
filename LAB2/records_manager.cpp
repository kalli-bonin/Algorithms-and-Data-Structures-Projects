//Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#include <iostream>

#include "records_manager.hpp"
#include "patient_record.hpp"

using namespace std;

const int MIN_CAP = 128;

RecordsManager::RecordsManager() {
	data = new PatientRecord*[MIN_CAP];
	size = 0;
	capacity = MIN_CAP;

	clearRecords();
}

RecordsManager::RecordsManager(int nCap) {
	if (nCap < MIN_CAP) {
		capacity = MIN_CAP;
	} else {
		capacity = nCap;
	}

	data = new PatientRecord*[capacity];
	size = 0;

	clearRecords();
}

int RecordsManager::getSize() {
	return size;
}

int RecordsManager::getCapacity() {
	return capacity;
}

void RecordsManager::print() {
	for (int i = 0; i < size; i++) {
		data[i] -> print();
	}
}

void RecordsManager::printAsJSON() {
	cout << "[" << endl;
	for (int i = 0; i < size - 1; i++) {
		data[i] -> printAsJSON();
		cout << "," << endl;
	}
		data[size - 1] -> printAsJSON();
	cout << endl << "]" << endl;
}

bool RecordsManager::insertRecord(unsigned int newCatID, unsigned int newPatID, string newName, string newAddress, string newDOB) {
	if (data == NULL) return false;

	int i=0;
	for (i = 0; data[i] -> getCatID() < newCatID && i < size; i++) ;
	
	for (; data[i] -> getCatID() == newCatID && data[i] -> getPatID() < newPatID && i < size; i++) ;
	
	// If there already exists a record with the same category ID and patient ID, reject insertion.
	if (i < size && data[i] -> getCatID() == newCatID && data[i] -> getPatID() == newPatID) return false; 
	
	size++;
	
	// Doubled capacity of records if out of space
	if (size > capacity) {
		capacity *= 2;
		//cout << "New Capacity: " << capacity;
		PatientRecord** newData = new PatientRecord*[capacity];
		
		for(int m = 0; m < capacity; m++) {
			newData[m] = new PatientRecord();
		}
		
		for (int j = 0; j < size; j++) {
			newData[j] = data[j];
		}
		delete [] data;
		
		data = new PatientRecord*[capacity];
		for (int j = 0; j < size; j++) {
			data[j] = newData[j];
		}
		delete [] newData;
		
	}
	
	// Shift elements to make roon for insertion.	
	for (int k = size; k >= i + 1; k--) {
		data[k] = data[k - 1];
	}
	
	// Insert element
	data[i] = new PatientRecord(newCatID, newPatID, newName, newAddress, newDOB);

	return true;
}

bool RecordsManager::removeRecord(unsigned int newCatID, unsigned int newPatID) {
	if (data == NULL) return false;
	
	int i = 0;
	while (data[i] -> getCatID() != newCatID && data[i] -> getPatID() != newPatID) {
		i++;
	}
	
	// If there is no record found, reject removal
	if (i + 1 >= size) return 0;
	
	for (; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	
	size--;
	
	if ((capacity + 1) / 2 >= MIN_CAP && size < (capacity + 1) / 4) {
		++capacity /= 2;

		PatientRecord** newData = new PatientRecord*[capacity];
		
		for(int m = 0; m < capacity; m++) {
			newData[m] = new PatientRecord();
		}
		
		for (int j = 0; j < size; j++) {
			newData[j] = data[j];
		}
		delete [] data;
		
		data = new PatientRecord*[capacity];
		for (int j = 0; j < size; j++) {
			data[j] = newData[j];
		}
		delete [] newData;
		newData = NULL;
		
	}
	
	return true;
}

void RecordsManager::clearRecords(){
	for(int i = 0; i < capacity; i++) {
		data[i] = new PatientRecord();
	}
}

RecordsManager::~RecordsManager() {
	delete [] data;
	data = NULL;
}
