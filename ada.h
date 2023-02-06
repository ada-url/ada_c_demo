/* auto-generated on 2023-02-05 22:29:21 -0500. Do not edit! */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada.h
/* begin file include/ada.h */
/**
 * @file ada.h
 * @brief Includes all definitions for Ada.
 */
#ifndef ADA_H
#define ADA_H

// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/character_sets-inl.h
/* begin file include/ada/character_sets-inl.h */
/**
 * @file character_sets-inl.h
 * @brief Definitions of the character sets used by unicode functions.
 * @author Node.js
 * @see https://github.com/nodejs/node/blob/main/src/node_url_tables.cc
 */
#ifndef ADA_CHARACTER_SETS_INL_H
#define ADA_CHARACTER_SETS_INL_H

// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/character_sets.h
/* begin file include/ada/character_sets.h */
/**
 * @file character_sets.h
 * @brief Declaration of the character sets used by unicode functions.
 * @author Node.js
 * @see https://github.com/nodejs/node/blob/main/src/node_url_tables.cc
 */
#ifndef ADA_CHARACTER_SETS_H
#define ADA_CHARACTER_SETS_H

// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/common_defs.h
/* begin file include/ada/common_defs.h */
/**
 * @file common_defs.h
 * @brief Common definitions for cross-platform compiler support.
 */
#ifndef ADA_COMMON_DEFS_H
#define ADA_COMMON_DEFS_H

#ifdef _MSC_VER
#define ADA_VISUAL_STUDIO 1
/**
 * We want to differentiate carefully between
 * clang under visual studio and regular visual
 * studio.
 */
#ifdef __clang__
// clang under visual studio
#define ADA_CLANG_VISUAL_STUDIO 1
#else
// just regular visual studio (best guess)
#define ADA_REGULAR_VISUAL_STUDIO 1
#endif // __clang__
#endif // _MSC_VER


#if defined(__GNUC__)
  // Marks a block with a name so that MCA analysis can see it.
  #define ADA_BEGIN_DEBUG_BLOCK(name) __asm volatile("# LLVM-MCA-BEGIN " #name);
  #define ADA_END_DEBUG_BLOCK(name) __asm volatile("# LLVM-MCA-END " #name);
  #define ADA_DEBUG_BLOCK(name, block) BEGIN_DEBUG_BLOCK(name); block; END_DEBUG_BLOCK(name);
#else
  #define ADA_BEGIN_DEBUG_BLOCK(name)
  #define ADA_END_DEBUG_BLOCK(name)
  #define ADA_DEBUG_BLOCK(name, block)
#endif

// Align to N-byte boundary
#define ADA_ROUNDUP_N(a, n) (((a) + ((n)-1)) & ~((n)-1))
#define ADA_ROUNDDOWN_N(a, n) ((a) & ~((n)-1))

#define ADA_ISALIGNED_N(ptr, n) (((uintptr_t)(ptr) & ((n)-1)) == 0)

#if defined(ADA_REGULAR_VISUAL_STUDIO)

  #define ada_really_inline __forceinline
  #define ada_never_inline __declspec(noinline)

  #define ada_unused
  #define ada_warn_unused

  #ifndef ada_likely
  #define ada_likely(x) x
  #endif
  #ifndef ada_unlikely
  #define ada_unlikely(x) x
  #endif

  #define ADA_PUSH_DISABLE_WARNINGS __pragma(warning( push ))
  #define ADA_PUSH_DISABLE_ALL_WARNINGS __pragma(warning( push, 0 ))
  #define ADA_DISABLE_VS_WARNING(WARNING_NUMBER) __pragma(warning( disable : WARNING_NUMBER ))
  // Get rid of Intellisense-only warnings (Code Analysis)
  // Though __has_include is C++17, it is supported in Visual Studio 2017 or better (_MSC_VER>=1910).
  #ifdef __has_include
  #if __has_include(<CppCoreCheck\Warnings.h>)
  #include <CppCoreCheck\Warnings.h>
  #define ADA_DISABLE_UNDESIRED_WARNINGS ADA_DISABLE_VS_WARNING(ALL_CPPCORECHECK_WARNINGS)
  #endif
  #endif

  #ifndef ADA_DISABLE_UNDESIRED_WARNINGS
  #define ADA_DISABLE_UNDESIRED_WARNINGS
  #endif

  #define ADA_DISABLE_DEPRECATED_WARNING ADA_DISABLE_VS_WARNING(4996)
  #define ADA_DISABLE_STRICT_OVERFLOW_WARNING
  #define ADA_POP_DISABLE_WARNINGS __pragma(warning( pop ))

#else // ADA_REGULAR_VISUAL_STUDIO

  #define ada_really_inline inline __attribute__((always_inline))
  #define ada_never_inline inline __attribute__((noinline))

  #define ada_unused __attribute__((unused))
  #define ada_warn_unused __attribute__((warn_unused_result))

  #ifndef ada_likely
  #define ada_likely(x) __builtin_expect(!!(x), 1)
  #endif
  #ifndef ada_unlikely
  #define ada_unlikely(x) __builtin_expect(!!(x), 0)
  #endif

  #define ADA_PUSH_DISABLE_WARNINGS _Pragma("GCC diagnostic push")
  // gcc doesn't seem to disable all warnings with all and extra, add warnings here as necessary
  #define ADA_PUSH_DISABLE_ALL_WARNINGS ADA_PUSH_DISABLE_WARNINGS \
    ADA_DISABLE_GCC_WARNING(-Weffc++) \
    ADA_DISABLE_GCC_WARNING(-Wall) \
    ADA_DISABLE_GCC_WARNING(-Wconversion) \
    ADA_DISABLE_GCC_WARNING(-Wextra) \
    ADA_DISABLE_GCC_WARNING(-Wattributes) \
    ADA_DISABLE_GCC_WARNING(-Wimplicit-fallthrough) \
    ADA_DISABLE_GCC_WARNING(-Wnon-virtual-dtor) \
    ADA_DISABLE_GCC_WARNING(-Wreturn-type) \
    ADA_DISABLE_GCC_WARNING(-Wshadow) \
    ADA_DISABLE_GCC_WARNING(-Wunused-parameter) \
    ADA_DISABLE_GCC_WARNING(-Wunused-variable)
  #define ADA_PRAGMA(P) _Pragma(#P)
  #define ADA_DISABLE_GCC_WARNING(WARNING) ADA_PRAGMA(GCC diagnostic ignored #WARNING)
  #if defined(ADA_CLANG_VISUAL_STUDIO)
  #define ADA_DISABLE_UNDESIRED_WARNINGS ADA_DISABLE_GCC_WARNING(-Wmicrosoft-include)
  #else
  #define ADA_DISABLE_UNDESIRED_WARNINGS
  #endif
  #define ADA_DISABLE_DEPRECATED_WARNING ADA_DISABLE_GCC_WARNING(-Wdeprecated-declarations)
  #define ADA_DISABLE_STRICT_OVERFLOW_WARNING ADA_DISABLE_GCC_WARNING(-Wstrict-overflow)
  #define ADA_POP_DISABLE_WARNINGS _Pragma("GCC diagnostic pop")

#endif // MSC_VER

#if defined(ADA_VISUAL_STUDIO)
    /**
     * It does not matter here whether you are using
     * the regular visual studio or clang under visual
     * studio.
     */
    #if ADA_USING_LIBRARY
    #define ADA_DLLIMPORTEXPORT __declspec(dllimport)
    #else
    #define ADA_DLLIMPORTEXPORT __declspec(dllexport)
    #endif
#else
    #define ADA_DLLIMPORTEXPORT
#endif

/// If EXPR is an error, returns it.
#define ADA_TRY(EXPR) { auto _err = (EXPR); if (_err) { return _err; } }

// __has_cpp_attribute is part of C++20
#if !defined(__has_cpp_attribute)
#define __has_cpp_attribute(x) 0
#endif


#if __has_cpp_attribute(gnu::noinline)
#define ADA_ATTRIBUTE_NOINLINE [[gnu::noinline]]
#else
#define ADA_ATTRIBUTE_NOINLINE
#endif

namespace ada {
  [[noreturn]] inline void unreachable() {
#ifdef __GNUC__
    __builtin_unreachable();
#elif defined(_MSC_VER)
    __assume(false);
#else
#endif
  }
}



#if defined(__GNUC__) && !defined(__clang__)
#if __GNUC__ <= 8
#define ADA_OLD_GCC 1
#endif //  __GNUC__ <= 8
#endif // defined(__GNUC__) && !defined(__clang__)

#if ADA_OLD_GCC
#define ada_constexpr
#else
#define ada_constexpr constexpr
#endif

 #if defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__)
 #define ADA_IS_BIG_ENDIAN (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
 #elif defined(_WIN32)
 #define ADA_IS_BIG_ENDIAN 0
 #else
 #if defined(__APPLE__) || defined(__FreeBSD__) // defined __BYTE_ORDER__ && defined __ORDER_BIG_ENDIAN__
 #include <machine/endian.h>
 #elif defined(sun) || defined(__sun) // defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/byteorder.h>
 #else  // defined(__APPLE__) || defined(__FreeBSD__)

 #ifdef __has_include
 #if __has_include(<endian.h>)
 #include <endian.h>
 #endif //__has_include(<endian.h>)
 #endif //__has_include

 #endif // defined(__APPLE__) || defined(__FreeBSD__)


 #ifndef !defined(__BYTE_ORDER__) || !defined(__ORDER_LITTLE_ENDIAN__)
 #define ADA_IS_BIG_ENDIAN 0
 #endif

 #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
 #define ADA_IS_BIG_ENDIAN 0
 #else // __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
 #define ADA_IS_BIG_ENDIAN 1
 #endif // __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

 #endif // defined __BYTE_ORDER__ && defined __ORDER_BIG_ENDIAN__


#ifndef ADA_HAS_ICU
#if __has_include(<unicode/uidna.h>)
#define ADA_HAS_ICU 1
#else
#define ADA_HAS_ICU 0
#endif // __has_include(<unicode/uidna.h>)
#endif // ADA_HAS_ICU

#if ADA_HAS_ICU
#include <unicode/utypes.h>
#include <unicode/uidna.h>
#include <unicode/utf8.h>
#endif // ADA_HAS_ICU

#define ADA_WINDOWS_TO_ASCII_FALLBACK 0 // we never use anything but ICU. No fallback.

#endif // ADA_COMMON_DEFS_H
/* end file include/ada/common_defs.h */
#include <stdint.h>

/**
 * @namespace ada::character_sets
 * @brief Includes the definitions for unicode character sets.
 */
namespace ada::character_sets {
  ada_really_inline bool bit_at(const uint8_t a[], const uint8_t i);
} // namespace ada::character_sets

#endif // ADA_CHARACTER_SETS_H
/* end file include/ada/character_sets.h */

namespace ada::character_sets {

  constexpr char hex[1024] =
      "%00\0%01\0%02\0%03\0%04\0%05\0%06\0%07\0"
      "%08\0%09\0%0A\0%0B\0%0C\0%0D\0%0E\0%0F\0"
      "%10\0%11\0%12\0%13\0%14\0%15\0%16\0%17\0"
      "%18\0%19\0%1A\0%1B\0%1C\0%1D\0%1E\0%1F\0"
      "%20\0%21\0%22\0%23\0%24\0%25\0%26\0%27\0"
      "%28\0%29\0%2A\0%2B\0%2C\0%2D\0%2E\0%2F\0"
      "%30\0%31\0%32\0%33\0%34\0%35\0%36\0%37\0"
      "%38\0%39\0%3A\0%3B\0%3C\0%3D\0%3E\0%3F\0"
      "%40\0%41\0%42\0%43\0%44\0%45\0%46\0%47\0"
      "%48\0%49\0%4A\0%4B\0%4C\0%4D\0%4E\0%4F\0"
      "%50\0%51\0%52\0%53\0%54\0%55\0%56\0%57\0"
      "%58\0%59\0%5A\0%5B\0%5C\0%5D\0%5E\0%5F\0"
      "%60\0%61\0%62\0%63\0%64\0%65\0%66\0%67\0"
      "%68\0%69\0%6A\0%6B\0%6C\0%6D\0%6E\0%6F\0"
      "%70\0%71\0%72\0%73\0%74\0%75\0%76\0%77\0"
      "%78\0%79\0%7A\0%7B\0%7C\0%7D\0%7E\0%7F\0"
      "%80\0%81\0%82\0%83\0%84\0%85\0%86\0%87\0"
      "%88\0%89\0%8A\0%8B\0%8C\0%8D\0%8E\0%8F\0"
      "%90\0%91\0%92\0%93\0%94\0%95\0%96\0%97\0"
      "%98\0%99\0%9A\0%9B\0%9C\0%9D\0%9E\0%9F\0"
      "%A0\0%A1\0%A2\0%A3\0%A4\0%A5\0%A6\0%A7\0"
      "%A8\0%A9\0%AA\0%AB\0%AC\0%AD\0%AE\0%AF\0"
      "%B0\0%B1\0%B2\0%B3\0%B4\0%B5\0%B6\0%B7\0"
      "%B8\0%B9\0%BA\0%BB\0%BC\0%BD\0%BE\0%BF\0"
      "%C0\0%C1\0%C2\0%C3\0%C4\0%C5\0%C6\0%C7\0"
      "%C8\0%C9\0%CA\0%CB\0%CC\0%CD\0%CE\0%CF\0"
      "%D0\0%D1\0%D2\0%D3\0%D4\0%D5\0%D6\0%D7\0"
      "%D8\0%D9\0%DA\0%DB\0%DC\0%DD\0%DE\0%DF\0"
      "%E0\0%E1\0%E2\0%E3\0%E4\0%E5\0%E6\0%E7\0"
      "%E8\0%E9\0%EA\0%EB\0%EC\0%ED\0%EE\0%EF\0"
      "%F0\0%F1\0%F2\0%F3\0%F4\0%F5\0%F6\0%F7\0"
      "%F8\0%F9\0%FA\0%FB\0%FC\0%FD\0%FE\0%FF";

  constexpr uint8_t C0_CONTROL_PERCENT_ENCODE[32] = {
      // 00     01     02     03     04     05     06     07
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 08     09     0A     0B     0C     0D     0E     0F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 10     11     12     13     14     15     16     17
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 18     19     1A     1B     1C     1D     1E     1F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 20     21     22     23     24     25     26     27
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 28     29     2A     2B     2C     2D     2E     2F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 30     31     32     33     34     35     36     37
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 38     39     3A     3B     3C     3D     3E     3F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 40     41     42     43     44     45     46     47
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 48     49     4A     4B     4C     4D     4E     4F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 50     51     52     53     54     55     56     57
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 58     59     5A     5B     5C     5D     5E     5F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 60     61     62     63     64     65     66     67
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 68     69     6A     6B     6C     6D     6E     6F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 70     71     72     73     74     75     76     77
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 78     79     7A     7B     7C     7D     7E     7F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x80,
      // 80     81     82     83     84     85     86     87
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 88     89     8A     8B     8C     8D     8E     8F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 90     91     92     93     94     95     96     97
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 98     99     9A     9B     9C     9D     9E     9F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // A0     A1     A2     A3     A4     A5     A6     A7
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // A8     A9     AA     AB     AC     AD     AE     AF
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // B0     B1     B2     B3     B4     B5     B6     B7
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // B8     B9     BA     BB     BC     BD     BE     BF
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // C0     C1     C2     C3     C4     C5     C6     C7
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // C8     C9     CA     CB     CC     CD     CE     CF
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // D0     D1     D2     D3     D4     D5     D6     D7
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // D8     D9     DA     DB     DC     DD     DE     DF
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // E0     E1     E2     E3     E4     E5     E6     E7
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // E8     E9     EA     EB     EC     ED     EE     EF
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // F0     F1     F2     F3     F4     F5     F6     F7
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // F8     F9     FA     FB     FC     FD     FE     FF
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
    };

  constexpr uint8_t SPECIAL_QUERY_PERCENT_ENCODE[32] = {
      // 00     01     02     03     04     05     06     07
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 08     09     0A     0B     0C     0D     0E     0F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 10     11     12     13     14     15     16     17
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 18     19     1A     1B     1C     1D     1E     1F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 20     21     22     23     24     25     26     27
      0x01 | 0x00 | 0x04 | 0x08 | 0x00 | 0x00 | 0x00 | 0x80,
      // 28     29     2A     2B     2C     2D     2E     2F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 30     31     32     33     34     35     36     37
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 38     39     3A     3B     3C     3D     3E     3F
      0x00 | 0x00 | 0x00 | 0x00 | 0x10 | 0x00 | 0x40 | 0x00,
      // 40     41     42     43     44     45     46     47
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 48     49     4A     4B     4C     4D     4E     4F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 50     51     52     53     54     55     56     57
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 58     59     5A     5B     5C     5D     5E     5F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 60     61     62     63     64     65     66     67
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 68     69     6A     6B     6C     6D     6E     6F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 70     71     72     73     74     75     76     77
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 78     79     7A     7B     7C     7D     7E     7F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x80,
    // 80     81     82     83     84     85     86     87
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 88     89     8A     8B     8C     8D     8E     8F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 90     91     92     93     94     95     96     97
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 98     99     9A     9B     9C     9D     9E     9F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A0     A1     A2     A3     A4     A5     A6     A7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A8     A9     AA     AB     AC     AD     AE     AF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B0     B1     B2     B3     B4     B5     B6     B7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B8     B9     BA     BB     BC     BD     BE     BF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C0     C1     C2     C3     C4     C5     C6     C7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C8     C9     CA     CB     CC     CD     CE     CF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D0     D1     D2     D3     D4     D5     D6     D7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D8     D9     DA     DB     DC     DD     DE     DF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E0     E1     E2     E3     E4     E5     E6     E7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E8     E9     EA     EB     EC     ED     EE     EF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F0     F1     F2     F3     F4     F5     F6     F7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F8     F9     FA     FB     FC     FD     FE     FF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
    };

  constexpr uint8_t QUERY_PERCENT_ENCODE[32] = {
      // 00     01     02     03     04     05     06     07
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 08     09     0A     0B     0C     0D     0E     0F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 10     11     12     13     14     15     16     17
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 18     19     1A     1B     1C     1D     1E     1F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 20     21     22     23     24     25     26     27
      0x01 | 0x00 | 0x04 | 0x08 | 0x00 | 0x00 | 0x00 | 0x00,
      // 28     29     2A     2B     2C     2D     2E     2F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 30     31     32     33     34     35     36     37
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 38     39     3A     3B     3C     3D     3E     3F
      0x00 | 0x00 | 0x00 | 0x00 | 0x10 | 0x00 | 0x40 | 0x00,
      // 40     41     42     43     44     45     46     47
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 48     49     4A     4B     4C     4D     4E     4F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 50     51     52     53     54     55     56     57
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 58     59     5A     5B     5C     5D     5E     5F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 60     61     62     63     64     65     66     67
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 68     69     6A     6B     6C     6D     6E     6F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 70     71     72     73     74     75     76     77
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 78     79     7A     7B     7C     7D     7E     7F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x80,
    // 80     81     82     83     84     85     86     87
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 88     89     8A     8B     8C     8D     8E     8F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 90     91     92     93     94     95     96     97
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 98     99     9A     9B     9C     9D     9E     9F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A0     A1     A2     A3     A4     A5     A6     A7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A8     A9     AA     AB     AC     AD     AE     AF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B0     B1     B2     B3     B4     B5     B6     B7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B8     B9     BA     BB     BC     BD     BE     BF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C0     C1     C2     C3     C4     C5     C6     C7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C8     C9     CA     CB     CC     CD     CE     CF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D0     D1     D2     D3     D4     D5     D6     D7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D8     D9     DA     DB     DC     DD     DE     DF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E0     E1     E2     E3     E4     E5     E6     E7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E8     E9     EA     EB     EC     ED     EE     EF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F0     F1     F2     F3     F4     F5     F6     F7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F8     F9     FA     FB     FC     FD     FE     FF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
    };

