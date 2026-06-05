#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "fit.h"
#include "fit_example.h"

#define FIT_EPOCH_YEAR 1989
#define FIT_EPOCH_MONTH 12
#define FIT_EPOCH_DAY 31
#define FIT_EPOCH_HOUR 0
#define FIT_EPOCH_MINUTE 0
#define FIT_EPOCH_SECOND 0

FIT_BOOL GetEpoch(int year, int month, int day, int hour, int minute, int second, FIT_DATE_TIME *date_time);
FIT_BOOL GetEpochForFit(int year, int month, int day, int hour, int minute, int second, FIT_DATE_TIME *date_time);
FIT_BOOL GetEpochForFitByArgs(char *argv[], FIT_DATE_TIME *date_time);
void PrintEpochTimeFit(const FIT_DATE_TIME *date_time, const FIT_UINT32 *time_offset);