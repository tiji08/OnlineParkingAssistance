
#include <stdio.h>

void print(char *arg) {
    printf("arg = %s\n", arg);
}

int main() {
    char *name = "Kamal";
    print(name);
    return 0;
}

