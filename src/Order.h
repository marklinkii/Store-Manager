///////////////////////////////////////////////////////////////
//  File:   Order.h
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Order.h
///////////////////////////////////////////////////////////////

#ifndef PROJECT_2_ORDER_H
#define PROJECT_2_ORDER_H

using namespace std;

#include <queue>
#include <string>
#include <ostream>

#include "Food.h"

class Order {
private:
    string m_sCustomerName;
    queue<Food::FOOD_TYPE> m_requests;
    bool m_bAcceptsPartialOrders;
    bool m_bOrderCompleted;
    bool m_orderStarted;
    queue<Food*> m_filledRequests;
    queue<Food::FOOD_TYPE> m_unfilled;
public:
    ~Order();
    Order();
    Order(bool newPartial, string newName, bool newOrderCompleted, queue<Food::FOOD_TYPE> newRequests);

    void addUnfilled(Food::FOOD_TYPE);
    void setCustomerName(string newName);
    void setAcceptPartial(bool newAccept);
    void setOrderComplete();
    void setOrderStarted();
    bool isAcceptPartial();
    string getName() const;

    bool requestEmpty() const;
    bool getOrderComplete() const;
    Food::FOOD_TYPE getNextRequest();
    void addRequestToOrder(Food::FOOD_TYPE type);
    void addFoodToOrder(Food* newFood);
    Food* popFoodFromOrder();

    void printOrder(ostream& os);
};

#endif //PROJECT_2_ORDER_H
