/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     struct ListNode *next;
 *      * };
 *       */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int addflag = 0;
	    struct ListNode *curNode = l1;
		    struct ListNode *zeroNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			    
				    zeroNode->val = 0;
					    zeroNode->next = 0;
						    
							    while(l1 != 0 || l2 !=0 || addflag ==1)
								    {
									        if(l1 == 0)
											        {
													            l1 = zeroNode;
																        }
																		        if(l2 == 0)
																				        {
																						            l2 = zeroNode;
																									        }

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
																																																																					          
																																																																							          printf("%d\n",l1->val);
																																																																									          l1 = l1->next;
																																																																											          l2 = l2->next;
																																																																													          
																																																																															      }
																																																																																      return curNode;
																																																																																	  }
