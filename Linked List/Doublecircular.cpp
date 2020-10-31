#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next,*prev;
    Node(int n){
        data=n;
        next=prev=NULL;
    }
};

class List{
    public:
    Node *head,*tail;
    List(){
        head=tail=NULL;
    }
    void create(){
        int d;
        Node *curr,*temp;
        curr=head;
        cout<<"Enter data:";
        cin>>d;
        while(d!=0){
            temp=new Node(d);
            if(head==NULL){
                head=tail=temp;
                head->next=head->prev=head;
            }
            else{
                tail->next=temp;
                temp->prev=tail;
                temp->next=head;
                head->prev=temp;
                tail=temp;
            }
            cout<<"Enter data:";
            cin>>d;
        }
    }
    void print(){
        Node *temp=head;
        if(head==NULL)
        {
            cout<<"EMPTY LIST\n";
        }
        else{
            while(temp!=tail){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<temp->data;
        }
    }

    void insertAtBeg(Node* temp){
        if(head==NULL){
            head=tail=temp;
            temp->next=temp->prev=head;
        }
        else{
            temp->next=head;
            temp->prev=tail;
            head->prev=temp;
            tail->next=temp;
            head=temp;
        }
    }
    void insertAtEnd(Node* temp){
        if(head==NULL){
            head=tail=temp;
            temp->next=temp->prev=head;
        }
        else{
            temp->next=head;
            temp->prev=tail;
            head->prev=temp;
            tail->next=temp;
            tail=temp;
        }
    }
    int getlength(){
        int len=0;
        Node* curr=head;
        while(curr->next!=head){
            len++;
            curr=curr->next;
        }
        return len+1;
    }
    void insertAt(Node* temp,int pos){
        int len=this->getlength();
        Node *curr=head;
        if(pos<1 or pos>len)
            cout<<"INvalid response";
        else if(pos==1){
            this->insertAtBeg(temp);
        }
        else
        {
            pos-=2;
            while(pos--){
                curr=curr->next;
            }
            temp->prev=curr;
            temp->next=curr->next;
            curr->next=temp;
            temp->next->prev=temp;
        }
    }
    void deleteFirst(){
        if(head==NULL){
            cout<<"NO node found";
        }
        else if(head->next==head){
            head=tail=NULL;
        }
        else{
            head=head->next;
            tail->next=head;
            head->prev=tail;
        }
    }
    void deleteLast(){
        if(head==NULL){
            cout<<"NO node found";
        }
        else if(head->next==head){
            head=tail=NULL;
        }
        else{
            tail=tail->prev;
            tail->next=head;
            head->prev=tail;
        }
    }
        void deletePos(int pos){
        int len=this->getlength();
        Node *curr=head;
        if(pos<1 or pos>len)
            cout<<"Invalid response";
        else if(pos==1){
            this->deleteFirst();
        }
        else
        {
            pos-=1;
            while(pos--){
                curr=curr->next;
            }
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
        }
    }
};
int main(){
    List l;
    Node *node=NULL;
    char ch;
    int n,pos,d;
    cout<<"----------LINKED LIST-----------\n";
    label:
    cout<<"OPERATIONS\n";
    cout<<"1.create\n2.insertAtBeg\n3.insertAt\n4.insertAtEnd\n5.deletefirst\n6.deletelast\n7.deleteposition\n8.print\nEnter your choice:";
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
            l.print();
            break;
    }
    cout<<"Do you want to try again(y/n):";
    cin>>ch;
    if(ch=='y')
        goto label;
    return 0;
}