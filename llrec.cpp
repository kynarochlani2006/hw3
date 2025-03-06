#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  Node* temp = head;
  head = head->next;

  llpivot(head, smaller, larger, pivot);

  if(temp->val <= pivot){
    temp->next = smaller;
    smaller = temp;
  } else if(temp->val > pivot){
    temp->next = larger;
    larger = temp;
  }
}
