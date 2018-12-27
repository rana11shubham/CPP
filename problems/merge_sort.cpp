#include<bits/stdc++.h>
using namespace std;
void merg(int arr[],int l,int mid,int h){
        int n1=mid-l+1;
        int n2=h-mid;
        int a[n1];
        int b[n2];
        for(int i=0;i<n1;i++)
           { a[i]=arr[i+l];
              //cout<<a[i]<<endl;
              //cout<<"dfdfdfdf"<<endl;
           }
        for(int j=0;j<n2;j++){
            b[j]=arr[j+mid+1];
        }
        int i=0,j=0,k=l;
         while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }

        }


void merge_sort(int arr[],int l,int h){
    if(l<h){
        int mid=l+(h-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merg(arr,l,mid,h);

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
    merge_sort(arr,0,size-1);
    cout<<"The sorted array is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
