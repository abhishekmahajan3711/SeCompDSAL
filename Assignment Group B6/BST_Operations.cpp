// Beginning with an empty binary search tree, Construct binary search tree by inserting 
// the values in the order given. After constructing a binary tree -
// i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data 
// value found in the tree, iv. Change a tree so that the roles of the left and right pointers 
// are swapped at every node, v. Search a value

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

/*for creating or insertng the node */
node *insert(node *root, int val)
{

    if (root == NULL)
    {
        return new node(val);
    }
    if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        root->left = insert(root->left, val);
    }

    return root;
}

/*for searching the key value in tree*/
bool search(node *root, int key)
{

    if (root == NULL)
    {
        return false;
    }
    if (key == root->data)
    {
        return true;
    }
    if (key > root->data)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

/*finding the node with minimun value*/
node *lowest_value(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

/*displayin of tree with help of inorder traversal*/
void inorder_traversal(node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder_traversal(root->left);
    cout << root->data << ", ";
    inorder_traversal(root->right);
}

/*total number of nodes in the longest paht may right or left*/
void nodes_longest_path(node *root, int cr, int lr)
{

    node *left_node = root;
    while (left_node != NULL)
    {
        lr++;
        left_node = left_node->left;
    }
    node *right_node = root;

    while (right_node != NULL)
    {
        cr++;
        right_node = right_node->right;
    }

    if (cr > lr)
    {
        cout << "Right path is longest and no. of nodes are " << cr;
        cout << endl;
    }
    else
    {
        cout << "Left path is longest and no. of nodes are " << lr;
        cout<<endl;
    }
}

/*making mirror of the tree by swapping of the numbers */
void mirror(node *root)
{
    if (root)
    {
        mirror(root->left);
        mirror(root->right);

        node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    else
    {
        return;
    }
}

/*main funciton */
int main()
{
    cout << "\nLet's create a new binary search tree " << endl;
    cout << "Enter the value of root node : ";
    int r;
    cin >> r;
    node *root = NULL;
    root = insert(root, r);
    cout << "Root node creted successfully " << endl
         << endl;

    while (true)
    {
        cout<<endl<<endl;
        cout << "\t\t-----------------------MENU----------------------------" << endl;

        cout << "\tEnter 1 : To insert new node " << endl;
        cout << "\tEnter 2 : Find number of nodes in longest path from root " << endl;
        cout << "\tEnter 3 : Minimum of data value found in tree " << endl;
        cout << "\tEnter 4 : Change a tree so that the roles of th left and right pointers are swapped at every node  " << endl;
        cout << "\tEnter 5 : Search a value " << endl;
        cout << "\tEnter 6 : To exit" << endl;

        int c;
        cout << "\tEnter your choice : ";
        cin >> c;

        switch (c)
        {
        case 1:
            int v;
            cout << "Enter value for new node : ";
            cin >> v;
            insert(root, v);
            cout << "Node inserted " << endl;
            break;

        case 2:
            nodes_longest_path(root, 0, 0);
            
            break;

        case 3:
            cout << "Lowest value in the tree is = " << (lowest_value(root))->data << endl;
            break;

        case 4:
            cout << "Original tree inorder display : " << endl;
            inorder_traversal(root);
            cout << endl;
            cout << "Mirror tree inorder display : " << endl;
            inorder_traversal(root);
            cout << endl;
            break;

        case 5:
            cout << "Enter the value to be searched : ";
            int key;
            cin >> key;
            cout << endl;
            if (search(root, key))
            {
                cout << "Key found in the tree " << endl;
            }
            else
            {
                cout << "Key not found in the tree " << endl;
            }
            break;

        case 6:
            cout << "Program exit " << endl;
            exit(0);

        default:
           cout<<"Invalid choice "<<endl;
           break;
        }
    }
    return 0;
}
