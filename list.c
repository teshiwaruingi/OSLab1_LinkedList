// list/list.c
//
// Implementation for linked list.
//
// Teshi Waruingi

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t * linkedList = (list_t *)malloc(sizeof(list_t));
  linkedList->head = NULL;
  return linkedList;
  }

void list_free(list_t *l) {
  node_t * head = l->head;
  node_t * temp = NULL;
  while (head != NULL) {
    temp = head->next;
    free(head);
    head = temp;
 }
}

void list_print(list_t *l) {
  node_t * head = l->head;
  while (head != NULL) {
    printf("%d, ", head->value);
    head = head->next;
  }
  printf("\n");
}
int list_length(list_t *l) { 
  int length = 0;
  node_t * head = l->head;
  while (head != NULL) {
    length += 1;
    head = head->next;
  }
  return length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t * head = l->head;
  node_t * new_node = (node_t *)malloc(sizeof(node_t *));
  new_node -> value = value;
  new_node->next = NULL;
  if (head == NULL) {
    l->head = new_node;
  }
  else {
    while (head->next != NULL) {
      head = head->next;
    }
    head->next = new_node;
   }
}
void list_add_to_front(list_t *l, elem value) {
  node_t * new_node = (node_t *)malloc(sizeof(node_t *));
  new_node->value = value;
  new_node->next = l->head;
  l->head = new_node;
}
void list_add_at_index(list_t *l, elem value, int index) {
  if (index == 0 ){
    list_add_to_front(l, value);
  }
  else {
    int count = 0;
    node_t * curr = l->head;
    node_t * prev = NULL;
    while (count < index) {
      prev = curr;
      curr = curr->next;
      count += 1;
    }
    node_t * new_node = (node_t *)malloc(sizeof(node_t *));
    new_node -> value = value;
    new_node->next = curr;
    prev->next = new_node;
  }
}

elem list_remove_from_back(list_t *l) { 
  node_t * head = l->head;
  node_t * prev = NULL;
  while (head->next != NULL) {
    prev = head;
    head = head->next;
}
  elem element = head->value;
  prev->next = NULL;
  free(head);
  return element;
  }

elem list_remove_from_front(list_t *l) { 
  node_t * head = l->head;
  if (head == NULL) {
    return -1;
  }
  elem element = head->value;
  l->head = head->next;
  free(head);
  return element;
  
}
elem list_remove_at_index(list_t *l, int index) { 
   if (index == 0 ) {
    return list_remove_from_front(l);
  }
  else {
    int count = 0;
    node_t * curr = l->head;
    node_t * prev = NULL;
    while (count < index) {
      prev = curr;
      curr = curr->next;
      count += 1;
    }
    prev->next = curr->next;
    elem element = curr->value;
    free(curr);
    return element;
  }
}

bool list_is_in(list_t *l, elem value) { 
  node_t * head = l->head;
  while (head != NULL) {
    if (head->value == value){
      return true;
    }
    head = head->next;
  }
  return false;
}
elem list_get_elem_at(list_t *l, int index) { 
    int count = 0;
    node_t * head = l->head;
    while (count < index && head != NULL) {
      head = head->next;
      count += 1;
    }
  if (count == index && head != NULL) {
    return head->value;
  }
  return -1; 
}
int list_get_index_of(list_t *l, elem value) {
  int index = 0;
  node_t * head = l->head;
  while (head != NULL) {
    if (head->value == value) {
      return index;
    }
    head = head->next;
    index += 1;
  }
  return -1;
}