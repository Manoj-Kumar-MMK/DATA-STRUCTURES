#include<iostream>
using namespace std;

class Queue{
    public:
    Queue(int n){
        capacity=n;
        arr=new int[n];
        front=0;
        rear=n-1;
    }
    int front,rear,capacity,size=0,*arr;
    int frontel(){
        if(size!=0)
        return arr[front];
        else
        cout<<"Queue is empty";        
        return 0;
    }
    int rearel(){
        if(size!=0)
        return arr[rear];
        else
        {
            cout<<"Queue is empty";
        }
        return 0;
    }
    void enqueue(int d){
        if(size==capacity){
            cout<<"QUEUE OVERFLOW\n";
            return;
        }
        rear=(rear+1)%capacity;
        arr[rear]=d;
        ++size;
    }
    int dequeue(){
        if(size==0){
            cout<<"QUEUE UNDERFLOW\n";
            return -1;
        }
        int temp=arr[front];
        front=(front+1)%capacity;
        --size;
        return temp;
    }
    void isEmpty(){
        if(size==0)
            cout<<"Queue is empty\n";
        else
            cout<<"Queue is not empty\n";
    }
    void isFull(){
        if(size==capacity)
            cout<<"Queue is full\n";
        else
            cout<<"Queue is not full\n";
    }
    int capacityof(){
        return capacity;
    }
    int sizeOf(){
        return size;
    }
};

int main(){
    int c,max,d;
    char ch;
    cout<<"Enter the size of the queue you want to create:";
    cin>>max;
    Queue a(max);
    label:
    cout<<"OPERATIONS:\n1.enqueue\n2.dequeue\n3.front\n4.rear\n5.capacity\n6.size\n7.Check Empty\n8.Check Full\nEnter the operation choice:";
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
        
        case 3:
        cout<<"Front:"<<a.frontel()<<endl;
        break;

        case 4:
        cout<<"Rear:"<<a.rearel()<<endl;
        break;

        case 6:
        cout<<"SIZE:"<<a.sizeOf()<<endl;
        break;
        
        case 5:
        cout<<"CAPACITY:"<<a.capacityof()<<endl;
        break;

        case 7:
        a.isEmpty();
        break;

        case 8:
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