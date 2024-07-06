// https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here 
        if(head == NULL) return;
        Node* it = head;
        
        for(int i = 0 ; i < M-1 ; i++) {
            if(it == NULL) {
                return;
            }
            it = it->next;
        }
        // after reaching mth node
        if(it == NULL) return;
        Node* MthNode = it;
        it = MthNode->next;
        
        for(int i = 0 ; i < N ; i++) {
            if(it == NULL) break;
            
            Node* temp = it->next;
            delete it;
            it = temp;
        }
        
        MthNode->next = it;
        
        linkdelete(it,M,N);
    }
};



