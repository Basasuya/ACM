#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define N	7000
 
long long aa[N];
 
int compare(const void *a, const void *b) {
	int i = *(int *) a;
	int j = *(int *) b;
 
	return aa[i] == aa[j] ? 0 : aa[i] > aa[j] ? -1 : 1;
}
 
int main() {
	static char used[N];
	static int bb[N], ii[N];
	int n, h, i, j;
	long long ans;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", &aa[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &bb[i]);
	for (h = 0; h < n; h++)
		ii[h] = h;
	qsort(ii, n, sizeof *ii, compare);
	memset(used, 1, n * sizeof *used);
	ans = 0;
	for (h = 0; h < n; h++) {
		i = ii[h];
		used[i] = 0;
		for (j = 0; j < n; j++) {
            // printf("%d: %lld %lld %lld \n", used[j], aa[i], aa[j], (aa[i] & aa[j]) );
			if (used[j] && (aa[i] & aa[j]) == aa[i]) {
                used[i] = 1;
				ans += bb[i];
				break;
			}
        }
        // printf("\n");
	}
	printf("%lld\n", ans);
	return 0;
}