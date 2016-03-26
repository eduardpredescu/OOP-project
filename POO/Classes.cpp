#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string>
#include<windows.h>
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


	friend ifstream& operator>>(ifstream& in, Auto& a){
		in >> a.identifier;
		in >> a.engine;
		in >> a.max_speed;
		in >> a.engine_cc;
		in >> a.avg_consumption_urban;
		in >> a.avg_speed_urban;
		in >> a.avg_consumption;
		in>> a.avg_speed;
		return in;
	}
	friend istream& operator>>(istream& in, Auto& a){
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

	friend ostream& operator<<(ostream& out, Auto& a){
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
	friend ofstream& operator<<(ofstream& out, Auto& a){
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

};









class Geofence{
	friend class GeoFile;
private:
	string identifier;
	string restriction;
	long double point[2];
	int radius;
	long double left_up_corner[2];
	long double right_down_corner[2];
public:
	Geofence(){
		identifier = "";
		restriction = "";
		point[0] = 0;
		point[1] = 0;
		radius = 0;
		left_up_corner[0] = 0;
		left_up_corner[1] = 0;
		right_down_corner[0] = 0;
		right_down_corner[1] = 0;
	}
	Geofence(string id, string restr, long double* p, int rad){
		identifier = id;
		restriction = restr;
		point[0] = p[0];
		point[1] = p[1];
		radius = rad;
	}
	Geofence(string id, string restr, long double* left, long double* right){
		identifier = id;
		restriction = restr;
		left_up_corner[0] = left[0];
		left_up_corner[1] = left[1];
		right_down_corner[0] = right[0];
		right_down_corner[1] = right[1];
	}

	Geofence(const Geofence& g){
		identifier = g.identifier;
		restriction = g.restriction;
		if (identifier == "rectangle"){
			left_up_corner[0] = g.left_up_corner[0];
			left_up_corner[1] = g.left_up_corner[1];
			right_down_corner[0] = g.right_down_corner[0];
			right_down_corner[1] = g.right_down_corner[1];
		}
		else
		{
			point[0] = g.point[0];
			point[1] = g.point[1];
			radius = g.radius;
		}
	}

	Geofence& operator=(Geofence& g){
		identifier = g.identifier;
		restriction = g.restriction;
		if (identifier == "rectangle"){
			left_up_corner[0] = g.left_up_corner[0];
			left_up_corner[1] = g.left_up_corner[1];
			right_down_corner[0] = g.right_down_corner[0];
			right_down_corner[1] = g.right_down_corner[1];
		}
		else
		{
			point[0] = g.point[0];
			point[1] = g.point[1];
			radius = g.radius;
		}
		return *this;
	}

	void initCircle(string id, string t, long double* p, int rad){
		identifier = id;
		restriction = t;
		point[0] = p[0];
		point[1] = p[1];
		radius = rad;
	}
	void initRectangle(string id, string t, long double* left, long double* right){
		identifier = id;
		restriction = t;
		left_up_corner[0] = left[0];
		left_up_corner[1] = left[1];
		right_down_corner[0] = right[0];
		right_down_corner[1] = right[1];
	}
	long double getPoint(int i){
		return point[i];
	}
	string getIdentifier(){
		return identifier;
	}
	long double getLeftUpCorner(int i){
		return left_up_corner[i];
	}

	long double getRightDownCorner(int i){
		return right_down_corner[i];
	}

	long double getRadius(){
		return radius;
	}

	friend ifstream& operator>>(ifstream& in, Geofence& g){
		in >> g.identifier;
		in >> g.restriction;
		if (g.identifier == "rectangle"){
			in >> g.left_up_corner[0];
			in >> g.left_up_corner[1];
			in >> g.right_down_corner[0];
			in >> g.right_down_corner[1];
		}
		else
		{
			in >> g.point[0];
			in >> g.point[1];
			in >> g.radius;
		}

		return in;
	}

	friend istream& operator>>(istream& in, Geofence& g){
		char text[256];
		long double number;
		int radius;
		cout << "Insert shape:" << endl;
		in.getline(text, '\n');
		g.identifier = text;
		if (g.identifier == "rectangle"){
			cout << "Insert left up coords:" << endl;
			for (int i = 0; i < 2; i++){
				in >> number;
				g.left_up_corner[i] = number;
			}
			cout << "Insert right down coords:" << endl;
			for (int i = 0; i < 2; i++){
				in >> number;
				g.right_down_corner[i] = number;
			}
		}
		else{
			cout << "Insert circle center:" << endl;
			for (int i = 0; i < 2; i++){
				in >> number;
				g.point[i] = number;
			}
			cout << "Insert radius:" << endl;
			in >> radius;
			g.radius = radius;
		}

		return in;
	}
	friend ostream& operator<<(ostream& out, Geofence& g){
		out << "Identifier:" << g.identifier << endl
			<< "Restriction:" << g.restriction << endl;
		if (g.identifier == "circle"){
			out << "X:" << g.point[0] << endl
				<< "Y:" << g.point[1] << endl
				<< "Radius:" << g.radius << endl;
		}
		else{
			out << "Left_up_corner X:" << g.left_up_corner[0] << endl
				<< "Left_up_corner Y:" << g.left_up_corner[1] << endl
				<< "Right_down_corner X:" << g.right_down_corner[0] << endl
				<< "Right_down_corner Y:" << g.right_down_corner[1] << endl;
		}

		return out;
	}
	friend ofstream& operator<<(ofstream& out, Geofence& g){
		out << "Identifier:" << g.identifier << endl
			<< "Restriction:" << g.restriction << endl;
		if (g.identifier == "circle"){
			out << "X:" << g.point[0] << endl
				<< "Y:" << g.point[1] << endl
				<< "Radius:" << g.radius << endl;
		}
		else{
			out << "Left_up_corner X:" << g.left_up_corner[0] << endl
				<< "Left_up_corner Y:" << g.left_up_corner[1] << endl
				<< "Right_down_corner X:" << g.right_down_corner[0] << endl
				<< "Right_down_corner Y:" << g.right_down_corner[1] << endl;
		}

		return out;
	}
};










class Telematics{
private:
	char* identifier;
	long double timestamp;
	long double coords[2];
	int speed;
public:
	Telematics(){
		identifier = new char[strlen("noname") + 1];
		strcpy(identifier, "noname");
		coords[0] = 0;
		coords[1] = 0;
		speed = 0;
	}
	Telematics(char* id, __int64 time, long double* c,int sp){
		identifier = new char[strlen(id) + 1];
		strcpy(identifier,id);
		timestamp = time;
		coords[0] = c[0];
		coords[1] = c[1];
		speed = sp;
	}

	Telematics(const Telematics& t){
		identifier = new char[strlen(t.identifier) + 1];
		strcpy(identifier, t.identifier);
		timestamp = t.timestamp;
		coords[0] = t.coords[0];
		coords[1] = t.coords[1];
		speed = t.speed;
	}

	Telematics& operator=(Telematics& t){
		if (identifier)
			delete identifier;
		identifier = new char[strlen(t.identifier) + 1];
		strcpy(identifier, t.identifier);
		timestamp = t.timestamp;
		coords[0] = t.coords[0];
		coords[1] = t.coords[1];
		speed = t.speed;
		return *this;
	}

	string getIdentifier() const{
		return identifier;
	}

	long double getCoords(int i) const{
		return coords[i];
	}
	long double showTimestamp(){
		return timestamp;
	}
	friend ostream& operator<<(ostream& out, Telematics& t){
		out << "Identifier:" << t.identifier << endl
			<< "Coords:" << t.coords[0] << " " << t.coords[1] << endl
			<< "Speed:" << t.speed << endl
			<< "Time:" << t.timestamp << endl;

		return out;
	}
	friend ofstream& operator<<(ofstream& out, Telematics& t){
		out << t.identifier << endl
			<< t.timestamp << endl
			<< t.coords[0] << endl
			<< t.coords[1] << endl
			<< t.speed << endl;

		return out;
	}
	friend istream& operator>>(istream& in, Telematics& t){
		char text[256];
		long double number;
		int speed;
		cout << "Insert identifier:" << endl;
		in >> text;
		t.identifier = new char[strlen(text) + 1];
		strcpy(t.identifier, text);
		cout << "Insert timestamp:" << endl;
		in >> number;
		t.timestamp = number;
		cout << "Insert coords:" << endl;
		for (int i = 0; i < 2; i++){
			in >> number;
			t.coords[i] = number;
		}
		cout << "Insert speed:" << endl;
		in >> speed;
		t.speed = speed;
		return in;
	}
	friend ifstream& operator>>(ifstream& in, Telematics &t){
		char buffer[256];
		in >> buffer;
		t.identifier = new char[strlen(buffer) + 1];
		strcpy(t.identifier, buffer);
		in >> t.timestamp >> t.coords[0] >> t.coords[1] >> t.speed;
		return in;
	}
	~Telematics(){
		if (identifier)
			delete[] identifier;
	}
};


class File{
protected:
	char name[50];
	ifstream in;
public:
	File(char* name = "nope"){
		strcpy(this->name ,name);
		in.open(this->name);
	}
	~File(){
		in.close();
	}
};

class AutoFile :public File{
private:
	ofstream out;
	vector<Auto> auto_list;
public:
	AutoFile(char* name="nope") :File(name){
		int i = 0;
		while (!in.eof()){
			Auto temp;
			in >> temp;
			auto_list.push_back(temp);
		}
		in.close();
	}


	vector<Auto>const &getAutoList() const {
		return auto_list;
	}

	void setAutoList(vector<Auto> autoList) {
		auto_list = autoList;
	}

};

class GeoFile :public File{
private:
	ofstream out;
	vector<Geofence> rules_list;
public:
	GeoFile(char* name="nope") :File(name){
		int i = 0;
		while (!in.eof()){
			Geofence temp;
			in >> temp;
			rules_list.push_back(temp);
			i++;
		}

		in.close();
	}
	vector<Geofence>const &getRulesList() const {
		return rules_list;
	}

	void setRulesList(vector<Geofence> rulesList) {
		rules_list = rulesList;
	}
};

class TeleFile :public File{
private:
	ofstream out;
	vector<Telematics> telem_list;
public:
	TeleFile(char* name="nope") :File(name){
		int i = 0;
		while (!in.eof()){
			Telematics temp;
			in >> temp;
			telem_list.push_back(temp);
			i++;
		}
		in.close();
	}

	void Append(Telematics& t){
		out.open(name, ios::app);
			out << t << endl;
		out.close();
	}

	vector<Telematics>const &getTelemList() const {
		return telem_list;
	}

	void setTelemList(vector<Telematics> telemList) {
		telem_list = telemList;
	}
};




class Reports{
public:
	long double totalDist(TeleFile &t, string id){
		vector<Telematics> temp;
		long double total = 0;
		temp = t.getTelemList();
		for (unsigned i = 0; i < temp.size() - 1; i++){
			long double distancex = 0;
			long double distancey = 0;
			if (temp.at(i).getIdentifier().compare(id) == 0){
				distancex = (temp.at(i + 1).getCoords(0) - temp.at(i).getCoords(0));
				distancex *= distancex;
				distancey = (temp.at(i + 1).getCoords(1) - temp.at(i).getCoords(1));
				distancey *= distancey;
				total += sqrt(distancex + distancey);
			}
		}
		return total;
	}
	int autoNumber(AutoFile &a){
		vector<Auto> temp;
		temp = a.getAutoList();
		return temp.size();
	}
	int teleNumber(TeleFile &t){
		vector<Telematics> temp;
		temp = t.getTelemList();
		return temp.size();
	}
	int geoNumber(GeoFile &g){
		vector<Geofence> temp;
		temp = g.getRulesList();
		return temp.size();
	}
	vector<Telematics> geoAlerts(GeoFile &g, TeleFile &t, string id, int option){
		vector<Geofence> tempg;
		vector<Telematics> tempt;
		vector<Telematics> geocompliant;
		tempg = g.getRulesList();
		tempt = t.getTelemList();
		unsigned i = 0;

		for (i = 0; i < tempt.size(); i++){
			if (id.compare(tempt.at(i).getIdentifier()) == 0)
				if (tempg.at(option).getIdentifier().compare("rectangle") == 0){
				if ((tempt.at(i).getCoords(0) >= tempg.at(option).getLeftUpCorner(0)) &&
					(tempt.at(i).getCoords(1) <= tempg.at(option).getLeftUpCorner(1)) &&
					(tempt.at(i).getCoords(0) <= tempg.at(option).getRightDownCorner(0)) &&
					(tempt.at(i).getCoords(1) >= tempg.at(option).getRightDownCorner(1))){
					geocompliant.push_back(tempt.at(i));
				}
				}
				else
				{
					double dx = sqrt(tempt.at(i).getCoords(0) - tempg.at(option).getPoint(0));
					double dy = sqrt(tempt.at(i).getCoords(1) - tempg.at(option).getPoint(1));
					dx *= dx;
					dy *= dy;
					double d = sqrt(dx + dy);
					double r = tempg.at(option).getRadius();
					if (d <= r){
						geocompliant.push_back(tempt.at(i));
					}
				}
		}
			return geocompliant;
			
	}

	double Consumption(vector<Telematics> geocompliant, string restriction, AutoFile &a){
		if (geocompliant.size() != 0){
			vector<Auto> temp_a = a.getAutoList();
			Auto temp;
			double Consumption = 0;
			double Distance = 0;
			temp = temp_a.at(0);
			for (unsigned i = 0; i < geocompliant.size() - 1; i++){
				double dx = (geocompliant.at(i + 1).getCoords(0) - geocompliant.at(i).getCoords(0))*
					(geocompliant.at(i + 1).getCoords(0) - geocompliant.at(i).getCoords(0));
				double dy = (geocompliant.at(i + 1).getCoords(1) - geocompliant.at(i).getCoords(1))*
					(geocompliant.at(i + 1).getCoords(1) - geocompliant.at(i).getCoords(1));
				Distance += dx + dy;
			}
			if (restriction == "red"){
				Consumption = (Distance*temp.getAvgConsumptionUrban()) / 100;
			}
			else
				Consumption = (Distance*temp.getAvgConsumption()) / 100;

			return Consumption;
		}
		else{
			cout << "The specified auto didn't go through the zone" << endl;
			return 0;
		}
			
	}




};