  constexpr uint8_t FRAGMENT_PERCENT_ENCODE[32] = {
      // 00     01     02     03     04     05     06     07
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 08     09     0A     0B     0C     0D     0E     0F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 10     11     12     13     14     15     16     17
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 18     19     1A     1B     1C     1D     1E     1F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 20     21     22     23     24     25     26     27
      0x01 | 0x00 | 0x04 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 28     29     2A     2B     2C     2D     2E     2F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 30     31     32     33     34     35     36     37
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 38     39     3A     3B     3C     3D     3E     3F
      0x00 | 0x00 | 0x00 | 0x00 | 0x10 | 0x00 | 0x40 | 0x00,
      // 40     41     42     43     44     45     46     47
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 48     49     4A     4B     4C     4D     4E     4F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 50     51     52     53     54     55     56     57
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 58     59     5A     5B     5C     5D     5E     5F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 60     61     62     63     64     65     66     67
      0x01 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 68     69     6A     6B     6C     6D     6E     6F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 70     71     72     73     74     75     76     77
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 78     79     7A     7B     7C     7D     7E     7F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x80,
    // 80     81     82     83     84     85     86     87
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 88     89     8A     8B     8C     8D     8E     8F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 90     91     92     93     94     95     96     97
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 98     99     9A     9B     9C     9D     9E     9F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A0     A1     A2     A3     A4     A5     A6     A7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A8     A9     AA     AB     AC     AD     AE     AF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B0     B1     B2     B3     B4     B5     B6     B7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B8     B9     BA     BB     BC     BD     BE     BF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C0     C1     C2     C3     C4     C5     C6     C7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C8     C9     CA     CB     CC     CD     CE     CF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D0     D1     D2     D3     D4     D5     D6     D7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D8     D9     DA     DB     DC     DD     DE     DF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E0     E1     E2     E3     E4     E5     E6     E7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E8     E9     EA     EB     EC     ED     EE     EF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F0     F1     F2     F3     F4     F5     F6     F7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F8     F9     FA     FB     FC     FD     FE     FF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
    };

  constexpr uint8_t USERINFO_PERCENT_ENCODE[32] = {
      // 00     01     02     03     04     05     06     07
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 08     09     0A     0B     0C     0D     0E     0F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 10     11     12     13     14     15     16     17
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 18     19     1A     1B     1C     1D     1E     1F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 20     21     22     23     24     25     26     27
      0x01 | 0x00 | 0x04 | 0x08 | 0x00 | 0x00 | 0x00 | 0x00,
      // 28     29     2A     2B     2C     2D     2E     2F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x80,
      // 30     31     32     33     34     35     36     37
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 38     39     3A     3B     3C     3D     3E     3F
      0x00 | 0x00 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 40     41     42     43     44     45     46     47
      0x01 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 48     49     4A     4B     4C     4D     4E     4F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 50     51     52     53     54     55     56     57
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 58     59     5A     5B     5C     5D     5E     5F
      0x00 | 0x00 | 0x00 | 0x08 | 0x10 | 0x20 | 0x40 | 0x00,
      // 60     61     62     63     64     65     66     67
      0x01 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 68     69     6A     6B     6C     6D     6E     6F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 70     71     72     73     74     75     76     77
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 78     79     7A     7B     7C     7D     7E     7F
      0x00 | 0x00 | 0x00 | 0x08 | 0x10 | 0x20 | 0x00 | 0x80,
    // 80     81     82     83     84     85     86     87
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 88     89     8A     8B     8C     8D     8E     8F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 90     91     92     93     94     95     96     97
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 98     99     9A     9B     9C     9D     9E     9F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A0     A1     A2     A3     A4     A5     A6     A7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A8     A9     AA     AB     AC     AD     AE     AF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B0     B1     B2     B3     B4     B5     B6     B7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B8     B9     BA     BB     BC     BD     BE     BF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C0     C1     C2     C3     C4     C5     C6     C7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C8     C9     CA     CB     CC     CD     CE     CF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D0     D1     D2     D3     D4     D5     D6     D7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D8     D9     DA     DB     DC     DD     DE     DF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E0     E1     E2     E3     E4     E5     E6     E7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E8     E9     EA     EB     EC     ED     EE     EF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F0     F1     F2     F3     F4     F5     F6     F7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F8     F9     FA     FB     FC     FD     FE     FF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
    };

  constexpr uint8_t PATH_PERCENT_ENCODE[32] = {
      // 00     01     02     03     04     05     06     07
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 08     09     0A     0B     0C     0D     0E     0F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 10     11     12     13     14     15     16     17
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 18     19     1A     1B     1C     1D     1E     1F
      0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
      // 20     21     22     23     24     25     26     27
      0x01 | 0x00 | 0x04 | 0x08 | 0x00 | 0x00 | 0x00 | 0x00,
      // 28     29     2A     2B     2C     2D     2E     2F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 30     31     32     33     34     35     36     37
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 38     39     3A     3B     3C     3D     3E     3F
      0x00 | 0x00 | 0x00 | 0x00 | 0x10 | 0x00 | 0x40 | 0x80,
      // 40     41     42     43     44     45     46     47
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 48     49     4A     4B     4C     4D     4E     4F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 50     51     52     53     54     55     56     57
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 58     59     5A     5B     5C     5D     5E     5F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 60     61     62     63     64     65     66     67
      0x01 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 68     69     6A     6B     6C     6D     6E     6F
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 70     71     72     73     74     75     76     77
      0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00,
      // 78     79     7A     7B     7C     7D     7E     7F
      0x00 | 0x00 | 0x00 | 0x08 | 0x00 | 0x20 | 0x00 | 0x80,
    // 80     81     82     83     84     85     86     87
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 88     89     8A     8B     8C     8D     8E     8F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 90     91     92     93     94     95     96     97
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // 98     99     9A     9B     9C     9D     9E     9F
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A0     A1     A2     A3     A4     A5     A6     A7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // A8     A9     AA     AB     AC     AD     AE     AF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B0     B1     B2     B3     B4     B5     B6     B7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // B8     B9     BA     BB     BC     BD     BE     BF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C0     C1     C2     C3     C4     C5     C6     C7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // C8     C9     CA     CB     CC     CD     CE     CF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D0     D1     D2     D3     D4     D5     D6     D7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // D8     D9     DA     DB     DC     DD     DE     DF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E0     E1     E2     E3     E4     E5     E6     E7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // E8     E9     EA     EB     EC     ED     EE     EF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F0     F1     F2     F3     F4     F5     F6     F7
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80,
    // F8     F9     FA     FB     FC     FD     FE     FF
    0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20 | 0x40 | 0x80
    };

  ada_really_inline bool bit_at(const uint8_t a[], const uint8_t i) {
    return !!(a[i >> 3] & (1 << (i & 7)));
  }

} // namespace ada::character_sets

#endif // ADA_CHARACTER_SETS_H
/* end file include/ada/character_sets-inl.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/checkers-inl.h
/* begin file include/ada/checkers-inl.h */
/**
 * @file checkers-inl.h
 * @brief Definitions for URL specific checkers used within Ada.
 */
#ifndef ADA_CHECKERS_INL_H
#define ADA_CHECKERS_INL_H


#include <string_view>
#include <cstring>

namespace ada::checkers {

  inline bool has_hex_prefix_unsafe(std::string_view input) {
    // This is actualy efficient code, see has_hex_prefix for the assembly.
    uint32_t value_one = 1;
    bool is_little_endian = (reinterpret_cast<char*>(&value_one)[0] == 1);
    uint16_t word0x{};
    std::memcpy(&word0x, "0x", 2); // we would use bit_cast in C++20 and the function could be constexpr.
    uint16_t two_first_bytes{};
    std::memcpy(&two_first_bytes, input.data(),2);
    if(is_little_endian) { two_first_bytes |= 0x2000; } else { two_first_bytes |= 0x020; }
    return two_first_bytes == word0x;
  }

  inline bool has_hex_prefix(std::string_view input) {
    return input.size() >=2 && has_hex_prefix_unsafe(input);
  }

  constexpr bool is_digit(char x) noexcept { return (x >= '0') & (x <= '9'); }

  constexpr char to_lower(char x) noexcept { return (x | 0x20); }

  constexpr bool is_alpha(char x) noexcept { return (to_lower(x) >= 'a') && (to_lower(x) <= 'z'); }

  inline constexpr bool is_windows_drive_letter(std::string_view input) noexcept {
    return input.size() >= 2 && (is_alpha(input[0]) && ((input[1] == ':') || (input[1] == '|')))
      && ((input.size() == 2) || (input[2] == '/' || input[2] == '\\' || input[2] == '?' || input[2] == '#'));
  }

  inline constexpr bool is_normalized_windows_drive_letter(std::string_view input) noexcept {
    return input.size() >= 2 && (is_alpha(input[0]) && (input[1] == ':'));
  }

  ada_really_inline constexpr bool begins_with(std::string_view view, std::string_view prefix) {
    // in C++20, you have view.begins_with(prefix)
    return view.size() >= prefix.size() && (view.substr(0, prefix.size()) == prefix);
  }

} // namespace ada::checkers

#endif //ADA_CHECKERS_H
/* end file include/ada/checkers-inl.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/log.h
/* begin file include/ada/log.h */
/**
 * @file log.h
 * @brief Includes the definitions for logging.
 * @private Excluded from docs through the doxygen file.
 */
#ifndef ADA_LOG_H
#define ADA_LOG_H

#include <iostream>
// To enable logging, set ADA_LOGGING to 1:
#ifndef ADA_LOGGING
#define ADA_LOGGING 0
#endif

namespace ada {

/**
 * Private function used for logging messages.
 * @private
 */
template <typename T>
ada_really_inline void inner_log([[maybe_unused]] T t) {
#if ADA_LOGGING
    std::cout << t << std::endl;
#endif
}


/**
 * Private function used for logging messages.
 * @private
 */
template<typename T, typename... Args>
ada_really_inline void inner_log([[maybe_unused]] T t, [[maybe_unused]] Args... args) {
#if ADA_LOGGING
    std::cout << t;
    inner_log(args...) ;
#endif
}


/**
 * Log a message.
 * @private
 */
template<typename T, typename... Args>
ada_really_inline void log([[maybe_unused]] T t, [[maybe_unused]] Args... args) {
#if ADA_LOGGING
    std::cout << "ADA_LOG: " << t;
    inner_log(args...) ;
#endif
}

/**
 * Log a message.
 * @private
 */
template<typename T>
ada_really_inline void log([[maybe_unused]] T t) {
#if ADA_LOGGING
    std::cout << "ADA_LOG: " <<  t << std::endl;
#endif

}
}

#if ADA_LOGGING

#ifndef ada_log
#define ada_log(...) do { \
    ada::log(__VA_ARGS__); \
} while(0)
#endif // ada_log
#else
#define ada_log(...)
#endif // ADA_LOGGING

#endif // ADA_LOG_H
/* end file include/ada/log.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/encoding_type.h
/* begin file include/ada/encoding_type.h */
/**
 * @file encoding_type.h
 * @brief Definition for supported encoding types.
 */
#ifndef ADA_ENCODING_TYPE_H
#define ADA_ENCODING_TYPE_H

#include <string>

namespace ada {

  /**
   * This specification defines three encodings with the same names as encoding schemes defined
   * in the Unicode standard: UTF-8, UTF-16LE, and UTF-16BE.
   *
   * @see https://encoding.spec.whatwg.org/#encodings
   */
  enum class encoding_type {
    UTF8,
    UTF_16LE,
    UTF_16BE,
  };

  /**
   * Convert a encoding_type to string.
   */
  ada_warn_unused std::string to_string(encoding_type type);

} // ada namespace

#endif // ADA_ENCODING_TYPE_H
/* end file include/ada/encoding_type.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/helpers.h
/* begin file include/ada/helpers.h */
/**
 * @file helpers.h
 * @brief Definitions for helper functions used within Ada.
 */
#ifndef ADA_HELPERS_H
#define ADA_HELPERS_H

// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/url.h
/* begin file include/ada/url.h */
/**
 * @file url.h
 * @brief Declaration for the URL
 */
#ifndef ADA_URL_H
#define ADA_URL_H

// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/checkers.h
/* begin file include/ada/checkers.h */
/**
 * @file checkers.h
 * @brief Declarations for URL specific checkers used within Ada.
 */
#ifndef ADA_CHECKERS_H
#define ADA_CHECKERS_H


#include <string_view>
#include <cstring>

/**
 * @namespace ada::checkers
 * @brief Includes the definitions for validation functions
 */
namespace ada::checkers {

  /**
   * Assuming that x is an ASCII letter, this function returns the lower case equivalent.
   * @details More likely to be inlined by the compiler and constexpr.
   */
  constexpr char to_lower(char x) noexcept;

  /**
   * Returns true if the character is an ASCII letter. Equivalent to std::isalpha but
   * more likely to be inlined by the compiler.
   *
   * @attention std::isalpha is not constexpr generally.
   */
  constexpr bool is_alpha(char x) noexcept;

  /**
   * Check whether a string starts with 0x or 0X. The function is only
   * safe if input.size() >=2.
   *
   * @see has_hex_prefix
   */
  inline bool has_hex_prefix_unsafe(std::string_view input);
  /**
   * Check whether a string starts with 0x or 0X.
   */
  inline bool has_hex_prefix(std::string_view input);

  /**
   * Check whether x is an ASCII digit. More likely to be inlined than std::isdigit.
   */
  constexpr bool is_digit(char x) noexcept;

  /**
   * @details A string starts with a Windows drive letter if all of the following are true:
   *
   *   - its length is greater than or equal to 2
   *   - its first two code points are a Windows drive letter
   *   - its length is 2 or its third code point is U+002F (/), U+005C (\), U+003F (?), or U+0023 (#).
   *
   * https://url.spec.whatwg.org/#start-with-a-windows-drive-letter
   */
  inline constexpr bool is_windows_drive_letter(std::string_view input) noexcept;

  /**
   * @details A normalized Windows drive letter is a Windows drive letter of which the second code point is U+003A (:).
   */
  inline constexpr bool is_normalized_windows_drive_letter(std::string_view input) noexcept;

  /**
   * @warning Will be removed when Ada supports C++20.
   */
  ada_really_inline constexpr bool begins_with(std::string_view view, std::string_view prefix);

  /**
   * Returns true if an input is an ipv4 address.
   */
  ada_really_inline ada_constexpr bool is_ipv4(std::string_view view) noexcept;

  /**
   * Returns a bitset. If the first bit is set, then at least one character needs
   * percent encoding. If the second bit is set, a \\ is found. If the third bit is set
   * then we have a dot. If the fourth bit is set, then we have a percent character.
   */
  ada_really_inline constexpr uint8_t path_signature(std::string_view input) noexcept;

  /** 
   * Returns true if the length of the domain name and its labels are according to the specifications.
   * The length of the domain must be 255 octets (253 characters not including the last 2 which are the empty
   * label reserved at the end). When the empty label is included (a dot at the end), the domain name can have
   * 254 characters. The length of a label must be at least 1 and at most 63 characters.
   * @see section 3.1. of https://www.rfc-editor.org/rfc/rfc1034
   * @see https://www.unicode.org/reports/tr46/#ToASCII
  */
  ada_really_inline constexpr bool verify_dns_length(std::string_view input) noexcept;

} // namespace ada::checkers

#endif //ADA_CHECKERS_H
/* end file include/ada/checkers.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/scheme.h
/* begin file include/ada/scheme.h */
/**
 * @file scheme.h
 * @brief Declarations for the URL scheme.
 */
#ifndef ADA_SCHEME_H
#define ADA_SCHEME_H


#include <array>
#include <optional>
#include <string>

/**
 * @namespace ada::scheme
 * @brief Includes the scheme declarations
 */
namespace ada::scheme {

  /**
   * Type of the scheme as an enum.
   * Using strings to represent a scheme type is not ideal because
   * checking for types involves string comparisons. It is faster to use
   * a simple integer.
   */
  enum type {
    HTTP = 0,
    NOT_SPECIAL = 1,
    HTTPS = 2,
    WS = 3,
    FTP = 4,
    WSS = 5,
    FILE = 6
  };

  /**
   * A special scheme is an ASCII string that is listed in the first column of the following table.
   * The default port for a special scheme is listed in the second column on the same row.
   * The default port for any other ASCII string is null.
   *
   * @see https://url.spec.whatwg.org/#url-miscellaneous
   * @param scheme
   * @return If scheme is a special scheme
   */
  ada_really_inline constexpr bool is_special(std::string_view scheme);

  /**
   * A special scheme is an ASCII string that is listed in the first column of the following table.
   * The default port for a special scheme is listed in the second column on the same row.
   * The default port for any other ASCII string is null.
   *
   * @see https://url.spec.whatwg.org/#url-miscellaneous
   * @param scheme
   * @return The special port
   */
  constexpr uint16_t get_special_port(std::string_view scheme) noexcept;

  /**
   * Returns the port number of a special scheme.
   * @see https://url.spec.whatwg.org/#special-scheme
   */
  constexpr uint16_t get_special_port(ada::scheme::type type) noexcept;
  /**
   * Returns the scheme of an input, or NOT_SPECIAL if it's not a special scheme defined by the spec.
   */
  constexpr ada::scheme::type get_scheme_type(std::string_view scheme) noexcept;

} // namespace ada::serializers

#endif // ADA_SCHEME_H
/* end file include/ada/scheme.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/serializers.h
/* begin file include/ada/serializers.h */
/**
 * @file serializers.h
 * @brief Definitions for the URL serializers.
 */
#ifndef ADA_SERIALIZERS_H
#define ADA_SERIALIZERS_H


#include <array>
#include <optional>
#include <string>

/**
 * @namespace ada::serializers
 * @brief Includes the definitions for URL serializers
 */
namespace ada::serializers {

  /**
   * Finds and returns the longest sequence of 0 values in a ipv6 input.
   */
  void find_longest_sequence_of_ipv6_pieces(const std::array<uint16_t, 8>& address, size_t& compress, size_t& compress_length) noexcept;

  /**
   * Serializes an ipv6 address.
   * @details An IPv6 address is a 128-bit unsigned integer that identifies a network address.
   * @see https://url.spec.whatwg.org/#concept-ipv6-serializer
   */
  std::string ipv6(const std::array<uint16_t, 8>& address) noexcept;

