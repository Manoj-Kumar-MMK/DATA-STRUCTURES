#include<iostream>
#include<stack>
#include<string>
#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    switch(c){
        case '^':
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}
int prece(char c){
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else 
        return -1;
}
void prefixToInfix(string s){
    stack<string> a;
    int l=s.length();
    for(int i=l-1;i>=0;i--){
        if(isOperator(s[i])){
            string a1=a.top();a.pop();
            string a2=a.top();a.pop();
            string temp='('+a1+s[i]+a2+')';
            a.push(temp);
        }
        else
        {
            a.push(string(1,s[i]));
        }        
    }
    cout<<a.top();
}
void prefixToPostfix(string s){
    stack<string> a;
    int l=s.length();
    for(int i=l-1;i>=0;i--){
        if(isOperator(s[i])){
            string a1=a.top();a.pop();
            string a2=a.top();a.pop();
            string temp=a1+a2+s[i];
            a.push(temp);
        }
        else
        {
            a.push(string(1,s[i]));
        }        
    }
    cout<<a.top();
}
void postfixToPrefix(string s){
    stack<string> a;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(isOperator(s[i])){
            string a1=a.top();a.pop();
            string a2=a.top();a.pop();
            string temp=s[i]+a2+a1;
            a.push(temp);
        }
        else
        {
            a.push(string(1,s[i]));
        }        
    }
    cout<<a.top();
}
void postfixToInfix(string s){
    stack<string> a;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(isOperator(s[i])){
            string a1=a.top();a.pop();
            string a2=a.top();a.pop();
            string temp='('+a2+s[i]+a1+')';
            a.push(temp);
        }
        else
        {
            a.push(string(1,s[i]));
        }        
    }
    cout<<a.top();
}
void infixToPostfix(string s){
    stack <char> a;
    string ns;
    int l=s.length();
    for(int i=0;i<l;i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            ns+=s[i];
        }
        else if(s[i]=='(')
            a.push('(');
        else if(s[i]==')'){
            while(!a.empty() && a.top()!='('){
                ns+=a.top();
                a.pop();
            }
            if(a.top()=='(')
                a.pop();
        }
        else{
            while(!a.empty() && prece(s[i])<=prece(a.top())  ){
                ns+=a.top();
                a.pop();
            }
            a.push(s[i]);
        }
    }
    while(!a.empty()){
        ns+=a.top();
        a.pop();
    }
    cout<<"The postfix form is:"<<ns<<endl;
}
void infixToPrefix(string s){
    stack <char> a;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            s[i]=')';
            continue;
        }
        if(s[i]==')')
            s[i]='(';
    }
    string ns;
    int l=s.length();
    for(int i=0;i<l;i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            ns+=s[i];
        }
        else if(s[i]=='(')
            a.push('(');
        else if(s[i]==')'){
            while(!a.empty() && a.top()!='('){
                ns+=a.top();
                a.pop();
            }
            if(a.top()=='(')
                a.pop();
        }
        else{
            while(!a.empty() && prece(s[i])<=prece(a.top())  ){
                ns+=a.top();
                a.pop();
            }
            a.push(s[i]);
        }
    }
    while(a.top()!='X'){
        ns+=a.top();
        a.pop();
    }
    reverse(ns.begin(),ns.end());
    cout<<"The prefix form is:"<<ns<<endl;
}
int main(){
    string exp="a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}