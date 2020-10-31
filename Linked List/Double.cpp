#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next=NULL,*prev=NULL;

    Node(int n){
        data=n;
    }
};

class List{
    public:
    Node* head=NULL,*tail=NULL;

    void create(){
        int d;
        Node *curr,*temp;
        curr=head;
        cout<<"Enter data:";
        cin>>d;
        while(d!=0){
            temp=new Node(d);
            if(head==NULL)
                head=tail=temp;
            else{
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
            }
            cout<<"Enter data:";
            cin>>d;
        }
    }
    void insertAtBeg(Node* temp){
        if(head==NULL)
            head=tail=temp;
        else{        
            head->prev=temp;
            temp->next=head;
            head=temp;
        }
    }

    void insertAtEnd(Node* temp){
        if(head==NULL)
            head=tail=temp;
        else{
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }            
    }
    void insertAt(Node* temp,int pos){
        Node* curr=head;
        if(pos==1){
            this->insertAtBeg(temp);
        }
        else{
        pos-=2;        
        while(pos--){
            curr=curr->next;
        }
        temp->next=curr->next;
        temp->prev=curr;
        curr->next=temp;
        if(!curr->next){
            temp->next->prev=temp;
        }     
        }
    }
    void deleteFirst(){
        if(head==NULL)
            cout<<"Empty list";
        else{
        head=head->next;
        if(head)
        head->prev=NULL;
        }
    }
    void deleteLast(){
        if(tail==NULL)
            cout<<"Empty list";
        else{
        tail=tail->prev;
        tail->next=NULL;
        }
    }
    void deletePos(int pos){
        Node *curr=head;
        if(pos==1){
            this->deleteFirst();
            return;
        }
        pos--;
        while(pos--){
            curr=curr->next;
        }
        curr->prev->next=curr->next;
        if(curr->next)
            curr->next->prev=curr->prev;
    }
    
    void deleteData(int d){
        Node *curr=head;
        if(curr!=NULL && curr->data==d)
            head=curr->next;
        else{
            while(curr->next!=NULL && curr->data!=d){
                curr=curr->next;
            }
            curr->next->prev=curr->prev;
            curr->prev->next=curr->next;           
        }
    }
    void deleteAllData(int d){
        Node* curr=head;
        while(curr->next!=NULL){
            if(curr->data==d){
                if(curr==head){
                    curr=head->next;
                    curr->prev=NULL;
                    head=curr;
                    continue;
                }
                else{
                curr->prev->next=curr->next;
                if(!curr->next)
                    curr->next->prev=curr->prev;
                }
            }
            curr=curr->next;
        }
    }
    void reverse(){
        Node *curr,*temp;
        curr=head;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=curr->prev;
            curr->prev=temp;
            curr=temp;
        }     
        curr=head;
        head=tail;
        tail=curr;
    }
    void sorted(){
        int d;
        Node *curr,*temp;
        cout<<"Enter data:";
        cin>>d;
        while(d!=0){
            temp=new Node(d);
            if(head==NULL)
                head=temp;
            else if(head->data>=d){
                this->insertAtBeg(temp);
            }
            else{
                curr=head;
                while(curr->next!=NULL && curr->next->data<temp->data)
                    curr=curr->next;
                temp->next=curr->next;
                temp->prev=curr;
                if(curr->next!=NULL)
                    temp->next->prev=temp;
                curr->next=temp;
            }
            cout<<"Enter data:";
            cin>>d;
            }
        }
    void print(){
        Node* curr=head;
        while(curr!=NULL){
            cout<<curr->data;
            if(curr->next!=NULL)
            cout<<"->";
            curr=curr->next;
        }
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
    cout<<"1.create\n2.insertAtBeg\n3.insertAt\n4.insertAtEnd\n5.deletefirst\n6.deletelast\n7.deleteposition\n8.deletefirstocc\n9.deleteallocc\n10.print\n11.reverse\n12.sorted\nEnter your choice:";
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
            l.sorted();
            break;
        default:
        cout<<"RESPONSE INVALID:\n";
    }
    cout<<"Do you want to try again(y/n):";
    cin>>ch;
    if(ch=='y')
        goto label;
    return 0;
}