#include<bits/stdc++.h>
using namespace std;

int main(){
  //simple pattern
  for(int i=5; i>0; i--){
    for(int j =5; j>=i; j--){
      cout<<i;
    }
    cout<<endl;
  }

  cout<<endl;

  //printing alphabets
  for(int i=0; i<5; i++){
    for(char a= 'A'; a<= 'A'+i; a++){
      cout<<a<<" ";
    }
    cout<<endl;
  }

  cout<<endl;

  //reverse printing
  for(int i= 0; i<=5; i++){
    for(int j = 5; j>=i; j--){
      cout<<"* ";
    }
    cout<<endl;
  }

  //space introduction
  for(int i = 0; i< 5; i++){
    for(int j = 5-i-1; j>0; j--){
      cout<<" ";
    }
    for(int j = 0; j<= i; j++){
      cout<<"*";
    }
    cout<<"\n";
  }
  return 0;
}