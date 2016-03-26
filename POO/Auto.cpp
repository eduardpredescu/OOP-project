#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class Auto{
	friend class AutoFile;
private:
	string identifier;
	string engine;
	int max_speed;
	int engine_cc;
	int avg_consumption_urban;
	int avg_speed_urban;
	int avg_consumption;
	int avg_speed;
public:
	Auto(string identifier = "", string engine = "", int max_speed = 0, int engine_cc = 0, int avg_speed_urban = 0,
		int avg_consumption_urban = 0, int avg_consumption = 0, int avg_speed = 0){
		this->identifier = identifier;
		this->engine = engine;
		this->max_speed = max_speed;
		this->engine_cc = engine_cc;
		this->avg_consumption = avg_consumption;
		this->avg_consumption_urban = avg_consumption_urban;
		this->avg_speed_urban = avg_speed_urban;
		this->avg_speed = avg_speed;
	}

	Auto(const Auto& a){
		this->identifier = a.identifier;
		this->engine = a.engine;
		this->max_speed = a.max_speed;
		this->engine_cc = a.engine_cc;
		this->avg_consumption = a.avg_consumption;
		this->avg_speed_urban = a.avg_speed_urban;
		this->avg_consumption_urban = a.avg_consumption_urban;
		this->avg_speed = a.avg_speed;
	}

	Auto& operator=(Auto& a){
		this->identifier = a.identifier;
		this->engine = a.engine;
		this->max_speed = a.max_speed;
		this->engine_cc = a.engine_cc;
		this->avg_consumption = a.avg_consumption;
		this->avg_speed_urban = a.avg_speed_urban;
		this->avg_consumption_urban = a.avg_consumption_urban;
		this->avg_speed = a.avg_speed;
		return *this;
	}

	string getIdentifier() const{
		return identifier;
	}

	int getAvgConsumption() const {
		return avg_consumption;
	}

	int getAvgConsumptionUrban() const {
		return avg_consumption_urban;
	}

	int getAvgSpeed() const {
		return avg_speed;
	}

	int getAvgSpeedUrban() const {
		return avg_speed_urban;
	}

	string getEngine() const {
		return engine;
	}

	int getEngineCc() const {
		return engine_cc;
	}

	int getMaxSpeed() const {
		return max_speed;
	}


	friend ifstream& operator>>(ifstream&, Auto&);
	friend istream& operator>>(istream&, Auto&);
	friend ostream& operator<<(ostream&, Auto&);
	friend ofstream& operator<<(ofstream&, Auto&);

};

ostream& operator<<(ostream& out, Auto& a){
	out << "identifier" << a.getIdentifier() << endl
		<< "engine:" << a.getEngine() << endl
		<< "max_speed:" << a.getMaxSpeed() << endl
		<< "engine_cc :" << a.getEngineCc() << endl
		<< "avg_consumption_urban:" << a.getAvgConsumptionUrban() << endl
		<< "avg_speed_urban:" << a.getAvgSpeedUrban() << endl
		<< "avg_consumption:" << a.getAvgConsumption() << endl
		<< "avg_speed :" << a.getAvgSpeed() << endl;

	return out;
}

ofstream& operator<<(ofstream& out, Auto& a){
	out << "identifier" << a.getIdentifier() << endl
		<< "engine:" << a.getEngine() << endl
		<< "max_speed:" << a.getMaxSpeed() << endl
		<< "engine_cc :" << a.getEngineCc() << endl
		<< "avg_consumption_urban:" << a.getAvgConsumptionUrban() << endl
		<< "avg_speed_urban:" << a.getAvgSpeedUrban() << endl
		<< "avg_consumption:" << a.getAvgConsumption() << endl
		<< "avg_speed :" << a.getAvgSpeed() << endl;

	return out;
}

ifstream& operator>>(ifstream& in, Auto& a){
	char buffer[256];
	in >> buffer >> a.identifier
		>> buffer >> a.engine
		>> buffer >> a.max_speed
		>> buffer >> a.engine_cc
		>> buffer >> a.avg_consumption_urban
		>> buffer >> a.avg_speed_urban
		>> buffer >> a.avg_consumption
		>> buffer >> a.avg_speed;
	return in;
}

istream& operator>>(istream& in, Auto& a){
	char text[256];
	int number;
	cout << "Insert identifier:" << endl;
	in.getline(text, '\n');
	a.identifier = text;
	cout << "Insert engine:" << endl;
	in.getline(text, '\n');
	a.engine = text;
	cout << "Insert max speed:" << endl;
	in >> number;
	a.max_speed = number;
	cout << "Insert engine cc:" << endl;
	in >> number;
	a.engine_cc = number;
	cout << "Insert avg consumption urban:" << endl;
	in >> number;
	a.avg_consumption_urban = number;
	cout << "Insert avg speed urban:" << endl;
	a.avg_speed = number;
	in >> number;
	a.avg_speed_urban = number;
	cout << "Insert avg consumption:" << endl;
	a.avg_consumption = number;
	cout << "Insert avg speed:" << endl;
	in >> number;
	a.avg_speed = number;

	return in;
}
