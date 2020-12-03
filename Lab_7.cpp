// Lab_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

#include <cstdlib>

#include <stdio.h>

#include<malloc.h>

#include<string.h>

#include "locale.h"

#include "windows.h"


#define LEN 10 
#define st_art "_Арт_"
#define st_type "_Вид_"
#define st_name "_Бренд_"
#define st_season "__Сезон__"
#define st_price = 0;
#define pr 0.24


using namespace std;

class shoes
{
public:
	shoes()
	{
		name = st_name;
		type = st_type;
		art = st_art;
		price = 0;
	}

	shoes(string name, string type, string art, double price)
	{
		this->name = name;
		this->type = type;
		this->art =  art;
		this->price = price;
	}


	void set_name(char name[LEN])
	{
		this->name = name;
	}

	void set_type(char type[LEN])
	{
		this->type = type;
	}

	void set_art(char art[LEN])
	{
		this->art =  art;
	}

	void set_price(double price)
	{
		this->price = price;
	}

	string get_name()
	{
		cout << "Название бренда: " << name << endl;
	}

	string get_type()
	{
		cout << "Вид обуви: " << type << endl;
	}

	char get_art()
	{
		cout << "Артикул: " << art << endl;
	}

	double get_price()
	{
		return this->price;
	}

	void read()
	{
		cout << "Введите бренд\n";
		rewind(stdin); cin >> name;
		cout << "Введите вид обуви\n";
		rewind(stdin); cin >> type;
		cout << "Введите артикул\n";
		rewind(stdin); cin >> art;
		cout << "Введите стоимость\n";
		cin >> price;
	}

	void display()
	{

		cout << "Бренд: " << name << endl;
		cout << "Вид обуви: " << type << endl;
		cout << "Артикул: " << art << endl;
		cout << "Стоимость: " << price << endl;
	}



	friend double add(double sum, shoes* x);



private:
	string name;
	string type;
	string art;
	double price;



};

double add(double sum, shoes* x)
{
	sum += (*x).price;
	cout << "Общая стоимость товаров:" << sum << endl;
	return sum;
}


class store
{
public:


	store()
	{
		kol = 0;
		profit = 0;
		sale_count = 0;
		*para = new shoes();
	}
	store(int kol, double profit, int sale_count, shoes* para[LEN])
	{
		this->kol = kol;
		this->profit = profit;
		this->sale_count = sale_count;
		for (int i = 0; i < kol; i++)
		{
			this->para[i] = para[i];
		}
	}

	store(int kol, double profit, int sale_count, shoes* para)
	{
		this->kol = kol;
		this->profit = profit;
		this->sale_count = sale_count;
		for (int i = 0; i < kol; i++)
		{
			this->para[i] = para;
		}
	}

	shoes* get_shoes(store st)
	{
		return *para;
	}

	int get_kol()
	{
		return kol;
	}

	void set_kol(int kol)
	{
		this->kol = kol;
	}

	double get_profit()
	{
		return profit;
	}

	void set_profit(double profit)
	{
		this->profit = profit;
	}
	int get_sale()
	{
		return sale_count;
	}

	void set_sale(int sale_count)
	{
		this->sale_count = sale_count;
	}

	void read()
	{
		cout << "Количество пар: " << kol << endl;
		cout << "Выручка: " << profit << endl;
		cout << "Количество продаж: " << sale_count << endl;
	}


	void display()
	{
		cout << "Количество пар: " << kol << endl;
		cout << "Выручка: " << profit << endl;
		cout << "Количество продаж: " << sale_count << endl;
		for (int i = 0; i < kol; i++)
		{
			para[i]->display();
		}
	}


	void sale()
	{
		for (int i = 0; i < kol; i++)
		{
			profit += para[i]->get_price();
			sale_count++;
			kol -= 1;
		}
		cout << "\nПродажа прошла успешно\n";
	}

