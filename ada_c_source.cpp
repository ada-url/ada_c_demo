
#include "ada_c_header.h"

#include "ada.cpp"


extern "C" {
typedef void* ada_url;

ada_url ada_parse(char* string) noexcept {
    return new ada::result(ada::parse(string));
}

void ada_free(ada_url result) noexcept {
    ada::result* r = (ada::result*)result;
    delete r;
}

bool ada_is_valid(ada_url result) noexcept {
    ada::result& r = *(ada::result*)result;
    return bool(r);
}

const char* ada_get_scheme(ada_url result) noexcept {
    ada::result& r = *(ada::result*)result;
    if(!r) { return nullptr; }
    return r->get_scheme().data();
}
}