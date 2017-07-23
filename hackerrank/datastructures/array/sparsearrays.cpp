#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    vector<string> v;
    string s;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        v.push_back(s);
    }
    int q,ans;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        cin >> s;
        ans=0;
        for(int j=0;j<n;j++)
        {
            if(v[j]==s)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

