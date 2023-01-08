#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void push(Node **head, int a){
    Node *temp1 = new Node();
    temp1->data = a;
    temp1->next = NULL;
    temp1->prev = NULL;
    if(*head == NULL){
        *head = temp1;
        return;
    }
    Node *temp2 = *head;
    temp1->next = temp2;
    temp2->prev = temp1;
    *head = temp1;
}

void pop(Node **head){
    Node *temp1 = *head;
    if(*head==NULL){
        cout<<"empty"<<endl;
        return;
    }
    Node *temp2 = temp1->next;
    temp2->prev = NULL;
    temp1->next = NULL;
    *head = temp2;
}

void enqueue(Node **head, Node **tail, int a){
    Node *temp1 = new Node();
    temp1->data = a;
    temp1->next = NULL;
    temp1->prev = NULL;
    if(*head == NULL){
        *head = temp1;
        *tail = temp1;
        return;
    }
    Node *temp2 = *tail;
    temp1->prev = *tail;
    temp2->next = temp1;
    *tail = temp1;
}

void dequeue(Node **head, Node **tail){
    Node *temp1 = *head;
    if(*head==NULL){
        cout<<"empty"<<endl;
        return;
    }
    Node *temp2 = temp1->next;
    temp2->prev = NULL;
    temp1->next = NULL;
    *head = temp2;
}

void insert(Node **head, int a, int n){
    Node *temp1 = new Node();
    Node *temp2 = *head;
    temp1->data = a;
    temp1->next = NULL;
    temp1->prev = NULL;
    if(n==1){
        if(*head==NULL){
            *head = temp1;
            return;
        }
        temp1->next = temp2;
        temp2->prev = temp1;
        *head = temp1;
        return;
    }
    for(int i=0; i<n-2; i++){
        temp2 = temp2->next;
    }
    Node *temp3 = temp2->next;
    if(temp3==NULL){
        temp2->next = temp1;
        temp1->prev = temp2;
        return;
    }
    temp1->next = temp3;
    temp1->prev = temp2;
    temp2->next = temp1;
    temp3->prev = temp1;
}

void del(Node **head, int n){
    Node *temp1 = *head;
    Node *temp2 = temp1->next;
    if(n==1){
        if(temp1 == NULL){
            cout<<"empty"<<endl;
            return;
        }
        temp1->next = NULL;
        temp2->prev = NULL;
        *head = temp2;
        return;
    }
    for(int i=0; i<n-2; i++){
        temp1 = temp1->next;
    }
    if(temp2->next==NULL){
        temp1->next = NULL;
        temp2->prev = NULL;
        free(temp2);
        return;
    }
    Node *temp3 = temp2->next;
    temp1->next =temp3;
    temp3->prev =temp1;
    temp2->prev =NULL;
    temp2->next =NULL;

}

void reverse(Node **head, Node* p){
    if(p->next == NULL){
        *head = p;
        return;
    }
    reverse(head, p->next);
    Node *q = p->next;
    p->next = p->prev;
    q->next = p;
    p->next =NULL;
}

void print(Node **head){
    Node *temp =*head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    /*(insert(&head, 5, 1);
    insert(&head, 4, 1);
    insert(&head, 3, 1);
    insert(&head, 2, 1);
    insert(&head, 0, 1);
    insert(&head, 6, 6);
    insert(&head, 1, 2);
    reverse(&head, head);*/
    //push(&head, 1);
    //push(&head, 2);
    //push(&head, 3);
    //push(&head, 4);
    //push(&head, 5);
    //pop(&head);
    enqueue(&head, &tail, 5);
    enqueue(&head, &tail, 4);
    enqueue(&head, &tail, 3);
    enqueue(&head, &tail, 2);
    enqueue(&head, &tail, 1);
    dequeue(&head, &tail);
    print(&head);
    return 0;
}