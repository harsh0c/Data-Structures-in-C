#include<bits/stdc++.h>
using namespace std;

void basicop(int n){
	int i,j,k,m;    // on i,off j,toggle k,check m.
	cin>>i>>j>>k>>m;
	int onmask =(1<<i);
	int offmask= ~(1<<j);
	int toggmask= (1<<k);
	int checkmask= (1<<m);
	cout<<(n|onmask)<<"\n";
	cout<<(n&offmask)<<"\n";
	cout<<(n^toggmask)<<"\n";

    printf("%s\n",((n&checkmask)==0? "false":"true"));
}
void rsbtut(int n){    // rightmost set bit.
	string str = bitset<32>(n & (-n)).to_string();
	str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
	cout<<str<<endl;
}

void kernighanalgo(int n){
	int count=0;
	while(n!=0){
		int rsbm=(n&(-n));
		n=n-rsbm;
		count++;
	}
	cout<<count<<endl;
}

void josephAlgo(int n){
	int i=1;
	while(i*2 <=n){
		i*=2;
	}
	int l=n-i;
	int ans=2*l+1;
	cout<<ans<<endl;
}
long long solve(long long a, long long b) {
    long long minVal = LLONG_MAX;
    long long x = 1;
    while (x <= max(a, b)) {
        minVal = min(minVal, (a & x) + (b & x));
        x = x << 1;
    }
    return minVal;
}

int main(){
	int n;
	cin>>n;
	// basicop(n);
	// n<<x  n*(2^x)
	// rsb=x&2'sx  x&-x 
	// rsbtut(n);
    
	// kernighanalgo(n);    // no. of set bits in n.

	// for(int i=1;i<=n;i++){
	// 	josephAlgo(i);
	// }

	cout<<solve(16,15);

	return 0;
}