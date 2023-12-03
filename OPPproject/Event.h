#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include "Location.h"
#include <list>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

enum event_type { sport, movie, theatre };

class Event {

private:
	char* event_name;
	string date;
	string time;
	int nr_rows;
	int nr_seats;
	Location location;
	event_type teven;
	int duration;
	string* actors;
	int nr_actors;
	string* protagonists;
	int nr_protagonists;
	int** matrix_seat;


public:

	//default constructor
	Event() {
		event_name = new char[strlen("A") + 1];
		strcpy_s(event_name, strlen("A") + 1, "A");
		date = "0";
		time = "0";
		nr_seats = 0;
		teven = movie;
		duration = 0;
		matrix_seat = NULL;

	}


	//constructor with parameters

	Event(const char* event_name, event_type teven, string date, string time, Location seat, int duration) {
		this->event_name = new char[strlen(event_name) + 1];
		strcpy_s(this->event_name, strlen(event_name) + 1, event_name);
		this->date = date;
		this->time = time;
		for (int i = 0; i < seat.getNrRows(); i++) {
			this->nr_seats += seat.getNrSeatsPerRow()[i];
		}
		this->location = seat;
		this->teven = teven;
		this->duration = duration;
		int** matrix_seat = new int* [seat.getNrRows()];
		for (int i = 0; i < seat.getNrRows(); i++)
			matrix_seat[i] = new int[seat.getNrSeatsPerRow()[i]];
		for (int i = 0; i < seat.getNrRows(); i++)
			for (int j = 0; j < seat.getNrSeatsPerRow()[i]; j++)
				matrix_seat[i][j] = 0;
		this->matrix_seat = matrix_seat;
	}
	Event(const char* event_name, event_type teven, string date, string time, Location seat, int duration) {
		this->event_name = new char[strlen(event_name) + 1];
		strcpy_s(this->event_name, strlen(event_name) + 1, event_name);
		this->date = date;
		this->time = time;
		for (int i = 0; i < seat.getNrRows(); i++) {
			this->nr_seats += seat.getNrSeatsPerRow()[i];
		}
		this->location = seat;
		this->duration = duration;
		int** matrix_seat = new int* [seat.getNrRows()];
		for (int i = 0; i < seat.getNrRows(); i++)
			matrix_seat[i] = new int[seat.getNrSeatsPerRow()[i]];
		for (int i = 0; i < seat.getNrRows(); i++)
			for (int j = 0; j < seat.getNrSeatsPerRow()[i]; j++)
				matrix_seat[i][j] = 0;
		this->matrix_seat = matrix_seat;
	}

	//copy constructor

	Event(const Event& e) {
		this->event_name = new char[strlen(e.event_name) + 1];
		strcpy_s(this->event_name, strlen(e.event_name) + 1, e.event_name);
		this->date = e.date;
		this->time = e.time;
		for (int i = 0; i < location.getNrRows(); i++) {
			this->nr_seats += location.getNrSeatsPerRow()[i];
		}
		this->nr_seats = e.nr_seats;
		this->location = e.location;
		this->teven = e.teven;
		this->duration = e.duration;
		int** matrix_seat = new int* [location.getNrRows()];
		for (int i = 0; i < location.getNrRows(); i++)
			matrix_seat[i] = new int[location.getNrSeatsPerRow()[i]];
		for (int i = 0; i < location.getNrRows(); i++)
			for (int j = 0; j < location.getNrSeatsPerRow()[i]; j++)
				matrix_seat[i][j] = e.matrix_seat[i][j];
		this->matrix_seat = matrix_seat;

	}

	//overload the operator

