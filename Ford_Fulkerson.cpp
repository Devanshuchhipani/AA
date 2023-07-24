

#include <iostream>
#include <queue>
#include <climits>
using namespace std;
#define n  6 

 
bool bfs(int rgraph[ n][ n], int s , int t, int parent[n])
{
    int visited[n]={0};
    
    queue<int> q;
    
    q.push(s);
    
    visited[s]=1;
    
    parent[s] = -1;
    
    while( !q.empty())
    {
        //u = deque(q); 
        int u = q.front() ;
        q.pop() ;
        
        for(int v=0; v<n ; v++)
        {
            if (visited[v] == 0 && rgraph[u][v]>0)
            {
                if(v ==t )
                {
                    parent[v]=u;
                    return true;
                }
                
                q.push(v);
                visited[v] =1;
                parent[v] = u ;
            }
        }
    }
    return false;
}

int ford_fulkerson(int G[n][n], int s , int t )
{
    int rgraph[n][n];
    
    for(int u =0; u<n ; u++)
    {
        for (int v = 0; v<n ; v++)
        {
            rgraph[u][v] = G[u][v];
        }
    }
    
    int Max_flow = 0;
    int parent[n];
    
    while( bfs(rgraph, s , t, parent))
    {
        int path_flow = INT_MAX;
        int u ;
        for(int v = t; v!= s ; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow,rgraph[u][v]);
        }
        for(int v = t; v!= s ; v = parent[v])
        {
             u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        Max_flow += path_flow;
    }
    return Max_flow;
}

int main()
{
    //int n =6;
    int G[6][6] = {
        {0,16,13,0,0,0},
        {0,0,10,12,0,0},
        {0,4,0,0,14,0},
        {0,0,9,0,0,20},
        {0,0,0,7,0,4},
        {0,0,0,0,0,0},
    };
    
    int ans = ford_fulkerson(G,0,5);
    
    cout << ans << endl;

    return 0;
}


