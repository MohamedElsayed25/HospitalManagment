#include<iostream>
using namespace std;
const int maxLength=5;
const int maxSpecial=20;
string names[maxSpecial + 1][maxLength];
int statis[maxSpecial + 1][maxLength];
int queueLength[21]{ 0 };

int menue()
{
	int choice = -1;
	while (choice == -1)
	{
		cout << "Enter your choice\n";
		cout << "1) Add new patient\n";
		cout << "2) Print all patient\n";
		cout << "3) Get next patient\n";
		cout << "4) Exit\n";
		cin >> choice;
		if (!(choice >= 1 && choice <= 4))
		{
			cout << "invalide choice\n";
			choice = -1;
		}
	}
	return choice;
}
void shiftRight(int spe ,string name[],int stat[])
{
	int len = queueLength[spe];
	for (int i = len - 1; i >= 0; i--)
	{
		name[i + 1] = name[i];
		stat[i + 1] = stat[i];
	}
	queueLength[spe]++;
}
void shiftLift(int spe, string name[], int stat[])
{
	int len = queueLength[spe];
	for (int i = 1; i <len; i++)
	{
		name[i -1] = name[i];
		stat[i - 1] = stat[i];
	}
	queueLength[spe]--;

}
bool add_patient()
{
	string name;
	int sta, spe;
	cout << "Enter specalization,name,statis: ";
	cin >> spe >> name >> sta;
	int pos = queueLength[spe];
	if (pos >= maxLength)
	{
		cout << "the specialization is full" << endl;
		return false;
	}
	if (sta == 0)
	{
		names[spe][pos] = name;
		statis[spe][pos] = sta;
		queueLength[spe]++;
		
	}
	else {
		shiftRight(spe, names[spe], statis[spe]);
		names[spe][0] = name;
		statis[spe][0] = sta;
		
	}
	return true;
}
void printPatient(int spe,string name[],int stat[])
{
	
	int len = queueLength[spe];
	if (len == 0)
	{
		return;
	}
	cout << "there are " << len << " in specializatio " << spe << endl;
	for (int i = 0; i < len; i++)
	{
		cout << name[i] << " ";
		if (stat[i])
			cout << "Uregant" << endl;
		else
			cout << "Regular" << endl;
	}
}
void printAllPatients()
{
	cout << "****************************\n";
	for (int i = 0; i < maxSpecial; i++)
	{
		printPatient(i,names[i],statis[i]);
	}
}
void getNext()
{
	int spe;
	cout << "Enter specializatio: \n";
	cin >> spe;
	int len = queueLength[spe];
	if (len == 0)
	{
		cout << "NO ptient now take a rest doctor"<<endl ;
		return;
	}
	
		cout << names[spe][0] << " go to the doctor please\n";
		shiftLift(spe, names[spe], statis[spe]);
	
}
void system()
{
	while (true)
	{
		int choice = menue();
			if (choice == 1)

				add_patient();
			else if (choice == 2)
				printAllPatients();
			else if (choice == 3)
				getNext();
			else 
				break;

	}
}
int main()
{
	system();
	return 0;
}