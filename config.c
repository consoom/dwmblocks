#include "config.h"

#include "block.h"
#include "util.h"

// clang-format off
Block blocks[] = {
	      /*Command*/      /*Update Interval*/  /*Update Signal*/
    {"s-volume",               0,	            10},
    {"s-mem",	               15,	            11},
    {"s-time",	               1,                   12},
    {"s-date",	               60,                  13},
    {"s-moon",                 18000,	            14},
    {"s-nightfilter",          900,                 15},
};
// clang-format on

const unsigned short blockCount = LEN(blocks);
