// Created by Alex Petkovic (20728032) and Kalli Bonin (20706260)

#include <string>
#include "InterpersonalAffinity.hpp"

using namespace std;

int main() {

    string testNames[10] = {"Andy", "Kelsey", "Nathan", "Olive", "Greg", "Shelly", "Jess", "Brooks", "Maria", "Darryl"};
    InterpersonalAffinity testIA;
    testIA.setNames(10, testNames);

    testIA.setAffinity("Andy", "Kelsey", 1);
    testIA.setAffinity("Andy", "Brooks", 3);
    testIA.setAffinity("Kelsey", "Maria", 2);
    testIA.setAffinity("Kelsey", "Nathan", 7);
    testIA.setAffinity("Nathan", "Brooks", 8);
    testIA.setAffinity("Nathan", "Jess", 1);
    testIA.setAffinity("Nathan", "Olive", 6);
    testIA.setAffinity("Olive", "Greg", 10);
    testIA.setAffinity("Olive", "Shelley", 4);
    testIA.setAffinity("Olive", "Jess", 7);
    testIA.setAffinity("Greg", "Shelley", 2);
    testIA.setAffinity("Shelley", "Jess", 6);
    testIA.setAffinity("Jess", "Brooks", 5);
    testIA.setAffinity("Brooks", "Maria", 6);
    testIA.setAffinity("Maria", "Darryl", 2);
    testIA.setAffinity("Darryl", "Andy", 9);

    testIA.print();

    testIA.dijkstra(testNames, 0);

}
