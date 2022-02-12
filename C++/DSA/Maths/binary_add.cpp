  

//adding binary number..

#include<iostream>
#include<limits.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;

 
int main()
{
  
  int t;
  cin>>t;
  while(t--)
    {
      string a,b,ans;
      cin>>a>>b;

      int i=a.length()-1;
      int j=b.length()-1;
      int carry=0;

      while(i>=0 || j>=0 || carry)
      {
        if(i>=0)
            carry+=a[i--]-'0';
        if(j>=0)
          carry+=b[j--]-'0';

        ans+=(carry%2 + '0');
        carry/=2;
      }
      reverse(ans.begin(),ans.end());

      cout<<ans;
      cout<<endl;
      } 

  return 0;

}


// Important point to note: 

// a = a + "xy" is O(N) while a += "xy" is O(1) (amortized).

// a = a + "xy" creates a copy of a, appends "xy" and then assigns it back to a.

// a += "xy" just appends "xy" to a.

// Therefore the time complexity of this approach is O(n).