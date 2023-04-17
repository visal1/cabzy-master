#include <iostream>
#include <vector>
#include <queue>
#include "cabinfo.h"

using namespace std;

int INT_MAX;

//function for shortest path
vector<int> dijkstra(vector<vector<pair<int,int> > > graph, int start)
{
    vector<int> dist(graph.size(), INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;


    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

//function to add edge
void addEdge(vector<vector<pair<int,int> > >& graph, int u, int v, float w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

//function to find distance for 1 destination
int shortest(vector<vector<pair<int,int> > > graph,int sectors[],int l,int d)
{
    int a,b;
    for(int i=0;i<24;i++)
    {
      if(sectors[i]==l)
            a=i;
      if(sectors[i]==d)
            b=i;
    }
    
    vector<int> dist = dijkstra(graph, a);

    
    return dist[b];

    /*cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < 24 ; ++i)
        cout << i << "\t\t" << dist[i] << endl;*/
}

//function to find distance during pool for 2 or 3 people
int shortest_pool(vector<vector<pair<int,int> > > graph,int sectors[],int s,int e, int m, int n, int people)
{
    int a, b, c, d;
    int ans = INT_MAX;

    for(int i=0;i<24;i++)
    {
      if(sectors[i]==s)
            a=i;
      if(sectors[i]==e)
            b=i;
      if(sectors[i]==m)
            c=i; 
      if(sectors[i]==n)
            d=i; 
    }

    vector<int> dist1 = dijkstra(graph, a);
    vector<int> dist2 = dijkstra(graph, b);
    vector<int> dist3 = dijkstra(graph, c);

    if(people == 3)
    {
    	vector<int> dist4 = dijkstra(graph, d);

		ans = min(ans, dist1[b] + dist2[c] + dist3[d]);
    	ans = min(ans, dist1[b] + dist2[d] + dist4[c]);
    	ans = min(ans, dist1[c] + dist3[b] + dist2[d]);
    	ans = min(ans, dist1[c] + dist3[d] + dist4[b]);
    	ans = min(ans, dist1[d] + dist4[b] + dist2[c]);
    	ans = min(ans, dist1[d] + dist4[c] + dist3[b]);
    }

    if(people == 2)
    {
    	ans = min(ans, dist1[b] + dist2[c]);
    	ans = min(ans, dist1[c] + dist1[b]);
    }

    return ans;
}

//function for pre-defined sectors
void sectors(vector<vector<pair<int,int> > > &graph)
{
    int sectors[24] = {6,8,12,16,18,22,25,27,30,32,34,35,
                       36,37,44,49,57,59,61,62,76,100,126,128};

    addEdge(graph, 0, 1, 1.3);
    addEdge(graph, 1, 2, 1.6);
    addEdge(graph, 2, 5, 1.8);
    addEdge(graph, 4, 3, 1.8);
    addEdge(graph, 4, 7, 1.6);
    addEdge(graph, 4, 13, 3.6);
    addEdge(graph, 5, 4, 4.9);
    addEdge(graph, 5, 16, 1.2);
    addEdge(graph, 6, 9, 2.2);
    addEdge(graph, 7, 4, 1.8);
    addEdge(graph, 7, 6, 2.0);
    addEdge(graph, 7, 8, 2.0);
    addEdge(graph, 8, 12, 1.9);
    addEdge(graph, 9, 11, 2.5);
    addEdge(graph, 11, 15, 3.2);
    addEdge(graph, 12, 13, 2.6);
    addEdge(graph, 14, 4, 4.3);
    addEdge(graph, 16, 17, 1.9);
    addEdge(graph, 17, 19, 2.9);
    addEdge(graph, 17, 18, 2.9);
    addEdge(graph, 17, 20, 5.1);
    addEdge(graph, 18, 5, 2.7);
    addEdge(graph, 18, 7, 6.0);
    addEdge(graph, 18, 10, 2.6);
    addEdge(graph, 20, 21, 4.5);
    addEdge(graph, 21, 23, 4.6);
    addEdge(graph, 22, 14, 5.8);
    addEdge(graph, 23, 22, 4.1);
}

int getrandomdigit()
{
    return rand() % 10;
}

//calculate fare, rupees 50 as basic fare
float fare(int dis)
{
    float f = 0;
    float rate = (getrandomdigit()+1)*10+getrandomdigit();
    f = 50 + dis*rate;
	return f;

}

//function for single customer
void single_ride(vector<vector<pair<int,int> > > &graph)
{
    int sectors[24] = {6,8,12,16,18,22,25,27,30,32,34,35,
                       36,37,44,49,57,59,61,62,76,100,126,128};

    cout<<"Enter your location"<<endl;
    int l;
    cin>>l;
    cout<<"Enter your destination"<<endl;
    int d;
    cin>>d;
    int x = shortest(graph,sectors,l,d);
    cout<<"Distance(km) "<<x;

    cout<<"Total fare to be paid :: "<<fare(x)<<endl;
}

//function for pool customers
void pool_ride(vector<vector<pair<int,int> > > &graph, int people)
{
    int sectors[24] = {6,8,12,16,18,22,25,27,30,32,34,35,
                       36,37,44,49,57,59,61,62,76,100,126,128};

    int l, d, a, b=0;

    cout<<"Enter your location"<<endl;
    cin>>l;
    cout<<"Enter destination 1"<<endl;
    cin>>d;
    cout<<"Enter destination 2"<<endl;
    cin>>a;
    if(people == 3)
    {cout<<"Enter destination 3"<<endl;
    cin>>b;}
    int x = shortest_pool(graph, sectors, l, d, a, b, people);
    cout<<"Distance(km) "<<x<<endl;

    cout<<"Total fare to be paid :: "<<fare(x)<<endl;
}

//helper function to find number of passenger
void ride(vector<vector<pair<int,int> > > &graph, int people)
{
    if(people == 1)
        single_ride(graph);
    else
        pool_ride(graph, people);

}


//function for number of destinations input
int total_des()
{
	int p;

	cout<<"Enter number of destinations (max 3):: ";
	cin>>p;
	return p;
}



//main function
int booking()
{
    vector<vector<pair<int,int> > > graph(24, vector<pair<int,int> >(24));

    sectors(graph);

   	int p = total_des();

    ride(graph, p);

    info();

    return 0;
}