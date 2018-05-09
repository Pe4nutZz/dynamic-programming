#include<iostream>
#include<string>
#include<vector>
using namespace std;
void getNext(string s, vector<int>&next) {
	int i = 0, j = -1;
	next[0] = -1;
	while (i < s.size()-1) {
		if (j == -1 || s[i] == s[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
	
}
int index_kmp(string s, string t, vector<int>&next) {
	int i = 0, j = 0;
	int m1 = s.size();
	int m2 = t.size();
	while (i < m1&&j < m2) {
		if (j == -1 || s[i] == t[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j == t.size()) {
		return i - j;
	}
	else {
		return -1;
	}
}
int main() {
	string s = "acabaabaabcacaabc";
	string t = "abaabcac";
	vector<int> next(t.size(), 0);
	getNext(t, next);
	for (int i = 0; i < next.size(); i++) {
		cout << next[i] << " ";
	}
	cout << endl;
	int res= index_kmp(s, t, next);
	cout << res;
	system("pause");
	return 0;
}