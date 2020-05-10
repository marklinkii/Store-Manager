///////////////////////////////////////////////////////////////
//  File:   Food.h
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Food.h
///////////////////////////////////////////////////////////////

#ifndef PROJECT_2_FOOD_H
#define PROJECT_2_FOOD_H

using namespace std;

#include <ostream>

class Food {
public:
    enum FOOD_TYPE{
        fruit,
        vegetable,
        meat,
        starch,
        sweet
    };
    FOOD_TYPE getType() const;
    void printFood(ostream& os);
    ~Food();
    Food();
    Food(FOOD_TYPE new_m_eType, string new_m_sName, double new_m_dCost);
    string getName() const;
    double getCost() const;
private:
    FOOD_TYPE m_eType;
    string m_sName;
    double m_dCost;
};

#endif //PROJECT_2_FOOD_H
