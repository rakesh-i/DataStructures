#include<iostream>
#include<cstring>
#include<math.h>
#include<cfloat>

struct Node{
    int data;
    Node *prev;
    Node *next;
};

void insert(Node**, int, int);
void print(Node **);
void del(Node**, int n);
void reverse(Node**, Node*);
Node* lastNode(Node**);

int main()
{
    Node *head = NULL;
    insert(&head, 5, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 2);
    //print(&head);
    del(&head, 1);
    //print(&head);
    del(&head, 1);
    //print(&head);
    del(&head, 1);
    //print(&head);
    //del(&head, 1);
    reverse(&head, head);
    Node *last = lastNode(&head);
    printf("last node value: %d\n", last);
    print(&head);

}

void insert(Node **head, int a, int n){
    Node *temp1 = new Node();
    temp1->data = a;
    temp1->next = NULL;
    temp1->prev = NULL;
    if(n==1){
        if(*head==NULL){
            *head = temp1;
            return;
        }
        temp1->next = *head;
        (*head)->prev = temp1;
        *head = temp1;
        return;
    }
    Node *temp2 = *head;
    for(int i=0; i<n-2; i++){
        temp2 = temp2->next;
    }
    if(temp2->next == NULL){
        temp2->next = temp1;
        temp1->prev = temp2;
        return;
    }
    Node *temp3 = temp2->next;
    temp1->next = temp3;
    temp3->prev = temp1;
    temp2->next = temp1;
    temp1->prev = temp2;
}

void print(Node **head){
    Node *temp = *head;
    if(*head==NULL){
        printf("The list is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse(Node **head, Node *p){
    if(*head == NULL){
        printf("the list is empty\n");
        return;
    }
    if(p->next==NULL){
        *head = p;
        return;
    }
    reverse(head, p->next);
    Node *q = p->next;
    q->next = p;
    p->prev = p->next;
    p->next = NULL;
}

void del(Node **head, int n){
    Node *temp1 = *head;
    if(*head == NULL){
        printf("The list is empty\n");
        return;
    }
    if(n==1){
        *head = temp1->next;
        free(temp1);
        return;
    }
    for(int i=0; i<n-2; i++){
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    if(temp2->next==NULL){
        temp1->next = NULL;
        free(temp2);
        return;
    }
    Node *temp3 = temp2->next;
    temp1->next = temp3;
    temp3->prev = temp1;
    free(temp2);
}

Node *lastNode(Node **head){
    static Node *temp = *head;
    if(*head == NULL){
        return(NULL);
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return(temp);
}
