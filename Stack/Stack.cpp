#include<iostream>
using namespace std;

class Stack{
    public:
    Stack(int max){
        arr=new int[max];
        cap=max;
    }
    int *arr,top=-1,cap;
    void push(int n){
        if(top>=cap-1)
            cout<<"Stack overflow:\n";
        else
            arr[++top]=n;
    }
    int pop(){
        if(top<0){
            cout<<"Stack Underflow\n";
            return -1;
        }
        else
            return arr[top--];
    }
    void peek(){
        if(top<0)
            cout<<"Stack underflow\n";
        else       
        cout<<"The top of stack is:"<<arr[top]<<endl;
    }
    int capacity(){
        return cap;
    }
    int size(){
        return top+1;
    }
    void isEmpty(){
        if(top<0)
            cout<<"Stack is empty\n";
        else
            cout<<"Stack is not empty\n";
    }
    void isFull(){
        if(top==cap-1)
            cout<<"Stack is full\n";
        else
            cout<<"Stack is not full\n";
    }
};

int main(){
    int max,c,d;
    char ch;
    cout<<"Enter the size of the stack you want to create:";
    cin>>max;
    Stack a(max);
    label:
    cout<<"OPERATIONS:\n1.push\n2.pop\n3.peek\n4.size\n5.capacity\n6.Check Empty\n7.Check Full\nEnter the operation choice:";
    cin>>c;
    switch(c){
        case 1:
        cout<<"Enter value:";
        cin>>d;
        a.push(d);
        break;

        case 2:
        cout<<"The popped element:"<<a.pop()<<endl;
        break;
        
        case 3:
        a.peek();
        break;
        
        case 4:
        cout<<"SIZE:"<<a.size()<<endl;
        break;
        
        case 5:
        cout<<"CAPACITY:"<<a.capacity()<<endl;
        break;

        case 6:
        a.isEmpty();
        break;

        case 7:
        a.isFull();
        break;
        
        default:
        cout<<"Response invalid:\n";  
    }
    cout<<"Do you want to try again(y/n):";
    cin>>ch;
    if(ch=='y')
        goto label;
    return 0;
}