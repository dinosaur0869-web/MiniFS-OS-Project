#include <string.h>
#include "path.h"

int split_path(const char *path, char parts[][32]) {
    int count = 0;
    char temp[256];

    if (path == NULL || strlen(path) == 0)
        return 0;

    // 複製一份，避免破壞原字串
    strcpy(temp, path);

    // 如果是絕對路徑，跳過前面的 '/'
    char *token = strtok(temp, "/");

    while (token != NULL) {
        strcpy(parts[count], token);
        count++;
        token = strtok(NULL, "/");
    }

    return count;
}
