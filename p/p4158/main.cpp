#define LOCAL
#include <bits/stdc++.h>
using namespace std;
int f[51][2550],sum[51][2550];
int g[51][2550][51];
int n,m,t;
char s[150];
signed main() {
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    cin>>n>>m>>t;
	for(int i=1;i<=n;i++){
		cin>>s;
		sum[i][0]=0;
		for(int j=1;j<=m;j++){
			if(s[j-1]=='1') sum[i][j]=sum[i][j-1]+1;
			else sum[i][j]=sum[i][j-1];
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	for(int k=1;k<=m;k++)
	for(int q=j-1;q<k;q++){
		g[i][j][k]=max(g[i][j][k],g[i][j-1][q]+max(sum[i][k]-sum[i][q],k-q-sum[i][k]+sum[i][q]));
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=t;j++)
	for(int k=0;k<=min(j,m);k++){
	f[i][j]=max(f[i][j],f[i-1][j-k]+g[i][k][m]); }
	int ans=0; 
	for(int i=1;i<=t;i++) ans=max(ans,f[n][i]);
	cout<<ans<<endl;
    return 0;
}