#include "ada_c.h"
#include <stdio.h>
#include <stdlib.h>

int main(int c, char *arg[] ) {
  void* url = ada_parse("https://www.google.com");
  if(!ada_is_valid(url)) { puts("failure"); return EXIT_FAILURE; }
  puts(ada_get_scheme(url));
  ada_free(url);
  return EXIT_SUCCESS;
}

