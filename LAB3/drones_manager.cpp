//
// Alex Petkovic (20728032) and Kalli Bonin (20706260)
//

#include <iostream>
#include "drones_manager.h"

DronesManager::DronesManager() {
    size = 0;
    first = last = NULL;
}

DronesManager::~DronesManager() {
    while (first) {
        DroneRecord* temp = first;
        first = first -> next;
        delete temp;
    }
}

unsigned int DronesManager::get_size() const {
    return size;
}

bool DronesManager::empty() const {
    return size == 0;
}

// Returns the value at the given index in the list
// If index is invalid, returns the last element; if the list is empty, returns DroneRecord(0)
DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
    if (empty()) return DroneRecord(0);
    if (index < 0 || index > size - 1) index = size - 1;

    DroneRecord *target = first;
    int count = 0;
    while (target -> next && count < index){
        target = target -> next;
        count++;
    }

    return *target;
}

// Searches for the given value, and returns the index of this value if found
// Returns the size of the list otherwise; if the list is empty, returns 0
unsigned int DronesManager::search(DroneRecord value) const {
    if (empty()) return 0;

    DroneRecord *target = first;
    int count = 0;
    while (target -> next && !(*target == value) && count < size - 1) {
        target = target -> next;
        count++;
    }

    if (*target == value) {
        return count;
    } else {
        return size;
    }
}

// Prints all elements in the list to the standard output
void DronesManager::print() const {
    DroneRecord* target = first;
    while (target) {  // Change to stdout ??
        cout << "Drone ID: "        << target -> droneID       << endl;
        cout << "Range: "           << target -> range         << endl;
        cout << "Year Bought: "     << target -> yearBought    << endl;
        cout << "Drone Type: "      << target -> droneType     << endl;
        cout << "Manufacturer: "    << target -> manufacturer  << endl;
        cout << "Description: "     << target -> description   << endl;
        cout << "Battery Type: "    << target -> batteryType   << endl << endl;

        target = target -> next;
    }
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
    return lhs.droneID == rhs.droneID;
}

// Inserts a value into the list at a given index; the list is not sorted
bool DronesManager::insert(DroneRecord value, unsigned int index) {
    if (empty()) {
        insert_front(value);
    } else {
        if (index < 0 || index > size - 1) index = size - 1;

        DroneRecord *target = first;
        DroneRecord* temp;
        int count = 0;
        while (target -> next && count < index){
            target = target -> next;
            count++;
        }

        temp = target;
        target = new DroneRecord(value);
        target -> next = temp;
        target -> prev = temp -> prev;
        temp   -> prev = target;
    }

    size++;

    return true;
}

// Inserts a value at the beginning of the list; the list is not sorted
bool DronesManager::insert_front(DroneRecord value) {
    DroneRecord* temp = first;
    first = new DroneRecord(value);
    first -> prev = NULL;
    first -> next = temp;

    if (temp) {
        temp -> prev = first;
    } else {
        last = first;
    }

    size++;

    return true;
}

// Inserts a value at end of the list; the list is not sorted
bool DronesManager::insert_back(DroneRecord value) {
    if (empty()) {
        insert_front(value);
    } else { // general case: non-empty list
        DroneRecord *end = first; // init end ptr
        while (end->next) // iterate until NULL
            end = end->next;
        end->next = new DroneRecord(value);
        end->next->next = NULL;
        last = end->next;

        size++;
    }

    return true;
}

// Deletes a value from the list at the given index
bool DronesManager::remove(unsigned int index) {
    if (empty()) return false;

    DroneRecord* target = first;
    int count = 0;
    while (target -> next && count < index) {
        target = target->next;
        count++;
    }

    if (target -> next)
        target -> next -> prev = target -> prev;
    else
        last = target -> prev;

    if (target -> prev)
        target -> prev -> next = target -> next;
    else
        first = target -> next;

    delete target;

    size--;

    return true;
}

// Deletes a value from the beginning of the list
bool DronesManager::remove_front() {
    if (empty()) return false;

    DroneRecord* temp = first;
    first = first -> next;

    if (first) { // Account for one-item list
        first -> prev = NULL;
    } else {
        last = NULL;
    }

    delete temp;

    size--;

    return true;
}

