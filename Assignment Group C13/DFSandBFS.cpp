// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
// list to perform BFS. Use the map of the area around the college as the graph. Identify 
// the prominent land marks as nodes and perform DFS and BFS on that.

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class Graph
{

    int vertices;

public:
    vector<list<int>> v;

    Graph(int n)
    {
        this->vertices = n;
        v.resize(n);
    }

    void addedge(int x, int y)
    {
        v[x].push_back(y);
        v[y].push_back(x);
    }

    void print_adj_list()
    {
        cout<<endl;
        for (int i = 0; i < v.size(); i++)
        {

            cout << "Vertex " << i << " -> ";
            for (int x : v[i])
            {

                cout << x << " ";
            }
            cout << endl;
        }
    }

    void dfs(int start)
    {
        vector<bool> visited(vertices, false);
        stack<int> st;

        st.push(start);
        visited[start] = true;

        while (!st.empty())
        {
            int vn = st.top();
            st.pop();
            cout << vn << " ";

            for (int i : v[vn])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    st.push(i);
                }
            }
        }
    }

    void bfs(int start)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {

            int a = q.front();
            q.pop();
            cout << a << " ";

            for (int i : v[a])
            {

                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{

    int v,e;

    cout << endl;
    cout << "\tEnter number of nodes/vertices of the graph : ";

    cin >> v;
    Graph obj(v);
    cout << "Enter the number of edges of the graph : ";
    cin>>e;
    cout<<endl;
    for (int i = 0; i < e; i++)
    {
        int x,y;
        cout << "\nFor edge " << i + 1<<": ";
        cout<<"Enter first vertex of edge :";
        cin >> x ;
        cout<<"\t    Enter last vertex of edge :";
        cin >> y;
        obj.addedge(x, y);
    }
    
    cout<<endl<<endl<<"\t-------------------Adjancey List------------------";
    obj.print_adj_list();
    
    cout<<endl<<"\t--------------DFS(Depth First Search)-------------"<<endl;
    obj.dfs(0);
    cout<<endl<<endl<<"\t-------------BFS(Breadth First Search)------------"<<endl;
    obj.bfs(0);

    return 0;
}