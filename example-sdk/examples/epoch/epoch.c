#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "fit_time.h"

int main(int argc, char *argv[])
{
    if (argc < 7)
    {
        printf("usage: epoch.exe <year> <month> <day> <hour> <minute> <second>");
        return 1;
    }

    {
        
        time_t t_of_day = GetEpochForFitByArgs(&argv[1]);
        if(t_of_day == -1)
        {
            return 1;
        }
        printf("seconds since the Epoch: %ld\n", (long)(t_of_day));
    }

    return 0;
}

// int main(void) {
//     time_t now;
//     struct tm ts;
//     char buf[80];

//     // Get the current time
//     time(&now);

//     // Format the time as a string
//     ts = *localtime(&now);
//     strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
//     printf("%s\n", buf);
//     return 0;
// }

// int main(void)
// {
//     time_t rawtime = 0;
//     struct tm ts;
//     char buf[80];
//     ts = *localtime(&rawtime);
//     strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
//     printf("%s\n", buf);
//     return 0;
// }