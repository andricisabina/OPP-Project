#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;


class Location {
private:
	int nr_rows;
	int* nr_seats_per_row;
	int nr_extinguishers;
	int urgent_exits;
	static int staff_guards;

public:

	//default constructor

	Location() {
		nr_rows = 0;
		nr_seats_per_row = NULL;
		nr_extinguishers = 0;
		urgent_exits = 0;
	}

	//constructor with parameters

	Location(int nr_rows, const int* nr_seats_per_row, int nr_extinguishers, int urgent_exits)
	{
		this->nr_rows = nr_rows;
		this->nr_seats_per_row = new int[nr_rows];
		for (int i = 0; i < nr_rows; i++)
			this->nr_seats_per_row[i] = nr_seats_per_row[i];
		this->nr_extinguishers = nr_extinguishers;
		this->urgent_exits = urgent_exits;
	}

	//copy constructor

	Location(const Location& l)
	{
		this->nr_rows = l.nr_rows;
		this->nr_seats_per_row = new int[l.nr_rows];
		for (int i = 0; i < l.nr_rows; i++)
			this->nr_seats_per_row[i] = l.nr_seats_per_row[i];
		this->nr_extinguishers = l.nr_extinguishers;
		this->urgent_exits = l.urgent_exits;

	}

	//supraincarcarea operatorului de atribuire

	Location& operator=(const Location& l)
	{
		if (this != &l) {
			this->nr_rows = l.nr_rows;
			if (this->nr_seats_per_row != NULL)
				delete[] this->nr_seats_per_row;
			this->nr_seats_per_row = new int[l.nr_rows];
			for (int i = 0; i < l.nr_rows; i++)
				this->nr_seats_per_row[i] = l.nr_seats_per_row[i];
			this->nr_extinguishers = l.nr_extinguishers;
			this->urgent_exits = l.urgent_exits;
		}
		return *this;
	}

	//getteri si setteri

	void setNrRows(int nr_rows)
	{
		if (nr_rows) {
			this->nr_rows = nr_rows;
		}
	}

	int getNrRows()
	{
		return this->nr_rows;
	}

	void setNrSeatsPerRow(int* nr_seats_per_row)
	{
		if (this->nr_seats_per_row != NULL)
			delete[] this->nr_seats_per_row;
		this->nr_seats_per_row = new int[this->nr_rows];
		for (int i = 0; i < this->nr_rows; i++)
			this->nr_seats_per_row[i] = nr_seats_per_row[i];
	}

	int* getNrSeatsPerRow()
	{
		return this->nr_seats_per_row;
	}

	void setNrExtinguishers(int nr_extinguishers)
	{
		if (nr_extinguishers) {
			this->nr_extinguishers = nr_extinguishers;
		}
	}

	void setNrExits(int urgent_exits)
	{
		if (urgent_exits) {
			this->urgent_exits = urgent_exits;
		}
	}


	void setTakenSeats(int x, int y) {
		this->nr_seats_per_row[x] = y;

	}

	void showTakenSeats() {
		{
			for (int i = 0; i < this->nr_rows; i++)
				cout << "Row " << i + 1 << " has " << this->nr_seats_per_row[i] << " taken seats" << endl;
		}

	}

	int getNrExtinguishers()
	{
		return this->nr_extinguishers;
	}

	int getNrExits()
	{
		return this->urgent_exits;
	}

	//destructor

	~Location()
	{
		if (this->nr_seats_per_row != NULL)
			delete[] this->nr_seats_per_row;

	}
	//operator ==
	bool operator==(Location l) {
		if (this->nr_rows == l.nr_rows)
			return true;
		else
			return false;
	}

	//operator >=

	bool operator>=(Location l) {
		if (this->nr_rows >= l.nr_rows)
			return true;
		else
			return false;
	}

	//verify exits

	void verifyexits(Location l) {
		if (l.urgent_exits > 0) cout << "IN THE LOCATION EXISTS URGENT EXITS";
		else {
			cout << "IN THE LOCATION DOES NOT EXISTS URGENT EXITS";
		}
	}

	//verify extinguishers

	void verifyextinguishers(Location l) {
		if (l.nr_extinguishers > 0) cout << "IN THE LOCATION EXISTS EXTINGUISHERS";
		else {
			cout << "IN THE LOCATION DOES NOT EXISTS EXTINGUISHERS";
		}
	}

	//static

	static void setGuards(int staff_guards) {
		Location::staff_guards = staff_guards;
	}


	//load the operators

	friend ostream& operator<<(ostream& out, Location l);
	friend istream& operator>>(istream& in, Location& l);
};
int Location::staff_guards = 0;

ostream& operator<<(ostream& out, Location l) {

	out << "The number of rows is: " << l.nr_rows << endl;
	out << "The number of seats per row is: ";
	cout << endl;
	for (int i = 0; i < l.nr_rows; i++) {
		out << l.nr_seats_per_row[i] << " ";
		out << endl;
	}
	out << "The number of urgent exits  is: " << l.urgent_exits << endl;
	out << "The number of extinguishers is: " << l.nr_extinguishers << endl;
	out << "The number of guards: " << l.staff_guards << endl;
	return out;
}

istream& operator>>(istream& in, Location& l) {

	cout << "The number of rows: ";
	in >> l.nr_rows;
	if (l.nr_seats_per_row != NULL)
		delete[] l.nr_seats_per_row;
	l.nr_seats_per_row = new int[l.nr_rows];
	cout << "The number of seats per row is: ";
	for (int i = 0; i < l.nr_rows; i++)
		in >> l.nr_seats_per_row[i];
	cout << "The number of urgent exits is:";
	in >> l.urgent_exits;
	cout << "The number of extinguishers: ";
	in >> l.nr_extinguishers;
	return in;
}


template <class T>

T capacity(T a, T b) {
	return a * b;
}










