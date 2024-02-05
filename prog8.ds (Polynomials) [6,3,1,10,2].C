#include<stdio.h>
#include<stdlib.h>

struct polynomial
{
    int coeff;
    int power;
    struct polynomial *LINK;
};

typedef struct polynomial NODE;
NODE *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

NODE *create_poly();
NODE *add_poly(NODE *poly1, NODE *poly2);
void display_poly(NODE *ptr);

NODE *create_poly()
{
    int coeff, pow;
    int flag;
    NODE *tmp_node = (NODE *)malloc(sizeof(NODE));
    NODE *poly = tmp_node;

    do
    {
        printf("\n Enter Coeff: ");
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;

        printf("\n Enter pow: ");
        scanf("%d", &pow);
        tmp_node->power = pow;

        tmp_node->LINK = NULL;

        printf("\n Do you want to add one more node? [Y=1/N=0]");
        scanf("%d", &flag);

        if (flag == 1)
        {
            tmp_node->LINK = (NODE *)malloc(sizeof(NODE));
            tmp_node = tmp_node->LINK;
            tmp_node->LINK = NULL;
        }
    } while (flag);

    return poly;
}

NODE *add_poly(NODE *poly1, NODE *poly2)
{
    NODE *tmp_node, *poly;
    tmp_node = (NODE *)malloc(sizeof(NODE));
    tmp_node->LINK = NULL;
    poly3 = tmp_node;

    while (poly1 && poly2)
    {
        if (poly1->power > poly2->power)
        {
            tmp_node->power = poly1->power;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->LINK;
        }
        else if (poly1->power < poly2->power)
        {
            tmp_node->power = poly2->power;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->LINK;
        }
        else
        {
            tmp_node->power = poly1->power;
            tmp_node->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->LINK;
            poly2 = poly2->LINK;
        }

        if (poly1 && poly2)
        {
            tmp_node->LINK = (NODE *)malloc(sizeof(NODE));
            tmp_node = tmp_node->LINK;
            tmp_node->LINK = NULL;
        }
    }

    while (poly1 || poly2)
    {
        tmp_node->LINK = (NODE *)malloc(sizeof(NODE));
        tmp_node = tmp_node->LINK;
        tmp_node->LINK = NULL;

        if (poly1)
        {
            tmp_node->power = poly1->power;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->LINK;
        }
        if (poly2)
        {
            tmp_node->power = poly2->power;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->LINK;
        }
    }

    return poly3;
}

void display_poly(NODE *ptr)
{
    while (ptr != NULL)
    {
        printf("%d x^%d", ptr->coeff, ptr->power);
        ptr = ptr->LINK;
        if (ptr != NULL)
            printf(" + ");
    }
}

int main()
{
    printf("\n Create 1st polynomial \n");
    poly1 = create_poly();
    printf("\n The first polynomial expression is :\n");
    display_poly(poly1);

    printf("\n Create 2nd polynomial \n");
    poly2 = create_poly();
    printf("\n The second polynomial is : \n");
    display_poly(poly2);

    poly3 = add_poly(poly1, poly2);
    printf("\n The Addition of two polynomials is : ");
    display_poly(poly3);

    return 0;
}
