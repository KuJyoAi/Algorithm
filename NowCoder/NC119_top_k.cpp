// 求最小的k个数

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int partition(vector<int> &v, int l, int r);
vector<int> GetLeastNumbers_Solution(vector<int> input, int k);
int main()
{
    vector<int> v = {1, 2, 3, 4, 6, 7, 5, 8};
    v = GetLeastNumbers_Solution(v, 7);
    for (auto r : v)
    {
        cout << r << ",";
    }
    return 0;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> res;
    if (k == 0)
    {
        return vector<int>{};
    }
    int l = 0, r = input.size();
    while (l < r)
    {
        int m = partition(input, l, r);
        for(auto a:input){
            cout<<a<<" ";
        }
        cout<<endl;
        if (m + 1 == k)
        {
            return vector<int>{input.begin(), input.begin() + k};
        }
        else if (m + 1 < k)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    return res;
}

int partition(vector<int> &v, int l, int r){
    if(l+1>=r) return l;
    int pivot = v[l];
    int i=l+1,j=r-1;
    while(true){
        //分别找到左边第一个大于pivot的数和右边第一个小于pivot的数
        while(i<j && v[j]>=pivot) j--;
        while(i<j && v[i]<=pivot) i++;
        if (i==j) break;
        swap(v[i],v[j]);
    }
    if(pivot>v[i]){
        swap(v[l],v[i]);        
    }
    return i;
}