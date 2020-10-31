#include<bits/stdc++.h>
using namespace std;
int parent(int i){
    return (i-1)/2;
}
int lchild(int i){
    return 2*i+1;
}
int rchild(int i){
    return 2*i+2;
}
void heapifydown(vector<int>& a,int i){
    int l=lchild(i),r=rchild(i);
    int small=i;
    if(l<a.size() && a[l]<a[i])
        small=l;
    if(r<a.size() && a[r]<a[small])
        small=r;
    if(small!=i){
        swap(a[small],a[i]);
        heapifydown(a,small);
    }    
}
void heapifyup(vector<int>& a,int ind){
    int par=parent(ind);
    if(par>=0 && a[par]>a[ind]){
        swap(a[par],a[ind]);
        heapifyup(a,par);
    }
}
void insert(vector<int>& a,int data){
    a.push_back(data);
    heapifyup(a,a.size()-1);
}
void create(vector<int>& a){
    int data;
    cout<<"Enter data to insert:";
    cin>>data;
    do{
        insert(a,data);
        cout<<"Enter data to insert:";
        cin>>data;
    }while(data);
}
void deleteMin(vector<int>& a){
    a[0]=a[a.size()-1];
    a.pop_back();
    heapifydown(a,0);
}
int main(){
    vector <int> a;
    int ch,data;
    char yn;
    do{
        cout<<"OPERATIONS:\n1.Create Minheap\n2.insert\n3.display\n4.delete Min\nYour choice:";
        cin>>ch;
        switch(ch){
            case 1:
            create(a);
            break;
            case 2:
            cout<<"Enter data to insert:";
            cin>>data;
            insert(a,data);
            break;
            case 3:
            for(int i:a)
                cout<<i<<"->";
            break;
            case 4:
            deleteMin(a);
            break;
            default:
            cout<<"Invalid response";
        }
        cout<<"Do you want to try again:";
        cin>>yn;
    }while(yn=='y');
    return 0;
}