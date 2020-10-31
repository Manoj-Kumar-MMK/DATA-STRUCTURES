#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next=NULL;
    Node(int d){
        data=d;
    }
};
class Queue{
    public:
    Node *front,*rear;
    Queue(){
        front=rear=NULL;
    }
    void enqueue(int d){
        Node *temp=new Node(d);
        if(rear==NULL){
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    int dequeue(){
        if(front==NULL){
            cout<<"Queue empty";
            exit(0);
        }
        int x=front->data;
        front=front->next;
        if(front==NULL)
        rear=NULL;
        return x;
    }
};

int main(){
    int c,d;
    char ch;
    Queue a;
    label:
    cout<<"OPERATIONS:\n1.enqueue\n2.dequeue\nEnter the operation choice:";
    cin>>c;
    switch(c){
        case 1:
        cout<<"Enter value:";
        cin>>d;
        a.enqueue(d);
        break;

        case 2:
        cout<<"The dequeued element:"<<a.dequeue()<<endl;
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