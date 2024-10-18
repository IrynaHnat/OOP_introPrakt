

#include <iostream>
#include<string>
#include<fstream>
using namespace std;

//1
struct Date
{
	size_t day, month, year;
	string getDate()
	{
		return (day < 10 ? "0" : "") + to_string(day) + "." + (month < 10 ? "0" : "") + to_string(month) + "." + to_string(year);
	}
};


class Student {
private:
    string fullName = "NoName";
    Date birthDate{};
    string phone = "NoPhone";
    string city = "NoCity";
    string country = "NoCountry";
    string institution = "NoInstitution";
    string institutionCity = "NoCity";
    string institutionCountry = "NoCountry";
    string groupNumber = "NoGroup";

public:
    Student() = default;

    Student(const string& fullName, const Date& birthDate, const string& phone,
        const string& city, const string& country, const string& institution,
        const string& institutionCity, const string& institutionCountry, const string& groupNumber)
        : birthDate{ birthDate } {
        setFullName(fullName);
        setPhone(phone);
        setCity(city);
        setCountry(country);
        setInstitution(institution);
        setInstitutionCity(institutionCity);
        setInstitutionCountry(institutionCountry);
        setGroupNumber(groupNumber);
    }

    string getFullName() { return this->fullName; }
    Date getBirthDate() { return this->birthDate; }
    string getPhone() { return this->phone; }
    string getCity() { return this->city; }
    string getCountry() { return this->country; }
    string getInstitution() { return this->institution; }
    string getInstitutionCity() { return this->institutionCity; }
    string getInstitutionCountry() { return this->institutionCountry; }
    string getGroupNumber() { return this->groupNumber; }


    void setFullName(const string& fullName) {
        if (fullName.empty() || fullName == " ") {
            cout << "Error!!! Full name is empty" << endl;
        }
        else {
            this->fullName = fullName;
        }
    }

    void setPhone(const string& phone) {
        if (!phone.empty() && phone != " ") {
            this->phone = phone;
        }
    }

    void setCity(const string& city) {
        if (!city.empty() && city != " ") {
            this->city = city;
        }
    }

    void setCountry(const string& country) {
        if (!country.empty() && country != " ") {
            this->country = country;
        }
    }

    void setInstitution(const string& institution) {
        if (!institution.empty() && institution != " ") {
            this->institution = institution;
        }
    }

    void setInstitutionCity(const string& institutionCity) {
        if (!institutionCity.empty() && institutionCity != " ") {
            this->institutionCity = institutionCity;
        }
    }

    void setInstitutionCountry(const string& institutionCountry) {
        if (!institutionCountry.empty() && institutionCountry != " ") {
            this->institutionCountry = institutionCountry;
        }
    }

    void setGroupNumber(const string& groupNumber) {
        if (!groupNumber.empty() && groupNumber != " ") {
            this->groupNumber = groupNumber;
        }
    }

    void print() {
        cout << "====================== " << this->fullName << " =======================" << endl;
        cout << "\t Date of Birth         :: " << this->birthDate.getDate() << endl;
        cout << "\t Contact Phone         :: " << this->phone << endl;
        cout << "\t City                  :: " << this->city << endl;
        cout << "\t Country               :: " << this->country << endl;
        cout << "\t Institution Name      :: " << this->institution << endl;
        cout << "\t Institution City      :: " << this->institutionCity << endl;
        cout << "\t Institution Country   :: " << this->institutionCountry << endl;
        cout << "\t Group Number          :: " << this->groupNumber << endl;
    }

    void input() {
        cout << "\t Full Name             :: "; getline(cin, this->fullName);
        cout << "\t Date of Birth (day month year):: "; cin >> this->birthDate.day >> this->birthDate.month >> this->birthDate.year;
        cin.ignore();
        cout << "\t Contact Phone         :: "; getline(cin, this->phone);
        cout << "\t City                  :: "; getline(cin, this->city);
        cout << "\t Country               :: "; getline(cin, this->country);
        cout << "\t Institution Name      :: "; getline(cin, this->institution);
        cout << "\t Institution City      :: "; getline(cin, this->institutionCity);
        cout << "\t Institution Country   :: "; getline(cin, this->institutionCountry);
        cout << "\t Group Number          :: "; getline(cin, this->groupNumber);
    }
};

//2

class Point {
private:
    double x;
    double y;
    double z;
public:
    Point() : x(0), y(0), z(0) {} 

    Point(double x, double y, double z) : x(x), y(y), z(z) {} 

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    void input() {
        cout << "Enter x: "; cin >> x;
        cout << "Enter y: "; cin >> y;
        cout << "Enter z: "; cin >> z;
    }

    void print() const {
        cout << "Ñoordinates of points: (" << x << ", " << y << ", " << z << ")" << endl;
    }

   
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error!" << endl;
            return;
        }
        file << x << endl;
        file << y << endl;
        file << z << endl;
        file.close();
    }

    
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error" << endl;
            return;
        }
        file >> x >> y >> z;
        file.close();
    }
};


int main()
{
    //1

    Date birthDate = { 14, 8, 1995 };
    Student student1;
    Student student2("Iryna Hnativ", { 7, 3, 1999 }, "123-456-7890", "Lviv", "Ukraine",
        "Lviv National University im.Ivana Franka", "Lviv", "Ukraine", "AB-101");

    student2.print();
    student1.input();
    student1.print();

    //2
    Point p1;
    Point p2(1.0, 2.0, 3.0);

    p1.input();
    p1.print();
    p2.print();

    p1.saveToFile("point.txt");
    p2.loadFromFile("point.txt");
    p2.print();
   





}

