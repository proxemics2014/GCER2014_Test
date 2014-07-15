#ifndef TELEOPPIONEER_H_
#define TELEOPPIONEER_H_

namespace std {

class TeleopPioneer
{
public:
	TeleopPioneer() {
		linear_ = 1;
		angular_ = 1;
		flag = 1;
	}
	//void usr_drive();
	//void auto_drive(int);
	int joyCallBack();
	int joyCall();
	int linear_;
	int angular_;
	int flag;
};
/*
void TeleopPioneer::auto_drive(int count)
{
	if (count % 2 == 0)
	{
		cout << "\nRobot is automatically driving to the nearest location!";
		//cout<<"\nSound Played!";
		system("start WINNER.mp3");
		cout << "\nI am the nearest position!";
	}
	else
	{
		cout << "\nRobot is automatically driving to the farthest location!";
		// cout<<"\nSound Played!";
		system("start WINNER.mp3");
		cout << "\nI am at the farthest position!";
	}
}
/*void TeleopPioneer::usr_drive()
{
	char u;
	cout << "\nEnter Controller: ";
	cin >> u;
	this->joyCallBack(u);

}
*/
int TeleopPioneer::joyCall()
{
	cout << "Inside wii-mote function!\n";
	return 0;
}
int TeleopPioneer::joyCallBack()
{
	//if(joy->buttons[10]==1)
/*	if (a == 'W' || a == 'w') {
		flag = 0;
		cout << "Switching to Wii-Mote Controller!\n";
		joyCall();
	}
	*/
	int n;
//	if(joy->buttons[11]==1)
	//if (a == 'R' || a == 'r') {
		flag = 1;
		cout << "Working with PS3 Controller!";
		cout << "\nEnter number(4,5,6,7) : ";
		cin >> n;
//		if(joy->buttons[4]==1)
		if (n == 4) {
			// vel.linear.x = 0.2*joy->buttons[4];
			cout << "You are going up!\n";
		}
		if (n == 5) {
			cout << "You are going right!\n";
		}
		if (n == 6) {
			cout << "You are going down!\n";
		}
		if (n == 7) {
			cout << "You are going left!\n";
		}
		if (n == 9) {
			cout << "Stopped!";
		}
		return 0;
//	}
}

} /* namespace std */

#endif /* TELEOPPIONEER_H_ */
