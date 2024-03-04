 void slove(stack<int> &inptstack, int cnt, int size){
    if(cnt==size/2){
        inptstack.pop();
        return ;
    }
    int num = inptstack.top();
    inptstack.pop();
    solve(inptstack, cnt+1, size);
    inptstack.push(num);
 }


void deleteMiddleElementfromstack(stack<int> &inputstack,  int N){
    int count = 0;
    slove(inputstack, count, N);
}