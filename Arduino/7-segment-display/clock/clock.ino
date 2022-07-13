#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup()
{
	while (!Serial)
		;

	Serial.begin(115200);
	if (!rtc.begin())
	{
		Serial.println("Couldn't find RTC");
		while (1)
			;
	}
}

// @brief change the time by relative value
// @param dHour		the change in hours
// @param dMinute	the change in minutes
void changeTime(int dHour, int dMinute)
{
	DateTime now = rtc.now();
	int hour = (now.hour() + dHour) % 24;
	if (hour < 0)
		hour = 23;
	int minute = (now.minute() + dMinute) % 60;
	if (minute < 0)
		minute = 59;
	rtc.adjust(DateTime(2000, 8, 30, hour, minute, now.second()));
}

void loop()
{
	DateTime now = rtc.now();

	Serial.print(now.hour(), DEC);
	Serial.print(':');

	Serial.print(now.minute(), DEC);
	Serial.print(':');
	Serial.print(now.second(), DEC);

	Serial.println("");
	changeTime(1, 0);

	delay(1000);
}
