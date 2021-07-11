#include "Building.h"
#include "University.h"
#include "Person.h"
#include "Student.h"
#include "Instructor.h"

#include <limits>


int main()
{
	bool menuExit = false;
	int userChoice;
        string personChoice;

	University university;
	Building b1("AB 6 Small Shed-Berry Creek", 1018, "27280 TAMPICO RD Corvallis, OR 97330");
	Building b2("AB Adair Hay Store-Loaf S", 6930, "27280 TAMPICO RD Corvallis, OR 97330");
	Building b3("AB Adair Resid-Berry Creek", 1755, "27280 TAMPICO RD Corvallis, OR 97330");
	Building b4("Adams Hall", 9848, "606 SW 15TH ST CORVALLIS, OR 97331");
	Building b5("Austin Hall", 93941, "2751 SW JEFFERSON WAY CORVALLIS, OR 97331");
	Building b6("Batcheller Hall", 17375, "2591 SW CAMPUS WAY CORVALLIS, OR 97331");
	Building b7("Buoy Lab", 2188, "891 SW 30TH STREET CORVALLIS, OR 97331");
	Building b8("Burt Hall", 64695, "2651 SW Orchard AVE CORVALLIS, OR 97331");
	Building b9("Callahan Hall", 63238, "1420 SW JEFFERSON AVE CORVALLIS, OR");
	Building b10("Clark Laboratory", 6795, "3260 SW CAMPUS WAY CORVALLIS, OR 97331");
	Building b11("Custodial Services Bldg", 1522, "621 SW 17TH ST CORVALLIS, OR 97331");
	Building b12("Dearborn Hall", 59713, "1891 SW CAMPUS WAY CORVALLIS, OR 97331");
	Building b13("Dryden Hall", 19148, "450 SW 30TH STREET CORVALLIS, OR 97331");
	Building b14("Energy Center", 20756, "3452 SW JEFFERSON WAY CORVALLIS, OR 97331");
	Building b15("Fairbanks Hall", 33562, "220 SW 26TH STREET CORVALLIS, OR 97331");
	Building b16("Finley Hall", 74473, "2100 SW MAY WAY CORVALLIS, OR 97331");
	Building b17("Gilbert Hall", 74065, "2100 SW MONROE AVE CORVALLIS, OR 97331");
	Building b18("Hawley Hall", 52140, "311 SW SACKETT PL CORVALLIS, OR 97331");
	Building b19("Johnson Hall", 54317, "105 SW 26TH CORVALLIS, OR 97321");
	Building b20("Kearney Hall", 26923, "1491 SW CAMPUS WAY CORVALLIS, OR 97331");
	Building b21("Strand Agriculture Hall", 96768, "170 SW WALDO PL CORVALLIS, OR 97331");
	Building b22("Weniger Hall", 196202, "103 SW MEMORIAL PL CORVALLIS, OR 97331");
	Building b23("Womens Building", 68354, "160 SW 26TH STREET CORVALLIS, OR 97331");

	university.saveBuilding(b1);
	university.saveBuilding(b2);
	university.saveBuilding(b3);
	university.saveBuilding(b4);
	university.saveBuilding(b5);
	university.saveBuilding(b6);
	university.saveBuilding(b7);
	university.saveBuilding(b8);
	university.saveBuilding(b9);
	university.saveBuilding(b10);
	university.saveBuilding(b11);
	university.saveBuilding(b12);
	university.saveBuilding(b13);
	university.saveBuilding(b14);
	university.saveBuilding(b15);
	university.saveBuilding(b16);
	university.saveBuilding(b17);
	university.saveBuilding(b18);
	university.saveBuilding(b19);
	university.saveBuilding(b20);
	university.saveBuilding(b21);
	university.saveBuilding(b22);
	university.saveBuilding(b23);

	Student s1("John Woods", 20, 2.5);
	Student s2("Sam Van Gorden", 19, 3.2);
	Student s3("Nick Jacobus", 18, 4.0);
	Student s4("Jesse Perez", 20, 1.2);
	Student s5("Katie Reinbold", 18, 3.0);
	Student s6("Chelsea Reiman", 21, 3.1);
	Student s7("Haley Horsewoman", 19, 2.4);
	Student s8("Matt Brown", 19, 2.9);
	Student s9("George Kasabian", 18, 3.2);
	Student s10("Amul Bhatia", 19, 3.4);
	Student s11("Dave Jacobus", 18, 3.1);
	Student s12("Jorge Gomez", 19, 2.0);
	Student s13("Neha Patel", 21, 3.3);
	Student s14("Cristina Rosales", 18, 3.5);
	Student s15("Tyler Isenberg", 20, 2.2);
	Student s16("Chris Peterson", 18, 3.0);
	Student s17("Nicole Lefler", 19, 2.7);
	Student s18("Henry Thomas", 21, 3.2);
	Student s19("Larissa Yates", 19, 2.5);
	Student s20("Fernando Perez", 18, 4.0);

	university.savePerson(&s1);
	university.savePerson(&s2);
	university.savePerson(&s3);
	university.savePerson(&s4);
	university.savePerson(&s5);
	university.savePerson(&s6);
	university.savePerson(&s7);
	university.savePerson(&s8);
	university.savePerson(&s9);
	university.savePerson(&s10);
	university.savePerson(&s11);
	university.savePerson(&s12);
	university.savePerson(&s13);
	university.savePerson(&s14);
	university.savePerson(&s15);
	university.savePerson(&s16);
	university.savePerson(&s17);
	university.savePerson(&s18);
	university.savePerson(&s19);
	university.savePerson(&s20);

	Instructor i1("Matt Davidson", 54, 4.2);
	Instructor i2("Mark Tice", 49, 3.5);
	Instructor i3("Dave Madsen", 52, 2.0);
	Instructor i4("Mary Doyle", 29, 5.0);
	Instructor i5("Dr. Linda Jacobs", 35, 4.4);
	Instructor i6("Dennis Richman", 55, 4.8);
	Instructor i7("Hilda Gomez", 48, 3.2);
	Instructor i8("Jennifer Winnick", 34, 1.5);
	Instructor i9("Dr. DeShaun Watson", 27, 5.0);
	Instructor i10("Raj Patel", 39, 2.3);

	university.savePerson(&i1);
	university.savePerson(&i2);
	university.savePerson(&i3);
	university.savePerson(&i4);
	university.savePerson(&i5);
	university.savePerson(&i6);
	university.savePerson(&i7);
	university.savePerson(&i8);
	university.savePerson(&i9);
	university.savePerson(&i10);

	while (!menuExit)
	{
        cout << "\n1. Print information about all the buildings." << endl;
        cout << "2: Print information of everybody at the university." << endl;
        cout << "3: Choose a person to do work." << endl;
        cout << "4: Exit Program" << endl;
        cout << "\nPlease chooose from the above options: ";
        cin >> userChoice;
		switch (userChoice)
		{
		case 1:
			cout << "\nYou have chosen to print information about all the buiildings." << endl << endl;
			university.printBuildingAddress();
			break;
		case 2:
			cout << "\nYou have chosen to print information of everybody at the university." << endl << endl;
			university.printPeople();
			break;
		case 3:
            university.printPeople();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.clear();
            cout << "Please enter the name of a person to do work: ";
            getline(cin, personChoice);
            ((Instructor*)university.findPerson(personChoice))->do_work();
			break;
		case 4:
			cout << "\nYou chave chosen to exit the program. Program will now exit." << endl;
			menuExit = true;
			break;
		default:
			cout << "\nInvalid entry. Please try again" << endl << endl;
			break;
		}
	}

	return 0;
}
