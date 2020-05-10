///////////////////////////////////////////////////////////////
//  File:   Orders.cpp
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Orders.cpp
///////////////////////////////////////////////////////////////

#include <fstream>
#include <sstream>
#include "Orders.h"

//adds an order to a queue of unfilled orders
void Orders::addOrder(Order *newOrder) {
    m_ordersUnfilled.push(newOrder);
}

//moves an order from a queue of unfilled orders to a queue of filled orders
//also changes the current order to the next in queue for unfilled orders
void Orders::completeOrder() {
    m_ordersCompleted.push(m_ordersUnfilled.front());
    m_ordersUnfilled.pop();
    if(m_ordersUnfilled.empty()){
        m_pCurrentOrder = nullptr;
    }
    else{
        m_pCurrentOrder = m_ordersUnfilled.front();
    }
}

//returns the first unfilled order
Order *Orders::getCurrentOrder() {
    m_pCurrentOrder = m_ordersUnfilled.front();
    return m_pCurrentOrder;
}


//loads orders from a text file
void Orders::loadOrders(string fileName) {
    ifstream file(fileName);
    string fname;
    string lname;
    string name;
    string type;
    string partial;
    istringstream ss(fileName);
    bool accepts;
    //exit if the file won't open
    if(!file.good()){
        exit(1);
    }
    string str;
    //while there are lines in the file
    while(getline(file, str)) {
        //stringstream takes the line and makes it a string
        istringstream ss(str);
        //first word is first name
        ss >> fname;
        //second word is last name
        ss >> lname;
        //third word is partial boolean
        ss >> partial;
        name = fname + " " + lname;
        if (partial == "yes") {
            accepts = true;
        } else {
            accepts = false;
        }
        //creates an order
        Order* newOrder = new Order();
        //sets name
        newOrder->setCustomerName(name);
        //sets partial acceptance
        newOrder->setAcceptPartial(accepts);
        //loops through rest of line, adding food types to the order accordingly
        while(ss>>type) {
            if (type == "sweet") {
                newOrder->addRequestToOrder(Food::FOOD_TYPE::sweet);
            } else if (type == "starch") {
                newOrder->addRequestToOrder(Food::FOOD_TYPE::starch);
            } else if (type == "meat") {
                newOrder->addRequestToOrder(Food::FOOD_TYPE::meat);
            } else if (type == "fruit") {
                newOrder->addRequestToOrder(Food::FOOD_TYPE::fruit);
            } else if (type == "vegetable") {
                newOrder->addRequestToOrder(Food::FOOD_TYPE::vegetable);
            }
        }
        //order is added to queue of unfilled orders
        addOrder(newOrder);
    }
}

//prints orders from the queue
void Orders::printOrders(ostream &os) {
    //temporary queues to loop through and print values
    queue<Order*> tempUnfilled = m_ordersUnfilled;
    queue<Order*> tempCompleted = m_ordersCompleted;
    os << "---------- Orders ----------" << endl;
    //unfilled orders being printed
    while(!tempUnfilled.empty()){
        tempUnfilled.front()->printOrder(os);
        tempUnfilled.pop();
    }
    //filled orders being printed
    while(!tempCompleted.empty()){
        tempCompleted.front()->printOrder(os);
        tempCompleted.pop();
    }
}

//default constructor
Orders::Orders(): m_ordersCompleted(), m_ordersUnfilled(), m_pCurrentOrder() {}

//default destructor
Orders::~Orders() = default;
