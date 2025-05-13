#include <stdio.h>
#include "gpt_printf.h"

int main(void)
{
    int mask = 0;
    int count = 0;
    /* 幅と精度のパターン */
    int widths[3] = {0, 3, 5};
    int precs[3]  = {-1, 0, 2};

    while (mask < 16 && count < 50)
    {
        char flags[5];
        int  fidx = 0;
        /* ビットマスクでフラグ文字を詰める */
        if (mask & 1) flags[fidx++] = '-';
        if (mask & 2) flags[fidx++] = '+';
        if (mask & 4) flags[fidx++] = ' ';
        if (mask & 8) flags[fidx++] = '0';
        flags[fidx] = '\0';

        int wi = 0;
        while (wi < 3 && count < 50)
        {
            int pi = 0;
            while (pi < 3 && count < 50)
            {
                char fmt[32];
                int  w = widths[wi];
                int  p = precs[pi];

                /* フォーマット文字列を作成 */
                if (w > 0)
                {
                    if (p >= 0)
                        snprintf(fmt, sizeof(fmt), "%%%s%d.%dd", flags, w, p);
                    else
                        snprintf(fmt, sizeof(fmt), "%%%s%dd",   flags, w);
                }
                else
                {
                    if (p >= 0)
                        snprintf(fmt, sizeof(fmt), "%%%s.%dd", flags, p);
                    else
                        snprintf(fmt, sizeof(fmt), "%%%sd",     flags);
                }

                /* 比較出力 */
				printf("%s\n", fmt);
                printf(fmt,  42);
				printf("\n");
                gpt_printf(fmt, 42);
				printf("\n\n");
                count++;
                pi++;
            }
            wi++;
        }
        mask++;
    }

    return 0;
}
