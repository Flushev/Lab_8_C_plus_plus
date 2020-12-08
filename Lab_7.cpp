// Lab_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

#include <cstdlib>

#include <stdio.h>

#include<malloc.h>

#include<string.h>

#include "locale.h"

#include "windows.h"

#pragma warning(disable:4996)



#define LEN 20
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

	shoes(char* s, double price)
	{
		int k = strlen(s) + 1;
		season = new char[k];
		strcpy(season, s);
		this->price = price;
	}

	shoes(shoes& s)
	{
		season = new char[20];
		strcpy (this->season, s.season);
		this->price = s.price;
	}

	shoes& operator = (shoes& s)
	{
		int k;
		if (this->season)
		{
			delete this->season;
		}
		this->season = NULL;
		k = strlen(s.season) + 1;
		this->season = new char[k];
		strcpy(this->season, s.season);
		this->price = s.price;
		return *this;
	}

	shoes(double price)
	{
		name = st_name;
		type = st_type;
		art = st_art;
		this->price = price;
	}

	void set_season(char* s)
	{
		strcpy(season, s);
	}

	void set_name(string name)
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
		cout << "" << endl;
	}

	void display_copy()
	{
		cout << "Сезон:" << season << endl;
		cout << "Стоимость: " << price << endl;
		cout << "" << endl;
	}


	friend double add(double sum, shoes* x);



private:
	string name;
	string type;
	string art;
	double price;
	char* season;



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
	
	static int rent(int kol)
	{
		static int stavka = 300;
		int renta = 0;
		if (kol < 2)
			stavka += 20;
		else stavka -= 20;
		renta = kol * stavka;
		return renta;
	}
private:
	int kol;
	double profit;
	int sale_count;
	shoes* para[LEN];
	static int stavka;
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

	// Инициализация массива через конструктор с одним параметром
	cout << "Инициализация массива через конструктор с одним параметром\n" << endl;
	shoes para_tmp[2] = { 1000,2000, };
	for (int i = 0; i < 2; i++)
	{
		para_tmp[i].display();
		cout << "\n" << endl;
	}
	
	
	//Глубокое копирование
	char* season;
	season = new char[20];
	strcpy(season, "Зима");
	shoes s (season, 2000);
	shoes s1 = s;
	cout << "\nПосле копирования\n" << endl;
	s.display_copy();
	s1.display_copy();
	strcpy(season, "Лето");
	s.set_season(season);
	cout << "После изменения первого объекта\n" << endl;
	s.set_price(5000);
	s.display_copy();
	s1.display_copy();

	//Перегрузка оператора присваивания
	shoes* s2 = new shoes(season, 3000);
	strcpy(season, "Зима");
	shoes* s3 = new shoes(season, 5000);
	cout << "\nПосле инициализации\n" << endl;
	s2->display_copy();
	s3->display_copy();
	cout << "\nПосле копирования\n" << endl;
	*s3 = *s2;
	s2->display_copy();
	s3->display_copy();
	s2->set_season(season);
	cout << "\nПосле изменения первого объекта\n" << endl;
	s2->display_copy();
	s3->display_copy();


	cout << "\n Основная программа:\n" << endl;
	// Констркутор без параметров (динамический объект)
	shoes* para1 = new shoes();

	para1->read();

	// Констркутор со всеми параметрами (статический объект)
	store st(kol, 0, 0, para1);
	
	cout << "Работа со статическими переменными\n" << endl;
	cout << "\nПосле ввода\n" << endl;
	st.display();

	// Статический метод
	st.sale();
	cout << "\nПосле продажи\n" << endl;
	st.display();
	st.tax(&taxa);
	st.back();
	cout << "\nПосле возврата\n" << endl;
	st.display();
	sum = add(sum, para1);
	kol = st.get_kol();
	renta = store::rent(st.get_kol());
	cout << "Налог на обувь: \n" << renta << endl;

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



	cout << "\n-------------------------------------------------\n" << endl;
	cout << "\nРабота с динамическим объектом класса\n" << endl;
	shoes* para2 = new shoes();
	para2->read();

	//Конструтор со всеми параметрами (динамический объект)
	store* st2 = new store(kol, 0, 0, para2);
	
	cout << "\nПосле ввода\n" << endl;
	st2->display();
	st2->sale();
	cout << "\nПосле продажи\n" << endl;
	st2->display();
	st2->back();
	cout << "\nПосле возврата\n" << endl;
	st2->display();
	renta = store::rent(st2->get_kol());
	cout << "Налог на обувь: \n" << renta << endl;
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
	}
	store* st3 = new store(kol, 0, 0, para3);


	renta = store::rent(st3->get_kol());
	cout << "\nПосле ввода\n" << endl;
	st3->display();
	st3->sale();
	cout << "\nПосле продажи\n" << endl;
	st3->display();
	st3->back();
	cout << "\nПосле возврата\n" << endl;
	st3->display();
	
	cout << "Налог на обувь: \n" << renta << endl;
	delete st3;
	cout << "\n-------------------------------------------------\n" << endl;
	return 0;
}