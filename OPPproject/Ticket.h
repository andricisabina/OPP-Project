#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include "Location.h"
#include "Event.h"
#include <list>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

enum ticket_type { vip, normal, category1, category2, lodge, lawn, tribune1, tribune2 };

class Ticket {
private:
	char* client_name;
	float ticket_price;
	int nr_seat;
	int nr_row;
	int nr_ticket;
	Event even;
	Location seat;
	const int nr_sold_ticket_day;
	static int nr_tickets;
	ticket_type type;
	int age;
	int ticket_id;



public:

	//default constructor

	Ticket() :nr_sold_ticket_day(nr_tickets++) {
		client_name = new char[strlen("A") + 1];
		strcpy_s(client_name, strlen("A") + 1, "A");
		ticket_price = 0;
		nr_seat = 0;
		nr_row = 0;
		type = normal;
		age = 0;

	}

	//constructor with parameters

	Ticket(const char* client_name, int age, int nr_seat, int nr_row, ticket_type type, Event even) :nr_sold_ticket_day(nr_tickets++) {
		this->client_name = new char[strlen(client_name) + 1];
		strcpy_s(this->client_name, strlen(client_name) + 1, client_name);
		this->nr_seat = nr_seat;
		this->nr_row = nr_row;
		this->type= type;
		this->even = even;
		this->age = age;
		if (age < 7) {
			this->ticket_price = 0;
		}
		else {
			if (type == vip) {
				this->ticket_price = 100;
			}
			if (type == normal) {
				this->ticket_price = 50;
			}
			if (type == category1) {
				this->ticket_price = 40;
			}
			if (type == category2) {
				this->ticket_price = 30;
			}
			if (type == lodge) {
				this->ticket_price = 20;
			}
			if (type == lawn) {
				this->ticket_price = 10;
			}
			if (type == tribune1) {
				this->ticket_price = 5;
			}
			if (type == tribune2) {
				this->ticket_price = 2;
			}
		}

	}





	Ticket(const Ticket& b) :nr_sold_ticket_day(nr_ticket++) {
		this->client_name = new char[strlen(b.client_name) + 1];
		strcpy_s(this->client_name, strlen(b.client_name) + 1, b.client_name);
		this->ticket_price = b.ticket_price;
		this->nr_seat = b.nr_seat;
		this->nr_row = b.nr_row;
		this->even = b.even;
		this->type = b.type;
		this->age = b.age;

	}

	//overloading the operator


	Ticket& operator=(const Ticket& b) {
		if (this != &b) {
			if (this->client_name != NULL)
				delete[] this->client_name;
			this->client_name = nullptr;
			this->client_name = new char[strlen(b.client_name) + 1];
			strcpy_s(this->client_name, strlen(b.client_name) + 1, b.client_name);
			this->ticket_price = b.ticket_price;
			this->nr_seat = b.nr_seat;
			this->nr_row = b.nr_row;
			this->even = b.even;
			this->type = b.type;
			this->age = b.age;
		}
		return *this;
	}

	//setters and gatters

	void setClientName(const char* client_name) {
		if (this->client_name != NULL)
			delete[] this->client_name;
		this->client_name = new char[strlen(client_name) + 1];
		strcpy_s(this->client_name, strlen(client_name) + 1, client_name);
	}

	char* getClientName() {
		char* copy = new char[strlen(this->client_name) + 1];
		strcpy_s(copy, strlen(this->client_name) + 1, this->client_name);
		return copy;
	}

	void setTicketPrice(float ticket_price) {
		if (ticket_price) {
			this->ticket_price = ticket_price;
		}
	}

	float getTicketPrice() {
		return this->ticket_price;
	}

	void setNrSeat(int nr_seat) {
		this->nr_seat = nr_seat;
	}

	int getNrSeat() {
		return this->nr_seat;
	}

	void setNrRow(int nr_row) {
		this->nr_row = nr_row;
	}

	void setAge(int age) {
		this->age = age;
	}

	void setType(ticket_type type) {
		this->type = type;
	}

	ticket_type getType() {
		return this->type;
	}

	int getage() {
		return this->age;
	}

	int getNrRow() {
		return this->nr_row;
	}

	void setEvent(Event even) {
		this->even = even;
	}


	Event getEvent() {
		return this->even;
	}

	void setLocation(Location seat) {
		this->seat = seat;
	}

	Location getLocation() {
		return this->seat;
	}

	int getNrSoldTicketDay() {
		return this->nr_sold_ticket_day;
	}

	int getticket_id() {
		return this->ticket_id;
	}

	//destructor 
	~Ticket() {
		if (this->client_name != NULL)
			delete this->client_name;
	}

	//voucher_git

	void voucher_gift(float price, int voucher_code) {
		if (voucher_code == 1234) {
			this-> ticket_price = price - (price * 10 / 100);
			cout << "The discounted price is: " << ticket_price << endl;
		}
		else {
			cout << "The voucher code is wrong.You don't have a discount yet! :( ";
		}
	}

	//metoda discount
	void applydiscount(int age) {
		if (age >= 7 && age < 14) {
			ticket_price = ticket_price - (ticket_price * 20 / 100);
			cout << "The discounted price for teens is: " << ticket_price << endl;
		}
	}


