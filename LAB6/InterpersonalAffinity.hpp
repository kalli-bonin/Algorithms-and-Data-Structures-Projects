// Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#ifndef INTERPERSONAL_AFFINITY_HPP
#define INTERPERSONAL_AFFINITY_HPP

#include <string>

using namespace std;

class InterpersonalAffinity {

public:
    // EXPLICIT CONSTRUCTOR AND DESTRUCTOR
    // creates a new empty DronesGraph
    InterpersonalAffinity();
    // destroy this DronesGraph, and frees up all dynamically allocated memory
    ~InterpersonalAffinity();

    int getSize() const;
    int getCapacity();

    bool setNames(int nSize, string nNames[]);
    bool setAffinity(string nameA, string nameB, int affinity);
    bool clearGraph();

    void print();

    void printPath(int dist[], string names[], int j);
    //int  printSolution(int dist[], int n, int parent[]);

    int  minDistance(int dist[], bool visited[]);
    void dijkstra(string names[], int start);


private:
    string* names;         // Array of names
    int size, capacity;     // Size and capacity of names
    int** edges = NULL;     // 2D array of edge values (social affinity)

};

#endif // INTERPERSONAL_AFFINITY_HPP