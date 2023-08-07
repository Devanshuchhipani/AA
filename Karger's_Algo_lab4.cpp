#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 4

void karger_mincut(int G[n][n])
{
    
    
    int n1 = n;
    
    int G3[n1][n1]={0};
    while( n1 > 2)
    {
    //1
    
        int G1[n1][n1] = {0};
        int u, v;
        cout << "Enter Edge : ";
        cin >> u >> v;
        u--;
        v--;
        //2
        for(int i = 0 ; i< n1  ; i++)
        {
            for(int j = i + 1 ; j< n1  ; j++)
            {
                int count =0;
                        
                if ( i == u && j ==v)
                {
                    G1[i][j] = G1[j][i]=0;
                }
                else if ( i ==u || i ==v)
                {
                    if(G[u][j] > 0)
                    {
                        count += G[u][j];
                    }
                    if(G[v][j] > 0)
                    {
                        count += G[v][j];
                    }
                    if(u<j)
                      G1[u][j]=count;
                    else
                      G1[j][u]=count;
                    
                    if(v<j)
                      G1[v][j]=count;
                    else
                      G1[j][v]=count;
                    
                    //G1[u][j] = G1[v][j] = count;
                }
                else if ( j == u || j ==v)
                {
                    if(G[u][i] > 0)
                    {
                        count += G[u][i];
                    }
                    if(G[v][i] > 0)
                    {
                        count += G[v][i];
                    }
                    
                    if(i<u)
                      G1[i][u]=count;
                    else
                      G1[u][i]=count;
                    
                    if(i<v)
                      G1[i][v]=count;
                    else
                      G1[v][i]=count;
                    
                //    G1[i][u] = G1[i][v] = count;
                }
                else
                {
                    G1[i][j] = G[i][j];
                }
                
                
                //cout << G[i][j] << " ";
            }
            //cout << endl;
        }
        
        //3
        for(int i =0; i< n1 ; i++)
        {
            for(int j =0; j< n1 ; j++)
            {
                if( i>= j)
                {
                    G1[i][j] = G1[j][i];
                    
                }
            }
        }    
        
        //4
        int G2[n1-1][n1-1] = {0};
        int r = 0 , c=0;
        for(int i =0; i< n1 ; i++)
        {
            c=0;
            if (i ==v)
                continue;
                
            for(int j =0; j< n1 ; j++)
            {
                if (j ==v )
                    continue;
                
                G2[r][c] = G1[i][j];
                c++;
            
                
            }
            r++;
        }
        
        // clear G
        
        for(int i =0; i< n ; i++)
        {
            for(int j =0; j< n ; j++)
            {
               G[i][j] = 0;
               G3[i][j] = G2[i][j];
            }
        }
        
        //cout<<"g \n";
        for(int i =0; i< n1-1 ; i++)
        {
            for(int j =0; j< n1-1 ; j++)
            {
                G[i][j] = G2[i][j];
                //cout << G[i][j] << " " ;
                
            }
            //cout << endl;
        }
        
        n1 = n1 - 1;
        
    }
    
    cout << "cut value : " << G[0][1]  << endl << "G : \n"; 
    
    for(int i =0; i< n ; i++)
    {
        for(int j =0; j< n ; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << "G2 : " << endl;
    for(int i =0; i< n1 ; i++)
    {
        for(int j =0; j< n1 ; j++)
        {
            cout << G3[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int G[n][n] = { {0,1,1,1},
                    {1,0,0,1},
                    {1,0,0,1},
                    {1,1,1,0}
                    };
    
    karger_mincut(G);
    
    return 0;
}


