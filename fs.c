FSNode* root;
FSNode* cwd; // current working directory

void fs_init() {
    root = malloc(sizeof(FSNode));
    strcpy(root->name, "/");
    root->type = TYPE_DIR;
    root->parent = NULL;
    root->child_count = 0;

    cwd = root;
}
