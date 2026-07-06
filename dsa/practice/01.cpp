#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
  int original = n;
  int rev = 0;
  while(n>0){
    int ones = n % 10;
    rev = rev * 10 + ones;
    n = n / 10;
  }
  return rev==original;
}

int reverseNum(int n){
  int rev = 0;
  while(n>0){
    int ones = n % 10;
    rev = rev * 10 + ones;
    n = n / 10;
  }
  return rev;
}

bool isPrime(int n){
  if(n == 1 || n == 2) return true;
  for(int i=2; i * i <n; i++){
    if(n%i==0) return false;
  }
  return true;
}

void fib(int n){
  int a = 0, b = 1;
  for(int i = 1; i<n; i++){
    cout<< a << " "; 
    int c = a + b;
    a = b;
    b = c;
  }
}

int fact(int n){
  if(n == 0 || n == 1) return 1;
  return n * fact(n-1);
}

int intPow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int digitCount(int n){
  int count = 0;
  while(n>0){
    count++;
    n/=10;
  }
  return count;
}

int isArmstrong(int n){
  int original = n;

  int sum = 0;
  int power = digitCount(n);

  while(n > 0){
    int digit = n % 10;
    sum+=intPow(digit, power);
    n/=10;
  }
  return sum==original;
}

void swapNum(int a, int b){
  cout<< "Initially: "<< a << "," << b;
  a = a + b;
  b = a - b;
  a = a - b;
  
  cout<< "Finally: "<< a << "," << b;
}

int gcd(int a, int b){
  while(b!=0){
    int remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}


int main(){
  int n = 1020304;
  // cout<<isPalindrome(n);
  // cout<<reverseNum(n);
  // cout<<"\n PRIME: "<<endl;
  // cout<<isPrime(n);
  // cout<<isPrime(7);
  // fib(10);
  // cout<<fact(6);
  // cout<<digitCount(12345);
  // cout<<isArmstrong(153);
  // swapNum(3, 4);
  cout<<gcd(12, 6);
}