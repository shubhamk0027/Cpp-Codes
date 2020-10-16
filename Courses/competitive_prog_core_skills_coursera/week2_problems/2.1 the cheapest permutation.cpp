#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
#include <deque>
#include <map>
#include <deque>
#include <iomanip>
#include <cmath>
#include <functional>
#include <set>
#include <list>
#define endl '\n'
using namespace std;
#define MOD 1000000007
#define ll long long
#define pb push_back
typedef pair<ll,ll> pll;
ll n;
ll arr[9]={1,2,3,4,5,6,7,8,9};
ll result[9]={0,0,0,0,0,0,0,0,0};
ll mat[9][9];
ll find_cost(){
	ll cost=0;
	for(ll i=0;i<(n-1);i++){
		cost+=mat[arr[i]-1][arr[i+1]-1];
	}
	return cost;
}
void get_result(){
	for(ll i=0;i<n;i++){
		result[i] = arr[i];
	}
}
void print_result(){
	for(ll i=0;i<n;i++)
		cout<<result[i]<<" ";
	cout<<"\n";
}
void process(){
	ll mincost = 10000;
	ll cost = 0;
	do{
		cost = find_cost();
		if(cost<mincost) {
			mincost = cost;
			get_result();
		}
	}while(next_permutation(arr,arr+n));
	//cout<<mincost<<"\n";
}
int main(){
cin.sync_with_stdio(false);
    while(cin>>n){
    	for(ll i=0;i<n;i++)
    		for(ll j=0;j<n;j++)
    			cin>>mat[i][j];
    	process();
    	print_result();
    }
	return 0;
}
