#include<bits/stdc++.h>
using namespace std;

int main() {
	string *tmp = new string[100];
	
	for(int i = 0; i < 100; ++i) {
		tmp[i].append("fff");	
	}
	for(int i = 0; i < 100; ++i) {
		cout << tmp[i] << endl;
	}
} 
