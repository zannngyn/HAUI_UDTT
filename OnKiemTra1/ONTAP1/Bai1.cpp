#include<bits/stdc++.h>
using namespace std;

int countConfig=0;

void ViewConfig(int n, int x[], char label[], string name[]){
	for (int i=1; i<=n; i++){
		cout<< label[x[i]-1]<<" - "<<name[x[i]-1]<<setw(5);
	}
	cout<<endl;
	countConfig++;
}

void NextConfig(int n, int x[], int i){
	int k=n;
	while (x[k]<x[i]) k--;
	swap(x[i],x[k]);
	int j=n;
	i++;
	while (i<=j){
		swap(x[i],x[j]);
		i++;
		j--;
	}
}

void ListConfig(int n, char label[], string name[]){
	int i;
	int x[n+1];
	for(int i=1; i<=n; i++){
		x[i]=i;
	}
	do{
		ViewConfig(n, x, label, name);
		i=n-1;
		while(i>0 && x[i]>x[i+1]){
			i--;
		}
		if(i>0){
			NextConfig(n, x, i);

		}
	}
	while(i>0);
	cout<<"Tong so Hoan vi:"<<countConfig;
}

void BackTracking(int k, int n, int x[], int check[], char label[], string name[]){
	for (int i = 1; i<=n; i++){
		if (check[i]==0){
			x[k]=i;
			if(n==k) ViewConfig(n,x,label,name);
			else{
				check[i] = 1;
				BackTracking(k+1,n,x,check,label,name);
				check[i]=0;
			}
		}
	}
	
}


int main(){
	int n=4;
	char label[]={'A','B','C','D'};
//	string name[]={"Hung","Cuc","Truc","Mai"};
//	ListConfig(n, label, name);
	
	int x1[n+1] = {0}, check[n+1] = {0};
	BackTracking(1,n,x1,check,label,name);
	cout<<"Tong so Hoan vi:"<<countConfig;
}
	
