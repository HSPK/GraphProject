#include "main.h"             
#include "priority_queue.h"

static int matchCmd(char *c);

int main(int argc, char const *argv[])
{
    init();
    // PriorityQueue *pq = priority_queue_new(PRIORITY_MIN);

    // int a[] = {4 ,5, 6 ,6, 333, 23, 334, 450, 418};
    // for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
    //     KeyValue *kv = key_value_new(a[i], NULL);
    //     priority_queue_enqueue(pq, kv);
    // }
    // priority_queue_print(pq);
    
    process(argc, (char **)argv);
    return 0;
}

void process(int argc, char *argv[])
{
    if (argc < 2) {
        printf("args too few!!!\n");
        return;
    }
    switch(matchCmd(argv[1])) {
        case 0:         //help
        case 1:
            printf("%s", readme);
            break;
        case 2:         //graph
        case 3:
            processGraph(argc, argv);
            break;
        case 8:         //suantou
            printSuantou();
            break;
        default:
            printf("could not find command:%s\n", argv[1]);
    }
}

void processGraph(int argc, char *argv[])
{
    if (argc < 4) {
        printf("args too few!!!\n");
        return;
    }
    switch (matchCmd(argv[3]))
    {
    case 4:         //stats
    case 5:
        graphStats(argc, argv);
        break;
    case 9:        //path
    case 10:
        graphPath(argc, argv);
        break;
    default:
        printf("graph: cmd error!!!\n");
        break;
    }
}

void graphPath(int argc, char *argv[])
{
    id_type u, v;
    if (argc < 9) {
        printf("args too few!!!\n");
        return;
    }
    u = stoi(argv[6]);
    v = stoi(argv[8]);
    char *path = shortestPath(u, v, argv[4], argv[2]);
    while (*path) {
        putchar(*path++);
    }
}

void graphStats(int argc, char *argv[])
{
    if (argc < 5) {
        printf("args too few!!!\n");
        return;
    }
    num_type n;
    float fnc;
    switch (matchCmd(argv[4]))
    {   
        case 11:        //edges
            n = numberOfEdges(argv[2]);
            printf("%d\n", n);
            break;
        case 12:       //vertices
            n = numberOfVertices(argv[2]);
            printf("%d\n", n);
            break;
        case 13:     //freeman
            fnc = freemanNetworkCentrality(argv[2]);
            printf("%f\n", fnc);
            break;
        case 14:        //closeness
            fnc = closenessCentrality(argv[2], stoi(argv[5]));
            printf("%f\n", fnc);
            break;
        default:
            printf("stats: unsopported arg: %s\n", argv[4]);
            break;
    }
}
/*void graphPath(int argc, char *argv[])
{
	if (argc < 9) {
		printf("args too few!!!\n");
		return;
	}
	char *path;
	int u = *argv[6] - '0';
	int v = *argv[8] - '0';
	path = shortestPath(u, v, argv[4], argv[2]); 
//	printf("%s",path);

}*/
void init()
{

}

void printSuantou()
{
    freopen("suantou.h", "r", stdin);
    //FILE *file = fopen("2.txt", stdin); 
    char c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}

static int matchCmd(char *c)
{
    for (int i = 0; i < cmd_num; i++) {
        if (strcmp(c, (char *)cmd_table[i]) == 0) {
            return i;
        }
    }
    return -1;
}
