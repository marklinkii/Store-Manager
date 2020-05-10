///////////////////////////////////////////////////////////////
//  File:   Store.h
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Store.h
///////////////////////////////////////////////////////////////

#ifndef PROJECT_2_STORE_H
#define PROJECT_2_STORE_H

using namespace std;

#include <stack>
#include <vector>

#include "Food.h"

class Store {
private:
    vector<stack<Food*>> m_bins;
public:
    ~Store();
    Store();
    void addFood(Food* newFood);
    Food* getFoodByType(Food::FOOD_TYPE type);
    void stockStore(string filename);
    void printStore(ostream& os);
};

#endif //PROJECT_2_STORE_H
