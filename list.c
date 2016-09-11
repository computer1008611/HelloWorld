/* 算法之单向链表 */ 
/*
 * 链表的优点：
 1）单个节点创建非常方便，普通的线性内存通常在创建的时候就需要设定数据的大小；
 2）节点的删除非常方便，不需要像线性结构那样移动剩下的数据；
 3）节点的访问方便，可以通过循环或者递归的方法访问到任意数据，但是平均的访问效率低于线性表
*/

typedef struct _LINK_NODE  
{  
    int data;  
    struct _LINK_NODE* next;  
}LINK_NODE; 

/* create the node */
LINK_NODE* alloca_node(int value)  
{  
    LINK_NODE* pLinkNode = NULL;  
    pLinkNode = (LINK_NODE*)malloc(sizeof(LINK_NODE));  
      
    pLinkNode->data = value;  
    pLinkNode->next = NULL;  
    return pLinkNode;  
}  

void delete_node(LINK_NODE** pNode)  
{  
    LINK_NODE** pNext;  
    if(NULL == pNode || NULL == *pNode)  
        return ;  
          
    pNext = &(*pNode)->next;  
    free(*pNode);  
    delete_node(pNext);   
}  

STATUS _add_data(LINK_NODE** pNode, LINK_NODE* pDataNode)  
{  
    if(NULL == *pNode){  
        *pNode = pDataNode;  
        return TRUE;  
    }  
      
    return _add_data(&(*pNode)->next, pDataNode);  
}  
  
STATUS add_data(const LINK_NODE** pNode, int value)  
{  
    LINK_NODE* pDataNode;  
    if(NULL == *pNode)  
        return FALSE;  
          
    pDataNode = alloca_node(value);  
    assert(NULL != pDataNode);  
    return _add_data((LINK_NODE**)pNode, pDataNode);  
}  

STATUS _delete_data(LINK_NODE** pNode, int value)  
{  
    LINK_NODE* pLinkNode;  
    if(NULL == (*pNode)->next)  
        return FALSE;  
      
    pLinkNode = (*pNode)->next;  
    if(value == pLinkNode->data){  
        (*pNode)->next = pLinkNode->next;  
        free(pLinkNode);  
        return TRUE;  
    }else{  
        return _delete_data(&(*pNode)->next, value);  
    }  
}  
  
STATUS delete_data(LINK_NODE** pNode, int value)  
{  
    LINK_NODE* pLinkNode;  
    if(NULL == pNode || NULL == *pNode)  
        return FALSE;  
  
    if(value == (*pNode)->data){  
        pLinkNode = *pNode;  
        *pNode = pLinkNode->next;  
        free(pLinkNode);  
        return TRUE;  
    }         
      
    return _delete_data(pNode, value);  
}  

LINK_NODE* find_data(const LINK_NODE* pLinkNode, int value)  
{  
    if(NULL == pLinkNode)  
        return NULL;  
      
    if(value == pLinkNode->data)  
        return (LINK_NODE*)pLinkNode;  
      
    return find_data(pLinkNode->next, value);  
}  

void print_node(const LINK_NODE* pLinkNode)  
{  
    if(pLinkNode){  
        printf("%d\n", pLinkNode->data);  
        print_node(pLinkNode->next);  
    }  
}  

int count_node(const LINK_NODE* pLinkNode)  
{  
    if(NULL == pLinkNode)  
        return 0;  
          
    return 1 + count_node(pLinkNode->next);  
}  




















