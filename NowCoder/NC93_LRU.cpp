#include<map>
#include<list>
using namespace std;
class Solution {
    list<pair<int, int>> dlist;//双向链表存k,v
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int cap;
    //用链表存，链表头部是最近使用的，尾部是最后使用的，如果要删去，就直接把尾部删去就好
  public:
    Solution(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        // 存在key
        if (map.count(key)) {
            //把这个放在头部，所以需要个tmp存着，然后删掉这个位置，再放到头部
            auto tmp = *map[key];
            dlist.erase(map[key]); //删除对应元素
            dlist.push_front(tmp);//把它放在最前面
            map[key] = dlist.begin(); //改变哈希表的指向
            return dlist.front().second;
        }
        return -1;
    }

    void set(int key, int value) {
        if (map.count(key)) {
            //存在, 删除, 并放到头部
            dlist.erase(map[key]);
        } else if (cap == dlist.size()) {
            // 位置满了, 删掉最后的
            auto tmp = dlist.back();
            map.erase(tmp.first);
            dlist.pop_back();
        }
        dlist.push_front(pair<int, int>(key, value));
        map[key] = dlist.begin(); //哈希表指向
    }
};

