#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct Student{
	int age;
	int score;
};

Student s[10];
priority_queue<Student> p;

// 运算符重载(推荐)
bool operator<(const Student s1, const Student s2){
	// 优先队列默认大顶堆, 这里符号相反可以变成小顶堆
	return s1.score > s2.score; 
}

// cmp函数
bool cmp(Student s1, Student s2){
	return s1.score < s2.score;
}

int main(){
	for(int i=0;i<10;i++){
		s[i].age = i+20;
		s[i].score = 80-i;
		p.push(s[i]);
	}
	
	sort(s,s+10);
	
	sort(s,s+10,cmp);
	
	while(!p.empty()){
		Student s = p.top();
		p.pop();
		cout<<s.age<<" "<<s.score<<endl;
	}
}		



