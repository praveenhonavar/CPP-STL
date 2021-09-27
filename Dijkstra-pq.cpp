#include<iostream>
#include<queue>
#include<list>

using namespace std;

typedef pair<int,int> iPair; 

list<pair<int,int>> *l;   // adjency list pointer

class Edges{

  public:
    void addEdges(int u,int v,int w){
      l[u].push_back(make_pair(v,w));
      l[v].push_back(make_pair(u,w));
    }
};


class Topology{

  public:

    int ver;
    int i=0;

    Topology(int V){
      ver=V;
      l = new list<pair<int,int>>[ver];
    };

   void shortestPath(int u);


};


void Topology :: shortestPath(int u){

      // priority_queue<int> pq;

      //min pq;
      priority_queue<iPair, vector<iPair>,greater<iPair>> pq;

      vector<int> dist(ver,999);

      pq.push(make_pair(0,u));

      dist[u]=0;

      while(!pq.empty()){
        
        int u = pq.top().second;

        pq.pop();

        list<pair<int,int>>:: iterator i;


        for(i = l[u].begin(); i!= l[u].end() ;i++){
          
          int v = (*i).first;
          int w  = (*i).second;

          if(dist[v] > dist[u]+w){

              dist[v] = dist[u]+w;

              pq.push(make_pair(dist[v],v));

          }
        }
      }

      for(int j=0;j<ver;j++){
        cout<<dist[j]<<endl;
      }


}

int main(){

  // priority_queue<int> pq;

  // pq.push(10);
  // pq.push(20);
  // pq.push(30);

  // cout<<pq.top();

  Topology t(5);
  Edges e;

  // e.addEdges(0, 1, 5);
  // e.addEdges(1, 2, 4);
  // e.addEdges(0, 2, 3);
  // e.addEdges(2, 3, 2);

  e.addEdges(0,1,3);

  e.addEdges(0,2,1);

  e.addEdges(1,2,7);

  e.addEdges(1,3,5);

  e.addEdges(1,4,1);

  e.addEdges(3,4,7);

  e.addEdges(2,3,2);

  t.shortestPath(0);




}
