//https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

#include<iostream>
using namespace std;

void StackQueue :: push(int x)
 {      s1.push(x);
 }
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{   int x;
    if(s1.empty() && s2.empty())return -1;
    if(!(s2.empty())){
         x=s2.top();
        s2.pop();
        return x;
    }
    else{
    while(!(s1.empty())){
        s2.push(s1.top());
        s1.pop();
        }

    x=s2.top();
    s2.pop();
    }
    return x;
        // Your Code
}
