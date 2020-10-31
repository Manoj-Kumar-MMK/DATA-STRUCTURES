#include<iostream>
#include<stack>
using namespace std;

class Queue1{
    public:
    stack <int> s;

    void enqueue(int data){
        s.push(data);
    }

    int dequeue(){
        if(s.empty()){
            cout<<"Stack underflow\n";
            exit(0);
        }
        int top=s.top();
        s.pop();

        if(s.empty()){
            return top;
        }

        int item=dequeue();
        s.push(top);

        return item;
    }
};

class Queue2{
    public:
    stack <int> s1,s2;

    void enqueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue(){
        if(s1.empty()){
            cout<<"Queue is empty\n";
            exit(0);
        }
        int x=s1.top();
        s1.pop();
        return x;
    }
};

int main(){
    Queue2 a;
    int c,d;
    char ch;
    label:
    cout<<"1.enqueue\n2.dequeue\nYour choice:";
    cin>>c;
    switch(c){
        case 1:
        cout<<"Enter data";
        cin>>d;
        a.enqueue(d);
        break;
        case 2:
        cout<<a.dequeue()<<endl;
        break;
        default:
        cout<<"INVALID RESPONSE";
    }
    cout<<"Do you want to ty another operation(y/n):";
    cin>>ch;
    if(ch=='y')
        goto label;
    return 0;
}