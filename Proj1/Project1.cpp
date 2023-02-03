// SuperStrings <Project1.cpp>
// EE 312 Project 1 submission by
// Hyokwon Chung
// hc27426
// Slip days used: <0>
// Summer 2022


#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types


//void makeDictionary(char* gotString, int* array) {
//    int i = 0;
//    int idx = 0;
//
//    int spaceFlag = 1;
//
//    while (gotString[i] != NULL) {
//        char content = gotString[i];
//        if (content == ' ') {
//            if (spaceFlag == 1) {
//                i++;
//            } else {
//                spaceFlag = 1;
//
//                i++;
//            }
//        } else if (content == '\n') {
//            i++;
//        } else if (((content > 'a') && (content < 'z')) || (content > 'A') && (content < 'Z')) {
//            if(spaceFlag == 1){
//                *(array+idx) = &gotString[i];
//                idx++;
//                spaceFlag == 0;
//            }
//            else{
//                array[idx] = content;
//            }
//        }
//    }
//}


void cmp(char *temp, char *word) {
    //if the dictionary hits null first, print out the word
    int idx1, idx2, flag, i;
    char tempHolder [50];
    char wordHolder [50];
    idx1 = idx2 = flag = i = 0;

    for (i = 0; temp[i] != '\0'; ++i) {
        if (temp[i] >= 'A' && temp[i] <= 'Z'){
            tempHolder[i] = temp[i] - 32;
        }
        else{
            tempHolder[i] = temp[i];
        }
    }
    tempHolder[i] = '\0';

    for (i = 0; word[i] != '\0'; ++i) {
        if (word[i] >= 'A' && word[i] <= 'Z'){
            wordHolder[i] = word[i] - 32;
        }
        else{
            wordHolder[i] = word[i];
        }
    }
    wordHolder[i] = '\0';

    while (temp[idx1] != '\0'){

        if (temp[idx1] == word[idx2]){
            idx2++;
        }
        if (word[idx2] == '\0'){
            flag = 1;
            break;
        }
        idx1++;

    }
    if (flag == 1){
        printf("%s\n", temp);
    }
}

void lookIntoCand(char* candidate, char *word, int second) {
    //go through each candidate word until null
    int i1 = 0;
    int i11 = 0;
    char temp [50];
    int spflag = 1;
    while(candidate[i1] != '\0') {
        if (((candidate[i1] == ' ') || (candidate[i1] == '\n') || (candidate[i1] == '\t')) && spflag == 0) {
            if (second == 0) {
                spflag = 1;
                temp[i11] = '\0';
                cmp(temp, word);
            }
            else {
                second = 0;
            }//set space flag
        }
        //after space and if it hits a letter, save in temp until next space
        else if ((candidate[i1] >= 'a' && candidate[i1] <= 'z') || (candidate[i1] >= 'A' && candidate[i1] <= 'Z')) {
            if (spflag == 1) { i11 = 0; }//first time encountering a word i11 = 0;
            temp[i11] = candidate[i1];
            i11++;
            spflag = 0;
        }
        i1++;
    }
    if ((candidate[i1] == '\0') && (spflag == 0)) {
        temp[i11] = '\0';
        cmp(temp, word); //set space flag
    }
}
void parseWord(char* target, char* candidate, int first, int second) {
    int i1 = 0;
    int i11 = 0;
    char word[50];
    int spflag = 1;
    while (target[i1] != '\0') {
        if (((target[i1] == ' ') || (target[i1] == '\n') || (target[i1] == '\t')) && spflag == 0) {
            if (first == 0) {
                spflag = 1;
                word[i11] = '\0';
                lookIntoCand(candidate, word, second);
            } else {
                first = 0;
            }
        } //set space flag
            //after space and if it hits a letter, save in word until next space
        else if ((target[i1] >= 'a' && target[i1] <= 'z') || (target[i1] >= 'A' && target[i1] <= 'Z')) {
            if (spflag == 1) { i11 = 0; }//first time encountering a word i11 = 0;
            word[i11] = target[i1];
            i11++;
            spflag = 0;
        }
        i1++;
    }
    if ((target[i1] == '\0') && (spflag == 0) ){
        word[i11] = '\0';
        lookIntoCand(candidate, word, second);
    }
}
/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/

void printSuperStrings(char targets [], char candidates []) {
    int first, second;
    first = second = 0;
    parseWord(targets, candidates, first, second);    //parseword(targets, arrptr);
    //char test [] = {'h', 'e', ' ', 'l', 'l', ' ', 'o', '\0'};
    //lookIntoCand(test ,candidates);
    }