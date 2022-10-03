#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// linke list implementation

struct node {
    float stockVal;
    struct node *next;
};

//struct node list[52];
struct node *head = NULL;
struct node *current = NULL;


// display the list
void printList () {
    struct node *ptr = head;

    printf("\n[ ");

    // start from the top
    while (ptr != NULL){
        printf("(%.2f)", ptr->stockVal);
        ptr = ptr->next;
    };

    printf(" ]\n");
};

// insert link at the first location
void insertFirst(float value) {

    // create a link 
    struct node *link = (struct node*) malloc(sizeof(struct node));

    link->stockVal = value;

    // point to old first node
    link->next = head;

    // point first to new first node
    head = link;
};

// get list length
int length() {
    int length = 0;
    //struct node *curr;

    for(current = head; current != NULL; current = current->next){
        // printf("%.2f, ", current->stockVal);
        length++;
    };

    return length;
};

// iterative approach to find the maximum value
float getMaxWL(struct node *node){

    float listMax = 0.00;

    while (node != NULL){
        if(listMax < (node->stockVal)) listMax = node->stockVal;
        node = node->next;
    };

    return listMax;
};

// recursive approach to finding the maximum
float getMaxRC(float listMax, struct node *node) {

    if(node == NULL) {
        return listMax;
    }
    else if (listMax < (node->stockVal)){
        listMax = node->stockVal;
    };

    return getMaxRC(listMax, node->next);
};


// main program
int main() {

    float x;
    // populate the list with 52 values representing the stock prices
    for (int i = 0; i < 52; i++){
        x = ((float)rand()/RAND_MAX + 3.5) * 5.3;
        insertFirst(x);
    };

    printf("\n\nHere is the List: \n");

    printList();
    printf("\nList Length = %d\n", length());
    printf("\nList Max with While Loop = %.2f\n", getMaxWL(head));
    printf("\nList Max Recursively = %.2f\n", getMaxRC(0.0, head));
    printf("\n");

    return 0;
};