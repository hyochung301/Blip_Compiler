
// Set <Project5.cpp>
// EE 312 Project 5 submission by
// Hyokwon Chung
// hc27426
// Slip days used: <0>
// Spring 2023


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"

/*
 * Several of the required functions have been written already
 * You may use these functions as-is or you may modify them in any way.
 * Please NOTE, you are responsible for ensuring that the functions work correctly in
 * your project solution. Just because the function works correctly in my solution does
 * NOT mean that the function will work correctly in yours.
 */

/*
 * Design NOTES:
 *
 * The design provided in this starter kit assumes
 * (1) empty sets will be represented with length == 0 and elements == nullptr (i.e., address 0)
 * (2) amortized doubling is not used, and capacity is ignored/unused. Functions should assume that
 * the amount of storage available in the elements[] array is equal to length
 */

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;


        if (arr[mid] == x)
            return mid;


        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

/* done for you already */
void destroySet(Set* self) {
    free(self->elements);
}

/* done for you already */
void createEmptySet(Set* self) {
    self->len = 0;
    self->elements = nullptr;
}

/* done for you already */
void createSingletonSet(Set* self, int x) {
    self->elements = (int*) malloc(sizeof(int));
    self->elements[0] = x;
    self->len = 1;
}

/* done for you already */
void createCopySet(Set* self, const Set* other) {
    self->elements = (int*) malloc(other->len * sizeof(int));
    for (int k = 0; k < other->len; k += 1) {
        self->elements[k] = other->elements[k];
    }
    self->len = other->len;
}

/* done for you already */
void assignSet(Set* self, const Set* other) {
    if (self == other) { return; }

    destroySet(self);
    createCopySet(self, other);
}

/* return true if x is an element of self */
bool isMemberSet(const Set* self, int x) {
    int n = self->len;
    int ret = binarySearch(self->elements, 0, n-1, x);
    if (ret == -1) return false;
    else return true;
}

/*
 * add x as a new member to this set.
 * If x is already a member, then self should not be changed
 * Be sure to restore the design invariant property that elements[] remains sorted
 * (yes, you can assume it is sorted when the function is called, that's what an invariant is all about)
 */
void insertSet(Set* self, int x) {
    int n = self->len;
    int idx=0;
    if (n == 0){createSingletonSet(self, x);return;} //new set, return new
    if (self->elements[n-1] < x){idx = n;}//if last element is smaller than the x,
    else {
        for (idx = 0; idx<n; idx++){
            if (self->elements[idx] == x) {
                return;     //if item is found, skip
            }
            else if (self->elements[idx] > x){//if item is smaller, find the pointer
                break;
            }
//        else if (self->elements[idx] > x){
//            break; //if item is bigger, go to next
//        }
        }
    }

    (self->len)++;; // increase the size
    self->elements  = (int*)realloc(self->elements, (self->len)*(sizeof(int))); //increase the size
    if (idx != ((self->len)-1)){
        for (int i = (self->len)-1 ; i >= idx; i--){
            self->elements[i] = self->elements[i - 1]; //shift elements
        }
    }
    self->elements[idx] = x;

}


/*
 * don't forget: it is OK to try to remove an element
 * that is NOT in the set.
 * If 'x' is not in the set 'self', then
 * removeSet should do nothing (it's not an error)
 * Otherwise, ('x' IS in the set), remove x. Be sure to update self->length
 * It is not necessary (nor recommended) to call malloc -- if removing an element means the
 * array on the heap is "too big", that's almost certainly OK, and reallocating a smaller array
 * is almost definitely NOT worth the trouble
 */
void removeSet(Set* self, int x) {
    int n = self->len;
    if (n == 0){return;}
    int i = 0;
    if(self->elements[n-1] == x) {(self->len)--;return;}
    int idx = binarySearch(self->elements, 0, n-1, x);
    if (idx == -1)return;
    for (i = idx+1; i <= n; i++){
        self->elements[i-1] = self->elements[i];
    }
    (self->len)--;
}

