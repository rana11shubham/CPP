#include<bits/stdc++.h>
using namespace std;
class Adj{
private:
       int n;
       int **adj;
       bool *visited;

    public:
        Adj(int n){
        this->n=n;
        visited=new bool(n);
        adj=new int*[n];
        for(int i=0;i<n;i++){
            adj[i]=new int(n);
            for(int j=0;j<n;j++){
                adj[i][j]=0;
            }
        }
        }
      void add_edge(int ori,int dest){
        if(ori>n ||ori<0 ||dest>n ||dest<0){
            cout<<"Invalid Edge\n";
        }
        else{
            adj[ori-1][dest-1]=1;
        }
    }
     void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }
     }
};

int main(){
    int n,ori,dest;
    cin>>n;
    Adj a(n);
    int sz=(n*n-1);
    for(int i=0;i<sz;i++){
        cout<<"Enter the edges (-1 -1) to exit"<<endl;
        cin>>ori>>dest;
         if(ori==-1 && dest==-1)
            break;
        a.add_edge(ori,dest);
    }
    a.print();
    return 0;
}
