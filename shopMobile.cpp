/*taha hasan khosravi
danial saghiri
*/
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;
class Date;
class Time;
class Address;
class User;
class Order;
class Customer;
class Admin;
class Manufacturer;
class Digital_Product;
class CPU;
class SmartPhone;
void font(int);
int Add();
void Showall1();
void Showall2();
void Remove();
void SingUp();
void Hashieyeh();
void menu();
void show();
void Adminmenu();
int LogIn();
void SingUpadmin();
void SingUpcustomer();
void Edit();
void OrderHistory();
void Customermenu();
void Buy();
void IncreaseBalance();
int Exit();
class CPU {
	friend ostream& operator<< (ostream&, CPU&);
	friend istream& operator>> (istream&, CPU&);
public:
	CPU();
	CPU(int, int, int);
	CPU(const CPU&);
	void setBitNum(int);
	void setCoreNum(int);
	void setCache(int);
	int getBitNum();
	int getCoreNum();
	int getCache();
private:
	int bitNum;
	int	coreNum;
	int	cache;
};
class Date {
	friend ostream& operator<< (ostream&, Date&);
	friend istream& operator>> (istream&, Date&);
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int year, int month, int day);
	Date(const Date& obj);
	void setDate(int year, int month, int day);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getDay() const;
	int getMonth()const;
	int getYear() const;
	bool operator==(Date obj);
	bool operator>(Date obj);
	Date operator=(Date obj);
};
class Time {
	friend ostream& operator<< (ostream&, Time&);
	friend istream& operator>> (istream&, Time&);
private:
	int hour;
	int minute;
public:
	Time();
	Time(int, int);
	Time(const Time&);
	void setTime(int, int);
	void setHour(int);
	void setMinute(int);
	int getHour();
	int getMinute();
};
class Address {
	friend ostream& operator<< (ostream&, Address&);
	friend istream& operator>> (istream&, Address&);
private:
	string country;
	long int zipCode;
public:
	Address();
	Address(string, long int);
	Address(const Address&);
	void setCountry(string);
	void setZipCode(long int);
	void setAddress(string, long int);
	string getCountry();
	long int getZipCode();
};
class User {
	friend ostream& operator <<(ostream&, User&);
	friend istream& operator >>(istream&, User&);
public:
	User();
	User(string, int);
	void setUserName(string);
	void setPassword(int);
	string getUserName();
	int getPassword();
	bool checkPassword(int);
private:
	string UserName;
	int password;
};
class Order {
	friend ostream& operator<<(ostream&, Order&);
	friend istream& operator>>(istream&, Order&);
public:
	Order();
	Order(int, Date, Time);
	void setProductID(int);
	void setDate(Date);
	void setTime(Time);
	int getProductID();
	Date getDate();
	Time getTime();
	Order operator=(Order);
private:
	int productID;
	Date date;
	Time time;
};
class Customer : public User {
	friend ostream& operator<<(ostream&, Customer&);
	friend istream& operator>>(istream&, Customer&);
public:
	Customer();
	Customer(string, int, double);
	void setBalance(double);
	double getBalance();
	void showOrderLog();
	void addOrdeLog(Order);
	int getN();
private:
	double balance;
	Order Orderlog[5];
	int n;
};
class Admin :public User {
	friend ostream& operator <<(ostream&, Admin&);
	friend istream& operator >>(istream&, Admin&);
public:
	Admin();
	Admin(string, int);
};
class Manufacturer {
	friend ostream& operator<< (ostream&, Manufacturer&);
	friend istream& operator>> (istream&, Manufacturer&);
public:
	Manufacturer();
	Manufacturer(string, Address);
	Manufacturer(const Manufacturer&);
	void setName(string);
	void setAdd(Address);
	string getName();
	Address getAdd();
private:
	string companyname;
	Address add;
};
class Digital_Product {
	friend ostream& operator<< (ostream&, Digital_Product&);
	friend istream& operator>> (istream&, Digital_Product&);
public:
	Digital_Product();
	Digital_Product(string, double, int, Manufacturer, Date, int);
	Digital_Product(const Digital_Product&);
	void setName(string);
	void setPrice(double);
	void setID(int);
	void setMF(Manufacturer);
	void setDate(Date);
	void setQuantity(int);
	string getName() const;
	double getPrice()const;
	int	getID()const;
	Manufacturer getMF() const;
	Date getDate()const;
	int getQuantity()const;
	void zeroQuantity();
	bool is_available();
private:
	string name;
	double price;
	int ID;
	Manufacturer MF;
	Date date;
	int quantity;
};
class SmartPhone :public Digital_Product {
	friend ostream& operator <<(ostream&, SmartPhone&);
	friend istream& operator >>(istream&, SmartPhone&);
private:
	int storage;
	CPU cpu;
	int ram;
	string OS;
public:
	SmartPhone();
	SmartPhone(string, double, int, Manufacturer, Date, int, int, CPU, int, string);
	SmartPhone(const SmartPhone&);
	void setStorage(int);
	void setCPU(CPU);
	void setRam(int);
	void setOS(string);
	int getStorage() const;
	CPU getCPU() const;
	int getRam() const;
	string getOS() const;
	SmartPhone operator++(int);
	SmartPhone operator++();
	SmartPhone operator=(SmartPhone);
};
CPU::CPU() {
	setBitNum(64);
	setCoreNum(4);
	setCache(64);
}
CPU::CPU(int _BitNum, int _CoreNum, int _Cache) {
	setBitNum(_BitNum);
	setCoreNum(_CoreNum);
	setCache(_Cache);
}
CPU::CPU(const CPU& C) {
	bitNum = C.bitNum;
	coreNum = C.coreNum;
	cache = C.cache;
}
void CPU::setBitNum(int _BitNum) {
	bitNum = _BitNum;
}
void CPU::setCoreNum(int _CoreNum) {
	coreNum = _CoreNum;
}
void CPU::setCache(int _Cache) {
	cache = _Cache;
}
int CPU::getBitNum() {
	return bitNum;
}
int CPU::getCoreNum() {
	return coreNum;
}
int CPU::getCache() {
	return cache;
}
ostream& operator<< (ostream& out, CPU& C) {
	out << C.bitNum << " " << C.coreNum << " " << C.cache;
	return out;
}
istream& operator>> (istream& in, CPU& C) {

	in >> C.bitNum >> C.coreNum >> C.cache;
	return in;
}
Date::Date() {
	setDate(1402, 1, 1);
}
Date::Date(const Date& obj) {
	year = obj.year;
	month = obj.month;
	day = obj.day;
}
Date::Date(int _year, int _month, int _day) {
	setDate(_year, _month, _day);
}
void Date::setDate(int _year, int _month, int _day) {
	setYear(_year);
	setMonth(_month);
	setDay(_day);
}
void Date::setDay(int _day) {
	if (month <= 6) {
		if (_day > 0 && _day <= 31)
			day = _day;
		else
			day = 1;
	}
	else if (month > 6 && month <= 11) {
		if (_day > 0 && _day <= 30)
			day = _day;
		else
			day = 1;
	}
	else {
		if (_day > 0 && _day <= 29)
			day = _day;
		else
			day = 1;
	}
}
void Date::setMonth(int _month) {
	if (_month > 0 && _month <= 12)
		month = _month;
	else
		month = 1;
}
void Date::setYear(int _year) {
	if (_year > 0)
		year = _year;
}
int Date::getDay() const {
	return day;
}
int Date::getMonth()const {
	return month;
}
int Date::getYear() const {
	return year;
}
ostream& operator<< (ostream& out, Date& D) {
	out << D.day << "/" << D.month << "/" << D.year;
	return out;
}
istream& operator>> (istream& in, Date& D) {
	in >> D.day >> D.month >> D.year;
	return in;
}
bool Date::operator==(Date obj) {
	if (day == obj.day && month == obj.month && year == obj.year)
		return true;
	else
		return false;
}
bool Date::operator>(Date obj) {
	bool temp = false;
	if (year > obj.year)
		temp = 1;
	else if (year == obj.year) {
		if (month > obj.month)
			temp = 1;
		else if (month == obj.month) {
			if (day > obj.day)
				temp = 1;
		}
	}
	return temp;
}
Date Date::operator=(Date obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
	return *this;
}
Time::Time() {
	setTime(11, 59);
}
Time::Time(int _hour, int _minute) {
	setTime(_hour, _minute);
}
Time::Time(const Time& T) {
	hour = T.hour;
	minute = T.minute;
}
void Time::setTime(int _hour, int _minute) {
	setHour(_hour);
	setMinute(_minute);
}
void Time::setHour(int _hour) {
	if (_hour >= 0 && _hour < 24)
		hour = _hour;
	else
		hour = 00;
}
void Time::setMinute(int _minute) {
	if (_minute >= 0 && _minute < 60)
		minute = _minute;
	else
		minute = 00;
}
int Time::getHour() {
	return hour;
}
int Time::getMinute() {
	return minute;
}
ostream& operator<< (ostream& out, Time& T) {
	out << T.hour << ":" << T.minute;
	return out;
}
istream& operator>> (istream& in, Time& T) {
	in >> T.hour >> T.minute;
	return in;
}
Address::Address() {
	setAddress("IRAN", 12345678);
}
Address::Address(string _country, long int _zipcode) {
	setAddress(_country, _zipcode);
}
Address::Address(const Address& A) {
	country = A.country;
	zipCode = A.zipCode;
}
void Address::setCountry(string _country) {
	country = _country;
}
void Address::setZipCode(long int _zipcode) {
	if (_zipcode > 0)
		zipCode = _zipcode;
}
void Address::setAddress(string _country, long int _zipcode) {
	setCountry(_country);
	setZipCode(_zipcode);
}
string Address::getCountry() {
	return country;
}
long int Address::getZipCode() {
	return zipCode;
}
ostream& operator<< (ostream& out, Address& A) {
	out << A.country << " " << A.zipCode;
	return out;
}
istream& operator>> (istream& in, Address& A) {
	in >> A.country >> A.zipCode;
	return in;
}
Manufacturer::Manufacturer() {
	setName("esnova :)");
}
Manufacturer::Manufacturer(string _name, Address _add) {
	setName(_name);
	setAdd(_add);
}
Manufacturer::Manufacturer(const Manufacturer& M) {
	companyname = M.companyname;
	add = M.add;
}
void Manufacturer::setName(string _name) {
	companyname = _name;
}
void Manufacturer::setAdd(Address _add) {
	add = _add;
}
string Manufacturer::getName() {
	return companyname;
}
Address Manufacturer::getAdd() {
	return add;
}
ostream& operator<< (ostream& out, Manufacturer& M) {
	out << M.companyname << " " << M.add << " ";
	return out;
}
istream& operator>> (istream& in, Manufacturer& M) {
	in >> M.companyname >> M.add;
	return in;
}

