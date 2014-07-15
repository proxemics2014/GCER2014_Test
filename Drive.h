/*
 * Drive.h
 *
 *  Created on: Jul 14, 2014
 *      Author: Aditya
 */

#ifndef DRIVE_H_
#define DRIVE_H_

#include <iostream>
double drive();
void user_drive();
void auto_drive(float position);
double read_artag();
using namespace std;
TeleopPioneer test;
double drive()
{
//	if(R1 == HELD)
	double val;
	char button;
	cout<<"Enter button pressed: ";
	cin>>button;
	if(button=='R' || button =='r')
	{
		cout<<"PS3 controller used to drive the robot. Robot being operated by operator\n";
		test.joyCallBack();
	}
	if(button=='L' || button =='l')
	{
		cout<<"Switching to Wii-mote controller.\n";
		test.joyCall();
		user_drive();
	}
 srand (time(NULL));
 val = read_artag();
 return val;
}
void user_drive()
{
	char button;
	do
	{
	cout<<"User driving robot";
	cout<<"Enter Button A to exit!!";
	cin>>button;
	}	while(button=='A' || button =='a');
}

void auto_drive(float position)
{
	float temp = read_artag();
	if(position!=temp)
	{
		cout<<"Robot is at: "<<temp<<endl;
		cout<<"Robot is driving to: "<<position<<endl;
		cout<<"Driving robot to desired location!\n";
	}
	else
	{
		cout<<"Stop."<<endl;
	}
}

double read_artag() {
	double val;
	val = rand() % 5 + 1;
	cout<< "Returning ARTag reading that is the distance between human and robot!\n";
	return val;
}

#endif /* DRIVE_H_ */
