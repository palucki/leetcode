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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* root = new ListNode{};
    ListNode* current = root;
    bool overflow = false;

    while (l1 || l2)
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + current->val;
        if (sum >= 10)
        {
            sum = sum % 10;
            overflow = true;
        }

        current->val = sum;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        
        if (l1 || l2 || overflow)
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