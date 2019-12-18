/* A C program that uses the “pebble game” technique to test if an input graph is minimally rigid (in two dimensions).
The first line of the input will be n, the number of vertices. n will not exceed 100. Each of the remaining 2n – 3 lines will
contain two values in the range 0 . . . n – 1 to designate an undirected edge. (Self-loops and parallel edges will not be
included.) Each input line should be echoed to the output before being processed. The last line of your output should be
either 1) an indication that the graph is minimally rigid (“Laman”) or 2) an indication that the last edge processed is
“redundant” along with the set of vertices giving the rigid subgraph for the redundant edge*/

#include <stdio.h>
#include <stdlib.h>
struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
void findpebble();
int isEmpty(struct queue* q);
void printQueue(struct queue* q);
int pebble[100],i=0;
int v[100][100]={0};
int a[100],b[100];
int nextadj[100]; 
int e=0;
int t=0;
int start=0;
int o=0;
int z=0;
/*Breadth fitst search searches in the adjacent loops of the node by adding them to the queue*/
struct queue        /*reference:programiz.com*/
{
    int items[40];
    int front;
    int rear;
};
/* Creating A structure with the value of vertex and a pointer to its adjacent node*/
struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int);

struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void bfs(struct Graph* graph, int startVertex, int b,int pebble[], int n);
void move(struct Graph* graph,int startVertex,int nextadj[],int e, int b,int pebble[],int n);
int main()
{
    int q=0;
    int n;
    scanf("%d",&n);/*Takes in the number of vertices*/
    struct Graph* graph = createGraph(n);
   int r=(2*n)-3; /*For a rigid structure the number of edges*/
   
    for(i=0;i<n;i++)
    {
        pebble[i]=2;
      
    }
    
for(i=0;i<r;i++) /*Reading the edges from user*/
{
   scanf("%d %d",&a[i],&b[i]);
}
for(i=0;i<r;i++)
{
   addEdge(graph, a[i],b[i] );
}

int x=0;
for(x=0;x<r;x++)
{
   
    
    printf(" %d - %d\n",a[x],b[x] );

   findpebble(graph,a[x],b[x],pebble,n);

   
   
}
 printf("The structure is rigid\n");
}
/*This function  checks for the number of pebbles at each vertex and calls bfs to get a missing pebble*/
void findpebble(struct Graph* graph,int a,int b,int pebble[],int n)
{ 
  
 
   
   if (pebble[a]+pebble[b]==4)
       {
       
        pebble[a]--;
        printf("Direction: %d -> %d so %d looses a pebble\n",a,b,a );
        v[a][b]=1;
        // printf("v[%d][%d]=%d\n",a,b,v[a][b] );
        
        return;
        
       }
       
    else if (pebble[a]+pebble[b]==3)
    {
        if(pebble[a]<pebble[b])
        {
            
            t=1;
            printf("pebble search for %d\n",a );
             bfs(graph, a,b,pebble,n);
             
             if(pebble[a]!=2)
              {
               printf("The structure is not rigid\n");
               exit(0);
              }
             pebble[a]--;
       printf("Final Edge %d to %d Direction : %d -> %d so %d looses a pebble\n",a,b,a,b,a );
              v[a][b]=1;
              v[b][a]=0;
        return;
         }
        else
        {
           
            t=1;
            printf("pebble search for %d\n",b );
           bfs(graph, b,a,pebble,n);
           
            if(pebble[b]!=2)
              {
               printf("The structure is not rigid\n");
               exit(0);
              }

            pebble[a]--;
       printf("Final Edge %d to %d Direction : %d -> %d so %d looses a pebble\n",a,b,a,b,a );
            v[a][b]=1;
            v[b][a]=0;
           
        return;
        }
        
          
    }
    else if(pebble[a]+pebble[b]<3)
    {  
       if (pebble[a]==0 && pebble[b]==2)
       {
        t=1;
        printf("pebble[%d]=%d\n",a,pebble[a] );
       bfs(graph, a,b,pebble,n);
       
       if(pebble[a]!=2)
              {
               printf("The structure is not rigid\n");
               exit(0);
              }
       pebble[a]--;
       printf("Final Edge %d to %d Direction : %d -> %d so %d looses a pebble\n",a,b,a,b,a );
       v[a][b]=1;
       v[b][a]=0;
      
        return;
    }  

       else if (pebble[b]==0 && pebble[a]==2)
        {
       t=1; 
       printf("peeble[%d]=%d\n",b,pebble[b] );
       bfs(graph, b,a,pebble,n);
       
       if(pebble[b]!=2)
              {

               printf("The structure is not rigid\n");
               exit(0);
              }
       pebble[a]--;
       printf("Direction : from %d to %d so %d looses a pebble\n",a,b,a );
       v[a][b]=1;
       v[b][a]=0;
       // printf("v[%d][%d]=%d\n",a,b,v[a][b] );
        
        return;
    }

        else 
       {
       t=1;
        printf("peeble[%d]=%d\n",a,pebble[a] );
       bfs(graph, a,b,pebble,n);
      
       if(pebble[a]!=2)
              {
               printf("The structure is not rigid\n");
               exit(0);
              }
       // printf("after a gets a pebble now call b to get a pebble\n");
       t=1;
       printf("peeble[%d]=%d\n",b,pebble[b] );
       bfs(graph, b,a,pebble,n);
       
       if(pebble[b]!=2)
              {
               printf("The structure is not rigid\n");
               exit(0);
              }
       // printf("b got a pebble too\n");

       pebble[a]--;
       printf("Final Edge %d to %d Direction : %d -> %d so %d looses a pebble\n",a,b,a,b,a );
        v[a][b]=1;
        v[b][a]=0;
        // printf("v[%d][%d]=%d\n",a,b,v[a][b] );
        return;
       }

    }

}
/*THE bfs searches in the adjacent nodes first for the missing pebble*/

