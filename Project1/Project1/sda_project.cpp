#include<iostream>
#include<string>
#include <stdlib.h>
#include <fstream>
using namespace std;

class card
{
private:
	string expirydate;
public:
	card()
	{
		expirydate = ".";
	}
	card(string edate)
	{
		expirydate = edate;
	}
	string getedate()
	{
		return expirydate;
	}
	void setedate(string edate)
	{
		expirydate = edate;
	}
	virtual void print()
	{};
};
class goldcard : public card
{
private:
	float discount;
public:
	goldcard()
	{
		discount = 0.15;
		setedate(".");
	}
	goldcard(string edate)
	{
		discount = 0.15;
		setedate(edate);
	}
	float getdiscount()
	{
		return discount;
	}
	void print()
	{
		cout << "Discount Offered: " << 0.15 * 100 << "%" << endl;
		cout << "Expiry Date: " << getedate() << endl;
	}
};
class platinumcard : public card
{
private:
	float discount;
public:

	platinumcard()
	{
		discount = 0.2;
		setedate(".");
	}
	platinumcard(string edate)
	{
		discount = 0.2;
		setedate(edate);
	}
	float getdiscount()
	{
		return discount;
	}
	void print()
	{
		cout << "Discount Offered: " << 0.2 * 100 << "%" << endl;
		cout << "Expiry Date: " << getedate() << endl;
	}
};
class silvercard : public card
{
private:
	float discount;
public:
	silvercard()
	{
		discount = 0.1;
		setedate(".");
	}
	silvercard(string edate)
	{
		discount = 0.1;
		setedate(edate);
	}
	float getdiscount()
	{
		return discount;
	}
	void print()
	{
		cout << "Discount Offered: " << 0.1 * 100 << "%" << endl;
		cout << "Expiry Date: " << getedate() << endl;
	}
};
class item
{
private:
	string name;
	string category;
	int ID;
	string agegroup;
public:
	item()
	{
		name = ".";
		category = ".";
		ID = 0;
		agegroup = ".";
	}
	item(string cat, int id, string age, string n)
	{
		name = n;
		category = cat;
		ID = id;
		agegroup = age;
	}
	void setitem(string cat, int id, string age, string n)
	{
		name = n;
		category = cat;
		ID = id;
		agegroup = age;
	}
	int getitemID()
	{
		return ID;
	}
	string getcategory()
	{
		return category;
	}
	string getagegroup()
	{
		return agegroup;
	}

	string getname() {
		return name;
	}
};
class cart
{
private:
	item* itemlist;
public:
	cart()
	{
		itemlist = nullptr;
	}
};
class customer
{
private:
	string ID;
	string password;
	card* mycard;
	int loyaltypoints;
	string accountstatus;
	string name;
	string address;
	cart* mycart;
public:
	customer()
	{
		ID = "";
		password = "";
		loyaltypoints = 0;
		accountstatus = "";
		mycard = nullptr;
		name = "";
		address = "";
		mycart = nullptr;
	}

	customer(string id, string pass, int lp, string status, string n, string add)
	{
		ID = id;
		password = pass;
		loyaltypoints = lp;
		accountstatus = status;
		mycard = nullptr;
		name = n;
		address = add;
		mycart = nullptr;
	}
	void setcustomer(string id, string pass, int lp, string status, string n, string add)
	{
		ID = id;
		password = pass;
		loyaltypoints = lp;
		accountstatus = status;
		name = n;
		address = add;
	}
	string getid()
	{
		return ID;
	}
	int getloyaltypoints()
	{
		return loyaltypoints;
	}
	string getpass()
	{
		return password;
	}
	string getstatus()
	{
		return accountstatus;
	}
	string getname() {
		return name;
	}
	string getaddress() {
		return address;
	}

	void addToCart() {};

	void issuecard() // use case implementation by Manal. Follows Open/Close Principle.
	{
		if (loyaltypoints <= 10) // no card will be issued due to insufficient loyalty points
		{
			cout << "Dear Customer,We cannot issue you a card due to insufficient loyalty points" << endl;
		}
		if (loyaltypoints > 10 && loyaltypoints <= 20) // silver card will be issued
		{
			cout << "Silver card issued!" << endl;
			mycard = new silvercard("01-01-23");
			mycard->print();
		}
		if (loyaltypoints > 20 && loyaltypoints <= 30)// Gold card will be issued
		{
			cout << "Gold card issued!" << endl;
			mycard = new goldcard("01-01-23");
			mycard->print();
		}
		if (loyaltypoints > 30)// Platinum card will be issued
		{
			cout << "Platinum card issued!" << endl;
			mycard = new platinumcard("01-01-23");
			mycard->print();
		}
	}
};


