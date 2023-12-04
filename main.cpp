#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Price.h"
using namespace std;
#define UP 72
#define DOWN 80
#define ENTER 13
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void goToXY(short xx, short yy)
{
	SetConsoleCursorPosition(hStdOut, { xx,yy });
}
void consoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int main()
{


		SetConsoleTitle(L"menu");
		consoleCursorVisible(false, 100);
		string menu[] = { "1. ADD", "2. DELETE", "3. SHOW ALL", "4. SHOW PRODUCTS FROM A SPECIFIC STORE", "5. SORT ALPHABETICALLY", "6. EXIT"};
		int activeMenu = 0;
		char ch;
		float x = 0;
		string text;
		Price object;

		int kolvo = 0;

		while (1)
		{
			int xx = 55, yy = 0;
			goToXY(xx, yy);
			for (int i = 0; i < size(menu); i++)
			{
				if (i == activeMenu)
					SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE |
						FOREGROUND_INTENSITY);
				else
					SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
				goToXY(xx, yy++);
				cout << menu[i] << endl;
			}
			ch = _getch();
			if (ch == -32)
				ch = _getch();
			switch (ch)
			{
			case UP:
				if (activeMenu > 0)
					--activeMenu;
				break;
			case DOWN:
				if (activeMenu < size(menu) - 1)
					++activeMenu;
				break;
			case ENTER:
				switch (activeMenu)
				{
				case 0:
					system("cls");
						object + 1;
						kolvo++;
					
					break;
				case 1:
					system("cls");
					if (kolvo != 0)
					{
						object.Show_all();
						cout << "CHOOSE: ";
						getline(cin, text);
						if (stoi(text) > 0 && stoi(text) <= kolvo)
						{
							object - stoi(text);
							kolvo--;
						}
						else
						{
							system("cls");
							cout << "ERROR!" << endl;
						}
					}
					else
					{
						system("cls");
						cout << "NO OBJECTS!" << endl;
					}
					break;
				case 2:
					system("cls");
					if (kolvo != 0)
						object.Show_all();
					else
						cout << "EMPTY!" << endl;
					break;
				case 3:
					system("cls");
					if (kolvo != 0)
						object.Show_products();
					else
						cout << "EMPTY!" << endl;
					break;
				case 4:
					system("cls");
					if (kolvo != 0)
					{
						object.Insertion_sort();
						cout << "SORTING SUCCESSFUL" << endl;
					}
					else
						cout << "EMPTY!" << endl;
					break;

				case 5:
					system("cls");
					exit(0);
					break;
				
				default:
					break;
				}
			default:
				break;
			}
		}

	}
