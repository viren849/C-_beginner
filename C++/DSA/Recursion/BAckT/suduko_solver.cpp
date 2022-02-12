#include<iostream>
#include<vector>
using namespace std;
bool isvalid(char c,int row,int col,vector<vector<char>>&mat)
{
  for(int i=0;i<9;i++)
  {
       if(mat[row][i]==c)return false;
       if(mat[i][col] == c) return false;

       if(mat[3*(row/3)+i/3][3*(col/3)+i%3] == c)return false;
   }  
   return true;
  
}
bool solve(vector<vector<char>>&mat,int col)
{    

   if(col == 9)
     return true;

      for(int row=0;row<9;row++)
      {
        if(mat[row][col] == '.')
         {
            for(char i='1';i<='9';i++)
             {
               if(isvalid(i,row,col,mat))
               {
                   mat[row][col]=i;
                   if(solve(mat,col+1))return true;    
                   mat[row][col]='.';
               }

             }
            return false;
         }
      }
      return true;
}
int main()
{
  vector<vector<char>>mat(9,vector<char>(9,'.'));
   for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
       cin>>mat[i][j];
    

    solve(mat,0);

    for(auto s: mat){
      for(char c: s)
        cout<<c<<" ";
      cout<<endl;
    }
}
// bool solve(vector<vector<char>>&mat,int c)
// {    

   
//      for(int col=0;col<9;col++)
//       for(int row=0;row<9;row++)
//       {
//         if(mat[row][col] == '.')
//          {
//             for(char i='1';i<='9';i++)
//              {
//                if(isvalid(i,row,col,mat))
//                {
//                    mat[row][col]=i;
//                    if(solve(mat,col+1))return true;    
//                        mat[row][col]='.';
//                }

//              }
//             return false;
//          }
//       }
//       return true;
// }