void bfs(struct Graph* graph, int startVertex, int b,int pebble[], int n)
 {
   
    struct queue* q = createQueue(); 
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    if(t==1)
    {
        start=startVertex;

        t--;
    }
    while(!isEmpty(q))
    {
        //printQueue(q);

        int currentVertex = dequeue(q);
        

    /*Saves the list of adjacent nodes*/
       struct node* temp = graph->adjLists[currentVertex];
        
       
       while(temp) 
       { 
        
            int adjVertex = temp->vertex;
           
                nextadj[o]=adjVertex;
                
            // printf("adj%d\n",adjVertex );
            //printf("start%d\n",start );
            // printf("path[%d][%d]=%d\n",currentVertex,adjVertex,v[currentVertex][adjVertex] );
            // printf("pebble[%d]=%d\n",adjVertex,pebble[adjVertex] );
                // printf("start is %d cv is %d\n",start,currentVertex);
                if(start == currentVertex)
                {
                  v[start][currentVertex]=1;
                }
        while( pebble[adjVertex] >= 1 && adjVertex != b && v[currentVertex][adjVertex]==1 && adjVertex !=start && v[start][currentVertex]==1)
        {   
            printf("pebble found at %d\n", adjVertex);
            pebble[adjVertex]--; 
            pebble[start]=pebble[start]+1;  


           v[start][currentVertex]=0; 
           
            v[currentVertex][adjVertex]=0;

             v[adjVertex][currentVertex]=1;

            
          /*When the search completes it exits the function*/
           

            if(pebble[start]==2)
            {  
               printf("pebble[%d]=%d\n",start,pebble[start]);
                o=0;
                return ;
            }
           
 
        }
           if(graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            
           if(pebble[start]!=2)
            {
            temp = temp->next;
            o++;    
            }   
          
       }
     /*Now the search moves onto to the set of next adjacent node*/

       if(pebble[start] !=2 && z==0)
       {
             
           
             move(graph,startVertex,nextadj,o,b,pebble,n);

       }   
       return;
          
    }
         
}


        
        
/*This function moves to the next adjacent node if there is a forward path to it and tries to find a pebble*/
void move(struct Graph* graph,int startVertex,int nextadj[],int e, int b,int pebble[],int n)
 {     
 	z=e-1;
 for(i=0;i<e;i++)
        {  
        	 

           if (v[start][nextadj[i]]==1 && nextadj[i] !=b)
           {
            
         
            
            bfs(graph,nextadj[i],b,pebble,n) ;
            z--;


            
            if(pebble[start]==2)
            {
              z=0;
              v[start][nextadj[i]]=0;
              v[nextadj[i]][start]=1;
             
             

              return;
            }
           }

           else
           {
           
           	z--;
           }

        }

}
 
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
 /*This functions makes spaces for graph and marks all nodes as unvisited*/
struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    
 
    int i;
    for (i = 0; i < vertices; i++)
     {
          
     
        pebble[i]=2;
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
     }
 
    return graph;
}
 
 /*Makes each vertex a node and links it to its adjacent node*/
void addEdge(struct Graph* graph, int src, int dest)
{
   
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
   
   
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;


}
/*A queu is need to carry on BFS*/
struct queue* createQueue()
 {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(struct queue* q) 
{
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}


/*LOADING*/
void enqueue(struct queue* q, int value)
{
    if(q->rear == 40-1)
        printf("\nQueue is Full!!");
    else 
    {
        if(q->front == -1)
            q->front = 0;
         
        q->rear++;
       
        q->items[q->rear] = value;
    
       
    }
}
/*UNLOADING THE QUEUE*/
int dequeue(struct queue* q)
{
    int item;
    if(isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear)
        {
            //printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}
void printQueue(struct queue *q) 
{
    int i = q->front;
    if(isEmpty(q))
     {
        // printf("Queue is empty");
    }
     else 
    {
        // printf("\nQueue contains \n");
        for(i = q->front; i < q->rear + 1; i++)
         {
                printf("%d ", q->items[i]);
        }
    }
    
}
