#include <stdio.h> #include<conio.h> #include<malloc.h> #include<stdlib.h> typedef struct student
{
    int sno;
    char sname[20];
    struct student *next;
}
node;
node *first = NULL, *last, *new1, *temp;
void createnode()
{
    new1 = (node *)malloc(sizeof(node));
    printf("Enter sno:");
    scanf("%d", &new1->sno);
    printf("Enter sname:");
    scanf("%s", &new1->sname);
    new1->next = NULL;
}
void printnode(node *head, int n)
{
    int i = 1;
    node *temp = head;
    while (i < n)
    {
        temp = temp->next;
        i++;
    }
    printf("%d", temp->data);
}
void append()
{
    createnode();
    if (first == NULL)
    {
        first = new1;
        last = new1;
    }
    else
    {
        last->next = new1;
        last = new1;
    }
}
void insert()
{
    int pos, i = 1;
    node *temp1, *temp2;
    createnode();
    printf("\n enter position:");
    scanf("%d", &pos);
    temp1 = first;
    while (i < pos)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        i++;
    }
    temp2->next = new1;
    new1->next = temp1;
}
void edit()
{
    int no;
    node *temp;
    printf("Enter no to modify");
    scanf("%d", &no);
    temp = first;
    while (temp != NULL)
    {
        if (no == temp->sno)
        {
            printf("\n Enter new no andnew name");
            scanf("%d%s", &temp->sno, temp->sname);
        }
        temp = temp->next;
    }
}
void display()
{
    int c = 0;
    if (first == NULL)
        printf("\n list is empty");
    else
    {
        for (temp = first; temp != NULL; temp = temp->next)
        {
            c++;
            printf("\n %d : %s", temp->sno, temp->sname);
        }
    }
    printf("\n no. of nodes:%d", c);
    getch();
}
void main()
{
    int o;
    do
    {
        printf("\n LINKED LIST MENU");
        printf("\n 1.ADD FIRST \n 2.APPEND \n 3.INSERT \n 4. EDIT");
        printf("\n 5.DISPLAY \n 6.exit");
        printf("\n Enter ur option:");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            printnode();
            break;
        case 2:
            append();
            break;
        case 3:
            insert();
            break;
        case 4:
            edit();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        }
    } while (o <= 6);
    getch();
}