  /**
   * Serializes an ipv4 address.
   * @details An IPv4 address is a 32-bit unsigned integer that identifies a network address.
   * @see https://url.spec.whatwg.org/#concept-ipv4-serializer
   */
  std::string ipv4(const uint64_t address) noexcept;

} // namespace ada::serializers

#endif // ADA_SERIALIZERS_H
/* end file include/ada/serializers.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/unicode.h
/* begin file include/ada/unicode.h */
/**
 * @file unicode.h
 * @brief Definitions for all unicode specific functions.
 */
#ifndef ADA_UNICODE_H
#define ADA_UNICODE_H

#include <string>
#include <optional>

/**
 * @namespace ada::unicode
 * @brief Includes the definitions for unicode operations
 */
namespace ada::unicode {

  /**
   * We receive a UTF-8 string representing a domain name.
   * If the string is percent encoded, we apply percent decoding.
   *
   * Given a domain, we need to identify its labels.
   * They are separated by label-separators:
   *
   * U+002E ( . ) FULL STOP
   * U+FF0E ( ． ) FULLWIDTH FULL STOP
   * U+3002 ( 。 ) IDEOGRAPHIC FULL STOP
   * U+FF61 ( ｡ ) HALFWIDTH IDEOGRAPHIC FULL STOP
   *
   * They are all mapped to U+002E.
   *
   * We process each label into a string that should not exceed 63 octets.
   * If the string is already punycode (starts with "xn--"), then we must
   * scan it to look for unallowed code points.
   * Otherwise, if the string is not pure ASCII, we need to transcode it
   * to punycode by following RFC 3454 which requires us to
   * - Map characters  (see section 3),
   * - Normalize (see section 4),
   * - Reject forbidden characters,
   * - Check for right-to-left characters and if so, check all requirements (see section 6),
   * - Optionally reject based on unassigned code points (section 7).
   *
   * The Unicode standard provides a table of code points with a mapping, a list of
   * forbidden code points and so forth. This table is subject to change and will
   * vary based on the implementation. For Unicode 15, the table is at
   * https://www.unicode.org/Public/idna/15.0.0/IdnaMappingTable.txt
   * If you use ICU, they parse this table and map it to code using a Python script.
   *
   * The resulting strings should not exceed 255 octets according to RFC 1035 section 2.3.4.
   * ICU checks for label size and domain size, but if we pass "be_strict = false", these
   * errors are ignored.
   *
   * @see https://url.spec.whatwg.org/#concept-domain-to-ascii
   *
   */
  bool to_ascii(std::optional<std::string>& out, std::string_view plain, bool be_strict, size_t first_percent);

  /**
   * Checks if the input has tab or newline characters.
   *
   * @attention The has_tabs_or_newline function is a bottleneck and it is simple enough that compilers
   * like GCC can 'autovectorize it'.
   */
  ada_really_inline constexpr bool has_tabs_or_newline(std::string_view user_input) noexcept;

  /**
   * Checks if the input is a forbidden host code point.
   * @see https://url.spec.whatwg.org/#forbidden-host-code-point
   */
  ada_really_inline constexpr bool is_forbidden_host_code_point(const char c) noexcept;


  /**
   * Checks if the input is a forbidden domain code point.
   * @see https://url.spec.whatwg.org/#forbidden-domain-code-point
   */
  ada_really_inline constexpr bool contains_forbidden_domain_code_point(char * input, size_t length) noexcept;

  /**
   * Checks if the input is a forbidden doamin code point.
   * @see https://url.spec.whatwg.org/#forbidden-domain-code-point
   */
  ada_really_inline constexpr bool is_forbidden_domain_code_point(const char c) noexcept;

  /**
   * Checks if the input is alphanumeric, '+', '-' or '.'
   */
  ada_really_inline constexpr bool is_alnum_plus(const char c) noexcept;

  /**
   * @details An ASCII hex digit is an ASCII upper hex digit or ASCII lower hex digit.
   * An ASCII upper hex digit is an ASCII digit or a code point in the range U+0041 (A) to U+0046 (F), inclusive.
   * An ASCII lower hex digit is an ASCII digit or a code point in the range U+0061 (a) to U+0066 (f), inclusive.
   */
  ada_really_inline constexpr bool is_ascii_hex_digit(const char c) noexcept;

  /**
   * Checks if the input is a C0 control or space character.
   *
   * @details A C0 control or space is a C0 control or U+0020 SPACE.
   * A C0 control is a code point in the range U+0000 NULL to U+001F INFORMATION SEPARATOR ONE, inclusive.
   */
  ada_really_inline constexpr bool is_c0_control_or_space(const char c) noexcept;

  /**
   * Checks if the input is a ASCII tab or newline character.
   *
   * @details An ASCII tab or newline is U+0009 TAB, U+000A LF, or U+000D CR.
   */
  ada_really_inline constexpr bool is_ascii_tab_or_newline(const char c) noexcept;

  /**
   * @details A double-dot path segment must be ".." or an ASCII case-insensitive match for ".%2e", "%2e.", or "%2e%2e".
   */
  ada_really_inline ada_constexpr bool is_double_dot_path_segment(const std::string_view input) noexcept;

  /**
   * @details A single-dot path segment must be "." or an ASCII case-insensitive match for "%2e".
   */
  ada_really_inline constexpr bool is_single_dot_path_segment(const std::string_view input) noexcept;

  /**
   * @details ipv4 character might contain 0-9 or a-f character ranges.
   */
  ada_really_inline constexpr bool is_lowercase_hex(const char c) noexcept;

  /**
   * @details Convert hex to binary.
   */
  unsigned constexpr convert_hex_to_binary(char c) noexcept;

  /**
   * first_percent should be  = input.find('%')
   *
   * @todo It would be faster as noexcept maybe, but it could be unsafe since.
   * @author Node.js
   * @see https://github.com/nodejs/node/blob/main/src/node_url.cc#L245
   * @see https://encoding.spec.whatwg.org/#utf-8-decode-without-bom
   */
  std::string percent_decode(const std::string_view input, size_t first_percent);

  /**
   * Returns a percent-encoding string whether percent encoding was needed or not.
   * @see https://github.com/nodejs/node/blob/main/src/node_url.cc#L226
   */
  std::string percent_encode(const std::string_view input, const uint8_t character_set[]);

  /**
   * Returns true if percent encoding was needed, in which case, we store
   * the percent-encoded content in 'out'. Otherwise, out is left unchanged.
   * @see https://github.com/nodejs/node/blob/main/src/node_url.cc#L226
   */
  bool percent_encode(const std::string_view input, const uint8_t character_set[], std::string& out);

  /**
   * Lowers the string in-place, assuming that the content is ASCII.
   * Return true if the content was ASCII.
   */
  constexpr bool to_lower_ascii(char * input, size_t length) noexcept;
} // namespace ada::unicode

#endif // ADA_UNICODE_H
/* end file include/ada/unicode.h */

#include <algorithm>
#include <charconv>
#include <optional>
#include <iostream>
#include <string>
#include <string_view>

namespace ada {
  /**
   * @brief Generic URL struct.
   *
   * @details To disambiguate from a valid URL string it can also be referred to as a URL record.
   * A URL is a struct that represents a universal identifier.
   * @see https://url.spec.whatwg.org/#url-representation
   */
  struct url {
    url() = default;
    url(const url &u) = default;
    url(url &&u) noexcept = default;
    url &operator=(url &&u) noexcept = default;
    url &operator=(const url &u) = default;
    ADA_ATTRIBUTE_NOINLINE ~url() = default;

    /**
     * @private
     * A URL’s username is an ASCII string identifying a username. It is initially the empty string.
     */
    std::string username{};

    /**
     * @private
     * A URL’s password is an ASCII string identifying a password. It is initially the empty string.
     */
    std::string password{};

    /**
     * @private
     * A URL’s host is null or a host. It is initially null.
     */
    std::optional<std::string> host{};

    /**
     * @private
     * A URL’s port is either null or a 16-bit unsigned integer that identifies a networking port. It is initially null.
     */
    std::optional<uint16_t> port{};

    /**
     * @private
     * A URL’s path is either an ASCII string or a list of zero or more ASCII strings, usually identifying a location.
     */
    std::string path{};

    /**
     * @private
     * A URL’s query is either null or an ASCII string. It is initially null.
     */
    std::optional<std::string> query{};

    /**
     * @private
     * A URL’s fragment is either null or an ASCII string that can be used for further processing on the resource
     * the URL’s other components identify. It is initially null.
     */
    std::optional<std::string> fragment{};

    /**
     * @see https://url.spec.whatwg.org/#dom-url-href
     * @see https://url.spec.whatwg.org/#concept-url-serializer
     */
    [[nodiscard]] std::string get_href() const noexcept;

    /**
     * The origin getter steps are to return the serialization of this’s URL’s origin. [HTML]
     * @see https://url.spec.whatwg.org/#concept-url-origin
     */
    [[nodiscard]] std::string get_origin() const noexcept;

    /**
     * The protocol getter steps are to return this’s URL’s scheme, followed by U+003A (:).
     * @see https://url.spec.whatwg.org/#dom-url-protocol
     */
    [[nodiscard]] std::string get_protocol() const noexcept;

    /**
     * Return url’s host, serialized, followed by U+003A (:) and url’s port, serialized.
     * @see https://url.spec.whatwg.org/#dom-url-host
     */
    [[nodiscard]] std::string get_host() const noexcept;

    /**
     * Return this’s URL’s host, serialized.
     * @see https://url.spec.whatwg.org/#dom-url-hostname
     */
    [[nodiscard]] std::string get_hostname() const noexcept;

    /**
     * The pathname getter steps are to return the result of URL path serializing this’s URL.
     * @see https://url.spec.whatwg.org/#dom-url-pathname
     */
    [[nodiscard]] std::string get_pathname() const noexcept;

    /**
     * Return U+003F (?), followed by this’s URL’s query.
     * @see https://url.spec.whatwg.org/#dom-url-search
     */
    [[nodiscard]] std::string get_search() const noexcept;

    /**
     * The username getter steps are to return this’s URL’s username.
     * @see https://url.spec.whatwg.org/#dom-url-username
     */
    [[nodiscard]] std::string get_username() const noexcept;

    /**
     * @return Returns true on successful operation.
     * @see https://url.spec.whatwg.org/#dom-url-username
     */
    bool set_username(const std::string_view input);

    /**
     * @return Returns true on success.
     * @see https://url.spec.whatwg.org/#dom-url-password
     */
    bool set_password(const std::string_view input);

    /**
     * @return Returns true on success.
     * @see https://url.spec.whatwg.org/#dom-url-port
     */
    bool set_port(const std::string_view input);

    /**
     * This function always succeeds.
     * @see https://url.spec.whatwg.org/#dom-url-hash
     */
    void set_hash(const std::string_view input);

    /**
     * This function always succeeds.
     * @see https://url.spec.whatwg.org/#dom-url-search
     */
    void set_search(const std::string_view input);

    /**
     * @return Returns true on success.
     * @see https://url.spec.whatwg.org/#dom-url-search
     */
    bool set_pathname(const std::string_view input);

    /**
     * @return Returns true on success.
     * @see https://url.spec.whatwg.org/#dom-url-host
     */
    bool set_host(const std::string_view input);

    /**
     * @return Returns true on success.
     * @see https://url.spec.whatwg.org/#dom-url-hostname
     */
    bool set_hostname(const std::string_view input);

    /**
     * @return Returns true on success.
     * @see https://url.spec.whatwg.org/#dom-url-protocol
     */
    bool set_protocol(const std::string_view input);

    /**
     * @see https://url.spec.whatwg.org/#dom-url-href
     */
    bool set_href(const std::string_view input);

    /**
     * The password getter steps are to return this’s URL’s password.
     * @see https://url.spec.whatwg.org/#dom-url-password
     */
    [[nodiscard]] std::string get_password() const noexcept;

    /**
     * Return this’s URL’s port, serialized.
     * @see https://url.spec.whatwg.org/#dom-url-port
     */
    [[nodiscard]] std::string get_port() const noexcept;

    /**
     * Return U+0023 (#), followed by this’s URL’s fragment.
     * @see https://url.spec.whatwg.org/#dom-url-hash
     */
    [[nodiscard]] std::string get_hash() const noexcept;

    /**
     * Returns true if this URL has a valid domain as per RFC 1034 and
     * corresponding specifications. Among other things, it requires
     * that the domain string has fewer than 255 octets.
     */
    [[nodiscard]] bool has_valid_domain() const noexcept;

    /**
     * Used for returning the validity from the result of the URL parser.
     */
    bool is_valid{true};

    /**
     * A URL has an opaque path if its path is a string.
     */
    bool has_opaque_path{false};

    /**
     * A URL includes credentials if its username or password is not the empty string.
     */
    [[nodiscard]] ada_really_inline bool includes_credentials() const noexcept;

    /**
     * A URL is special if its scheme is a special scheme. A URL is not special if its scheme is not a special scheme.
     */
    [[nodiscard]] ada_really_inline bool is_special() const noexcept;

    /**
     * @private
     *
     * Return the 'special port' if the URL is special and not 'file'.
     * Returns 0 otherwise.
     */
    [[nodiscard]] inline uint16_t get_special_port() const;

    /**
     * @private
     *
     * Return the scheme type. Note that it is faster to do
     * get_scheme_type() == ada::scheme::type::FILE than to do
     * get_scheme() == "file", since the former is a direct integer comparison,
     * while the other involves a (cheap) string test.
     */
    [[nodiscard]] ada_really_inline ada::scheme::type get_scheme_type() const noexcept;

    /**
     * @private
     *
     * Get the default port if the url's scheme has one, returns 0 otherwise.
     */
    [[nodiscard]] ada_really_inline uint16_t scheme_default_port() const noexcept;
    /**
     * @private
     *
     * A URL cannot have a username/password/port if its host is null or the empty string, or its scheme is "file".
     */
    [[nodiscard]] inline bool cannot_have_credentials_or_port() const;

    /**
     * @private
     *
     * Parse a port (16-bit decimal digit) from the provided input.
     * We assume that the input does not contain spaces or tabs
     * within the ASCII digits.
     * It returns how many bytes were consumed when a number is successfully parsed.
     * @return On failure, it returns zero.
     * @see https://url.spec.whatwg.org/#host-parsing
     */
    ada_really_inline size_t parse_port(std::string_view view, bool check_trailing_content = false) noexcept;

    /**
     * @private
     *
     * Return a string representing the scheme. Note that get_scheme_type() should often be used instead.
     * @see https://url.spec.whatwg.org/#dom-url-protocol
     */
    [[nodiscard]] inline std::string_view get_scheme() const noexcept;
    /**
     * Set the scheme for this URL. The provided scheme should be a valid
     * scheme string, be lower-cased, not contain spaces or tabs. It should
     * have no spurious trailing or leading content.
     */
    inline void set_scheme(std::string&& new_scheme) noexcept;

    /**
     * @private
     *
     * Take the scheme from another URL. The scheme string is moved from the
     * provided url.
     */
    inline void copy_scheme(ada::url&& u) noexcept;

    /**
     * @private
     *
     * Take the scheme from another URL. The scheme string is copied from the
     * provided url.
     */
    inline void copy_scheme(const ada::url& u);

    /**
     * @private
     *
     * Parse the host from the provided input. We assume that
     * the input does not contain spaces or tabs. Control
     * characters and spaces are not trimmed (they should have
     * been removed if needed).
     * Return true on success.
     * @see https://url.spec.whatwg.org/#host-parsing
     */
    [[nodiscard]] ada_really_inline bool parse_host(std::string_view input);

    /**
     * @private
     *
     * Parse the path from the provided input.
     * Return true on success. Control characters not
     * trimmed from the ends (they should have
     * been removed if needed).
     *
     * The input is expected to be UTF-8.
     *
     * @see https://url.spec.whatwg.org/
     */
    [[nodiscard]] ada_really_inline bool parse_path(const std::string_view input);

    /**
     * @private
     */
    template <bool has_state_override = false>
    [[nodiscard]] ada_really_inline bool parse_scheme(const std::string_view input);

    /**
     * Returns a JSON string representation of this URL.
     */
    std::string to_string() const;

  private:

    /**
     * @private
     *
     * Return true on success.
     * @see https://url.spec.whatwg.org/#concept-ipv4-parser
     */
    [[nodiscard]] bool parse_ipv4(std::string_view input);

    /**
     * @private
     *
     * Return true on success.
     * @see https://url.spec.whatwg.org/#concept-ipv6-parser
     */
    [[nodiscard]] bool parse_ipv6(std::string_view input);

    /**
     * @private
     *
     * Return true on success.
     * @see https://url.spec.whatwg.org/#concept-opaque-host-parser
     */
    [[nodiscard]] bool parse_opaque_host(std::string_view input);

    /**
     * @private
     */
    ada::scheme::type type{ada::scheme::type::NOT_SPECIAL};

    /**
     * @private
     *
     * A URL’s scheme is an ASCII string that identifies the type of URL and can be used to dispatch a
     * URL for further processing after parsing. It is initially the empty string.
     * We only set non_special_scheme when the scheme is non-special, otherwise we avoid constructing
     * string.
     *
     * Special schemes are stored in ada::scheme::details::is_special_list so we typically do not need
     * to store them in each url instance.
     */
    std::string non_special_scheme{};

  }; // struct url


  inline std::ostream& operator<<(std::ostream& out, const ada::url& u);
} // namespace ada

#endif // ADA_URL_H
/* end file include/ada/url.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/state.h
/* begin file include/ada/state.h */
/**
 * @file state.h
 * @brief Definitions for the states of the URL state machine.
 */
#ifndef ADA_STATE_H
#define ADA_STATE_H


#include <string>

namespace ada {

  /**
   * @see https://url.spec.whatwg.org/#url-parsing
   */
  enum class state {
    AUTHORITY,
    SCHEME_START,
    SCHEME,
    HOST,
    NO_SCHEME,
    FRAGMENT,
    RELATIVE_SCHEME,
    RELATIVE_SLASH,
    FILE,
    FILE_HOST,
    FILE_SLASH,
    PATH_OR_AUTHORITY,
    SPECIAL_AUTHORITY_IGNORE_SLASHES,
    SPECIAL_AUTHORITY_SLASHES,
    SPECIAL_RELATIVE_OR_AUTHORITY,
    QUERY,
    PATH,
    PATH_START,
    OPAQUE_PATH,
    PORT,
  };

  /**
   * Stringify a URL state machine state.
   */
  ada_warn_unused std::string to_string(ada::state s);

} // ada namespace

#endif // ADA_STATE_H
/* end file include/ada/state.h */

#include <string_view>
#include <optional>

/**
 * @namespace ada::helpers
 * @brief Includes the definitions for helper functions
 */
namespace ada::helpers {

  /**
   * This function is used to prune a fragment from a url, and returning the removed string if input has fragment.
   *
   * @details prune_fragment seeks the first '#' and returns everything after it as a
   * string_view, and modifies (in place) the input so that it points at everything
   * before the '#'. If no '#' is found, the input is left unchanged and std::nullopt is returned.
   *
   * @attention The function is non-allocating and it does not throw.
   * @returns Note that the returned string_view might be empty!
   */
  ada_really_inline std::optional<std::string_view> prune_fragment(std::string_view& input) noexcept;