class checkout
{
private:
	float bill;
	item* itemlist;
public:
	checkout()
	{
		bill = 0.0;
		itemlist = nullptr;
	}
};
class inventorymanager
{
private:
	string ID;
	string password;
public:
	inventorymanager()
	{
		ID = "";
		password = ".";
	}
	inventorymanager(string id, string pass)
	{
		ID = id;
		password = pass;
	}
	string getID()
	{
		return ID;
	}
	string getpass()
	{
		return password;
	}
	void setdetails(string id, string pass)
	{
		ID = id;
		password = pass;
	}
	void functions() {
		cout << "1. Manage Store Inventory" << endl;
		cout << "2. Define/Change Policy" << endl;
		cout << "0.Back" << endl;
	}
};
class inventory
{
private:
	int outletID;
	int* itemquantity;
	item* itemlist;
	int size;
	inventorymanager* Imanager;
public:
	inventory()
	{
		outletID = -1;
		itemquantity = nullptr;
		itemlist = nullptr;
		Imanager = nullptr;
		size = 0;
	}
	inventory(int id, int* quantity, item* list, inventorymanager* m, int s)
	{
		outletID = id;
		itemquantity = quantity;
		itemlist = list;
		Imanager = m;
		size = s;
	}
	int getID()
	{
		return outletID;
	}
	int* getquantity()
	{
		return itemquantity;
	}
	void setquantity(int* q)
	{
		itemquantity = q;
	}
	int getSize() {
		return size;
	}

	void printItemList() {
		//prints the entire inventory for the store and item details. e.g...
		cout << "Select any item to add to cart!" << endl << endl;
		cout << "1. Mini Skirt" << endl;
		cout << "2. Plain T-Shirt" << endl;
		cout << "3. Leather Jacket" << endl;
		cout << "4. Shear Leggings" << endl;
	}
};
class storeadmin
{
private:
	string ID;
	string password;
public:
	storeadmin()
	{
		ID = "";
		password = ".";
	}
	storeadmin(string id, string pass)
	{
		ID = id;
		password = pass;
	}
	string getID()
	{
		return ID;
	}
	string getpass()
	{
		return password;
	}
	void setdetails(string id, string pass)
	{
		ID = id;
		password = pass;
	}

	void functions() {
		cout << "1. Manage Users" << endl;
		cout << "2. Edit Outlet Status" << endl;
		cout << "0.Back" << endl;
	}

};
class storemanager
{
private:
	string ID;
	string password;
public:
	storemanager()
	{
		ID = "";
		password = ".";
	}
	storemanager(string id, string pass)
	{
		ID = id;
		password = pass;
	}
	string getID()
	{
		return ID;
	}
	string getpass()
	{
		return password;
	}
	void setdetails(string id, string pass)
	{
		ID = id;
		password = pass;
	}
	
	void functions() {
		cout << "1. Modify Discount Policy" << endl;
		cout << "2. Run Reports" << endl;
		cout << "0.Back" << endl;
	}
};
class floormanager
{
private:
	string ID;
	string password;
public:
	floormanager()
	{
		ID = "";
		password = ".";
	}
	floormanager(string id, string pass)
	{
		ID = id;
		password = pass;
	}
	string getID()
	{
		return ID;
	}
	string getpass()
	{
		return password;
	}
	void setdetails(string id, string pass)
	{
		ID = id;
		password = pass;
	}

	void functions() {
		cout << "1. Track Employee Attendance" << endl;
		cout << "2. Process Returns" << endl;
		cout << "3. Change Workshift" << endl;
		cout << "0.Back" << endl;
	}
};
class salesagent
{
private:
	string ID;
	string workshift;
public:
	salesagent()
	{
		ID = "";
		workshift = ".";
	}
	salesagent(string id, string ws)
	{
		ID = id;
		workshift = ws;
	}
	string getID()
	{
		return ID;
	}
	string getworkshift()
	{
		return workshift;
	}
	void setdetails(string id, string ws)
	{
		ID = id;
		workshift = ws;
	}
};

