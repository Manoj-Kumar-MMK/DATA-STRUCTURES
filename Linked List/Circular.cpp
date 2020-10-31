#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next=NULL;

    Node(int n){
        data=n;
    }
};

class List{
    public:
    Node* tail=NULL;

    void create(){
        int d;
        Node *temp;
        cout<<"Enter data:";
        cin>>d;
        while(d!=0){
            temp=new Node(d);
            if(tail==NULL)
            {
                tail=temp;
                tail->next=temp;
            }
            else
            {
                temp->next=tail->next;
                tail->next=temp;
                tail=temp;
            }            
            cout<<"Enter data:";
            cin>>d;
        }
    }
    void insertAtBeg(Node* temp){
        if(tail==NULL){
            tail=temp;
            tail->next=temp;
        }
        else{
        temp->next=tail->next;
        tail->next=temp;
        }
    }

    void insertAtEnd(Node* temp){
        if(tail==NULL){
            tail=temp;
            tail->next=temp;
        }
        else{
        temp->next=tail->next;
        tail->next=temp;
        }
        tail=temp;
    }
    int getlength(){
        int len=0;
        if(tail->next==NULL)
            return 0;
        Node *temp=tail->next;
        while(temp!=tail)
        {
            len++;
            temp=temp->next;
        }
        return len+1;
    }
    void insertAt(Node* temp,int pos){
        int len=this->getlength();
        Node *curr=tail->next;
        if(pos<0 and pos>len-1){
            cout<<"Invalid response:";
        }
        else if(pos==1){
            this->insertAtBeg(temp);
        }
        else{
        pos-=2;      
        while(pos--){
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
        }
    }
    void deleteFirst(){
        if(tail==NULL){
            cout<<"List is empty";
        }
        else if(tail->next==tail){
            tail=NULL;
        }
        else{
        tail->next=tail->next->next;
        }
    }
    void deleteLast(){
        Node *curr=tail->next;
        if(tail==NULL){
            cout<<"List is empty";
        }
        else if(tail->next==tail){
            tail=NULL;
        }
        else{
            while(curr->next!=tail){
                curr=curr->next;
            }
            curr->next=tail->next;
            tail=curr;
        }
    }
    void deletePos(int pos){
        Node *curr=tail->next;
        int len=this->getlength();
        if(pos<0 and pos>len){
            cout<<"Invalid response:";
            return;
        }
        else if(pos==1){
            this->deleteFirst();
            return;
        }
        else{
        pos-=2;
        while(pos--){
            curr=curr->next;
       }
       if(curr->next==tail)
        tail=curr;
        curr->next=curr->next->next;
        }
    }
    
    void deleteData(int d){
        Node *curr=tail->next,*prev;
        if(curr!=tail && curr->data==d){
            this->deleteFirst();
            return;
        }
        else{
            while(curr!=tail && curr->data!=d){
            prev=curr;
            curr=curr->next;            
            }
        if(curr==tail && curr->data==d){
            this->deleteLast();
            return;
        }        
        prev->next=curr->next;
        }
    }
    void deleteAllData(int n){
        Node* curr,*prev;
        one:
        prev=curr=tail->next;
        if(tail->next->data==n){
            this->deleteFirst();
            goto one;
        }
        curr=curr->next;
        while(curr!=tail->next){
            if(curr->data==n){
                prev->next=prev->next->next;
                curr=prev->next;
                continue;
            }
            prev=prev->next;
            curr=curr->next;
        }
    }
    void removeDuplicates(){
        Node *first,*sec;
        first=tail->next;
        do{
            sec=first;
           do{
                if(first->data==sec->next->data)
                sec->next=sec->next->next;
                else
                sec=sec->next;                
            } while(sec->next!=tail->next);
            first=first->next;            
        }while(first!=tail->next);
    }
    void reverse(){
        Node *curr,*next,*prev;
        if(tail==NULL)
            return;
        curr=tail->next;
        next=curr->next;
        prev=NULL;
        while(curr!=tail){
        prev=curr;
        curr=next;
        next=curr->next;
        curr->next=prev;     
        }
        next->next=tail;
        tail=next;     
    }
    void print(){
        Node* curr=tail->next;
        while(curr->next!=tail->next){
            cout<<curr->data<<"->";
            curr=curr->next;
        }
        cout<<curr->data;
    }
};

int main()
{
    List l;
    Node *node=NULL;
    char ch;
    int n,pos,d;
    cout<<"----------LINKED LIST-----------\n";
    label:
    cout<<"OPERATIONS\n";
    cout<<"1.create\n2.insertAtBeg\n3.insertAt\n4.insertAtEnd\n5.deletefirst\n6.deletelast\n7.deleteposition\n8.deletefirstocc\n9.deleteallocc\n10.print\n11.reverse\n12.remove duplicates\n13.getlength\nEnter your choice:";
    cin>>n;
    switch(n){
        case 1:
            l.create();
            break;
        case 2:
            cout<<"Enter data:";
            cin>>d;
            node=new Node(d);
            l.insertAtBeg(node);
            break;
        case 3:
            cout<<"Enter data:";
            cin>>d;
            node=new Node(d);
            cout<<"Enter position:";
            cin>>pos;
            l.insertAt(node,pos);
            break;
        case 4:
            cout<<"Enter data:";
            cin>>d;
            node=new Node(d);
            l.insertAtEnd(node);
            break;

        case 5:
            l.deleteFirst();
            break;
        case 6:
            l.deleteLast();
            break;
        case 7:
            cout<<"Enter position:";
            cin>>pos;
            l.deletePos(pos);
            break;
        case 8:
            cout<<"Enter key:";
            cin>>d;
            l.deleteData(d);
            break;
        case 9:
            cout<<"Enter key:";
            cin>>d;
            l.deleteAllData(d);
            break;
        case 10:
            l.print();
            break;
        case 11:
            l.reverse();
            break;
        case 12:
            l.removeDuplicates();
            break;
        case 13:
            cout<<"Length is:"<<l.getlength()<<endl;
            break;
        default:
        cout<<"RESPONSE INVALID:\n";
    }
    cout<<"\nDo you want to try again(y/n):";
    cin>>ch;
    if(ch=='y')
        goto label;
    return 0;
}