  /**
   * Defined by the URL specification, shorten a URLs paths.
   * @see https://url.spec.whatwg.org/#shorten-a-urls-path
   */
  ada_really_inline void shorten_path(std::string& path, ada::scheme::type type) noexcept;


 /**
  * @private
  *
  * Parse the path from the provided input and append to the existing
  * (possibly empty) path. The input cannot contain tabs and spaces: it
  * is the user's responsibility to check.
  *
  * The input is expected to be UTF-8.
  *
  * @return true on success.
  * @see https://url.spec.whatwg.org/
  */
  ada_really_inline bool parse_prepared_path(const std::string_view input, ada::scheme::type type, std::string& path);

  /**
   * Remove and mutate all ASCII tab or newline characters from an input.
   */
  ada_really_inline void remove_ascii_tab_or_newline(std::string& input) noexcept;

  /**
   * Return the substring from input going from index pos to the end. If pos > input.size(),
   * it returns an empty string_view. This function cannot throw.
   */
  ada_really_inline std::string_view substring(std::string_view input, size_t pos) noexcept;

  /**
   * Returns a host's delimiter location depending on the state of the instance.
   * Used by the host parser.
   */
  ada_really_inline size_t get_host_delimiter_location(const ada::url& url, std::string_view& view, bool& inside_brackets) noexcept;

  /**
   * Removes leading and trailing C0 control and whitespace characters from string.
   */
  ada_really_inline void trim_c0_whitespace(std::string_view& input) noexcept;

} // namespace ada::helpers

#endif // ADA_HELPERS_H
/* end file include/ada/helpers.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/parser.h
/* begin file include/ada/parser.h */
/**
 * @file parser.h
 * @brief Definitions for the parser.
 */
#ifndef ADA_PARSER_H
#define ADA_PARSER_H

// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/expected.h
/* begin file include/ada/expected.h */
/**
 * @file expected.h
 * @brief Definitions for std::expected
 * @private Excluded from docs through the doxygen file.
 */
///
// expected - An implementation of std::expected with extensions
// Written in 2017 by Sy Brand (tartanllama@gmail.com, @TartanLlama)
//
// Documentation available at http://tl.tartanllama.xyz/
//
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef TL_EXPECTED_HPP
#define TL_EXPECTED_HPP

#define TL_EXPECTED_VERSION_MAJOR 1
#define TL_EXPECTED_VERSION_MINOR 0
#define TL_EXPECTED_VERSION_PATCH 1

#include <exception>
#include <functional>
#include <type_traits>
#include <utility>

#if defined(__EXCEPTIONS) || defined(_CPPUNWIND)
#define TL_EXPECTED_EXCEPTIONS_ENABLED
#endif

#if (defined(_MSC_VER) && _MSC_VER == 1900)
#define TL_EXPECTED_MSVC2015
#define TL_EXPECTED_MSVC2015_CONSTEXPR
#else
#define TL_EXPECTED_MSVC2015_CONSTEXPR constexpr
#endif

#if (defined(__GNUC__) && __GNUC__ == 4 && __GNUC_MINOR__ <= 9 &&              \
     !defined(__clang__))
#define TL_EXPECTED_GCC49
#endif

#if (defined(__GNUC__) && __GNUC__ == 5 && __GNUC_MINOR__ <= 4 &&              \
     !defined(__clang__))
#define TL_EXPECTED_GCC54
#endif

#if (defined(__GNUC__) && __GNUC__ == 5 && __GNUC_MINOR__ <= 5 &&              \
     !defined(__clang__))
#define TL_EXPECTED_GCC55
#endif

#if (defined(__GNUC__) && __GNUC__ == 4 && __GNUC_MINOR__ <= 9 &&              \
     !defined(__clang__))
// GCC < 5 doesn't support overloading on const&& for member functions

#define TL_EXPECTED_NO_CONSTRR
// GCC < 5 doesn't support some standard C++11 type traits
#define TL_EXPECTED_IS_TRIVIALLY_COPY_CONSTRUCTIBLE(T)                         \
  std::has_trivial_copy_constructor<T>
#define TL_EXPECTED_IS_TRIVIALLY_COPY_ASSIGNABLE(T)                            \
  std::has_trivial_copy_assign<T>

// This one will be different for GCC 5.7 if it's ever supported
#define TL_EXPECTED_IS_TRIVIALLY_DESTRUCTIBLE(T)                               \
  std::is_trivially_destructible<T>

// GCC 5 < v < 8 has a bug in is_trivially_copy_constructible which breaks
// std::vector for non-copyable types
#elif (defined(__GNUC__) && __GNUC__ < 8 && !defined(__clang__))
#ifndef TL_GCC_LESS_8_TRIVIALLY_COPY_CONSTRUCTIBLE_MUTEX
#define TL_GCC_LESS_8_TRIVIALLY_COPY_CONSTRUCTIBLE_MUTEX
namespace tl {
namespace detail {
template <class T>
struct is_trivially_copy_constructible
    : std::is_trivially_copy_constructible<T> {};
#ifdef _GLIBCXX_VECTOR
template <class T, class A>
struct is_trivially_copy_constructible<std::vector<T, A>> : std::false_type {};
#endif
} // namespace detail
} // namespace tl
#endif

#define TL_EXPECTED_IS_TRIVIALLY_COPY_CONSTRUCTIBLE(T)                         \
  tl::detail::is_trivially_copy_constructible<T>
#define TL_EXPECTED_IS_TRIVIALLY_COPY_ASSIGNABLE(T)                            \
  std::is_trivially_copy_assignable<T>
#define TL_EXPECTED_IS_TRIVIALLY_DESTRUCTIBLE(T)                               \
  std::is_trivially_destructible<T>
#else
#define TL_EXPECTED_IS_TRIVIALLY_COPY_CONSTRUCTIBLE(T)                         \
  std::is_trivially_copy_constructible<T>
#define TL_EXPECTED_IS_TRIVIALLY_COPY_ASSIGNABLE(T)                            \
  std::is_trivially_copy_assignable<T>
#define TL_EXPECTED_IS_TRIVIALLY_DESTRUCTIBLE(T)                               \
  std::is_trivially_destructible<T>
#endif

#if __cplusplus > 201103L
#define TL_EXPECTED_CXX14
#endif

#ifdef TL_EXPECTED_GCC49
#define TL_EXPECTED_GCC49_CONSTEXPR
#else
#define TL_EXPECTED_GCC49_CONSTEXPR constexpr
#endif

#if (__cplusplus == 201103L || defined(TL_EXPECTED_MSVC2015) ||                \
     defined(TL_EXPECTED_GCC49))
#define TL_EXPECTED_11_CONSTEXPR
#else
#define TL_EXPECTED_11_CONSTEXPR constexpr
#endif

namespace tl {
template <class T, class E> class expected;

#ifndef TL_MONOSTATE_INPLACE_MUTEX
#define TL_MONOSTATE_INPLACE_MUTEX
class monostate {};

struct in_place_t {
  explicit in_place_t() = default;
};
static constexpr in_place_t in_place{};
#endif

template <class E> class unexpected {
public:
  static_assert(!std::is_same<E, void>::value, "E must not be void");

  unexpected() = delete;
  constexpr explicit unexpected(const E &e) : m_val(e) {}

  constexpr explicit unexpected(E &&e) : m_val(std::move(e)) {}

  template <class... Args, typename std::enable_if<std::is_constructible<
                               E, Args &&...>::value>::type * = nullptr>
  constexpr explicit unexpected(Args &&...args)
      : m_val(std::forward<Args>(args)...) {}
  template <
      class U, class... Args,
      typename std::enable_if<std::is_constructible<
          E, std::initializer_list<U> &, Args &&...>::value>::type * = nullptr>
  constexpr explicit unexpected(std::initializer_list<U> l, Args &&...args)
      : m_val(l, std::forward<Args>(args)...) {}

  constexpr const E &value() const & { return m_val; }
  TL_EXPECTED_11_CONSTEXPR E &value() & { return m_val; }
  TL_EXPECTED_11_CONSTEXPR E &&value() && { return std::move(m_val); }
  constexpr const E &&value() const && { return std::move(m_val); }

private:
  E m_val;
};

#ifdef __cpp_deduction_guides
template <class E> unexpected(E) -> unexpected<E>;
#endif

template <class E>
constexpr bool operator==(const unexpected<E> &lhs, const unexpected<E> &rhs) {
  return lhs.value() == rhs.value();
}
template <class E>
constexpr bool operator!=(const unexpected<E> &lhs, const unexpected<E> &rhs) {
  return lhs.value() != rhs.value();
}
template <class E>
constexpr bool operator<(const unexpected<E> &lhs, const unexpected<E> &rhs) {
  return lhs.value() < rhs.value();
}
template <class E>
constexpr bool operator<=(const unexpected<E> &lhs, const unexpected<E> &rhs) {
  return lhs.value() <= rhs.value();
}
template <class E>
constexpr bool operator>(const unexpected<E> &lhs, const unexpected<E> &rhs) {
  return lhs.value() > rhs.value();
}
template <class E>
constexpr bool operator>=(const unexpected<E> &lhs, const unexpected<E> &rhs) {
  return lhs.value() >= rhs.value();
}

template <class E>
unexpected<typename std::decay<E>::type> make_unexpected(E &&e) {
  return unexpected<typename std::decay<E>::type>(std::forward<E>(e));
}

struct unexpect_t {
  unexpect_t() = default;
};
static constexpr unexpect_t unexpect{};

namespace detail {
template <typename E>
[[noreturn]] TL_EXPECTED_11_CONSTEXPR void throw_exception(E &&e) {
#ifdef TL_EXPECTED_EXCEPTIONS_ENABLED
  throw std::forward<E>(e);
#else
#ifdef _MSC_VER
  __assume(0);
#else
  __builtin_unreachable();
#endif
#endif
}

#ifndef TL_TRAITS_MUTEX
#define TL_TRAITS_MUTEX
// C++14-style aliases for brevity
template <class T> using remove_const_t = typename std::remove_const<T>::type;
template <class T>
using remove_reference_t = typename std::remove_reference<T>::type;
template <class T> using decay_t = typename std::decay<T>::type;
template <bool E, class T = void>
using enable_if_t = typename std::enable_if<E, T>::type;
template <bool B, class T, class F>
using conditional_t = typename std::conditional<B, T, F>::type;

// std::conjunction from C++17
template <class...> struct conjunction : std::true_type {};
template <class B> struct conjunction<B> : B {};
template <class B, class... Bs>
struct conjunction<B, Bs...>
    : std::conditional<bool(B::value), conjunction<Bs...>, B>::type {};

#if defined(_LIBCPP_VERSION) && __cplusplus == 201103L
#define TL_TRAITS_LIBCXX_MEM_FN_WORKAROUND
#endif

// In C++11 mode, there's an issue in libc++'s std::mem_fn
// which results in a hard-error when using it in a noexcept expression
// in some cases. This is a check to workaround the common failing case.
#ifdef TL_TRAITS_LIBCXX_MEM_FN_WORKAROUND
template <class T>
struct is_pointer_to_non_const_member_func : std::false_type {};
template <class T, class Ret, class... Args>
struct is_pointer_to_non_const_member_func<Ret (T::*)(Args...)>
    : std::true_type {};
template <class T, class Ret, class... Args>
struct is_pointer_to_non_const_member_func<Ret (T::*)(Args...) &>
    : std::true_type {};
template <class T, class Ret, class... Args>
struct is_pointer_to_non_const_member_func<Ret (T::*)(Args...) &&>
    : std::true_type {};
template <class T, class Ret, class... Args>
struct is_pointer_to_non_const_member_func<Ret (T::*)(Args...) volatile>
    : std::true_type {};
template <class T, class Ret, class... Args>
struct is_pointer_to_non_const_member_func<Ret (T::*)(Args...) volatile &>
    : std::true_type {};
template <class T, class Ret, class... Args>
struct is_pointer_to_non_const_member_func<Ret (T::*)(Args...) volatile &&>
    : std::true_type {};

template <class T> struct is_const_or_const_ref : std::false_type {};
template <class T> struct is_const_or_const_ref<T const &> : std::true_type {};
template <class T> struct is_const_or_const_ref<T const> : std::true_type {};
#endif

// std::invoke from C++17
// https://stackoverflow.com/questions/38288042/c11-14-invoke-workaround
template <
    typename Fn, typename... Args,
#ifdef TL_TRAITS_LIBCXX_MEM_FN_WORKAROUND
    typename = enable_if_t<!(is_pointer_to_non_const_member_func<Fn>::value &&
                             is_const_or_const_ref<Args...>::value)>,
#endif
    typename = enable_if_t<std::is_member_pointer<decay_t<Fn>>::value>, int = 0>
constexpr auto invoke(Fn &&f, Args &&...args) noexcept(
    noexcept(std::mem_fn(f)(std::forward<Args>(args)...)))
    -> decltype(std::mem_fn(f)(std::forward<Args>(args)...)) {
  return std::mem_fn(f)(std::forward<Args>(args)...);
}

template <typename Fn, typename... Args,
          typename = enable_if_t<!std::is_member_pointer<decay_t<Fn>>::value>>
constexpr auto invoke(Fn &&f, Args &&...args) noexcept(
    noexcept(std::forward<Fn>(f)(std::forward<Args>(args)...)))
    -> decltype(std::forward<Fn>(f)(std::forward<Args>(args)...)) {
  return std::forward<Fn>(f)(std::forward<Args>(args)...);
}

// std::invoke_result from C++17
template <class F, class, class... Us> struct invoke_result_impl;

template <class F, class... Us>
struct invoke_result_impl<
    F,
    decltype(detail::invoke(std::declval<F>(), std::declval<Us>()...), void()),
    Us...> {
  using type =
      decltype(detail::invoke(std::declval<F>(), std::declval<Us>()...));
};

template <class F, class... Us>
using invoke_result = invoke_result_impl<F, void, Us...>;

template <class F, class... Us>
using invoke_result_t = typename invoke_result<F, Us...>::type;

#if defined(_MSC_VER) && _MSC_VER <= 1900
// TODO make a version which works with MSVC 2015
template <class T, class U = T> struct is_swappable : std::true_type {};

template <class T, class U = T> struct is_nothrow_swappable : std::true_type {};
#else
// https://stackoverflow.com/questions/26744589/what-is-a-proper-way-to-implement-is-swappable-to-test-for-the-swappable-concept
namespace swap_adl_tests {
// if swap ADL finds this then it would call std::swap otherwise (same
// signature)
struct tag {};

template <class T> tag swap(T &, T &);
template <class T, std::size_t N> tag swap(T (&a)[N], T (&b)[N]);

// helper functions to test if an unqualified swap is possible, and if it
// becomes std::swap
template <class, class> std::false_type can_swap(...) noexcept(false);
template <class T, class U,
          class = decltype(swap(std::declval<T &>(), std::declval<U &>()))>
std::true_type can_swap(int) noexcept(noexcept(swap(std::declval<T &>(),
                                                    std::declval<U &>())));

template <class, class> std::false_type uses_std(...);
template <class T, class U>
std::is_same<decltype(swap(std::declval<T &>(), std::declval<U &>())), tag>
uses_std(int);

template <class T>
struct is_std_swap_noexcept
    : std::integral_constant<bool,
                             std::is_nothrow_move_constructible<T>::value &&
                                 std::is_nothrow_move_assignable<T>::value> {};

template <class T, std::size_t N>
struct is_std_swap_noexcept<T[N]> : is_std_swap_noexcept<T> {};

template <class T, class U>
struct is_adl_swap_noexcept
    : std::integral_constant<bool, noexcept(can_swap<T, U>(0))> {};
} // namespace swap_adl_tests

template <class T, class U = T>
struct is_swappable
    : std::integral_constant<
          bool,
          decltype(detail::swap_adl_tests::can_swap<T, U>(0))::value &&
              (!decltype(detail::swap_adl_tests::uses_std<T, U>(0))::value ||
               (std::is_move_assignable<T>::value &&
                std::is_move_constructible<T>::value))> {};

template <class T, std::size_t N>
struct is_swappable<T[N], T[N]>
    : std::integral_constant<
          bool,
          decltype(detail::swap_adl_tests::can_swap<T[N], T[N]>(0))::value &&
              (!decltype(detail::swap_adl_tests::uses_std<T[N], T[N]>(
                   0))::value ||
               is_swappable<T, T>::value)> {};

template <class T, class U = T>
struct is_nothrow_swappable
    : std::integral_constant<
          bool,
          is_swappable<T, U>::value &&
              ((decltype(detail::swap_adl_tests::uses_std<T, U>(0))::value &&
                detail::swap_adl_tests::is_std_swap_noexcept<T>::value) ||
               (!decltype(detail::swap_adl_tests::uses_std<T, U>(0))::value &&
                detail::swap_adl_tests::is_adl_swap_noexcept<T, U>::value))> {};
#endif
#endif

// Trait for checking if a type is a tl::expected
template <class T> struct is_expected_impl : std::false_type {};
template <class T, class E>
struct is_expected_impl<expected<T, E>> : std::true_type {};
template <class T> using is_expected = is_expected_impl<decay_t<T>>;

template <class T, class E, class U>
using expected_enable_forward_value = detail::enable_if_t<
    std::is_constructible<T, U &&>::value &&
    !std::is_same<detail::decay_t<U>, in_place_t>::value &&
    !std::is_same<expected<T, E>, detail::decay_t<U>>::value &&
    !std::is_same<unexpected<E>, detail::decay_t<U>>::value>;

template <class T, class E, class U, class G, class UR, class GR>
using expected_enable_from_other = detail::enable_if_t<
    std::is_constructible<T, UR>::value &&
    std::is_constructible<E, GR>::value &&
    !std::is_constructible<T, expected<U, G> &>::value &&
    !std::is_constructible<T, expected<U, G> &&>::value &&
    !std::is_constructible<T, const expected<U, G> &>::value &&
    !std::is_constructible<T, const expected<U, G> &&>::value &&
    !std::is_convertible<expected<U, G> &, T>::value &&
    !std::is_convertible<expected<U, G> &&, T>::value &&
    !std::is_convertible<const expected<U, G> &, T>::value &&
    !std::is_convertible<const expected<U, G> &&, T>::value>;

template <class T, class U>
using is_void_or = conditional_t<std::is_void<T>::value, std::true_type, U>;

template <class T>
using is_copy_constructible_or_void =
    is_void_or<T, std::is_copy_constructible<T>>;

template <class T>
using is_move_constructible_or_void =
    is_void_or<T, std::is_move_constructible<T>>;

template <class T>
using is_copy_assignable_or_void = is_void_or<T, std::is_copy_assignable<T>>;

template <class T>
using is_move_assignable_or_void = is_void_or<T, std::is_move_assignable<T>>;

} // namespace detail

namespace detail {
struct no_init_t {};
static constexpr no_init_t no_init{};

// Implements the storage of the values, and ensures that the destructor is
// trivial if it can be.
//
// This specialization is for where neither `T` or `E` is trivially
// destructible, so the destructors must be called on destruction of the
// `expected`
template <class T, class E, bool = std::is_trivially_destructible<T>::value,
          bool = std::is_trivially_destructible<E>::value>
struct expected_storage_base {
  constexpr expected_storage_base() : m_val(T{}), m_has_val(true) {}
  constexpr expected_storage_base(no_init_t) : m_no_init(), m_has_val(false) {}

