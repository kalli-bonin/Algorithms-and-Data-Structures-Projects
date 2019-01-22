// Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#include <iostream>
#include <limits.h>
#include <iomanip>
#include "InterpersonalAffinity.hpp"

using namespace std;

const int CAPACITY = 10;

// Constructor
InterpersonalAffinity::InterpersonalAffinity() {
    size = 0;
    capacity = CAPACITY;

    names = new string[capacity]();

    // Initialize array of graphs
    edges = new int*[capacity]();
    for(int i = 0; i < capacity; i++)
        edges[i] = new int[capacity]();

    clearGraph();
}

// Destructor
InterpersonalAffinity::~InterpersonalAffinity() {
    for(int i = 0; i < capacity; i++)
        delete [] edges[i];
    delete [] edges;
}

int InterpersonalAffinity::getSize() const {
    return size;
}

int InterpersonalAffinity::getCapacity() {
    return capacity;
}

bool InterpersonalAffinity::clearGraph() {
    for (int i = 0; i < capacity; i++) {
        names[i] = "";
    }

    for (int i = 0; i < capacity; i++) {
        for (int j = 0; j < capacity; j++) {
            edges[i][j] = 0;
        }
    }
}

bool InterpersonalAffinity::setNames(int nSize, string nNames[]) {
    if (nSize > capacity) return false;

    clearGraph();

    for (int i = 0; i < nSize; i++) {
        names[i] = nNames[i];
    }

    size = nSize;
}

bool InterpersonalAffinity::setAffinity(string nameA, string nameB, int affinity) {
    int nameAIndex = -1, nameBIndex = -1;
    for (int i = 0; i < size; i++) {
        if (names[i] == nameA) nameAIndex = i;
        if (names[i] == nameB) nameBIndex = i;
    }

    if (nameAIndex < 0 || nameBIndex < 0) return false;

    edges[nameAIndex][nameBIndex] = affinity;
    edges[nameBIndex][nameAIndex] = affinity;

    return true;
}

void InterpersonalAffinity::print() {
    cout << endl << left << setw(15) << " ";
    for (int i = 0; i < size; i++) {
        cout << setw(15) << names[i];
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << setw(15) << names[i];
        for (int j = 0; j < size; j++) {
            cout << setw(15) << edges[i][j];
        }
        cout << endl;
    }
}

void InterpersonalAffinity::dijkstra(string names[] , int start)
{
    int dist[capacity];     // dist[i] holds the shortest distance from src to i

    bool visited[capacity]; // visited[i] == true if node i is included in shortest path from src to i

    // initialize all distances as "infinite" and visited as false
    for (int i = 0; i < capacity; i++)
        dist[i] = INT_MAX, visited[i] = false;

    // distance of starting node from itself is always 0
    dist[start] = 0;

    // find shortest path for all nodes
    for (int count = 0; count < capacity-1; count++)
    {
        // find the min distance node from the nodes that are unvisited
        int unvisited = minDistance(dist, visited);

        // mark the chosen node as visited
        visited[unvisited] = true;

        // update dist value of the adjacent nodes of the chosen node.
        for (int i = 0; i < capacity; i++)
        {
            // Update dist[i] only if the three following conditions are met
            // 1) if node is still unvisited
            // 2) if a path exists from node and the adjacent nodes edge
            // 3) if total weight of the path from start to current position is smaller than current value of dist[i]

            if (!visited[i] && edges[unvisited][i] && dist[unvisited] != INT_MAX && ( dist[unvisited] + edges[unvisited][i] ) < dist[i])
                dist[i] = dist[unvisited] + edges[unvisited][i];
        }
    }

    // print the constructed distance array
    printPath(dist, names, start);
}

int InterpersonalAffinity::minDistance(int dist[], bool visited[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int i = 0; i < capacity; i++)
        if (visited[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}


void InterpersonalAffinity::printPath(int dist[], string names[], int start)
{
    cout <<"Starting at " << names[start] << endl << endl;

    cout << "Name        Distance to " << endl;
    for (int i = 0; i < capacity; i++)
        cout << setw(14) << names[i] << setw(10) << dist[i] << endl;

    cout << endl;

}

