#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
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

class Price
{
	string product;
	string shop;
	int price;
	int size;
	Price** array;
public:
	~Price() { cout << "Destructor" << endl; delete array; };
	Price(int a)
	{
		string text;
		cout << "First object" << endl << "product: ";
		getline(cin, text);
		Setter_product(text);
		cout << "shop: ";
		getline(cin, text);
		Setter_shop(text);
		cout << "price: ";
		getline(cin, text);
		Setter_price(stoi(text));
	}
	Price()
	{
		price = 0;
	}
	Price(const Price& object)
	{
		
		this->array = new Price * [object.size];
		
		for (int i = 0; i < object.size; i++)
		{
			array[i] = object.array[i];
		}
	}
	void Setter_product(string product) { this->product = product; };
	void Setter_shop(string shop) { this->shop = shop; };
	void Setter_price(int price) { this->price = price; };
	void Setter_size(int size) { this->size = size; };

	string Getter_product() {return product;}
	string Getter_shop() { return shop; };
	int Getter_price() { return price; };
	int Getter_size() { return size; };

	void Show_products()
	{
		string text;
		getline(cin, text);

		for (int i = 0; i < Getter_size(); i++)
		{
			if (text == array[i]->Getter_shop())
			{
				cout << i + 1<<endl;
				array[i]->Show();
			}
		}
	}
	void Show()
	{
		cout << "product: " << Getter_product() << endl;
		cout << "shop: " << Getter_shop() << endl << "price: " << Getter_price() << endl;
	}
	void Show_all()
	{
		for (int i = 0; i < Getter_size(); i++)
		{
			cout << i + 1 << endl;
			cout << "Show all-Show" << endl;
			array[i]->Show();
		}
	}
	Price operator +(int number)
	{
		Price buffer(*this);
		Setter_size(Getter_size() + 1);
		array = new Price * [Getter_size()];
		
		
		for (int i = 0; i < Getter_size()-1; i++)
		{
			array[i] = buffer.array[i];
		}
		array[Getter_size() - 1] = new Price(1);
		return *this;
	}
	Price operator -(int number)
	{
		Price buffer(*this);
		Setter_size(Getter_size() - 1);
		array = new Price * [Getter_size()];
		for (int i = 0; i < number - 1; i++)
		{
			array[i] = buffer.array[i];
		}
		for (int i = number - 1; i < Getter_size(); i++)
		{
			array[i] = buffer.array[i + 1];
		}

		return *this;

	}
	
	//void Swap(string* xp, string* yp)
	//{
	//	string temp = *xp;
	//	*xp = *yp;
	//	*yp = temp;
	//}
	//int Partition(string arr[], int low, int high) {

	//	string pivot = arr[high];
	//	int i = (low - 1);

	//	for (int j = low; j <= high - 1; j++) {

	//		if (arr[j] < pivot) {
	//			i++;
	//			Swap(&arr[i], &arr[j]);
	//		}
	//	}
	//	Swap(&arr[i + 1], &arr[high]);
	//	return (i + 1);
	//}
	//void QuickSort(string arr[], int low, int high) {
	//	if (low < high) {
	//		int pi = Partition(arr, low, high);
	//		QuickSort(arr, low, pi - 1);
	//		QuickSort(arr, pi + 1, high);
	//	}
	//}
};
int main()
{


		SetConsoleTitle(L"menu");
		consoleCursorVisible(false, 100);
		string menu[] = { "1. ADD", "2. DELETE", "3. SHOW ALL", "4. SHOW PRODUCTS FROM A SPECIFIC STORE", "5. EXIT"};
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
					
						cout << endl << endl;
						object + 1;
						kolvo++;
					
					break;
				case 1:
					system("cls");
					if (kolvo != 0)
					{
						object.Show_all();
						cout << "CHOOSE: ";
						//cin >> k;
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
