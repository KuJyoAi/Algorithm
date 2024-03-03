#include<bits/stdc++.h>
using namespace std;
//记录思路:
/*
生成序列,如k=1;则序列为000111 00011 0001
将每一段序列作为起始点, 利用上一次的位置算出下一次的偏移,取模去除循环
然后看是否落在[k+1,2k-d]内即可 
*/
int main(){
	int k=0;;
	cin>>k;
	//移动偏移 
	int bias=2*k+1;
	//合法偏移:左侧偏移恒为k+1,右侧为2k-d 
	bool is=true;
	for(int m=k+1;true;m++){
		for(int p=0;p<k;p++){
			bias=(m-(2*k-p-bias+1))%(2*k-p);
			bias=bias==0?2*k-p:bias;
			
			if(!(bias>=k+1&&bias<=2*k-p)){
				is=false;
				break;
			}
		}
		if(is){
			cout<<m;	
			return 0;
		}else{
			is=true;
			bias=2*k+1;
		}
	}
	return 0;
}