// Deletes a value from the end of the list
bool DronesManager::remove_back() {
    if (empty()) return false;

    DroneRecord* temp = last;
    last = last -> prev;

    if (last) { // Account for one-item list
        last -> next = NULL;
    } else {
        first = NULL;
    }

    delete temp;

    size--;

    return true;
}

// Replaces the value at the given index with the given value; the list is not sorted
bool DronesManager::replace(unsigned int index, DroneRecord value) {
    if (empty()) return false;

    DroneRecord* target = first;
    DroneRecord* temp;
    int count = 0;
    while (target -> next && count < index){
        target = target -> next;
        count++;
    }

    temp = target;
    target = new DroneRecord(value.droneID, value.range, value.yearBought, value.droneType, value.manufacturer,
                             value.description, value.batteryType);
    target -> next = temp -> next;
    target -> prev = temp -> prev;

    if (target -> next)
        target -> next -> prev = target;
    else
        last = target;

    if (target -> prev)
        target -> prev -> next = target;
    else
        first = target;

    delete temp;

    return true;
}

// Reverses the linked list
bool DronesManager::reverse_list() {
    if (empty()) return false;

    DroneRecord* target = first;
    DroneRecord* prev = NULL;
    DroneRecord* next = NULL;

    while (!target) {
        next = target -> next;  // next = target's next
        target -> next = prev;  // target's next = NULL
        prev = target;
        target = next;
    }
    first = prev;

    return true;
}

// Returns true if the list is sorted in ascending (non‐descending) order
bool DronesManagerSorted::is_sorted_asc() const {
    if (size <= 1 || !first) return true;
    DroneRecord* target = first;
    while (target && target -> droneID < target -> next -> droneID) {
        target = target -> next;
    }
    return !target; // True if reached last, false if didn't
}

// Returns true if the list is sorted in descending (non‐ascending) order
bool DronesManagerSorted::is_sorted_desc() const {
    if (size <= 1 || !first) return true;
    DroneRecord* target = first;
    while (target && target -> droneID > target -> next -> droneID) {
        target = target -> next;
    }
    return !target; // True if reached last, false if didn't
}

// Inserts a value so that the list remains sorted in ascending order
// If the list is not sorted in appropriate order, insertion is rejected
bool DronesManagerSorted::insert_sorted_asc(DroneRecord val) {
    if (!is_sorted_asc()) return false;
    DroneRecord* target = first;
    int index = 0;
    while (target && target -> droneID < val.droneID) {
        target = target -> next;
        index++;
    }
    return insert(val, index);
}

// Inserts a value so that the list remains sorted in descending order
// If the list is not sorted in appropriate order, insertion is rejected
bool DronesManagerSorted::insert_sorted_desc(DroneRecord val) {
    if (!is_sorted_desc()) return false;
    DroneRecord* target = first;
    int index = 0;
    while (target && target -> droneID > val.droneID) {
        target = target -> next;
        index++;
    }
    return insert(val, index);
}

// Sorts the list into ascending (non‐descending) order
void DronesManagerSorted::sort_asc() {
    if (is_sorted_asc()) return;
    for (int i = 0; i < size; ++i) {
        DroneRecord* target = first;

        for (int j = 0; target && target -> next && j < size - 1; j++) {
            if (target -> droneID > target -> next -> droneID) {
                DroneRecord temp = *target;

                target -> droneID = target -> next -> droneID;
                target -> range = target -> next -> range;
                target -> yearBought = target -> next -> yearBought;
                target -> droneType = target -> next -> droneType;
                target -> manufacturer = target -> next -> manufacturer;
                target -> description = target -> next -> description;
                target -> batteryType = target -> next -> batteryType;

                target -> next -> droneID = temp.droneID;
                target -> next -> range = temp.range;
                target -> next -> yearBought = temp.yearBought;
                target -> next -> droneType = temp.droneType;
                target -> next -> manufacturer = temp.manufacturer;
                target -> next -> description = temp.description;
                target -> next -> batteryType = temp.batteryType;
            }
            target = target -> next;
        }
    }
}

// Sorts the list into descending (non‐ascending) order
void DronesManagerSorted::sort_desc() {
    sort_asc();
    reverse_list();
}
