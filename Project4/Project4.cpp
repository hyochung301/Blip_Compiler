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
Customer temp;

/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */


/* clear the inventory and reset the customer database to empty */
void reset(void) {
    /* your code here */
}

void processSummarize() {
    printf("There are %d Bottles %d Diapers and %d Rattles in inventory\n",mkt_inventory.bottles, mkt_inventory.diapers, mkt_inventory.rattles);
    //printf("we have had a total of 1 different customers");
    //printf(&s has purchased the most Bottles (4), );
    //printf(Craig has purchased the most Diapers (120), );
    //printf(no one has purchased any Rattles,);
}

void processPurchase() {
    
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
