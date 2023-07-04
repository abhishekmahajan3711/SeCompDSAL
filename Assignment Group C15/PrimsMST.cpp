// You have a business with several offices; you want to lease phone lines to connect them 
// up with each other; and the phone company charges different amounts of money to 
// connect different pairs of cities. You want a set of lines that connects all your offices 
// with a minimum total cost. Solve the problem by suggesting appropriate data structures.

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter total no. of nodes : ";
    cin>>n;

    //initializing arrays
    //adjancey matrix which stores the wieghts 
    int weight[n][n];
    //matrix to store parent 
    int parent[n];
    //to keep watch on visited or not
    bool visited[n];
    //to store cost
    int cost[n];

    //nodes will be named as 0,1,2,3_____
    //it will help in to go according to indexing
    //initalizing the arrays
    for(int i=0;i<n;i++){
        parent[i]=-1;
        visited[i]=false;
        cost[i]=9999;
        for(int j=0;j<n;j++){
            weight[i][j]=40000;
        }
    }

    //accepting the values 
    int x,y,w;
    char a;
    do{
        cout<<endl;
        cout<<"\nEnter the edge's node 1 : ";
        cin>>x;
        cout<<"\nEnter the edge's node 2 : ";
        cin>>y;
        cout<<"\nEnter the weight between both : ";
        cin>>w;
        weight[x][y]=weight[y][x]=w;
        cout<<"\nDo you want to add one more edge(y/n)? : ";
        cin>>a;
    }while(a=='y');

    int TotalCost=0;
   

    //making first node i.e. 0 as cost 0 
    cost[0]=0;
    
    for(int k=0;k<n;k++){
        //find minimum cost node and unvisited node
        //cout<<endl<<endl<<endl<<"Next itereation"<<endl;
        int min=999;
        int currNode;
        for(int p=0;p<n;p++){
           if(cost[p]<min && visited[p]==false){
            min=cost[p];
            currNode=p;
            // cout<<"currNode"<<currNode<<endl;
            // cout<<"Cost of CurrN"<<cost[p];
           }
        }

        //mark that node as visited
        visited[currNode]=true;
        //add its cost to total cost
        TotalCost=TotalCost+cost[currNode];
        // cout<<"Total cost "<<TotalCost<<endl;

        //traverse through current nodes adjancent nodes
        for(int h=0;h<n;h++){
           
           //if that node is not visited and its wieght is from current node is less than the cost then update it
           if(visited[h]==false && weight[currNode][h]<cost[h]){
              cost[h]=weight[currNode][h];
            //   cout<<"cost[h]"<<cost[h]<<"weight[currNode][h]"<<weight[currNode][h]<<endl;
              //make current Node as parent of this node
              parent[h]=currNode;
           }
        }
    }

    cout<<"\n\tMinimum Cost is : "<<TotalCost;
    return 0;
}
