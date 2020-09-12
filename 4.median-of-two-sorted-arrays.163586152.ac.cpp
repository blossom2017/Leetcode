class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        /*
        if(nums1.size()>nums2.size())return findMedianSortedArrays(nums2,nums1);
        int low =0;
        int high= nums1.size();
        int part,party,xmax,xmin,ymax,ymin;
        while(low<=high)
        {
            int part = (low+high)/2;
            if (part==0)xmax= INT_MIN;
            else xmax = nums1[part-1];
            int party= (nums1.size()+nums2.size()+1)/2-part;
            if(part==nums1.size())xmin = INT_MAX;
            else xmin = nums1[part];
            if(party==0)ymax= INT_MIN;
            else ymax = nums2[party-1];
            if(party==nums2.size())ymin = INT_MAX;
            else ymin = nums2[party];
            if(xmax<=ymin&&ymax<=xmin)
            {
                //done
                if((nums1.size()+nums2.size())%2==0)return (double)(max(xmax,ymax)+min(xmin,ymin))/2;
                else return max(xmax,ymax);
            }
            else if(xmax>ymin)high = part-1;
            else low = part+1;
        }
        return -1;
        
    }
    */
    int  minele = INT_MAX;
int maxele = INT_MIN;
int req;
    if((A.size()+B.size())%2==0)req = (A.size()+B.size())/2;
    else req = (A.size()+B.size()+1)/2;
    for(int i=0;i<A.size();i++)
    {
        minele = min(minele,A[i]);
        maxele = max(maxele,A[i]);
    }
    for(int i=0;i<B.size();i++)
    {
        minele = min(minele,B[i]);
        maxele = max(maxele,B[i]);
    }
    int low  = minele ;
    int high = maxele;
    int px,py;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int p=0;
        px= upper_bound(A.begin(),A.end(),mid)-A.begin();
        py=upper_bound(B.begin(),B.end(),mid)-B.begin();
       // cout<<low<<" "<<high<<" "<<mid<<" "<<p<<endl;
       p=px+py;
        if(p<req)low =mid+1;
        else high = mid-1;
    }
     if((A.size()+B.size())%2!=0) return low;
   else 
   {
     //  cout<<low<<"llllll ";
     int l1=low;
     req= req+1;
      low  = minele ;
     high = maxele;
  
    while(low<=high)
    {
        int mid = (low+high)/2;
        int p=0;
        px= upper_bound(A.begin(),A.end(),mid)-A.begin();
        py=upper_bound(B.begin(),B.end(),mid)-B.begin();
       // cout<<low<<" "<<high<<" "<<mid<<" "<<p<<endl;
       p=px+py;
        if(p<req)low =mid+1;
        else high = mid-1;
    }
     return (double)(l1+low)/2;
     
   }
   return -1;
}
};
