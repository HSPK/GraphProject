#include "graph.h"
#include "config.h"

void printGraph(AdjGraph g)
{
    for (int i = 0; i < MAXV; i++) {
        if (g->adj[i].num != -1) {
            printf("%d: ", i);
            Anode *p;
            p = g->adj[i].firstarc;
            while (p != NULL) {
                printf("-> %d(%d) ", p->no, p->weight);
                p = p->nextarc;
            }
            printf("\n");
        }
    }
}

void printGraphList(AdjGraph g)
{
    for (int i = 0; i < MAXV; i++) {
        if (g->adj[i].num > 0) {
            Anode *p;
            p = g->adj[i].firstarc;
            while (p != NULL) {
                printf("%d %d %d\n", i, p->no, p->weight);
                p = p->nextarc;
            }
        }
    }
}

AdjGraph createAdj(char *name) 
{
    AdjGraph g = (AdjGraph)malloc(sizeof(adjGraph));
    num_type n = 0, m = 0;

    for (int i = 0; i < MAXV; i++) {
        g->adj[i].firstarc = NULL;
        g->adj[i].num = -1;
    }
    FILE *file;
    file = fopen(name, "r");
    if (file == NULL) {
        printf("file open error!!!\n");
        exit(1);
    }
    id_type u, v;
    weight_type w;
    Anode *p;
    while (fscanf(file, "%d%d%d", &u, &v, &w) != EOF) {
        m++;
        if (g->adj[u].num == -1) {
            n++;
            g->adj[u].num = 0;
        }
        if (g->adj[v].num == -1) {
            n++;
            g->adj[v].num = 0;
        }
        g->adj[u].num++;
        p = (Anode *)malloc(sizeof(Anode));
        p->no = v; p->weight = w;
        p->nextarc = g->adj[u].firstarc;
        g->adj[u].firstarc = p;
    }
    g->m = m;
    g->n = n;
    //printf("%d %d\n", m, n);
    fclose(file);
    return g;
}
