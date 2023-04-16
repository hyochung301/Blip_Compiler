// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Hyokwon Chung
// hc27426
// Slip days used: <0>
// Spring 2023

#include <stdio.h>
#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"

void readString(UTString&);
void readNum(int&);

CustomerDB database;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;

/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Bottles") {
        return &num_bottles;
    } else if (word == "Diapers") {
        return &num_diapers;
    } else if (word == "Rattles") {
        return &num_rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Bottles") {
        return &cust.bottles;
    } else if (word == "Diapers") {
        return &cust.diapers;
    } else if (word == "Rattles") {
        return &cust.rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}

void processPurchase() {
    // not done, your effort goes here
    UTString str_item, str_customer;
    int numholder;
    readString(str_customer);
    readString(str_item);
    readNum(numholder);
    if (numholder > 0) {
        if (*selectInventItem(str_item) < numholder) {//database[str_customer].name.c_str()
            printf("Sorry %s, we only have %d %s\n", str_customer.c_str(), *selectInventItem(str_item),
                   str_item.c_str());
        } else {
            Customer cust = database[str_customer];
            int* items = selectInventItem(str_item, cust);
            *items += numholder;
            database[str_customer] = cust;
            //*selectInventItem(str_item, database[str_customer]) += numholder; //add purchased num to customer db
            *selectInventItem(str_item) -= numholder; //subtract from the inventory
        }
    }
}

void processSummarize() {
    printf("There are %d Bottles %d Diapers and %d Rattles in inventory\n", num_bottles, num_diapers, num_rattles);
    printf("we have had a total of %d different customers\n",database.size());

    Customer* max_bot = findMax("Bottles");
    if (max_bot == 0){
        printf("no one has purchased any Bottles\n");
    }
    else if (max_bot != 0){
        printf("%s has purchased the most Bottles (%d)\n", max_bot->name.c_str(), max_bot->bottles);
    }

    //diapers
    Customer* max_dia = findMax("Diapers");
    if (max_bot == 0){
        printf("no one has purchased any Diapers\n");
    }
    else if (max_bot != 0){
        printf("%s has purchased the most Diapers (%d)\n", max_dia->name.c_str(), max_dia->diapers);
    }

    //Rattles
    Customer* max_rat = findMax("Rattles");
    if (max_rat == 0){
        printf("no one has purchased any Rattles\n");
    }
    else if (max_rat != 0){
        printf("%s has purchased the most Rattles (%d)\n", max_rat->name.c_str(), max_rat->rattles);
    }

}

void processInventory() {
    UTString strholder;
    int numholder;
    readString(strholder);
    readNum(numholder);


    if (strholder == "Bottles"){
        num_bottles += numholder;
    }
    else if (strholder == "Rattles"){
        num_rattles += numholder;
    }
    else if (strholder == "Diapers"){
        num_diapers += numholder;
    }
}
