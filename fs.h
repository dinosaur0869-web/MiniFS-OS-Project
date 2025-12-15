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
