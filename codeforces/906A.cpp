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

int main(){
	string s,s1;
	int n,i,ans=0,ele,fl=0;
	cin >> n;
	set<char> st;
	set<char> :: iterator itr;
	int ct=0;
	vi v(26);
	vector<char> v1;
	vector<int> no(26);
	for(int j=0;j<26;j++){
		no[j]=0;
	}
	for(i=0;i<n;i++){
		cin >> s >> s1;
		if(s[0]=='!'){
			if(fl==0){
				for(int j=0;j<s1.size();j++){
					if(no[s1[j]-'a']==0){
						st.insert(s1[j]);
					}
				}
				fl=1;
			}
			else{
				for(int j=0;j<26;j++){
					v[j]=0;
				}
				for(int j=0;j<s1.size();j++){
					v[s1[j]-'a']=1;
				}
				for(itr=st.begin();itr!=st.end();itr++){
					if(v[*itr-'a']==0){
						v1.pb(*itr);
						//st.erase(*itr);
					}
				}
				for(int j=0;j<v1.size();j++){
					st.erase(v1[j]);
				}
				v1.clear();
			}
		}
		else if(s[0]=='.'){
			if(fl==0){
				for(int j=0;j<s1.size();j++){
					no[s1[j]-'a']=1;
				}
			}
			else{
				for(int j=0;j<26;j++){
					v[j]=0;
				}
				for(int j=0;j<s1.size();j++){
					v[s1[j]-'a']=1;
				}
				for(itr=st.begin();itr!=st.end();itr++){
					if(v[*itr-'a']==1){
						v1.pb(*itr);
						//st.erase(*itr);
					}
				}
				for(int j=0;j<v1.size();j++){
						st.erase(v1[j]);
					}
					v1.clear();
			}

		}
		else if(s[0]=='?' && i<n-1){
			if(fl==0){
				no[s1[0]-'a']=1;
			}
			else{
				if(st.find(s1[0])!=st.end()){
					v1.pb(s1[0]);
					//st.erase(s1[0]);
				}
				for(int j=0;j<v1.size();j++){
					st.erase(v1[j]);
				}
				v1.clear();
			}
		}
		if(st.size()==1){
			break;
		}
	}
	//cout << i << endl;
	for(int j=i+1;j<n;j++){
		cin >> s >> s1;
		if(s[0]=='!'){
			ct++;	
		}
		else if(s[0]=='?' && j<n-1){
			ct++;
		}
	}
	cout << ct << endl;
	return 0;
}