#include<bits/stdc++.h>
using namespace std;

void func1(int num){
  cout<<"Value of num is: "<< num << "\n";
}

int func2(int num){
  return num;
}

//pass by reference
void increment(int &a){
  cout<<++a;
}

int main(){
  func1(7);
  cout<<func2(7)<<"\n";

  int a = 10;
  increment(a);
  cout<<"\n"<<a;

  
  return 0;
}