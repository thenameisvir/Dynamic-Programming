#include<iostream>
#include<vector>
using namespace std;
int solvebyrecursion(int n){
  if(n==0 || n==1){
    return n;
  }
  int fib = solvebyrecursion(n-1) + solvebyrecursion(n-2);
  return fib;
}
int solvebymemoisation(vector<int>& dp,int n){
  if(n==0 || n==1){
    return n;
  }
  if(dp[n]!=-1){
    return dp[n];
  }
   dp[n] = solvebymemoisation(dp,n-1) + solvebymemoisation(dp,n-2);
  return dp[n];
}
int solvebytabulation(int n){
  vector<int>dp(n+1,-1);
  dp[0] = 0;
  dp[1] = 1;

  for(int i=2;i<=n;i++){
    dp[i] = dp[i-1]+dp[i-2];
  }
  return dp[n];
}
int main()
{
  int n = 8;
  int ans1 = solvebyrecursion(n);
  cout<<ans1<<endl;
  vector<int>dp(n+1,-1);
  int ans2 = solvebymemoisation(dp,n);
  cout<<ans2<<endl;
  int ans3 = solvebytabulation(n);
  cout<<ans3<<endl;

}