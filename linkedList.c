/*
 Implementation Reference:
 https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// linke list implementation

struct element {
    float stockVal;
    struct element *next;
};


struct element *head = NULL;
struct element *current = NULL;


// display the list
void printList () {
    struct element *ptr = head;

    printf("\n[ \n");

    // start from the top
    while (ptr != NULL){
        printf("(%.2f)", ptr->stockVal);
        ptr = ptr->next;
    };

    printf(" ]");
};

// insert link at the first location
void insertFirst(float value) {

    // create a link 
    struct element *link = (struct element*) malloc(sizeof(struct element));

    link->stockVal = value;

    // point to old first element
    link->next = head;

    // point first to new first element
    head = link;
};

// get list length
int length() {
    int length = 0;
    struct element *current;

    for(current = head; current != NULL; current = current->next){
        length++;
    };

    return length;
};

float getMax(){

    struct element *ptr = head;
    float listMax = 0.00;

    while (ptr != NULL){
        if(listMax < (ptr->stockVal)) listMax = ptr->stockVal;
        ptr = ptr->next;
    };

    return listMax;
};


// main program
void main() {

    float x;
    
    for (int i = 0; i < 52; i++){
        x = ((float)rand()/RAND_MAX + 3.5) * 5.3;
        //printf("%.2f, ", x);
        insertFirst(x);
    };

    printf("\n\nHere is the List: \n");

   printList();
   printf("\nList Length = %d\n", length());
   printf("List Max = %.2f\n", getMax());
   printf("\n");
};