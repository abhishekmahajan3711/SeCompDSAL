// Consider a scenario for Hospital to cater services to different kinds of patients as Serious 
// (top priority), b) non-serious (medium priority), c) General Checkup (Least priority). 
// Implement the priority queue to cater services to the patients.

#include<iostream>
using namespace std;
#define size 30

class PQueue{

   int r=-1;
   int f=-1;
   string pq[size];
   string priority[size];
   public:
      
   void enqueue(string name,string priority_name){
      
      //if full
      if(r==size-1){
        cout<<"Hospital overloaded";
      }
      else{
       
        if(r==-1 && f==-1){
           r=0;
           f=0;
           pq[r]=name;
           priority[r]=priority_name;
         
        }
        else{
          //if patient is serious
            if(priority_name=="serious"){
               if(priority[r]!="serious"){
                  int i=r;
                  while(priority[i]!="serious" && i!=-1){
                  
                    pq[i+1]=pq[i];
                    priority[i+1]=priority[i];
                    i--;
                  }
                  pq[i+1]=name;
                  priority[i+1]=priority_name;
                  r++;
                 
               }
               else{
                 r++;
                 pq[r]=name;
                 priority[r]=priority_name;
               }
            
          }
          //pateint is non-serious
          else if(priority_name=="non-serious"){
            if(priority[r]!="non-serious"){
                 int i=r;
                // while((priority[i]!="non-serious" || priority[i]!="checkup") && i!=-1){
                  while((priority[i]!="serious" && priority[i]!= "non-serious") && i!=-1){
                  pq[i+1]=pq[i];
                  priority[i+1]=priority[i];
                  i--;
                 }

                 pq[i+1]=name;
                 priority[i+1]=priority_name;
                 r++;
            }
            else{
              r++;
              pq[r]=name;
              priority[r]=priority_name;
            }
            
          }
          //noraml patient
          else{
                 r++;
                 pq[r]=name;
                 priority[r]=priority_name;
          }
        }
      }
      cout<<"patient added "<<endl;
      display();
   }

   void display(){

      for(int i=0;i<=r;i++){
        cout<<pq[i]<<" -> "<<priority[i]<<endl;
      }
   }

   void dequeue(){

     if(r==-1 && r==-1){
      cout<<"Queue is empty ";
     }
     else{
       for(int i=0;i<r;i++){
         pq[i]=pq[i+1];
         priority[i]=priority[i+1];
       }
       r--;
     }
     cout<<"Patient deleted "<<endl;
     display();
   }
   
   
};

int main(){
  int ch;
  int s;
  string name;
  string priority_name;
  char c;
  PQueue obj;
  do{
      cout<<"--------------------------HOSPITAL ENTRIES OPERATIONS--------------------------";
      cout<<"\n\tEnter 1: To add the patient";
      cout<<"\n\tEnter 2: To remove the patient";
      cout<<"\n\tEnter 3: Display list of patients";
      cout<<"\nEnter choice : ";
      cin>>ch;
      cout<<endl;

      if(ch==1){
           cout<<"Enter name of patient : ";
           cin>>name;
           cout<<endl;
           cout<<"Enter situation of patient accordingly : ";
           cout<<"\nEnter 1 : Serious ";
           cout<<"\nEnter 2 : Non-serious ";
           cout<<"\nEnter 3 : General Checkup ";
           cout<<"\nEnter number : ";
           cin>>s;
           if(s==1){
            priority_name="serious";
           }else if(s==2){
            priority_name="non-serious";
           }else{
            priority_name="checkup";
           }
           obj.enqueue(name,priority_name);
      }
      else if(ch==2){
        obj.dequeue();
      }
      else{
        obj.display();
      }
      cout<<"Do you want to continue?(y/n) : ";
      cin>>c;
  }while(c=='y');

  return 0;
}
