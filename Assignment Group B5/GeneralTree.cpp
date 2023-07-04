// A book consists of chapters, chapters consist of sections and sections consist of 
// subsections. Construct a tree and print the nodes. Find the time and space requirements 
// of your method. 


#include<iostream>
#include<string.h>
using namespace std;

struct node{
  string name;
  int count;
  struct node *next[10];
};


class tree{
   public:
     node* root=new node;

    void create(){
     //creating root node
      
      cout<<endl;
      cout<<"\tEnter the subject name : ";
      cin>>root->name;
      cout<<endl;
      cout<<"Enter the number of chapters : ";
      cin>>root->count;
      int nChapters=root->count;
      cout<<endl;

      //creating chapters
      for(int i=0;i<nChapters;i++){
       root->next[i]=new node;
       cout<<"Chapter "<<(i+1)<<" Name : ";
       cin>>root->next[i]->name;
       cout<<"Enter the number of sections : ";
       cin>>root->next[i]->count;
   
       
       //creating secitions
       
       int nSections=root->next[i]->count;

       for(int j=0;j<nSections;j++){
         root->next[i]->next[j]=new node;
         cout<<"Section "<<(j+1)<<" Name : ";
         cin>>root->next[i]->next[j]->name;
         
        }

       cout<<endl;
    }
   }



   void display(){

    cout<<endl;
    cout<<"Displaying...........";
    cout<<endl;
    cout<<"Subject name :"<<root->name;
    cout<<endl;
    cout<<endl;
    for(int i=0;i<(root->count);i++){

      cout<<"\tChahpter name: "<<root->next[i]->name;
      cout<<endl;

      for(int j=0;j<(root->next[i]->count);j++){
        cout<<"\t\tSection name : "<<root->next[i]->next[j]->name;
        cout<<endl;
      }
      cout<<endl;
    }

   }
};



int main(){

tree obj;
char d;
do{

  cout<<endl<<endl;
  cout<<"\t_______________________________MENU_________________________________"<<endl;
  cout<<"\t\tEnter 1 : For Creating Chapters and Sections "<<endl;
  cout<<"\t\tEnter 2 : For Displaying Chapters and Sections ";
  cout<<endl<<endl;
  cout<<"\tEnter your choice : ";
  int n;
  cin>>n;

  if(n==1){
    obj.create();
  }else if(n==2){
    obj.display();
  }
  
  cout<<endl<<endl;
  cout<<"Do you want to continue(y/n) ? : ";
 
  cin>>d;

}while(d=='y');

exit(0);

return 0;
}