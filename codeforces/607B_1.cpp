#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define _cin ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()

#define INF 2147483647
#define MAXN 504
#define ALPHA 26

ll mod = 1000000007;

int arr[MAXN], dp[MAXN][MAXN];

int solve(int l, int r)
{
    if(l > r) return (dp[l][r] = 0);
    else if(l == r) return (dp[l][r] = 1);
    else if(dp[l][r] != 100000000) return dp[l][r];
    dp[l][r] = min(dp[l][r], 1+solve(l+1,r));
    for(int i=l+2; i<=r; i++){
        if(arr[i] == arr[l]){
            dp[l][r] = min(dp[l][r], solve(l+1, i-1)+solve(i+1, r));
        }
    }
    if(arr[l] == arr[l+1]) dp[l][r] = min(dp[l][r], 1+solve(l+2,r));
    return dp[l][r];
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = 100000000;
    printf("%d\n",solve(0,n-1));
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}