/*  Name:Xueyu Wang
 *  USC NetID: 2670589054
 *  CS 455 Fall 2019
 *
 *  See ecListFuncs.h for specification of each function.
 */


// for NULL
#include <cstdlib>

// in case you want to use assert statements
#include <cassert>

#include "ecListFuncs.h"

using namespace std;


void longestRun(ListType list, int & maxRunVal, int & maxRunLen) {
   Node *p = list;
   maxRunLen = 0;
   int currentVal = p->data;
   int count = 0;
   while (p != NULL) {
      if (p->data == currentVal) {
         count++;
         p = p->next;
         if (count > maxRunLen) {
            maxRunLen = count;
            maxRunVal = currentVal;
         }
      }
      else {
         count = 1;
         currentVal = p->data;
         p = p->next;
      }
   }
}


void removeMultiplesOf3(ListType & list) {
   Node *p = list;
   Node *former = NULL;
   while (p != NULL) {
      if ((p->data) % 3 == 0) {
         if (former != NULL) {
            former->next = p->next;
            p = p->next;
         }
         else {
            list = list->next;
            p = p->next;
         }
      }
      else {
         former = p;
         p = p->next;
      }
   }
}


void insertMiddle(ListType & list, int midVal) {
   if (list == NULL||list->next == NULL) {
      list = new Node(midVal,list);
      return;
   }
   Node *p = list;
   Node *q = list->next;
   Node *current = new Node(midVal);
   while (q->next != NULL && q->next->next != NULL) {
      q = q->next->next;
      p = p->next;
   }
   current->next = p->next;
   p->next = current;
}


ListType merge(ListType list1, ListType list2) {
   if (list1 == NULL) {
      return list2;
   }
   else if (list2 == NULL) {
      return list1;
   }
   if (list1->data < list2->data) {
      list1->next = merge(list1->next, list2);
      return list1;
   }
   else if(list1->data > list2->data) {
      list2->next = merge(list1, list2->next);
      return list2;
   }
   else {
      list1->next = merge(list1->next, list2->next);
      return list1;
   }
}



