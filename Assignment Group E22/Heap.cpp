// Read the marks obtained by students of second year in an online examination of 
// particular subject. Find out maximum and minimum marks obtained in that subject. Use 
// heap data structure. Analyze the algorithm.

#include<iostream>
using namespace std;


class Heap{
    public:
     
     void Max_heapify(int a[],int i,int n){
        int l,r,largest;
        l=2*i;
        r=2*i+1;
        if(l<=n && a[l]>a[i]){
            largest=l;
        }else{
            largest=i;
        }
        if(r<=n && a[r]>a[largest]){
            largest=r;
        }
        if(largest!=i){
            int temp=a[largest];
            a[largest]=a[i];
            a[i]=temp;
            Max_heapify(a,largest,n);
        }

     }
     void Build_heap(int a[],int n){
        for(int k=n/2;k>=1;k--){
            Max_heapify(a,k,n);
        }
     }
     void HeapSort(int a[],int n){
        Build_heap(a,n);
        for(int i=n;i>=2;i--){
            swap(a[i],a[1]);
            Max_heapify(a,1,i-1);
        }
     }
     void accept(){
        int n;
        cout<<"Enter total number of students : ";
        cin>>n;
        int a[n+1];
        for(int i=1;i<n+1;i++){
            cout<<"\nEnter the student marks : ";
            cin>>a[i];
        }
        HeapSort(a,n);
        display(a,n);

     }
     void display(int a[],int n){
        cout<<"\n\nMaximum marks is : "<<a[n];
        cout<<"\nMinimum marks is : "<<a[1];

     }
};

int main(){
    Heap obj;
    obj.accept();
    return 0;
}