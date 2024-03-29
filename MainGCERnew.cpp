#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TeleopPioneer.h"
#include "Drive.h"
using namespace std;


// functions
void write_dist(double);
void functionCall();
void generate_perf_dists();
// double read_artag();  returns distance between human and robot
// double write_dist_moved();

// number of conditions
int n_comfort = 6;
int n_perf_exp = 6;
int min_n_pref = 2;

// return positions
double dist_near = 0.25;
double dist_far = 5.0;
double dist_choice = 0.0;

// selected distances
const int n_dists = 10;
float dist[n_dists] = {0.25, 0.75, 1.25, 1.75, 2.25, 2.75, 3.25, 3.75, 4.25,4.75};

//function definitions
void write_dist(double vale) {
	// move to this position
	cout << "\n Writing distance to file";
	ofstream myfile;
	myfile.open("write.csv", ios::ate | ios::app);
	if (myfile.is_open()) {
		myfile << vale << ",";
		myfile.close();
	} else {
		cout << "Unable to open file!";
	}
}

void functionCall()
{
	int y;
	ifstream myfile;
	myfile.open("UserID.txt");
	if (myfile.is_open()) {
		myfile >> y;   // change it to READ SYSTEM TIME
	} else {
		cout << "\nUnable to open file!";
	}
	y = y + 1;
	ofstream out;
	out.open("UserID.txt", ios::ate);
	out << y;
	out.close();
	int uid = y;
	ofstream in;
	in.open("write.csv", ios::ate | ios::app);
	if (in.is_open()) {
		in << "\n" << uid << ",";
		in.close();
	} else {
		cout << "\nUnable to open file!";
	}
}
float random_num_gen ()
{
	float value;
//	srand (time(NULL));
	value = dist[int(rand()%10)];
	return value;
}
void generate_perf_dists()
{
	float gpd;
	cout << "Writing distance to file\n Robot is automatically moving to point. ";
	// auto_drive(value);
	gpd = random_num_gen();
	// auto_drive(gpd);
	ofstream myfile;
	myfile.open("write.csv", ios::ate | ios::app);
	if (myfile.is_open()) {
		myfile << gpd << ",";
		myfile.close();
	} else {
		cout << "Unable to open file!";
	}
}
// main function
int main() {
	//int v;
	// open file!!
	functionCall();
	// int count = 0;
	// TeleopPioneer Test[6];
	double comf_dist[n_comfort];
	//int len = int(sizeof(comf_dist)/sizeof(double));
	for (int i = 0; i < 3; ++i)
	{
		//user_drive();
		comf_dist[i] = drive();
		// comf_dist[i] = read_artag();
		write_dist(comf_dist[i]);
		// return_dist =
		//auto_drive(i);*/
    }
	dist_choice = (comf_dist[0] + comf_dist[1]) / 2; // calculating the choice position

	// performance exploration
	//float perf_exp_dist[n_perf_exp];
	for (int i = 0; i < n_perf_exp; i++)
	{
		// srand (time(NULL));
		generate_perf_dists(); // generate_performance dists is a function
	}
}
