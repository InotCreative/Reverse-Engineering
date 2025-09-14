// Key Runner Code | main.c | runner

#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t keyFork = fork();

    if (keyFork == 0) {
        char *args[] = {"./keygen", NULL};
        execv("./keygen", args);
    }

    pid_t crackmeFork = fork();

    if (crackmeFork == 0) {
        FILE *inputFile = fopen("key.txt", "r");
        dup2(fileno(inputFile), STDIN_FILENO);
        char *args[] = {"./crackme", NULL};
        execv("./crackme", args);
    }
    
}