/*
 * EE312 Simple CRM Project
 *
 * YOUR INFO HERE!
 */

#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;
Customer mkt_inventory;


/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */


/* clear the inventory and reset the customer database to empty */
void reset(void) {
    mkt_inventory.bottles = 0;
    mkt_inventory.diapers = 0;
    mkt_inventory.rattles = 0;
    int i = 0;
    while (i < num_customers){
        customers[i].name.ptr = NULL;
        customers[i].name.len = 0;
        customers[i].rattles = 0;
        customers[i].bottles = 0;
        customers[i].diapers = 0;
        i++;
    }
    num_customers = 0;
}

void processSummarize() {
    int idx,i, max;
    printf("There are %d Bottles %d Diapers and %d Rattles in inventory\n",mkt_inventory.bottles, mkt_inventory.diapers, mkt_inventory.rattles);
    printf("we have had a total of %d different customers\n",num_customers);

    //bottles
    idx = max = i = 0; //index for max
    while (idx < num_customers){
        if (customers[idx].bottles > max){
            i = idx;
            max = customers[i].bottles;
        }
        idx++;
    }
    if (max == 0){
        printf("no one has purchased any Bottles\n");
    }
    else if (max != 0){
        StringPrint(&customers[i].name);
        printf(" has purchased the most Bottles (%d)\n", max);
    }

    //diapers
    idx = max = i = 0; //index for max
    while (idx < num_customers){
        if (customers[idx].diapers > max){
            i = idx;
            max = customers[i].diapers;
        }
        idx++;
    }
    if (max == 0){
        printf("no one has purchased any Diapers\n");
    }
    else if (max != 0){
        StringPrint(&customers[i].name);
        printf(" has purchased the most Diapers (%d)\n", max);
    }

    //Rattles
    idx = max = i = 0; //index for max
    while (idx < num_customers){
        if (customers[idx].rattles > max){
            i = idx;
            max = customers[i].rattles;
        }
        idx++;
    }
    if (max == 0){
        printf("no one has purchased any Rattles\n");
    }
    else if (max != 0){
        StringPrint(&customers[i].name);
        printf(" has purchased the most Rattles (%d)\n", max);
    }
}

void processPurchase() {
    String strholder;
    int numholder;
    String Bottles = StringCreate("Bottles");
    String Rattles = StringCreate("Rattles");
    String Diapers = StringCreate("Diapers");
    Customer temp;
    temp.rattles = 0;
    temp.bottles = 0;
    temp.diapers = 0;
    readString(&strholder);
    if (numholder == 0) { return void();};
    temp.name = strholder;
    readString(&strholder); //item type
    readNum(&numholder);
    if (StringIsEqualTo(&strholder, &Bottles)) {
        if(mkt_inventory.bottles < numholder){printf("Sorry ");StringPrint(&temp.name); printf(", we only have %d Bottles\n", mkt_inventory.bottles);return void();}
        mkt_inventory.bottles -= numholder;
        temp.bottles += numholder;
    } else if (StringIsEqualTo(&strholder, &Rattles)) {
        if(mkt_inventory.diapers < numholder){printf("Sorry ");StringPrint(&temp.name); printf(", we only have %d Rattles\n", mkt_inventory.rattles);return void();}
        mkt_inventory.rattles -= numholder;
        temp.rattles += numholder;
    } else if (StringIsEqualTo(&strholder, &Diapers)) {
        if(mkt_inventory.diapers < numholder){printf("Sorry ");StringPrint(&temp.name); printf(", we only have %d Diapers\n", mkt_inventory.diapers);return void();}
        mkt_inventory.diapers -= numholder;
        temp.diapers += numholder;
    }
    int i =0;
    bool match = 0;
    while(i<num_customers){
        if (StringIsEqualTo(&customers[i].name,&temp.name)){
            match = 1;
            break;
        }
        i++;
    }
    if (match == 0 || num_customers == 0){//new customer
        customers[num_customers].name = temp.name;
        customers[num_customers].diapers = temp.diapers;
        customers[num_customers].rattles = temp.rattles;
        customers[num_customers].bottles = temp.bottles;
        num_customers++;
    }
    else if (match == 1){//existing customer
        customers[i].diapers += temp.diapers;
        customers[i].rattles += temp.rattles;
        customers[i].bottles += temp.bottles;
    }
    StringDestroy(&Bottles);
    StringDestroy(&Rattles);
    StringDestroy(&Diapers);
    StringDestroy(&strholder);
}



void processInventory() {

    String strholder;
    int numholder;
    String Bottles = StringCreate("Bottles");
    String Rattles = StringCreate("Rattles");
    String Diapers = StringCreate("Diapers");

    readString(&strholder);
    readNum(&numholder);
    if (StringIsEqualTo(&strholder, &Bottles)) {
        mkt_inventory.bottles += numholder;
    } else if (StringIsEqualTo(&strholder, &Rattles)) {
        mkt_inventory.rattles += numholder;
    } else if (StringIsEqualTo(&strholder, &Diapers)) {
        mkt_inventory.diapers += numholder;
    }
    StringDestroy(&Bottles);
    StringDestroy(&Rattles);
    StringDestroy(&Diapers);
    StringDestroy(&strholder);
}
