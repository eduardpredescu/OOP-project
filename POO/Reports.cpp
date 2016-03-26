#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Auto.cpp"
#include"Geofence.cpp"
#include"Telematics.cpp"
#include"Files.cpp"
using namespace std;


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
	vector<Telematics> geoAlertsRectangle(GeoFile &g, TeleFile &t, string id, int option){
		vector<Geofence> tempg;
		vector<Telematics> tempt;
		vector<Telematics> geocompliant;
		tempg = g.getRulesList();
		tempt = t.getTelemList();
		int i = 0;

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
		vector<Auto> temp_a = a.getAutoList();
		Auto temp;
		double Consumption = 0;
		double Distance = 0;
		for (int i = 0; i < temp_a.size(); i++)
			if (geocompliant.at(0).getIdentifier().compare(temp_a.at(i).getIdentifier()) == 0){
			temp = temp_a.at(i);
			break;
			}
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




};