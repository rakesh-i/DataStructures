#include<iostream>
#include<math.h>
#include<ctype.h>
#include<cstring>
#include <cfloat>
using namespace std;

int main()
{
    char *a;
    a = (char*)malloc(6);
    strcpy(a, "hello");
    cout<<a<<endl;
    char *b;
    b = (char*)realloc(a, 7);
    strcpy(b, "rakesh");
    cout<<b;
    free(b); //ptr a and b are pointing to the same address. 
             //Happens when system extends the memory allocated
}
