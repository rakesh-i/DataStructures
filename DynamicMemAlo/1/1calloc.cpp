#include<iostream>
#include<math.h>
#include<ctype.h>
#include<cstring>
#include <cfloat>
using namespace std;

int main()
{
    int *p;
    int size;
    cout<<"Enter the size of array\n";
    cin>>size;
    p = (int*)calloc(size, sizeof(int));
    if(p==NULL){
        cout<<"Insufficient memory\n";
        exit(1);
    }
    cout<<"Enter the elements\n";
    for(int i=0; i<size; i++){
        cin>>p[i];
    }
    cout<<"The elements are: ";
    for(int j=0; j<size; j++){
        cout<<p[j]<<" ";
    }
    cout<<endl;
}
