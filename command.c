#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "path.h"
#include "fs.h"

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
    FSNode* cur = cwd;

    for (int i = 0; i < cur->child_count; i++) {
        printf("%s  ", cur->children[i]->name);
    }
    printf("\n");
}


void cmd_mkdir(char *path) {
    char parts[10][32];
    int n = split_path(path, parts);

    FSNode* cur = cwd;

    for (int i = 0; i < n; i++) {
        // 找 child
        FSNode* next = NULL;
        for (int j = 0; j < cur->child_count; j++) {
            if (strcmp(cur->children[j]->name, parts[i]) == 0) {
                next = cur->children[j];
                break;
            }
        }

        if (next == NULL) {
            // 最後一層才建立
            if (i == n - 1) {
                FSNode* node = malloc(sizeof(FSNode));
                strcpy(node->name, parts[i]);
                node->type = TYPE_DIR;
                node->parent = cur;
                node->child_count = 0;

                cur->children[cur->child_count++] = node;
                printf("Directory created: %s\n", parts[i]);
                return;
            } else {
                printf("Path not found\n");
                return;
            }
        }
        cur = next;
    }
}


void cmd_touch(char *path) {
    printf("[touch] path = %s\n", path);
}
