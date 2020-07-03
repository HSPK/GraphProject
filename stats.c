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

void deleteI(Vnode *v, id_type id)
{
    Anode *p, *pre;
    pre = v->firstarc;
    if (pre == NULL)
        return;
    if (pre->no == id) {
        v->firstarc = pre->nextarc;
        v->num--;
        free(pre);
        return;
    }
    p = pre->nextarc;
    while (p != NULL) {
        if (p->no == id) {
            pre->nextarc = p->nextarc;
            v->num--;
            free(p);
            return;
        }
        pre = p;
        p = p->nextarc;
    }
}

void deleteDupVer(AdjGraph g)
{
    for (int i = 0; i < MAXV; i++) {
        if (g->adj[i].num > 0) {
            Anode *p = g->adj[i].firstarc;
            while (p != NULL) {
                deleteI(&g->adj[p->no], i);
                //printGraph(g);
                //printf("\n");
                p = p->nextarc;
            }
        }
    }
}

float freemanNetworkCentrality(char name[])
{
    double cd;
    AdjGraph g;
    g = createAdj(name);
    freopen("out.txt", "w", stdout);
    printGraph(g);
    long cd1 = (long)(g->n - 1) * (g->n - 2);
    //printf("%ld", cd1);
    long max = -1;
    long sum = 0;
    int num;
    deleteDupVer(g);
    for (int i = 0; i < MAXV; i++) {
        num = g->adj[i].num;
        if (num > 0) {
            //printf("%d:%d\n", i, num);
            sum += 2 * num;
            if (num > max) {
                max = num;
            }
        }
    }
    printf("%ld %ld %ld\n", cd1, max, sum);
    sum = g->n * max - sum;
    cd = (double)sum / cd1;
    printf("\n");
    printGraph(g);
    printf("%.15lf\n", cd);
    return (float)cd;
}
