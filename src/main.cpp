#include <cstdio>
#include <cstring>
#include <ncurses.h>
#include "algo.h"
#include <ctype.h>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void help(){
    printf("%s ", "Usage:");
    printf("%s\n", "./main [options] [Algorithm] [Size] [Delay]");
    printf("\t%-9s %s\n","-a", "Disable access color. Default off");
    printf("\t%-9s %s\n","-s", "Disable swap color.");
    printf("\t%-9s %s\n","-y", "Disable ignore color.");
    printf("\t%-9s %s\n","-c", "Disable all color. Colorless");
    printf("\t%-9s %s\n","-h", "Show this help");
    printf("\t%-9s %s\n","Algorithm", "The sorting algorithm. Default: 1. See below.");
    printf("\t%-9s %s\n","Size", "The size of the array. Default: 10");
    printf("\t%-9s %s\n\n","Delay", "The Delay in ms between each step. Default 100");
    printf("\t%-9s\n\t%s\n","Example", "./main -ya 3 15 300");
    printf("\n%s\n","Algorithms:");
    printf("\t%s\n","1. BubbleSort");
    printf("\t%s\n","2. InsertSort");
    printf("\t%s\n","3. Selection_Sort");


}

bool valid_number(char* arg) {
    if (arg[0] == '\0') {
        return false;
    }

    for (int i=0; arg[i] != '\0'; i++) {
        if (!isdigit(arg[i])) {
            return false;
        }
    }
    
    return true;
}
bool valid_arg(char* arg) {
    if (arg[0] != '-') {
        return false;
    }

    for (int i = 1; arg[i] != '\0'; i++) {  // Iterate over each character starting from the second
        if (arg[i] == 'c' || arg[i] == 'y' || arg[i] == 's' || arg[i] == 'h' || arg[i] == 'a') {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

bool parse_args(int argc, char** argv, int* options) {
    //options[0] -> Algorithm   Default 1
    //options[1] -> Size        Default 10
    //options[2] -> Delay       Default 100
    //options[3] -> -a
    //options[4] -> -s
    //options[5] -> -y
    //options[3,4,5] -> -c

    int filled = 0;

    for (int i=1; i<argc; i++) {
        if ( valid_number(argv[i]) ) {
            options[filled++] = std::stoi(argv[i]);
        }
        else if ( valid_arg(argv[i]) ) {
            for (char* c=argv[i] +1; *c!= '\0'; c++) {
                if (*c == 'h') {
                    help();
                    return false;
                }
                else if (*c=='c') {
                    options[3] = 1;
                    options[4] = 1;
                    options[5] = 1;
                }
                else if (*c=='a') 
                    options[3] =1;
                
                else if (*c=='s')
                    options[4] =1;

                else if (*c=='y')
                    options[5] =1;

                else {
                    printf("The option %c does not exist.\n", *c);
                }
                
            }
        }
        else {
            printf("Invalid option: %s.\nSee ./main -h for help", argv[i]);
            return false;
        }
    }
    if (filled < 3) {
        options[2] = 100;
    } 
    if ( filled < 2) {
        options[1] = 10;
    }
    if ( filled < 1 ) {
        options[0] = 1;
    }

    return true;
}

int main(int argc, char* argv[]) {
    int options[6]={0,0,0,0,0,0};
    bool opts=parse_args(argc, argv, options);

    if (!opts) {
        return 1;
    }

    switch (options[0]) {
        case 1:
            BubbleSort(options);
            break;
        case 2:
            Insertion_Sort(options);
            break;
        case 3:
            Selection_Sort(options);
            break;
        case 4:
            BogoSort(options);
            break;
        default:
            printf("Invalid algorithm number.");
    }
    return 0;
}
