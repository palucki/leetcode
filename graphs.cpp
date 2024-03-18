#include <iostream>
#include <fstream>

#define MAXV 1000 /* maximum number of vertices */

struct edgenode
{
    int y;                 /* adjacency info */
    int weight;            /* edge weight, if any */
    struct edgenode *next; /* next edge in list */
};

struct graph
{
    edgenode *edges[MAXV + 1]; /* adjacency info */
    int degree[MAXV + 1];      /* outdegree of each vertex */
    int nvertices;             /* number of vertices in graph */
    int nedges;                /* number of edges in graph */
    bool directed;             /* is the graph directed? */
};

void initialize_graph(graph *g, bool directed)
{
    int i; /* counter */
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for (i = 1; i <= MAXV; i++)
        g->degree[i] = 0;
    for (i = 1; i <= MAXV; i++)
        g->edges[i] = nullptr;
}

void insert_edge(graph *g, int x, int y, bool directed)
{
    auto *p = new edgenode; /* temporary pointer */
    p->weight = 0;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p; /* insert at head of list */
    g->degree[x]++;
    if (directed == false)
        insert_edge(g, y, x, true);
    else
        g->nedges++;
}

void read_graph(graph* g, bool directed)
{
    initialize_graph(g, directed);

    // Read from the text file
    std::ifstream file("graphs.d");

    int n, m;
    file >> n >> m;

    std::cout << n << " vertices and " << m << " edges\n";
    g->nvertices = n;

    for(int i = 0; i < m; ++i)
    {
        int x, y;
        file >> x >> y;
        insert_edge(g, x, y, directed);
        // std::cout << "processing vertice " << i << '\n';
    }

    // Close the file
    file.close();
}

void print_graph(graph *g)
{
    int i;       /* counter */
    edgenode *p; /* temporary pointer */
    for (i = 1; i <= g->nvertices; i++)
    {
        printf("%d: ", i);
        p = g->edges[i];
        while (p != nullptr)
        {
            printf("%d ", p->y);
            p = p->next;
        }
        printf("\n");
    }
}

bool processed[MAXV+1]; /* which vertices have been processed */
bool discovered[MAXV+1]; /* which vertices have been found */
int parent[MAXV+1]; /* discovery relation */

void initialize_search(graph *g)
{
    // 1 based indexing
    for (int i = 1; i <= g->nvertices; i++)
    {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}

// struct edgenode
// {
//     int y;                 /* adjacency info */
//     int weight;            /* edge weight, if any */
//     struct edgenode *next; /* next edge in list */
// };

// struct graph
// {
//     edgenode *edges[MAXV + 1]; /* adjacency info */
//     int degree[MAXV + 1];      /* outdegree of each vertex */
//     int nvertices;             /* number of vertices in graph */
//     int nedges;                /* number of edges in graph */
//     bool directed;             /* is the graph directed? */
// };

void dfs(graph* g, int v)
{
    //mark v as visited and add edges to process
    std::cout << "At " << v << '\n';
    discovered[v] = true;
    processed[v] = true;

    edgenode* e = g->edges[v];
    while(e != nullptr)
    {
        int y = e->y;
        // std::cout << "next " << y << '\n';

        if(!discovered[y])
        {
            parent[y] = v;
            dfs(g, y);
        }
        
        e = e->next;
    }
}

int main(int argc, char **argv)
{
    graph g;
    read_graph(&g, true);
    print_graph(&g);

    std::cout << "BFS\n";

    std::cout << "DFS\n";
    dfs(&g, 1);



    return 0;
}