// A Dictionary stores keywords and its meanings. Provide facility for adding new 
// keywords, deleting keywords, updating values of any entry. Provide facility to display 
// whole data sorted in ascending/ Descending order. Also find how many maximum 
// comparisons may require for finding any keyword. Use Height balance tree and find the 
// complexity for finding a keyword 

#include <iostream>
using namespace std;

struct node
{
    string key;
    string meaning;
    node *left;
    node *right;
};
class AVL
{
    node *root = NULL;

public:
    node *balance(node *root)
    {
        int bal_fact = dif(root);
        if (bal_fact >= 2)
        {
            if (dif(root->left) < 0)
            {
                root = LR(root);
            }
            else
            {
                root = LL(root);
            }
        }
        else if (bal_fact <= -2)
        {
            if (dif(root->right) < 0)
            {
                root = RR(root);
            }
            else
            {
                root = RL(root);
            }
        }
        return root;
    }

    int dif(node *root)
    {
        int l, r, bal_fact;
        l = height(root->left);
        r = height(root->right);
        bal_fact = l - r;
        return bal_fact;
    }

    int maximum(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }

    int height(node *root)
    {
        if (root == NULL)
        {
            return (-1);
        }
        else
        {
            return (maximum(height(root->left), height(root->right)) + 1);
        }
    }

    node *LL(node *parent)
    {
        node *temp = parent->left;
        node *temp1 = temp->right;
        temp->right = parent;
        parent->left = temp1;
        return temp;
    }

    node *RR(node *parent)
    {
        node *temp = parent->right;
        node *temp1 = temp->left;
        temp->left = parent;
        parent->right = temp1;
        return temp;
    }

    node *LR(node *parent)
    {
        parent->left = RR(parent->left);
        return LL(parent);
    }

    node *RL(node *parent)
    {
        parent->right = LL(parent->right);
        return RR(parent);
    }

    void ascending(node *temp)
    {
        if (temp)
        {
            ascending(temp->left);
            cout << "\n\t" << temp->key << "-> " << temp->meaning;
            ascending(temp->right);
        }
    }

    void descending(node *temp)
    {
        if (temp)
        {
            descending(temp->right);
            cout << "\n\t" << temp->key << "-> " << temp->meaning;
            descending(temp->left);
        }
    }

    void display()
    {
        cout << "\nKeywords in ascending oreder are : ";
        ascending(root);
        cout << "\nKeywords in descending order are : ";
        descending(root);
    }

    node *insert(node *root, node *temp)
    {
        // if root==NULL
        if (!root)
        {
            return temp;
        }
        else
        {
            if (temp->key > root->key)
            {
                root->right = insert(root->right, temp);
                root = balance(root);
            }
            else if (temp->key < root->key)
            {
                root->left = insert(root->left, temp);
                root = balance(root);
            }
        }
        return root;
    }
    void create()
    {
        node *temp;
        char a;
        do
        {
            temp = new node;
            cout << "\nEnter the word : ";
            cin >> temp->key;
            cout << "\nEnter meaning : ";
            cin >> temp->meaning;
            temp->right = NULL;
            temp->left = NULL;
            root = insert(root, temp);
            cout << "\nDo you wanna continue ?(y/n) : ";
            cin >> a;
        } while (a == 'y');
    }

    node *extractmin(node *temp)
    {
        if (!temp->left)
        {
            return temp->right;
        }
        temp->left = extractmin(temp->left);
        return balance(temp);
    }

    node *deleteNode(node *root, string k)
    {
        if (!root)
        {
            return root;
        }
        if (k > root->key)
        {
            root->right = deleteNode(root->right, k);
        }
        else if (k < root->key)
        {
            root->left = deleteNode(root->left, k);
        }
        else
        {
            node *l = root->left;
            node *r = root->right;
            delete root;
            if (!r)
            {
                return l;
            }
            node *m = r;
            while (m->left)
            {
                m = m->left;
            }
            m->right = extractmin(r);
            m->left = l;

            return balance(m);
        }
        return balance(root);
    }

    void deleteMyNode()
    {
        string k;
        cout << "\nEnter the value you wanna delete : ";
        cin >> k;
        root = deleteNode(root, k);
        cout << "\nNode deleted ";
    }
};

int main()
{
    AVL obj;
    obj.create();
    obj.display();
    obj.deleteMyNode();
    obj.display();
    return 0;
}