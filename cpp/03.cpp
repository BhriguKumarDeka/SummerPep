//pointers
#include<bits/stdc++.h>
using namespace std;

int main(){
  int a = 100;
  int *p = &a;
  cout<<a<<"\n";
  cout<<p<<"\n";
  cout<<*p<<"\n";
  cout<<*(p+1)<<"\n";
  cout<<*p+1<<"\n";
  return 0;
}