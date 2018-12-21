/***************************************************************************
 *   ex16.c                                   Version 20181221.145940      *
 *                                                                         *
 *   Brief description                                                     *
 *   Copyright (C) 2018         by Your Name Here                          *
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
 *   Your Name Here                                                        *
 *   Email: your@email.here                                                *
 *   Webpage: http://www.upe.br                                            *
 *   Phone: +55 (81) 98765-4321                                            *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file ex16.c
 * @ingroup GroupUnique
 * @brief Brief description
 * @details This program really do a nice job as a template, and template only!
 * @version 20181221.145940
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
 *   $gcc ex16.c -o ex16.x -Wall
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
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv ex16.c
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include "ex16.h" /* library with definitions */

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
/* #include "ex16.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20181221.145940" /**< Version Number (string) */
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
void ex16_init(void); /* global initialization function */

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
 *    $./ex16 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.upe.br">www.upe.br</a>>
 * @author Your Name Here
 * @version 20181221.145940
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

    ex16_init(); /* initialization function */

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
 * @version 20181221.145940
 * @date 2018-12-21
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex16", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "ex16");
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
 * @version 20181221.145940
 * @date 2018-12-21
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex16", VERSION);
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
 * @version 20181221.145940
 * @date 2018-12-21
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void ex16_init(void)
{
    IFDEBUG("ex16_init()");
    /* initialization */
    return;
}

/** 
 * @brief Coleta a Expressao Regular do arquivo
 * @param [out] expReg armazena a expressao regular
 * @param [in] entrada nome do arquivo
 */
void entrada_dados(char *expReg, char *entrada)
{
    FILE *pf= fopen(entrada, "r");

    fgets(expReg, SBUFF, pf);
    return;
}

/**
 * @brief responsavel em quebra a Expressao Regular em expressoes miminas, e armazenando numa arvore binaria
 * @param [in] expReg Expressao Regular
 * @param [out] raiz Arvore Binaria
 */
void quebraExpressao(char *expReg, t_arvore **raiz)
{
    const int nOp= 3; /* numero de operadores*/
    char operadores[3] = {'|', '.', '*'} /* operadores em ordem crescente de prioridade*/,
         *op= malloc(2*sizeof(char)) /*operador*/,
         *partEsq, *partDir; /* Quebra da expressoas partes esqueda e direita*/
    int i, parentese= 0 /* parentese aberto*/;
    size_t j;

    if(!expReg)
        return;

    /* Procurando pelo operador de menor prioridade, sera o ponto de bisseccao do expressao*/
    for(i=0; i<nOp; i++)
    {
        for(j=0; j< strlen(expReg); j++) /* expressao escolhida, de baixa prioridade para a alta*/
        {
            if(expReg[j] == '(') /** para caso enteja entrando no parentese onde torna a expressao prioritaria*/
                parentese++;
            else if(expReg[j] == ')') /* sainda do parentese*/
                parentese--;
            else if(expReg[j] == operadores[i] && parentese == 0) /* verificando se entrou operador caso nao esteja dentro de um parentese*/ 
            {
                separador(expReg, &partEsq, &partDir, op, j);

                insere_arvore(raiz, *raiz, op);

                /* caso foi alcansado uma expressao minima*/
                if(strlen(partEsq) == 1)
                    insere_arvore(raiz, *raiz, partEsq);
                else
                    quebraExpressao(partEsq, raiz);

                /* caso foi alcansado uma expressao minima*/
                if(strlen(partDir) == 1)
                    insere_arvore(raiz, *raiz, partDir);
                else
                    quebraExpressao(partDir, raiz);

                return;
            }
        }
    }
    return;
}

/**
 * @brief separa a expressao regular no ponto pre determinado
 * @param [in] expReg expressao regular
 * @param [out] partEsc a parte esquerda da expressao regular
 * @param [out] partDir a parte direita da expressao regular
 * @param [in] size ponto de bisseccao
 */
void separador(char *expReg, char **partEsq, char **partDir, char *op, int size)
{
    char *esq, *dir;

    esq= malloc((size + 1) * sizeof(char));
    dir= malloc((strlen(expReg) - size) * sizeof(char));

    strncpy(esq, expReg, size);
    esq[size]= '\0';
    strcpy(dir, expReg+size+1);

    /* retira os parenteses caso toda a expressao esteja contida nas mesmas*/
    if(*esq == '(' && *(esq+strlen(esq)-1) == ')')
    {
        esq= esq+1;
        esq[strlen(esq)-1]= '\0';
    }
    /* retira os parenteses caso toda a expressao esteja contida nas mesmas*/
    if(*dir == '(' && dir[strlen(dir)-1] == ')')
    {
        dir= dir+1;
        dir[strlen(dir)-1]= '\0';
    }

    *partEsq= esq;
    *partDir= dir;

    op[0]= expReg[size];
    op[1]= '\0';

    return;
}

/**
 * @brief salva e organiza informacoes no formato de arvore binaria, insere em preordem 
 * @param [out] raiz objeto arvore
 * @param ant auxiliar, serve como orientador, registra a ultima posicao percorrida na arvore, uso interno exclusivo
 * inicie com o objeto da arvore
 */
void insere_arvore(t_arvore **raiz, t_arvore *ant, char *info)
{
    t_arvore *pl= *raiz;

    if(!pl)
    {
        pl= malloc(sizeof(t_arvore));
        pl->expReg= malloc(strlen(info) * sizeof(char));
        strcpy(pl->expReg, info);
        pl->tipo_op= tipo_operador(pl->expReg[0]);
        pl->esq= NULL;
        pl->dir= NULL;
        pl->pai= ant;
        *raiz= pl;
        return;
    }

    if(pl->tipo_op == 0 || pl->dir == ant || (pl->tipo_op == 1 && pl->esq == ant))
        insere_arvore(&pl->pai, pl, info);
    else if (pl->esq == ant)
        insere_arvore(&pl->dir, pl, info);
    else
        insere_arvore(&pl->esq, pl, info);
    return;
}

/**
 * @brief identifica o tipo da informacao: nao operador, operador unario ou operador binario
 * @param [in] info informacao
 * @return 0 p/ nao operador, 1 p/ operador unario, 2 p/ operador binario
 */
int tipo_operador(char info)
{
    if(info == '.' || info == '|')
        return 2;
    if(info == '*')
        return 1;
    return 0;
}

/* ---------------------------------------------------------------------------- */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160714.153029           */

