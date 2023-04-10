#include "config.h"

#include "block.h"
#include "util.h"

// clang-format off
Block blocks[] = {
	      /*Command*/      /*Update Interval*/  /*Update Signal*/
    {"echo ^C1^$(s-volume)",   0,	            10},
    {"echo ^C2^$(s-mem)",      15,	            11},
    {"echo ^C3^$(s-time)",     1,                   12},
    {"echo ^C4^$(s-date)",     60,                  13},
    {"echo ^C1^$(s-moon)",     18000,	            14},
    {"echo ^C1^$(s-nightfilter)",900,               15},
};
// clang-format on

const unsigned short blockCount = LEN(blocks);
