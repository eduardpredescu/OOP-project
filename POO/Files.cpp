#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Auto.cpp"
#include"Geofence.cpp"
#include"Telematics.cpp"
using namespace std;



class File{
protected:
	string name;
	ifstream in;
public:
	File(string name = ""){
		this->name = name;
		in.open(this->name.c_str());
	}
	virtual void virtualizer() = 0;
};

class AutoFile :public File{
private:
	ofstream out;
	vector<Auto> auto_list;
public:
	AutoFile(string name) :File(name){
		int i = 0;
		while (!in.eof()){
			in >> auto_list.at(i);
			i++;
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
	GeoFile(string name) :File(name){
		int i = 0;
		while (!in.eof()){
			in >> rules_list.at(i);
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
	TeleFile(string name) :File(name){
		int i = 0;
		while (!in.eof()){
			in >> telem_list.at(i);
			i++;
		}

		in.close();
	}

	void Append(string t){
		ifstream file;
		string buffer;
		file.open(t);
		out.open(name.c_str(), ios::app);
		while (!file.eof()){
			file >> buffer;
			out << buffer << endl;
		}
		file.close();
		out.close();
	}

	vector<Telematics>const &getTelemList() const {
		return telem_list;
	}

	void setTelemList(vector<Telematics> telemList) {
		telem_list = telemList;
	}
};