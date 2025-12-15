#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fs.h"

FSNode* root;
FSNode* cwd; // current working directory

void fs_init() {
    root = (FSNode*)malloc(sizeof(FSNode));
    strcpy(root->name, "/");
    root->type = TYPE_DIR;
    root->parent = NULL;
    root->child_count = 0;

    cwd = root;

    printf("[fs] initialized\n");
}
