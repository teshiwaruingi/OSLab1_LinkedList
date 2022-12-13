// list/list.c
//
// Implementation for linked list.
//
// Teshi Waruingi

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

/*

Allocate memory for a new linked list and initialize its head to NULL.
*/
list_t *list_alloc() {
// Allocate memory for the list
list_t *linkedList = (list_t *)malloc(sizeof(list_t));
// Initialize the head of the list to NULL
linkedList->head = NULL;

// Return the newly allocated and initialized list
return linkedList;
}

/*

Free the memory associated with a linked list.
This function frees the memory allocated for each node in the list, as well
as the memory allocated for the list itself. After this function is called,
the given linked list should not be used.
@param l
The linked list to free.
*/
void list_free(list_t *l) {
// Store a pointer to the head of the list
node_t *head = l->head;
// Keep track of the next node in the list as we traverse it
node_t *temp = NULL;

// Loop through each node in the list, freeing its memory
while (head != NULL) {
temp = head->next;
free(head);
head = temp;
}

// Free the memory allocated for the list itself
free(l);
}

/*

Print the values stored in a linked list.
This function prints the values stored in a linked list, starting with the
head of the list and continuing until the end of the list is reached.
@param l
The linked list to print.
*/
void list_print(list_t *l) {
// Store a pointer to the head of the list
node_t *head = l->head;
// Loop through each node in the list, printing its value
while (head != NULL) {
printf("%d, ", head->value);
head = head->next;
}

// Print a newline after all the values have been printed
printf("\n");
}

/*

Get the length of a linked list.
This function returns the number of nodes in the given linked list.
@param l
The linked list to get the length of.
@return
The length of the linked list.
*/
int list_length(list_t *l) {
// Initialize the length of the list to 0
int length = 0;
// Store a pointer to the head of the list
node_t *head = l->head;

// Loop through each node in the list, incrementing the length
while (head != NULL) {
length += 1;
head = head->next;
}

// Return the length of the list
return length;
}

void list_add_to_back(list_t *l, elem value) {
  // Get a pointer to the head of the list
  node_t * head = l->head;

  // Create a new node
  node_t * new_node = (node_t *)malloc(sizeof(node_t *));
  new_node -> value = value;
  new_node->next = NULL;

  // If the list is empty, set the head to the new node
  if (head == NULL) {
    l->head = new_node;
  }
  else {
    // Otherwise, find the last node in the list
    while (head->next != NULL) {
      head = head->next;
    }

    // Append the new node to the end of the list
    head->next = new_node;
  }
}

void list_add_to_front(list_t *l, elem value) {
  // Create a new node
  node_t * new_node = (node_t *)malloc(sizeof(node_t *));
  new_node->value = value;

  // Set the next pointer of the new node to the current head of the list
  new_node->next = l->head;

  // Set the head of the list to the new node
  l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
  // If the index is 0, add the element to the front of the list
  if (index == 0 ){
    list_add_to_front(l, value);
  }
  else {
    // Initialize a counter and pointers to the current and previous nodes
    int count = 0;
    node_t * curr = l->head;
    node_t * prev = NULL;

    // Iterate through the list until we reach the specified index
    while (count < index) {
      prev = curr;
      curr = curr->next;
      count += 1;
    }

    // Create a new node
    node_t * new_node = (node_t *)malloc(sizeof(node_t *));
    new_node -> value = value;

    // Set the next pointer of the new node to the current node
    new_node->next = curr;

    // Set the next pointer of the previous node to the new node
    prev->next = new_node;
  }
}


void list_add_at_index(list_t *l, elem value, int index) {
  // If the index is 0, add the element to the front of the list
  if (index == 0 ){
    list_add_to_front(l, value);
  }
  else {
    // Initialize a counter and pointers to the current and previous nodes
    int count = 0;
    node_t * curr = l->head;
    node_t * prev = NULL;

    // Iterate through the list until we reach the specified index
    while (count < index) {
      prev = curr;
      curr = curr->next;
      count += 1;
    }

    // Create a new node
    node_t * new_node = (node_t *)malloc(sizeof(node_t *));
    new_node -> value = value;

    // Set the next pointer of the new node to the current node
    new_node->next = curr;

    // Set the next pointer of the previous node to the new node
    prev->next = new_node;
  }
}

elem list_remove_at_index(list_t *l, int index) { 
   // If the index is 0, remove the element from the front of the list
  if (index == 0 ) {
    return list_remove_from_front(l);
  }
  else {
    // Initialize a counter and pointers to the current and previous nodes
    int count = 0;
    node_t * curr = l->head;
    node_t * prev = NULL;

    // Iterate through the list until we reach the specified index
    while (count < index) {
      prev = curr;
      curr = curr->next;
      count += 1;
    }

    // Set the next pointer of the previous node to the current node's next pointer
    prev->next = curr->next;

    // Save the value of the current node
    elem element = curr->value;

    // Free the memory allocated for the current node
    free(curr);

    // Return the saved value
    return element;
  }
}

// Returns true if the given value is in the list, false otherwise
bool list_is_in(list_t *l, elem value) { 
  // Get a pointer to the head of the list
  node_t * head = l->head;

  // Iterate through the list and check if the value is in any of the nodes
  while (head != NULL) {
    if (head->value == value){
      return true;
    }
    head = head->next;
  }
  return false;
}

// Returns the element at the specified index in the list
elem list_get_elem_at(list_t *l, int index) { 
  // Initialize a counter and a pointer to the head of the list
  int count = 0;
  node_t * head = l->head;

  // Iterate through the list until we reach the specified index or the end of the list
  while (count < index && head != NULL) {
    head = head->next;
    count += 1;
  }

  // If we reached the specified index and the current node is not NULL, return the value of the node
  if (count == index && head != NULL) {
    return head->value;
  }

  // Otherwise, return -1
  return -1; 
}

// Returns the index of the first occurrence of the given value in the list, or -1 if the value is not in the list
int list_get_index_of(list_t *l, elem value) {
  // Initialize a counter and a pointer to the head of the list
  int index = 0;
  node_t * head = l->head;

  // Iterate through the list and check if the value is in any of the nodes
  while (head != NULL) {
    if (head->value == value) {
      // If the value is found, return the index
      return index;
    }
    head = head->next;
    index += 1;
  }

  // If the value is not found, return -1
  return -1;
}
