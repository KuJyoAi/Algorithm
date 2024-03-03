#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, int> um;
int main(){
	um[1] = 1;
	um[2] = 2;
	
	for(const auto &p : um){
		cout<<"k:"<<p.first<<" v:"<<p.second<<endl;
	}
}
