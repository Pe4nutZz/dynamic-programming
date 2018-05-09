#include<iostream>
#include<vector>
#include<string>
using namespace std;
int bag01(vector<int> weight,vector<int>value,int m){
	int n = weight.size();
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i < n + 1; i++){
		for (int j = 1; j < m + 1; j++){
			if (weight[i-1]>j){
				dp[i][j] = dp[i - 1][j];
			}
			else{
				dp[i][j] = dp[i - 1][j]>dp[i - 1][j - weight[i-1]] + value[i-1] ? dp[i - 1][j] : dp[i - 1][j - weight[i-1]] + value[i-1];
			}
		}
	}
	return dp[n][m];
}
int main(){
	vector<int>weight = { 15, 10, 12, 8 };
	vector<int>value = {12,8,9,5};

	int  result = bag01(weight, value,30);
	cout << result;
	return 0;
}