class outlet
{
private:
	string city;
	int ID;
	string status;
	storemanager* Smanager;
	inventorymanager* Imanager;
	floormanager* Fmanager;
	salesagent* Sagent;
	storeadmin* admin;
	string discountpolicy;
	inventory* catalog;
public:
	outlet()
	{
		city = ".";
		ID = -1;
		status = ".";
		Smanager = nullptr;
		Imanager = nullptr;
		Fmanager = nullptr;
		Sagent = nullptr;
		admin = nullptr;
		discountpolicy = ".";
		catalog = nullptr;

	}
	outlet(string c, int id, string s, storemanager* sm, inventorymanager* i, floormanager* f, salesagent* sa, storeadmin* a, string dp, inventory* in)
	{
		city = c;
		ID = id;
		status = s;
		Smanager = sm;
		Imanager = i;
		Fmanager = f;
		Sagent = sa;
		admin = a;
		discountpolicy = dp;
		catalog = in;
	}
	string getstatus()
	{
		return status;
	}
	string getpolicy()
	{
		return discountpolicy;
	}
	void setstatus(string s)
	{
		status = s;
	}
	void setpolicy(string p)
	{
		discountpolicy = p;
	}
	void setstoremanager(storemanager* sm)
	{
		Smanager = sm;
	}
	void setinventorymanager(inventorymanager* i)
	{
		Imanager = i;
	}
	void setfloormanager(floormanager* f)
	{
		Fmanager = f;
	}
	void setstoreadmin(storeadmin* a)
	{
		admin = a;
	}
	void setsalesagent(salesagent* sa)
	{
		Sagent = sa;
	}

};
// interface
class productreport
{
public:
	virtual void viewproductreport() = 0;

};
// interface
class salesagentreport
{
public:
	virtual void viewsalesagentreport() = 0;
};
class report : public productreport, salesagentreport
{
public:
	void viewproductreport() {};
	void viewsalesagentreport() {};
};
class attendancesheet
{
private:
	string date;
	salesagent* list;
	bool* checkin;
	bool* checkout;
public:
	attendancesheet()
	{
		list = nullptr;
		checkin = nullptr;
		checkout = nullptr;
		date = ".";
	}
	attendancesheet(string d, salesagent* sa, bool* ci, bool* co)
	{
		date = d;
		list = sa;
		checkin = ci;
		checkout = co;
	}
	void setdate(string d)
	{
		date = d;
	}
	void setagentlist(salesagent* sa)
	{
		list = sa;
	}
	string getdate()
	{
		return date;
	}
	salesagent* getagentlist()
	{
		return list;
	}


};
class attendance
{
private:
	int outletID;
	attendancesheet* sheet;

public:
	attendance()
	{
		outletID = 0;
		sheet = nullptr;
	}
	attendance(int id, attendancesheet* attendance)
	{
		outletID = id;
		sheet = attendance;
	}
	void setoutletID(int id)
	{
		outletID = id;
	}
	int getoutletID()
	{
		return outletID;
	}


};

class storeData {
public:
	void storeCustomerData(string user, string pass, string name, string add) {
		ofstream file;
		file.open("Customer Data.txt",ios::app);
		if (file.good()) {
			file << user << " ";
			file << pass << " ";
			file << name << " ";
			file << add << " ";
			file << '0' << endl;
		}
		file.close();
	}
};



class getCustomerData {
public:
	string getCustomerName(string user,string pass) {
		string checkPass, checkID;
		string buff, name;
		ifstream file;
		file.open("Customer Data.txt");
		if (file.good()) {
			while (!file.eof()) {
				file >> checkID;
				file >> checkPass;
				file >> name; 
				file >> buff; //to skip over other customer data
				file >> buff;

				if (checkID == user && checkPass == pass) {
					return name;
				}
			}
		}
		file.close();
		return "";
	}

	string getCustomerAddress(string user, string pass) {
		string checkPass, checkID;
		string buff, add;
		ifstream file;
		file.open("Customer Data.txt");
		if (file.good()) {
			while (!file.eof()) {
				file >> checkID;
				file >> checkPass;
				file >> buff;
				file >> add; //to skip over other customer data
				file >> buff;

				if (checkID == user && checkPass == pass) {
					return add;
				}
			}
		}
		file.close();
		return "";
	}

	int getCustomerLoyaltyPoints(string user, string pass) {
		string checkPass, checkID;
		string buff, points;
		int lp = 0;
		ifstream file;
		file.open("Customer Data.txt");
		if (file.good()) {
			while (!file.eof()) {
				file >> checkID;
				file >> checkPass;
				file >> buff;
				file >> buff; //to skip over other customer data
				file >> points;

				if (checkID == user && checkPass == pass) {
					lp = stoi(points);
					return lp;
				}
			}
		}
		file.close();
		return 0;
	}
};

