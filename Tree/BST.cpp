#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int d):data(d),left(NULL),right(NULL){}
};

class BST{
    public:
    Node *root=NULL;

    Node* insert(int data,Node* root){
        if(root==NULL)
            return new Node(data);
        else if(data<root->data) 
            root->left=insert(data,root->left);
        else
            root->right=insert(data,root->right);        
        return root;
    }
    bool search(int data,Node* root){
        bool found=false;
        if(root==NULL)
            return found;
        if(root->data==data)
            return !found;
        bool lf=search(data,root->left);
        if(lf) return !found;
        bool rf=search(data,root->right);
        return rf;        
    }
    Node* minValNode(Node* root){
        Node* curr=root;
        while(curr && curr->left)
            curr=curr->left;
        return curr;
    }
    Node* deleteNode(int data,Node* root){
        if(root==NULL)
            return root;
        if(data<root->data)
            root->left=deleteNode(data,root->left);
        else if(data>root->data)
            root->right=deleteNode(data,root->right);
        else{
            if(root->right==NULL){
                Node* temp=root->left;
                return temp;
            }
            else if(root->left==NULL){
                Node* temp=root->right;
                return temp;
            }
            Node*temp=minValNode(root->right);
            root->data=temp->data;
            root->right=deleteNode(temp->data,root->right);
        }
        return root;
    }
    
    void print_inorder(Node *root){
        if(root==NULL)
            return;
        print_inorder(root->left);
        cout<<root->data<<"->";
        print_inorder(root->right);
    }
    public:
    bool search(int data){
        return search(data,root);
    }
    Node* deleteNode(int data){
        return deleteNode(data,root);
    }
    void print_inorder(){
        print_inorder(root);        
    }
};
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
    {    
        if (root == NULL)
          return ; 
    
        if (root->data == key) 
        { 
            if (root->left != NULL) 
            { 
                Node* tmp = root->left; 
                while (tmp->right) 
                    tmp = tmp->right; 
                pre = tmp ; 
            } 
            if (root->right != NULL) 
            { 
                Node* tmp = root->right ; 
                while (tmp->left) 
                    tmp = tmp->left ; 
                suc = tmp ; 
            } 
            return ; 
        } 
        if (root->data > key) 
        { 
            suc = root ; 
            findPreSuc(root->left, pre, suc, key) ; 
        } 
        else  
        { 
            pre = root ; 
            findPreSuc(root->right, pre, suc, key) ; 
        } 
} 
int main(){
    BST a;
    int ch,data,n;
    char yn;
    int *arr=new int[30];
    Node *pre=nullptr,*suc=nullptr;
    do{
        cout<<"OPERATIONS\n1.create\n2.insert\n3.search\n4.print inorder\n5.delete\n6.Predecessor and successor\nEnter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"Enter the elements of binary tree(enter 0 to stop):";
            cin>>data;
            do{
                a.root=a.insert(data,a.root);
                cout<<"Enter the elements of binary tree(enter 0 to stop):";
                cin>>data;
            }while(data!=0);
            break;
            case 2:
            cout<<"Enter the element to insert:";
            cin>>data;
            a.root=a.insert(data,a.root);
            break;
            case 3:
            cout<<"Enter the key to search:";
            cin>>data;
            if(a.search(data))
                cout<<"Found";
            else
                cout<<"Not found";            
            break;
            case 4:
            a.print_inorder();
            break;
            case 5:
            cout<<"Enter the key to delete";
            cin>>data;
            a.root=a.deleteNode(data,a.root);
            break;
            case 6:
            cout<<"Enter data to find predecessor and successor:";
            cin>>data;
            findPreSuc(a.root,pre,suc,data);
            if (pre != NULL) 
                cout << "Predecessor is " << pre->data << endl; 
            else
                cout << "No Predecessor";  
            if (suc != NULL) 
                cout << "Successor is " << suc->data; 
            else
                cout << "No Successor"; 
            break;
            default:
            cout<<"invalid response";
        }
        cout<<"\nDo you want to try again(y/n):";
        cin>>yn;
    }while(yn=='y');
    return 0;
}