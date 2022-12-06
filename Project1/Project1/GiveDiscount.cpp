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
class print {
	//Single-Responsibility Principle
	//Class only handles one responsibilty
public:
	void printDiscount(float discount, float before, float after) {
		system("CLS");
		cout << "You get a discount of " << discount << "%!" << endl;
		cout << "Before: $" << before << endl;
		cout << "After: $" << after << endl;
	}
	void printCart() {
		cout << "T-shirt      $10" << endl;
		cout << "Sweatshirt   $15" << endl;
		cout << "Skirt        $20" << endl << endl;

	}
	void printMenu() {
		cout << " Enter either one of these to proceed:" << endl << endl;
		cout << " 0. Exit" << endl;
		cout << " 1. Checkout" << endl;
		cout << " 2. Show Cart" << endl << endl;
	}
	void printCheckout() {
		cout << "    Welcome to Checkout!" << endl;
		cout << " If you own Loyalty Card enter: " << endl;
		cout << " 1. Gold" << endl;
		cout << " 2. Silver" << endl;
		cout << " 3. Platinum" << endl;
		cout << " 4. None" << endl;
	}
	void printGoodbye() {
		cout << " Thankyou for Visiting S&J! " << endl << endl;
		cout << "         Goodbye!  " << endl << endl;

	}
 	//Open-Close Principle
    //another type of printing can be extended easily with no modification in Discount class
};

