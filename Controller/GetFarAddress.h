#pragma once


#ifndef GET_FAR_ADDRESS

/**
 * All credit to Carlos Lamas for this patch:
 * https://savannah.nongnu.org/patch/?6352
 *
 * GET_FAR_ADDRESS allows us to export a 24-bit flash address into our
 * code (as a 32-bit variable) which means we can seamlessly address
 * large binaries stored in flash without having to fix their address.
 */

#define GET_FAR_ADDRESS(var)                  \
({                                            \
  uint32_t tmp;                               \
                                              \
  __asm__ __volatile__(                       \
                                              \
      "ldi  %A0, lo8(%1)"           "\n\t"    \
      "ldi  %B0, hi8(%1)"           "\n\t"    \
      "ldi  %C0, hh8(%1)"           "\n\t"    \
      "clr  %D0"                    "\n\t"    \
    :                                         \
      "=d" (tmp)                              \
    :                                         \
      "p"  (&(var))                           \
  );                                          \
  tmp;                                        \
})


#endif