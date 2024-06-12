#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <set>

class MinStack {
public:
    MinStack()
    {
    }
    
    void push(int val) 
    {
        m_mins.insert(val);
        m_data.push_back(val);
    }
    
    void pop() 
    {
        const auto elem_it = m_data.end() - 1;

        m_mins.erase(m_mins.find(*elem_it));
        m_data.erase(elem_it);
    }
    
    int top() 
    {
        return m_data[m_data.size() - 1];
    }
    
    int getMin() 
    {
        return *m_mins.begin();
    }

private:
    std::multiset<int> m_mins;
    std::vector<int> m_data;
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