#include<iostream>
#include<math.h>
#include<ctype.h>
#include<cstring>
#include <cfloat>
using namespace std;

int count = 0;

struct Node{
    int data;
    Node *next;
};
Node *tail = new Node();

void insert(Node **head, int a, int n){
    Node *temp1 = new Node();
    temp1->data = a;
    temp1->next = NULL;
    if(n==1){
        temp1->next = *head;
        *head = temp1;
        if(count==0){
            tail = temp1;
        }
        count++;
        return;
    }
    Node *temp2 = *head;
    for(int i=0; i<n-2; i++){
        temp2 = temp2->next;
    }
    if(temp2->next == NULL){
        temp2->next = temp1;
        tail = temp1;
        count++;
        return;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    count++;
}

void del(Node **head, int n){
    Node *temp1 = *head;
    if(n==1){
        if(*head == NULL){
            cout<<"is empty\n";
            return;
        }
        *head = temp1->next;
        free(temp1);
        count--;
        return;
    }
    for(int i=0; i<n-2; i++){
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    Node *temp3 = temp2->next;
    if(temp2->next == NULL){
        tail = temp1;
        temp1->next = NULL;
        free(temp2);
        count--;
        return;
    }
    temp1->next = temp3;
    free(temp2);
    count--;
}

void recurr(Node *p, Node **head){
    if(p->next == NULL){
        tail = *head;
        *head = p;
        return;
    }
    recurr(p->next, head);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

void print(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node *head = NULL;
    insert(&head, 3, 1);
    insert(&head, 2, 1);
    insert(&head, 1, 1);
    insert(&head, 6, 4);
    insert(&head, 5, 4);
    insert(&head, 4, 4);
    del(&head, 5);
    recurr(head, &head);
    print(&head);   
}
