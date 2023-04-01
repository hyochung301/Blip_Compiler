// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Hyokwon Chung
// hc27426
// Slip days used: <0>
// Spring 2023

#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here
    int i = 0;
    for (int i = 0; i < this->length; i++) {
        Customer& cus = this->data[i];
        if (name == cus.name) {
            return cus; // customer found, return by reference
        }
    }
    //customer not found, add to the list
    if (this->length == this -> capacity) {//check capacity by comparing length and cap
        this->capacity = this->capacity * 2;// if capacity is smaller, double the cap
    }

    Customer temp(name); //add the customer by customer constructor
    this->data[this->length] = temp;
    //increase the length
    this->length += 1;
    //return by reference
    return this->data[this->length - 1];
    ;
}

bool CustomerDB::isMember(UTString name) {
    int i = 0;
    while (i < this->length){
        if (name == this->operator[](i).name){
            return true;
        }
        return false;
    }
}
