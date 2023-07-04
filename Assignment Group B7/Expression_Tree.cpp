// Construct an expression tree from the given prefix expression eg. +--a*bc/def and 
// traverse it using post order traversal (non recursive) and then delete the entire tree

#include <iostream>
#include <stack>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
};

node* createNode(char value){
    node* temp=new node;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

}

node* createTree(string expression){
    stack<node*>st;
    int len=expression.length();

    for(int i=len-1;i>=0;i--){
     
         char a=expression[i];

         if(isdigit(a) || isalpha(a)){
             node* New=createNode(a);
             st.push(New);
         }else{
            node* New=createNode(a);
            New->left=st.top();
            st.pop();
            New->right=st.top();
            st.pop();
            st.push(New);
         
         }
    }
    return st.top();
}

void PostOrder(node* root){
    stack<node*>s1;
    stack<node*>s2;
     
    if(root!=NULL){
        s1.push(root);
    }
      
    while(!s1.empty()){
        
        root = s1.top();
        s1.pop();
        s2.push(root);
        
        if(root->left!=NULL){
            s1.push(root->left);
        }
        if(root->right!=NULL){
            s1.push(root->right);
        }
    }
 
    int s=s2.size();
    node* temp=NULL;
    for(int i=0;i<s;i++){
     
         temp=s2.top();
         cout<<temp->data<<" ";
         s2.pop();

    }
}

void deleteTree(node* root){
    if(root==NULL)
      return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){

    string s;
    cout<<endl;
    cout<<"\tEnter the expression : ";
    getline(cin,s);
    cout<<"\n\tCreating the tree....................";
    node* startNode=createTree(s);
    cout<<"\n\tTree created successfully !!!!!!!!!!!";
    cout<<"\n\n\tPost Order traversal of tree : ";
    PostOrder(startNode);
    cout<<"\n\n\tDeleteing the tree...................";
    deleteTree(startNode);
    cout<<"\n\tTree deleted successfully !!!!!!!!!!!"<<endl<<endl;
    


    return 0;
}