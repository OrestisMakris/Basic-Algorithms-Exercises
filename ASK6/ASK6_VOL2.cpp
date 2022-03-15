#include<iostream>
#include<list>
#include<iterator>
#include <vector>
using namespace std;

void displayGraph(list<int> graph[], int v)  // display the Graph
{
   for(int i = 1; i<v; i++) {
      cout << i << "--->";
      list<int> :: iterator it;
      for(it = graph[i].begin(); it != graph[i].end(); ++it) {
         cout << *it << " ";
      }
      cout << endl;
   }
}
void insert_edge(list<int> graph[], int u, int v)  //add vertices (u v), (v u)
{    
   graph[u].push_back(v);
}

void convertstructure(list<int> graph[], int v)  
{

     list<int> :: iterator it;
     int counter =0 ;
     vector<int> graphoutedges;
     int nodeoutedges[v];

     for(int i = 1; i<v; i++) {

         nodeoutedges[i] = counter;
         for(it = graph[i].begin(); it != graph[i].end(); ++it) {

        graphoutedges.push_back(*it);
        counter++;
      }
     }

     nodeoutedges[0]=graphoutedges.size()-1; 
     
     cout << "Nodeoutedges:"<< " ";
    for (int j = 0; j < v; j++) {
            cout << nodeoutedges[j] << " ";
    }cout << endl;
    cout << "Graphoutedges:"<< " ";
    for (int j = 0; j < graphoutedges.size(); j++) {
            cout << graphoutedges[j] << " ";
    }cout << endl;


}


main(int argc, char* argv[]) 
{
   int v = 9;    //number of vertices in graph +1
   //create an array of lists whose size is v
   list<int> graph[v];
   insert_edge(graph, 1, 2);
   insert_edge(graph, 1, 3);
   insert_edge(graph, 1, 4);
   insert_edge(graph, 1, 5);
   insert_edge(graph, 2, 3);
   insert_edge(graph, 3, 1);
   insert_edge(graph, 3, 5);
   insert_edge(graph, 4, 5);
   insert_edge(graph, 5, 2);
   insert_edge(graph, 6, 7);
   insert_edge(graph, 7, 8);
   insert_edge(graph, 8, 6);
   insert_edge(graph, 8, 7);
  
   displayGraph(graph, v);
   
   convertstructure(graph,v);
   
}