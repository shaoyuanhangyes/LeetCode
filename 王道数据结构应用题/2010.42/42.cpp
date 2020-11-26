#include <iostream>

using namespace std;

void reverse(int* r,int start,int end){
    for(int i=0;i<(end-start+1)/2;++i){
        int temp=r[i+start];
        r[i+start]=r[end-i];
        r[end-i]=temp;
    }
}

int main(){
    int R[5]={1,2,3,4,5};
    int n=5;
    int p;
    cout<<"please enter distance:p=";
    cin>>p;
    reverse(R,0,p-1);
    reverse(R,p,n-1);
    reverse(R,0,n-1);
    for(int i=0;i<5;++i) cout<<R[i]<<" ";
    return 1;
}