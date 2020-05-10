///////////////////////////////////////////////////////////////
//  File:   Manager.cpp
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Manager.cpp
///////////////////////////////////////////////////////////////

#include "Manager.h"
#include <fstream>
#include <sstream>

//creates store from file (puts items in bins)
void Manager::createStore(string filename) {
    m_store.stockStore(filename);
}

//creates orders from file
void Manager::createOrders(string filename) {
    m_orders.loadOrders(filename);
}

//fills each order accordingly
void Manager::fillOrders(ostream &os) {
    //while there are orders
    while(m_orders.getCurrentOrder() != nullptr){
        Order* current = m_orders.getCurrentOrder();
        current->setOrderStarted();
        //completes current order
        while(!current->getOrderComplete()) {
            Food::FOOD_TYPE curReq = current->getNextRequest();
            Food* currentitem = m_store.getFoodByType(curReq);
            //partial order allowed
            if (current->isAcceptPartial()) {
                //store doesn't have food type
                if(currentitem == nullptr){
                    current->addUnfilled(curReq);
                }
                //store has request
                else {
                    current->addFoodToOrder(currentitem);
                }
                //no more requests- complete order
                if(current->requestEmpty()){
                    current->setOrderComplete();
                    m_orders.completeOrder();
                }
            }
            //partial order not allowed
            else{
                //store doesn't have food type - return all items
                if(currentitem == nullptr){
                    current->addUnfilled(curReq);
                    //return items to store
                    Food* goBack = current->popFoodFromOrder();
                    if(goBack!= nullptr){
                        m_store.addFood(goBack);
                    }
                    while(goBack != nullptr){
                        goBack = current->popFoodFromOrder();
                        if(goBack!=nullptr) {
                            current->addUnfilled(goBack->getType());
                            m_store.addFood(goBack);
                        }
                    }
                    current->setOrderComplete();
                    m_orders.completeOrder();
                }
                //store has request
                else {
                    current->addFoodToOrder(currentitem);
                }
                //no more requests- complete order
                if(current->requestEmpty()){
                    current->setOrderComplete();
                    m_orders.completeOrder();
                }
            }
        }
    }
}

//prints items in store and status of orders
void Manager::printStatus(ostream &os) {
    m_store.printStore(os);
    m_orders.printOrders(os);
}

//constructor with parameters: calls to create store and orders
Manager::Manager(string newStoreName, string newOrderName): storeName(newStoreName), orderName(newOrderName) {
    createStore(newStoreName);
    createOrders(newOrderName);
}

//default constructor
Manager::Manager():m_store(), m_orders(), storeName(), orderName() {}

//default destructor
Manager::~Manager() = default;