	Event& operator=(const Event& e) {
		if (this != &e) {
			if (this->event_name != NULL)
				delete[] this->event_name;
			this->event_name = new char[strlen(e.event_name) + 1];
			strcpy_s(this->event_name, strlen(e.event_name) + 1, e.event_name);
			this->date = e.date;
			this->time = e.time;
			for (int i = 0; i < location.getNrRows(); i++) {
				this->nr_seats += location.getNrSeatsPerRow()[i];
			}
			this->nr_rows = e.nr_rows;
			this->location = e.location;
			this->teven = e.teven;
			this->duration = e.duration;
			int** matrix_seat = new int* [location.getNrRows()];
			for (int i = 0; i < location.getNrRows(); i++)
				matrix_seat[i] = new int[location.getNrSeatsPerRow()[i]];
			for (int i = 0; i < location.getNrRows(); i++)
				for (int j = 0; j < location.getNrSeatsPerRow()[i]; j++)
					matrix_seat[i][j] = e.matrix_seat[i][j];
			this->matrix_seat = matrix_seat;

		}
		return *this;
	}


	//setters and getters

	void setEventName(const char* event_name) {
		if (this->event_name != NULL)
			delete[] this->event_name;
		this->event_name = new char[strlen(event_name) + 1];
		strcpy_s(this->event_name, strlen(event_name) + 1, event_name);
	}

	char* getEventName() {
		char* copy = new char[strlen(this->event_name) + 1];
		strcpy_s(copy, strlen(this->event_name) + 1, this->event_name);
		return copy;
	}

	void setDate(string date) {
		this->date = date;

	}


	string getDate() {
		return this->date;
	}

	void setTime(string time) {
		this->time = time;
	}

	void setDuration(int duration) {
		if (duration)
			this->duration = duration;
	}

	int getDuration() {
		return this->duration;
	}

	string getTime() {
		return this->time;
	}

	void setNrRows(int nr_rows) {
		if (nr_rows > 0)
			this->nr_rows = nr_rows;
	}

	int getNrRows() {
		return this->nr_rows;
	}

	void setLocation(Location location) {
		this->location = location;
	}

	Location getLocation() {
		return this->location;
	}

	void setEventType(event_type teven) {
		if (teven == 0 || teven == 1 || teven == 2)
			this->teven = teven;
	}

	event_type getEventType() {
		return this->teven;
	}


	bool verify_free_seat(int** matrix_seat, int x, int y) {
		bool ok = false;
		if (x < location.getNrRows() && y < location.getNrSeatsPerRow()[x - 1]) {
			if (matrix_seat[x - 1][y - 1] == 0) {
				ok = true;
			}


		}
		return ok;

	}

	void setMatrix(int** matrix_seat) {
		if (this->matrix_seat != NULL) {
			for (int i = 0; i < location.getNrRows(); i++)
				delete[] this->matrix_seat[i];
			delete[] this->matrix_seat;
		}
		this->matrix_seat = new int* [location.getNrRows()];
		for (int i = 0; i < location.getNrRows(); i++)
			this->matrix_seat[i] = new int[location.getNrSeatsPerRow()[i]];
		for (int i = 0; i < location.getNrRows(); i++)
			for (int j = 0; j < location.getNrSeatsPerRow()[i]; j++)
				this->matrix_seat[i][j] = matrix_seat[i][j];

	}


	int** getMatrix() {
		int** copy = new int* [location.getNrRows()];
		for (int i = 0; i < location.getNrRows(); i++)
			copy[i] = new int[location.getNrRows()[i]];
		for (int i = 0; i < location.getNrRows(); i++)
			for (int j = 0; j < location.getNrSeatsPerRow()[i]; j++)
				copy[i][j] = this->matrix_seat[i][j];
		return copy;
	}

	int** getMatrixSeat() {
		int** copy = new int* [location.getNrRows()];
		for (int i = 0; i < location.getNrRows(); i++)
			copy[i] = new int[location.getNrSeatsPerRow()[i]];
		for (int i = 0; i < location.getNrRows(); i++)
			for (int j = 0; j < location.getNrRows()[i]; j++)
				copy[i][j] = this->matrix_seat[i][j];
		return copy;

	}


	//acestea sunt gandite intr-un scenariu pentru teatru, daca i se ofera utilizatorului posibilitatea de a vedea actorii si
	//intr-un scenariu pentru film, daca i se ofera utilizatorului posibilitatea de a vedea actorii 
	//nu am realizat-o si pentru evenimentul sportiv pana in acest punct

	void setNrActors(int nr_actors) {
		if (nr_actors)
			this->nr_actors = nr_actors;
	}

	int getNrActors() {
		return this->nr_actors;
	}

