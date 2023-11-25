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

	void show_ticket() {
		ifstream f("bile1.bin", ios::binary | ios::in);
		Ticket b;
		Event e;
		b.readingBinary("bile1.bin");

	}


	void verify_id_ticket() {
		{
			int id;
			cout << "Introduce the ticket id you want to verify: ";
			cin >> id;
			ifstream f("bile1.bin");
			Ticket b;
			b.readingBinary("bile1.bin");
			if (id == b.getid_ticket()) {
				cout << "The ticket with id " << id << " exists in the database!" << endl;
			}
			else {
				cout << "The ticket with id " << id << " exists in the database!" << endl;
			}
			f.close();
		}
	}

	void showtype() {
		cout << "Welcome! Select event's type!" << endl;
		cout << "Choose event type:" << endl;
		cout << "1. Movie" << endl;
		cout << "2. Theatre" << endl;
		cout << "3. Sport" << endl;
		cout << "Choose option: ";
		int a;
		cin >> a;
		switch (a) {
		case 1:
			cout << "Ticket type:" << endl;
			cout << "1. Normal" << endl;
			cout << "2. VIP" << endl;
			cout << "Choose ticket's type: ";
			int b;
			cin >> b;
			if (b == 1) {
				cout << "Choose movie at CinemaCity";
				cout << endl;
				cout << "1.After" << endl;
				cout << "2.Titanic" << endl;
				int youroption;
				cin >> youroption;
				if (youroption == 1) {

					cout << "Row 2 to row " << l3.getNrRows() << endl;
					for (int i = 1; i < l3.getNrRows(); i++) {
						cout << "Row " << i + 1 << "has " << l3.getNrSeatsPerRow()[i] << "seats ";
						cout << endl;
					}
					cout << endl;
					int r, s;
					cout << "Row: ";
					cin >> r;
					cout << "Seat: ";
					cin >> s;
					if (r != 1 && s >= 1) {
						if (r <= l3.getNrRows() && s <= l3.getNrSeatsPerRow()[r - 1]) {
							ifstream f("AfterMovie.txt", ios::in);
							int** matrix = new int* [l3.getNrRow()];
							for (int i = 0; i < l3.getNrRow(); i++) {
								matrice[i] = new int[l3.getNrSeatsPerRow()[i]];
							}
							for (int i = 0; i < l3.getNrRows(); i++) {
								for (int j = 0; j < l3.getNrSeatsPerRow()[i]; j++) {
									f >> matrix[i][j];
								}
							}
							f.close();
							if (e1.verify_free_seat(matrix, r, s) == true) {
								matrix[r - 1][s - 1] = 1;

								//write
								ofstream f1("AfterMovie.txt", ios::out);
								for (int i = 0; i < l3.getNrRow(); i++) {
									for (int j = 0; j < l3.getNrSeatsPerRow()[i]; j++) {
										f1 << matrix[i][j] << " ";
									}
									f1 << endl;
								}
								f1.close();
								//verifies the free seats in the matrix


								//Set the event matrix e with the value of the array in the file read
								e1.setMatrix(matrice);
								e1.getMatrix();
								cout << e1;
								ticket(e1, l3, r, s);
							}
							else {
								cout << "The seat is taken!";
							}
						}
						else {
							cout << "You choose a VIP seat. Try again!";
							cout << endl;
						}
					}
					else {
						cout << "Invalid";
						cout << endl;
					}
					break;