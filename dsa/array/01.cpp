#include<bits/stdc++.h>
using namespace std;


int main(){
  vector <int> v = {10, 20, 30, 40, 50};
  v.push_back(60);
  cout<<v.size();
  v.pop_back();
  cout<<"\n";
  cout<<v.size();
  v.clear();
  cout<<"\n";
  cout<<v.size();

  return 0; 
}