class cart{
private:
	item* itemlist;
public:
	cart()
	{
		itemlist = nullptr;
	}
	void ShowContents() {
		print c;
		c.printCart();

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
		ID = ".";
		password = ".";
		loyaltypoints = 0;
		accountstatus = ".";
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

	void issuecard() // use case implementation
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

class Discount {
private:
	float disc;
public:
	//Single-Responsibility Principle
	//Class only handles one responsibilty

	void GoldDiscount(float total) {
		float temp = total;
		float discount = 15;
		disc = 0.15 * total;
		total = total - disc;
		print d;
	    d.printDiscount(discount, temp, total);
		
	}
	void PlatinumDiscount(float total) {
		float temp = total;
		float discount = 20;
		disc = 0.2 * total;
		total = total - disc;
		print d;
		d.printDiscount(discount, temp, total);
	}
	void SilverDiscount(float total) {
		float temp = total;
		float discount = 10;
		disc = 0.1 * total;
		total = total - disc;
		print d;
		d.printDiscount(discount, temp, total);  //print class separated
	}
  //Open-Close Principle
  //another type of discount can be extended easily with no modification in Discount class


};

class checkout
{
private:
	float bill;
	item* itemlist;
	cart c;
	
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


	int login(string user, string pass, int num, int num2) {
		if (num == 1) {
			//customer
			string checkPass, checkID;
			string fname, name;
			string faddress, address;
			string loyaltyPoints;
			int lp;
			ifstream file;
			bool found = 0;
			file.open("Customer Data.txt");
			if (file.good()) {
				while (!file.eof() && found == 0) {
					file >> checkID;
					file >> checkPass;
					file >> name;
					file >> address;
					file >> loyaltyPoints;

					//check existence of user
					if (checkID == user && checkPass == pass) {
						found = 1;
						lp = stoi(loyaltyPoints);
						name = fname;
						address = faddress;
					}
				}
			}
			file.close();
			if (found == 1) {
				cout << "Login successful" << endl << endl;
				customer c1(user, pass, lp, "Active", name, address);
				c1.issuecard();
				return 1;
			}
			else {
				cout << "User Not Found" << endl << endl;
				return 0;
			}
		}
		else if (num == 2) {
			//admin
			string checkPass, checkID;
			ifstream file;
			if (num2 == 1) {
				bool found = 0;
				file.open("Store Admin Data.txt");
				if (file.good()) {
					while (!file.eof() && found == 0) {
						file >> checkID;
						file >> checkPass;
						//check existence of user
						if (checkID == user && checkPass == pass) {
							found = 1;

						}
					}
				}
				file.close();
				if (found == 1) {
					cout << "Login successful" << endl << endl;
					storeadmin admin(user, pass);
					system("CLS");
					admin.functions();
					return 1;
				}
				else {
					cout << "User Not Found" << endl << endl;
					return 0;
				}
			}
			else if (num2 == 2) {
				bool found = 0;
				file.open("Store Manager Data.txt");
				if (file.good()) {
					while (!file.eof() && found == 0) {
						file >> checkID;
						file >> checkPass;
						//check existence of user
						if (checkID == user && checkPass == pass) {
							found = 1;

						}
					}
				}
				file.close();
				if (found == 1) {
					cout << "Login successful" << endl << endl;
					storemanager smanager(user, pass);
					system("CLS");
					smanager.functions();
					return 1;
				}
				else {
					cout << "User Not Found" << endl << endl;
					return 0;
				}
			}
			else if (num2 == 3) {
				bool found = 0;
				file.open("Inventory Manager Data.txt");
				if (file.good()) {
					while (!file.eof() && found == 0) {
						file >> checkID;
						file >> checkPass;
						//check existence of user
						if (checkID == user && checkPass == pass) {
							found = 1;
						}
					}
				}
				file.close();
				if (found == 1) {
					cout << "Login successful" << endl << endl;
					inventorymanager imanager(user, pass);
					system("CLS");
					imanager.functions();
					return 1;
				}
				else {
					cout << "User Not Found" << endl << endl;
					return 0;
				}
			}
			else if (num2 == 4) {
				bool found = 0;
				file.open("Floor Manager Data.txt");
				if (file.good()) {
					while (!file.eof() && found == 0) {
						file >> checkID;
						file >> checkPass;
						//check existence of user
						if (checkID == user && checkPass == pass) {
							found = 1;
						}
					}
				}
				file.close();
				if (found == 1) {
					cout << "Login successful" << endl << endl;
					floormanager fmanager(user, pass);
					system("CLS");
					fmanager.functions();

					return 1;
				}
				else {
					cout << "User Not Found" << endl << endl;
					return 0;
				}
			}
			else {
				return 0;
			}
		}
	}

};

//Design Principles mentioned in respective classes
int main() {


	int num = 0;
	float bill = 45.0;  //hard-coded bill as calculation of bill and other functionalities handled in "Checkout" use-case
	print menu;
	menu.printMenu(); //separate class for printing



	do {
		cin >> num;
		if (num == 1) { //num 1 is for proceeding with applying discount etc
			system("CLS"); 
			int num2;
			menu.printCheckout(); //Differenct functions of 'print' class are being invoked
			cin >> num2;
			if (num2 == 1) {
				Discount obj;    //separate class for giving discount
				obj.GoldDiscount(bill); 
				menu.printMenu(); 

			}
			else if (num2 == 2) {
				Discount obj;
				obj.SilverDiscount(bill);
				cout << endl << endl;
				menu.printMenu();
			}
			else if (num2==3) {
				Discount obj;
				obj.PlatinumDiscount(bill);
				cout << endl << endl;
				menu.printMenu();
			}
			else if(num2==4) {
				system("CLS");
				cout << "You have no Discount!" << endl;
				cout << endl << endl;
				menu.printMenu();
			}

		}
		else if(num==2) { //num 2 is if user wants to view contents of cart with prices
			system("CLS");
			cart ItemList;
			ItemList.ShowContents();  //cart class handles this function
			cout << endl << endl;
			menu.printMenu();
		}
		else{
			if(num!=0)
			cout << "Enter a valid number." << endl;  //check for invalid input other than exit command
		}

	} while (num != 0);



	system("CLS");
	cout << endl << endl << endl;
	menu.printGoodbye();




	system("pause");
	return 0;
}