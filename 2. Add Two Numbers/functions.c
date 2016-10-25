/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int addflag = 0;
    struct ListNode* curNode = l1;
    
    while(l1 != 0 || l2 !=0 || addflag == 1)
    {

        if(addflag == 1)
        {
            l1->val = l1->val+l2->val+1;
            
        }
        else
        {
           l1->val = l1->val+l2->val ; 
        }
       
        if(l1->val > 9)
        {
            addflag = 1;
            l1->val -= 10;
        }
        else
        {
            addflag = 0;
        }
        
        if(l1->next != 0 || l2->next != 0 || addflag == 1)
        {
            if(l1->next == 0)
            {
                l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                l1->next->val = 0;
                l1->next->next = 0;
            }
        
            if(l2->next == 0)
            {
                l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                l2->next->val = 0;
                l2->next->next = 0;
            } 
        }
      
        l1 = l1->next;
        l2 = l2->next;
        
        
       //printf("%d-%d-%d\n",l1->next->val,l2->next->val, addflag);
        
    }
    return curNode;
}
