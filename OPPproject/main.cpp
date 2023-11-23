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