class dataVerifier {
private:
	string username, password;
	bool found(string filename) {
		string checkPass, checkID;
		ifstream file;
		file.open(filename);
		if (file.good()) {
			while (!file.eof()) {
				file >> checkID;
				file >> checkPass;

				//check existence of user
				if (checkID == username && checkPass == password) {
					return true;
				}
			}
		}
		file.close();
		return false;
	}
public:
	dataVerifier(string user, string pass) {
		this->username = user;
		this->password = pass;
	}

	bool verifyCustomerUsername() {
		string checkID;
		string buff;
		ifstream file;
		file.open("Customer Data.txt");
		if (file.good()) {
			while (!file.eof()) {
				file >> checkID;
				file >> buff;
				file >> buff; //to skip over other customer data
				file >> buff;
				file >> buff;

				//check existence of user
				if (checkID == username) {
					return true;
				}
			}
		}
		file.close();
		return false;
	}

	bool verifyCustomer() {
		string checkPass, checkID;
		string buff;
		ifstream file;
		file.open("Customer Data.txt");
		if (file.good()) {
			while (!file.eof()) {
				file >> checkID;
				file >> checkPass;
				file >> buff; //to skip over other customer data
				file >> buff;
				file >> buff;

				//check existence of user
				if (checkID == username && checkPass == password) {
					return true;
				}
			}
		}
		file.close();
		return false;
	}

	bool verifyStoreManager() {
		return this->found("Store Manager Data.txt");
	}
	bool verifyStoreAdmin() {
		return this->found("Store Admin Data.txt");
	}
	bool verifyInventoryManager() {
		return this->found("Inventory Manager Data.txt");
	}
	bool verifyFloorManager() {
		return this->found("Floor Manager Data.txt");
	}
};

//implemented by Sana
//Follows SRP, Open/Close
class signup {
private:
	string username, password, name, address;
public:
	signup(string username, string password, string name, string add) {
		this->password = password;
		this->username = username;
		this->name = name;
		this->address = add;
	}

	int signingup() {
		dataVerifier verify(this->username, this->password); 
		bool found = verify.verifyCustomerUsername(); //checks if the username exists
		if (!found) { //stores data in data file if username is free
			storeData c;
			c.storeCustomerData(username, password, name, address);
			return 0;
		}
		else {
			return 3;
		}
	}
};

//implemented by all
//Follows SRP, Open/Close
class login {
private:
	string username, password;
public:
	login(string user, string pass) {
		this->username = user;
		this->password = pass;
	}
	string getUser() {
		return this->username;
	}
	string getPass() {
		return this->password;
	}

	int loggingInCustomer(customer& c) {
		dataVerifier verify(this->username, this->password);
		bool found=verify.verifyCustomer();
		if (found) {
			getCustomerData data;
			c.setcustomer(username, password, data.getCustomerLoyaltyPoints(username, password), "Active", data.getCustomerName(username, password), data.getCustomerAddress(username, password));
			return 1;
		}
		else {
			return 0;
		}
		
	}

	storeadmin* loggingInStoreAdmin() {
		dataVerifier verify(this->username, this->password);
		bool found = verify.verifyStoreAdmin();
		if (found) {
			storeadmin SA(username, password);
			return &SA;
		}
		else {
			return nullptr;
		}
	}
	storemanager* loggingInStoreManager() {
		dataVerifier verify(this->username, this->password);
		bool found = verify.verifyStoreManager();
		if (found) {
			storemanager SM(username, password);
			return &SM;
		}
		else {
			return nullptr;
		}
	}
	inventorymanager* loggingInInventoryManager() {
		dataVerifier verify(this->username, this->password);
		bool found=verify.verifyInventoryManager();
		if (found) {
			inventorymanager IM(username, password);
			return &IM;
		}
		else {
			return nullptr;
		}
	}
	floormanager* loggingInFloorManager() {
		dataVerifier verify(this->username, this->password);
		bool found = verify.verifyFloorManager();
		if (found) {
			floormanager FM(username, password);
			return &FM;
		}
		else {
			return nullptr;
		}
	}
};

class onlinestore
{
private:
	inventory* list;
public:
	onlinestore()
	{
		list = nullptr;
	}
	onlinestore(inventory* i)
	{
		list = i;
	}

	inventory* getList() {
		return list;
	}

	int signin(string user, string pass, string name, string add) {
		signup c(user, pass, name, add);
		int num= c.signingup();
		if (num == 0) {
			system("CLS");
			cout << "You have successfully logged in. You will now be redirected to the main page." << endl << endl;
			system("pause");
			system("CLS");
		}
		else {
			system("CLS");
			cout << "Username is already taken, please refill the form." << endl << endl;
			system("pause");
			system("CLS");
		}
		return num;
	} 

