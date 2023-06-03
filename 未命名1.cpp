#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
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
        void showBrief();
        void start(Bank* b1);
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
    if(remains + numOfMoney < 0)
    {
        cout << "余额不足" << endl;
        return false;
    }
    remains += numOfMoney;
    if(lenOfRecords == 0){
        currentDate.push_back(nowDate);
        currentRecords = new double[++lenOfRecords];
        currentRecords[0] = numOfMoney;
        return true;
    }
	double* buf = new double[lenOfRecords];
	for (int i = 0;i < lenOfRecords;i++)
		buf[i] = currentRecords[i];
	currentRecords = new double[++lenOfRecords];
	for (int i = 0;i < lenOfRecords - 1;i++)
		currentRecords[i] = buf[i];
	currentRecords[lenOfRecords - 1] = numOfMoney;
    currentDate.push_back(nowDate);
    delete []buf;
    if(currentDate.size() >= 31){
        changeMonth();
    }
    return true;
}
void Bank::check()
{
        for (int i = 0;i < lenOfRecords;i++){
            cout << currentDate[i] << '\t' << currentRecords[i]
            << endl;
        }
        for (int i = 0;i < lastDate.size();i++){
            cout << lastDate[i] << '\t' << lastRecords[i]
            <<endl;
        }
        if (lastDate.size() == 0 && currentDate.size() == 0)
        {
            cout << "未查询到交易记录..."  << endl;
        }
        return ;
}
void Bank::changeMonth()
{
    lastRecords = new double[lenOfRecords];
    for (int i = 0;i < lenOfRecords;i++){
        lastRecords[i] = currentRecords[i];
        lastDate.emplace_back(currentDate[i]);
    }
    lenOfRecords = 0;
}
void Bank::showBrief()
{
    cout << "account: " << account
    << "\nstartTime: " << startTime
    << "\nremains: " << remains << endl;
}
void Bank::start(Bank* b1)
{
    cout << "welcome to Bank management system" << endl;
    while(1){
        cout << "请选择您的服务(输入对应数字获取服务)" << endl;
        cout << "1.创建账户\n" << "2.登录(未开放)\n"
        << "3.存钱\n" << "4.取钱\n" << "5.保存(未开放)\n" 
        << "6.查询记录\n" << "7.信息显示\n" << "8.退出\n";
        int res = 0;
        cin >> res;
        while(res <= 0 || res > 8){
            cout << "请输入正确数字\n" ;
            cin >> res;
        }
        switch(res){
            case 1:{
                string newName;
                string newDate;
                double newRemains;
                bool reSure = false;
                do{
                    cout << "请输入账户名 >";
                    cin >> newName; 
                    cout << "请输入日期 >";
                    cin >> newDate;
                    cout << "请输入余额 >";
                    cin >> newRemains;
                    cout << "账户基础信息如下: \n"
                    << "账户名：" <<newName<<endl
                    <<"创建日期: " << newDate<<endl
                    <<"存入金额: " << newRemains<<endl
                    << "是否创建?[y/n]";
                    char sign =  'n';
                    cin >> sign;
                    if (sign == 'y')
                        reSure = true;
                }while(!reSure);
                b1 = new Bank(newName, newDate, newRemains);
                cout << "账户创建成功" << endl;
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                if(b1 == nullptr){
                    cout << "请先创建账户\n";
                    break;
                }
                double money = 0;
                cout << "请输入存入金额\n";
                cin >> money;
                while(money <= 0){
                    cout << "存入金额必须大于零\n";
                    cin >> money;
                }
                cout << "请输入日期\n";
                string nowDate;
                cin >> nowDate;
                b1->jiaoyi(money, nowDate);
                break;
            }
            case 4:{
                if(b1 == nullptr){
                    cout << "请先创建账户\n";
                    break;
                }
                double money = 0;
                cout << "请输入取出金额\n";
                cin >> money;
                while(money <= 0){
                    cout << "取出金额必须大于零\n";
                    cin >> money;
                }
                cout << "请输入日期\n";
                string nowDate;
                cin >> nowDate;
                b1->jiaoyi(-money, nowDate);
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                b1->check();
                break;
            }
            case 7:{
                b1->showBrief();
                break;
            }
            case 8:{
                exit(1);
            }
            default:
                break;
        }
    }
}
int main()
{
    Bank* b, * b1;
    b->start(b1);
	return 0;
}
