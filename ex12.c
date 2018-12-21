/***************************************************************************
 *   ex12.c                                   Version 20181221.145521      *
 *                                                                         *
 *   Program to convert AFD to ER                                            *
 *   Copyright (C) 2018         by Roberto Arruda Braga                      *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Roberto Arruda Braga                                                  *
 *   Email: rob.arr.bra@gmail.com                                          *
 *   Webpage: http://www.upe.br                                            *
 *   Phone: +55 (81) 97307-3232                                            *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file ex12.c
 * @ingroup GroupUnique
 * @brief Brief description
 * @details This program really do a nice job as a template, and template only!
 * @version 20181221.145521
 * @date 2018-12-21
 * @author Your Name Here <<your@email.here>>
 * @par Webpage
 * <<a href="http://www.upe.br">www.upe.br</a>>
 * @copyright (c) 2018 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc ex12.c -o ex12.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv ex12.c
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */

/* To include assert.h for diagnostics, do it after #define DEBUG bellow */
/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <stdint.h> */ /* Integer types and sizes */
/* #include <inttypes.h> */ /* Macros for integer types */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "ex12.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20181221.145521" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void ex12_init(void); /* global initialization function */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, rab!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./ex12 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.upe.br">www.upe.br</a>>
 * @author Your Name Here
 * @version 20181221.145521
 * @date 2018-12-21
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -V  version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhV")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'V':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    ex12_init(); /* initialization function */

    /* ...and we are done */
    /* Write your code here... */

    return EXIT_SUCCESS;
}

/* Write your functions here... */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Your Name Here
 * @version 20181221.145521
 * @date 2018-12-21
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex12", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "ex12");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Your Name Here", "your@email.here");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Your Name Here
 * @version 20181221.145521
 * @date 2018-12-21
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex12", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2018, "Your Name Here", "your@email.here");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written in
 * multiple lines
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x == funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @return Void
 *
 * @warning Be carefull with blu
 * @todo Need to implement it. Its empty now. This doxygen tags are overwhelming.
 * Mandatory tags are: ingroup, brief, details, param, return, author and date.
 * The others are optional.
 *
 * @deprecated This function will be deactivated in version +11
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @note You can read more about it at <<a href="http://www.upe.br">www.upe.br</a>>
 *
 * @author Your Name Here
 * @version 20181221.145521
 * @date 2018-12-21
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void ex12_init(void)
{
    IFDEBUG("ex12_init()");
    /* initialization */
    return;
}

/* ---------------------------------------------------------------------------- */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160714.153029           */
#include <stdio.h>
#include <stdlib.h>
#include  <getopt.h>
#include <string.h>


int main(int *argv[])
{
    return 0;
}


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
/** 
 *  * @brief coleta o estados finais do arquivo, auxilia a funcao entrada_dados()
 *  * @param [out] list armazena o estados finais
 *  * @param [in] stream referencia do arquivo
 *  * @return
 **/
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




void uniao(ltrans_t **list)
{
    ltrans_t *pl, *pl2, res/* variavel que vai unificar as transicoes semelhantes*/;

    while(busca_semelhantes(*list, &pl, &pl2)) /* procurando por transicoes semelhantes, retorna 0 se nada for encontrado, e 1 se encontrado*/
    {
        res.ei= pl->ei;
        res.ef= pl->ef;
        res.lei= malloc(definir_tamanho(pl->lei, pl2->lei) * sizeof(char)); /* definindo o tamanho da string que vai unir as leis*/

        /* processo de atribuicao da uniao das leis em um string*/
        if(strcmp(pl->lei, "E") != 0)
        {
            strcpy(res.lei, pl->lei);
            if(strcmp(pl2->lei, "E") != 0)
            {
                strcat(res.lei, "|");
                strcat(res.lei, pl2->lei);
            }
        }
        else
        {
            if(strcmp(pl2->lei, "E") != 0)
                strcpy(res.lei, pl2->lei);
            else
                strcpy(res.lei, "E");
        }
        /* ------------- */

        remove_transicao(list, pl);
        remove_transicao(list, pl2);
        insere_transicao(list, res.ei, res.lei, res.ef);
        free(res.lei);
    }
    return;
}

int estado_eliminar(quintupla_t Q)
{
    int vetor[Q.K], i, menor /* indice do vetor com menor valor*/;
    ltrans_t *pl= Q.D;

    for(i=0; i<Q.K; i++) vetor[i]= 0;

    while(pl!= NULL)
    {
        if(pl->ei < Q.K)
            vetor[pl->ei]+= 1;

        if(pl->ef < Q.K)
            vetor[pl->ef]+= 1;

        pl= pl->prox;
    }

    menor= 0; /* indice do vetor inicial*/
    for(i=1; i<Q.K; i++)
    {
        if(vetor[menor] == 0)
            menor = i;
        else if(vetor[menor] > vetor[i] && vetor[i] != 0)
            menor= i;
    }
    return menor;
}

void estados_limite(quintupla_t *Q)
{
    lest_t *pl= Q->F;
    insere_transicao(&Q->D, Q->K, "E", Q->S);

    while(pl!= NULL)
    {
        insere_transicao(&Q->D, pl->estado, "E", Q->K+1);
        pl= pl->prox;
    }
    return;
}


