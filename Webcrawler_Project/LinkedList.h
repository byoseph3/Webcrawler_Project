#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct Linked_List_Node {
    void* data; // pointer to the data that we want to store (probably a string that represents the urls)
    struct Linked_List_Node* next; // next pointer
} ll_node;

void setNext(ll_node* self, ll_node* nextNode);

#endif // LINKEDLIST_H_INCLUDED
