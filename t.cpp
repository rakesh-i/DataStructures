#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **head, int a){
    Node *temp1 = new Node();
    temp1->data = a;
    temp1->next = *head;
    *head = temp1;
}

void pop(Node **head){
    Node *temp1 = *head;
    if(*head==NULL){
        cout<<"empty"<<endl;
        return;
    }
    *head = temp1->next;
    temp1->next = NULL;
}

void insert(Node **head, int a, int n){
    Node *temp1 = new Node();
    temp1->data = a;
    if(n == 1){
        temp1->next = *head;
        *head = temp1;
        return;
    }
    Node *temp2 = *head;
    for(int i=0; i<n-2; i++){
        temp2 = temp2->next;
    }
    if(temp2->next==NULL){
        temp2->next = temp1;
        return;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void del(Node **head, int n){
    Node *temp1 = *head;
    if(n==1){
        if(*head == NULL){
            cout<<"empty"<<endl;
            return;
        }
        *head = temp1->next;
        temp1->next = NULL;
        return;
    }
    for(int i = 0; i<n-2; i++){
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = NULL;
}

void reverse(Node **head, Node *p){
    if(p->next == NULL){
        *head = p;
        return;
    }
    reverse(head, p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

void print(Node **head){
    Node *temp = *head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main(){
    Node *head = NULL;
    /*insert(&head, 4, 1);
    insert(&head, 3, 1);
    insert(&head, 2, 1);
    insert(&head, 1, 1);
    insert(&head, 6, 3);*/
    //del(&head, 3);
    //reverse(&head, head);
    push(&head, 5);
    pop(&head);
    pop(&head);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    print(&head);
    return 0;
}