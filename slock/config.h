/* user and group to drop privileges to */
static const char *user  = "edes";
static const char *group = "wheel";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#ba9773", /* during input */
	[FAILED] = "#cc817c",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
