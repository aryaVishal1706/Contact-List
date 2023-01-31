#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i = 0;
struct node
{
    long int ph;
    char name[20];
    struct node *Right;
    struct node *Left;
} *root = NULL;
void search(struct node *ptr, char name[])
{
    if (root == NULL)
    {
        return;
    }
    else if(strcmp(ptr->name, name) > 0){
    if(ptr->Left!=NULL){
        ptr = ptr -> Left;
        search(ptr, name);
        }
    else{
            printf("No Contact was Found.\n");
        }
}
    else if(strcmp(ptr->name, name)<0){
        if(ptr->Right!=NULL){
        ptr = ptr -> Right;
        search(ptr, name);
        }
        else{
        printf("No Contact was Found.\n");
           }
    }
    else if(strcmp(ptr->name, name)==0){
        printf("Name\t\tPhone Number\n");
        printf("%s\t\t%ld\n\n", ptr->name, ptr->ph);
    }
}

void insert()
{
    struct node *n = (struct node *)(malloc(sizeof(struct node)));
    printf("\nEnter your Name:\n");
    scanf("%s", n->name);
    printf("Enter Phone Number:\n");
    scanf("%ld", &n->ph);
    n->Left = NULL;
    n->Right = NULL;
    if (root == NULL)
    {
        root = n;
        return;
    }
    struct node *ptr = root, *temp = NULL;
    int fl = 0;
    while (ptr != NULL && fl == 0)
    {
        if (strcmp(n->name, ptr->name) == 0)
        {
            fl = 1;
            printf("Name exists..\n");
            return;
        }
        else if (strcmp(n->name, ptr->name) > 0)
        {
            temp = ptr;
            if (temp->Right == NULL)
            {
                temp->Right = n;
                return;
            }
            else
            {
                ptr = ptr->Right;
            }
        }
        else if (strcmp(n->name, ptr->name) < 0)
        {
            temp = ptr;
            if (temp->Left == NULL)
            {
                temp->Left = n;
                return;
            }
            else
            {
                ptr = ptr->Left;
            }
        }
    }

}
struct node* delete(char name[]){
    struct node *t=root,*t1=NULL;
    //SEARCHING NODE
    while(t!=NULL && strcmp(t->name,name)!=0){
            t1=t;
    if(strcmp(t->name,name)<0){
     t=t->Right;
    }
    else{
        t=t->Left;
    }
}
    //CASES
    if(t->Left==NULL && t->Right==NULL){
        //CASE-1 Leaf Node
        if(t1==NULL){
            root=NULL;
             printf("Contact Deleted.\n");
        }
        else {
                if(t1->Left==t){
            t1->Left=NULL;
        }
        else{
             t1->Right=NULL;
        }
           printf("Contact Deleted.\n");
        }
    }
    else if((t->Left!=NULL) && (t->Right!=NULL)){
        //CASE-3 TWO CHILD NODES
          	struct node *s,*x;
			s=t->Right;
				while(s->Left!=NULL)
				{
					s=s->Left;
				}
				x=(struct node *)malloc(sizeof(struct node));
				strcpy(x->name,s->name);
				x->ph=s->ph;

				delete(s->name);
				t->ph=x->ph;
				strcpy(t->name,x->name);
			}
    else{
        //CASE-2 ONE CHILD NODE
        if(t1==NULL){
            if(t->Left!=NULL){
                root=t->Left;
            }
            else{
                root=t->Right;
            }
        }
        else{
        if(t1->Left==t){
            if(t->Left==NULL){
                t1->Left=t->Right;
            }
            else{
                t1->Left=t->Left;
            }
        }
        else{
            if(t1->Right==t){
            if(t->Left==NULL){
                t1->Right=t->Right;
            }
            else{
                t1->Right=t->Left;
                }
            }
        }
        }
        printf("Contact Deleted.\n");
    }
    return t;
}
void displayI(struct node *r1)
{
    struct node *ptr = r1;
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        displayI(ptr->Left);
        printf("%d\t%s\t\t%ld\n\n", i, ptr->name, ptr->ph);
        i++;
        displayI(ptr->Right);
    }
}
void displayD(struct node *r1)
{
    struct node *ptr = r1;
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        displayD(ptr->Right);
        printf("%d\t%s\t\t%ld\n\n", i, ptr->name, ptr->ph);
        i++;
        displayD(ptr->Left);
    }
}
int main()
{
    char str2[10],del[10];
    struct node *tcs;
    int n;
    while (1)
    {
        printf("-------- MENU --------\n");
        printf("1.Add Contact.\n");
        printf("2.Delete Contact.\n");
        printf("3.Search Contact.\n");
        printf("4.sort in Ascending Order.\n");
        printf("5.sort in Descending Order.\n");
        printf("6.Exit.\n");

        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert();
            printf("\n");
            break;
        case 2:
            printf("Enter name you want to delete:");
            scanf("%s",del);
            delete(del);
            printf("\n");
            break;
        case 3:
            printf("\nEnter name you want to search:");
            scanf("%s", str2);
            printf("\n");
            search(root, str2);
            printf("\n");
            break;
        case 4:
            printf("Sr.No\tName\t\tPhone Number\n");
            printf("\n");
            i = 1;
            displayI(root);
            printf("\n");
            break;
        case 5:
            printf("Sr.No\tName\t\tPhone Number\n");
            printf("\n");
            i = 1;
            displayD(root);
            printf("\n");
            break;
        case 6:
            exit(0);
        default:
            printf("Enter Valid choice..\n");
            break;
        }
    }
    return 0;
}
