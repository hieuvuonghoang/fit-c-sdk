#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 2021-09-08T01:46:40-0600Z in seconds since the FIT Epoch of 1989-12-31T:00:00:00Z
    struct tm t;
    time_t t_of_day;
    char buf[80];

    // putenv("TZ=UTC");
    // tzset();

    t.tm_year = 1989 - 1900;
    t.tm_mon = 12 - 1;
    t.tm_mday = 31;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t_of_day = mktime(&t);

    printf("epoch time for 1989-12-31T:00:00:00Z: %ld\n", (long)(t_of_day));

    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &t);
    printf("%s\n", buf);
    
    return 0;
}

// int main(int argc, char *argv[])
// {
//     if (argc < 7)
//     {
//         printf("usage: epoch.exe <year> <month> <day> <hour> <minute> <second>");
//         return 1;
//     }

//     {

//         time_t t_of_day = GetEpochForFitByArgs(&argv[1]);
//         if(t_of_day == -1)
//         {
//             return 1;
//         }
//         printf("seconds since the Epoch: %ld\n", (long)(t_of_day));
//     }

//     return 0;
// }

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