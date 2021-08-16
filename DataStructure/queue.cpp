//----------------------------------------------------------------------------------
// [ Queue ]
//----------------------------------------------------------------------------------

#include <stdio.h>

template <typename T>
class queue {
private:
    struct node {
        T val;
        node *pNext = 0;
        node *pPrev = 0;
        node() {}
        node(T val) : val(val) {}
    };
    
    node *m_pBegin = 0;
    node *m_pEnd = 0;
    unsigned int m_iSize = 0;

public:
    queue() { m_pEnd = new node(); }
    ~queue() {
        while (m_iSize) pop();
        delete m_pEnd;
    }

    unsigned int size() { return m_iSize; }
    bool empty() { return m_iSize == 0; }
    T& front() { return m_pBegin->val; }
    T& back() { return m_pEnd->pPrev->val; }

    void push(T val) {
        node *pNode = new node(val);
        pNode->pPrev = m_pEnd->pPrev;
        pNode->pNext = m_pEnd;
        if (m_iSize) m_pEnd->pPrev->pNext = pNode;
        else m_pBegin = pNode;
        m_pEnd->pPrev = pNode;
        ++m_iSize;
    }

    void pop() {
        if (!m_iSize) return;
        m_pBegin = m_pBegin->pNext;
        delete m_pBegin->pPrev;
        --m_iSize;
    }
};

int main() {
    queue<int> q;

    for (int i = 1; i <= 10; ++i)
        q.push(i);

    printf("q.front(): %d / q.back(): %d / q.size(): %d / q.empty(): %d\n", q.front(), q.back(), q.size(), q.empty());
    // q.front(): 1 / q.back(): 10 / q.size(): 10 / q.empty(): 0

    for (int i = 0; i < 5; ++i)
        q.pop();

    printf("q.front(): %d / q.back(): %d / q.size(): %d / q.empty(): %d\n", q.front(), q.back(), q.size(), q.empty());
    // q.front(): 6 / q.back(): 10 / q.size(): 5 / q.empty(): 0

    while (!q.empty())
        q.pop();

    printf("q.size(): %d / q.empty(): %d\n", q.size(), q.empty());
    // q.size(): 0 / q.empty(): 1
}