  template <class... Args,
            detail::enable_if_t<std::is_constructible<T, Args &&...>::value> * =
                nullptr>
  constexpr expected_storage_base(in_place_t, Args &&...args)
      : m_val(std::forward<Args>(args)...), m_has_val(true) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                T, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr expected_storage_base(in_place_t, std::initializer_list<U> il,
                                  Args &&...args)
      : m_val(il, std::forward<Args>(args)...), m_has_val(true) {}
  template <class... Args,
            detail::enable_if_t<std::is_constructible<E, Args &&...>::value> * =
                nullptr>
  constexpr explicit expected_storage_base(unexpect_t, Args &&...args)
      : m_unexpect(std::forward<Args>(args)...), m_has_val(false) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                E, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr explicit expected_storage_base(unexpect_t,
                                           std::initializer_list<U> il,
                                           Args &&...args)
      : m_unexpect(il, std::forward<Args>(args)...), m_has_val(false) {}

  ~expected_storage_base() {
    if (m_has_val) {
      m_val.~T();
    } else {
      m_unexpect.~unexpected<E>();
    }
  }
  union {
    T m_val;
    unexpected<E> m_unexpect;
    char m_no_init;
  };
  bool m_has_val;
};

// This specialization is for when both `T` and `E` are trivially-destructible,
// so the destructor of the `expected` can be trivial.
template <class T, class E> struct expected_storage_base<T, E, true, true> {
  constexpr expected_storage_base() : m_val(T{}), m_has_val(true) {}
  constexpr expected_storage_base(no_init_t) : m_no_init(), m_has_val(false) {}

  template <class... Args,
            detail::enable_if_t<std::is_constructible<T, Args &&...>::value> * =
                nullptr>
  constexpr expected_storage_base(in_place_t, Args &&...args)
      : m_val(std::forward<Args>(args)...), m_has_val(true) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                T, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr expected_storage_base(in_place_t, std::initializer_list<U> il,
                                  Args &&...args)
      : m_val(il, std::forward<Args>(args)...), m_has_val(true) {}
  template <class... Args,
            detail::enable_if_t<std::is_constructible<E, Args &&...>::value> * =
                nullptr>
  constexpr explicit expected_storage_base(unexpect_t, Args &&...args)
      : m_unexpect(std::forward<Args>(args)...), m_has_val(false) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                E, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr explicit expected_storage_base(unexpect_t,
                                           std::initializer_list<U> il,
                                           Args &&...args)
      : m_unexpect(il, std::forward<Args>(args)...), m_has_val(false) {}

  ~expected_storage_base() = default;
  union {
    T m_val;
    unexpected<E> m_unexpect;
    char m_no_init;
  };
  bool m_has_val;
};

// T is trivial, E is not.
template <class T, class E> struct expected_storage_base<T, E, true, false> {
  constexpr expected_storage_base() : m_val(T{}), m_has_val(true) {}
  TL_EXPECTED_MSVC2015_CONSTEXPR expected_storage_base(no_init_t)
      : m_no_init(), m_has_val(false) {}

  template <class... Args,
            detail::enable_if_t<std::is_constructible<T, Args &&...>::value> * =
                nullptr>
  constexpr expected_storage_base(in_place_t, Args &&...args)
      : m_val(std::forward<Args>(args)...), m_has_val(true) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                T, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr expected_storage_base(in_place_t, std::initializer_list<U> il,
                                  Args &&...args)
      : m_val(il, std::forward<Args>(args)...), m_has_val(true) {}
  template <class... Args,
            detail::enable_if_t<std::is_constructible<E, Args &&...>::value> * =
                nullptr>
  constexpr explicit expected_storage_base(unexpect_t, Args &&...args)
      : m_unexpect(std::forward<Args>(args)...), m_has_val(false) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                E, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr explicit expected_storage_base(unexpect_t,
                                           std::initializer_list<U> il,
                                           Args &&...args)
      : m_unexpect(il, std::forward<Args>(args)...), m_has_val(false) {}

  ~expected_storage_base() {
    if (!m_has_val) {
      m_unexpect.~unexpected<E>();
    }
  }

  union {
    T m_val;
    unexpected<E> m_unexpect;
    char m_no_init;
  };
  bool m_has_val;
};

// E is trivial, T is not.
template <class T, class E> struct expected_storage_base<T, E, false, true> {
  constexpr expected_storage_base() : m_val(T{}), m_has_val(true) {}
  constexpr expected_storage_base(no_init_t) : m_no_init(), m_has_val(false) {}

  template <class... Args,
            detail::enable_if_t<std::is_constructible<T, Args &&...>::value> * =
                nullptr>
  constexpr expected_storage_base(in_place_t, Args &&...args)
      : m_val(std::forward<Args>(args)...), m_has_val(true) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                T, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr expected_storage_base(in_place_t, std::initializer_list<U> il,
                                  Args &&...args)
      : m_val(il, std::forward<Args>(args)...), m_has_val(true) {}
  template <class... Args,
            detail::enable_if_t<std::is_constructible<E, Args &&...>::value> * =
                nullptr>
  constexpr explicit expected_storage_base(unexpect_t, Args &&...args)
      : m_unexpect(std::forward<Args>(args)...), m_has_val(false) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                E, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr explicit expected_storage_base(unexpect_t,
                                           std::initializer_list<U> il,
                                           Args &&...args)
      : m_unexpect(il, std::forward<Args>(args)...), m_has_val(false) {}

  ~expected_storage_base() {
    if (m_has_val) {
      m_val.~T();
    }
  }
  union {
    T m_val;
    unexpected<E> m_unexpect;
    char m_no_init;
  };
  bool m_has_val;
};

// `T` is `void`, `E` is trivially-destructible
template <class E> struct expected_storage_base<void, E, false, true> {
  #if __GNUC__ <= 5
  //no constexpr for GCC 4/5 bug
  #else
  TL_EXPECTED_MSVC2015_CONSTEXPR
  #endif 
  expected_storage_base() : m_has_val(true) {}
     
  constexpr expected_storage_base(no_init_t) : m_val(), m_has_val(false) {}

  constexpr expected_storage_base(in_place_t) : m_has_val(true) {}

  template <class... Args,
            detail::enable_if_t<std::is_constructible<E, Args &&...>::value> * =
                nullptr>
  constexpr explicit expected_storage_base(unexpect_t, Args &&...args)
      : m_unexpect(std::forward<Args>(args)...), m_has_val(false) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                E, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr explicit expected_storage_base(unexpect_t,
                                           std::initializer_list<U> il,
                                           Args &&...args)
      : m_unexpect(il, std::forward<Args>(args)...), m_has_val(false) {}

  ~expected_storage_base() = default;
  struct dummy {};
  union {
    unexpected<E> m_unexpect;
    dummy m_val;
  };
  bool m_has_val;
};

// `T` is `void`, `E` is not trivially-destructible
template <class E> struct expected_storage_base<void, E, false, false> {
  constexpr expected_storage_base() : m_dummy(), m_has_val(true) {}
  constexpr expected_storage_base(no_init_t) : m_dummy(), m_has_val(false) {}

  constexpr expected_storage_base(in_place_t) : m_dummy(), m_has_val(true) {}

  template <class... Args,
            detail::enable_if_t<std::is_constructible<E, Args &&...>::value> * =
                nullptr>
  constexpr explicit expected_storage_base(unexpect_t, Args &&...args)
      : m_unexpect(std::forward<Args>(args)...), m_has_val(false) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                E, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr explicit expected_storage_base(unexpect_t,
                                           std::initializer_list<U> il,
                                           Args &&...args)
      : m_unexpect(il, std::forward<Args>(args)...), m_has_val(false) {}

  ~expected_storage_base() {
    if (!m_has_val) {
      m_unexpect.~unexpected<E>();
    }
  }

  union {
    unexpected<E> m_unexpect;
    char m_dummy;
  };
  bool m_has_val;
};

// This base class provides some handy member functions which can be used in
// further derived classes
template <class T, class E>
struct expected_operations_base : expected_storage_base<T, E> {
  using expected_storage_base<T, E>::expected_storage_base;

  template <class... Args> void construct(Args &&...args) noexcept {
    new (std::addressof(this->m_val)) T(std::forward<Args>(args)...);
    this->m_has_val = true;
  }

  template <class Rhs> void construct_with(Rhs &&rhs) noexcept {
    new (std::addressof(this->m_val)) T(std::forward<Rhs>(rhs).get());
    this->m_has_val = true;
  }

  template <class... Args> void construct_error(Args &&...args) noexcept {
    new (std::addressof(this->m_unexpect))
        unexpected<E>(std::forward<Args>(args)...);
    this->m_has_val = false;
  }

#ifdef TL_EXPECTED_EXCEPTIONS_ENABLED

  // These assign overloads ensure that the most efficient assignment
  // implementation is used while maintaining the strong exception guarantee.
  // The problematic case is where rhs has a value, but *this does not.
  //
  // This overload handles the case where we can just copy-construct `T`
  // directly into place without throwing.
  template <class U = T,
            detail::enable_if_t<std::is_nothrow_copy_constructible<U>::value>
                * = nullptr>
  void assign(const expected_operations_base &rhs) noexcept {
    if (!this->m_has_val && rhs.m_has_val) {
      geterr().~unexpected<E>();
      construct(rhs.get());
    } else {
      assign_common(rhs);
    }
  }

  // This overload handles the case where we can attempt to create a copy of
  // `T`, then no-throw move it into place if the copy was successful.
  template <class U = T,
            detail::enable_if_t<!std::is_nothrow_copy_constructible<U>::value &&
                                std::is_nothrow_move_constructible<U>::value>
                * = nullptr>
  void assign(const expected_operations_base &rhs) noexcept {
    if (!this->m_has_val && rhs.m_has_val) {
      T tmp = rhs.get();
      geterr().~unexpected<E>();
      construct(std::move(tmp));
    } else {
      assign_common(rhs);
    }
  }

  // This overload is the worst-case, where we have to move-construct the
  // unexpected value into temporary storage, then try to copy the T into place.
  // If the construction succeeds, then everything is fine, but if it throws,
  // then we move the old unexpected value back into place before rethrowing the
  // exception.
  template <class U = T,
            detail::enable_if_t<!std::is_nothrow_copy_constructible<U>::value &&
                                !std::is_nothrow_move_constructible<U>::value>
                * = nullptr>
  void assign(const expected_operations_base &rhs) {
    if (!this->m_has_val && rhs.m_has_val) {
      auto tmp = std::move(geterr());
      geterr().~unexpected<E>();

#ifdef TL_EXPECTED_EXCEPTIONS_ENABLED
      try {
        construct(rhs.get());
      } catch (...) {
        geterr() = std::move(tmp);
        throw;
      }
#else
      construct(rhs.get());
#endif
    } else {
      assign_common(rhs);
    }
  }

  // These overloads do the same as above, but for rvalues
  template <class U = T,
            detail::enable_if_t<std::is_nothrow_move_constructible<U>::value>
                * = nullptr>
  void assign(expected_operations_base &&rhs) noexcept {
    if (!this->m_has_val && rhs.m_has_val) {
      geterr().~unexpected<E>();
      construct(std::move(rhs).get());
    } else {
      assign_common(std::move(rhs));
    }
  }

  template <class U = T,
            detail::enable_if_t<!std::is_nothrow_move_constructible<U>::value>
                * = nullptr>
  void assign(expected_operations_base &&rhs) {
    if (!this->m_has_val && rhs.m_has_val) {
      auto tmp = std::move(geterr());
      geterr().~unexpected<E>();
#ifdef TL_EXPECTED_EXCEPTIONS_ENABLED
      try {
        construct(std::move(rhs).get());
      } catch (...) {
        geterr() = std::move(tmp);
        throw;
      }
#else
      construct(std::move(rhs).get());
#endif
    } else {
      assign_common(std::move(rhs));
    }
  }

#else

  // If exceptions are disabled then we can just copy-construct
  void assign(const expected_operations_base &rhs) noexcept {
    if (!this->m_has_val && rhs.m_has_val) {
      geterr().~unexpected<E>();
      construct(rhs.get());
    } else {
      assign_common(rhs);
    }
  }

  void assign(expected_operations_base &&rhs) noexcept {
    if (!this->m_has_val && rhs.m_has_val) {
      geterr().~unexpected<E>();
      construct(std::move(rhs).get());
    } else {
      assign_common(rhs);
    }
  }

#endif

  // The common part of move/copy assigning
  template <class Rhs> void assign_common(Rhs &&rhs) {
    if (this->m_has_val) {
      if (rhs.m_has_val) {
        get() = std::forward<Rhs>(rhs).get();
      } else {
        destroy_val();
        construct_error(std::forward<Rhs>(rhs).geterr());
      }
    } else {
      if (!rhs.m_has_val) {
        geterr() = std::forward<Rhs>(rhs).geterr();
      }
    }
  }

  bool has_value() const { return this->m_has_val; }

  TL_EXPECTED_11_CONSTEXPR T &get() & { return this->m_val; }
  constexpr const T &get() const & { return this->m_val; }
  TL_EXPECTED_11_CONSTEXPR T &&get() && { return std::move(this->m_val); }
#ifndef TL_EXPECTED_NO_CONSTRR
  constexpr const T &&get() const && { return std::move(this->m_val); }
#endif

  TL_EXPECTED_11_CONSTEXPR unexpected<E> &geterr() & {
    return this->m_unexpect;
  }
  constexpr const unexpected<E> &geterr() const & { return this->m_unexpect; }
  TL_EXPECTED_11_CONSTEXPR unexpected<E> &&geterr() && {
    return std::move(this->m_unexpect);
  }
#ifndef TL_EXPECTED_NO_CONSTRR
  constexpr const unexpected<E> &&geterr() const && {
    return std::move(this->m_unexpect);
  }
#endif

  TL_EXPECTED_11_CONSTEXPR void destroy_val() { get().~T(); }
};

// This base class provides some handy member functions which can be used in
// further derived classes
template <class E>
struct expected_operations_base<void, E> : expected_storage_base<void, E> {
  using expected_storage_base<void, E>::expected_storage_base;

  template <class... Args> void construct() noexcept { this->m_has_val = true; }

  // This function doesn't use its argument, but needs it so that code in
  // levels above this can work independently of whether T is void
  template <class Rhs> void construct_with(Rhs &&) noexcept {
    this->m_has_val = true;
  }

  template <class... Args> void construct_error(Args &&...args) noexcept {
    new (std::addressof(this->m_unexpect))
        unexpected<E>(std::forward<Args>(args)...);
    this->m_has_val = false;
  }

  template <class Rhs> void assign(Rhs &&rhs) noexcept {
    if (!this->m_has_val) {
      if (rhs.m_has_val) {
        geterr().~unexpected<E>();
        construct();
      } else {
        geterr() = std::forward<Rhs>(rhs).geterr();
      }
    } else {
      if (!rhs.m_has_val) {
        construct_error(std::forward<Rhs>(rhs).geterr());
      }
    }
  }

  bool has_value() const { return this->m_has_val; }

  TL_EXPECTED_11_CONSTEXPR unexpected<E> &geterr() & {
    return this->m_unexpect;
  }
  constexpr const unexpected<E> &geterr() const & { return this->m_unexpect; }
  TL_EXPECTED_11_CONSTEXPR unexpected<E> &&geterr() && {
    return std::move(this->m_unexpect);
  }
#ifndef TL_EXPECTED_NO_CONSTRR
  constexpr const unexpected<E> &&geterr() const && {
    return std::move(this->m_unexpect);
  }
#endif

  TL_EXPECTED_11_CONSTEXPR void destroy_val() {
    // no-op
  }
};

// This class manages conditionally having a trivial copy constructor
// This specialization is for when T and E are trivially copy constructible
template <class T, class E,
          bool = is_void_or<T, TL_EXPECTED_IS_TRIVIALLY_COPY_CONSTRUCTIBLE(T)>::
              value &&TL_EXPECTED_IS_TRIVIALLY_COPY_CONSTRUCTIBLE(E)::value>
struct expected_copy_base : expected_operations_base<T, E> {
  using expected_operations_base<T, E>::expected_operations_base;
};

// This specialization is for when T or E are not trivially copy constructible
template <class T, class E>
struct expected_copy_base<T, E, false> : expected_operations_base<T, E> {
  using expected_operations_base<T, E>::expected_operations_base;

  expected_copy_base() = default;
  expected_copy_base(const expected_copy_base &rhs)
      : expected_operations_base<T, E>(no_init) {
    if (rhs.has_value()) {
      this->construct_with(rhs);
    } else {
      this->construct_error(rhs.geterr());
    }
  }

  expected_copy_base(expected_copy_base &&rhs) = default;
  expected_copy_base &operator=(const expected_copy_base &rhs) = default;
  expected_copy_base &operator=(expected_copy_base &&rhs) = default;
};

// This class manages conditionally having a trivial move constructor
// Unfortunately there's no way to achieve this in GCC < 5 AFAIK, since it
// doesn't implement an analogue to std::is_trivially_move_constructible. We
// have to make do with a non-trivial move constructor even if T is trivially
// move constructible
#ifndef TL_EXPECTED_GCC49
template <class T, class E,
          bool = is_void_or<T, std::is_trivially_move_constructible<T>>::value
              &&std::is_trivially_move_constructible<E>::value>
struct expected_move_base : expected_copy_base<T, E> {
  using expected_copy_base<T, E>::expected_copy_base;
};
#else
template <class T, class E, bool = false> struct expected_move_base;
#endif
template <class T, class E>
struct expected_move_base<T, E, false> : expected_copy_base<T, E> {
  using expected_copy_base<T, E>::expected_copy_base;

  expected_move_base() = default;
  expected_move_base(const expected_move_base &rhs) = default;

  expected_move_base(expected_move_base &&rhs) noexcept(
      std::is_nothrow_move_constructible<T>::value)
      : expected_copy_base<T, E>(no_init) {
    if (rhs.has_value()) {
      this->construct_with(std::move(rhs));
    } else {
      this->construct_error(std::move(rhs.geterr()));
    }
  }
  expected_move_base &operator=(const expected_move_base &rhs) = default;
  expected_move_base &operator=(expected_move_base &&rhs) = default;
};

// This class manages conditionally having a trivial copy assignment operator
template <class T, class E,
          bool = is_void_or<
              T, conjunction<TL_EXPECTED_IS_TRIVIALLY_COPY_ASSIGNABLE(T),
                             TL_EXPECTED_IS_TRIVIALLY_COPY_CONSTRUCTIBLE(T),
                             TL_EXPECTED_IS_TRIVIALLY_DESTRUCTIBLE(T)>>::value
              &&TL_EXPECTED_IS_TRIVIALLY_COPY_ASSIGNABLE(E)::value
                  &&TL_EXPECTED_IS_TRIVIALLY_COPY_CONSTRUCTIBLE(E)::value
                      &&TL_EXPECTED_IS_TRIVIALLY_DESTRUCTIBLE(E)::value>
struct expected_copy_assign_base : expected_move_base<T, E> {
  using expected_move_base<T, E>::expected_move_base;
};

template <class T, class E>
struct expected_copy_assign_base<T, E, false> : expected_move_base<T, E> {
  using expected_move_base<T, E>::expected_move_base;

