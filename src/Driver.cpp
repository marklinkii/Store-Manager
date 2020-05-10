///////////////////////////////////////////////////////////////
//  File:   Driver.cpp
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Driver.cpp
///////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Manager.h"

void printGreeting(){
    cout << "Mark Link" << endl;
    cout << "Section 503" << endl;
}

int main(int argc, char* argv[]) {
    std::ofstream outputFileStream;

    //print greeting
    printGreeting();

    //take in store and order files
    Manager manager(argv[1], argv[2]);

    //open output file
    outputFileStream.open("results.txt");

    manager.printStatus(outputFileStream);

    manager.fillOrders(outputFileStream);

    manager.printStatus(outputFileStream);

    outputFileStream.close();

    return EXIT_SUCCESS;
}