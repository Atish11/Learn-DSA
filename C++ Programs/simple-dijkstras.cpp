#include <iostream>

#define INFINITY 999999
#define V 10

using namespace std;

void dijkstras(int graph[V][V], int n);
int findminvertex(int distance[], bool visited[], int n);

int main(){
	int graph[V][V], i, j, n;
	
	cout<<"Enter num of vertices (Max 10): ";
	cin>>n;
	
	cout<<endl<<"Enter the graph represented as an adjacency matrix: ";
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cout<<endl<<"Enter ["<<i<<"]["<<j<<"] element: ";
			cin>>graph[i][j];
		}
	}
	
	dijkstras(graph, n);
	return 0;
}


void dijkstras(int graph[V][V], int n){
	int distance[V]; // array to hold the distance from origin to the
					// n th vertex.
	bool visited[V]; // array to find if the particular vertex is
						// visited already or not
	
	// since we have not visited any one let us intialize the
		//distacne[] and visited[] array.
	for(int i=0; i<n ; i++){
		distance[i] = INFINITY;
		visited[i] = false;
	}
	
	//since vertex 0 is start vertex and we know its distance is 0 so;
	distance[0] = 0;
	
	
	for(int i=0; i<n-1; i++) // we are not checking from 0 to last
	// vertext, for last vertex
	// we not need to visit its neighbour becoz when we reach the
	// last vertex it is obvious that
	// all its neighbour would already had been visited.
	{
		//we need to find the minimum vertex here.
		int minvertex = findminvertex(distance, visited, n);
		// passing address of distance and visited arrays along with n
		
		//since we got the minvertex , we need to mark this vertex as
		// visited.
		visited[minvertex] = true;
		
		//now since i have minvertex, i need to explore all neighbours
		for(int j=0; j<n; j++){
			//check if the vertex that we are checking is the neighbour
			// of the i vertex;
			if(graph[minvertex][j] != 0) // checking if there is
			// the edge from minvertex to j;
			{
				if(!visited[j]){ //now checking if this neighbour is
				// not visited.
					//now lets caluclate the distacne of this
					// neighboutr from the minvertex.
					int dist = distance[minvertex] + graph[minvertex][j];
					// adding the distacne from source to minvertex and
					//the current cost of this edge.
					
					//now lets check if this recently calculated
					// distacne is a better option for j or not.
					// better mens this should be less than the
					// previously stored distacne.
					if(dist < distance[j]){
						//if this is really better option then lets update the distance[j];
						distance[j] = dist;
					}
				}
			}
		}
	}
	
	//done, lets print results.
	cout<<endl<<endl<<"Vertex\t\tDistance"<<endl;
	for(int i=0; i<n; i++){
		cout<<i<<"\t\t\t"<<distance[i]<<endl;
	}
}


int findminvertex(int distance[], bool visited[], int n){
	//since at first we dont know what the minvertex is, lets make it -1;
	int minvertex = -1;
	
	// lets scan all distacne arraays that are not visited prior,
	//and find the minimum one.
	for(int i=0; i<n; i++){
		if(!visited[i]){ // if not visited previously;
			if((distance[i] < distance[minvertex]) || (minvertex == -1)){ // if the new distacne is less than the minvertex distance
			// here since you know at first minvertex = -1 which triggers array out of bounds error, so for that first time we need a condition to keep
			//the first unvisited vertex as minvertex hence we put if minvertex == -1 also in the if condition.
			minvertex = i; // update the minvertex with i
			}
		}
	}
	
	return minvertex;
}
