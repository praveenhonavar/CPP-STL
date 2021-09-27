#include <iostream>
#include<list>
#include<queue>
#include<array>

using namespace std;

int ver;
int src,des;

typedef pair<int,int> iPair;

list<pair<int,int>> *l;


class Edge{

  public:
    void addEdge(int u,int v,int w){

      l[u].push_back(make_pair(v,w));
      l[v].push_back(make_pair(u,w));

    }

};

class Topology : Edge{

  public:
    Topology(int V){
      ver=V;

      l = new list<pair<int,int>>[ver];

      readFile();

    }

  void readFile(){
    
    Edge e;

    e.addEdge(0,1,3);
    e.addEdge(0,2,1);
    e.addEdge(1,2,7);
    e.addEdge(1,3,5);
    e.addEdge(1,4,1);
    e.addEdge(3,4,7);
    e.addEdge(2,3,2);


    // e.addEdge(0,1,5);
    // e.addEdge(0,2,3);
    // e.addEdge(1,2,4);
    // e.addEdge(2,3,2);
    
  }

};

class InputFromUser{
  public:
    void readInput(){
      cout<<"Enter Source"<<endl;
      cin>>src;
      cout<<"Enter Destination"<<endl;
      cin>>des;
    }

};

class Output{
  public:
    void printAllWeights(vector<int> d){
      for(int i=0;i<ver;i++){
        cout<<src<<"->"<<i<<"="<<d[i]<<endl;
      }
    }

    void printWeight(vector<int> d){

      cout<<"-------------------------------"<<endl;

      int i=0;
      while(i != des){
        i++;
        continue;
      }
      cout<<src<<"->"<<des<<"="<<d[i]<<endl;
    }

    void printRoutes(vector<int> r){
      cout<<"yooo"<<endl;
      // for(int p=0;p<ver;p++){
      //   int val = r[p];

      //   while(val != src){
      //     cout<<val<<endl;
      //     val=r[val];
      //   }

      //   cout<<val;

      // }

      for(int i=0;i<ver;i++){
        cout<<r[i]<<endl;
      }



    }

};

class ShortestPath : Output{
  
  public:


    void computeShortestPath(int u){

        priority_queue<iPair,vector<iPair>,greater<iPair>> pq;

        vector<int> dist(ver,999);

        vector<int> path(ver);

        dist[src] = 0;

        pq.push(make_pair(0,src));

        while(!pq.empty()){

          int u = pq.top().second;

          pq.pop();

          list<pair<int,int>>::iterator i;

          for(i = l[u].begin();i!=l[u].end();i++){

            int v = (*i).first;
            int w = (*i).second;

            if(dist[v] > dist[u] + w){

              dist[v] = dist[u] + w;

              path[v] = u;

              pq.push(make_pair(dist[v],v));
            }

          }
        }

        Output pathObj;

        pathObj.printAllWeights(dist);

        pathObj.printWeight(dist);

        pathObj.printRoutes(path);

      
    }
  

};




int main(){
  
  Topology t(5);

  InputFromUser i;

  i.readInput();

  ShortestPath sp;

  sp.computeShortestPath(src);



}


