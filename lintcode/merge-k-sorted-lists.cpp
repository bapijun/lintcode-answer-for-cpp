class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) {
			return nullptr;
		}
		ListNode* Result = nullptr;
		ListNode* NowResult = nullptr;
		while(!lists.empty()) {
			int Min = INT_MAX;
			vector<ListNode*>::iterator NowIte;
			for(vector<ListNode*>::iterator ListIte = lists.begin(); ListIte != lists.end(); ) {
				if(nullptr == *ListIte) {
					ListIte = lists.erase(ListIte);//自动移动到ListIte下一位
				}
				else {
					if((*ListIte)->val < Min) {
						Min = (*ListIte)->val;
						NowIte = ListIte;
					}
					ListIte++;	
				}//end of else
			}//end of for
			if(Min != INT_MAX) {
				ListNode* tem = new ListNode(Min);
				if(nullptr == NowResult) {
					Result = tem;
					NowResult = tem;
					(*NowIte) = (*NowIte)->next;
				}
				else {
					NowResult->next = tem;
					NowResult = NowResult->next;
					(*NowIte) = (*NowIte)->next;
				}//end of else
			}//end of if
		}//end of while
		return Result;
    }
};
