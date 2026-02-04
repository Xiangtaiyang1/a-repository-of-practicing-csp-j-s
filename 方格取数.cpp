#include<bits/stdc++.h>
using namespace std;
const int maxmp = 1e3+10;
int r,c;
int mp[maxmp][maxmp];
long long dp[maxmp][maxmp][3];
bool vis[maxmp][maxmp][3];
short int sign[maxmp];

int cha(int i){
	if (!i){
		return i;
	}
	
	if (i < 0){
		return 1;
	}
	
	if (i > 0){
		return 2;
	}
	
	return -1;
}

long long dfs(int nr,int nc){
	bool calc = false;	
	long long sum = mp[nr][nc];
	long long ans = 0;
	
	if (nr == r && nc == c){
		return sum;
	}
	
	short int _move = sign[nc];
	
	if (vis[nr][nc][cha(_move)]){
		return sum+dp[nr][nc][cha(_move)];
	}
	
	if (_move == 0){
		if (nr > 1){
			sign[nc] = -1;
			
			long long v = dfs(nr-1,nc);
			if (calc){
				ans = max(ans,v);
			}
			else{
				calc = true;
				ans = v;
			}
			
			
			sign[nc] = 0;
		}
		if (nr < r){
			sign[nc] = 1;
			
			long long v = dfs(nr+1,nc);
			if (calc){
				ans = max(ans,v);
			}
			else{
				calc = true;
				ans = v;
			}
			
			sign[nc] = 0;
		}
	}
	
	
	
	else{
		int sr = nr+_move;
		if (sr >= 1 && sr <= r){
			long long v = dfs(sr,nc);
			if (calc){
				ans = max(ans,v);
			}
			else{
				calc = true;
				ans = v;
			}
		}
		
	}
	
	if (nc < c){
		long long v = dfs(nr,nc+1);
		if (calc){
			ans = max(ans,v);
		}
		else{
			calc = true;
			ans = v;
		}
	}
	
	vis[nr][nc][cha(_move)] = true;
	dp[nr][nc][cha(_move)] = ans;
	return ans+sum;
}

int main(){
	cin >> r >> c;
	for (int i = 1;i <= r;i++){
		for (int j = 1;j <= c;j++){
			cin >> mp[i][j];
		}
	}
	
	sign[1] = 1;
	sign[c] = 1;
	
	cout << dfs(1,1);
	return 0;
}


