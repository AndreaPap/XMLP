/*
*
*	Parser di html che mette a diposizione una funzione di input per generare lo stato dal file xml
*   e diverse funzioni di output
* 	riferimento: https://it.wikipedia.org/wiki/XML
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* StateLoad( char* XMLPathInput );
char* StateKill( char* State );

char* OutputFilter( char* State, char* TagInput );					// funzione che dallo stato e dal tipo di tag cercato trova tutte le proprietà e contenuti

void main();
