#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next=NULL;
    Node(int n):data(n){}
};

class Stack{
    public:
    Node *top=NULL;

    void push(int data){
        Node *temp=new Node(data);
        temp->next=top;
        top=temp;
    }

    void peek(){
        if(top==NULL){
            cout<<"Stack underflow\n";
            return;
        }
        else
        {
            cout<<"top element is:"<<top->data<<endl;
        }
    }

    int pop(){
        if(top==NULL){
            cout<<"Stack underflow\n";
            return -1;
        }
        int x=top->data;
        top=top->next;
        return x;
    }

    void isEmpty(){
        if(top==NULL){
            cout<<"Stack empty\n";
        }
        else
        {
            cout<<"Stack not empty\n";
        }
        
    }

};

int main(){
    int c,d;
    char ch;
    Stack a;
    label:
    cout<<"OPERATIONS:\n1.push\n2.pop\n3.peek\n4.Check Empty\nEnter the operation choice:";
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
        a.isEmpty();
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
