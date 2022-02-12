//N-Queen problem.....
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

// in right there will be no chance ..
// only placing a queen in a particular row..
//only left with three dir.....

//deep complexity n power n;
bool isvalid(int row,int col,vector<vector<int>>&mat,int n)
{
  for(int i=row,j=col;i>=0 && j>=0;i--,j--)
      if(mat[i][j] == 1)return false;

  for(int i=row,j=col;j>=0;j--)
    if(mat[i][j] ==1)return false;

  for(int i=row,j=col;i<n && j>=0;i++,j--)
    if(mat[i][j] ==1)return false;

  return true;
}

//hashing......

int rowhsh[50]={0}; //size n
int upcol[50]={0};  //2*n-1;
int dncol[50]={0};  //2*n-1;
bool isvalid2(int row,int col,vector<vector<int>>&mat,int n)
{
 
    if(rowhsh[row]==1)return false;
    if(dncol[row+col] == 1)  return false;
    if(upcol[n-1 + row-col] == 1) return false;
  return true;
}
int helper(vector<vector<int>>&mat,int n,int col)
{
      

      if(col == n){
        return 1;
      }
      int res=0;
        for(int row=0;row<n;row++)
        {
           if(isvalid2(row,col,mat,n))
           {
                 mat[row][col]=1;
                  rowhsh[row]=1;
                  dncol[row+col]=1;
                  upcol[n-1+ row-col]=1;

                  res+=helper(mat,n,col+1);
            
                  rowhsh[row]=0;
                  dncol[row+col]=0;
                  upcol[n-1+row-col]=0;
                 mat[row][col]=0;
           }
        }
        return res;   
}
int main()
{
  int n;
  cin>>n;
  vector<vector<int>>mat(n,vector<int>(n,0));
 cout<< helper(mat,n,0);
        return 0;
    
}