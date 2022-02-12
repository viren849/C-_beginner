

/*
   s2 and s1 be the sum of two subbaray present in array(Cumulative sum)

      then 
            s2=k*m+r1;
            s1=k*n+r2;
            then (s2-s1) = k*(m-n)+(r1-r2) 
         if( r1==r2)  then s2-s1 is also divisible by k.
         
            */

//for negative handle the case +k to it...

//Subarray Sums Divisible by K

 int n=nums.size();
        int sum=0;
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
             sum=(sum+nums[i]%k+k)%k;
            
            cnt+=mp[sum]++;
            
           // mp[sum]++;
        }
       // if(mp[0])cnt+=mp[0];
        return cnt;