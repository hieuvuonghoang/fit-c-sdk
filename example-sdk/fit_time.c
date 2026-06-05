#include "fit_time.h"

void PrintEpochTimeFit(const FIT_DATE_TIME *date_time, const FIT_UINT32 *time_offset) {

    FIT_DATE_TIME date_time_start = 0;
    FIT_BOOL result = GetEpoch(FIT_EPOCH_YEAR, FIT_EPOCH_MONTH, FIT_EPOCH_DAY, FIT_EPOCH_HOUR, FIT_EPOCH_MINUTE, FIT_EPOCH_SECOND, &date_time_start);
    if (!result)
    {
        return;
    }
    time_t t_of_day = *(date_time) + date_time_start;
    t_of_day += *time_offset;  // Add offset to time_t before converting
    struct tm ts;
    char buf[80];
    ts = *localtime(&t_of_day);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
    printf("%s\n", buf);
}

FIT_BOOL GetEpochForFitByArgs(char* argv[], FIT_DATE_TIME *date_time) {
    return GetEpochForFit(atoi(argv[0]), atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), date_time);
}

FIT_BOOL GetEpoch(int year, int month, int day, int hour, int minute, int second, FIT_DATE_TIME *date_time)
{
    if (year < 1900 || year > 2100)
    {
        printf("Error: year must be between 1900 and 2100\n");
        return FIT_FALSE;
    }
    if (month < 1 || month > 12)
    {
        printf("Error: month must be between 1 and 12\n");
        return FIT_FALSE;
    }
    if (day < 1 || day > 31)
    {
        printf("Error: day must be between 1 and 31\n");
        return FIT_FALSE;
    }
    if (hour < 0 || hour > 23)
    {
        printf("Error: hour must be between 0 and 23\n");
        return FIT_FALSE;
    }
    if (minute < 0 || minute > 59)
    {
        printf("Error: minute must be between 0 and 59\n");
        return FIT_FALSE;
    }
    if (second < 0 || second > 59)
    {
        printf("Error: second must be between 0 and 59\n");
        return FIT_FALSE;
    }
    struct tm t;
    t.tm_year = year - 1900; // Year - 1900
    t.tm_mon = month - 1;    // Month, where 0 = jan
    t.tm_mday = day;         // Day of the month
    t.tm_hour = hour;
    t.tm_min = minute;
    t.tm_sec = second;
    *date_time = mktime(&t);
    return FIT_TRUE;
}

FIT_BOOL GetEpochForFit(int year, int month, int day, int hour, int minute, int second, FIT_DATE_TIME *date_time)
{
    FIT_DATE_TIME t_of_day = 0;
    FIT_BOOL result = GetEpoch(year, month, day, hour, minute, second, &t_of_day);
    if (result == FIT_FALSE)
    {
        return FIT_FALSE;
    }
    FIT_DATE_TIME t_of_day_start = 0;
    result = GetEpoch(FIT_EPOCH_YEAR, FIT_EPOCH_MONTH, FIT_EPOCH_DAY, FIT_EPOCH_HOUR, FIT_EPOCH_MINUTE, FIT_EPOCH_SECOND, &t_of_day_start);
    if (result == FIT_FALSE)
    {
        return FIT_FALSE;
    }
    *date_time = t_of_day - t_of_day_start;
    return FIT_TRUE;
}