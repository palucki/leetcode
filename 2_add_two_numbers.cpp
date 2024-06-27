#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* l)
{
    while(l)
    {
        std::cout << l->val << "->";
        l = l->next;
    }
    std::cout << '\n';
}

// 2 4 3
// 5 6 4

struct Nodes {
    ListNode* current;
    ListNode* l1;
    ListNode* l2;
};

Nodes addBothValid(ListNode* l1, ListNode* l2, ListNode* current, bool& overflow)
{
    while(l1 && l2)
    {
        std::cout << "l1 = " << l1->val << " l2 = " << l2->val << '\n';

        int sum = l1->val + l2->val + current->val;
        if (sum >= 10)
        {
            sum = sum % 10;
            overflow = true;
        }

        current->val = sum;

        l1 = l1->next;
        l2 = l2->next;
        if(l1 || l2 || overflow)
        {
            current->next = new ListNode{};
            current = current->next;
            if (overflow)
            {
                current->val = 1;
                overflow = false;
            }
        }
    }

    return {current, l1, l2};
}

ListNode* addOneValid(ListNode* l1, ListNode *current, bool& overflow)
{
    while(l1)
    {
        int sum = l1->val + current->val;
        if (sum >= 10)
        {
            sum = sum % 10;
            overflow = true;
        }

        current->val = sum;

        l1 = l1->next;
        if(l1 || overflow)
        {
            current->next = new ListNode{};
            current = current->next;
            if (overflow)
            {
                current->val = 1;
                overflow = false;
            }
        }
    }

    return current;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* root = new ListNode{};
    ListNode* current = root;
    bool overflow = false;

    Nodes n = addBothValid(l1, l2, current, overflow);
    current = n.current;
    l1 = n.l1;
    l2 = n.l2;

    std::cout << "ended with current value " << current->val << '\n';

    // add left from l1
    current = addOneValid(l1, current, overflow);

    std::cout << "ended with current value " << current->val << '\n';

    current = addOneValid(l2, current, overflow);

    std::cout << "ended with current value " << current->val << '\n';

    return root;
}

void test(ListNode* l1, ListNode* l2)
{
    auto* result = addTwoNumbers(l1, l2);
    print(result);
}

int main()
{
    ListNode l17{9};
    ListNode l16{9, &l17};
    ListNode l15{9, &l16};
    ListNode l14{9, &l15};
    ListNode l13{9, &l14};
    ListNode l12{9, &l13};
    ListNode l11{9, &l12};

    ListNode l24{9,};
    ListNode l23{9, &l24};
    ListNode l22{9, &l23};
    ListNode l21{9, &l22};

    print(&l11);
    print(&l21);

    test(&l11, &l21);

    return 0;
}