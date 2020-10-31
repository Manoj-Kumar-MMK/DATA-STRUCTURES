#include<iostream>
using namespace std;
#define n 10

class Tree{
    public:
    int arr[n];
    void createFromLevel(){
        int d;
        cout<<"Enter the node in level order:";
        cin>>d;
        int i=0;
        while(d!=-1){
            if(d==0){

                continue;
            }
            else
            {
                arr[i]=d;
                i=i*2+1;
            }
            
        }
    }
}

int main(){
    
    return 0;
}