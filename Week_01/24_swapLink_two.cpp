#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
}

int main()
{
    vector<int> link = {1, 2, 3, 4, 5, 6};
    ListNode* cur = new ListNode(link[0]);
    ListNode* head = cur;
    for (int i = 1; i < link.size(); ++i)
    {
        cur->next = new ListNode(link[i]);
        cur = cur->next;
    }

    auto res = swapPairs(head);
    while(res != NULL){
        cout<<res->val<<" ";
        res = res->next;
    }

}