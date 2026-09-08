#include "clock.h"



/*----------GLOBAL_VARIABLES----------*/
SensorPCF85063 rtc;

char timeBuffer[20];
char dateBuffer[30];
char dayBuffer[12];
int lastMinute = -1;
int lastDay = -1;

/*----------CLOCK_RESET----------*/
void clock_reset() {

    const char* months[] = {
        "Jan", "Feb", "Mar", "Apr",
        "May", "Jun", "Jul", "Aug",
        "Sep", "Oct", "Nov", "Dec"
    };

    int month = 0;
    int day;
    int year;

    int hour;
    int minute;
    int second;

    char monthStr[4];

    // Parse compile date: "Jul 17 2026"
    sscanf(
        __DATE__,
        "%s %d %d",
        monthStr,
        &day,
        &year
    );

    // Convert month string to number
    for (int i = 0; i < 12; i++) {
        if (strcmp(monthStr, months[i]) == 0) {
            month = i + 1;
            break;
        }
    }

    // Parse compile time: "18:22:10"
    sscanf(
        __TIME__,
        "%d:%d:%d",
        &hour,
        &minute,
        &second
    );

    rtc.setDateTime(
        RTC_DateTime(
            year,
            month,
            day,
            hour,
            minute,
            second,
            0
        )
    );
}

/*----------CLOCK_SETUP----------*/
void clock_setup() {
    if (!rtc.begin(Wire))
    {
        Serial.println("RTC not found!");
        while (1);
    }
}

/*----------CLOCK----------*/
const char* clock_run() {
    
    // Get the current date and time from the RTC
    RTC_DateTime now = rtc.getDateTime();

    // Only update when the Minutes changes
    if (now.getMinute() != lastMinute)
    {
      lastMinute = now.getMinute();

      // Format the time as HH:MM
      sprintf(
          timeBuffer,
          "%02d:%02d",
          now.getHour(),
          now.getMinute()
        );
    }
    
    return timeBuffer;
    
}

/*----------DATE----------*/
const char* date_run()
{
    RTC_DateTime now = rtc.getDateTime();

    if (now.getDay() != lastDay)
    {
        lastDay = now.getDay();

        sprintf(
            dateBuffer,
            "%02d/%02d/%04d",
            now.getMonth(),
            now.getDay(),
            now.getYear()
        );
    }

    return dateBuffer;
}

const char* day_run() {
    RTC_DateTime now = rtc.getDateTime();

    const char* days[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    sprintf(
        dayBuffer,
        "%s",
        days[now.getWeek()]
    );

    return dayBuffer;
}