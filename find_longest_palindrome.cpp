#include<iostream>
#include<vector>
#include<string>
using namespace std;
string findLongestPalindrome(string s){
	int n = s.size();
	vector<vector<bool>>dp(n, vector<bool>(n, false));
	int maxlen = 1;
	int start = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			if (i - j < 2){
				dp[j][i] = (s[i] == s[j]);
			}
			else{
				dp[j][i] = (s[i] == s[j] && dp[j + 1][i - 1]);
			}
			if (dp[j][i] && maxlen<(i-j+1)){
				maxlen = i - j + 1;
				start = j;
			}
		}
	}
	return s.substr(start, maxlen);
}
int main(){
	string s = "abccba";
	string result=findLongestPalindrome(s);
	cout << result;
	return 0;
}