	void setNrProtagonists(int nr_protagonists) {
		if (nr_protagonists)
			this->nr_protagonists = nr_protagonists;
	}

	int getNrProtagonists() {
		return this->nr_protagonists;
	}

	void setActors(string* actors, int nr_actors) {
		if (this->actors != NULL)
			delete[] this->actors;
		this->actors = new string[nr_actors];
		for (int i = 0; i < nr_actors; i++)
			this->actors[i] = actors[i];
		this->nr_actors = nr_actors;
	}

	string* getActors() {
		string* copy = new string[this->nr_actors];
		for (int i = 0; i < this->nr_actors; i++)
			copy[i] = this->actors[i];
		return copy;
	}

	void setProtagonists(string* protagonists, int nr_protagonists) {
		if (this->protagonists != NULL)
			delete[] this->protagonists;
		this->protagonists = new string[nr_protagonists];
		for (int i = 0; i < nr_protagonists; i++)
			this->protagonists[i] = protagonists[i];
		this->nr_protagonists = nr_protagonists;
	}


	string* getProtagonists() {
		string* copy = new string[this->nr_protagonists];
		for (int i = 0; i < this->nr_protagonists; i++)
			copy[i] = this->protagonists[i];
		return copy;
	}


	//desctructor 

	~Event() {
		if (this->event_name != NULL)
			delete this->event_name;
	}

	//operator !

	bool operator!() {
		if (this->nr_seats != 0) return true;
		else return false;
	}

	//operator +

	Event operator+(int value) {
		Event copy = *this;
		copy.nr_seats = nr_seats + value;
		return copy;
	}

	// Possible extensions for a football match

	void possibleextensions(int minutes_possible_extensions) {
		if (teven == sport) duration += minutes_possible_extensions;
		cout << "The new duration is: " << duration << endl;
	}




	//take a seat

	bool TakeSeat(Location& seat, int x, int y) {
		bool ok = false;
		if (x < seat.getNrRows() && y < seat.getNrSeatsPerRow()[x - 1]) {
			if (matrix_seat[x - 1][y - 1] == 0) {
				matrix_seat[x - 1][y - 1] = 1;
				cout << "Seat successfully booked!";
				nr_seats--;
				cout << "Number of seats left: " << nr_seats;
				cout << endl;
				ok = true;
			}
			else { cout << "The seat is already taken"; }
			cout << "Occupied seats:" << endl;
			for (int i = 0; i < seat.getNrRows(); i++) {
				for (int j = 0; j < seat.getNrSeatsPerRow()[i]; j++) {
					cout << matrix_seat[i][j] << " ";
				}
				cout << endl;
			}
		}
		return ok;
	}

	//setter load matrix





	//getter load matrix

	int** getOccupancyMatrix() {
		int** copy = new int* [location.getNrRows()];
		for (int i = 0; i < location.getNrRows(); i++)
			copy[i] = new int[location.getNrSeatsPerRow()[i]];
		for (int i = 0; i < location.getNrRows(); i++)
			for (int j = 0; j < location.getNrSeatsPerRow()[i]; j++)
				copy[i][j] = this->matrix_seat[i][j];
		return copy;
	}

	//urmaroarele metode functioneaza doar pentru cazul teatru


	void showtheatreactors() {
		if (teven == theatre) {
			actors = new string[nr_actors];
			for (int i = 0; i < nr_actors; i++)
				cout << actors[i] << endl;
		}
	}




	void showprotagonists() {
		if (teven == movie) {
			protagonists = new string[nr_protagonists];
			for (int i = 0; i < nr_protagonists; i++)
				cout << protagonists[i] << endl;
		}
	}



	//overloading the reading and writing

	friend ostream& operator<<(ostream& out, Event e);
	friend istream& operator>>(istream& in, Event& e);

};

