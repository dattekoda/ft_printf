#ifndef GPT_PRINTF_H
# define GPT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/* ------------------------ format structure -------------------------------- */

typedef struct s_format
{
    int     flag_minus;
    int     flag_zero;
    int     flag_hash;
    int     flag_space;
    int     flag_plus;
    int     width;
    int     precision;
    int     dot;
    char    spec;
}   t_format;

/* ------------------------- public prototype -------------------------------- */

int gpt_printf(const char *fmt, ...);

#endif