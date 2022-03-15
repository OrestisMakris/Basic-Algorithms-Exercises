#include<iostream>
#include<list>
#include<iterator>

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
   graph[v].push_back(u);
}

void BFS(list<int> graph[],int s , int V )
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;

    int level[V]; // create a array for counting levels 

    level[s] = 0; // intialize the level array from begining vertex
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = graph[s].begin(); i != graph[s].end(); ++i)
        {
             cout << "Level " << *i << endl;
            if (!visited[*i])
            {
                 level[*i] = level[s] + 1;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    
    for(int i = 1; i < V; i++) {
            if(!visited[i]){ //if there is a node, not visited by bfs, graph is not connected
                cout << "The graph is not connected "<< endl;
            exit(0);
            }

        }cout << "The graph is connected "<< endl;

    cout << "Nodes"
         << "    "
         << "Level" << endl;
    for (int i =1 ; i < V; i++)
        cout << " " << i << "   -->   " << level[i] << endl;

    // for (int i =1 ; i < V; i++)
    // {
    //     cout<<"Level" << level[i] << endl;
    //     for(int j =1; j<level[i]; j++)
    //      cout<<j << endl;
    
    // }

}

main(int argc, char* argv[]) 
{
   int v = 9;    //number of vertices in graph +1
   //create an array of lists whose size is v
   int x =0; // starting vertex
   list<int> graph[v];
   insert_edge(graph, 1, 2);
   insert_edge(graph, 1, 3);
   insert_edge(graph, 2, 3);
   insert_edge(graph, 2, 4);
   insert_edge(graph, 2, 5);
   insert_edge(graph, 3, 7);
   insert_edge(graph, 3, 8);
   insert_edge(graph, 3, 5);
   insert_edge(graph, 4, 5);
   insert_edge(graph, 5, 6);
   insert_edge(graph, 7, 8);

   displayGraph(graph, v);

   cout<<"Enter the Vertex you want to start implementing the BFS algorithm"<<endl;
   //cin >> x;
   BFS(graph,1,v);
   
}