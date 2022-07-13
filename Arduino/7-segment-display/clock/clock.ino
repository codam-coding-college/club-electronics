#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 11;
int pinF = 12;
int pinG = 13;
int pinDP = 6;
int D1 = 7;
int D2 = 8;
int D3 = 9;
int D4 = 10;

char digits[10] = {
	0b01111110,
	0b00110000,
	0b01101101,
	0b01111001,
	0b00110011,
	0b01011011,
	0b01011111,
	0b01110000,
	0b01111111,
	0b01111011,
};

void setup()
{
	while (!Serial)
		;
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
	pinMode(pinC, OUTPUT);
	pinMode(pinD, OUTPUT);
	pinMode(pinE, OUTPUT);
	pinMode(pinF, OUTPUT);
	pinMode(pinG, OUTPUT);
	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D3, OUTPUT);
	pinMode(D4, OUTPUT);

	Serial.begin(115200);
	if (!rtc.begin())
	{
		Serial.println("Couldn't find RTC");
		while (1)
			;
	}
}

// @param index the index of the number, 0, 1, 2, 3
void selectDigit(int index)
{
	char flag;
	if (index == 0)
		flag = 0b00001000;
	if (index == 1)
		flag = 0b00000100;
	if (index == 2)
		flag = 0b00000010;
	if (index == 3)
		flag = 0b00000001;

	digitalWrite(D1, flag & 0b00000111);
	digitalWrite(D2, flag & 0b00001011);
	digitalWrite(D3, flag & 0b00001101);
	digitalWrite(D4, flag & 0b00001110);
}

void writeDigit(char flag)
{
	digitalWrite(pinA, flag & 0b01000000);
	digitalWrite(pinB, flag & 0b00100000);
	digitalWrite(pinC, flag & 0b00010000);
	digitalWrite(pinD, flag & 0b00001000);
	digitalWrite(pinE, flag & 0b00000100);
	digitalWrite(pinF, flag & 0b00000010);
	digitalWrite(pinG, flag & 0b00000001);
}

void displayTime(unsigned int hour, unsigned int minute)
{
	(void)minute;
	selectDigit(0);
	writeDigit(digits[hour]);
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

int i = 0;
void loop()
{
	displayTime(i, 0);
	i = ++i % 10;
	delay(1000);
}
