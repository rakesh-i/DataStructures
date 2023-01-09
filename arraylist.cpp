#include<iostream>
using namespace std;
#define MAX_SIZE 100
int head = -1;

void insert(int * array, int n){
    if(head == -1){
        array[0] = n;
        head++;
    }
    else{
        array[head+1] = n;
        head++;
    }
}
void inm(int * array, int n, int m){
  
        for(int i=head;i>=m; i--){
            array[i+1] = array[i];
        }
        array[m] = n;
        head++;
    
}

void del(int* array, int n){
    if (head==-1){
        cout<<"List is empty"<<endl;
    }
    else{
        for(int i=n;i<head;i++){
            array[i] = array[i+1];
        } 
        head--;
    }
}

void reverse(int *array){
    int h = head;
    //cout<<array[h];
    int t = 0;

    for(int i=0;i<=head/2; i++){
        int temp = array[h];
        array[h] = array[t];
        array[t] = temp;
        t++;
        h--;
    }
}

void print(int * array){
    for(int i=0;i<head+1;i++){
        cout<<array[i];
        cout<<" ";
    }
    cout<<endl;
}

int main(){
    int array[MAX_SIZE];
    insert(array, 1);
    insert(array, 2);
    insert(array, 3);
    insert(array, 5);
    insert(array, 6);
    insert(array, 7);
    //inm(array, 4, 3);
    //del(array);
    //del(array);
    //del(array);
    //del(array);
    //del(array, 5);
    //cout<<head;
    reverse(array);
    print(array);

}
