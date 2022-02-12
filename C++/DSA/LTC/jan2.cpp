       // int n=time.size();
       // int count=0;
       // unordered_map<int,int>mp;
       //  vector<int>rem;
       //  for(int i: time)
       //      rem.push_back(i%60);
       //    int z=0;  
       //   int mid=0;
       //  for(int i:rem)
       //      cout<<i<<" ";
       //  for(int i:rem)
       //    if(i==0) z++;
       //  else if(i==30) mid++;
       //  else
       //  {
       //      if(mp.find(60-i)!=mp.end())
       //          count+=mp[60-i];
        
       //      mp[i]++;
       //  }
       //  count+=(z*(z-1))/2;
       //  count+=(mid*(mid-1))/2;
       //  return count;
    
    #include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  int count=0;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int lrr[60]={0};

  for(int i=0;i<n;i++)
    lrr[arr[i]%60]++;

  for(int i=1;i<=29;i++)
    count+=lrr[i]*lrr[60-i];
  
    int z=lrr[0];
    int mid=lrr[60/2];
    count+=(z*(z-1))/2;
    count+=(mid*(mid-1))/2;

    cout<<count<<endl;
  return 0;
}