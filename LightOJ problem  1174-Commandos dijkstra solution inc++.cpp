
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
int dist[105];
vector<pair<int,int>>graph[105];
void dijkstra(int src)
{
    for(int i=0; i<105; i++)dist[i]=inf;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        int curnod=pq.top().second;
        int curdis=pq.top().first;
        pq.pop();
        if(dist[curnod]<curdis)
            continue;

        for(auto child:graph[curnod])
        {
            if(dist[child.first]>curdis+child.second)
            {
                dist[child.first]=curdis+child.second;
                pq.push({dist[child.first],child.first});
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {

        int n,m;
        cin>>n>>m;
        int ans=0;
        for(int i=0; i<105; i++)graph[i].clear();
        int dist2[105];
        for(int i=0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].push_back({b,1});
            graph[b].push_back({a,1});
        }
        int s,d;
        cin>>s>>d;
        dijkstra(s);
        for(int i=0; i<105; i++)dist2[i]=dist[i];
        dijkstra(d);
        for(int i=0; i<n; i++)
        {
            ans=max(ans,dist2[i]+dist[i]);
        }
        printf("Case %d: ",k);
        cout<<ans<<endl;
    }


}
