#include <iostream>
#include <string>
using namespace std;
// TODO: 没写完
struct trie {
    // !注意使用时下面的变量可能要改成全局变量, 否则会出现段错误
    int nex[1000][26], cnt;
    bool exist[1000];  // 该结点结尾的字符串是否存在
    // s, l: 字符串s的长度
    void insert(string s) {  // 插入字符串
        int l = s.size();
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
        exist[p] = 1;
    }

    // s, l: 字符串s的长度
    bool find(string s) {  // 查找字符串
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