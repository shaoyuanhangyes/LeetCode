#include <iostream>

using namespace std;

int mergearray(int* a,int La,int* b,int Lb){
    int i=2*La-1;
    int p1=La-1;
    int p2=Lb-1;
    while(p1>=0&&p2>=0){
        if(a[p1]<b[p2]) a[i--]=b[p2--];
        else a[i--]=a[p1--];
    }
    while(p2>=0) a[i--]=b[p2--];
    return a[10/2];
}

int main(){
    int a[]={11,13,15,17,19,0,0,0,0,0};
    int b[]={2,4,6,8,10};
    cout<<mergearray(a,5,b,5);
}