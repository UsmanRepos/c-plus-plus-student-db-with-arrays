#include<iostream>
#include<string>
#define SIZE 70
#define SUB 3
using namespace std;


void mySetter(int sr[], string sn[], int sm[][SUB], double sa[], char sg[], int& nn)
{
	cout << " Enter The Total Number Of Students: ";
	while (true)
	{
		cin >> nn;
		if (nn < 70 && nn > 0)
		{
			break;
		}
		else
			cout << " Invalid Range !!! \n Enter Again: ";
	}

	for (int i = 0; i < nn; i++)
	{
		int sum = 0;
		cout << "\n Enter Data For Student No " << i + 1 << endl;

		cout << " Enter RegNo: ";
		while (true)
		{
			cin >> sr[i];
			if (sr[i] > 1000 && sr[i] < 9999)
				break;
			else
				cout << " Invalid Range !!! \n Enter Again: ";
		}

		cin.ignore(10, '\n');
		cout << " Enter Name: ";
		getline(cin, sn[i]);

		cout << " Enter Marks: ";
		for (int j = 0; j < SUB; j++)
		{
			cin >> sm[i][j];
			sum += sm[i][j];  
		}
		sa[i] = (sum * 1.0) / SUB;

		if (sa[i] >= 80)
			sg[i] = 'A';
		else if (sa[i] >= 70)
			sg[i] = 'B';
		else if (sa[i] >= 60)
			sg[i] = 'C';
		else if (sa[i] >= 50)
			sg[i] = 'D';
		else
			sg[i] = 'F';
	}
}
void myGetter(int sr[], string sn[], int sm[][SUB], double sa[], char sg[], int nn)
{
	cout << "\n RegNo \t Stu Name \t Sub_1  Sub_2  Sub_3  Average Grade \n";
	for (int i = 0; i < nn; i++)
	{
		cout << " " << sr[i] <<"    " << sn[i] << "    ";
		for (int j = 0; j < SUB; j++)
		{
			cout << sm[i][j] << "    ";
		}
		cout <<" " << sa[i] << "    " << sg[i] << endl;
	}
}

void mySort(int sr[], string sn[], int sm[][SUB], double sa[], char sg[], int nn)
{
	for (int i = 0; i < nn - 1; i++)
	{
		for (int j = i + 1; j < nn; j++)
		{
			if (sr[i] > sr[j])
			{
				swap(sr[i], sr[j]);
				swap(sn[i], sn[j]);
				for (int k = 0; k < SUB; k++)
				{
					swap(sm[i][k], sm[j][k]);
				}
				swap(sa[i], sa[j]);
				swap(sg[i], sg[j]);
			}
		}
	}
}
void myInsert(int sr[], string sn[], int sm[][SUB], double sa[], char sg[], int& nn)
{
	int sum = 0;
	cout << "\n Enter Data For Student You Want To Insert ... " << endl;

	cout << " Enter RegNo: ";
	while (true)
	{
		cin >> sr[nn];
		if (sr[nn] > 1000 && sr[nn] < 9999)
			break;
		else
			cout << " Invalid Range !!! \n Enter Again: ";
	}

	cin.ignore(10, '\n');
	cout << " Enter Name: ";
	getline(cin, sn[nn]);

	cout << " Enter Marks: ";
	for (int j = 0; j < SUB; j++)
	{
		cin >> sm[nn][j];
		sum += sm[nn][j];
	}
	sa[nn] = (sum * 1.0) / SUB;

	if (sa[nn] >= 80)
		sg[nn] = 'A';
	else if (sa[nn] >= 70)
		sg[nn] = 'B';
	else if (sa[nn] >= 60)
		sg[nn] = 'C';
	else if (sa[nn] >= 50)
		sg[nn] = 'D';
	else
		sg[nn] = 'F';

	nn++;
}

void myDelete(int sr[], string sn[], int sm[][SUB], double sa[], char sg[], int& nn)
{
	int  regNo, index;
	bool flag = false;

	cout << "\n Enter RegNo Of Student You Want To Delete: ";
	cin >> regNo;

	for (int i = 0; i < nn; i++)
	{
		if (sr[i] == regNo)
		{
			index = i;
			flag = true;
			break;
		}
	}
	if (flag)
	{
		for (int i = index; i < nn; i++)
		{
			sr[i] = sr[i + 1];
			sn[i] = sn[i + 1];

			for (int j = 0; j < SUB; j++)
			{
				sm[i][j] = sm[i + 1][j];
			}
			sa[i] = sa[i + 1];
			sg[i] = sg[i + 1];
		}
		nn--;
	}
	else
		cout << " Given RegNo does Not Exist ... \n";

}
void myUpdate(int sr[], string sn[], int sm[][SUB], double sa[], char sg[], int nn)
{
	int  regNo, index, sum = 0;
	bool flag = false;

	cout << "\n Enter RegNo Of Student You Want To Delete: ";
	cin >> regNo;

	for (int i = 0; i < nn; i++)
	{
		if (sr[i] == regNo)
		{
			index = i;
			flag = true;
			break;
		}
	}
	if (flag)
	{
		cout << "\n Enter Data For Student You Want To Update ... " << endl;

		cin.ignore(10, '\n');
		cout << " Enter Name: ";
		getline(cin, sn[index]);

		cout << " Enter Marks: ";
		for (int j = 0; j < SUB; j++)
		{
			cin >> sm[index][j];
			sum += sm[index][j];
		}
		sa[index] = (sum * 1.0) / SUB;

		if (sa[index] >= 80)
			sg[index] = 'A';
		else if (sa[index] >= 70)
			sg[index] = 'B';
		else if (sa[index] >= 60)
			sg[index] = 'C';
		else if (sa[index] >= 50)
			sg[index] = 'D';
		else
			sg[index] = 'F';
	}
	else
		cout << " Given RegNo does Not Exist ... \n";
}
int main()
{
	int    regNo[SIZE] = { 0 };
	string name[SIZE] = { " " };
	int    subMarks[SIZE][SUB] = { {0} };
	double average[SIZE] = { 0.0 };
	char   grade[SIZE] = { ' ' };
	char   ch;
	int    n;

	while (true) {

		cout << "\n -----------(MAIN MENU)----------\n";
		cout << " 1) SETTER \n";
		cout << " 2) GETTER \n";
		cout << " 3) SORTING \n";
		cout << " 4) INSERTION \n";
		cout << " 5) DELETION \n";
		cout << " 6) UPDATION \n";
		cout << " 7) EXIT \n\n";

		cout << " Enter Your Choice: ";
		cin >> ch;

		switch (ch) {
		case '1':
			mySetter(regNo, name, subMarks, average, grade, n);
			break;
		case '2':
			myGetter(regNo, name, subMarks, average, grade, n);
			break;
		case '3':
			mySort(regNo, name, subMarks, average, grade, n);
			break;
		case '4':
			myInsert(regNo, name, subMarks, average, grade, n);
			break;
		case '5':
			myDelete(regNo, name, subMarks, average, grade, n);
			break;
		case '6':
			myUpdate(regNo, name, subMarks, average, grade, n);
			break;
		case '7':
			exit(-1);
		default:
			cout << "\n Invalid Input !!! \n Enter Again ....\n";
		}
	}

}