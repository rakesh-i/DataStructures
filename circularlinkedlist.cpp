#include<iostream>
#include<math.h>
#include<ctype.h>
#include<cstring>
#include <cfloat>

struct Node{
    int data;
    Node *next;
};

void insert(Node**, Node**, int, int);
void del(Node**, Node**, int);
void print(Node**);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insert(&head, &tail, 2, 1);
    insert(&head, &tail, 1, 1);
    insert(&head, &tail, 3, 3);
    insert(&head, &tail, 4, 4);
    insert(&head, &tail, 5, 5);
    del(&head, &tail, 5);
    print(&head);
}

void insert(Node **head, Node **tail, int a, int n){
    Node *temp1 = new Node();
    temp1->data = a;
    temp1->next = NULL;
    if(n==1){
        if(*head==NULL&&*tail==NULL){
            temp1->next = temp1;
            *head = temp1;
            *tail = temp1;
            return;
        }
        temp1->next = *head;
        *head = temp1;
        (*tail)->next = temp1;
        return;
    }
    Node *temp2 = *head;
    for(int i=0; i<n-2; i++){
        temp2 = temp2->next;
    }
    if(temp2->next==*head){
        temp1->next = *head;
        *tail = temp1;
        temp2->next = temp1;
        return;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print(Node **head){
    Node *temp = *head;
    if(*head==NULL){
        printf("The list is empty\n");
        return;
    }
    printf("%d ", temp->data);
    temp = temp->next;
    while(temp!=*head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void del(Node **head, Node **tail, int n){
    Node *temp1 = *head;
    if(*head==NULL){
        printf("The list is empty\n");
        return;
    }
    Node *temp2 = temp1->next;
    if(n==1){
        (*tail)->next = temp2;
        *head = temp2;
        free(temp1);
        return;
    }
    for(int i=0; i<n-2; i++){
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    Node *temp3 = temp2->next;
    if(temp3==*head){
        temp1->next = *head;
        *tail = temp1;
        free(temp2);
        return;
    }
    temp1->next = temp3;
    free(temp2);
}