  expected_copy_assign_base() = default;
  expected_copy_assign_base(const expected_copy_assign_base &rhs) = default;

  expected_copy_assign_base(expected_copy_assign_base &&rhs) = default;
  expected_copy_assign_base &operator=(const expected_copy_assign_base &rhs) {
    this->assign(rhs);
    return *this;
  }
  expected_copy_assign_base &
  operator=(expected_copy_assign_base &&rhs) = default;
};

// This class manages conditionally having a trivial move assignment operator
// Unfortunately there's no way to achieve this in GCC < 5 AFAIK, since it
// doesn't implement an analogue to std::is_trivially_move_assignable. We have
// to make do with a non-trivial move assignment operator even if T is trivially
// move assignable
#ifndef TL_EXPECTED_GCC49
template <class T, class E,
          bool =
              is_void_or<T, conjunction<std::is_trivially_destructible<T>,
                                        std::is_trivially_move_constructible<T>,
                                        std::is_trivially_move_assignable<T>>>::
                  value &&std::is_trivially_destructible<E>::value
                      &&std::is_trivially_move_constructible<E>::value
                          &&std::is_trivially_move_assignable<E>::value>
struct expected_move_assign_base : expected_copy_assign_base<T, E> {
  using expected_copy_assign_base<T, E>::expected_copy_assign_base;
};
#else
template <class T, class E, bool = false> struct expected_move_assign_base;
#endif

template <class T, class E>
struct expected_move_assign_base<T, E, false>
    : expected_copy_assign_base<T, E> {
  using expected_copy_assign_base<T, E>::expected_copy_assign_base;

  expected_move_assign_base() = default;
  expected_move_assign_base(const expected_move_assign_base &rhs) = default;

  expected_move_assign_base(expected_move_assign_base &&rhs) = default;

  expected_move_assign_base &
  operator=(const expected_move_assign_base &rhs) = default;

  expected_move_assign_base &
  operator=(expected_move_assign_base &&rhs) noexcept(
      std::is_nothrow_move_constructible<T>::value
          &&std::is_nothrow_move_assignable<T>::value) {
    this->assign(std::move(rhs));
    return *this;
  }
};

// expected_delete_ctor_base will conditionally delete copy and move
// constructors depending on whether T is copy/move constructible
template <class T, class E,
          bool EnableCopy = (is_copy_constructible_or_void<T>::value &&
                             std::is_copy_constructible<E>::value),
          bool EnableMove = (is_move_constructible_or_void<T>::value &&
                             std::is_move_constructible<E>::value)>
struct expected_delete_ctor_base {
  expected_delete_ctor_base() = default;
  expected_delete_ctor_base(const expected_delete_ctor_base &) = default;
  expected_delete_ctor_base(expected_delete_ctor_base &&) noexcept = default;
  expected_delete_ctor_base &
  operator=(const expected_delete_ctor_base &) = default;
  expected_delete_ctor_base &
  operator=(expected_delete_ctor_base &&) noexcept = default;
};

template <class T, class E>
struct expected_delete_ctor_base<T, E, true, false> {
  expected_delete_ctor_base() = default;
  expected_delete_ctor_base(const expected_delete_ctor_base &) = default;
  expected_delete_ctor_base(expected_delete_ctor_base &&) noexcept = delete;
  expected_delete_ctor_base &
  operator=(const expected_delete_ctor_base &) = default;
  expected_delete_ctor_base &
  operator=(expected_delete_ctor_base &&) noexcept = default;
};

template <class T, class E>
struct expected_delete_ctor_base<T, E, false, true> {
  expected_delete_ctor_base() = default;
  expected_delete_ctor_base(const expected_delete_ctor_base &) = delete;
  expected_delete_ctor_base(expected_delete_ctor_base &&) noexcept = default;
  expected_delete_ctor_base &
  operator=(const expected_delete_ctor_base &) = default;
  expected_delete_ctor_base &
  operator=(expected_delete_ctor_base &&) noexcept = default;
};

template <class T, class E>
struct expected_delete_ctor_base<T, E, false, false> {
  expected_delete_ctor_base() = default;
  expected_delete_ctor_base(const expected_delete_ctor_base &) = delete;
  expected_delete_ctor_base(expected_delete_ctor_base &&) noexcept = delete;
  expected_delete_ctor_base &
  operator=(const expected_delete_ctor_base &) = default;
  expected_delete_ctor_base &
  operator=(expected_delete_ctor_base &&) noexcept = default;
};

// expected_delete_assign_base will conditionally delete copy and move
// constructors depending on whether T and E are copy/move constructible +
// assignable
template <class T, class E,
          bool EnableCopy = (is_copy_constructible_or_void<T>::value &&
                             std::is_copy_constructible<E>::value &&
                             is_copy_assignable_or_void<T>::value &&
                             std::is_copy_assignable<E>::value),
          bool EnableMove = (is_move_constructible_or_void<T>::value &&
                             std::is_move_constructible<E>::value &&
                             is_move_assignable_or_void<T>::value &&
                             std::is_move_assignable<E>::value)>
struct expected_delete_assign_base {
  expected_delete_assign_base() = default;
  expected_delete_assign_base(const expected_delete_assign_base &) = default;
  expected_delete_assign_base(expected_delete_assign_base &&) noexcept =
      default;
  expected_delete_assign_base &
  operator=(const expected_delete_assign_base &) = default;
  expected_delete_assign_base &
  operator=(expected_delete_assign_base &&) noexcept = default;
};

template <class T, class E>
struct expected_delete_assign_base<T, E, true, false> {
  expected_delete_assign_base() = default;
  expected_delete_assign_base(const expected_delete_assign_base &) = default;
  expected_delete_assign_base(expected_delete_assign_base &&) noexcept =
      default;
  expected_delete_assign_base &
  operator=(const expected_delete_assign_base &) = default;
  expected_delete_assign_base &
  operator=(expected_delete_assign_base &&) noexcept = delete;
};

template <class T, class E>
struct expected_delete_assign_base<T, E, false, true> {
  expected_delete_assign_base() = default;
  expected_delete_assign_base(const expected_delete_assign_base &) = default;
  expected_delete_assign_base(expected_delete_assign_base &&) noexcept =
      default;
  expected_delete_assign_base &
  operator=(const expected_delete_assign_base &) = delete;
  expected_delete_assign_base &
  operator=(expected_delete_assign_base &&) noexcept = default;
};

template <class T, class E>
struct expected_delete_assign_base<T, E, false, false> {
  expected_delete_assign_base() = default;
  expected_delete_assign_base(const expected_delete_assign_base &) = default;
  expected_delete_assign_base(expected_delete_assign_base &&) noexcept =
      default;
  expected_delete_assign_base &
  operator=(const expected_delete_assign_base &) = delete;
  expected_delete_assign_base &
  operator=(expected_delete_assign_base &&) noexcept = delete;
};

// This is needed to be able to construct the expected_default_ctor_base which
// follows, while still conditionally deleting the default constructor.
struct default_constructor_tag {
  explicit constexpr default_constructor_tag() = default;
};

// expected_default_ctor_base will ensure that expected has a deleted default
// consturctor if T is not default constructible.
// This specialization is for when T is default constructible
template <class T, class E,
          bool Enable =
              std::is_default_constructible<T>::value || std::is_void<T>::value>
struct expected_default_ctor_base {
  constexpr expected_default_ctor_base() noexcept = default;
  constexpr expected_default_ctor_base(
      expected_default_ctor_base const &) noexcept = default;
  constexpr expected_default_ctor_base(expected_default_ctor_base &&) noexcept =
      default;
  expected_default_ctor_base &
  operator=(expected_default_ctor_base const &) noexcept = default;
  expected_default_ctor_base &
  operator=(expected_default_ctor_base &&) noexcept = default;

