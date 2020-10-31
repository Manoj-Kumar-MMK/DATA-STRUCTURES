#include<iostream>
#include<queue>
using namespace std;

class Stack2{
    public:
    queue <int> q1,q2;

    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q2.swap(q1);
    }
    int pop(){
        if(q1.empty()){
            cout<<"Queue is empty\n";
            exit(0);
        }
        else{      
        int x=q1.front();
        q1.pop();
        return x;
        };
    }
    void peek(){
        if(q1.empty())
            cout<<"Queue is empty\n";
        else
            cout<<"Top element:"<<q1.front()<<endl;
    }
};
class Stack1{
    public:
    queue <int> q1;

    void push(int x){
        int size=q1.size();
        q1.push(x);
        while(size--){
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop(){
        if(q1.empty()){
            cout<<"Queue is empty\n";
            exit(0);
        }
        else{      
        int x=q1.front();
        q1.pop();
        return x;
        }
    }
    void peek(){
        if(q1.empty())
            cout<<"Queue is empty\n";
        else
            cout<<"Top element:"<<q1.front()<<endl;
    }
};

int main(){
    int m,c,d;
    char ch;
    Stack2 a;
    label:
    cout<<"1.push\n2.pop\n3.peek\nYour choice:";
    cin>>c;
    switch(c){
        case 1:
        cout<<"Enter data:";
        cin>>d;
        a.push(d);
        break;
        case 2:
        a.pop();
        break;
        case 3:
        a.peek();
        break;
        default:
        cout<<"Invalid response:";
    }
    cout<<"Do you want to try another operation(y/n):";
    cin>>ch;
    if(ch=='y')
        goto label;
    return 0;
}