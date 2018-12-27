#include<bits/stdc++.h>
using namespace std;
void max_heapify(int arr[],int n,int i){
    int lar=i;
    int l=2*i+1;
    int r=2*i+2;
    if(arr[lar]<=arr[l] && l<n){
        lar=l;
    }
    if(arr[lar]<=arr[r] && r<n){
        lar=r;
    }
    if(lar!=i){
        swap(arr[i],arr[lar]);
        max_heapify(arr,n,lar);
    }
}
void build_heap(int arr[],int n){
    for(int i=floor(n/2-1);i>=0;i--){
        max_heapify(arr,n,i);
    }
    for(int j=n-1;j>0;j--){
        swap(arr[0],arr[j]);
        max_heapify(arr,j,0);
    }

    }
int main(){
    int size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    cout<<"Enter the elements of array"<<endl;
    int *arr=new int(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    build_heap(arr,size);
    cout<<"The sorted array is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;

}
