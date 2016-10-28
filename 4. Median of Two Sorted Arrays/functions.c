
int mid(int size)
{
    return size%2==0?size/2-1:size/2;
}

int findNumberPos(int num,int start,int* nums1, int nums1Size) 
{
    if(num <= nums1[0])
    {
        return start;
    }
    if(num >= nums1[nums1Size-1])
    {
        return start+nums1Size;    
    }
    if(num >= nums1[mid(nums1Size)] && num <= nums1[mid(nums1Size)+1] )
    {
        return start+mid(nums1Size)+1;
    }
    
    if(num > nums1[mid(nums1Size)])
    {
        return findNumberPos(num, start+mid(nums1Size)+1,nums1+mid(nums1Size)+1, nums1Size-mid(nums1Size)-1);      
    }
    else
    {
        return findNumberPos(num,start,nums1, nums1Size-mid(nums1Size)-1);      
    }
}

double  findMedianSortedArraysPos(int num,int pos,int* nums1, int nums1Size,int real1Size, int* nums2, int nums2Size,int real2Size)
{
    int retPos[2] ={0};
    int numPos = 0;
    double median = 0;
    
    if(nums1Size == 0)
    {
        if(num == 1)
           return  (double)nums2[pos];
        else
           return  ((double)(nums2[pos]+(nums2[pos+1]<nums1[0] && nums2[pos+1] >=nums2[pos]?nums2[pos+1]:nums1[0])))/2;
    }
    if(nums2Size == 0)
    {
        if(num == 1)
           return  (double)nums1[pos];
        else
           return  ((double)(nums1[pos]+(nums1[pos+1]<nums2[0] && nums1[pos+1] >=nums1[pos]?nums1[pos+1]:nums2[0])))/2;
    }
  
    if(nums1Size == 1 )
    {
        numPos = findNumberPos(nums1[0],0,nums2,nums2Size);   
        if(numPos == pos)
        {
           retPos[0] = nums1[0];
           retPos[1] = (nums1[1]<nums2[pos] && nums1[1]>=nums1[0])?nums1[1]:nums2[pos];  
        }
        else if (numPos == pos +1)
        {
           retPos[0] = nums2[pos]; 
           retPos[1] = nums1[0]; 
        }
        else if(numPos > pos +1)
        {
           retPos[0] = nums2[pos]; 
           retPos[1] = nums2[pos+1];  
        }
        else
        {
           retPos[0] = nums2[pos-1];
           retPos[1] = (real1Size>=2 && nums1[1]<nums2[pos])?nums1[1]:nums2[pos];  
        }    
        goto END;
           
    }
    
    if(nums2Size == 1 )
    {
        numPos = findNumberPos(nums2[0],0,nums1,nums1Size);   
        if(numPos == pos)
        {
           retPos[0] = nums2[0];
           retPos[1] = (nums2[1]<nums1[pos] && nums2[1]>=nums2[0])?nums2[1]:nums1[pos];   
        }
        else if (numPos == pos +1)
        {
           retPos[0] = nums1[pos]; 
           retPos[1] = nums2[0]; 
        }
        else if(numPos > pos +1)
        {
           retPos[0] = nums1[pos]; 
           retPos[1] = nums1[pos+1];  
        }
        else
        {
           retPos[0] = nums1[pos-1]; 
           retPos[1] = (real2Size>=2 && nums2[1]<nums1[pos])?nums2[1]:nums1[pos];   
        }       
         goto END;
    }
    
    if(nums1Size > nums2Size)
    {
        numPos =  findNumberPos(nums2[mid(nums2Size)],0,nums1,nums1Size);  
        
        if(numPos == pos-mid(nums2Size))
        {
            retPos[0] = nums2[mid(nums2Size)];
            retPos[1] = (nums2[mid(nums2Size)+1]<nums1[numPos] && nums2[mid(nums2Size)+1]>=nums2[mid(nums2Size)])?nums2[mid(nums2Size)+1]:nums1[numPos];  
        }
        else if(numPos < pos-mid(nums2Size))
        {
            return findMedianSortedArraysPos(num,pos-numPos-mid(nums2Size)-1, nums1+numPos,nums1Size-numPos,real1Size-numPos,nums2+mid(nums2Size)+1, nums2Size-mid(nums2Size)-1,real2Size-mid(nums2Size)-1);  
        }
        else
        {
            return findMedianSortedArraysPos(num,pos,nums1, numPos, real1Size,nums2, mid(nums2Size),real2Size);    
        }
    }
    else
    {
        numPos =  findNumberPos(nums1[mid(nums1Size)],0,nums2,nums2Size);  
        
        if(numPos == pos-mid(nums1Size))
        {
            retPos[0] = nums1[mid(nums1Size)];
            retPos[1] = (nums1[mid(nums1Size)+1]<nums2[numPos] && nums1[mid(nums1Size)+1]>=nums1[mid(nums1Size)])?nums1[mid(nums1Size)+1]:nums2[numPos];     
        }
        else if(numPos < pos-mid(nums1Size))
        {
            return findMedianSortedArraysPos(num,pos-numPos-mid(nums1Size)-1,nums1+mid(nums1Size)+1, nums1Size-mid(nums1Size)-1,real1Size-mid(nums1Size)-1, nums2+numPos,nums2Size-numPos,real2Size-numPos);      
        }
        else 
        {
            return findMedianSortedArraysPos(num,pos,nums1, mid(nums1Size), real1Size,nums2, numPos,real2Size);     
        }
    }
 END:   
    if(num == 1)
    {
        median = (double)retPos[0];
    }
    else
    {
        
        median = (double)retPos[0]+ (double)retPos[1];
        median = median/2;
    }

   return median;
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    

    
    int num =(nums1Size+nums2Size)%2 == 0?2:1;
    
    if(nums1Size == 0)
    { 
        if(num == 1)
           return  (double)nums2[mid(nums2Size)];
        else
           return  (double)(nums2[mid(nums2Size)]+nums2[mid(nums2Size)+1])/2;
    }
    if(nums2Size == 0)
    {
        if(num == 1)
           return  (double)nums1[mid(nums1Size)];
        else
           return  (double)(nums1[mid(nums1Size)]+nums1[mid(nums1Size)+1])/2;    
    }

    
    if(nums1Size ==1 && nums2Size==1)
    {
        return (double)(nums1[mid(nums1Size)]+nums2[mid(nums1Size)])/2;    
    }

    
    return findMedianSortedArraysPos(num,mid(nums1Size+nums2Size),nums1,nums1Size,nums1Size,nums2,nums2Size,nums2Size);

}






