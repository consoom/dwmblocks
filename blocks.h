//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",		"s-volume",		0,			10},
	{"", 		"s-mem",		15,			0},
	{"", 		"s-time",		1,			0},
	{"", 		"s-date",		60,			0},
	{"", 		"s-moon",		18000,			0},
	{"",		"s-nightfilter",	900,			0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 5;
