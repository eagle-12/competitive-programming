#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k


ll mod = 1000000007;

using namespace std;

char arr[10][10];

void prin(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cout << arr[i][j] ;
			if(j%3==0){
				cout << " ";
			}
		}
		if(i%3==0){
			cout << endl;
		}
		cout << endl;
	}
}

int main(){
	int x,y;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin >> arr[i][j];
		}
	}
	cin >> x >> y;
	int a=x%3;
	int b=y%3;
	if(a==1 && b==1){
		int ct=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(arr[i][j]=='.'){
					arr[i][j]='!';
					ct++;
				}
			}
		}
			if(ct==0){
				for(int i=1;i<=9;i++){
					for(int j=1;j<=9;j++){
						if(arr[i][j]=='.'){
							arr[i][j]='!';
						}
					}
				}
			}
		
	}
	else if(a==1 && b==2){
		int ct=0;
		for(int i=1;i<=3;i++){
			for(int j=4;j<=6;j++){
				if(arr[i][j]=='.'){
					arr[i][j]='!';
					ct++;
				}
			}
		}
			if(ct==0){
				for(int i=1;i<=9;i++){
					for(int j=1;j<=9;j++){
						if(arr[i][j]=='.'){
							arr[i][j]='!';
						}
					}
				}
			}
			
	}
	else if(a==1 && b==0){
		int ct=0;
		for(int i=1;i<=3;i++){
			for(int j=7;j<=9;j++){
				if(arr[i][j]=='.'){
					arr[i][j]='!';
					ct++;
				}
			}
		}
			if(ct==0){
				for(int i=1;i<=9;i++){
					for(int j=1;j<=9;j++){
						if(arr[i][j]=='.'){
							arr[i][j]='!';
						}
					}
				}
			}
		
	}
	else if(a==2 && b==1){
		int ct=0;
		for(int i=4;i<=6;i++){
			for(int j=1;j<=3;j++){
				if(arr[i][j]=='.'){
					arr[i][j]='!';
					ct++;
				}
			}
		}
			if(ct==0){
				for(int i=1;i<=9;i++){
					for(int j=1;j<=9;j++){
						if(arr[i][j]=='.'){
							arr[i][j]='!';
						}
					}
				}
			}
		
	}
	else if(a==2 && b==2){
		int ct=0;
		for(int i=4;i<=6;i++){
			for(int j=4;j<=6;j++){
				if(arr[i][j]=='.'){
					arr[i][j]='!';
					ct++;
				}
			}
		}
			if(ct==0){
				for(int i=1;i<=9;i++){
					for(int j=1;j<=9;j++){
						if(arr[i][j]=='.'){
							arr[i][j]='!';
						}
					}
				}
			}
		
	}
	else if(a==2 && b==0){
		int ct=0;
		for(int i=4;i<=6;i++){
			for(int j=7;j<=9;j++){
				if(arr[i][j]=='.'){
					arr[i][j]='!';
					ct++;
				}
			}
		}
			if(ct==0){
				for(int i=1;i<=9;i++){
					for(int j=1;j<=9;j++){
						if(arr[i][j]=='.'){
							arr[i][j]='!';
						}
					}
				}
			}
		
	}
	else if(a==0 && b==1){
		int ct=0;
		for(int i=7;i<=9;i++){
			for(int j=1;j<=3;j++){
				if(arr[i][j]=='.'){
					arr[i][j]='!';
					ct++;
				}
			}
		}
			if(ct==0){
				for(int i=1;i<=9;i++){
					for(int j=1;j<=9;j++){
						if(arr[i][j]=='.'){
							arr[i][j]='!';
						}
					}
				}
			}
	}
	else if(a==0 && b==2){
		int ct=0;
		for(int i=7;i<=9;i++){
			for(int j=4;j<=6;j++){
				if(arr[i][j]=='.'){
					arr[i][j]='!';
					ct++;
				}
			}
		}
		if(ct==0){
				for(int i=1;i<=9;i++){
					for(int j=1;j<=9;j++){
						if(arr[i][j]=='.'){
							arr[i][j]='!';
						}
					}
				}
			}
		//cout << "HELLO" << endl;
	}
	else if(a==0 && b==0){
		int ct=0;
		for(int i=7;i<=9;i++){
			for(int j=7;j<=9;j++){
				if(arr[i][j]=='.'){
					arr[i][j]='!';
					ct++;
				}
			}
		}
			if(ct==0){
				for(int i=1;i<=9;i++){
					for(int j=1;j<=9;j++){
						if(arr[i][j]=='.'){
							arr[i][j]='!';
						}
					}
				}
			}
		
	}
	prin();
	return 0;
}
