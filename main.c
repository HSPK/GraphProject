#include "main.h"             

int main(int argc, char const *argv[])
{
    init();
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
    
    default:
        printf("graph: cmd error!!!\n");
        break;
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
        default:
            printf("stats: unsopported arg: %s\n", argv[4]);
            break;
    }
}

void init()
{

}

void printSuantou()
{

}

int strcmp(char *p, char *q) 
{
    char *a = p;
    char *b = q;
    while (!(*a - *b) && *b != '\0') {
        a++; b++;
    }
    return *a - *b;
}

int matchCmd(char *c)
{
    for (int i = 0; i < cmd_num; i++) {
        if (strcmp(c, (char *)cmd_table[i]) == 0) {
            return i;
        }
    }
    return -1;
}