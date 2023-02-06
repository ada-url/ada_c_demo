#ifndef ADA_C_H
#define ADA_C_H

#include <stdbool.h>
typedef void* ada_url;

ada_url ada_parse(char* string);

void ada_free(ada_url result);

bool ada_is_valid(ada_url result);

const char* ada_get_scheme(ada_url result);

#endif // ADA_C_H