Digital_Product::Digital_Product() {
	setName("esnova1 :)");
	setPrice(0);
	setID(00);
	setQuantity(0);
}
Digital_Product::Digital_Product(string _name, double _price, int _Id, Manufacturer _Mf, Date _date, int _quantity) {
	setName(_name);
	setPrice(_price);
	setID(_Id);
	setMF(_Mf);
	setDate(_date);
	setQuantity(_quantity);
}
Digital_Product::Digital_Product(const Digital_Product& D) {
	name = D.name;
	price = D.price;
	ID = D.ID;
	MF = D.MF;
	date = D.date;
	quantity = D.quantity;
}
void Digital_Product::setName(string _name) {
	name = _name;
}
void Digital_Product::setPrice(double _price) {
	if (_price > 0)
		price = _price;
}
void Digital_Product::setID(int _Id) {
	ID = _Id;
}
void Digital_Product::setMF(Manufacturer _Mf) {
	MF = _Mf;
}
void Digital_Product::setDate(Date _date) {
	date = _date;
}
void Digital_Product::setQuantity(int _quantity) {
	if (_quantity >= 0)
		quantity = _quantity;
}
string Digital_Product::getName()const {
	return name;
}
double Digital_Product::getPrice()const {
	return price;
}
int	Digital_Product::getID()const {
	return ID;
}
Manufacturer Digital_Product::getMF()const {
	return MF;
}
Date Digital_Product::getDate()const {
	return date;
}
int Digital_Product::getQuantity() const {
	return quantity;
}
void Digital_Product::zeroQuantity() {
	quantity = 0;
}
bool Digital_Product::is_available() {
	if (quantity == 0)
		return false;
	else
		return true;
}
ostream& operator<< (ostream& out, Digital_Product& D) {
	out << D.name << " " << D.price << " " << D.ID << " " << D.MF << " " << D.date << " " << D.quantity;
	return out;
}
istream& operator>> (istream& in, Digital_Product& D) {
	in >> D.name >> D.price >> D.ID >> D.MF >> D.date >> D.quantity;
	return in;
}
SmartPhone::SmartPhone() :Digital_Product() {
	setStorage(64);
	setRam(8);
	setOS("Android");
}
SmartPhone::SmartPhone(string _name, double _price, int _id, Manufacturer _mf, Date _date, int _quantity, int _storage, CPU _cpu, int _ram, string _os) :Digital_Product(_name, _price, _id, _mf, _date, _quantity) {
	setStorage(_storage);
	setCPU(_cpu);
	setRam(_ram);
	setOS(_os);
}
SmartPhone::SmartPhone(const SmartPhone& S) {
	setName(S.getName());
	setPrice(S.getPrice());
	setID(S.getID());
	setMF(S.getMF());
	setDate(S.getDate());
	setQuantity(S.getQuantity());
	storage = S.storage;
	cpu = S.cpu;
	ram = S.ram;
	OS = S.OS;
}
void SmartPhone::setStorage(int _storage) {
	if (_storage > 0)
		storage = _storage;
}
void SmartPhone::setCPU(CPU _cpu) {
	cpu = _cpu;
}
void SmartPhone::setRam(int _ram) {
	if (_ram > 0)
		ram = _ram;
}
void SmartPhone::setOS(string _os) {
	OS = _os;
}
int SmartPhone::getStorage()const {
	return storage;
}
CPU SmartPhone::getCPU() const {
	return cpu;
}
int SmartPhone::getRam() const {
	return ram;
}
string SmartPhone::getOS() const {
	return OS;
}
SmartPhone SmartPhone::operator++(int) {
	SmartPhone temp = *this;
	temp.storage = storage + 1;
	temp.ram = ram + 1;
	return temp;
}
SmartPhone SmartPhone::operator++() {
	++storage;
	++ram;
	return *this;
}
SmartPhone SmartPhone::operator=(SmartPhone S) {
	setName(S.getName());
	setPrice(S.getPrice());
	setID(S.getID());
	setMF(S.getMF());
	setDate(S.getDate());
	setQuantity(S.getQuantity());
	storage = S.storage;
	cpu = S.cpu;
	ram = S.ram;
	OS = S.OS;
	return *this;
}
ostream& operator <<(ostream& out, SmartPhone& S) {
	Manufacturer m = S.getMF();
	Date d = S.getDate();
	out << S.getID() << " " << S.getName() << " " << S.getPrice() << " " << m << d << " " << S.getQuantity() << " " << S.storage << " " << S.cpu << " " << S.ram << " " << S.OS << endl;
	return out;
}
istream& operator >>(istream& in, SmartPhone& S) {
	int i;
	string n;
	double p;
	Manufacturer m;
	Date d;
	int q;
	cout << " ID - name - price - Manufacturer(company name - country - zipCode) - date(DD/MM/YY) - quantity - storage(GB) -  cpu   info (bit - core - cache) - ram - OS:" << endl;
	in >> i >> n >> p >> m >> d >> q >> S.storage >> S.cpu >> S.ram >> S.OS;
	S.setID(i);
	S.setName(n);
	S.setPrice(p);
	S.setMF(m);
	S.setDate(d);
	S.setQuantity(q);
	return in;
}
User::User() {
	setPassword(0000);
	setUserName("shatani");
}
User::User(string _username, int _password) {
	setPassword(_password);
	setUserName(_username);
}
void User::setUserName(string _username) {
	UserName = _username;
}
void User::setPassword(int _password) {
	password = _password;
}
string User::getUserName() {
	return UserName;
}
int User::getPassword() {
	return password;
}
bool User::checkPassword(int pascheck) {
	if (password == pascheck)
		return 1;
	else
		return 0;
}
ostream& operator <<(ostream& out, User& U) {
	out << U.UserName << " " << U.password << endl;
	return out;
}
istream& operator >>(istream& in, User& U) {
	cout << "enter username:" << endl;
	in >> U.UserName;
	cout << endl << "enter passwored:" << endl;
	in >> U.password;
	return in;
}
Admin::Admin() :User() {}
Admin::Admin(string _username, int _password) :User(_username, _password) {}
ostream& operator <<(ostream& out, Admin& A) {
	out << A.getUserName() << " " << A.getPassword();
	return out;
}
istream& operator >>(istream& in, Admin& A) {
	string _n;
	int _p;
	cout << "enter username:" << endl;
	in >> _n;
	cout << endl << "enter passwored:" << endl;
	in >> _p;
	A.setPassword(_p);
	A.setUserName(_n);
	return in;
}
Order::Order() {
	setProductID(00);
}
Order::Order(int _productid, Date _date, Time _time) {
	setProductID(_productid);
	setDate(_date);
	setTime(_time);
}
void Order::setProductID(int _productid) {
	productID = _productid;
}
void Order::setDate(Date _date) {
	date = _date;
}
void Order::setTime(Time _time) {
	time = _time;
}
int Order::getProductID() {
	return productID;
}
Date Order::getDate() {
	return date;
}
Time Order::getTime() {
	return time;
}
Order Order::operator=(Order O) {
	setProductID(O.getProductID());
	setDate(O.getDate());
	setTime(O.getTime());
	return *this;
}
ostream& operator <<(ostream& out, Order& O) {
	out << O.productID << " " << O.date << " " << O.time << endl;
	return out;
}
istream& operator >>(istream& in, Order& O) {
	in >> O.productID >> O.date >> O.time;
	return in;
}
Customer::Customer() {
	setBalance(0);
}
Customer::Customer(string _username, int _password, double _balance) {
	setUserName(_username);
	setPassword(_password);
	setBalance(_balance);
}
void Customer::setBalance(double _balance) {
	if (_balance > 0)
		balance = _balance;
}
double Customer::getBalance() {
	return balance;
}
void Customer::showOrderLog() {
	for (int i = 0; i < 5; i++)
	{
		if (Orderlog[i].getProductID() != 00)
			cout << Orderlog[i] << endl;
	}
}
void Customer::addOrdeLog(Order O) {
	bool flag = 0;
	for (int i = 0;i < 5;i++) {
		if (Orderlog[i].getProductID() == 00) {
			Orderlog[i] = O;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		for (int i = 0, j = 1; j < 5; i++, j++)
		{
			Orderlog[i] = Orderlog[j];
		}
		Orderlog[4] = O;
	}
}
int Customer::getN() {
	return n;
}
ostream& operator <<(ostream& out, Customer& C) {
	out << C.getUserName() << " " << C.getPassword() << " " << C.balance << endl;
	return out;
}
istream& operator >>(istream& in, Customer& C) {
	string _n;
	int _p;
	cout << "enter username:" << endl;
	in >> _n;
	cout << endl << "enter passwored:" << endl;
	in >> _p;
	cout << endl << "enter balance:" << endl;
	in >> C.balance;
	C.setUserName(_n);
	C.setPassword(_p);
	return in;
}
void gotoxy(int x, int y)
{
	COORD coord = { 0,0 };
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Maximizewindow()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
SmartPhone M[20];
Admin A[5];
Customer C[10];
int custom;
void Hashieyeh()
{
	for (int i = 0;i < 26;i++)
	{
		for (int j = 0;j < 118;j++)
		{
			if (i == 0 || i == 25 || j == 0 || j == 117)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}
void menu() {
	Maximizewindow();
	system("cls");
	Hashieyeh();
	int a;
	system("color 0A");
	gotoxy(54, 7);
	cout << "1_ Singup";
	gotoxy(54, 11);
	cout << "2_ Login";
	gotoxy(54, 15);
	cout << "3_ Exit";;
	a = _getch() - '0';
	switch (a)
	{
	case(1): {
		SingUp();
	}
		   break;
	case(2): {
		LogIn();
	}
		   break;
	case(3): {
		Exit();
	}
	}
}
int LogIn() {
	system("cls");
	int b = 0;
	User u;
	system("color 01");
	cin >> u;
	for (int i = 0; i < 5; i++)
	{
		if (A[i].getUserName() == u.getUserName()) {
			++b;
			if (A[i].getPassword() == u.getPassword()) {
				Adminmenu();
				return 0;
			}
			else {
				system("color 01");
				cout << "password is not correct";
				Sleep(2000);
				LogIn();
				return 0;
			}

		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (C[i].getUserName() == u.getUserName()) {
			++b;
			if (C[i].getPassword() == u.getPassword()) {
				custom = i;
				Customermenu();
				return 0;
			}
			else {
				cout << "password is not correct";
				Sleep(2000);
				LogIn();
				return 0;
			}

		}
	}
	if (b == 0) {
		cout << "user not foud" << "\n" << "youre backing to menu in two secound.";
		Sleep(2000);
		menu();
		return 0;
	}
}
void SingUp() {
	system("cls");
	int b;
	system("color 0B");
	cout << "1_ Singup as amdin." << "\n2_ Singup as customer";
	b = _getch() - '0';
	switch (b)
	{
	case(1): {
		SingUpadmin();
	}
		   break;
	case(2): {
		SingUpcustomer();
	}
		   break;
	}
}
void SingUpadmin() {
	system("cls");
	Admin temp;
	bool done = 0;
	cin >> temp;
	for (int i = 0; i < 5; i++) {
		if (A[i].getPassword() == 0000) {
			A[i] = temp;
			done = 1;
			break;
		}
	}
	if (done == 0) {
		cout << "admin list is full!!!";
	}
	else {
		cout << "successful" << "\n" << "youre backing to menu in two secound.";
	}
	Sleep(2000);
	menu();
}
void SingUpcustomer() {
	system("cls");
	Customer temp;
	bool done = 0;
	cin >> temp;
	for (int i = 0; i < 10; i++) {
		if (C[i].getPassword() == 0000) {
			C[i] = temp;
			done = 1;
			break;
		}
	}
	if (done == 0) {
		cout << "customer list is full!!!";
	}
	else {
		cout << "successful" << "\n" << "youre backing to menu in two secound.";
	}
	Sleep(2000);
	menu();
}
void Adminmenu() {
	system("cls");
	int F;
	system("color 0C");
	Hashieyeh();
	gotoxy(50, 5);
	cout << "1_ Add phones";
	gotoxy(50, 8);
	cout << "2_ Edit phones";
	gotoxy(50, 11);
	cout << "3_ Remove phones";
	gotoxy(50, 14);
	cout << "4_ Show all phones";
	gotoxy(50, 17);
	cout << "5_ Exit to menu";
	F = _getch() - '0';
	switch (F)
	{
	case(1): {
		Add();
	}
		   break;
	case(2): {
		Edit();
	}
		   break;
	case(3): {
		Remove();
	}
		   break;
	case(4): {
		Showall1();
	}
		   break;
	case(5): {
		menu();
	}
	}
}
int Add() {
	system("cls");
	int n;
	bool b = 0;
	cout << "How much phone you want to add?" << endl;
	cin >> n;
	SmartPhone S;
	for (int i = 0; i < n; i++)
	{
		cin >> S;
		for (int i = 0;i < 20;i++) {
			if (M[i].getQuantity() == 0) {
				M[i] = S;
				cout << "successful!" << endl;
				b = 1;
				break;
			}
		}
		if (b == 0) {
			cout << "list is full" << "\n youre backing to adminmenu in to two second" << endl;
			Sleep(2000);
			Adminmenu();
			return 0;
		}
	}
	cout << " youre backing to adminmenu in to two second";
	Sleep(2000);
	Adminmenu();
	return 0;
}
void Edit() {
	system("cls");
	show();
	int _Id;
	bool b = 0;
	SmartPhone S;
	cout << "enter id what you want to change:" << endl;
	cin >> _Id;
	for (int i = 0; i < 20; i++) {
		if (M[i].getID() == _Id) {
			cin >> S;
			M[i] = S;
			b = 1;
			cout << "successful!" << endl;
			break;
		}
	}
	if (b == 0)
		cout << "id not found" << "\n youre backing to adminmenu in to two second" << endl;
	else
		cout << " youre backing to adminmenu in to two second";
	Sleep(2000);
	Adminmenu();
}
void Remove() {
	system("cls");
	show();
	int _Id;
	SmartPhone S;
	bool C = 0;
	cout << "enter id what you want to delete:" << endl;
	cin >> _Id;
	for (int i = 0; i < 20; i++) {
		if (M[i].getID() == _Id)
			C = 1;
		if (C == 1) {
			M[i] = M[i + 1];
		}
	}
	M[19] = S;
	if (C == 1) {
		cout << "successful!" << endl;
		cout << " youre backing to adminmenu in to two second";
	}
	else
		cout << "id not found" << "\n youre backing to adminmenu in to two second" << endl;
	Sleep(2000);
	Adminmenu();
}
void Showall1() {
	system("cls");
	int x = 1;
	char a;
	for (int i = 0; i < 20; i++)
	{
		if (M[i].getQuantity() != 0) {
			cout << x << "_ " << M[i];
			++x;
		}
	}
	cout << "press any key to back to menu:" << endl;
	a = _getch() - '0';
	cout << " youre backing to adminmenu in to two second";
	Sleep(2000);
	Adminmenu();
}
void Showall2() {
	system("cls");
	int x = 1;
	char a;
	for (int i = 0; i < 20; i++)
	{
		if (M[i].getQuantity() != 0) {
			cout << x << "_ " << M[i];
			++x;
		}
	}
	cout << "press any key to back to menu:" << endl;
	a = _getch() - '0';
	cout << " youre backing to Customermenu in to two second";
	Sleep(2000);
	Customermenu();
}
void Customermenu() {
	system("cls");
	int F;
	system("color 0D");
	Hashieyeh();
	gotoxy(50, 5);
	cout << "1_ Buy";
	gotoxy(50, 8);
	cout << "2_ Increase balance";
	gotoxy(50, 11);
	cout << "3_ Order history";
	gotoxy(50, 14);
	cout << "4_ Show all phones";
	gotoxy(50, 17);
	cout << "5_ Exit to menu";
	F = _getch() - '0';
	switch (F)
	{
	case(1): {
		Buy();
	}
		   break;
	case(2): {
		IncreaseBalance();
	}
		   break;
	case(3): {
		OrderHistory();
	}
		   break;
	case(4): {
		Showall2();
	}
		   break;
	case(5): {
		menu();
	}
	}
}
void show() {
	int x = 1;
	char a;
	for (int i = 0; i < 20; i++)
	{
		if (M[i].getQuantity() != 0) {
			cout << x << "_ " << M[i] << endl;
			++x;
		}
	}
}
void Buy() {
	system("cls");
	show();
	int a;
	bool d = 0, r = 0;
	Date D;
	Time T;
	cout << "enter id what you want to buy:" << endl;
	cin >> a;
	for (int i = 0; i < 20; i++) {
		if (M[i].getID() == a) {
			d = 1;
			if (C[custom].getBalance() >= M[i].getPrice()) {
				C[custom].setBalance(C[custom].getBalance() - M[i].getPrice());
				M[i].setQuantity(M[i].getQuantity() - 1);
				Order shop(a, D, T);
				C[custom].addOrdeLog(shop);
				cout << "successful!"<<endl;
			}
			else {
				r = 1;
			}
		}

	}
	if (r == 1)
		cout << "not enogh mony :(" << endl;
	if (d == 0)
		cout << "not currect id!" << endl;
	cout << " youre backing to adminmenu in to two second";
	Sleep(2000);
	Customermenu();
}
void IncreaseBalance() {
	system("cls");
	int a;
	cout << "how much do yo want to increase?" << endl;
	cin >> a;
	C[custom].setBalance(C[custom].getBalance() + a);
	cout << " youre backing to customermenu in to two second";
	Sleep(2000);
	Customermenu();
}
void OrderHistory() {
	char a;
	system("cls");
	C[custom].showOrderLog();
	cout << "press any key to back to menu:" << endl;
	a = _getch() - '0';
	cout << " youre backing to customermenu in to two second";
	Sleep(2000);
	Customermenu();
}
int Exit() {
	system("cls");
	Hashieyeh();
	gotoxy(38, 12);
	system("color 01");
	cout << "HOPE YOU ENJOYED!SEE YOU IN A ANOTHER FIELD";
	gotoxy(0, 25);
	Sleep(2000);
	return 0;
}
void font(int y) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   
	cfi.dwFontSize.Y = y;                  
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); 
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
int main() {
	font(28);
	menu();
}