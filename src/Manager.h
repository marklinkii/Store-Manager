///////////////////////////////////////////////////////////////
//  File:   Manager.h
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Manager.h
///////////////////////////////////////////////////////////////

#ifndef PROJECT_2_MANAGER_H
#define PROJECT_2_MANAGER_H

using namespace std;

#include "Store.h"
#include "Orders.h"

class Manager {
private:
    string storeName;
    string orderName;
    Store m_store;
    Orders m_orders;
public:
    ~Manager();
    Manager();
    Manager(string newStoreName, string newOrderName);
    void createStore(string filename);
    void createOrders(string filename);
    void fillOrders(ostream& os);
    void printStatus(ostream& os);
};

#endif //PROJECT_2_MANAGER_H
