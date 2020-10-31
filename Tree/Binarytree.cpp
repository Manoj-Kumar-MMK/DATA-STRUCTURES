#include <iostream>
#include <vector>
#include<queue>
using namespace std;
#define arrsize 20

void clear(vector<int>& a){
    while(a.begin()!=a.end()){
        a.pop_back();
    }
}
void print_vec(vector<int> a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << "-->";
    }
}
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
class Binarytree
{
public:
    Node *root;
    int countNodes(Node *root)
    {
        int n;
        if (root == NULL)
            return 0;
        int ln = countNodes(root->left);
        int rn = countNodes(root->right);
        return ln + rn + 1;
    }
    Node *create()
    {
        int d;
        cout << "\nEnter the data:";
        cin >> d;
        if (d == 0)
            return NULL;
        Node *temp = new Node(d);
        cout << "\nEnter left child of" << d;
        temp->left = create();
        cout << "\nEnter right child of" << d;
        temp->right = create();
        return temp;
    }
    void preorder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << "->";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node *root)
    {
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "->";
    }
    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << "->";
        inorder(root->right);
    }
    int getheight(Node *root)
    {
        if (root == nullptr)
            return 0;
        else
        {
            int lheight = getheight(root->left);
            int rheight = getheight(root->right);
            if (lheight > rheight)
                return lheight + 1;
            else
                return rheight + 1;
        }
    }
    void printLevelOrder()
    {
        int h = getheight(root);
        for (int i = 1; i <= h; i++)
        {
            printLevel(root, i);
        }
    }
    void printLevel(Node *root, int level)
    {
        if (root==NULL)
            return;
        else if (level == 1)
            cout << root->data << "->";
        else if (level > 1)
        {
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
    }
    void printLevelOrderZigZag()
    {
        int h = getheight(root);
        bool dir = true;
        for (int i = 1; i <= h; i++)
        {
            printLevelSpecific(root, i, dir);
            dir = !dir;
        }
    }
    void printLevelSpecific(Node *root, int level, bool dir)
    {
        if (root==nullptr)
            return;
        else if (level == 1)
            cout << root->data << "->";
        else if (level > 1)
        {
            if (dir)
            {
                printLevelSpecific(root->left, level - 1,dir);
                printLevelSpecific(root->right, level - 1,dir);
            }
            else{
                printLevelSpecific(root->right, level - 1,dir);
                printLevelSpecific(root->left, level - 1,dir);
            }
        }
    }
    void convertToArrayLevelOrder(Node *root, vector<int>& arr,int ind=0)
    {
            if (root == NULL)
                return;
            arr[ind]=root->data;
            convertToArrayLevelOrder(root->left, arr,(2 * ind) + 1);
            convertToArrayLevelOrder(root->right, arr,(2 * ind) + 2);
    }
    void convertToArrayPreorder(Node *root, vector<int>& arr)
    {
        if (root == NULL)
            return;
        arr.push_back(root->data);
        convertToArrayPreorder(root->left, arr);
        convertToArrayPreorder(root->left, arr);
    }
    void convertToArrayPostorder(Node *root, vector<int>& arr)
    {
        if (root == NULL)
            return;
        convertToArrayPostorder(root->left, arr);
        convertToArrayPostorder(root->left, arr);
        arr.push_back(root->data);
    }
    void convertToArrayInorder(Node *root, vector<int>& arr)
    {
        if (root == NULL)
            return;
        convertToArrayInorder(root->left, arr);
        arr.push_back(root->data);
        convertToArrayInorder(root->left, arr);
    }
    
    bool search(Node *root, int data)
    {
        if (root == NULL)
            return false;

        if (root->data == data)
            return true;

        bool l = search(root->left,data);

        if (l)
            return l;
        bool r=search(root->right,data);

        return r;
    }
    Node *minValNode()
    {
        Node *curr = root;
        while (curr && curr->left)
            curr = curr->left;
        return curr;
    }
    Binarytree()
    {
        root = NULL;
    }
    int countNodes()
    {
        return countNodes(root);
    }
    int getheight()
    {
        return getheight(root);
    }
};

int main()
{
    Binarytree a;
    int data, ch, nc;
    char yn;
    vector<int> arr;
    do
    {
        cout << "OPERATIONS:\n1.create\n2.search\n3.inorder\n4.preorder\n5.postorder\n6.level order\n7.level order zigzag\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            a.root = a.create();
            nc = a.countNodes();
            break;
        case 2:
            cout << "Enter the data to search:";
            cin >> data;
            if (a.search(a.root,data))
                cout << "Found";
            else
            {
                cout << "Not found";
            }
            break;
        case 3:
            a.inorder(a.root);
            break;
        case 4:
            a.preorder(a.root);
            break;
        case 5:
            a.postorder(a.root);
            break;
        case 6:
            a.printLevelOrder();
            break;
        case 7:
            a.printLevelOrderZigZag();
            break;
        default:
            cout << "Invalid response";
            break;
        }
        cout << "Do you wan to try again";
        cin >> yn;
    } while (yn == 'y');
    return 0;
}