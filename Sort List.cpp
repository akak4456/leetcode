if(!head || !head->next) return head; // If only 1 element simply return
        if(!head->next->next) { // If 2 elements, do a swap if necessary
            if(head->val > head->next->val) {
                auto tmp = head;
                head = head->next;
                head->next = tmp;
                tmp->next = nullptr;
            }
            return head;
        }
        
        ListNode* mid = head, *end = head, *nextStart, *sortedLeft, *sortedRight, *newH = new ListNode(-1), *ref = newH;
        
        while(end) { // Find mid point
            end = end->next;
            if(end) end = end->next; 
            if(end) mid = mid->next;
        }
        
        nextStart = mid->next; mid->next = nullptr; // Disconnect first half from second half
        
        sortedLeft = sortList(head); sortedRight = sortList(nextStart); // Recursively sort the halves
        
        while(true) { // Merge
            if(!sortedLeft) {newH->next = sortedRight; return ref->next;}
            if(!sortedRight) {newH->next = sortedLeft; return ref->next;}
            
            if(sortedLeft->val < sortedRight->val) {
                newH = newH->next = sortedLeft;
                sortedLeft = sortedLeft->next;
            }
            else {
                newH = newH->next = sortedRight;
                sortedRight = sortedRight->next;
            }
        }
        
        return ref->next;