ostream& operator<<(ostream& out, Event e) {
	out << "The name of the event: " << e.event_name << endl;
	out << "The date is: " << e.date << endl;
	out << "The time is:: " << e.time << endl;
	out << "The number of seats is: " << e.nr_seats << endl;
	switch (e.teven) {
	case 0:out << "Event type: sport" << endl; break;
	case 1:out << "Event type: movie" << endl; break;
	case 2:out << "Event type: theatre" << endl; break;
	default:
		out << "normal" << endl; break;
	}
	out << e.location << endl;
	out << "The duration is: " << e.duration << endl;
	out << "Matrix' seats: " << endl;
	for (int i = 0; i < e.location.getNrRows(); i++) {
		for (int j = 0; j < e.location.getNrSeatsPerRow()[i]; j++) {
			out << e.matrix_seat[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Event& e) {
	cout << "The name of the event is: ";
	char buffer[50];
	in >> buffer;
	if (e.event_name != NULL)
		delete e.event_name;
	e.event_name = new char[strlen(buffer) + 1];
	strcpy_s(e.event_name, strlen(buffer) + 1, buffer);
	cout << "The date is: ";
	in >> e.date;
	cout << "The time is: ";
	in >> e.time;
	cout << "The number of seats is: ";
	in >> e.nr_seats;
	string event_type;
	in >> event_type;
	if (event_type == "sport")
		e.teven = sport;
	else if (event_type == "movie")
		e.teven = movie;
	else if (event_type == "theatre")
		e.teven = theatre;
	else
		e.teven = sport;
	cout << "The location is: ";
	in >> e.location;
	cout << "The duration is: ";
	in >> e.duration;
	return in;
}

class TheatreEvent :public Event {
private:
	string actors;

public:

	TheatreEvent() :Event() {
		actors = "";
	}

	TheatreEvent(const char* event_name, event_type teven, string date, string time, Location seat, int duration, string actors) :Event(event_name, teven, date, time, seat, duration) {
		this->actors = actors;
	}

	TheatreEvent(const TheatreEvent& e) :Event(e) {
		this->actors = e.actors;
	}

	TheatreEvent& operator=(const TheatreEvent& e) {
		Event::operator=(e);
		this->actors = e.actors;
		return *this;
	}

	~TheatreEvent() {
		actors = "";
	}

	string getActors() {
		return actors;
	}

	void setActors(string actors) {
		this->actors = actors;
	}

	friend ostream& operator<<(ostream& out, TheatreEvent e);
	friend istream& operator>>(istream& in, TheatreEvent& e);
};

ostream& operator<<(ostream& out, TheatreEvent e) {
	out << (Event)e;
	out << "Actors: " << e.actors << endl;
	return out;
}

istream& operator>>(istream& in, TheatreEvent& e) {
	in >> (Event&)e;
	cout << "Actors: ";
	in >> e.actors;
	return in;
}




class VirtualEventSports {
protected:
	int nr_jucatori;
	int nr_rezerve;
	string suprafata_joc;

public:
	virtual int jucatori() = 0;
	virtual int rezerve() = 0;
	virtual string suprafata();
	virtual void afiseaza();



};


string VirtualEventSports::suprafata()
{
	return string();
}

void VirtualEventSports::afiseaza()
{

}

class Fotbal : public VirtualEventSports {

public:
	int jucatori() {
		return 11;
	}
	int rezerve() {
		return 7;
	}
	string suprafata() {
		return "gazon";
	}
	void afiseaza() {
		cout << "Jucatori: " << jucatori() << endl;
		cout << "Rezerve: " << rezerve() << endl;
		cout << "Suprafata: " << suprafata() << endl;
	}

};

class Handbal : public VirtualEventSports {

public:
	int jucatori()
	{
		return 7;
	}
	int rezerve() {
		return 5;
	}
	string suprafata() {
		return "gazon";
	}
	void afiseaza() {
		cout << "Jucatori: " << jucatori() << endl;
		cout << "Rezerve: " << rezerve() << endl;
		cout << "Suprafata: " << suprafata() << endl;
	}
};

class Volei : public VirtualEventSports {

public:
	int jucatori()
	{
		return 6;
	}
	int rezerve() {
		return 6;
	}
	string suprafata() {
		return "gazon";
	}
	void afiseaza() {
		cout << "Jucatori: " << jucatori() << endl;
		cout << "Rezerve: " << rezerve() << endl;
		cout << "Suprafata: " << suprafata() << endl;
	}
};


