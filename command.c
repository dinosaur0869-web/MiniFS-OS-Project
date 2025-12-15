#include <stdio.h>
#include <string.h>
#include "command.h"
#include "path.h"

void execute_command(char *input) {
    char cmd[32], arg[128];

    arg[0] = '\0';

    sscanf(input, "%s %127[^\n]", cmd, arg);

    if (strcmp(cmd, "ls") == 0) {
        cmd_ls(arg);
    } 
    else if (strcmp(cmd, "mkdir") == 0) {
        cmd_mkdir(arg);
    } 
    else if (strcmp(cmd, "touch") == 0) {
        cmd_touch(arg);
    } 
    else {
        printf("Unknown command: %s\n", cmd);
    }
}

void cmd_ls(char *path) {
    if (strlen(path) == 0)
        printf("[ls] current directory\n");
    else
        printf("[ls] path = %s\n", path);
}

void cmd_mkdir(char *path) {
    char parts[10][32];
    int n = split_path(path, parts);

    printf("[mkdir] path = %s\n", path);
    printf("split result:\n");

    for (int i = 0; i < n; i++) {
        printf("  part[%d] = %s\n", i, parts[i]);
    }
}

void cmd_touch(char *path) {
    printf("[touch] path = %s\n", path);
}
