///////////////////////////////////////////////////////////////
//  File:   Orders.h
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Orders.h
///////////////////////////////////////////////////////////////

#ifndef PROJECT_2_ORDERS_H
#define PROJECT_2_ORDERS_H

using namespace std;

#include <queue>

#include "Order.h"

class Orders {
private:
    queue<Order*> m_ordersUnfilled;
    queue<Order*> m_ordersCompleted;
    Order* m_pCurrentOrder;
public:
    ~Orders();
    Orders();

    void addOrder(Order* newOrder);
    void completeOrder();
    Order* getCurrentOrder();
    void loadOrders(string fileName);
    void printOrders(ostream& os);
};

#endif //PROJECT_2_ORDERS_H
