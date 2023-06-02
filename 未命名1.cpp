#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Bank{
	private:
		string account;
		string startTime;
		double remains;
		double* currentRecords;
		double* lastRecords;
		int lenOfRecords;
		vector<string> currentDate;
		vector<string> lastDate;
	public:
		Bank(string name, string nowDate, double money);
		~Bank(){
			cout << account << " ÒÑ¾­±»É¾³ý" << endl; 
		}
		bool jiaoyi(double numOfMoney, string nowDate);
		void changeMonth();
		void check();
};
Bank::Bank(string name, string nowDate, double money):
	account(name), startTime(nowDate), remains(money)
{
	lenOfRecords = 1;
	currentRecords = new double[lenOfRecords];
	currentRecords[0] = money;
	currentDate.push_back(nowDate);
}
bool Bank::jiaoyi(double numOfMoney, string nowDate)
{
	double buf[lenOfRecords];
	for (int i = 0;i < lenOfRecords;i++)
		buf[i] = currentRecords[i];
	currentRecords = new double[++lenOfRecords];
	for (int i = 0;i < lenOfRecords - 1;i++)
		currentRecords[i] = buf[i];
	currentReords[lenOfRecordds - 1] = numOfMoney;
}
int main()
{
	int a[5] = {1,2,3,4,5};
	cout << sizeof(a) / sizeof(a[0]) << endl;
	getlen(a);
	return 0;
}
