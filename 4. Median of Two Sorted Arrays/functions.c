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



double  findMedianSortedArraysPos(int num,int pos,int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int retPos[2] ={0};
    int numPos = 0;
    double median = 0;
    
    if(nums1Size == 0)
    {
        printf("13-%d:%d:%d\n",pos,nums1[0],nums2[pos+1]);
        if(num == 1)
           return  (double)nums2[pos];
        else
           printf("14-%d\n",nums2[pos]+(nums2[pos+1]<nums1[0] && nums2[pos+1] >=nums2[pos]?nums2[pos+1]:nums1[0]));
           return  ((double)(nums2[pos]+(nums2[pos+1]<nums1[0] && nums2[pos+1] >=nums2[pos]?nums2[pos+1]:nums1[0])))/2;
    }
    if(nums2Size == 0)
    {
        if(num == 1)
           return  (double)nums1[pos];
        else
           return  ((double)(nums1[pos]+(nums1[pos+1]<nums2[0] && nums1[pos+1] >=nums1[pos]?nums1[pos+1]:nums2[0])))/2;
    }
    if(nums1Size ==1 && nums2Size==1)
    {
        return (double)(nums1[pos]+nums2[pos])/2;    
    }
    

    if(nums1Size == 1 )
    {
        printf("4-%d:%d:%d:%d\n",nums1[0],0,nums2,nums2Size);
        numPos = findNumberPos(nums1[0],0,nums2,nums2Size);   
        printf("5-%d:%d\n",numPos,nums1[0]);
        if(numPos == pos)
        {
           retPos[0] = nums1[0];
           retPos[1] = nums2[pos];
           
           //return retPos;
        }
        else if (numPos == pos +1)
        {
           retPos[0] = nums2[pos]; 
           retPos[1] = nums1[0]; 
           
           printf("6-%d:%d\n",nums2[pos] ,nums1[0]);
           printf("7-%d:%d\n",retPos[0] ,retPos[1]);
        }
        else if(numPos > pos +1)
        {
           retPos[0] = nums2[pos]; 
           retPos[1] = nums2[pos+1];  
        }
        else
        {
           retPos[0] = nums2[pos-1]; 
           
           retPos[1] = (nums1[1]<nums2[pos] && nums1[1]>=nums1[0])?nums1[1]:nums2[pos];  
        }
        
        goto END;
        
     
    }
    
    if(nums2Size == 1 )
    {
        numPos = findNumberPos(nums2[0],0,nums1,nums1Size);   
        if(numPos == pos)
        {
           retPos[0] = nums2[0];
           retPos[1] = nums1[pos];
           //return retPos;
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
           retPos[1] = (nums2[1]<nums1[pos] && nums2[1]>=nums2[0])?nums2[1]:nums1[pos];   
        }
        
         goto END;
    }
    
    if(nums1Size > nums2Size)
    {
        numPos =  findNumberPos(nums2[mid(nums2Size)],0,nums1,nums1Size);  
        printf("10-%d:%d:%d\n",numPos,pos,mid(nums1Size));
        
        if(numPos == pos-mid(nums1Size))
        {
            retPos[0] = nums2[mid(nums2Size)];
            retPos[1] = (nums2[mid(nums2Size)+1]<nums1[numPos] && nums2[mid(nums2Size)+1]>=nums2[mid(nums2Size)])?nums2[mid(nums2Size)+1]:nums1[numPos];  
        }
        else if(numPos < pos-mid(nums1Size))
        {
            return findMedianSortedArraysPos(num,pos-numPos-mid(nums2Size)-1, nums1+numPos,nums1Size-numPos,nums2+mid(nums2Size)+1, nums2Size-mid(nums2Size)-1);  
        }
        else
        {
            return findMedianSortedArraysPos(num,pos,nums1, numPos, nums2, mid(nums2Size));    
        }
    }
    else
    {
   
        numPos =  findNumberPos(nums1[mid(nums1Size)],0,nums2,nums2Size);  
        printf("2-%d:%d:%d\n",numPos,pos,mid(nums2Size));
       
        
        if(numPos == pos-mid(nums2Size))
        {
            retPos[0] = nums1[mid(nums1Size)];
            retPos[1] = (nums1[mid(nums1Size)+1]<nums2[numPos] && nums1[mid(nums1Size)+1]>=nums1[mid(nums1Size)])?nums1[mid(nums1Size)+1]:nums2[numPos];   
    
        }
        else if(numPos < pos-mid(nums2Size))
        {
            printf("3-%d:%d:%d:%d:%d\n",pos-numPos-mid(nums1Size)-1,mid(nums1Size)+1,nums1Size-mid(nums1Size)-1,numPos,nums2Size-numPos);
            return findMedianSortedArraysPos(num,pos-numPos-mid(nums1Size)-1,nums1+mid(nums1Size)+1, nums1Size-mid(nums1Size)-1, nums2+numPos,nums2Size-numPos);      
        }
        else 
        {
            return findMedianSortedArraysPos(num,pos,nums1, mid(nums1Size), nums2, numPos);     
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
        printf("9-%f:%d:%d\n",median,retPos[0],retPos[1]);
        median = median/2;
    }
    printf("10-%f\n",median);

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

    printf("1-%d\n",mid(nums1Size+nums2Size));
    

    
    return findMedianSortedArraysPos(num,mid(nums1Size+nums2Size),nums1,nums1Size,nums2,nums2Size);

}



