/*
+--------------------------------------------------------------------------------------+
|Federal University Of Juiz de Fora - UFJF - Minas Gerais - Brazil                     |
|Institute for Exact Sciences - ICE                                                    |
|Computer Science Degree                                                               |
|Project: Qual é o Bicho?                        				                       |
|Professor: Bernardo Martins Rocha                    bernardomartinsrocha@ice.ufjf.br |
|Students......: Douglas Coelho Braga de Oliveira     dcoelhobo@gmail.com              |
|                Igor Freitas Couto                   igor.fcouto@gmail.com            |
|                Mauro Correia Vieira                 mauroccvieira@gmail.com          |
|Created in......:October/25/2012                                                      |
|Objective: this file is the head of the library                                       |
+--------------------------------------------------------------------------------------+
*/

#ifndef BICHO_H_INCLUDED
#define BICHO_H_INCLUDED

#include "Arvore.h"

static int JOGAR; // Variável de controle

void playGame(Arvore* no);
void endGame(Arvore *raiz);

#endif // BICHO_H_INCLUDED
