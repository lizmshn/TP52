#pragma once
#include <iostream>
#include <string>
using namespace std;
class Price
{
	string product;
	string shop;
	int price;
	int size;
	Price** array;
public:

	Price(int a);
	Price();
	Price(const Price& object);
	~Price();
	void Setter_product(string product);
	void Setter_shop(string shop);
	void Setter_price(int price);
	void Setter_size(int size);

	string Getter_product();
	string Getter_shop();
	int Getter_price();
	int Getter_size();

	void Show_products();
	void Show();
	void Show_all();
	Price operator +(int number);
	Price operator -(int number);
	void Insertion_sort();

};