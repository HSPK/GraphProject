#ifndef _STATS_H_
#define _STATS_H_

#include "config.h"

int numberOfEdges(char name[]);
int numberOfVertices(char name[]);
float freemanNetworkCentrality(char name[]);
float closenessCentrality(char name[], int node);

#endif
