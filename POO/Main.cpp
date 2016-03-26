#include<fstream>
#include<iostream>
#include<Windows.h>
#include "Classes.cpp"



int main(int argc, char* argv[]){
	char file1[50];
	char file2[50];
	char file3[50];
	ifstream fileopen;

	if (argc != 4){
		cout << "Incorrect number of parameters";
		return 1;
	}
	else
	{
		strcpy(file1,argv[1]);
		strcpy(file2,argv[2]);
		strcpy(file3,argv[3]);

		try{
			fileopen.open(file1);
		}
		catch (exception e2){
			cout << "Error opening auto.txt" << endl;
			return 2;
		}
		try{
			fileopen.open(file2);
		}
		catch (exception e3){
			cout << "Error opening geofence.txt" << endl;
			return 3;
		}
		try{
			fileopen.open(file3);
		}
		catch (exception e4){
			cout << "Error opening telematics.txt" << endl;
			return 4;
		}
		cout << "Please wait..." << endl;
		AutoFile a(file1);
		GeoFile g(file2);
		TeleFile t(file3);
		vector<Telematics> auto1circr;
		vector<Telematics> auto1circg;
		vector<Telematics> auto1rectg;
		vector<Telematics> auto2circr;
		vector<Telematics> auto2circg;
		vector<Telematics> auto2rectg;
		vector<Telematics> auto3circr;
		vector<Telematics> auto3circg;
		vector<Telematics> auto3rectg;
		Reports r;
		auto1circr = r.geoAlerts(g, t, "auto1", 0);
		auto1rectg = r.geoAlerts(g, t, "auto1", 1);
		auto1circg = r.geoAlerts(g, t, "auto1", 2);
		auto2circr = r.geoAlerts(g, t, "auto2", 0);
		auto2rectg = r.geoAlerts(g, t, "auto2", 1);
		auto2circg = r.geoAlerts(g, t, "auto2", 2);
		auto3circr = r.geoAlerts(g, t, "auto3", 0);
		auto3rectg = r.geoAlerts(g, t, "auto3", 1);
		auto3circg = r.geoAlerts(g, t, "auto3", 2);
		string auto_name;
		int option;
		cout << "***********************************GREENDRIVING*********************************************" << endl;
		cout << "1-Number of autos" << endl;
		cout << "2-Number of telematic points" << endl;
		cout << "3-Number of rules" << endl;
		cout << "4-Distance travelled" << endl;
		cout << "5-Total consumption" << endl;
		cout << "6-Timestamp of entrance" << endl;
		cout << "7-Timestamp of exit" << endl;
		cout << "8-Insert new telematic point" << endl;
		cout << "0-Exit" << endl;
		cin >> option;
		while (option != 0){
			switch (option){
			case 1:
				cout <<"Number of cars:"<< r.autoNumber(a) << endl;
				break;
			case 2:
				cout <<"Number of points:"<<r.teleNumber(t) << endl;
				break;
			case 3:
				cout <<"Number of rules:"<< r.geoNumber(g) << endl;
				break;
			case 4:
				cout << "Insert auto identifier" << endl;
				cin >> auto_name;
				cout<<r.totalDist(t, auto_name)<<endl;
				break;
			case 5:
				cout << "Insert auto identifier" << endl;
				cin >> auto_name;
				if (auto_name == "auto1"){
					cout << "Red Circle:" <<r.Consumption(auto1circr,"red",a)<< endl;
					cout << "Green Rectangle:" << r.Consumption(auto1rectg, "green", a) << endl;
					cout << "Green Circle:" << r.Consumption(auto1circg, "green", a) << endl;
				}
				else
					if (auto_name == "auto2"){
					cout << "Red Circle:" << r.Consumption(auto2circr, "red", a) << endl;
					cout << "Green Rectangle:" << r.Consumption(auto2rectg, "green", a) << endl;
					cout << "Green Circle:" << r.Consumption(auto2circg, "green", a) << endl;
					}
					else{
						cout << "Red Circle:" << r.Consumption(auto2circr, "red", a) << endl;
						cout << "Green Rectangle:" << r.Consumption(auto2rectg, "green", a) << endl;
						cout << "Green Circle:" << r.Consumption(auto2circg, "green", a) << endl;
					}
				break;
			case 6:
				cout << "Insert auto identifier" << endl;
				cin >> auto_name;
				if (auto_name == "auto1"){
					cout << "Red Circle:";
					if (auto1circr.size() != 0)
						cout << auto1circr.at(0).showTimestamp() << endl;
					else
						cout << "auto never entered zone" << endl;
					cout << "Green Rectangle:"; 
					if (auto1rectg.size() != 0)
					cout<<auto1rectg.at(0).showTimestamp()<<endl;
					else
						cout << "auto never entered zone" << endl;
					cout << "Green Circle:"; 
					if (auto1circg.size()!=0)
					cout<<auto1circg.at(0).showTimestamp()<<endl;
					else
						cout << "auto never entered zone" << endl;
				}
				else
					if (auto_name == "auto2"){
					cout << "Red Circle:";
					if (auto2circr.size() != 0)
						cout << auto2circr.at(0).showTimestamp() << endl;
					else
						cout << "auto never entered zone" << endl;
					cout << "Green Rectangle:";
					if (auto2rectg.size() != 0)
						cout << auto2rectg.at(0).showTimestamp() << endl;
					else
						cout << "auto never entered zone" << endl;
					cout << "Green Circle:";
					if (auto2circg.size() != 0)
						cout << auto2circg.at(0).showTimestamp() << endl;
					else
						cout << "auto never entered zone" << endl;
					}
					else{
						cout << "Red Circle:";
						if (auto3circr.size() != 0)
							cout << auto3circr.at(0).showTimestamp() << endl;
						else
							cout << "auto never entered zone" << endl;
						cout << "Green Rectangle:";
						if (auto3rectg.size() != 0)
							cout << auto3rectg.at(0).showTimestamp() << endl;
						else
							cout << "auto never entered zone" << endl;
						cout << "Green Circle:";
						if (auto3circg.size() != 0)
							cout << auto3circg.at(0).showTimestamp() << endl;
						else
							cout << "auto never entered zone" << endl;
					}
					
					break;
			case 7:
				cout << "Insert auto identifier" << endl;
				cin >> auto_name;
				if (auto_name == "auto1"){
					if (auto_name == "auto1"){
						cout << "Red Circle:";
						if (auto1circr.size() != 0)
							cout << auto1circr.at(auto1circr.size()-1).showTimestamp() << endl;
						else
							cout << "auto never entered zone" << endl;
						cout << "Green Rectangle:";
						if (auto1rectg.size() != 0)
							cout << auto1rectg.at(auto1rectg.size()-1).showTimestamp() << endl;
						else
							cout << "auto never entered zone" << endl;
						cout << "Green Circle:";
						if (auto1circg.size() != 0)
							cout << auto1circg.at(auto1circg.size()-1).showTimestamp() << endl;
						else
							cout << "auto never entered zone" << endl;
					}
				}
				else
					if (auto_name == "auto2"){
					cout << "Red Circle:";
					if (auto2circr.size() != 0)
						cout << auto2circr.at(auto2circr.size()-1).showTimestamp() << endl;
					else
						cout << "auto never entered zone" << endl;
					cout << "Green Rectangle:";
					if (auto2rectg.size() != 0)
						cout << auto2rectg.at(auto2rectg.size()-1).showTimestamp() << endl;
					else
						cout << "auto never entered zone" << endl;
					cout << "Green Circle:";
					if (auto2circg.size() != 0)
						cout << auto2circg.at(auto2circg.size()-1).showTimestamp() << endl;
					else
						cout << "auto never entered zone" << endl;
					}
					else{
						cout << "Red Circle:";
						if (auto3circr.size() != 0)
							cout << auto3circr.at(auto3circr.size()-1).showTimestamp() << endl;
						else
							cout << "auto never entered zone" << endl;
						cout << "Green Rectangle:";
						if (auto3rectg.size() != 0)
							cout << auto3rectg.at(auto3rectg.size()-1).showTimestamp() << endl;
						else
							cout << "auto never entered zone" << endl;
						cout << "Green Circle:";
						if (auto3circg.size() != 0)
							cout << auto3circg.at(auto3circg.size()-1).showTimestamp() << endl;
						else
							cout << "auto never entered zone" << endl;
					}
					break;
			case 8:
				Telematics insert;
				cout << "Insert telematic point:" << endl;
				cin >> insert;
				t.Append(insert);
				break;

			}
			cout << "Press another key" << endl;
			cin >> option;


		}
		return 0;
	}
}