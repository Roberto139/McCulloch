#include <stdio.h>
#include <stdlib.h>
#include  <getopt.h>
#include <string.h>


void entrada de dados(quintupla *Q,const char *entrada)
{
    FILE *pf=fopen(entrada, "r");
    char ch[SBUFF];

    fgets(ch, SBUFF, pf);
    fgets(ch, SBUFF, pf); 
    Q->k= atoi(ch);


    fgets(ch, SBUFF, pf);
    fgets(ch, SBUFF, pf); 
    Q->k= atoi(ch);


    fgets(ch, SBUFF, pf);
    fgets(ch, SBUFF, pf); 
    Q->A= atoi(ch);


    fgets(ch, SBUFF, pf);
    fgets(ch, SBUFF, pf); 
    Q->S= atoi(ch);


    fgets(ch, SBUFF, pf);
    fgets(ch, SBUFF, pf); 
    Q->F= atoi(ch);
    coleta_final(&Q->F,pf);

    fgets(ch, SBUFF, pf);
    fgets(ch, SBUFF, pf); 
    Q->D= atoi(ch);
    coleta_transicao(&Q->D, pf);

    fclose(pf);

    return 
}

void coleta_final(lest_t **list,FILE *stream)
{
    char ch[SBUFF], *sch;

    fgets(ch,SBUFF, stream);

    sch = strok(ch, " " );

    do
    {
        insere_estado(list, atoi(sch));
    }while((sch==strok(NULL, "  "))!=NULL);
}

void coleta_transicao(ltrans_t **list, FILE *stream)

{
    char ch[SBUFF], *sei, *slei, *sef;

    while(fgets(ch, SBUFF, stream)!=NULL)
    {
        sei=strok(ch, " ");
        slei=strok(NULL, " ");
        sef=strok(NULL, " ");
        insere_transicao(list, atoi(sei), slei, atoi(sef);
    }
}

void estados_limites(quintupla_t *Q)

{

    lest_t *pl= Q->F;

    insere_transicao(&Q->D, Q->K, "E", Q->S);



    while

    {   

        insere_transicao(&Q->D, pl->estado, "E", Q->K+1);

        pl= pl->prox;

     }

    return;

    }

int lista_unitaria(ltrans_t *list)
{
    if(!list)
        return 0;
    return list->prox ==NULL ? 1:0;
}


