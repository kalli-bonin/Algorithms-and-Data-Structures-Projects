//Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "records_manager.hpp"
#include "records_manager_test.hpp"

using namespace std;

int main() {
	srand(time(NULL));
	
	RecordsManagerTest testDriver;
	
	RecordsManager recordsMan1;
	RecordsManager recordsMan2(4);
	RecordsManager recordsMan3(14);

	cout << "Test 1 - Default Capacity: \n================================\n\n";

	testDriver.test1(recordsMan1, 10);
	testDriver.test2(recordsMan1, 10);
	testDriver.test3(recordsMan1, 5);
	testDriver.test2(recordsMan1, 10);
	testDriver.test3(recordsMan1, 10);
	testDriver.test2(recordsMan1, 200);
	testDriver.test3(recordsMan1, 200);
	
	cout << "Test 2 - Less than Minimum Capacity: \n================================\n\n";
	
	testDriver.test1(recordsMan2, 10);
	testDriver.test2(recordsMan2, 10);
	testDriver.test3(recordsMan2, 5);
	testDriver.test2(recordsMan2, 10);
	testDriver.test3(recordsMan2, 10);
	testDriver.test2(recordsMan2, 200);
	testDriver.test3(recordsMan2, 200);
	
	cout << "Test 2 - More than Minimum Capacity: \n================================\n\n";
	
	testDriver.test1(recordsMan3, 10);
	testDriver.test2(recordsMan3, 10);
	testDriver.test3(recordsMan3, 5);
	testDriver.test2(recordsMan3, 10);
	testDriver.test3(recordsMan3, 10);
	testDriver.test2(recordsMan3, 200);
	testDriver.test3(recordsMan3, 200);
	
	cout << "Test Print as JSON: \n================================\n\n";
	
	recordsMan1.printAsJSON();
	
	return 0;
}

RecordsManagerTest::RecordsManagerTest() {}
RecordsManagerTest::~RecordsManagerTest() {}

// Test inserting given number of records with random category and patient IDs 
bool RecordsManagerTest::test1(RecordsManager &recordsMan, int testSize) {
	bool testPassed = true;

	for (int i = 0; i < testSize; i++) {
		int newCatID = rand() % 9001, newPatID = rand() % 9001;
		
		cout << "Inserted record " << i + 1 
		     << " --> \t (CatID = " << newCatID << ", PatID = " << newPatID << "): \t";
		
		if (!(recordsMan.insertRecord(newCatID, newPatID, "Bob Smith Joe Bob", "725 Harbourfront Road", "18/09/52"))) {
			cout << "Failed";
			testPassed = false;
		} else {
			cout << "Succeeded";
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "Record Size: " << recordsMan.getSize() << " Capacity: " << recordsMan.getCapacity() << endl << endl;
	recordsMan.print();
	
	return testPassed;
}

// Test inserting given number of records with sequential category and patient IDs
bool RecordsManagerTest::test2(RecordsManager &recordsMan, int testSize) {
	bool testPassed = true;

	for (int i = 0; i < testSize; i++) {
		int newCatID = i, newPatID = i;
		
		cout << "Inserting record " << i + 1 
		     << " --> \t (CatID = " << newCatID << ", PatID = " << newPatID << "): \t";
		
		if (!(recordsMan.insertRecord(newCatID, newPatID, "Bob Smith Joe Bob", "725 Harbourfront Road", "18/09/52"))) {
			cout << "Failed";
			testPassed = false;
		} else {
			cout << "Succeeded";
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "Record Size: " << recordsMan.getSize() << " Capacity: " << recordsMan.getCapacity() << endl << endl;
	recordsMan.print();
	
	return testPassed;
}

// Test deleting given number of sequential category and patient IDs
bool RecordsManagerTest::test3(RecordsManager &recordsMan, int testSize) {
	bool testPassed = true;

	for (int i = 0; i < testSize; i++) {
		int newCatID = i, newPatID = i;
		
		cout << "Deleting record " << i + 1 
		     << " --> \t (CatID = " << newCatID << ", PatID = " << newPatID << "): \t";
		
		if (!(recordsMan.removeRecord(newCatID, newPatID))) {
			cout << "Failed";
			testPassed = false;
		} else {
			cout << "Succeeded";
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "Record Size: " << recordsMan.getSize() << " Capacity: " << recordsMan.getCapacity() << endl << endl;
	recordsMan.print();
	
	return testPassed;
}
