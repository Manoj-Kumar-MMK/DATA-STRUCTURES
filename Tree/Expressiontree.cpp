#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

typedef struct Node 
{ 
    char data; 
    struct Node * left, *right; 
    Node(char d){
        data=d;
        left=right=NULL;
    }
}Node; 
  
bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^') 
        return true; 
    return false; 
}

Node* expressionTree(string postfix){
    stack<Node*> s;
    Node* n,*l,*r;

    for(int i=0;i<postfix.length();i++){
        if(!isOperator(postfix[i])){
            n=new Node(postfix[i]);
            s.push(n);
        }
        else
        {
            n=new Node(postfix[i]);
            r=s.top();
            n->right=r;
            s.pop();
            l=s.top();
            n->left=l;
            s.pop();
            s.push(n);
        }
    }
    n=s.top();
    s.pop();
    return n;
}
void inorder(Node* root){
    if(!root)
        return;
  
    inorder(root->left);
    cout<<root->data; 
    inorder(root->right);
}
void preorder(Node* root){
    if(!root)
        return;
    cout<<root->data;   
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(!root)
        return;   
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}

int main(){
    string s;
    cout<<"Enter postfix expression:";
    cin>>s;
    Node* t=expressionTree(s);
    cout<<"Infix:";inorder(t);
    cout<<endl<<"Prefix:";preorder(t);
    cout<<endl<<"Postfix:";postorder(t);   
    return 0;
}