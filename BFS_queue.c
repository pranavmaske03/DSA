#include"LinkedList.h"

void Print_Tree(struct NodeBST **queue,int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\t",queue[i]->data);
    }
    printf("\n");
}

void BFS(struct NodeBST *root)
{
    if(root == NULL) return;

    struct NodeBST *queue[500];
    struct NodeBST *tmp_node = NULL;
    int rear = 0,front = 0,tmp = 0;

    queue[rear++] = root;
    while(front < rear)
    {
        tmp = rear - front;
        for(int i = 0; i < tmp; i++)
        {
            tmp_node = queue[front++];
            if(tmp_node->lchild != NULL)
            {
                queue[rear++] = tmp_node->lchild;
            }
            if(tmp_node->rchild != NULL)
            {
                queue[rear++] = tmp_node->rchild;
            }
        }
    }
    Print_Tree(queue,rear);
}

int main()
{
    struct NodeBST* first1 = NULL;
    bool bRet = false;

    Insert(&first1,52);
    Insert(&first1,13);
    Insert(&first1,23);
    Insert(&first1,27);
    Insert(&first1,36);
    Insert(&first1,17);
    
    BFS(first1);

    return 0;
}