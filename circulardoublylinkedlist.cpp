#include<iostream>
#include<math.h>
#include<ctype.h>
#include<cstring>
#include <cfloat>

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void insert(Node**, Node**, int, int);
void del(Node**, Node**, int);
void print(Node**);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insert(&head, &tail, 4, 1);
    insert(&head, &tail, 3, 1);
    insert(&head, &tail, 2, 1);
    insert(&head, &tail, 1, 1);
    insert(&head, &tail, 5, 5);
    del(&head, &tail, 1);
    print(&head);
}

void insert(Node **head, Node **tail, int a, int n){
    Node *temp1 = new Node();
    temp1->data = a;
    temp1->next = NULL;
    temp1->prev = NULL;
    if(n==1){
        if((*head==NULL)&&(*tail==NULL)){
            *head = temp1;
            *tail = temp1;
            temp1->next = temp1;
            temp1->prev = temp1;
            // printf("first ");
            // printf("%d %d |%d\n", (*head)->data, (*tail)->data, temp1->data);
            return;
        }
        temp1->next = *head;
        temp1->prev = (*head)->prev;
        (*head)->prev = temp1;
        (*tail)->next = temp1;
        *head = temp1;
        // printf("first? ");
        // printf("%d %d |%d\n", (*head)->data, (*tail)->data, temp1->data);
        return;
    }
    Node *temp2 = *head;
    for(int i=0; i<n-2; i++){
        temp2 = temp2->next;
    }
    Node *temp3 = temp2->next;
    if(temp3==*head){
        *tail = temp1;
    }
    temp1->next = temp3;
    temp3->prev = temp1;
    temp2->next = temp1;
    temp1->prev = temp2;
    // printf("middle ");
    // printf("%d %d |%d\n", (*head)->data, (*tail)->data, temp1->data);
}

void del(Node **head, Node **tail, int n){
    Node *temp1 = *head;
    if(*head == NULL){
        printf("list is empty\n");
        return;
    }
    Node *temp2 = temp1->next;
    if(n==1){
        if(temp2==*head){
            *head == NULL;
            *tail == NULL;
            return;
        }
        temp2->prev = *tail;
        (*tail)->next = temp2;
        *head = temp2;
        free(temp1);
        return;
    }
    for(int i=0; i<n-2;i++){
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    Node *temp3 = temp2->next;
    if(temp3==*head){
        temp1->next = temp3;
        temp3->prev = temp1;
        *tail = temp1;
        free(temp2);
        return;
    }
    temp3->prev = temp1;
    temp1->next = temp3;
    free(temp2);
}

void print(Node **head){
    Node *temp = *head;
    if(*head == NULL){
        printf("list is empty\n");
        return;
    }
    printf("%d ", temp->data);
    temp = temp->next;
    while(temp!=*head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    std::cout<<std::endl;
}
