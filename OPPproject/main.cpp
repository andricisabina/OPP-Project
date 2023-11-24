#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <string.h>
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include <vector>

using namespace std;
Location l3(3, new int[3] { 5, 6, 7 }, 3, 3);
Event e1("After", film, "11/02/2022", "13:00", l3, 100);
Event e2("Titanic", film, "11/02/2022", "13:00", l3, 100);
Location l4(3, new int[3] { 7, 7, 7 }, 3, 3);
Location l5(3, new int[3] { 7, 7, 7 }, 3, 3);
TheatreEvent e3("Nebuni din dragoste", theatre, "11/02/2022", "13:00", l4, 100, "Mara Morgeinstein~Ionut Bobonete");
Event e5("Steaua-Dinamo", sport, "11/02/2022", "13:00", l5, 100);

void Ticket(Event e1, Location l1, int seat, int row{
	cout << "Create a ticket" << endl;
	char* client_name;
	client_name = new char[20];
	cout << "Introduce the client's name:";
	cin >> client_name;
	int age;
	cout << "Introduce the client's age: ";
	cin >> age;
	Ticket b1(client_name, age, seat, row, normal, e1);
	cout << b1;
	ofstream m;
	m.open("Saved Tickets");
	m << b1;
	m.close();
	b1.writingBinary("bile1.bin");
	cout << "-----------";
	cout << "The ticket was successfully created!" << endl;
	cout << "-----------";
	ifstream f("bile1.bin", ios::binary | ios::in);
	Ticket b;
	Event e;
	b.readingBinary("bile1.bin");

	}