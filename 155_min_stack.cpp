#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <set>
#include <limits>

class MinStack {
public:
    MinStack()
    {
    }
    
    void push(int val) 
    {
        if(m_data.empty())
        {
            m_data.push_back({val, std::min(val, val)});
            return;
        }
        
        int current_min = m_data[m_data.size() - 1].second;
        m_data.push_back({val, std::min(val, current_min)});
    }
    
    void pop() 
    {
        m_data.erase(m_data.end() - 1);
    }
    
    int top() 
    {
        return m_data[m_data.size() - 1].first;
    }
    
    int getMin() 
    {
        return m_data[m_data.size() - 1].second;
    }

private:
    std::vector<std::pair<int, int>> m_data;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack* obj = new MinStack();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    std::cout << "Min: " << obj->getMin() << '\n';
    obj->pop();
    std::cout << "Min: " << obj->getMin() << '\n';

    return 0;
}