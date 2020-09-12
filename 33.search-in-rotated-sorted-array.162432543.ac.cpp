class Solution {
public:
    int search(vector<int>& A, int B) {
        /*
        if(nums.size()==0)return -1;
        int pivot;
        int high = nums.size()-1;
        int low = 0;
        if(nums[high]>nums[low])
        {
            pivot=0;
        }
        else 
        {
            while(low<=high)
            {
                int mid= (low+high)/2;
                if(nums[mid]<nums[mid+1]&&nums[mid]<nums[mid-1])
                {
                    pivot=mid;
                    break;
                }
                else if(nums[mid]>=nums[high]&&nums[mid]>=nums[low])low=mid+1;
                else high = mid-1;
            }
            
        }
        
        int l1 = 0;
        int h1=pivot-1;
        int l2= pivot;
        int h2 = nums.size()-1;
        cout<<pivot<<" ";
        while(l1<=h1)
        {
            int mid = (l1+h1)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]<target)l1=mid+1;
            else h1=mid-1;
        }
         while(l2<=h2)
        {
             
            int mid = (l2+h2)/2;
          //   cout<<nums[mid]<<" "<<l2<<" "<<h2<<target<<endl;
            if(nums[mid]==target)return mid;
            if(nums[mid]<target)l2=mid+1;
            else h2=mid-1;
            //    cout<<nums[mid]<<" "<<l2<<" "<<h2;
        }
        
        return -1;
        */
        int pivot;
    int high=A.size()-1;
    int low =0;
    while(low<=high)
    {
        int mid =(low+high)/2;
        if(A[mid]<A[mid+1]&&A[mid]<A[mid-1])
        {
            pivot=mid;
            break;
        }
        else if(A[mid]>=A[low]&&A[mid]>=A[high])low=mid+1;
        else high=mid-1;
    }
    low=0;
     high = A.size()-1;
    while(low<=high)
    {
       
        int mid= (low+high)/2 ;
      //   cout<<low<<" "<<high<<" "<<mid<<" "<<pivot<<" "<<(mid+pivot)%A.size()<<endl;
        if(A[(mid+pivot)%A.size()]==B)return (mid+pivot)%A.size();
        else if(B>A[(mid+pivot)%A.size()])low=mid+1;
        else high=mid-1;
    }
    return -1;
    }
};
