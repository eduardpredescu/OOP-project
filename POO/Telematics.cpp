#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
using namespace std;



class Telematics{
private:
	string identifier;
	long double timestamp;
	long double coords[2];
public:
	Telematics(){
		identifier = "";
		timestamp = 0;
		coords[0] = 0;
		coords[1] = 0;
	}
	Telematics(string id, long double time, long double* c){
		identifier = id;
		timestamp = time;
		coords[0] = c[0];
		coords[1] = c[1];
	}

	Telematics(const Telematics& t){
		identifier = t.identifier;
		timestamp = t.timestamp;
		coords[0] = t.coords[0];
		coords[1] = t.coords[1];
	}

	Telematics& operator=(Telematics& t){
		identifier = t.identifier;
		timestamp = t.timestamp;
		coords[0] = t.coords[0];
		coords[1] = t.coords[1];
	}

	string getIdentifier() const{
		return identifier;
	}

	long double getCoords(int i) const{
		return coords[i];
	}

	friend ostream& operator<<(ostream&, Telematics&);
	friend ofstream& operator<<(ofstream&, Telematics&);
	friend istream& operator>>(istream&, Telematics&);
	friend ifstream& operator>>(ifstream&, Telematics&);
};

ostream& operator<<(ostream& out, Telematics& t){
	out << "Identifier:" << t.identifier << endl
		<< "Coords:" << t.coords[0] << " " << t.coords[1] << endl;
	time_t timer;
	timer = t.timestamp;
	struct tm *timeinfo = localtime(&timer);
	out << asctime(timeinfo) << endl;

	return out;
}

ofstream& operator<<(ofstream& out, Telematics& t){
	out << t.identifier << endl
		<< t.coords[0] << endl
		<< t.coords[1] << endl
		<< t.timestamp << endl;

	return out;
}

istream& operator>>(istream& in, Telematics& t){
	char text[256];
	long double number;
	cout << "Insert identifier:" << endl;
	in.getline(text, '\n');
	t.identifier = text;
	cout << "Insert coords:" << endl;
	for (int i = 0; i < 2; i++){
		in >> number;
		t.coords[i] = number;
	}
	return in;
}

ifstream& operator>>(ifstream& in, Telematics &t){
	in >> t.identifier >> t.coords[0] >> t.coords[1] >> t.timestamp;
	return in;
}