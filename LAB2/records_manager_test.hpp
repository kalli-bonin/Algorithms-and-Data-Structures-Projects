//Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#ifndef records_manager_test_h
#define records_manager_test_h

#include "records_manager.hpp"

using namespace std;

class RecordsManagerTest {
	public:
		RecordsManagerTest();
		~RecordsManagerTest();
		
		bool test1(RecordsManager &recordsMan, int testSize);
		bool test2(RecordsManager &recordsMan, int testSize);
		bool test3(RecordsManager &recordsMan, int testSize);
		bool test4(RecordsManager &recordsMan);
		bool test5(RecordsManager &recordsMan);
		bool test6(RecordsManager &recordsMan);
		bool test7(RecordsManager &recordsMan);
		bool test8(RecordsManager &recordsMan);
		bool test9(RecordsManager &recordsMan);
		bool test10(RecordsManager &recordsMan);
};

#endif
