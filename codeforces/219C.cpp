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

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

string s;

int main(){
	int n,k;
	cin >> n >> k;
	cin >> s;
	if(k==2){
		int p_1=0,p_2=0,ans_1=0,ans_2=0;
		for(int i=0;i<s.size();i++){
			if(i%2==0){
				if(s[i]=='A'){
					p_1++;
				}
				else{
					p_2++;
				}
			}
			else{
				if(s[i]=='A'){
					p_2++;
				}
				else{
					p_1++;
				}
			}
		}
		if(p_1>p_2){
			cout << p_2 << endl;
			for(int j=0;j<n/2;j++){
				cout << "AB";
			}
			if(n%2==1){
				cout << "A";
			}
		}
		else{
			cout << p_1 << endl;
			for(int j=0;j<n/2;j++){
				cout << "BA";
			}
			if(n%2==1){
				cout << "B";
			}	
		}
	}
	else{
		string s1=s;
		int ans=0;
		for(int i=0;i<s.size()-1;){
			if(s[i]==s[i+1]){
				int ct=1,idx=i;
				while(s[i]==s[i+1]){
					i++;
					ct++;
				}
				ans+=ct/2;
				if(ct%2==0){
					if(i==s.size()-1){
						for(int j=idx+1;j<=i;j+=2){
							if(s[idx]=='A'){
								s1[j]='B';
							}
							else{
								s1[j]='A';
							}
						}
					}
					else{
						if((s[idx]=='A' && s[i+1]=='B')||(s[idx]=='B' && s[i+1]=='A')){
							for(int j=idx+1;j<=i;j+=2){
								s1[j]='C';
							}
						}
						else if(s[idx]=='A' || s[i+1]=='A'){
							for(int j=idx+1;j<=i;j+=2){
								s1[j]='B';
							}
						}
						else if(s[idx]=='B' || s[i+1]=='B'){
							for(int j=idx+1;j<=i;j+=2){
								s1[j]='A';
							}
						}
						else{
							for(int j=idx+1;j<=i;j+=2){
								s1[j]='A';
							}
						}
					}
				}
				else{
					for(int j=idx+1;j<=i;j+=2){
						if(s[idx]=='A'){
							s1[j]='B';
						}
						else{
							s1[j]='A';
						}
					}
				}
			}
			else{
				i++;
			}
		}
		cout << ans << endl;
		cout << s1 << endl;
	}
	return 0;
}