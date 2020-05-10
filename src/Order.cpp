///////////////////////////////////////////////////////////////
//  File:   Order.cpp
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Order.cpp
///////////////////////////////////////////////////////////////

#include "Order.h"

//sets name using parameter
void Order::setCustomerName(string newName) {
    m_sCustomerName = newName;
}

//sets partial acceptance status using parameter
void Order::setAcceptPartial(bool newAccept) {
    m_bAcceptsPartialOrders = newAccept;
}

//sets the status of the order to complete
void Order::setOrderComplete() {
    m_bOrderCompleted = true;
}

//returns if order is allowed to be partial
bool Order::isAcceptPartial() {
    return m_bAcceptsPartialOrders;
}

//returns the next request then pops it from queue
Food::FOOD_TYPE Order::getNextRequest() {
    auto temp = m_requests.front();
    m_requests.pop();
    return temp;
}

//adds a food type to the request queue
void Order::addRequestToOrder(Food::FOOD_TYPE type) {
    m_requests.push(type);
}

//adds a specific food type to the filled request queue
void Order::addFoodToOrder(Food *newFood) {
    if(newFood == nullptr){
        return;
    }
    m_filledRequests.push(newFood);
}

//removes a food item from the order and returns the food item
Food *Order::popFoodFromOrder() {
    if(m_filledRequests.empty()){
        return nullptr;
    }
    auto front = m_filledRequests.front();
    m_requests.push(front->getType());
    m_filledRequests.pop();
    return front;
}

//prints status of each order
void Order::printOrder(ostream &os) {
    double totalCost = 0.00;

    //temporary unfilled request queue
    queue<Food::FOOD_TYPE> tempReq = m_requests;

    //temporary filled request queue
    queue<Food*> tempFilled = m_filledRequests;

    //temporary unsatisfied request queue
    queue<Food::FOOD_TYPE> tempUnfilled = m_unfilled;

    //if the order hasn't started processing
    if (!m_orderStarted) {
        os << m_sCustomerName << endl;
        os << "Requests: ";
        while(!tempReq.empty()) {
            if (tempReq.front() == Food::FOOD_TYPE::sweet) {
                os << "sweet ";
            } else if (tempReq.front() == Food::FOOD_TYPE::starch) {
                os << "starch ";
            } else if (tempReq.front() == Food::FOOD_TYPE::meat) {
                os << "meat ";
            } else if (tempReq.front() == Food::FOOD_TYPE::fruit) {
                os << "fruit ";
            } else if (tempReq.front() == Food::FOOD_TYPE::vegetable) {
                os << "vegetable ";
            }
            tempReq.pop();
        }
        os << endl << "-----" << endl;
    }

    //if the order is partially filled
    else if(m_bOrderCompleted && m_bAcceptsPartialOrders && tempUnfilled.size()!=0){
        os << m_sCustomerName << " (Partial)" << endl;
        os << "Unfilled requests: ";
        //loop through unfilled requests
        while(!tempUnfilled.empty()) {
            if (tempUnfilled.front() == Food::FOOD_TYPE::sweet) {
                os << "sweet ";
            } else if (tempUnfilled.front() == Food::FOOD_TYPE::starch) {
                os << "starch ";
            } else if (tempUnfilled.front() == Food::FOOD_TYPE::meat) {
                os << "meat ";
            } else if (tempUnfilled.front() == Food::FOOD_TYPE::fruit) {
                os << "fruit ";
            } else if (tempUnfilled.front() == Food::FOOD_TYPE::vegetable) {
                os << "vegetable ";
            }
            tempUnfilled.pop();
        }
        os << endl << "Items:" << endl;
        //loop through filled requests
        while(!tempFilled.empty()){
            os << tempFilled.front()->getName() << " $" << tempFilled.front()->getCost() << endl;
            totalCost += tempFilled.front()->getCost();
            tempFilled.pop();
        }
        os << "Total: $" << totalCost << endl << "-----" << endl;
    }

    //order is completely filled
    else if(m_bOrderCompleted && tempReq.size()==0){
        os << m_sCustomerName << endl << "Items:" << endl;
        while(!tempFilled.empty()){
            os << tempFilled.front()->getName() << " $" << tempFilled.front()->getCost() << endl;
            totalCost += tempFilled.front()->getCost();
            tempFilled.pop();
        }
        os << "Total: $" << totalCost << endl << "-----" << endl;
    }

    //partial order not accepted, print requests
    else if(m_bOrderCompleted && !m_bAcceptsPartialOrders && tempReq.size() > 0){
        os << m_sCustomerName << " - Unable to complete order" << endl;
        os << "Unfilled Requests: ";
        while(!tempReq.empty()) {
            if (tempReq.front() == Food::FOOD_TYPE::sweet) {
                os << "sweet ";
            } else if (tempReq.front() == Food::FOOD_TYPE::starch) {
                os << "starch ";
            } else if (tempReq.front() == Food::FOOD_TYPE::meat) {
                os << "meat ";
            } else if (tempReq.front() == Food::FOOD_TYPE::fruit) {
                os << "fruit ";
            } else if (tempReq.front() == Food::FOOD_TYPE::vegetable) {
                os << "vegetable ";
            }
            tempReq.pop();
        }
        while(!tempUnfilled.empty()){
            if (tempUnfilled.front() == Food::FOOD_TYPE::sweet) {
                os << "sweet ";
            } else if (tempUnfilled.front() == Food::FOOD_TYPE::starch) {
                os << "starch ";
            } else if (tempUnfilled.front() == Food::FOOD_TYPE::meat) {
                os << "meat ";
            } else if (tempUnfilled.front() == Food::FOOD_TYPE::fruit) {
                os << "fruit ";
            } else if (tempUnfilled.front() == Food::FOOD_TYPE::vegetable) {
                os << "vegetable ";
            }
            tempUnfilled.pop();
        }
        os << endl << "-----" << endl;
    }
    else{
        os << "Unknown error with " << m_sCustomerName <<"'s order" << endl << "-----" <<endl;
    }
}

//constructor with parameters
Order::Order(bool newPartial, string newName, bool newOrderCompleted, queue<Food::FOOD_TYPE> newRequests) {
    m_bAcceptsPartialOrders = newPartial;
    m_bOrderCompleted = newOrderCompleted;
    m_sCustomerName = newName;
    m_requests = newRequests;
    m_orderStarted = false;
}

//default constructor
Order::Order():m_bAcceptsPartialOrders(), m_bOrderCompleted(false), m_sCustomerName(), m_requests(), m_orderStarted(false) {}

//returns customer's name
string Order::getName() const {
    return m_sCustomerName;
}

//returns true is the order is finished (false if not)
bool Order::getOrderComplete() const{
    return m_bOrderCompleted;
}

//returns true if the request queue is empty (false if not)
bool Order::requestEmpty() const {
    if(m_requests.empty()){
        return true;
    }
    return false;
}

//sets the status of the order to started
void Order::setOrderStarted() {
    m_orderStarted = true;
}

//adds a food type to a queue of unfilled requests
void Order::addUnfilled(Food::FOOD_TYPE type) {
    m_unfilled.push(type);
}

//default destructor
Order::~Order() = default;
