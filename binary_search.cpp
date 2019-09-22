#include <iostream>

using namespace std;

int bs(int arr[], int k, int n){
	int r = n - 1, l = 0;
	while(l<r){
		int m = (r + l)/2;
		if(arr[m] >= k){
			r = m;
		} else{
			l = m;
		}
	}
	if(arr[r]==k){
		return r;
	}
	return r - 1;
}

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int arr[n], f[k];	
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < k; ++i)
	{
		cin>>f[i];
	}
	for (int i = 0; i < k; ++i)
	{
		cout<<arr[bs(arr, f[i], n)]<<endl;
	}
	return 0;
}