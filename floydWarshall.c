#include<stdio.h> 
#define INF 99999


int V=6; int counter=1;
int G[6][6] = {{0,5,6,INF,INF,INF}, 
                        {5,0,8,3,4,INF}, 
                        {6,8,0,INF,6,INF}, 
                        {INF,3,INF,0,3,7},
                        {INF,4,6,3,0,7},
                        {INF,INF,INF,7,7,0}}; 
 int dist[6][6];


void disp() 
{ 
	counter++;
    printf ("The adjacency matrix after %d Iteration is: \n", counter); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            if (dist[i][j] == INF) 
                printf("%s  	", "INF"); 
            else
                printf ("%d 	 ", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 

void floyd_Warshall() 
{ 

    int i,j,k;
    for (i=0; i < V; i++) 
        for (j=0; j < V; j++) 
            dist[i][j] = G[i][j]; 
  

    for (k=0; k<V; k++) 
    { 
        for (i=0; i<V; i++) 
        { 
            for (j=0; j<V; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
		printf("\n");
		disp();
    } 
  
	return;
} 

void main() 
{ 
    floyd_Warshall(); 
    return; 
} 