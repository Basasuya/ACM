#include<bits/stdc++.h>
 
using namespace std;
 
 
struct seg{
	int a, b, c, d;
};
 
bool sort1(const seg& a, const seg& b){
	return a.a < b.a;
}
 
bool sort2(const seg& a, const seg& b){
	return a.c < b.c;
}
 
bool check(vector<seg>& c){
	int n = c.size();
	
	sort(c.begin(), c.end(), sort1);
	long long check1 = 0;
	
	for(int i = 0; i < n; i++){
		//binary search to find right endpoint
		
		int low = i, high = n-1, mid;
		while(low < high){
			mid = (low + high + 1)/2;
			
			if(c[i].b >= c[mid].a){ //intersect
				low = mid;
			}else{
				high = mid-1;
			}
		}
		mid = (low + high + 1)/2;
		//mid is the one which intersects
		
		check1 += mid - i;
	}
	
	sort(c.begin(), c.end(), sort2);
	long long check2 = 0;
	
	for(int i = 0; i < n; i++){
		//binary search to find right endpoint
		
		int low = i, high = n-1, mid;
		while(low < high){
			mid = (low + high + 1)/2;
			
			if(c[i].d >= c[mid].c){ //intersect
				low = mid;
			}else{
				high = mid-1;
			}
		}
		mid = (low + high + 1)/2;
		//mid is the one which intersects
		
		check2 += mid - i;
	}
	//cout<<"CHECK "<<check1<<" "<<check2<<endl;
	return check2 == check1;
	
}
 
 
signed main(){
	ios::sync_with_stdio(false); 
	cin.tie(0);
	srand(time(NULL));
	int n; cin>>n;
	vector<seg> a(n);
	mt19937 rng;
	for(int i = 0; i < n; i++){
		cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
	}
	
	for(int i = 0; i < 60; i++){
		vector<seg> c;
		c.reserve(n);
		//cout<<"S "<<endl;
		for(int j = 0; j < n; j++){
			if(rng()%2 == 0){
				c.push_back(a[j]);
		//		cout<<j<<" ";
			}
		}
		//cout<<endl;
		
		//check
		bool ans = check(c);
		if(!ans){
 
			cout<<"NO"<<endl;
			return 0;
		}else{
		}
	}
	cout<<"YES"<<endl;
	
}