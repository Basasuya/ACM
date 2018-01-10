#include<bits/stdc++.h>
using namespace std;

void replace(string a, string b, string c) {
	regex reg(b);
	string result = regex_replace(a, reg, c);
	cout << result << endl;
}
void count(string a, string b) {
	regex reg(b);
	smatch sm;
	int cnt = 0;
	while( regex_search(a, sm, reg) ) {
		cnt ++;
		a = sm.suffix().str();
	}
	cout << cnt << endl;
}
void search(string a, string b) {
	regex reg(b);
	smatch sm;
	int t1 = a.length();
	int t2, t3;
	bool flag = regex_search(a, sm, reg);
	t3 = sm.begin()->str().length();
	a = sm.suffix().str();
	t2 = a.length();
	printf("%d %d %d\n", t1, t2, t3);
}


int main() {
	string a, b, c;
	while(1) {
		getline(cin, a);
		getline(cin, b);
		//		replace(a, b, c);	
		count(a, b);
	//	search(a, b);
	}
	return 0;	
}	
