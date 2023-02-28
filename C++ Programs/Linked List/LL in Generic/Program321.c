#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}

void InsertLast(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *First;
    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)
    {
        return;
    }
    else if((*First) -> next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        (*First) = (*First)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(temp ->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE First)
{
    printf("Elements of linked List are :\n");
    
    while(First != NULL)
    {
        printf("| %d |->",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

int Count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

void InsertAtPos(PPNODE First, int no, int ipos)
{
    int iCnt = 0;
    int iNodeCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    iNodeCnt = Count(*First);
    printf("Count is %d\n",iNodeCnt);

    if((ipos < 1) || (ipos > (iNodeCnt+1)))
    {
        printf("Invalid Position \n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First,no);
    }
    if(ipos == (iNodeCnt+1))
    {
        InsertLast(First,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *First;

        for(iCnt = 1;iCnt < (ipos -1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE First, int no,int ipos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    int iCnt = 0;
    int iNodeCnt = 0;

    iNodeCnt = Count(*First);
    printf("Count is : %d\n",iNodeCnt);
    
    if((ipos < 1) || (ipos > (iNodeCnt + 1)))
    {
        printf("Invalid Input\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First);
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;

        for(iCnt = 1;iCnt <(ipos -1); iCnt++)
        {
            temp1 = temp1 -> next;
        }
        temp2 = temp1 ->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);
    Display(Head);
    iRet = Count(Head);
    printf("Total nodes in LL are : %d\n",iRet);

    InsertLast(&Head, 101);
    InsertLast(&Head, 111);
    InsertLast(&Head, 121);
    Display(Head);
    iRet = Count(Head);
    printf("Total nodes in LL after Insert are : %d\n",iRet);

    InsertAtPos(&Head,105,5);
    Display(Head);
    iRet = Count(Head);
    printf("Total nodes in LL after InsertAtPos are : %d\n",iRet);

    DeleteFirst(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Total nodes in LL after Delete First are : %d\n",iRet);

    DeleteLast(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Total nodes in LL after Delete last are : %d\n",iRet);

    DeleteAtPos(&Head,105,5);
    Display(Head);
    iRet = Count(Head);
    printf("Total nodes in LL after deleteAtPos are : %d\n",iRet);

    return 0;
}