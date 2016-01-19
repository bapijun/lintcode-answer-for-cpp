class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        if(lists.empty()) return nullptr;
        vector<ListNode* > heap;
        // 1. 选出每个链表的头来插入小顶堆中，
        for(int i = 0; i != lists.size(); i ++){
           if(lists[i]) heap.push_back(lists[i]);
        }
        makeHeap(heap);
        // 2. 再把堆顶接入合并链表中，
        ListNode head(-1); // 合并链表的表头
        ListNode* p = &head;
        while(!heap.empty()){
            auto minNode = heap[0];
            p->next = minNode; // 接入链表
            p = p->next;
            // 3. 被选出的指针后移再加入小顶堆中,回到2
            auto next = minNode->next;
            if(next) {
                heap[0] = next;
            }else{
                swap(heap[0], heap[heap.size()-1]);
                heap.pop_back();
            }
            minHeap(heap, 1);
        }
        // 4. 最后所有链表都为空时，返回合并链表的头指针
        return head.next;
    }
    // 建立小顶堆
    // 自低向上
    void makeHeap(vector<ListNode*> &heap){
        // 从最后一个元素的父节点开始建立小顶堆
        for(int i = heap.size()/2; i >0 ; i --){
            minHeap(heap, i);
        }
    }
    // 小顶堆,以第i个元素为根建立小顶堆
    //位置从1开始，取元素时记得-1
    // 自顶向下
    void minHeap(vector<ListNode*> &heap, int i){
        int l = i*2;
        int r = l+1;
        int least(i);
        // 算出最小元素的位置
        if((l< heap.size()+1) && heap[l-1]->val<heap[i-1]->val ){
            // 如果没有超过边界并且左孩子比父亲小，则换
            least = l;
        }
        if(r<heap.size()+1 && heap[r-1]->val<heap[least-1]->val){
            // 如果没有超过边界并且右孩子最小，则换
            least = r;
        }
        if(least != i){
            swap(heap[i-1], heap[least-1]);
            minHeap(heap, least);
        }
    }
};
