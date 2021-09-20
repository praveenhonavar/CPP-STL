#include iostream
#includelist

using namespace std;

class Graph{

  int V;
  listint l;
  public
  Graph(int V){
    this-V=V;
    l = new listint[V];
  };

  public
    void addEdge(int x,int y)
    {
      l[x].push_back(y);
      l[y].push_back(x);
    }

    void printGraph(){

      for(int i=0;iV;i++){
        for(int pl[i]){
          coutp;
        }
      }

    }
  

};



int main() {

  Graph g(3);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);

  g.printGraph();



}