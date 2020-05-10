///////////////////////////////////////////////////////////////
//  File:   Food.cpp
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Food.cpp
///////////////////////////////////////////////////////////////

#include "Food.h"

//prints out the name and cost of a food item
void Food::printFood(ostream &os) {
    os << "---------- Food ----------" << endl;
    os << "Name: " << m_sName << endl;
    os << "Cost: " << m_dCost << endl;
    os << "-----" << endl;
}

//returns the enumeration of a food type
Food::FOOD_TYPE Food::getType() const {
    return m_eType;
}

//constructor with parameters
Food::Food(Food::FOOD_TYPE new_m_eType, string new_m_sName, double new_m_dCost):m_eType(new_m_eType), m_sName(new_m_sName), m_dCost(new_m_dCost) {}

//default constructor
Food::Food():m_eType(),m_sName(),m_dCost()  {}

//returns the food's name
string Food::getName() const {
    return m_sName;
}

//returns the food's cost
double Food::getCost() const {
    return m_dCost;
}

//default destructor
Food::~Food() = default;
