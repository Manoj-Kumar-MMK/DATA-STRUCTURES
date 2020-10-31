#include<iostream>
using namespace std;

class Hash{
    private:
    int cap,size,prime,*table;
    public:
    Hash(int capacity,int hashkey){
        cap=capacity;
        prime=hashkey;
        size=0;
        table=new int[cap];
        for(int i=0;i<cap;i++)
            table[i]=-1;
    }  
    bool isFull(){
        if(size==cap)
            return 1;
        return 0;
    }
    int hash1(int key){
        return key%cap;
    }
    int hash2(int key){
        return (prime-(key%prime));
    }
    void insertHash(int key){
        if(isFull())
            return;

        int index=hash1(key);
        
        if(table[index]!=-1){
            int index2=hash2(key);
            for(int i=0;i<cap;i++){        
                index=(index+i*index2)%cap;
                if(table[index]==-1){
                    table[index]==key;
                    break;
                }
            }
        }
        else
            table[index]=key;        
    }
    void search(int key){
        int index1=hash1(key);
        int index2=hash2(key);
        
        int i=0;
        while(table[(index1+i*index2)%cap]!=key){
            if(table[(index1+i*index2)%cap]==-1){
                cout<<key<<"not found\n";
                return;
            }
        }
        cout<<key<<"found\n";
    }
    void display(){
        for(int i=0;i<cap;i++){
            if(table[i]!=-1){
                cout<<i<<"--->"<<table[i]<<endl;
            }
            else
                cout<<i<<endl;            
        }
    }


};

int main(){
    int *a,n,i,key,cap,prime;
    cout<<"Enter the number of elements of the array";
    cin>>n;
    a=new int[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the size and prime number of hashing for the hash table:";
    cin>>cap>>prime;
    Hash b(cap,prime);
    for(i=0;i<n;i++){
        b.insertHash(a[i]);
    }
    cout<<"Enter the element to search:";
    cin>>key;
    b.search(key);
}