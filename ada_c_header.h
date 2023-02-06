#ifndef ADA_C_HEADER_H
#define ADA_C_HEADER_H

#include "ada.h"

extern "C" {
typedef void* ada_url;

ada_url ada_parse(char* string) noexcept;

void ada_free(ada_url result) noexcept;

bool ada_is_valid(ada_url result) noexcept;

const char* ada_get_scheme(ada_url result) noexcept;
}
#endif // ADA_C_HEADER_H