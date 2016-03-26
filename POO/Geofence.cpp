#include<iostream>
#include<fstream>
#include<string>
using namespace std;

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

	Geofence(Geofence& g){
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

	friend ifstream& operator>>(ifstream&, Geofence&);
	friend istream& operator>>(istream&, Geofence&);
	friend ostream& operator<<(ostream&, Geofence&);
	friend ofstream& operator<<(ofstream&, Geofence&);
};

ostream& operator<<(ostream& out, Geofence& g){
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

ofstream& operator<<(ofstream& out, Geofence& g){
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

istream& operator>>(istream& in, Geofence& g){
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

ifstream& operator>>(ifstream& in, Geofence& g){
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