#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int h){
	int p=arr[h];
	int i=l-1;
	for(int j=l;j<h;j++){
		if(arr[j]<=p){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return i+1;

}
void quick_sort(int arr[],int l,int h){
	if(l<h){
	int q=partition(arr,l,h);
	 quick_sort(arr,l,q-1);
	 quick_sort(arr,q+1,h);
}
}
int main() {
	// your code goes here
	int size;
	cin>>size;
    int *arr=new int(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,size-1);
    for(int i=0;i<size;i++){
    	cout<<arr[i]<<"\t";
    }
	return 0;
}
