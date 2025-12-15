#ifndef PATH_H
#define PATH_H

// 將路徑拆成多個部分
// 回傳拆出來的數量
// ex: "/docs/a.txt" -> ["docs", "a.txt"], 回傳 2
int split_path(const char *path, char parts[][32]);

#endif
