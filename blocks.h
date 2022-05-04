//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",		"s-volume",		0,			10},
	{"", 		"s-mem",		15,			11},
	{"", 		"s-time",		1,			12},
	{"", 		"s-date",		60,			13},
	{"", 		"s-moon",		18000,			14},
	{"",		"s-nightfilter",	900,			15},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 5;
