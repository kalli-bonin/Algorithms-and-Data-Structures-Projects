//
// Alex Petkovic (20728032) and Kalli Bonin (20706260)
//

#ifndef DRONEMANAGER_DRONES_MANAGER_TEST_H
#define DRONEMANAGER_DRONES_MANAGER_TEST_H

#include "drones_manager.h"
#include <iostream>

#define ASSERT_TRUE(T) if (!(T)) return false;

class DronesManagerTest {
public:
    // new empty list is valid
    bool test1() {
        DronesManager manager;
        ASSERT_TRUE(manager.get_size() == 0)
        ASSERT_TRUE(manager.empty() == true)
        ASSERT_TRUE(manager.first == NULL)
        ASSERT_TRUE(manager.last == NULL)
        return true;
    }

    // insert_front() and insert_back() on zero-element list
    bool test2() {
        DronesManager manager1, manager2;
        manager1.insert_front(DronesManager::DroneRecord(100));
        manager2.insert_back(DronesManager::DroneRecord(100));

        ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
        ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
        ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
        ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
        ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
        ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))
        return true;
    }

    // select() and search() work properly
    bool test3() {
        DronesManager manager;
        int randVals[5];

        //insert 5 random elements, save them in array to be able to check vals
        for (int i = 0; i < 5; i++) {
            randVals[i] = rand() % 9001;
            manager.insert_back(DronesManager::DroneRecord(randVals[i]));
        }
        //check all values were inserted
        ASSERT_TRUE(manager.size == 5)
        cout << "added" << endl;

        //check that the index at 0 returns the value at 0
        ASSERT_TRUE(manager.select(0).droneID == randVals[0])
        cout << "selected" << endl;

        //checks that an invalid index returns the last record
        ASSERT_TRUE(manager.select(5).droneID == randVals[4])
        cout << "indexed" << endl;

        //checks that the value exists at index 1
        ASSERT_TRUE(manager.search(randVals[1]) == 1)
        cout << "searched" << endl;

        return true;
    }

    // remove_front() and remove_back() on one-element list
    bool test4() {
        //create two one-element list
        DronesManager manager1, manager2;
        manager1.insert_front(DronesManager::DroneRecord(100));
        manager2.insert_back(DronesManager::DroneRecord(100));

        ASSERT_TRUE(manager1.remove_front())
        cout << "removed front" << endl;

        ASSERT_TRUE(manager2.remove_back())
        cout << "removed back" << endl;


        return true;
    }

    // replace() and reverse_list() work properly
    bool test5() {
        DronesManager manager;
        manager.insert_front(DronesManager::DroneRecord(100));

        ASSERT_TRUE(manager.replace(0, 500))
        ASSERT_TRUE(manager.reverse_list())

        return true;
    }

    // insert_front() keeps moving elements forward
    bool test6() {
        DronesManager manager;

        //insert 5 elements at front
        for (int i = 0; i < 5; i++)
            manager.insert_front(DronesManager::DroneRecord(rand() % 9001));

        //checks to make sure that all values were inserted
        ASSERT_TRUE(manager.size == 5);
        return true;
    }

    // inserting at different positions in the list
    bool test7() {
        DronesManager manager;

        //insert 5 elements at front
        for (int i = 0; i < 5; i++)
            manager.insert_front(DronesManager::DroneRecord(rand() % 9001));

        //insert 5 more elements randomly within the bounds
        for (int i = 0; i < 5; i++)
            manager.insert(DronesManager::DroneRecord(rand() % 9001), rand() % 5+i);
        //checks to make sure that all values were inserted
        ASSERT_TRUE(manager.size == 10);
        return true;
    }

    // try to remove too many elements, then add a few elements
    bool test8() {
        DronesManager manager;

        //insert 5 elements at front
        for (int i = 0; i < 5; i++)
            manager.insert_front(DronesManager::DroneRecord(rand() % 9001));
        ASSERT_TRUE(manager.size == 5);

        //this will try to remove one extra element
        for (int j = 0; j <= 5; j++)
            manager.remove(j);
        ASSERT_TRUE(manager.size == 0);


        //then add back 5 elements
        for (int i = 0; i < 5; i++)
            manager.insert_front(DronesManager::DroneRecord(rand() % 9001));
        ASSERT_TRUE(manager.size == 5);
        return true;
    }

    // lots of inserts and deletes, some of them invalid
    bool test9() {
        DronesManagerSorted manager;
        //insert 5 elements at front
        for (int i = 0; i < 5; i++)
            manager.insert_front(DronesManager::DroneRecord(rand() % 9001));
        ASSERT_TRUE(manager.size == 5);

        //remove 3 elements at index j
        for (int j = 0; j < 3; j++)
            manager.remove(j);
        ASSERT_TRUE(manager.size == 2);

        //add a random number of additional elements in sorted descending order
        for (int k = 0; k < 5; k++)
            manager.insert_front(DronesManager::DroneRecord(rand() % 9001));
        ASSERT_TRUE(manager.size == 7);

        return true;
    }

    // inserts into an unsorted list, then sort the list
    bool test10() {
        DronesManagerSorted manager;
        //insert 5 elements at front
        for (int i = 0; i < 5; i++)
            manager.insert_front(DronesManager::DroneRecord(rand() % 9001));
        ASSERT_TRUE(manager.size == 5);

        manager.sort_asc();
        ASSERT_TRUE(manager.is_sorted_asc())
        return true;
    }

    // insert and remove into sorted manager in ascending order
    bool test11() {
        DronesManagerSorted manager;

        for (int i = 0; i < 5; i++)
            manager.insert_sorted_asc(DronesManager::DroneRecord(rand() % 9001));
        //check elements were added and sorted
        ASSERT_TRUE(manager.size == 5);
        ASSERT_TRUE(manager.is_sorted_asc());

        //remove a random number of elements at a random index
        for (int j = 0; j < 3; j++)
            manager.remove(j);
        ASSERT_TRUE(manager.size == 2);

        //add a random number of additional elements in sorted descending order
        for (int k = 0; k < 5; k++)
            manager.insert_sorted_asc(DronesManager::DroneRecord(rand() % 9001));
        //check elements were added and still sorted
        ASSERT_TRUE(manager.size == 7);
        ASSERT_TRUE(manager.is_sorted_asc());

        return true;
    }

    //insert and remove into sorted manager in descending order
    bool test12() {
        DronesManagerSorted manager;
        for (int i = 0; i < 5; i++)
            manager.insert_sorted_desc(DronesManager::DroneRecord(rand() % 9001));
        //check elements were added and sorted
        ASSERT_TRUE(manager.size == 5);
        ASSERT_TRUE(manager.is_sorted_desc());

        //remove a random number of elements at a random index
        for (int j = 0; j < 3; j++)
            manager.remove(j);
        ASSERT_TRUE(manager.size == 2);

        //add a random number of additional elements in sorted descending order
        for (int k = 0; k < 5; k++)
            manager.insert_sorted_desc(DronesManager::DroneRecord(rand() % 9001));
        //check elements were added and still sorted
        ASSERT_TRUE(manager.size == 7);
        ASSERT_TRUE(manager.is_sorted_desc());
    }
};

#endif

