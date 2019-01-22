// Alex Petkovic (20728032) and Kalli Bonin (20706260)

#include <iostream>
#include "priority_queue.hpp"

using namespace std;

// Constructor initializes heap to an array of (capacity + 1) size,
// so that there are at most capacity elements in the priority queue.
// Elements should be stored into index 1 and higher.
PriorityQueue::PriorityQueue(unsigned int capacity) {
    cout << "TEST";
    capacity_ = capacity;
    size_ = 0;
	heap_ = new TaskItem*[capacity + 1]();
}

// Destructor of the class PriorityQueue.
// It deallocates the memory space allocated for the priority queue.
PriorityQueue::~PriorityQueue() {
    for (int i = 0; i <= size_; i++) {
        if (heap_[i]) delete heap_[i];
    }
	delete [] heap_;
}

// Returns the number of elements in the priority queue.
unsigned int PriorityQueue::size() const {
	return size_;
}

// Returns true if the priority queue is empty, and false otherwise.
bool PriorityQueue::empty() const {
   return size_ == 0;
}

// Returns true if the priority queue is full, and false otherwise.
bool PriorityQueue::full() const {
	return size_ == capacity_;
}

// Prints the contents of the priority queue. Format is not specified.
void PriorityQueue::print() const {
	for(int i = 1; i <= size_; ++i) {
		if(heap_[i])
			cout << "heap[" << i << "] = (Priority: " << heap_[i]->priority << ", Description: " << heap_[i]->description << ")" << endl;
	}
}

// Returns the max element of the priority queue, but does not remove it.
// If the priority queue is empty, it returns (-1, "NULL").
PriorityQueue::TaskItem PriorityQueue::max() const {
    if (empty())
        return TaskItem(-1, "NULL");
    return *heap_[1];
}

// Inserts the given value into the priority queue.
// Returns true if successful, and false otherwise.
// Priority queue does not change in capacity.
bool PriorityQueue::enqueue( TaskItem val ) {
    if (full())
        return false;

    if (empty()){
        heap_[1] = new TaskItem(val);

    } else {
        int index = size_ + 1;
        heap_[index] = new TaskItem(val);

        // Ensures heap compliance, by iterating through the heap, moving new TaskItem up
        // the heap while its parent's priority is less than its priority.
        while (index > 1 && heap_[index / 2]->priority < heap_[index]->priority) {
            TaskItem* temp = heap_[index];
            heap_[index] = heap_[index/2];
            heap_[index/2] = temp;
            index /= 2;
        }
    }

    size_++;

    return true;
}

// Removes the top element with the maximum value (priority) and rearranges
// the resulting heap. Returns true if successful, and false otherwise.
// Priority queue does not change in capacity.
bool PriorityQueue::dequeue() {
    if (empty())
        return false;

    delete heap_[1];
    heap_[1] = heap_[size_];
    size_--;

    int index = 1;

    // Ensures heap compliance, by iterating through the heap, moving the new root TaskITem down the heap
    // while its priority is less than its largest child's priority.
    while (index < size_ / 2 && index * 2 + 1 < size_ && heap_[index]->priority < std::max(heap_[index * 2]->priority, heap_[index * 2 + 1]->priority)) {
        int swapIndex = 0;
        if (heap_[index * 2]->priority > heap_[index * 2 + 1]->priority)
            swapIndex = index * 2;
        else
            swapIndex = index * 2 + 1;

        TaskItem* temp = heap_[index];
        heap_[index] = heap_[swapIndex];
        heap_[swapIndex] = temp;
        index = swapIndex;
    }

    return true;
}
