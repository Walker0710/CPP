#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
typedef struct Node {
    int userID;
    char name[50];
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int userID, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->userID = userID;
    strcpy(newNode->name, name);
    newNode->next = newNode->prev = newNode; // Circular reference
    return newNode;
}

// Function to insert node y as a successor to node x
Node* insert(Node* x, Node* y) {
    
    if (!x) 
    return y; // If x is null, return y as the new list
    
    Node* xNext = x->next; // Store the next node of x
    x->next = y;
    y->prev = x;
    y->next = xNext;
    xNext->prev = y;
    
    return y;
}

// Function to delete node x and return its successor
Node* delete(Node* x) {
    
    if (!x) 
    return NULL; // If x is null, return null
    
    if (x->next == x) { // Only one node in the list
        free(x);
        return NULL;
    }
    
    Node* xPrev = x->prev;
    Node* xNext = x->next;
    xPrev->next = xNext;
    xNext->prev = xPrev;
    free(x);
    
    return xNext;
}

// Function to print all elements starting from node x
void printList(Node* x) {
    if (!x) 
    return; // If x is null, return
    
    Node* start = x;
    
    do {
        printf("UserID: %d, Name: %s\n", x->userID, x->name);
        x = x->next;
    } 

    while (x != start);
}

// Function to merge two circular lists
Node* merge(Node* x, Node* y) {
    if (!x) return y; // If list x is empty, return list y
    if (!y) return x; // If list y is empty, return list x

    Node* xPrev = x->prev;
    Node* yPrev = y->prev;

    xPrev->next = y; // Link end of x to start of y
    y->prev = xPrev;

    yPrev->next = x; // Link end of y to start of x
    x->prev = yPrev;

    return x; // Return pointer to any node in the merged list
}


int main() {

    Node* list1 = createNode(1, "Alice");
    Node* list2 = createNode(2, "Bob");

    // Add more nodes to list 1
    Node* node3 = createNode(3, "Charlie");
    Node* node4 = createNode(4, "David");
    insert(list1, node3);
    insert(node3, node4);

    // Print list 1
    printf("List 1:\n");
    printList(list1);

    // Create another list and add nodes
    Node* list3 = createNode(5, "Eve");
    Node* list4 = createNode(6, "Frank");
    insert(list3, list4);

    // Print list 2
    printf("List 2:\n");
    printList(list3);

    // Merge the two lists
    Node* mergedList = merge(list1, list3);
    printf("Merged List:\n");
    printList(mergedList);

    // Delete a node from the merged list
    Node* newHead = delete(node3);
    printf("List after deleting Charlie:\n");
    printList(newHead);

    return 0;
}
