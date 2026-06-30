#include<bits/stdc++.h>
using namespace std;

int main(){
  
  // for(int i=0; i<3; i++){
    //   for(int j=0; j<2; j++){
      //     cout<<arr[j][i];
      //   }
      //   cout<<endl;
      // }

  int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
      
  for(int i=0; i<3; i++){
    for(int j=0; j<4; j+=2){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"\n";

  for(int i=0; i<3; i++){
    for(int j=1; j<4; j+=2){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }


}

