#include <iostream>
#include <string>
using namespace std;

typedef struct node{
    string key;
    int val;
    struct node* left;
    struct node* right;
    struct node* parent;
}Node;

class BSTree{
    public:
        BSTree();
        void put(string key, int val);
        int get(string key);
        bool remove(string key);
        void rank();

    private:
        Node* find_succesor(Node* p);
        void print(Node *p);
        Node* root;
        size_t size;

};

BSTree::BSTree()
{
    root = NULL;
    size = 0;
}

void BSTree::print(Node *p)
{
    if(p)
    {
        print(p->left);
        cout << p->key << ":" << p->val << endl;
        print(p->right);
    }
}

void BSTree::rank()
{
    print(root);
}

void BSTree::put(string key, int val)
{
    Node *p = new Node;
    p->key = key;
    p->val = val;
    p->left = NULL;
    p->right = NULL;

    if(!root)
    {
        root = p;
        p->parent = NULL;
        return;
    }
    
    Node *i = root;
    while(true)
    {
        if(i->key == key)
        {
            i->val = val;
            return;
        }
        else if(i->key < key)
        {
            if(i->right == NULL)
            {
                i->right = p;
                p->parent = i;
                return;
            }
            i = i->right;
        }
        else
        {
            if(i->left == NULL)
            {
                i->left = p;
                p->parent = i;
                return;
            }
            i = i->left;
        }
    }
}

int BSTree::get(string key)
{
    Node *i = root;

    while(i)
    {
        if(i->key == key)
            break;
        else if(i->key < key)
            i = i->right;
        else
            i = i->left;
    }
    return i == NULL ? -1 : i->val;
}

Node* BSTree::find_succesor(Node *p)
{
    p = p->right;
    while(p->left) p = p->left;
    return p;
}

bool BSTree::remove(string key)
{
    Node* p = root;
    while(p)
    {
        if(p->key == key)
            break;
        else if(p->key < key)
            p = p->right;
        else
            p = p->left;
    }

    if(!p)
        return false;

    if(!p->left || !p->right)
    {
        Node* temp = !p->left ? p->right : p->left;
        if(root->key == p->key)
            root = temp;
        else if(p->parent->left == p)
            p->parent->left = temp;
        else
            p->parent->right = temp;

        if(temp)
        {
            temp->parent = p->parent;
        }
        delete p;
    }
    else
    {
        Node * successor = find_succesor(p);
        string s_key = successor->key;
        int s_val = successor->val;
        remove(successor->key);
        p->key = s_key;
        p->val = s_val;
    }
    return true;
}

int main()
{
    BSTree t;
    t.put("ace",100);
    t.put("ying",99);
    t.put("zhao",200);
    t.put("hao",13);
    t.put("a",130);
    t.put("b",45);
    t.put("c",45);
    t.remove("ace");
    //cout << t.get("ying") << endl;
    t.rank();
}
