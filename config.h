#pragma once

#define CLICKABLE_BLOCKS 1  // Enable clickability for blocks
#define CMDLENGTH 45        // Number of characters that each block will output
#define DELIMITER "  "      // Delimiter string used to separate blocks
#define LEADING_DELIMITER 0  // Whether a leading separator should be used

const Block blocks[] = {
	      /*Command*/      /*Update Interval*/  /*Update Signal*/
	BLOCK("s-volume",      0,	            10),
	BLOCK("s-mem",	       15,		    11),
	BLOCK("s-time",	       1,	            12),
	BLOCK("s-date",	       60,	            13),
	BLOCK("s-moon",        18000,		    14),
	BLOCK("s-nightfilter", 900,                 15),
};
