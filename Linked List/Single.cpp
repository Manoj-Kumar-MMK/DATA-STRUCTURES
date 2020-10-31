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
    Node* head=NULL;

    void create(){
        int d;
        Node *temp,*curr;
        cout<<"Enter data:";
        cin>>d;
        while(d!=0){
            temp=new Node(d);
            if(head==NULL)
            {
                head=curr=temp;
            }
            else
            {
                curr->next=temp;
                curr=temp;
            }
            cout<<"Enter data:";
            cin>>d;
        }
    }
    void insertAtBeg(Node* temp){
        temp->next=head;
        head=temp;
    }

    void insertAtEnd(Node* temp){
        Node *curr=head;
        if(curr==NULL){
            head=temp;
        }
        else{
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
        }
    }
    void insertAt(Node* temp,int pos){
        Node* curr=head;
        if(pos==1){
            this->insertAtBeg(temp);
            return;
        }
        pos-=2;        
        while(pos--){
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
    void deleteFirst(){
        head=head->next;
    }
    void deleteLast(){
        Node *curr=head,*prev;
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
    }
    void deletePos(int pos){
        Node *curr=head;
        if (pos==1){
            this->deleteFirst();
            return;
        }
        pos-=2;
        while(pos--){
            curr=curr->next;
       }
        curr->next=curr->next->next;
    }
    
    void deleteData(int d){
        Node *curr=head,*prev;
        if(curr!=NULL && curr->data==d)
            head=curr->next;
        else{
            while(curr->next!=NULL && curr->data!=d){
            prev=curr;
            curr=curr->next;            
            }
        if(curr==NULL)
        return;
        prev->next=curr->next;
        }
    }
    void deleteAllData(int n){
        Node* curr,*prev;
        one:
        prev=curr=head;
        if(head->data==n){
            this->deleteFirst();
            goto one;
        }
        curr=curr->next;
        while(curr!=NULL){
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
        first=head;
        while(first!=NULL){
            sec=first;
            while(sec->next!=NULL){
                if(first->data==sec->next->data)
                sec->next=sec->next->next;
                else
                sec=sec->next;                
            }
            first=first->next;            
        }
    }
    void reverse(){
        Node *curr,*next,*prev;
        curr=head;
        next=prev=NULL;
        while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;       
        }
        head=prev;     
    }
    void sorted(){
        int d;
        Node *curr,*temp;
        cout<<"Enter data:";
        cin>>d;
        while(d!=0){
            temp=new Node(d);
            if(head==NULL || head->data>=temp->data)
                this->insertAtBeg(temp);
            else{
                curr=head;
                while(curr->next!=NULL &&  curr->next->data<temp->data)
                    curr=curr->next;
                temp->next=curr->next;
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
    cout<<"1.create\n2.insertAtBeg\n3.insertAt\n4.insertAtEnd\n5.deletefirst\n6.deletelast\n7.deleteposition\n8.deletefirstocc\n9.deleteallocc\n10.print\n11.reverse\n12.sorted\n13.remove duplicates\nEnter your choice:";
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
        case 13:
            l.removeDuplicates();
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