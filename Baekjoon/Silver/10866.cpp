//----------------------------------------------------------------------------------
// [ 덱 ] https://www.acmicpc.net/problem/10866
//----------------------------------------------------------------------------------

#include <iostream>

typedef struct NODE {
    int val;
    NODE *pPrev = NULL, *pNext = NULL;
} *PNODE;

int main() {
    int n, val, i, size = 0;
    char cmd[20];
    PNODE pBegin = new NODE(), pEnd = new NODE(), pNode, pNext;
    
    pBegin->pNext = pEnd; 
    pEnd->pPrev = pBegin;

    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%s", cmd);
        switch (cmd[1]) {
            case 'u':       // push
            scanf("%d", &val);
            pNode = new NODE({val});
            if (cmd[5] == 'f') {
                pNode->pNext = pBegin->pNext;
                pNode->pPrev = pBegin;
                pBegin->pNext->pPrev = pNode;
                pBegin->pNext = pNode;
            } else {
                pNode->pNext = pEnd;
                pNode->pPrev = pEnd->pPrev;
                pEnd->pPrev->pNext = pNode;
                pEnd->pPrev = pNode;
            }
            ++size;
            break;
            
            case 'o':       // pop
            if (size == 0) {
                printf("%d\n", -1);
            } else {
                pNode = (cmd[4] == 'f') ? pBegin->pNext : pEnd->pPrev;
                pNode->pPrev->pNext = pNode->pNext;
                pNode->pNext->pPrev = pNode->pPrev;
                printf("%d\n", pNode->val);
                --size;
                delete pNode;
            }
            break;

            case 'i':       // size
            printf("%d\n", size);
            break;

            case 'm':       // empty
            printf("%d\n", size == 0);
            break;

            case 'r':       // front
            printf("%d\n", (size == 0) ? -1 : pBegin->pNext->val);
            break;

            case 'a':       // back
            printf("%d\n", (size == 0) ? -1 : pEnd->pPrev->val);
            break;
        }
    }
    
    pNode = pBegin;
    while (pNode != NULL) {
        pNext = pNode->pNext;
        delete pNode;
        pNode = pNext;
    }
}