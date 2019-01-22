//Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#ifndef patient_record_h
#define patient_record_h

#include <string>

using namespace std;

class PatientRecord {
	
	public:
		PatientRecord();
		PatientRecord(unsigned int newCatID, unsigned int newPatID, string newName, string newAddress, string newDOB);
		
		unsigned int getCatID();
		unsigned int getPatID();
		string getName();
		string getAddress();
		string getDOB();
		
		void setCatID(unsigned int catID);
		void setPatID(unsigned int patID);
		void setName(string name);
		void setAddress(string address);
		void setDOB(string DOB);
		
		void print();
		void printAsJSON();
		
		void operator = (const PatientRecord &patientRecord);
		
	private:
		unsigned int catID, patID;
		string name, address, DOB;
};

#endif
