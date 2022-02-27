#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct kolejka_prio
{
    int liczba;
    int priorytet;
    struct kolejka_prio *next;
}kolejka_prio;


int losuj(int min, int max)
{
	return (rand()%(max-min+1)+min);
}

void addQ(kolejka_prio **head, int n, int prio, int num)
{
    struct kolejka_prio* nowa = (struct kolejka_prio*)malloc(sizeof(struct kolejka_prio));
    nowa->priorytet = prio;
    nowa->liczba = num;
    nowa->next = NULL;
    if((*head)==NULL)
     {
        *head = nowa;
     }
     else
     {
         if(counter(*head) == n)
         {

         }
         else
         {
             kolejka_prio* wsk = *head;
             while((wsk)->next != NULL)
             {
                wsk = wsk->next;
             }
             wsk->next = nowa;
         }
     }
}

int counter(kolejka_prio *head)
{
    int counter = 0;
    kolejka_prio *wsk = head;
    while(wsk != NULL)
    {
        counter++;
        wsk = wsk->next;
    }
    return counter;
}

bool isEmpty(kolejka_prio *head)
{
    if(head==NULL)
    {

        return true;
    }
    else
    {

        return false;
    }
}

bool isFull(kolejka_prio *head, int n)
{
    if(counter(head)==n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Show(kolejka_prio **head)
{
    kolejka_prio* wsk = head;
    if(head == NULL)
    {
         printf("Kolejka jest pusta\n");
    }
    else
    {
        while(wsk != NULL)
        {
            printf("[%d] %d\n", wsk->priorytet, wsk->liczba);
            wsk = wsk->next;
        }
    }
}

void usunHead(kolejka_prio **head)
{
        kolejka_prio *temp = *head;
        (*head)=(*head)->next;
        printf("[Priorytet %d] %d\n\n", temp->priorytet, temp->liczba);
        free(temp);
}

int main()
{
    int komenda, n;
    kolejka_prio *head1 = NULL;
    kolejka_prio *head2 = NULL;
    kolejka_prio *head3 = NULL;
    kolejka_prio *head4 = NULL;
    kolejka_prio *tablicaHead[4] = {head1,head2,head3,head4};
    printf("Podaj n jako wielkosc kolejek: \n");
    scanf("%d", &n);
	while(1)
    {
        printf("Program kolejek\n");
        printf("----------------------------------------------\n");
        printf("[0] Wyjscie z programu\n");
        printf("[1] Kliknij 1 aby program dzialal dalej\n");
        printf("[2] Wyswietl kolejki\n");
        printf("----------------------------------------------\n\n");
		printf("\nWybrana komenda: ");
		scanf("%d", &komenda);
		printf("\n");
		switch (komenda)
		{
			case 0: return 0; break;
			case 1:
			    srand(time(0));
			    for(int i =0; i<4; i++)
                {
                    int prio = losuj(1,n);
                    int num = losuj(1,100);
                    int min;
                    int minHead;
                    if(isEmpty(tablicaHead[i]) == true)
                    {
                        if(isFull(tablicaHead[i], n) == true)
                        {
                            printf("Kolejka [%d] jest pelna!!!\n\n", i);
                        }
                        else
                        {
                            printf("Do kolejki [%d] dodano: [Priorytet %d] %d\n\n", i, prio, num);
                        }
                        addQ(&tablicaHead[i], n, prio, num);
                    }
                    else
                    {
                        min = counter(tablicaHead[i]);
                        for(int j = 0; j<4; j++)
                        {
                            if(counter(tablicaHead[j])< min)
                            {
                                min = counter(tablicaHead[j]);
                                minHead = j;
                            }
                        }
                        if(isFull(tablicaHead[minHead], n) == true)
                        {
                            printf("Kolejka [%d] jest pelna!!!\n\n", minHead);
                        }
                        else
                        {
                            printf("Do kolejki [%d] dodano: [Priorytet %d] %d\n\n", minHead, prio, num);
                        }
                        addQ(&tablicaHead[minHead], n, prio, num);
                    }
                }

                int najw = 0;
                int najw2 = 0;
                int najwHead1;
                int najwHead2;
                for(int j = 0; j<4; j++)
                {
                    if(tablicaHead[j]->priorytet > najw)
                    {
                        najw = tablicaHead[j]->priorytet;
                        najwHead1 = j;
                    }
                }
                for(int k = 0; k<4; k++)
                {
                    if(tablicaHead[k] != tablicaHead[najwHead1])
                    {
                        if((tablicaHead[k]->priorytet > najw2))
                        {
                            najw2 = tablicaHead[k]->priorytet;
                            najwHead2 = k;
                        }
                    }
                }
                printf("Z kolejki [%d] usunieto: ", najwHead1);
                usunHead(&tablicaHead[najwHead1]);
                printf("Z kolejki [%d] usunieto: ", najwHead2);
                usunHead(&tablicaHead[najwHead2]);

			     break;
			     case 2:
			         for(int i =0;i<4;i++)
                     {
                         printf("Kolejka nr %d\n", i);
                         Show(tablicaHead[i]);
                         printf("----------------------------------------------\n\n");
                     }
                     break;
        }
    }
    return 0;
}
