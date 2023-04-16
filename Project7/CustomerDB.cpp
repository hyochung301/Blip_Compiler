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
    if (isMember(name)) {
        for (int i = 0; i < this->length; i++) {
            if (this->data[i].name == name) {
                return this->data[i];// customer found, return by reference
            }
        }
    }
        //customer not found, add to the list
    else {
        if (this->length == this->capacity) {
            // double the capacity

            // create a new array with the doubled capacity
            Customer *new_data = new Customer[(this->capacity)*2];
            // copy the old data to the new array
            for (int i = 0; i < this->length; i++) {
                new_data[i] = this->data[i];
            }
            // delete the old data
            delete[] this->data;
            // update the data pointer to point to the new array
            this->data = new_data;
            this->capacity *= 2;

        }
        //add the customer
        Customer temp(name);
        this->data[this->length] = temp;
        this->length += 1;
        return this->data[this->length - 1];
    }
}

bool CustomerDB::isMember(UTString name) {
    for (int i = 0; i < this->length; i++){
        if (this->data[i].name == name){
            return true;
        }
    }
    return false;

}
