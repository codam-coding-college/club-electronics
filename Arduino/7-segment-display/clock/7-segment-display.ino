#include <SevSeg.h>

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

//set all segments & digits as outputs
void	setup()
{
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
}

void loop()
{
	digit1();zero();delay(500);
	digit2();one();delay(500);
	digit3();two();delay(500);
	digit4();three();delay(500);
	digit3();four();delay(500);
	digit2();five();delay(500);
	digit1();six();delay(500);
	digit2();seven();delay(500);
	digit3();eight();delay(500);
	digit4();nine();delay(500);

	all4Digits();
	allNumbers();
	one();
	two();
	three();
	four();
	five();
	six();
	seven();
	eight();
	nine();

}


//functions representing numbers 0-9
void	zero()
{
	digitalWrite(pinA,	HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, LOW);
	}

void	one()
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
}

void	two()
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, HIGH);
}

void	three()
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, HIGH);
}

void	four()
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
}

void	five()
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
}

void	six()
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
}

void	seven()
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
}

void eight()
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
}

void nine()
{
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
}

void allNumbers()
{
	zero();delay(500);
	one();delay(500);
	two();delay(500);
	three();delay(500);
	four();delay(500);
	five();delay(500);
	six();delay(500);
	seven();delay(500);
	eight();delay(500);
	nine();delay(500);
}

void turnOffAllSegments()
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
}


//functions to select individual digits on the display
void digit1()
{
	digitalWrite(D1, HIGH);
	digitalWrite(D2, LOW);
	digitalWrite(D3, LOW);
	digitalWrite(D4, LOW);
}

void digit2()
{
	digitalWrite(D1, LOW);
	digitalWrite(D2, HIGH);
	digitalWrite(D3, LOW);
	digitalWrite(D4, LOW);
}

void digit3()
{
	digitalWrite(D1, LOW);
	digitalWrite(D2, LOW);
	digitalWrite(D3, HIGH);
	digitalWrite(D4, LOW);
}

void digit4()
{
	digitalWrite(D1, LOW);
	digitalWrite(D2, LOW);
	digitalWrite(D3, LOW);
	digitalWrite(D4, HIGH);
}

void all4Digits()
{
	digitalWrite(D1, LOW);
	digitalWrite(D2, LOW);
	digitalWrite(D3, LOW);
	digitalWrite(D4, LOW);
}