/* done for you already */
void displaySet(const Set* self) {
    int k;

    printf("{");

    if (self->len == 0) {
        printf("}");
    }
    else {
        for (k = 0; k < self->len; k += 1) {
            if (k < self->len - 1) {
                printf("%d,", self->elements[k]);
            } else {
                printf("%d}", self->elements[k]);
            }
        }
    }
}

/* return true if self and other have exactly the same elements */
bool isEqualToSet(const Set* self, const Set* other) {
    int n = self->len;
    int n2 = other->len;
    if (n != n2) return false;

    for (int i = 0; i < n; i++) {
        if (self->elements[i] != other->elements[i]) {
            return false;
        }
    }
        return true;
}


/* return true if every element of self is also an element of other */
bool isSubsetOf(const Set* self, const Set* other) {
    int n = self->len;
    int n2 = other->len;
    if (n > n2) return false;
    int idx2, i;
    idx2 = i= 0;
    while (idx2 < n2){
        if (self->elements[i] == other->elements[i]) {
            i++;
        }
        idx2++;
        if (i == n){return false;} // reached the end of self
    }
    return true;
}

/* done for you */
bool isEmptySet(const Set* self) {
    return self->len == 0;
}

/* remove all elements from self that are not also elements of other */
void intersectFromSet(Set* self, const Set* other) {
    int n = self->len;
    int n2 = other->len;
    int idx2, i;
    idx2 = i = 0;
    bool leftover = false;



    while(i<n){//if self ends earlier, break out of the love
        if(idx2 == n2){leftover = true; break;}//if other ends earlier, there are left over
        if(self->elements[i] == other->elements[idx2]){//same, increment both i++, idx2++;
            i++; idx2++;
        }
        else if (self->elements[i] < other->elements[idx2]){//self[i] < other[idx2].
            removeSet(self, self->elements[i]);//delete self[i]
            i++;//increment i
        }
        else if (self->elements[i] > other->elements[idx2]){//self [i]> other[idx2]
            idx2++;//increment idx2
        }
        //if other ends earlier, needs to erase everything left over.
    }
    if (leftover == true){
        int h = n-(i+1); //how many is left over
        self->len = self->len-h;
        //realloc(self,sizeof(int)*(self->len)); //realloc(subtract however many is left over.)
    }
}

/* remove all elements from self that are also elements of other */
void subtractFromSet(Set* self, const Set* other) {
    int n = self->len;
    int n2 = other->len;
    int idx2, i;
    idx2 = i = 0;

    while(i<n){//if self ends earlier, break out of the loop
        if (idx2 == 99){
            printf("99");
        }
        if(idx2 == n2){break;} // gone through all self.
        if(self->elements[i] == other->elements[idx2]){//same, increment both i++, idx2++;
            removeSet(self, self->elements[i]);//delete self[i]
            idx2++;
        }
        else if (self->elements[i] < other->elements[idx2]){//self[i] < other[idx2].

            i++;//increment i
        }
        else if (self->elements[i] > other->elements[idx2]){//self [i]> other[idx2]
            idx2++;//increment idx2
        }
    }


}

/* add all elements of other to self (obviously, without creating duplicate elements) */
void unionInSet(Set* self, const Set* other) {
    int n = self->len;
    int n2 = other->len;
    int idx2, i;
    idx2 = i = 0;

    while(i<n){//if self ends earlier, break out of the love
        if(idx2 == n2){break;} // gone through all self.
        if(self->elements[i] == other->elements[idx2]){//same, increment both i++, idx2++;
            i++; idx2++;
        }
        else if (self->elements[i] < other->elements[idx2]){//self[i] < other[idx2].
            insertSet(self, other->elements[idx2]);//insert

            i++;//increment i
        }
        else if (self->elements[i] > other->elements[idx2]){//self [i]> other[idx2]
            idx2++;//increment idx2
        }
    }
}