	int Login(string user, string pass, int num, int num2) {
		if (num == 1) {
			//customer
			login customer1(user, pass);
			customer c;
			num=customer1.loggingInCustomer(c);
			if (num==1) {
				system("CLS");
				c.issuecard();
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (num == 2) {
			//admin
			if (num2 == 1) {
				//Store admin
				login SA(user, pass);
				storeadmin* sadmin = SA.loggingInStoreAdmin();
				if (sadmin) {
					system("CLS");
					sadmin->functions();
					return 5;
				}
				else {
					return 0;
				}
			}
			else if (num2 == 2) {
				//Store Manager
				login SM(user, pass);
				storemanager* smanager = SM.loggingInStoreManager();
				if (smanager) {
					system("CLS");
					smanager->functions();
					return 5;
				}
				else {
					return 0;
				}
			}
			else if (num2 == 3) {
				//Inventory Manager
				login IM(user, pass);
				inventorymanager* imanager = IM.loggingInInventoryManager();
				if (imanager) {
					system("CLS");
					imanager->functions();
					return 5;
				}
				else {
					return 0;
				}
			}
			else if (num2 == 4) {
				//Floor Manager
				login FM(user, pass);
				floormanager* fmanager = FM.loggingInFloorManager();
				if (fmanager) {
					system("CLS");
					fmanager->functions();
					return 5;
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		}
	}

};

//we will flesh out proper working functions in the final deliverable. For now we have set up a skeleton code for our classes.
//Since the deliverable only asks for a welcome page, we have worked on the aesthetics. Functionality will be added later.
//selecting an option will not show too much progression

int main() {

	onlinestore obj;
	int num = 0, num2 = 0;
	string pass = "", user = "";
	string name = "", address = "";
	do
	{
		system("CLS");
		cout << "                    Welcome to S&J Boutique! " << endl << endl;
		cout << "S&J offers apparels for both males and females of all age groups!" << endl << " Our store also issues loyalty cards which translates into discounts" << endl << " on your next purchase." << endl << endl;
		cout << "If you are a customer, choose any option below. If you are an employee, select login to proceed." << endl << endl;
		cout << "1. Show catalog" << endl;
		cout << "2. Login" << endl;
		cout << "3. Sign up" << endl;
		cout << endl << "Press any other number to exit" << endl;

		cin >> num;
		system("CLS");

		while (num == 1 || num == 2 || num == 3) {
			if (num == 1) {
				inventory* catalog;
				catalog = obj.getList();
				cout << "            CATALOG" << endl << endl;
				catalog->printItemList();
				cout << "0. Back" << endl;
				cin >> num;
				if (num == 0) {
					break;
				}
				break;
			}
			else if (num == 2) {
				cout << "Are you a customer or an employee?" << endl << endl;
				cout << "1. Customer" << endl << "2. Employee" << endl << "0. Back" << endl;
				cin >> num2;
				system("CLS");
				if (num2 == 1) {
					cout << "Enter username: ";
					cin >> user;
					cout << "Enter password: ";
					cin >> pass;
					num = obj.Login(user, pass, num2, 0);
					system("pause");
				}
				else if (num2 == 2) {
					int num3 = 0;
					cout << "Please select one of the following for logging in:" << endl << endl;
					cout << "1. Store Admin" << endl;
					cout << "2. Store Manager" << endl;
					cout << "3. Inventory Manager" << endl;
					cout << "4. Floor Manager" << endl;
					cout << "0. Back" << endl;
					cin >> num3;
					system("CLS");
					cout << "Enter username: ";
					cin >> user;
					cout << "Enter password: ";
					cin >> pass;
					num = obj.Login(user, pass, num2, num3);
					system("pause");
				}
				else {
					break;
				}
			}
			else if (num == 3) {
				cout << "Welcome to customer signup! Please fill in the details below" << endl << endl;
				cout << "Enter username: ";
				cin >> user;
				cout << "Enter password: ";
				cin >> pass;
				cout << "Enter your full name: ";
				cin >> name;
				cout << "Enter your address: ";
				cin >> address;
				num=obj.signin(user, pass, name, address);
			}
			else {
				break;
			}
		}
	} while (num >= 0 && num <= 3);

	system("CLS");
	cout << "                 Goodbye!" << endl << endl;


	system("pause");
	return 0;
}