  constexpr explicit expected_default_ctor_base(default_constructor_tag) {}
};

// This specialization is for when T is not default constructible
template <class T, class E> struct expected_default_ctor_base<T, E, false> {
  constexpr expected_default_ctor_base() noexcept = delete;
  constexpr expected_default_ctor_base(
      expected_default_ctor_base const &) noexcept = default;
  constexpr expected_default_ctor_base(expected_default_ctor_base &&) noexcept =
      default;
  expected_default_ctor_base &
  operator=(expected_default_ctor_base const &) noexcept = default;
  expected_default_ctor_base &
  operator=(expected_default_ctor_base &&) noexcept = default;

  constexpr explicit expected_default_ctor_base(default_constructor_tag) {}
};
} // namespace detail

template <class E> class bad_expected_access : public std::exception {
public:
  explicit bad_expected_access(E e) : m_val(std::move(e)) {}

  virtual const char *what() const noexcept override {
    return "Bad expected access";
  }

  const E &error() const & { return m_val; }
  E &error() & { return m_val; }
  const E &&error() const && { return std::move(m_val); }
  E &&error() && { return std::move(m_val); }

private:
  E m_val;
};

/// An `expected<T, E>` object is an object that contains the storage for
/// another object and manages the lifetime of this contained object `T`.
/// Alternatively it could contain the storage for another unexpected object
/// `E`. The contained object may not be initialized after the expected object
/// has been initialized, and may not be destroyed before the expected object
/// has been destroyed. The initialization state of the contained object is
/// tracked by the expected object.
template <class T, class E>
class expected : private detail::expected_move_assign_base<T, E>,
                 private detail::expected_delete_ctor_base<T, E>,
                 private detail::expected_delete_assign_base<T, E>,
                 private detail::expected_default_ctor_base<T, E> {
  static_assert(!std::is_reference<T>::value, "T must not be a reference");
  static_assert(!std::is_same<T, std::remove_cv<in_place_t>::type>::value,
                "T must not be in_place_t");
  static_assert(!std::is_same<T, std::remove_cv<unexpect_t>::type>::value,
                "T must not be unexpect_t");
  static_assert(
      !std::is_same<T, typename std::remove_cv<unexpected<E>>::type>::value,
      "T must not be unexpected<E>");
  static_assert(!std::is_reference<E>::value, "E must not be a reference");

  T *valptr() { return std::addressof(this->m_val); }
  const T *valptr() const { return std::addressof(this->m_val); }
  unexpected<E> *errptr() { return std::addressof(this->m_unexpect); }
  const unexpected<E> *errptr() const {
    return std::addressof(this->m_unexpect);
  }

  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  TL_EXPECTED_11_CONSTEXPR U &val() {
    return this->m_val;
  }
  TL_EXPECTED_11_CONSTEXPR unexpected<E> &err() { return this->m_unexpect; }

  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  constexpr const U &val() const {
    return this->m_val;
  }
  constexpr const unexpected<E> &err() const { return this->m_unexpect; }

  using impl_base = detail::expected_move_assign_base<T, E>;
  using ctor_base = detail::expected_default_ctor_base<T, E>;

public:
  typedef T value_type;
  typedef E error_type;
  typedef unexpected<E> unexpected_type;

#if defined(TL_EXPECTED_CXX14) && !defined(TL_EXPECTED_GCC49) &&               \
    !defined(TL_EXPECTED_GCC54) && !defined(TL_EXPECTED_GCC55)
  template <class F> TL_EXPECTED_11_CONSTEXPR auto and_then(F &&f) & {
    return and_then_impl(*this, std::forward<F>(f));
  }
  template <class F> TL_EXPECTED_11_CONSTEXPR auto and_then(F &&f) && {
    return and_then_impl(std::move(*this), std::forward<F>(f));
  }
  template <class F> constexpr auto and_then(F &&f) const & {
    return and_then_impl(*this, std::forward<F>(f));
  }

#ifndef TL_EXPECTED_NO_CONSTRR
  template <class F> constexpr auto and_then(F &&f) const && {
    return and_then_impl(std::move(*this), std::forward<F>(f));
  }
#endif

#else
  template <class F>
  TL_EXPECTED_11_CONSTEXPR auto
  and_then(F &&f) & -> decltype(and_then_impl(std::declval<expected &>(),
                                              std::forward<F>(f))) {
    return and_then_impl(*this, std::forward<F>(f));
  }
  template <class F>
  TL_EXPECTED_11_CONSTEXPR auto
  and_then(F &&f) && -> decltype(and_then_impl(std::declval<expected &&>(),
                                               std::forward<F>(f))) {
    return and_then_impl(std::move(*this), std::forward<F>(f));
  }
  template <class F>
  constexpr auto and_then(F &&f) const & -> decltype(and_then_impl(
      std::declval<expected const &>(), std::forward<F>(f))) {
    return and_then_impl(*this, std::forward<F>(f));
  }

#ifndef TL_EXPECTED_NO_CONSTRR
  template <class F>
  constexpr auto and_then(F &&f) const && -> decltype(and_then_impl(
      std::declval<expected const &&>(), std::forward<F>(f))) {
    return and_then_impl(std::move(*this), std::forward<F>(f));
  }
#endif
#endif

#if defined(TL_EXPECTED_CXX14) && !defined(TL_EXPECTED_GCC49) &&               \
    !defined(TL_EXPECTED_GCC54) && !defined(TL_EXPECTED_GCC55)
  template <class F> TL_EXPECTED_11_CONSTEXPR auto map(F &&f) & {
    return expected_map_impl(*this, std::forward<F>(f));
  }
  template <class F> TL_EXPECTED_11_CONSTEXPR auto map(F &&f) && {
    return expected_map_impl(std::move(*this), std::forward<F>(f));
  }
  template <class F> constexpr auto map(F &&f) const & {
    return expected_map_impl(*this, std::forward<F>(f));
  }
  template <class F> constexpr auto map(F &&f) const && {
    return expected_map_impl(std::move(*this), std::forward<F>(f));
  }
#else
  template <class F>
  TL_EXPECTED_11_CONSTEXPR decltype(expected_map_impl(
      std::declval<expected &>(), std::declval<F &&>()))
  map(F &&f) & {
    return expected_map_impl(*this, std::forward<F>(f));
  }
  template <class F>
  TL_EXPECTED_11_CONSTEXPR decltype(expected_map_impl(std::declval<expected>(),
                                                      std::declval<F &&>()))
  map(F &&f) && {
    return expected_map_impl(std::move(*this), std::forward<F>(f));
  }
  template <class F>
  constexpr decltype(expected_map_impl(std::declval<const expected &>(),
                                       std::declval<F &&>()))
  map(F &&f) const & {
    return expected_map_impl(*this, std::forward<F>(f));
  }

#ifndef TL_EXPECTED_NO_CONSTRR
  template <class F>
  constexpr decltype(expected_map_impl(std::declval<const expected &&>(),
                                       std::declval<F &&>()))
  map(F &&f) const && {
    return expected_map_impl(std::move(*this), std::forward<F>(f));
  }
#endif
#endif

#if defined(TL_EXPECTED_CXX14) && !defined(TL_EXPECTED_GCC49) &&               \
    !defined(TL_EXPECTED_GCC54) && !defined(TL_EXPECTED_GCC55)
  template <class F> TL_EXPECTED_11_CONSTEXPR auto transform(F &&f) & {
    return expected_map_impl(*this, std::forward<F>(f));
  }
  template <class F> TL_EXPECTED_11_CONSTEXPR auto transform(F &&f) && {
    return expected_map_impl(std::move(*this), std::forward<F>(f));
  }
  template <class F> constexpr auto transform(F &&f) const & {
    return expected_map_impl(*this, std::forward<F>(f));
  }
  template <class F> constexpr auto transform(F &&f) const && {
    return expected_map_impl(std::move(*this), std::forward<F>(f));
  }
#else
  template <class F>
  TL_EXPECTED_11_CONSTEXPR decltype(expected_map_impl(
      std::declval<expected &>(), std::declval<F &&>()))
  transform(F &&f) & {
    return expected_map_impl(*this, std::forward<F>(f));
  }
  template <class F>
  TL_EXPECTED_11_CONSTEXPR decltype(expected_map_impl(std::declval<expected>(),
                                                      std::declval<F &&>()))
  transform(F &&f) && {
    return expected_map_impl(std::move(*this), std::forward<F>(f));
  }
  template <class F>
  constexpr decltype(expected_map_impl(std::declval<const expected &>(),
                                       std::declval<F &&>()))
  transform(F &&f) const & {
    return expected_map_impl(*this, std::forward<F>(f));
  }

#ifndef TL_EXPECTED_NO_CONSTRR
  template <class F>
  constexpr decltype(expected_map_impl(std::declval<const expected &&>(),
                                       std::declval<F &&>()))
  transform(F &&f) const && {
    return expected_map_impl(std::move(*this), std::forward<F>(f));
  }
#endif
#endif

#if defined(TL_EXPECTED_CXX14) && !defined(TL_EXPECTED_GCC49) &&               \
    !defined(TL_EXPECTED_GCC54) && !defined(TL_EXPECTED_GCC55)
  template <class F> TL_EXPECTED_11_CONSTEXPR auto map_error(F &&f) & {
    return map_error_impl(*this, std::forward<F>(f));
  }
  template <class F> TL_EXPECTED_11_CONSTEXPR auto map_error(F &&f) && {
    return map_error_impl(std::move(*this), std::forward<F>(f));
  }
  template <class F> constexpr auto map_error(F &&f) const & {
    return map_error_impl(*this, std::forward<F>(f));
  }
  template <class F> constexpr auto map_error(F &&f) const && {
    return map_error_impl(std::move(*this), std::forward<F>(f));
  }
#else
  template <class F>
  TL_EXPECTED_11_CONSTEXPR decltype(map_error_impl(std::declval<expected &>(),
                                                   std::declval<F &&>()))
  map_error(F &&f) & {
    return map_error_impl(*this, std::forward<F>(f));
  }
  template <class F>
  TL_EXPECTED_11_CONSTEXPR decltype(map_error_impl(std::declval<expected &&>(),
                                                   std::declval<F &&>()))
  map_error(F &&f) && {
    return map_error_impl(std::move(*this), std::forward<F>(f));
  }
  template <class F>
  constexpr decltype(map_error_impl(std::declval<const expected &>(),
                                    std::declval<F &&>()))
  map_error(F &&f) const & {
    return map_error_impl(*this, std::forward<F>(f));
  }

#ifndef TL_EXPECTED_NO_CONSTRR
  template <class F>
  constexpr decltype(map_error_impl(std::declval<const expected &&>(),
                                    std::declval<F &&>()))
  map_error(F &&f) const && {
    return map_error_impl(std::move(*this), std::forward<F>(f));
  }
#endif
#endif
  template <class F> expected TL_EXPECTED_11_CONSTEXPR or_else(F &&f) & {
    return or_else_impl(*this, std::forward<F>(f));
  }

  template <class F> expected TL_EXPECTED_11_CONSTEXPR or_else(F &&f) && {
    return or_else_impl(std::move(*this), std::forward<F>(f));
  }

  template <class F> expected constexpr or_else(F &&f) const & {
    return or_else_impl(*this, std::forward<F>(f));
  }

#ifndef TL_EXPECTED_NO_CONSTRR
  template <class F> expected constexpr or_else(F &&f) const && {
    return or_else_impl(std::move(*this), std::forward<F>(f));
  }
#endif
  constexpr expected() = default;
  constexpr expected(const expected &rhs) = default;
  constexpr expected(expected &&rhs) = default;
  expected &operator=(const expected &rhs) = default;
  expected &operator=(expected &&rhs) = default;

  template <class... Args,
            detail::enable_if_t<std::is_constructible<T, Args &&...>::value> * =
                nullptr>
  constexpr expected(in_place_t, Args &&...args)
      : impl_base(in_place, std::forward<Args>(args)...),
        ctor_base(detail::default_constructor_tag{}) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                T, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr expected(in_place_t, std::initializer_list<U> il, Args &&...args)
      : impl_base(in_place, il, std::forward<Args>(args)...),
        ctor_base(detail::default_constructor_tag{}) {}

  template <class G = E,
            detail::enable_if_t<std::is_constructible<E, const G &>::value> * =
                nullptr,
            detail::enable_if_t<!std::is_convertible<const G &, E>::value> * =
                nullptr>
  explicit constexpr expected(const unexpected<G> &e)
      : impl_base(unexpect, e.value()),
        ctor_base(detail::default_constructor_tag{}) {}

  template <
      class G = E,
      detail::enable_if_t<std::is_constructible<E, const G &>::value> * =
          nullptr,
      detail::enable_if_t<std::is_convertible<const G &, E>::value> * = nullptr>
  constexpr expected(unexpected<G> const &e)
      : impl_base(unexpect, e.value()),
        ctor_base(detail::default_constructor_tag{}) {}

  template <
      class G = E,
      detail::enable_if_t<std::is_constructible<E, G &&>::value> * = nullptr,
      detail::enable_if_t<!std::is_convertible<G &&, E>::value> * = nullptr>
  explicit constexpr expected(unexpected<G> &&e) noexcept(
      std::is_nothrow_constructible<E, G &&>::value)
      : impl_base(unexpect, std::move(e.value())),
        ctor_base(detail::default_constructor_tag{}) {}

  template <
      class G = E,
      detail::enable_if_t<std::is_constructible<E, G &&>::value> * = nullptr,
      detail::enable_if_t<std::is_convertible<G &&, E>::value> * = nullptr>
  constexpr expected(unexpected<G> &&e) noexcept(
      std::is_nothrow_constructible<E, G &&>::value)
      : impl_base(unexpect, std::move(e.value())),
        ctor_base(detail::default_constructor_tag{}) {}

  template <class... Args,
            detail::enable_if_t<std::is_constructible<E, Args &&...>::value> * =
                nullptr>
  constexpr explicit expected(unexpect_t, Args &&...args)
      : impl_base(unexpect, std::forward<Args>(args)...),
        ctor_base(detail::default_constructor_tag{}) {}

  template <class U, class... Args,
            detail::enable_if_t<std::is_constructible<
                E, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  constexpr explicit expected(unexpect_t, std::initializer_list<U> il,
                              Args &&...args)
      : impl_base(unexpect, il, std::forward<Args>(args)...),
        ctor_base(detail::default_constructor_tag{}) {}

  template <class U, class G,
            detail::enable_if_t<!(std::is_convertible<U const &, T>::value &&
                                  std::is_convertible<G const &, E>::value)> * =
                nullptr,
            detail::expected_enable_from_other<T, E, U, G, const U &, const G &>
                * = nullptr>
  explicit TL_EXPECTED_11_CONSTEXPR expected(const expected<U, G> &rhs)
      : ctor_base(detail::default_constructor_tag{}) {
    if (rhs.has_value()) {
      this->construct(*rhs);
    } else {
      this->construct_error(rhs.error());
    }
  }

  template <class U, class G,
            detail::enable_if_t<(std::is_convertible<U const &, T>::value &&
                                 std::is_convertible<G const &, E>::value)> * =
                nullptr,
            detail::expected_enable_from_other<T, E, U, G, const U &, const G &>
                * = nullptr>
  TL_EXPECTED_11_CONSTEXPR expected(const expected<U, G> &rhs)
      : ctor_base(detail::default_constructor_tag{}) {
    if (rhs.has_value()) {
      this->construct(*rhs);
    } else {
      this->construct_error(rhs.error());
    }
  }

  template <
      class U, class G,
      detail::enable_if_t<!(std::is_convertible<U &&, T>::value &&
                            std::is_convertible<G &&, E>::value)> * = nullptr,
      detail::expected_enable_from_other<T, E, U, G, U &&, G &&> * = nullptr>
  explicit TL_EXPECTED_11_CONSTEXPR expected(expected<U, G> &&rhs)
      : ctor_base(detail::default_constructor_tag{}) {
    if (rhs.has_value()) {
      this->construct(std::move(*rhs));
    } else {
      this->construct_error(std::move(rhs.error()));
    }
  }

  template <
      class U, class G,
      detail::enable_if_t<(std::is_convertible<U &&, T>::value &&
                           std::is_convertible<G &&, E>::value)> * = nullptr,
      detail::expected_enable_from_other<T, E, U, G, U &&, G &&> * = nullptr>
  TL_EXPECTED_11_CONSTEXPR expected(expected<U, G> &&rhs)
      : ctor_base(detail::default_constructor_tag{}) {
    if (rhs.has_value()) {
      this->construct(std::move(*rhs));
    } else {
      this->construct_error(std::move(rhs.error()));
    }
  }

  template <
      class U = T,
      detail::enable_if_t<!std::is_convertible<U &&, T>::value> * = nullptr,
      detail::expected_enable_forward_value<T, E, U> * = nullptr>
  explicit TL_EXPECTED_MSVC2015_CONSTEXPR expected(U &&v)
      : expected(in_place, std::forward<U>(v)) {}

  template <
      class U = T,
      detail::enable_if_t<std::is_convertible<U &&, T>::value> * = nullptr,
      detail::expected_enable_forward_value<T, E, U> * = nullptr>
  TL_EXPECTED_MSVC2015_CONSTEXPR expected(U &&v)
      : expected(in_place, std::forward<U>(v)) {}

  template <
      class U = T, class G = T,
      detail::enable_if_t<std::is_nothrow_constructible<T, U &&>::value> * =
          nullptr,
      detail::enable_if_t<!std::is_void<G>::value> * = nullptr,
      detail::enable_if_t<
          (!std::is_same<expected<T, E>, detail::decay_t<U>>::value &&
           !detail::conjunction<std::is_scalar<T>,
                                std::is_same<T, detail::decay_t<U>>>::value &&
           std::is_constructible<T, U>::value &&
           std::is_assignable<G &, U>::value &&
           std::is_nothrow_move_constructible<E>::value)> * = nullptr>
  expected &operator=(U &&v) {
    if (has_value()) {
      val() = std::forward<U>(v);
    } else {
      err().~unexpected<E>();
      ::new (valptr()) T(std::forward<U>(v));
      this->m_has_val = true;
    }

    return *this;
  }

  template <
      class U = T, class G = T,
      detail::enable_if_t<!std::is_nothrow_constructible<T, U &&>::value> * =
          nullptr,
      detail::enable_if_t<!std::is_void<U>::value> * = nullptr,
      detail::enable_if_t<
          (!std::is_same<expected<T, E>, detail::decay_t<U>>::value &&
           !detail::conjunction<std::is_scalar<T>,
                                std::is_same<T, detail::decay_t<U>>>::value &&
           std::is_constructible<T, U>::value &&
           std::is_assignable<G &, U>::value &&
           std::is_nothrow_move_constructible<E>::value)> * = nullptr>
  expected &operator=(U &&v) {
    if (has_value()) {
      val() = std::forward<U>(v);
    } else {
      auto tmp = std::move(err());
      err().~unexpected<E>();

#ifdef TL_EXPECTED_EXCEPTIONS_ENABLED
      try {
        ::new (valptr()) T(std::forward<U>(v));
        this->m_has_val = true;
      } catch (...) {
        err() = std::move(tmp);
        throw;
      }
#else
      ::new (valptr()) T(std::forward<U>(v));
      this->m_has_val = true;
#endif
    }

    return *this;
  }

  template <class G = E,
            detail::enable_if_t<std::is_nothrow_copy_constructible<G>::value &&
                                std::is_assignable<G &, G>::value> * = nullptr>
  expected &operator=(const unexpected<G> &rhs) {
    if (!has_value()) {
      err() = rhs;
    } else {
      this->destroy_val();
      ::new (errptr()) unexpected<E>(rhs);
      this->m_has_val = false;
    }

    return *this;
  }

  template <class G = E,
            detail::enable_if_t<std::is_nothrow_move_constructible<G>::value &&
                                std::is_move_assignable<G>::value> * = nullptr>
  expected &operator=(unexpected<G> &&rhs) noexcept {
    if (!has_value()) {
      err() = std::move(rhs);
    } else {
      this->destroy_val();
      ::new (errptr()) unexpected<E>(std::move(rhs));
      this->m_has_val = false;
    }

    return *this;
  }

  template <class... Args, detail::enable_if_t<std::is_nothrow_constructible<
                               T, Args &&...>::value> * = nullptr>
  void emplace(Args &&...args) {
    if (has_value()) {
      val().~T();
    } else {
      err().~unexpected<E>();
      this->m_has_val = true;
    }
    ::new (valptr()) T(std::forward<Args>(args)...);
  }

  template <class... Args, detail::enable_if_t<!std::is_nothrow_constructible<
                               T, Args &&...>::value> * = nullptr>
  void emplace(Args &&...args) {
    if (has_value()) {
      val().~T();
      ::new (valptr()) T(std::forward<Args>(args)...);
    } else {
      auto tmp = std::move(err());
      err().~unexpected<E>();

#ifdef TL_EXPECTED_EXCEPTIONS_ENABLED
      try {
        ::new (valptr()) T(std::forward<Args>(args)...);
        this->m_has_val = true;
      } catch (...) {
        err() = std::move(tmp);
        throw;
      }
#else
      ::new (valptr()) T(std::forward<Args>(args)...);
      this->m_has_val = true;
#endif
    }
  }

  template <class U, class... Args,
            detail::enable_if_t<std::is_nothrow_constructible<
                T, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  void emplace(std::initializer_list<U> il, Args &&...args) {
    if (has_value()) {
      T t(il, std::forward<Args>(args)...);
      val() = std::move(t);
    } else {
      err().~unexpected<E>();
      ::new (valptr()) T(il, std::forward<Args>(args)...);
      this->m_has_val = true;
    }
  }

  template <class U, class... Args,
            detail::enable_if_t<!std::is_nothrow_constructible<
                T, std::initializer_list<U> &, Args &&...>::value> * = nullptr>
  void emplace(std::initializer_list<U> il, Args &&...args) {
    if (has_value()) {
      T t(il, std::forward<Args>(args)...);
      val() = std::move(t);
    } else {
      auto tmp = std::move(err());
      err().~unexpected<E>();

#ifdef TL_EXPECTED_EXCEPTIONS_ENABLED
      try {
        ::new (valptr()) T(il, std::forward<Args>(args)...);
        this->m_has_val = true;
      } catch (...) {
        err() = std::move(tmp);
        throw;
      }
#else
      ::new (valptr()) T(il, std::forward<Args>(args)...);
      this->m_has_val = true;
#endif
    }
  }

private:
  using t_is_void = std::true_type;
  using t_is_not_void = std::false_type;
  using t_is_nothrow_move_constructible = std::true_type;
  using move_constructing_t_can_throw = std::false_type;
  using e_is_nothrow_move_constructible = std::true_type;
  using move_constructing_e_can_throw = std::false_type;

  void swap_where_both_have_value(expected & /*rhs*/, t_is_void) noexcept {
    // swapping void is a no-op
  }

  void swap_where_both_have_value(expected &rhs, t_is_not_void) {
    using std::swap;
    swap(val(), rhs.val());
  }

  void swap_where_only_one_has_value(expected &rhs, t_is_void) noexcept(
      std::is_nothrow_move_constructible<E>::value) {
    ::new (errptr()) unexpected_type(std::move(rhs.err()));
    rhs.err().~unexpected_type();
    std::swap(this->m_has_val, rhs.m_has_val);
  }

  void swap_where_only_one_has_value(expected &rhs, t_is_not_void) {
    swap_where_only_one_has_value_and_t_is_not_void(
        rhs, typename std::is_nothrow_move_constructible<T>::type{},
        typename std::is_nothrow_move_constructible<E>::type{});
  }

  void swap_where_only_one_has_value_and_t_is_not_void(
      expected &rhs, t_is_nothrow_move_constructible,
      e_is_nothrow_move_constructible) noexcept {
    auto temp = std::move(val());
    val().~T();
    ::new (errptr()) unexpected_type(std::move(rhs.err()));
    rhs.err().~unexpected_type();
    ::new (rhs.valptr()) T(std::move(temp));
    std::swap(this->m_has_val, rhs.m_has_val);
  }

  void swap_where_only_one_has_value_and_t_is_not_void(
      expected &rhs, t_is_nothrow_move_constructible,
      move_constructing_e_can_throw) {
    auto temp = std::move(val());
    val().~T();
#ifdef TL_EXPECTED_EXCEPTIONS_ENABLED
    try {
      ::new (errptr()) unexpected_type(std::move(rhs.err()));
      rhs.err().~unexpected_type();
      ::new (rhs.valptr()) T(std::move(temp));
      std::swap(this->m_has_val, rhs.m_has_val);
    } catch (...) {
      val() = std::move(temp);
      throw;
    }
#else
    ::new (errptr()) unexpected_type(std::move(rhs.err()));
    rhs.err().~unexpected_type();
    ::new (rhs.valptr()) T(std::move(temp));
    std::swap(this->m_has_val, rhs.m_has_val);
#endif
  }

  void swap_where_only_one_has_value_and_t_is_not_void(
      expected &rhs, move_constructing_t_can_throw,
      e_is_nothrow_move_constructible) {
    auto temp = std::move(rhs.err());
    rhs.err().~unexpected_type();
#ifdef TL_EXPECTED_EXCEPTIONS_ENABLED
    try {
      ::new (rhs.valptr()) T(std::move(val()));
      val().~T();
      ::new (errptr()) unexpected_type(std::move(temp));
      std::swap(this->m_has_val, rhs.m_has_val);
    } catch (...) {
      rhs.err() = std::move(temp);
      throw;
    }
#else
    ::new (rhs.valptr()) T(std::move(val()));
    val().~T();
    ::new (errptr()) unexpected_type(std::move(temp));
    std::swap(this->m_has_val, rhs.m_has_val);
#endif
  }

public:
  template <class OT = T, class OE = E>
  detail::enable_if_t<detail::is_swappable<OT>::value &&
                      detail::is_swappable<OE>::value &&
                      (std::is_nothrow_move_constructible<OT>::value ||
                       std::is_nothrow_move_constructible<OE>::value)>
  swap(expected &rhs) noexcept(
      std::is_nothrow_move_constructible<T>::value
          &&detail::is_nothrow_swappable<T>::value
              &&std::is_nothrow_move_constructible<E>::value
                  &&detail::is_nothrow_swappable<E>::value) {
    if (has_value() && rhs.has_value()) {
      swap_where_both_have_value(rhs, typename std::is_void<T>::type{});
    } else if (!has_value() && rhs.has_value()) {
      rhs.swap(*this);
    } else if (has_value()) {
      swap_where_only_one_has_value(rhs, typename std::is_void<T>::type{});
    } else {
      using std::swap;
      swap(err(), rhs.err());
    }
  }

  constexpr const T *operator->() const { return valptr(); }
  TL_EXPECTED_11_CONSTEXPR T *operator->() { return valptr(); }

  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  constexpr const U &operator*() const & {
    return val();
  }
  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  TL_EXPECTED_11_CONSTEXPR U &operator*() & {
    return val();
  }
  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  constexpr const U &&operator*() const && {
    return std::move(val());
  }
  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  TL_EXPECTED_11_CONSTEXPR U &&operator*() && {
    return std::move(val());
  }

  constexpr bool has_value() const noexcept { return this->m_has_val; }
  constexpr explicit operator bool() const noexcept { return this->m_has_val; }

  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  TL_EXPECTED_11_CONSTEXPR const U &value() const & {
    if (!has_value())
      detail::throw_exception(bad_expected_access<E>(err().value()));
    return val();
  }
  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  TL_EXPECTED_11_CONSTEXPR U &value() & {
    if (!has_value())
      detail::throw_exception(bad_expected_access<E>(err().value()));
    return val();
  }
  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  TL_EXPECTED_11_CONSTEXPR const U &&value() const && {
    if (!has_value())
      detail::throw_exception(bad_expected_access<E>(std::move(err()).value()));
    return std::move(val());
  }
  template <class U = T,
            detail::enable_if_t<!std::is_void<U>::value> * = nullptr>
  TL_EXPECTED_11_CONSTEXPR U &&value() && {
    if (!has_value())
      detail::throw_exception(bad_expected_access<E>(std::move(err()).value()));
    return std::move(val());
  }

  constexpr const E &error() const & { return err().value(); }
  TL_EXPECTED_11_CONSTEXPR E &error() & { return err().value(); }
  constexpr const E &&error() const && { return std::move(err().value()); }
  TL_EXPECTED_11_CONSTEXPR E &&error() && { return std::move(err().value()); }

  template <class U> constexpr T value_or(U &&v) const & {
    static_assert(std::is_copy_constructible<T>::value &&
                      std::is_convertible<U &&, T>::value,
                  "T must be copy-constructible and convertible to from U&&");
    return bool(*this) ? **this : static_cast<T>(std::forward<U>(v));
  }
  template <class U> TL_EXPECTED_11_CONSTEXPR T value_or(U &&v) && {
    static_assert(std::is_move_constructible<T>::value &&
                      std::is_convertible<U &&, T>::value,
                  "T must be move-constructible and convertible to from U&&");
    return bool(*this) ? std::move(**this) : static_cast<T>(std::forward<U>(v));
  }
};

namespace detail {
template <class Exp> using exp_t = typename detail::decay_t<Exp>::value_type;
template <class Exp> using err_t = typename detail::decay_t<Exp>::error_type;
template <class Exp, class Ret> using ret_t = expected<Ret, err_t<Exp>>;

#ifdef TL_EXPECTED_CXX14
template <class Exp, class F,
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              *std::declval<Exp>()))>
constexpr auto and_then_impl(Exp &&exp, F &&f) {
  static_assert(detail::is_expected<Ret>::value, "F must return an expected");

  return exp.has_value()
             ? detail::invoke(std::forward<F>(f), *std::forward<Exp>(exp))
             : Ret(unexpect, std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>()))>
