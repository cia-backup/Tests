#define PAGE_UP     73
#define HOME        71
#define END         79
#define PAGE_DOWN   81
#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77
#define F1          59
#define F2          60
#define F3          61
#define F4          62
#define F5          63
#define F6          64
#define F7          65
#define F8          66
#define F9          67
#define F10         68
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	char KeyStroke;
	cout << "Press Escape to quit." << endl;
	int c;
	do
	{
		KeyStroke =	getch();
		c = KeyStroke;
		cout << KeyStroke << " = " << c << endl;
	} 
	while (KeyStroke != 27); // 27 = Escape key
	return 0;
}
