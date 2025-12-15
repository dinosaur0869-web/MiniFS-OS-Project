#ifndef FS_H
#define FS_H

#define MAX_NAME 32
#define MAX_CHILD 16

typedef enum {
    TYPE_FILE,
    TYPE_DIR
} NodeType;

typedef struct FSNode {
    char name[MAX_NAME];
    NodeType type;
    struct FSNode* parent;
    struct FSNode* children[MAX_CHILD];
    int child_count;
} FSNode;

/* 這兩行非常重要 */
extern FSNode* root;
extern FSNode* cwd;

void fs_init();

#endif