constexpr auto and_then_impl(Exp &&exp, F &&f) {
  static_assert(detail::is_expected<Ret>::value, "F must return an expected");

  return exp.has_value() ? detail::invoke(std::forward<F>(f))
                         : Ret(unexpect, std::forward<Exp>(exp).error());
}
#else
template <class> struct TC;
template <class Exp, class F,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              *std::declval<Exp>())),
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr>
auto and_then_impl(Exp &&exp, F &&f) -> Ret {
  static_assert(detail::is_expected<Ret>::value, "F must return an expected");

  return exp.has_value()
             ? detail::invoke(std::forward<F>(f), *std::forward<Exp>(exp))
             : Ret(unexpect, std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          class Ret = decltype(detail::invoke(std::declval<F>())),
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr>
constexpr auto and_then_impl(Exp &&exp, F &&f) -> Ret {
  static_assert(detail::is_expected<Ret>::value, "F must return an expected");

  return exp.has_value() ? detail::invoke(std::forward<F>(f))
                         : Ret(unexpect, std::forward<Exp>(exp).error());
}
#endif

#ifdef TL_EXPECTED_CXX14
template <class Exp, class F,
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              *std::declval<Exp>())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>
constexpr auto expected_map_impl(Exp &&exp, F &&f) {
  using result = ret_t<Exp, detail::decay_t<Ret>>;
  return exp.has_value() ? result(detail::invoke(std::forward<F>(f),
                                                 *std::forward<Exp>(exp)))
                         : result(unexpect, std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              *std::declval<Exp>())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>
auto expected_map_impl(Exp &&exp, F &&f) {
  using result = expected<void, err_t<Exp>>;
  if (exp.has_value()) {
    detail::invoke(std::forward<F>(f), *std::forward<Exp>(exp));
    return result();
  }

  return result(unexpect, std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>
constexpr auto expected_map_impl(Exp &&exp, F &&f) {
  using result = ret_t<Exp, detail::decay_t<Ret>>;
  return exp.has_value() ? result(detail::invoke(std::forward<F>(f)))
                         : result(unexpect, std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>
auto expected_map_impl(Exp &&exp, F &&f) {
  using result = expected<void, err_t<Exp>>;
  if (exp.has_value()) {
    detail::invoke(std::forward<F>(f));
    return result();
  }

  return result(unexpect, std::forward<Exp>(exp).error());
}
#else
template <class Exp, class F,
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              *std::declval<Exp>())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>

constexpr auto expected_map_impl(Exp &&exp, F &&f)
    -> ret_t<Exp, detail::decay_t<Ret>> {
  using result = ret_t<Exp, detail::decay_t<Ret>>;

  return exp.has_value() ? result(detail::invoke(std::forward<F>(f),
                                                 *std::forward<Exp>(exp)))
                         : result(unexpect, std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              *std::declval<Exp>())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>

auto expected_map_impl(Exp &&exp, F &&f) -> expected<void, err_t<Exp>> {
  if (exp.has_value()) {
    detail::invoke(std::forward<F>(f), *std::forward<Exp>(exp));
    return {};
  }

  return unexpected<err_t<Exp>>(std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>

constexpr auto expected_map_impl(Exp &&exp, F &&f)
    -> ret_t<Exp, detail::decay_t<Ret>> {
  using result = ret_t<Exp, detail::decay_t<Ret>>;

  return exp.has_value() ? result(detail::invoke(std::forward<F>(f)))
                         : result(unexpect, std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>

auto expected_map_impl(Exp &&exp, F &&f) -> expected<void, err_t<Exp>> {
  if (exp.has_value()) {
    detail::invoke(std::forward<F>(f));
    return {};
  }

  return unexpected<err_t<Exp>>(std::forward<Exp>(exp).error());
}
#endif

#if defined(TL_EXPECTED_CXX14) && !defined(TL_EXPECTED_GCC49) &&               \
    !defined(TL_EXPECTED_GCC54) && !defined(TL_EXPECTED_GCC55)
template <class Exp, class F,
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>
constexpr auto map_error_impl(Exp &&exp, F &&f) {
  using result = expected<exp_t<Exp>, detail::decay_t<Ret>>;
  return exp.has_value()
             ? result(*std::forward<Exp>(exp))
             : result(unexpect, detail::invoke(std::forward<F>(f),
                                               std::forward<Exp>(exp).error()));
}
template <class Exp, class F,
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>
auto map_error_impl(Exp &&exp, F &&f) {
  using result = expected<exp_t<Exp>, monostate>;
  if (exp.has_value()) {
    return result(*std::forward<Exp>(exp));
  }

  detail::invoke(std::forward<F>(f), std::forward<Exp>(exp).error());
  return result(unexpect, monostate{});
}
template <class Exp, class F,
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>
constexpr auto map_error_impl(Exp &&exp, F &&f) {
  using result = expected<exp_t<Exp>, detail::decay_t<Ret>>;
  return exp.has_value()
             ? result()
             : result(unexpect, detail::invoke(std::forward<F>(f),
                                               std::forward<Exp>(exp).error()));
}
template <class Exp, class F,
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>
auto map_error_impl(Exp &&exp, F &&f) {
  using result = expected<exp_t<Exp>, monostate>;
  if (exp.has_value()) {
    return result();
  }

  detail::invoke(std::forward<F>(f), std::forward<Exp>(exp).error());
  return result(unexpect, monostate{});
}
#else
template <class Exp, class F,
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>
constexpr auto map_error_impl(Exp &&exp, F &&f)
    -> expected<exp_t<Exp>, detail::decay_t<Ret>> {
  using result = expected<exp_t<Exp>, detail::decay_t<Ret>>;

  return exp.has_value()
             ? result(*std::forward<Exp>(exp))
             : result(unexpect, detail::invoke(std::forward<F>(f),
                                               std::forward<Exp>(exp).error()));
}

template <class Exp, class F,
          detail::enable_if_t<!std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>
auto map_error_impl(Exp &&exp, F &&f) -> expected<exp_t<Exp>, monostate> {
  using result = expected<exp_t<Exp>, monostate>;
  if (exp.has_value()) {
    return result(*std::forward<Exp>(exp));
  }

  detail::invoke(std::forward<F>(f), std::forward<Exp>(exp).error());
  return result(unexpect, monostate{});
}

template <class Exp, class F,
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>
constexpr auto map_error_impl(Exp &&exp, F &&f)
    -> expected<exp_t<Exp>, detail::decay_t<Ret>> {
  using result = expected<exp_t<Exp>, detail::decay_t<Ret>>;

  return exp.has_value()
             ? result()
             : result(unexpect, detail::invoke(std::forward<F>(f),
                                               std::forward<Exp>(exp).error()));
}

template <class Exp, class F,
          detail::enable_if_t<std::is_void<exp_t<Exp>>::value> * = nullptr,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>
auto map_error_impl(Exp &&exp, F &&f) -> expected<exp_t<Exp>, monostate> {
  using result = expected<exp_t<Exp>, monostate>;
  if (exp.has_value()) {
    return result();
  }

  detail::invoke(std::forward<F>(f), std::forward<Exp>(exp).error());
  return result(unexpect, monostate{});
}
#endif

#ifdef TL_EXPECTED_CXX14
template <class Exp, class F,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>
constexpr auto or_else_impl(Exp &&exp, F &&f) {
  static_assert(detail::is_expected<Ret>::value, "F must return an expected");
  return exp.has_value() ? std::forward<Exp>(exp)
                         : detail::invoke(std::forward<F>(f),
                                          std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>
detail::decay_t<Exp> or_else_impl(Exp &&exp, F &&f) {
  return exp.has_value() ? std::forward<Exp>(exp)
                         : (detail::invoke(std::forward<F>(f),
                                           std::forward<Exp>(exp).error()),
                            std::forward<Exp>(exp));
}
#else
template <class Exp, class F,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<!std::is_void<Ret>::value> * = nullptr>
auto or_else_impl(Exp &&exp, F &&f) -> Ret {
  static_assert(detail::is_expected<Ret>::value, "F must return an expected");
  return exp.has_value() ? std::forward<Exp>(exp)
                         : detail::invoke(std::forward<F>(f),
                                          std::forward<Exp>(exp).error());
}

template <class Exp, class F,
          class Ret = decltype(detail::invoke(std::declval<F>(),
                                              std::declval<Exp>().error())),
          detail::enable_if_t<std::is_void<Ret>::value> * = nullptr>
detail::decay_t<Exp> or_else_impl(Exp &&exp, F &&f) {
  return exp.has_value() ? std::forward<Exp>(exp)
                         : (detail::invoke(std::forward<F>(f),
                                           std::forward<Exp>(exp).error()),
                            std::forward<Exp>(exp));
}
#endif
} // namespace detail

template <class T, class E, class U, class F>
constexpr bool operator==(const expected<T, E> &lhs,
                          const expected<U, F> &rhs) {
  return (lhs.has_value() != rhs.has_value())
             ? false
             : (!lhs.has_value() ? lhs.error() == rhs.error() : *lhs == *rhs);
}
template <class T, class E, class U, class F>
constexpr bool operator!=(const expected<T, E> &lhs,
                          const expected<U, F> &rhs) {
  return (lhs.has_value() != rhs.has_value())
             ? true
             : (!lhs.has_value() ? lhs.error() != rhs.error() : *lhs != *rhs);
}
template <class E, class F>
constexpr bool operator==(const expected<void, E> &lhs,
                          const expected<void, F> &rhs) {
  return (lhs.has_value() != rhs.has_value())
             ? false
             : (!lhs.has_value() ? lhs.error() == rhs.error() : true);
}
template <class E, class F>
constexpr bool operator!=(const expected<void, E> &lhs,
                          const expected<void, F> &rhs) {
  return (lhs.has_value() != rhs.has_value())
             ? true
             : (!lhs.has_value() ? lhs.error() == rhs.error() : false);
}

template <class T, class E, class U>
constexpr bool operator==(const expected<T, E> &x, const U &v) {
  return x.has_value() ? *x == v : false;
}
template <class T, class E, class U>
constexpr bool operator==(const U &v, const expected<T, E> &x) {
  return x.has_value() ? *x == v : false;
}
template <class T, class E, class U>
constexpr bool operator!=(const expected<T, E> &x, const U &v) {
  return x.has_value() ? *x != v : true;
}
template <class T, class E, class U>
constexpr bool operator!=(const U &v, const expected<T, E> &x) {
  return x.has_value() ? *x != v : true;
}

template <class T, class E>
constexpr bool operator==(const expected<T, E> &x, const unexpected<E> &e) {
  return x.has_value() ? false : x.error() == e.value();
}
template <class T, class E>
constexpr bool operator==(const unexpected<E> &e, const expected<T, E> &x) {
  return x.has_value() ? false : x.error() == e.value();
}
template <class T, class E>
constexpr bool operator!=(const expected<T, E> &x, const unexpected<E> &e) {
  return x.has_value() ? true : x.error() != e.value();
}
template <class T, class E>
constexpr bool operator!=(const unexpected<E> &e, const expected<T, E> &x) {
  return x.has_value() ? true : x.error() != e.value();
}

template <class T, class E,
          detail::enable_if_t<(std::is_void<T>::value ||
                               std::is_move_constructible<T>::value) &&
                              detail::is_swappable<T>::value &&
                              std::is_move_constructible<E>::value &&
                              detail::is_swappable<E>::value> * = nullptr>
void swap(expected<T, E> &lhs,
          expected<T, E> &rhs) noexcept(noexcept(lhs.swap(rhs))) {
  lhs.swap(rhs);
}
} // namespace tl

#endif
/* end file include/ada/expected.h */
#include <optional>
#include <string_view>

/**
 * @namespace ada::parser
 * @brief Includes the definitions for supported parsers
 */
namespace ada::parser {

  /**
   * Parses a url.
   */
  url parse_url(std::string_view user_input,
                const ada::url* base_url = nullptr,
                ada::encoding_type encoding = ada::encoding_type::UTF8);

} // namespace ada

#endif // ADA_PARSER_H
/* end file include/ada/parser.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/scheme-inl.h
/* begin file include/ada/scheme-inl.h */
/**
 * @file scheme-inl.h
 * @brief Definitions for the URL scheme.
 */
#ifndef ADA_SCHEME_INL_H
#define ADA_SCHEME_INL_H


namespace ada::scheme {

  /**
   * @namespace ada::scheme::details
   * @brief Includes the definitions for scheme specific entities
   */
  namespace details {
    // for use with is_special and get_special_port
    // Spaces, if present, are removed from URL.
    constexpr std::string_view is_special_list[] = {"http", " ", "https",
                                                    "ws", "ftp", "wss", "file", " "};
    // for use with get_special_port
    constexpr uint16_t special_ports[] = {80, 0, 443, 80, 21, 443, 0, 0};
  }

  ada_really_inline constexpr bool is_special(std::string_view scheme) {
    if(scheme.empty()) { return false; }
    int hash_value = (2*scheme.size() + (unsigned)(scheme[0])) & 7;
    const std::string_view target = details::is_special_list[hash_value];
    return (target[0] == scheme[0]) && (target.substr(1) == scheme.substr(1));
  }
  constexpr uint16_t get_special_port(std::string_view scheme) noexcept {
    if(scheme.empty()) { return 0; }
    int hash_value = (2*scheme.size() + (unsigned)(scheme[0])) & 7;
    const std::string_view target = details::is_special_list[hash_value];
    if ((target[0] == scheme[0]) && (target.substr(1) == scheme.substr(1))) {
      return details::special_ports[hash_value];
    } else { return 0; }
  }
  constexpr uint16_t get_special_port(ada::scheme::type type) noexcept {
    return details::special_ports[int(type)];
  }
  constexpr ada::scheme::type get_scheme_type(std::string_view scheme) noexcept {
    if(scheme.empty()) { return ada::scheme::NOT_SPECIAL; }
    int hash_value = (2*scheme.size() + (unsigned)(scheme[0])) & 7;
    const std::string_view target = details::is_special_list[hash_value];
    if ((target[0] == scheme[0]) && (target.substr(1) == scheme.substr(1))) {
      return ada::scheme::type(hash_value);
    } else { return ada::scheme::NOT_SPECIAL; }
  }

} // namespace ada::serializers

#endif // ADA_SCHEME_H
/* end file include/ada/scheme-inl.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/url-inl.h
/* begin file include/ada/url-inl.h */
/**
 * @file url-inl.h
 * @brief Definitions for the URL
 */
#ifndef ADA_URL_INL_H
#define ADA_URL_INL_H


namespace ada {
  [[nodiscard]] ada_really_inline bool url::includes_credentials() const noexcept {
    return !username.empty() || !password.empty();
  }
  [[nodiscard]] ada_really_inline bool url::is_special() const noexcept {
    return type != ada::scheme::NOT_SPECIAL;
  }
  [[nodiscard]] inline uint16_t url::get_special_port() const {
    return ada::scheme::get_special_port(type);
  }
  [[nodiscard]] ada_really_inline ada::scheme::type url::get_scheme_type() const noexcept {
    return type;
  }
  [[nodiscard]] ada_really_inline uint16_t url::scheme_default_port() const noexcept {
    return scheme::get_special_port(type);
  }
  [[nodiscard]] inline bool url::cannot_have_credentials_or_port() const {
    return !host.has_value() || host.value().empty() || type == ada::scheme::type::FILE;
  }
  ada_really_inline size_t url::parse_port(std::string_view view, bool check_trailing_content) noexcept {
    ada_log("parse_port('", view, "') ", view.size());
    uint16_t parsed_port{};
    auto r = std::from_chars(view.data(), view.data() + view.size(), parsed_port);
    if(r.ec == std::errc::result_out_of_range) {
      ada_log("parse_port: std::errc::result_out_of_range");
      is_valid = false;
      return 0;
    }
    ada_log("parse_port: ", parsed_port);
    const size_t consumed = size_t(r.ptr - view.data());
    ada_log("parse_port: consumed ", consumed);
    if(check_trailing_content) {
      is_valid &= (consumed == view.size() || view[consumed] == '/' || view[consumed] == '?' || (is_special() && view[consumed] == '\\'));
    }
    ada_log("parse_port: is_valid = ", is_valid);
    if(is_valid) {
      port = (r.ec == std::errc() && scheme_default_port() != parsed_port) ?
        std::optional<uint16_t>(parsed_port) : std::nullopt;
    }
    return consumed;
  }
  [[nodiscard]] inline std::string_view url::get_scheme() const noexcept {
    if(is_special()) { return ada::scheme::details::is_special_list[type]; }
    // We only move the 'scheme' if it is non-special.
    return non_special_scheme;
  }
  inline void url::set_scheme(std::string&& new_scheme) noexcept {
    type = ada::scheme::get_scheme_type(new_scheme);
    // We only move the 'scheme' if it is non-special.
    if(!is_special()) {
      non_special_scheme = new_scheme;
    }
  }
  inline void url::copy_scheme(ada::url&& u) noexcept {
    non_special_scheme = u.non_special_scheme;
    type = u.type;
  }
  inline void url::copy_scheme(const ada::url& u) {
    non_special_scheme = u.non_special_scheme;
    type = u.type;
  }

  inline std::ostream& operator<<(std::ostream& out, const ada::url& u) {
    return out << u.to_string();
  }
} // namespace ada

#endif // ADA_URL_H
/* end file include/ada/url-inl.h */

// Public API
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/ada_version.h
/* begin file include/ada/ada_version.h */
/**
 * @file ada_version.h
 * @brief Definitions for Ada's version number.
 */
#ifndef ADA_ADA_VERSION_H
#define ADA_ADA_VERSION_H

#define ADA_VERSION "0.1.0"

namespace ada {

  enum {
    ADA_VERSION_MAJOR = 0,
    ADA_VERSION_MINOR = 1,
    ADA_VERSION_REVISION = 0,
  };

} // namespace ada

#endif // ADA_ADA_VERSION_H
/* end file include/ada/ada_version.h */
// dofile: invoked with prepath=/Users/dlemire/CVS/github/ada/include, filename=ada/implementation.h
/* begin file include/ada/implementation.h */
/**
 * @file implementation.h
 * @brief Definitions for user facing functions for parsing URL and it's components.
 */
#ifndef ADA_IMPLEMENTATION_H
#define ADA_IMPLEMENTATION_H

#include <string>
#include <optional>


namespace ada {
  enum class errors {
    generic_error
  };

  using result = tl::expected<ada::url,ada::errors>;

  /**
   * The URL parser takes a scalar value string input, with an optional null or base URL base (default null)
   * and an optional encoding encoding (default UTF-8).
   *
   * @param input the string input to analyze.
   * @param base_url the optional string input to use as a base url.
   * @param encoding encoding (default to UTF-8)
   * @return a parsed URL.
   */
  ada_warn_unused ada::result parse(std::string_view input,
                                 const ada::url* base_url = nullptr,
                                 ada::encoding_type encoding = ada::encoding_type::UTF8);
  /**
   * Computes a href string from a file path.
   * @return a href string (starts with file:://)
   */
  std::string href_from_file(std::string_view path);
}

#endif // ADA_IMPLEMENTATION_H
/* end file include/ada/implementation.h */

#endif // ADA_H
/* end file include/ada.h */
