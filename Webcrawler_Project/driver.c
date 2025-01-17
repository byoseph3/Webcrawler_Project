#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

typedef struct Linked_List_Node {
    void* data;
    struct Linked_List_Node* next;
} ll_node;

static ll_node* head;
static ll_node* tail;

void generate_url_node(char* url) {
    if (!head) {
        head = (ll_node*) malloc(sizeof(ll_node));
        head->data = malloc(strlen(url)+1);
        strcpy(head->data, url);
        tail = head;
    } else {
        ll_node* next = (ll_node*) malloc(sizeof(ll_node));
        next->data = malloc(strlen(url)+1);
        strcpy(next->data, url);
        tail->next = next;
        tail = tail->next;
    }
}

int generate_url_ll() {
    FILE *fp;
    fp = fopen("seedlist.txt", "r");
    char line[256];

    if (!fp) {
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        generate_url_node(line);
    }

    return 0;
}

void ut_print_url_ll() {

    generate_url_ll();
    ll_node* curr = (ll_node*) malloc(sizeof(ll_node));
    curr = head;
    while (curr) {
        printf("%s\n", curr->data);
        curr = curr->next;
    }

}

void main() {
    ut_print_url_ll();
    return;
}
