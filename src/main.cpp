#include <cstdio>
#include <ncurses.h>
#include "algo.h"
void help(){
    printf("%s\n", "Usage:");
    printf("%s\n", "./main [options] [Size] [Delay]");
    printf("\t%-6s %s\n","-a", "Toggle access color. Default off");
    printf("\t%-6s %s\n","-s", "Toggle swap color.");
    printf("\t%-6s %s\n","-y", "Toggle ignore color.");
    printf("\t%-6s %s\n","Size", "The size of the array. Default: 10");
    printf("\t%-6s %s\n\n","Delay", "The Delay in ms between each step. Default 100");
    printf("\t%-6s\n\t%s\n","Example", "./main -t 5 500");

}

void verify(char* arg){
    char ptr = *arg;
    while (ptr!= ) {

    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        help();
        return 0;
    }

    Insertion_Sort(5, 500);
    BubbleSort(10, 100);
    /* Selection_Sort(5, 500); */
}
