//----------------------------------------------------------------------------------
// [ Stack ]
//----------------------------------------------------------------------------------

#include <stdio.h>

template <typename T>
class stack {
private:
    struct node {
        T val;
        node *pPrev = 0;
        node() {}
        node(T val) : val(val) {}
    };

    node* m_pTop = 0;
    unsigned int m_iSize = 0;

public:
    stack() {}
    ~stack() {
        node *pNode = m_pTop;
        while (pNode) {
            m_pTop = m_pTop->pPrev;
            delete pNode;
            pNode = m_pTop;
        }
    }

    unsigned int size() { return m_iSize; }
    bool empty() { return m_iSize == 0; }
    T& top() { return m_pTop->val; }

    void push(T val) {
        node *pNode = new node(val);
        pNode->pPrev = m_pTop;
        m_pTop = pNode;
        ++m_iSize;
    }

    void pop() {
        if (!m_iSize) return;
        node *pNode = m_pTop;
        m_pTop = m_pTop->pPrev;
        delete pNode;
        --m_iSize;
    }
};

int main() {
    stack<int> stk;

    for (int i = 1; i <= 10; ++i)
        stk.push(i);

    printf("stk.top(): %d / stk.size(): %d / stk.empty(): %d\n", stk.top(), stk.size(), stk.empty());    
    // stk.top(): 10 / stk.size(): 10 / stk.empty(): 0

    for (int i = 0; i < 5; ++i)
        stk.pop();

    printf("stk.top(): %d / stk.size(): %d / stk.empty(): %d\n", stk.top(), stk.size(), stk.empty());
    // stk.top(): 5 / stk.size(): 5 / stk.empty(): 0

    while (!stk.empty())
        stk.pop();

    printf("stk.size(): %d / stk.empty(): %d\n", stk.size(), stk.empty());
    // stk.size(): 0 / stk.empty(): 1
}