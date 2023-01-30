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
    cout<<"Enter the size of the array\n";
    cin>>size;
    if((p = (int*)malloc(sizeof(int)*size))==NULL){
        cout<<"Space is not available\n";
        exit(1);
    }
    cout<<"Enter the elements\n";
    for(int i=0; i<size;i++){
        cin>>p[i];
    }
    cout<<"The elements are :\n";
    for(int j=0; j<size; j++){
        cout<<p[j]<<" ";
    }
    cout<<endl;
}