	void back()
	{
		for (int i = 0; i < 1; i++)
		{
			profit -= para[i]->get_price();
			sale_count--;
			kol += 1;
		}
		cout << "\nВозврат прошел успешно\n";
	}


	void tax(double* taxa)
	{
		*taxa = profit * pr;
		cout << "Налог на прибыль составит:" << *taxa << endl;
		return;
	}

	store& operator++ ()
	{
		this->sale_count++;
		return *this;
	}

	store operator++ (int)
	{
		store tmp = *this;
		++ *this;
		return tmp;
	}
	
	static void rent(int& renta)
	{
		static int stavka = 0;
		stavka += 300;
		renta = stavka;
		return;
	}
private:
	int kol;
	double profit;
	int sale_count;
	shoes* para[LEN];
};


int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int kol = 1;
	string standart_name = "__Бренд__";
	string standart_type = "__Вид__";
	string standart_art = "__Арт__";
	int renta = 0;
	double taxa = 0;

	// Начало основной программы
	cout << "\n Основная программа:\n" << endl;
	shoes* para1 = new shoes(standart_name, standart_type, standart_art, 0);
	para1->read();
	store st(kol, 0, 0, para1);
	cout << "Работа со статическими переменными\n" << endl;
	cout << "\nПосле ввода\n" << endl;
	st.display();
	// Статический метод
	st.rent(renta);
	cout << "Налог на обувь: \n" << renta << endl;
	st.sale();
	cout << "\nПосле продажи\n" << endl;
	st.display();
	st.tax(&taxa);
	st.back();
	cout << "\nПосле возврата\n" << endl;
	st.display();
	sum = add(sum, para1);
	kol = st.get_kol();

	// Перегрузки
	cout << "\n __Перегрузки__ \n" << endl;
	store st10 (kol, 0, 2, para1);
	st10.display();
	st10 = ++st;
	cout << "\n Префикс: \n" << endl;
	cout << "Количество продаж в 1 магазине:\n" << st10.get_sale() << endl;
	cout << "Количество продаж вo 2 магазине:\n" << st.get_sale() << endl;
	st10 = st++;
	cout << "\n Постфикс: \n" << endl;
	cout << "Количество продаж в 1 магазине:\n" << st10.get_sale() << endl;
	cout << "Количество продаж вo 2 магазине:\n" << st.get_sale() << endl;


	renta = 0;
	cout << "\n-------------------------------------------------\n" << endl;
	cout << "\nРабота с динамическим объектом класса\n" << endl;
	shoes* para2 = new shoes(standart_name, standart_type, standart_art, 0);
	para2->read();
	store* st2 = new store(kol, 0, 0, para2);
	cout << "\nПосле ввода\n" << endl;
	store::rent(renta);
	cout << "Налог на обувь: \n" << renta << endl;
	st2->display();
	st2->sale();
	cout << "\nПосле продажи\n" << endl;
	st2->display();
	st2->back();
	cout << "\nПосле возврата\n" << endl;
	st2->display();
	sum = add(sum, para2);


	renta = 0;
	cout << "\n-------------------------------------------------\n" << endl;
	cout << "\nРабота с массивом\n" << endl;
	shoes para3[LEN];
	cout << "\nВведите количество позиций\n" << endl;
	cin >> kol;
	for (int i = 0; i < kol; i++)
	{

		para3[i].read();
		sum = add(sum, &para3[i]);
		st.rent(renta);
	}
	store* st3 = new store(kol, 0, 0, para3);



	cout << "\nПосле ввода\n" << endl;
	st3->display();
	cout << "Налог на обувь: \n" << renta << endl;
	st3->sale();
	cout << "\nПосле продажи\n" << endl;
	st3->display();

	st3->back();
	cout << "\nПосле возврата\n" << endl;
	st3->display();
	delete st3;
	cout << "\n-------------------------------------------------\n" << endl;
	return 0;
}