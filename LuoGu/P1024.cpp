#include<iostream>
#include<cmath>
using namespace std;
double a,b,c,d;
double sovle(double a, double b);
double calc(double x){
	return a*pow(x,3)+b*pow(x,2)+c*x+d;
}

int main(){
	cin>>a>>b>>c>>d;
	
	double t1,t2;
	for(int i=-100;i<=100;i++){
		t1=calc(i);
		t2=calc(i+1);
		
		if(t1*t2==0){
			if(!t1){
				printf("%.2f ",(double)i);
				//cout<<i<<endl;
			}
			
		}else if(t1*t2<0){
			printf("%.2f ",sovle(i,i+1));
		}
		
		
		
	}
	return 0;
}

double sovle(double a, double b){
	//ÕâÀïdoubleÓÐÎó²î 
	if(abs(calc(a))<10E-6){
		return a;
	}else if(abs(calc(b))<10E-6){
		return b;
	}
	
	double mid=(b+a)/2;
	while(b-a>0.01){
		if(calc(mid)*calc(a)<0){
			b = mid;
		}else{
			a = mid;
		}
		mid=(b+a)/2;
	}
	//cout<<"a:"<<a<<"\tb:"<<b<<endl;
	//cout<<calc(b)<<"233"<<endl;
	return (double)(round(a*100)/100);
}
