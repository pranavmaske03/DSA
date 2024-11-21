#include"LinkedList.h"

int Height(struct NodeBST *root)
{
    if(root == NULL) return 0;

    int left_height = Height(root->lchild);
    int right_height = Height(root->rchild);

    return (left_height > right_height ? left_height : right_height) + 1;
}

void PrintCurrentLevel(struct NodeBST *root,int level)
{
    if(root == NULL) return;

    if(level == 1)
    {
        printf("%d\t",root->data);
    }
    else if(level > 1)
    {
        PrintCurrentLevel(root->lchild,level-1);
        PrintCurrentLevel(root->rchild,level-1);
    }
}

void PrintCurrentOrder(struct NodeBST *root)
{
    int height = Height(root);
    for(int i = 1; i <= height; i++)
    {
        PrintCurrentLevel(root,i);
    }
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
    
    PrintCurrentOrder(first1);

    return 0;
}