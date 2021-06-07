#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"
#include "stack.h"

int main(int argc, char **argv) {

  screen s;
  struct matrix * edges;
  struct matrix * polygons;
  struct stack * csystems;
  
  struct matrix *a;
  struct matrix * b;
  //had an issue where copy_matrix did not work
  //a=new_matrix(4,4);
  //b=new_matrix(4,4);
  //ident(a);
  //a->m[1][1]=2;
  //ident(b);
  //printf("a:\n");
  //print_matrix(a);
  //copy_matrix(a,b);
  //printf("b\n");
 // print_matrix(b);
  edges = new_matrix(4, 4);
  polygons = new_matrix(4, 4);
  csystems = new_stack();
  push(csystems);
  //print_matrix(peek(csystems));
  if ( argc == 2 )
    parse_file( argv[1], csystems, edges, polygons, s );
  else
    parse_file( "stdin", csystems, edges, polygons, s );

  free_matrix( edges );
  free_matrix( polygons );
  free_stack(csystems);
}