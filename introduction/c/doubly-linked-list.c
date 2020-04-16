#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct node {
   char data[100];

   struct node *next;
   struct node *prev;
};

struct node *head = NULL;
struct node *last = NULL;
// struct node *current = NULL;

// Write functions to find from it. Test them.

bool isEmpty() {
   return head == NULL;
}

void insertFirst(char data[100]) {

   struct node *link = malloc(sizeof(struct node));
   strncpy(link->data, data, 100);

   if(isEmpty()) {
      last = link;
   } else {
      head->prev = link;
   }

   link->next = head;
   head = link;
}

void insertLast(char data[100]) {

   struct node *link = malloc(sizeof(struct node));
   strncpy(link->data, data, 100);

   if(isEmpty()) {
      last = link;
   } else {
      last->next = link;
      link->prev = last;
   }

   last = link;
}

struct node* deleteFirst() {

   struct node *tempLink = head;

   if(head->next == NULL){
      last = NULL;
   } else {
      head->next->prev = NULL;
   }

   head = head->next;
   return tempLink;
}

struct node* deleteLast() {

   struct node *tempLink = last;

   if(head->next == NULL) {
      head = NULL;
   } else {
      last->prev->next = NULL;
   }

   last = last->prev;
   return tempLink;
}

struct node* delete(char data[100]) {
   struct node* current = head;
   struct node* previous = NULL;

   if(head == NULL) {
      return NULL;
   }

   while(strncmp(current->data, data, 100) != 0) {
      if(current->next == NULL) {
         return NULL;
      } else {
         previous = current;
         current = current->next;
      }
   }

   if(current == head) {
      head = head->next;
   } else {
      current->prev->next = current->next;
   }

   if(current == last) {
      last = current->prev;
   } else {
      current->next->prev = current->prev;
   }

   return current;
}

struct node* find(char data[100]) {
  struct node* current = head;

  while(strncmp(current->data, data, 100) != 0) {
    if (current == last) {
      return NULL;
    } else {
      current = current->next;
    }
  }

  printf("(%s) ",current->data);
  return current;
}

void displayForward() {

   struct node *ptr = head;
   printf("\n[ ");

   while(ptr != NULL) {
      printf("(%s) ",ptr->data);
      ptr = ptr->next;
   }

   printf(" ]");
}

int main() {
   insertFirst("10");
   insertFirst("20");
   insertFirst("30");
   insertFirst("1");
   insertFirst("40");
   insertLast("56");

   printf("\nList (First to Last): ");
   displayForward();

   printf("\nList , after deleting first record: ");
   deleteFirst();
   displayForward();

   printf("\nList , after deleting last record: ");
   deleteLast();
   displayForward();

   printf("\nList , find data with 1: ");
   find("1");
   // displayForward();

   printf("\nList  , after delete data(20) : ");
   delete("20");
   displayForward();
}
