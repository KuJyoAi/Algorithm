#include<bits/stdc++.h>
using namespace std;

int words[128];//ascii桶 
int main(){
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		words[s[i]]++;
	}
	
	int max=0,min=100;
	for(int i='a';i<='z';i++){
		if(words[i]!=0){
			if(words[i]>max){
				max=words[i];
			}
			
			if(words[i]<min){
				min=words[i];
			}
		}
	}
	
	int res=max-min;
	if(res==0||res==1){
		cout<<"No Answer"<<endl;
		cout<<0;
		return 0;
	}
	for(int i=2;i*i<=res;i++){
		if(res%i==0){
			cout<<"No Answer"<<endl;
			cout<<0;
			return 0;
		}
	}

	cout<<"Lucky Word"<<endl;
	cout<<res;
	return 0;
} 
