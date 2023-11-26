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
Event e1("After", movie, "11/02/2022", "13:00", l3, 100);
Event e2("Titanic", movie, "11/02/2022", "13:00", l3, 100);
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

	void show_tickets() {
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
							int** matrix = new int* [l3.getNrRows()];
							for (int i = 0; i < l3.getNrRows(); i++) {
								matrix[i] = new int[l3.getNrSeatsPerRow()[i]];
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
								for (int i = 0; i < l3.getNrRows(); i++) {
									for (int j = 0; j < l3.getNrSeatsPerRow()[i]; j++) {
										f1 << matrix[i][j] << " ";
									}
									f1 << endl;
								}
								f1.close();
								//verifies the free seats in the matrix


								//Set the event matrix e with the value of the array in the file read
								e1.setMatrix(matrix);
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
				}
				if (b == 2) {
					cout << "Alege film la CinemaCity";
					cout << endl;
					cout << "1.After" << endl;
					cout << "2.Titanic" << endl;
					int youroption2;
					cin >> youroption2;
					if (youroption2 == 1) {
						cout << "Row 1,seats from 1 to " << l3.getNrSeatsPerRow()[0] << endl;
						cout << endl;
						int m, n;
						cout << "Row: ";
						cin >> m;
						cout << "Seat";
						cin >> n;
						if (m == 1 && n >= 1 && n <= l3.getNrSeatsPerRow()[m - 1]) {
							ifstream f("AfterMovie.txt", ios::in);
							int** matrix = new int* [l3.getNrRows()];
							for (int i = 0; i < l3.getNrRows(); i++) {
								matrix[i] = new int[l3.getNrSeatsPerRow()[i]];
							}
							for (int i = 0; i < l3.getNrRows(); i++) {
								for (int j = 0; j < l3.getNrSeatsPerRow()[i]; j++) {
									f >> matrix[i][j];
								}
							}
							f.close();
							if (e1.verify_free_seat(matrix, m, n) == true) {
								matrix[m - 1][n - 1] = 1;
								ofstream f1("AfterMovie.txt", ios::out);
								for (int i = 0; i < l3.getNrRows(); i++) {
									for (int j = 0; j < l3.getNrSeatsPerRow()[i]; j++) {
										f1 << matrix[i][j] << " ";
									}
									f1 << endl;
								}
								f1.close();
								e1.setMatrix(matrix);
								e1.getMatrix();
								cout << e1;

								ticket(e1, l3, m, n);
							}
							else {
								cout << "The seat is taken!";
							}
						}
						else {
							cout << "You didn't choose a VIP seat";
							cout << endl;
						}
						break;
					}
					if (youroption2 == 2) {
						cout << "Row 1, seats from 1 to " << l3.getNrSeatsPerRow()[0] << endl;
						cout << endl;
						int mn, nm;
						cout << "Row: ";
						cin >> mn;
						cout << "Seat: ";
						cin >> nm;
						if (mn == 1 && nm >= 1 && nm <= l3.getNrSeatsPerRow()[mn - 1]) {
							ifstream f("Titanic.txt", ios::in);
							int** matrix = new int* [l3.getNrRows()];
							for (int i = 0; i < l3.getNrRows(); i++) {
								matrix[i] = new int[l3.getNrSeatsPerRow()[i]];
							}
							for (int i = 0; i < l3.getNrRows(); i++) {
								for (int j = 0; j < l3.getNrSeatsPerRow()[i]; j++) {
									f >> matrix[i][j];
								}
							}
							f.close();
							if (e2.verify_free_seat(matrix, mn, nm) == true) {
								matrix[mn - 1][nm - 1] = 1;
								ofstream f1("Titanic.txt", ios::out);
								for (int i = 0; i < l3.getNrRows(); i++) {
									for (int j = 0; j < l3.getNrSeatsPerRow()[i]; j++) {
										f1 << matrix[i][j] << " ";
									}
									f1 << endl;
								}
								f1.close();
								e2.setMatrix(matrix)
								e1.getMatrix (
								cout << e2;
								ticket (e2, l3, mn, nm);
							}
							else {
								cout << "The seat is taken";
							}
						}
						else {
							cout << "You didn't choose a VIP seat";
							cout << endl;
						}

					}
					break;
				}

				break;

		case 2:

			cout << "Ticket type:" << endl;
			cout << "1. Category 1" << endl;
			cout << "2. Category 2" << endl;
			cout << "3. Lodge" << endl;
			int c;
			cin >> c;
			if (c == 1) {
				cout << "Choose the play at TNB";
				cout << endl;
				cout << "1.Nebuni din dragoste" << endl;
				int option4;
				cin >> option4;
				if (option4 == 1) {
					cout << "Rows 1,2 without 1st seat, where there are: " << l4.getNrRows() << " rows" << endl;
					cout << endl;
					int ft, t;
					cout << "Row: ";
					cin >> t;
					cout << "Seat: ";
					cin >> ft;
					if (t == 1 || t == 2 && ft != 1 && ft <= l4.getNrSeatsPerRow()[t - 1]) {
						ifstream f("Nebuni.txt", ios::in);
						int** matrix = new int* [l4.getNrRows()];
						for (int i = 0; i < l4.getNrRows(); i++) {
							matrix[i] = new int[l4.getNrSeatsPerRow()[i]];
						}
						for (int i = 0; i < l4.getNrRows(); i++) {
							for (int j = 0; j < l4.getNrSeatsPerRow()[i]; j++) {
								f >> matrix[i][j];
							}
						}
						f.close();
						if (e3.verify_free_seat(matrix, ft, t) == true) {
							matrix[t - 1][ft - 1] = 1;
							ofstream f1("Nebuni.txt", ios::out);
							for (int i = 0; i < l4.getNrRows(); i++) {
								for (int j = 0; j < l4.getNrSeatsPerRow()[i]; j++) {
									f1 << matrix[i][j] << " ";
								}
								f1 << endl;
							}
							f1.close();
							e3.setMatrix(matrix);
							e3.getMatrix();
							cout << e3;
							ticket(e3, l4, ft, t);
						}
						else {
							cout << "The seat is taken!";
						}
					}
					else {
						cout << "The seat is not available!" << endl;
					}
				}
				break;
			}
			if (c == 2) {
				cout << "Choose the play at TNB";
				cout << endl;
				cout << "1.Nebuni din dragoste" << endl;
				int option5;
				cin >> option5;
				if (option5 == 1) {
					cout << "All seats, without rows 1 and 2 and 1st seat in all rows, where there are: " << l4.getNrRows() << " rows" << endl;
					cout << endl;
					int u, p;
					cout << "Row: ";
					cin >> u;
					cout << "Seat: ";
					cin >> p;
					if (p > 1 && p < -l4.getNrSeatsPerRow()[u - 1] && u>2 && u <= l4.getNrRows()) {
						ifstream f("Nebuni.txt", ios::in);
						int** matrix = new int* [l4.getNrRows()];
						for (int i = 0; i < l4.getNrRows(); i++) {
							matrix[i] = new int[l4.getNrSeatsPerRow()[i]];
						}
						for (int i = 0; i < l4.getNrRows(); i++) {
							for (int j = 0; j < l4.getNrSeatsPerRow()[i]; j++) {
								f >> matrix[i][j];
							}
						}
						f.close();
						if (e3.verifiy_free_seat(matrix, u, p) == true) {
							matrix[u - 1][p - 1] = 1;
							ofstream f1("Nebuni.txt", ios::out);
							for (int i = 0; i < l4.getNrRows(); i++) {
								for (int j = 0; j < l4.getNrSeatsPerRow()[i]; j++) {
									f1 <<matrix[i][j] << " ";
								}
								f1 << endl;
							}
							f1.close();
							e3.setMatrix(matrix);
							e3.getMatrix();
							cout << e3;
							ticket(e3, l4, p, u);
						}
						else {
							cout << "The seat is taken!";
						}
					}
					else {
						cout << "The seat is not available!" << endl;

					}
				}
				break;
			}

			if (c == 3) {
				cout << "Choose the play at TNB";
				cout << endl;
				cout << "1.Nebuni din dragoste" << endl;
				int option6;
				cin >> option6;
				if (option6 == 1) {
					cout << "1st seat on each row, where there is: " << l4.getNrRows() << "rows" << endl;
					cout << endl;
					int k, j;
					cout << "Row: ";
					cin >> k;
					cout << "Seat: ";
					cin >> j;
					if (j == 1 && k >= 1 && k <= l4.getNrRows()) {
						ifstream f("Nebuni.txt", ios::in);
						int** matrix = new int* [l4.getNrRows()];
						for (int i = 0; i < l4.getNrRows(); i++) {
							matrix[i] = new int[l4.getNrSeatsPerRow()[i]];
						}
						for (int i = 0; i < l4.getNrRows(); i++) {
							for (int j = 0; j < l4.getNrSeatsPerRow()[i]; j++) {
								f >> matrix[i][j];
							}
						}
						f.close();
						if (e3.verify_free_seat(matrix, k, j) == true) {
							matrix[k - 1][j - 1] = 1;
							ofstream f1("Nebuni.txt", ios::out);
							for (int i = 0; i < l4.getNrRows(); i++) {
								for (int j = 0; j < l4.getNrSeatsPerRow()[i]; j++) {
									f1 << matrix[i][j] << " ";
								}
								f1 << endl;
							}
							f1.close();
							e3.setMatrix(matrix);
							e3.getMatrix();
							cout << e3;
							ticket(e3, l4, k, j);
						}
						else {
							cout << "The seat is taken!";
						}
					}
					else {
						cout << "The seat is not available!" << endl;
					}
				}
			}
			break;


		case 3:
			cout << "Ticket typet:" << endl;
			cout << "1. Lawn" << endl;
			cout << "2. Tribune 1" << endl;
			cout << "3. Tribune 2" << endl;
			int d;
			cin >> d;
			if (d == 1) {
				cout << "Choose sport event:";
				cout << endl;
				cout << "1.Meci Steaua- Dinamo" << endl;
				int option7;
				cin >> option7;
				if (option7 == 1) {
					cout << "First and last seat on each row where there is: " << endl;
					for (int i = 0; i < l5.getNrRows(); i++) {
						cout << "Row " << i + 1 << "has" << l5.getNrSeatsPerRow()[i] << "seats ";
						cout << endl;
					}
					int v, o;
					cout << "Row: ";
					cin >> v;
					cout << "Seat: ";
					cin >> o;
					if (o == 1 || o == l5.getNrSeatsPerRow()[v - 1] && v >= 1 && v <= l5.getNrRows()) {
						ifstream f("Meci.txt", ios::in);
						int** matrix = new int* [l5.getNrRows()];
						for (int i = 0; i < l5.getNrRows(); i++) {
							matrix[i] = new int[l5.getNrSeatsPerRow()[i]];
						}
						for (int i = 0; i < l5.getNrRows(); i++) {
							for (int j = 0; j < l5.getNrSeatsPerRow()[i]; j++) {
								f >> matrix[i][j];
							}
						}
						f.close();
						if (e5.verify_free_seat(matrix, v, o) == true) {
							matrixe[v - 1][o - 1] = 1;
							ofstream f1("Meci.txt", ios::out);
							for (int i = 0; i < l5.getNrRows(); i++) {
								for (int j = 0; j < l5.getNrSeatsPerRow()[i]; j++) {
									f1 << matrix[i][j] << " ";
								}
								f1 << endl;
							}
							f1.close();
							e5.setMatrix(matrix);
							e5.getMatrix();
							cout << e5;
							ticket(e5, l5, v, o);
						}
						else {
							cout << "The seat is taken!";
						}
					}
					else {
						cout << "You didn't choose Lawn seat";
						cout << endl;
					}

				}
				if (d == 2) {
					cout << "Choose sport event:";
					cout << endl;
					cout << "1.Meci Steaua- Dinamo" << endl;
					int option8;
					cin >> option8;
					if (option8 == 1) {

						for (int i = 0; i < l5.getNrRows() - 1; i++) {
							cout << "Randul " << i + 1 << " locurile 2-" << l5.getNrSeatsPerRow()[i] - 1;
							cout << endl;
						}
						int q, w;
						cout << "Row: ";
						cin >> q;
						cout << "Seat: ";
						cin >> w;
						if (q >= 1 && q <= l5.getNrRows() - 1 && w > 1 && w < l5.getNrSeatsPerRow()[q - 1]) {
							ifstream f("Meci.txt", ios::in);
							int** matrix = new int* [l5.getNrRows()];
							for (int i = 0; i < l5.getNrRows(); i++) {
								matrix[i] = new int[l5.getNrSeatsPerRow()[i]];
							}
							for (int i = 0; i < l5.getNrRows(); i++) {
								for (int j = 0; j < l5.getNrSeatsPerRow()[i]; j++) {
									f >> matrix[i][j];
								}
							}
							f.close();
							if (e5.verify_free_seat(matrix, q, w) == true) {
								matrix[q - 1][w - 1] = 1;
								ofstream f1("Meci.txt", ios::out);
								for (int i = 0; i < l5.getNrRows(); i++) {
									for (int j = 0; j < l5.getNrSeatsPerRow()[i]; j++) {
										f1 << matrix[i][j] << " ";
									}
									f1 << endl;
								}
								f1.close();
								e5.setMatrix(matrix);
								e5.getMatrix();
								cout << e5;
								ticket(e5, l5, q, w);
							}
							else {
								cout << "The seat is taken!";
							}
						}
						else {
							cout << "You didn't choose a seat at Tribune1";
							cout << endl;
						}
					}
					break;
				}
				if (d == 3) {
					cout << "Choose sport event:";
					cout << endl;
					cout << "1.Meci Steaua- Dinamo" << endl;
					int option9;
					cin >> option9;
					if (option9 == 1) {
						int f = l5.getNrRows();
						cout << "Row " << f << " seats from 2 to " << l5.getNrSeatsPerRow()[f - 1] - 1;
						cout << endl;
						int ab, cd;
						cout << "Row: ";
						cin >> ab;
						cout << "Sear: ";
						cin >> cd;
						if (ab == l5.getNrRow() && cd > 1 && cd <= l5.getNrSeatsPerRow()[ab - 1] - 1) {
							ifstream f("Meci.txt", ios::in);
							int** matrix = new int* [l5.getNrRows()];
							for (int i = 0; i < l5.getNrRows(); i++) {
								matrix[i] = new int[l5.getNrSeatsPerRow()[i]];
							}
							for (int i = 0; i < l5.getNrRows(); i++) {
								for (int j = 0; j < l5.getNrSeatsPerRow()[i]; j++) {
									f >> matrix[i][j];
								}
							}
							f.close();
							if (e5.verify_free_seat(matrix, ab, cd) == true) {
								ofstream f1("Meci.txt", ios::out);
								for (int i = 0; i < l5.getNrRows(); i++) {
									for (int j = 0; j < l5.getNrSeatsPerRow()[i]; j++) {
										f1 << matrix[i][j] << " ";
									}
									f1 << endl;
								}
								f1.close();
								e5.setMatrix(matrix);
								e5.getMatrix();
								cout << e5;
								ticket(e5, l5, ab, cd);
							}
							else {
								cout << "The seat is taken!";
							}
						}
						else {
							cout << "You didn't choose seat at Tribune2";
							cout << endl;
						}

					}
				}
				break;
			}
			break;
			}

		}



		void reading_from_files() {

			//reads data and creates ticket

			std::ifstream f("Locatii.txt");
			int nr_rows;
			f >> nr_rows;
			int* nr_seats_per_row = new int[nr_row];
			for (int i = 0; i < nr_row; i++) {
				f >> nr_seats_per_row[i];
			}
			int nr_extinguishers;
			f >> nr_extinguishers;
			int urgent_exits;
			f >> urgent_exits;
			Location location(nr_rows, nr_seats_per_row, nr_extinguishers, urgent_exits);
			f.close();


			std::ifstream f1("Eveniment.txt");
			char* nume = new char[20];
			f1 >> nume;
			string date;
			f1 >> date;
			string time;
			f1 >> time;
			int duration;
			f1 >> duration;
			Event event(name, date, time, location, duration);
			f1.close();


			//reads client name, age, seat, row, ticket type,event type


			std::ifstream f2("Bilete.txt");
			char* client_name = new char[20];
			f2 >> client_name;
			int age;
			f2 >> age;
			int row;
			f2 >> row;
			int seat;
			f2 >> seat;
			string type;
			f2 >> type;
			ticket_type typet;
			if (type == "vip") {
				typet = vip;
			}
			else if (type == "normal") {
				typet = normal;
			}
			else if (type == "lawn") {
				typet = lawn;
			}

			Ticket ticket1(client_name, age, row, seat, typet, event);
			event.takeseat(location, row, seat);
			f2.close();





		}





		void lansare_console_txt() {

			int optiune;
			int r;
			cout << "1. Main" << endl;
			cout << "2. Main dat.txt" << endl;
			cout << "Option: ";
			cin >> option;
			if (option == 1) {
				showtype();
				cout << "Continue? ";
				cout << "1.YES";
				cout << "2.NO";
				cin >> r;
				while (r == 1) {
					showtype();
					cin >> r;
				}

			}
			else if (option == 2) {
				reading_from_files();
			}
			else {
				cout << "The option doesn't exist" << endl;
			}

		}


		void small_menu() {
			cout << "---------------------------------";
			cout << endl;
			cout << " Welcome to YourTicket! ";
			cout << endl;
			cout << "---------------------------------";
			cout << endl;
			cout << "Are you an administrator or a client? ";
			cout << endl;
			cout << "----------------------------------";
			cout << endl;
			cout << "1. Administrator";
			cout << endl;
			cout << "2. Client";
			cout << endl;
			cout << "Option: ";
			int a;
			cin >> a;
			switch (a)
			{
			case 1:
				cout << "Choose option: ";
				cout << "1.Show available tickets!";
				cout << endl;
				cout << "2.Verify if the ID is valid!";
				cout << endl;
				cout << "3.Create a location!";
				cout << endl;
				cout << "4.Create an event!";
				int gr;
				cin >> gr;
				if (gr == 1) {
					show_tickets();
				}
				if (gr == 2) {
					int h;
					cin >> h;
					verify_tickets_id();
				}
				if (gr == 3) {
					int nr_rows;
					cout << "Introduce the rows' number: ";
					cin >> nr_rows;
					int* nr_seats_per_row = new int[nr_rows];
					for (int i = 0; i < nr_randuri; i++) {
						cout << "Introduce the seats' number for row " << i + 1 << ": ";
						cin >> nr_locuri_pe_rand[i];
					}
					int nr_extinguishers;
					cout << "Introduce the number of extinguishers: ";
					cin >> nr_extinguishers;
					int urgent_exits;
					cout << "Introduce the number of urgent exits: ";
					cin >> urgent_exits;
					Location location(nr_rows, nr_seats_per_row, nr_extinguishers, urgent_exits);
					cout << location;
				}
				if (gr == 4) {
					char* name = new char[20];
					cout << "Introduce the name of the event: ";
					cin >> name;
					string date;
					cout << "Introduce the date of the event: ";
					cin >> date;
					string time;
					cout << "Introduce the time of the event: ";
					cin >> time;
					int duration;
					cout << "Introduce the duration of the event: ";
					cin >> duration;
					Location location;
					cin >> location;
					Event event(name, date, time, location, duration);
					cout << eveniment;
				}
				break;
			case 2:
				cout << "1.Buy ticket";
				cout << endl;
				cout << "2.Show the next events";
				cout << endl;
				cout << "3.	Info about the sports event";
				cout << endl;
				cout << "4.Show discounts:";
				cout << endl;
				int lo;
				cin >> lo;
				if (lo == 1) {
					lansare_console_txt();
					break;
				}
				if (lo == 2) {

					cout << "Event type: ";
					cout << "1.Movie";
					cout << "2.Theatre";
					cout << "3.Sport";

					int j;
					cin >> j;
					if (j == 1) {
						list < Evennt> events_name;
						events_name.push_back(e1);
						events_namee.push_back(e2);
						list < Event> ::iterator it;
						for (it = events_name.begin(); it != events_name.end(); it++) {
							cout << (*it).getEventName() << endl;
						}
						cout << endl;
						break;
					}
					if (j == 2) {
						list <Event> event_name_theatre;
						event_name_theatre.push_back(e3);
						list <Event> ::iterator it;
						for (it = event_name_theatre.begin(); it != event_name_theatre.end(); it++) {
							cout << (*it).getEventName() << endl;
						}
						cout << endl;
						break;

					}
					if (j == 3) {
						list <Eveniment> nume_eveniment_sport;
						nume_eveniment_sport.push_back(e5);
						list <Eveniment> ::iterator it;
						for (it = nume_eveniment_sport.begin(); it != nume_eveniment_sport.end(); it++) {
							cout << (*it).getNumeEveniment() << endl;
						}
						cout << endl;
						break;

					}
					break;
				}

				if (lo == 3) {
					cout << "Choose sport";
					cout << endl;
					cout << "1.Football";
					cout << endl;
					cout << "2.Handball";
					cout << endl;
					cout << "3.Voleyball";
					cout << endl;
					cout << "Introduce your option: ";
					int gt;
					cin >> gt;
					if (gt == 1) {
						Football f1;
						f1.players();
						f1.reserves();
						f1.surface();
						f1.show();
						break;
					}
					if (gt == 2) {
						Handbal h1;
						h1.reserves();
						h1.players();
						h1.surface();
						h1.show();
						break;
					}
					if (gt == 3) {
						Volei v1;
						v1.reserves();
						v1.players();
						v1.surface();
						v1.show();
						break;
					}
					break;
				}
				if (lo == 4) {
					cout << "Do you have a voucher as a gift? Enter the code and we will show you the discount price!";
					Bilet b;
					cout << "Full price:";
					cout << endl;
					int a;
					cin >> a;
					cout << "Voucher code:";
					cout << endl;
					int c;
					cin >> c;
					b.git_voucher(a, c);
				}

			default:

				break;
			}

		}


		int main() {

			meniu_mic();

		}
