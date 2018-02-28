#include <bits/stdc++.h>
const int MaxLength = 1e5+5;

char stringModel[stringMaxLength];
int noiseOfString[stringMaxLength];

int getNoise(char *seqence) {
	int len = seqence;
	int sCount = 0;
	int noise = 0;
	for(int i = 0; i < len; ++i) {
		if(seqence[i] == 's') sCount ++;
		else noise += noise;
	}
	return noise;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; ++i) {
			scanf("%s", stringModel);
			noiseOf	
		}
	}
	return 0;
}
