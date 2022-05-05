#define CMDLENGTH 45
#define DELIMITER " "
#define CLICKABLE_BLOCKS

const Block blocks[] = {
	      /*Command*/      /*Update Interval*/  /*Update Signal*/
	BLOCK("s-volume",      0,	            10),
	BLOCK("s-mem",	       15,		    11),
	BLOCK("s-time",	       1,	            12),
	BLOCK("s-date",	       60,	            13),
	BLOCK("s-moon",        18000,		    14),
	BLOCK("s-nightfilter", 900,                 15),
};
