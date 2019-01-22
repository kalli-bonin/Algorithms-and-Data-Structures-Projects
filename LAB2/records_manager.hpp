//Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#ifndef records_manager_h
#define records_manager_h

#include "patient_record.hpp"
#include <string>

using namespace std;

class RecordsManager {
	
	friend class RecordsManagerTest;
	
	public:		
		RecordsManager();
		RecordsManager(int nCap);
		~RecordsManager();
		
		int getSize();
		int getCapacity();
		void print();
		void printAsJSON();
		bool insertRecord(unsigned int newCatID, unsigned int newPatID, string newName, string newAddress, string newDOB);
		bool removeRecord(unsigned int newCatID, unsigned int newPatID);
		void clearRecords();
		
	private:
		PatientRecord** data = NULL;
		int size, capacity;
		
};

#endif
