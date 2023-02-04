/*
 * Copy the contents of header.txt (filled out) and paste here
 */

#include <assert.h>     //to provide assert()
#include <stdbool.h>    //to provide "bool" datatype (true or false)
#include <stdlib.h>     //dynamic allocation functions
#include <stdint.h>     //integer datatype with precise explicit width
#include <string.h>     //utility functions for string management
#include "UTString.h"

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(const UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    UTString* utstring = (UTString*)malloc(sizeof(UTString));

    utstring->length = strlen(src);
    utstring->capacity = strlen(src);
    utstring->string = (char*)malloc(strlen(src)+5);
    strcpy(utstring->string, src);

    CHECK(utstring) = SIGNATURE;

    return utstring;
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    assert(isOurs(s));
    int ret = 0;
    ret = strlen(s->string);

    return ret;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) {
    if (strlen(suffix) >= (s->capacity) - (s->length)) {
        strncat(s->string, suffix, (s->capacity) - (s->length));//s -> string
        s->length += (s->capacity) - (strlen(suffix));
    }
    else {
        strncat(s->string, suffix, (s->capacity) - (s->length));//s -> string
        s->length += (strlen(suffix));
    }
    return s;
}

/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    //assert(isOurs(dst));

    return NULL;
}

/*
 * Free all memory associated with the given UTString.
 */
void utstrfree(UTString* self) {
    free(self);
}

/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    assert(isOurs(s));
    if (new_capacity > s ->capacity) {
        UTString *temp = (UTString *) malloc(sizeof(UTString)); //create new UTSTring;
        temp->capacity = new_capacity;
        temp->string = (char*)malloc(temp->capacity+5);
        strcpy(temp -> string, s->string);
        temp->length = (strlen(temp->string));
        free(s);
        return temp;
    }//copy string over;
    return s;
}
