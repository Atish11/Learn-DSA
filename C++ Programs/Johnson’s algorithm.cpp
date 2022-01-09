#include<iostream>
#define INF 9999
using namespace std;
int min(int a, int b);
int cost[10][10], adj[10][10];
inline int min(int a, int b){
   return (a<b)?a:b;
}
main() {
   int vert, edge, i, j, k, c;
   cout << "Enter no of vertices: ";
   cin >> vert;
   cout << "Enter no of edges: ";
   cin >> edge;
   cout << "Enter the EDGE Costs:\n";
   for (k = 1; k <= edge; k++) { 
      cin >> i >> j >> c;
      adj[i][j] = cost[i][j] = c;
   }
   for (i = 1; i <= vert; i++)
      for (j = 1; j <= vert; j++) {
         if (adj[i][j] == 0 && i != j)
            adj[i][j] = INF; 
      }
   for (k = 1; k <= vert; k++)
      for (i = 1; i <= vert; i++)
         for (j = 1; j <= vert; j++)
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); 
   cout << "Resultant adj matrix\n";
   for (i = 1; i <= vert; i++) {
      for (j = 1; j <= vert; j++) {
            if (adj[i][j] != INF)
               cout << adj[i][j] << " ";
      }
      cout << "\n";
   }
}


//List ADT Type Definitions 
typedef struct node 
{ 
 void *DataPtr; 
 struct node *link; 
} Node; 
typedef struct
{ 
 int count; 
 Node *pos; 
 Node *head; 
 Node *rear; 
 int (*compare) (void *argument1, void *argument2) 
} LIST;  


//Stack ADT Type Definitions 
typedef struct node 
{ 
 void *DataPtr; 
 struct node *link; 
} StackNode; 
typedef struct
{ 
 int count; 
 StackNode *top; 
} STACK; 


//Queue ADT Type Definitions 
typedef struct node 
{ 
 void *DataPtr; 
 struct node *next; 
} QueueNode; 
typedef struct 
{ 
 QueueNode *front; 
 QueueNode *rear; 
 int count; 
} QUEUE; 







