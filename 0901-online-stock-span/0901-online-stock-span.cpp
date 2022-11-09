class StockSpanner {
protected:
    stack<pair<int, int>> stack; // monotonic stack - {price, answer}
public:
    StockSpanner() {}
    
    int next(int price) {
        int ans = 1; // the price itself
        while(!stack.empty() && stack.top().first <= price)
        {
            ans += stack.top().second;
            stack.pop();
        }
        stack.push({price, ans});
        return ans;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */