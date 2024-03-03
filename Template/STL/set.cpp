#include<iostream>
#include<unordered_set>

using namespace std;
unordered_set<int> s;
int main(){
	// 添加元素
	s.emplace(1);
	s.emplace(2);
	
	cout<<"size:"<<s.size()<<endl;
	
	// iterator
	for(auto iter = s.begin(); iter!=s.end();iter++){
		cout<< "e:"<< *iter << endl;
	}
	
	// auto for each
	for(auto se:s){
		cout<< "e:"<< se << endl;
	}
	
	unordered_set<int> set1 = {1, 2, 3, 4, 5};
	unordered_set<int> set2 = {4, 5, 6, 7, 8};
	
	// 求并集
	std::unordered_set<int> union_set = set1;
	union_set.insert(set2.begin(), set2.end());
	
	// 求交集
	std::unordered_set<int> intersection_set;
	for(auto iter = set1.begin();iter != set1.end(); iter++){
		if(set2.find(*iter) != set2.end())
			intersection_set.insert(*iter);
	}

}
