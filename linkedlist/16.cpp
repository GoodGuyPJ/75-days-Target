//approch for add 2 number respresented by linked list

Node* addtwoLL(Node* fist, Node* second){
    first = reverse(first);
    second = reverse(second);

    Node* ans  = add(first, second);
    ans = reverse(ans);
    return ans;

}

Node* add(first, second){
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first!= NULL || second!=NULL|| carry!=NULL){
        int val1 = 0;
        if(first!= NULL) val1 = first->data;
        int val2 =0;
        if(second!= NULL) val2 = second->data;

        int sum = val1+val2+carry;
        int digit = sum %10;
        insertatTail(anshead, anstail, digit);
        carry = sum/10;
        if(first!= NULL){
            first = first->next;
        }
        if(second!= NULL){
            second = second->next;
        }
        return anshead;
    }
}