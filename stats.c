#include "graph.h"
#include "stats.h"

int numberOfEdges(char name[])
{
    AdjGraph g;
    num_type m;
    g = createAdj(name);
    m = g->m;
    //printf("%d", g->m);
    free(g);
    return m;
}

int numberOfVertices(char name[])
{
    AdjGraph g;
    num_type n;
    g = createAdj(name);
    //printf("%d", g->n);
    n = g->n;
    free(g);
    return n;
}

float freemanNetworkCentrality(char name[])
{

}
