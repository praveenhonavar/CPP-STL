#include <iostream>
#include<list>
#include<map>
#include<queue>
#include<array>

#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int ver;
string src,des;

typedef pair<int,string> iPair;

map<string,list<pair<string,int>>> l;

class Edge{

  public:
  void readFile(){
     
  //  addEdge("a","b",3);
  //  addEdge("a","c",1);
  //  addEdge("b","c",7);
  //  addEdge("b","d",5);
  //  addEdge("b","e",1);
  //  addEdge("c","d",2);
  //  addEdge("d","e",7);

ifstream infile("sn.txt");
//ifstream infile("sn1.txt");
//ifstream infile("sn2.txt");

	string line;
	while (getline(infile, line))
	{
    		istringstream iss(line);
    		string a, b;
    		int c;
    		if (!(iss >> a >> b >> c)) 
        { 
          break; 
        } // error
	  	cout<<endl<<a<<"  "<<b<<"  "<<c<<endl;
      addEdge(a,b,c);
    
	}

   
   ver=l.size();


    // e.addEdge(0,1,5);
    // e.addEdge(0,2,3);
    // e.addEdge(1,2,4);
    // e.addEdge(2,3,2);
   
}
 
    void addEdge(string u,string v,int w){

      l[u].push_back(make_pair(v,w));
      l[v].push_back(make_pair(u,w));

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
    void printAllWeights(map<string,int> d){
       
        for(auto p : d){
            cout<<src<<"-->"<<p.first<<"="<<p.second<<endl;
        }
    }

    void printWeight(map<string,int> d){

      cout<<"-------------------------------"<<endl;

      for(auto p : d){
         
        string city = p.first;
       
        if(city==des){
            cout<<src<<"-->"<<des<<"="<<d[city]<<endl;
        }
      }
     
     cout<<"-------------------------------"<<endl;

    //   while(i != des){
    //     i++;
    //     continue;
    //   }
    }

    void printRoutes(map<string,string> r){
       
    //  cout<<"yooo"<<endl;

    //   for(auto p : r){
    //         cout<<p.first<<"-->"<<p.second<<endl;
    //     }
       
        string k = des;
       
        while(k != src){
            cout<<k<<"-->";
            k=r[k];
        }
        cout<<src;
      }
};

class Topology : public Edge,public Output{

  public:
    Topology(){

 Edge e;

      e.readFile();

    }
void shortestPath(string u){

        priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
       
        map<string,int> dist;
       
        map<string,string> path;
       
        for(auto p: l){
           
            string city = p.first;
            //cout<<city<<endl;
            dist[city] = 999;
            //cout<<dist[city]<<endl;
           
        }
       
        //vector<string> path(ver);

        dist[src] = 0;

        pq.push(make_pair(0,src));

        while(!pq.empty()){

          string u = pq.top().second;
         
          pq.pop();

          list<pair<string,int>>::iterator i;

          for(i = l[u].begin();i!=l[u].end();i++){

            string v = (*i).first;
            int w = (*i).second;
           
            //cout<<"weight"<<w;
           
            if(dist[v] > dist[u] + w){

              dist[v] = dist[u] + w;

              path[v] = u;
             
              //cout<<dist[v]<<endl;

              pq.push(make_pair(dist[v],v));
            }
          }
        }
       
        printAllWeights(dist);

        printWeight(dist);

        printRoutes(path);
       
}
 
};

int main(){
 
  Topology t;
 
  InputFromUser i;

  i.readInput();

  t.shortestPath(src);

}