///////////////////////////////////////////////////////////////
//  File:   Store.cpp
//  Course: CSCE-221 Data Structures & Algorithms
//  Author: Mark Link
//  Date:   10/23/2019
//  Usage:  Complete definition of Class Store.cpp
///////////////////////////////////////////////////////////////

#include <fstream>
#include <sstream>
#include "Store.h"

//takes food parameter and places it in respective bin by type
void Store::addFood(Food* newFood) {
    if(newFood->getType()==Food::FOOD_TYPE::sweet){
        m_bins[0].push(newFood);
    }
    else if(newFood->getType()==Food::FOOD_TYPE::meat){
        m_bins[1].push(newFood);
    }
    else if(newFood->getType()==Food::FOOD_TYPE::starch){
        m_bins[2].push(newFood);
    }
    else if(newFood->getType()==Food::FOOD_TYPE::vegetable){
        m_bins[3].push(newFood);
    }
    else if(newFood->getType()==Food::FOOD_TYPE::fruit){
        m_bins[4].push(newFood);
    }
}

//returns the first food item of a given type
Food *Store::getFoodByType(Food::FOOD_TYPE type) {
    //loops through all bins
    for(int i = 0; i < 5; ++i){
        //if the bin is not empty
        if(!m_bins.at(i).empty()){
            //if the items in the bin are of same type
            if(m_bins.at(i).top()->getType() == type) {
                Food *item = m_bins.at(i).top();
                m_bins.at(i).pop();
                return item;
            }
        }
    }
    //item not found
    return nullptr;
}

//puts food into bins from a text file
void Store::stockStore(string filename) {
    ifstream file(filename);
    string dummy;
    string name;
    string type;
    double cost;
    //if file won't open,, exit
    if(!file.good()){
        exit(1);
    }
    //gets name from a set of quotations, followed by type and cost
    while(getline(getline(file, dummy, '"'), name, '"') >> type >> cost)
    {
        //identify the type then create a food object
        //then, add the food object to the store
        if(type == "sweet"){
            Food* newFood = new Food(Food::FOOD_TYPE::sweet, name, cost);
            addFood(newFood);
        }
        else if(type == "starch"){
            Food* newFood = new Food(Food::FOOD_TYPE::starch, name, cost);
            addFood(newFood);
        }
        else if(type == "meat"){
            Food* newFood = new Food(Food::FOOD_TYPE::meat, name, cost);
            addFood(newFood);
        }
        else if(type == "fruit"){
            Food* newFood = new Food(Food::FOOD_TYPE::fruit, name, cost);
            addFood(newFood);
        }
        else if(type == "vegetable"){
            Food* newFood = new Food(Food::FOOD_TYPE::vegetable, name, cost);
            addFood(newFood);
        }
        else {
            return;
        }
    }
}

//prints quantity of items, type of items, and name of items in the store
void Store::printStore(ostream &os) {
    //temporary copy of bins to print items
    vector<stack<Food*>> tempFood = m_bins;
    os << "---------- Store ----------" << endl;
    //loops through bins
    for(int i = 0; i < tempFood.size(); ++i){
        //if any bin is empty
        if(tempFood.at(i).empty()){
            if(i == 0){
                os << "sweet: 0" << endl;
            }
            else if(i == 1){
                os << "meat: 0" << endl;
            }
            else if(i == 2){
                os << "starch: 0" << endl;
            }
            else if(i == 3){
                os << "vegetable: 0" << endl;
            }
            else if(i == 4){
                os << "fruit: 0" << endl;
            }
        }
        //bin is not empty
        else {
            //print the type
            if (tempFood.at(i).top()->getType() == Food::FOOD_TYPE::sweet) {
                os << "sweet: ";
            } else if (tempFood.at(i).top()->getType() == Food::FOOD_TYPE::meat) {
                os << "meat: ";
            } else if (tempFood.at(i).top()->getType() == Food::FOOD_TYPE::starch) {
                os << "starch: ";
            } else if (tempFood.at(i).top()->getType() == Food::FOOD_TYPE::vegetable) {
                os << "vegetable: ";
            } else if (tempFood.at(i).top()->getType() == Food::FOOD_TYPE::fruit) {
                os << "fruit: ";
            }
            //then print quantity
            os << tempFood.at(i).size() << " ";
            //then loop through and print item names
            while (!tempFood.at(i).empty()) {
                if (tempFood.at(i).size() == 1) {
                    os << tempFood.at(i).top()->getName();
                    tempFood.at(i).pop();
                } else {
                    os << tempFood.at(i).top()->getName() << ", ";
                    tempFood.at(i).pop();
                }
            }
            os << endl;
        }
    }
}

//default constructor
Store::Store(){
    //creates empty stacks to represent each food bin
    auto* one = new stack<Food*>;
    m_bins.push_back(*one);
    auto* two = new stack<Food*>;
    m_bins.push_back(*two);
    auto* three = new stack<Food*>;
    m_bins.push_back(*three);
    auto* four = new stack<Food*>;
    m_bins.push_back(*four);
    auto* five = new stack<Food*>;
    m_bins.push_back(*five);
}

//default destructor
Store::~Store() = default;
