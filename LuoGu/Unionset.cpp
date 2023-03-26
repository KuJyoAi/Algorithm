//并查集
int fa[100];
void makeSet(int size) {
    for (int i = 0; i < size; i++) {
        fa[i]=i;
    }
}
int find(int x) {
    if (x != fa[x]){
        fa[x] = find(fa[x]);
    }  
    return fa[x];
}
// x 不是自身的父亲，即 x 不是该集合的代表
// 查找 x 的祖先直到找到代表，于是顺手路径压缩