	//reading binary


	void readingBinary(string name) {
		ifstream h(name, ios::in | ios::binary);
		if (h.is_open()) {
			if (this-> client_name != NULL)
			{
				delete[] this-> client_name;
			}
			int dimNume = 0;
			h.read((char*)&dimNume, sizeof(dimNume));
			this->client_name = new char[dimNume + 1];
			h.read(this->client_name, static_cast<std::streamsize>(dimNume) + 1);
			cout << "Client name: " << this->client_name << endl;
			h.read((char*)&this->nr_seat, sizeof(this->nr_seat));
			cout << "Seat: " << this->nr_seat << endl;
			h.read((char*)&this->nr_row, sizeof(this->nr_row));
			cout << "Row: " << this->nr_row << endl;
			//reading ticket_id
			h.read((char*)&this->ticket_id, sizeof(this->ticket_id));
			cout << "ID: " << this->ticket_id << endl;

		}
	}

	//writing binary

	void writingBinary(string name) {
		ofstream h(name, ios::out | ios::binary);
		if (h.is_open()) {
			int dimName = strlen(this->client_name);
			h.write((char*)&dimName, sizeof(dimName));
			h.write(this->client_name, static_cast<std::streamsize>(dimName) + 1);
			h.write((char*)&this->nr_seat, sizeof(this->nr_seat));
			h.write((char*)&this->nr_row, sizeof(this->nr_row));
			this->ticket_id = getId();
			h.write((char*)&this->ticket_id, sizeof(this->ticket_id));
		}
	}



	//operator cast

	explicit operator float() {
		return this->ticket_price;
	}

	//operator -
	Ticket operator-(int value) {
		Ticket copy = *this;
		copy.ticket_price = copy.ticket_price - 10;
		return copy;
	}


	int getId() {
		this->ticket_id = id();
		return this->ticket_id;
	}

	//aici am scris o metoda de generare bilet cu id aleator

	int id() {

		srand((unsigned)time(NULL));

		for (int i = 1; i <= 5; i++) {
			int random = 100 + (rand() % 101);
			return random;

		}
	}


	//aici am inceput sa ma gandesc cum sa abordez faza 2, in acre trebuie sa verific daca biletul este valid
	//iau in calcul crearea unui vector in care sa salvez id-urile create si apoi sa verific daca id-ul biletului introdus este valid, prin compararea cu elementele din vector


	//void verifica_bilet_valid(const int id_bil) {
	//	if (this->id_bilet == id_bil) cout << "ID VALID";
	//	else cout << "ID INVALID";
	//}




	//overloading the operators

	friend ostream& operator<<(ostream& out, Ticket b);
	friend istream& operator>>(istream& in, Ticket& b);

};
int Ticket::nr_tickets = 0;

ostream& operator<<(ostream& out, Ticket b)
{
	out << "Client name: " << b.client_name << endl;
	out << "Age: " << b.age << endl;
	out << "Ticket price: " << b.ticket_price << endl;
	out << "Number seat: " << b.nr_seat << endl;
	out << "Number row: " << b.nr_row << endl;
	switch (b.tip) {
	case 0:out << "Ticket type: vip" << endl; break;
	case 1:out << "Ticket type: normal" << endl; break;
	case 2:out << "Ticket type: category1 " << endl; break;
	case 3:out << "Ticket type: category2 " << endl; break;
	case 4:out << "Ticket type: lodge " << endl; break;
	case 5:out << "Ticket type: tribune1 " << endl; break;
	case 6:out << "Ticket type: tribune2 " << endl; break;
	case 7:out << "Ticket type: lawn " << endl; break;
	}
	out << "Event: " << b.even;
	out << "Ticket id: " << b.getId() << endl;
	out << " Sold tickets today: " << b.nr_sold_ticket_day << endl;
	return out;

}



istream& operator>>(istream& in, Ticket& b)
{
	cout << "The client name is: ";
	char buffer[50];
	in >> buffer;
	if (b.client_name!= NULL)
		delete b.client_name;
	b.client_name = new char[strlen(buffer) + 1];
	strcpy_s(b.client_name, strlen(buffer) + 1, buffer);
	cout << "Age";
	in >> b.age;
	cout << "The price ticket is: ";
	in >> b.ticket_price;
	cout << "The number of seat is: ";
	in >> b.nr_seat;
	cout << "The number of row is: ";
	in >> b.nr_row;
	cout << "The ticket type is: ";
	string ticket_type;
	in >> ticket_type;
	if (ticket_type == "normal")
		b.type = normal;
	else if (ticket_type == "vip")
		b.type = vip;
	else if (ticket_type == "category1")
		b.type = category1;
	else if (ticket_type == "category2")
		b.type = category2;
	else if (ticket_type == "lodge")
		b.type = lodge;
	else if (ticket_type == "lawn")
		b.type = lawn;
	else if (ticket_type == "tribune1")
		b.type = tribune1;
	else if (ticket_type == "tribune2")
		b.type = tribune2;

	cout << "The event is: ";
	in >> b.even;

	return in;
}













