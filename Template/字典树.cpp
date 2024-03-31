#include <iostream>
#include <string>
using namespace std;
// TODO: 没写完
struct trie {
    // nex[p][c] 表示结点p的第c个子结点的编号，cnt表示结点的数量
    // exist[p] 表示结点p是否是一个字符串的结尾
    int nex[1000][26], cnt;
    bool exist[1000];
    void insert(string s) {
        int l = s.size();
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) {
                // 如果没有，就添加结点
                nex[p][c] = ++cnt;
            }
            p = nex[p][c];
        }
        exist[p] = 1;
    }

    bool find(string s) {
        int l = s.size();
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return exist[p];
    }
};

int main(){
    trie t;
    t.insert("hello");
    t.insert("world");
    std::cout << t.find("hello") << std::endl;
    std::cout << t.find("world") << std::endl;
    std::cout << t.find("hell") << std::endl;
    std::cout << t.find("worl") << std::endl;
    return 0;
}