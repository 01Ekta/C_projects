#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Bank {
    string f_name, l_name, phone_no, address, cnic;
    int amount;

    Bank() : f_name(""), l_name(""), phone_no(""), address(""), cnic(""), amount(0) {}

    void welcome() {
        cout << "\t\t\t\t\t\tMy Banking System!\t\t\t\t\t\t" << endl;
    }

    void info() {
        cout << "Please enter your first name: "; cin >> f_name;
        cout << "Please enter your last name: "; cin >> l_name;
        cout << "Please enter your Phone number: "; cin >> phone_no;
        cout << "Please enter your address: "; cin >> address;
        cout << "Please enter your CNIC: "; cin >> cnic;
    }

    void display() {
        cout << "Your first name: " << f_name << endl;
        cout << "Your last name: " << l_name << endl;
        cout << "Your Phone number: " << phone_no << endl;
        cout << "Your address: " << address << endl;
        cout << "Your CNIC: " << cnic << endl;
        cout << "Your current amount is: " << amount << endl;
    }
};

int main() {
    int key;
    Bank b;

    do {
        b.welcome();
        cout << "Please select one option from below menu. \n";
        cout << "1. Account open. \n2. Deposit Amount. \n3. Withdraw Amount. \n4. Check Balance. \n";
        cout << "5. Update Record. \n6. Delete Record. \n7. Search Record. \n8. Exit.\n";
        cin >> key;

        if (key == 1) {
            b.info();
            ofstream f("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat", ios::app);
            f.write((char*)&b, sizeof(b));
            f.close();
            b.display();
            Sleep(3000);
            system("cls");
        }
        else if (key == 2) {
            string nam;
            int am = 0, count = 0;
            cout << "Please enter your first name: ";
            cin >> nam;

            ifstream u("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            ofstream f("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat1", ios::app);

            while (u.read((char*)&b, sizeof(b))) {
                if (nam == b.f_name) {
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    cout << "Please enter amount to deposit: ";
                    cin >> am;
                    b.amount += am;
                    cout << "New amount is: " << b.amount << endl;
                    count++;
                }
                f.write((char*)&b, sizeof(b));
            }
            f.close();
            u.close();

            if (count > 0) {
                remove("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
                rename("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat1", "C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            } else {
                cout << "Record not found.\n";
            }
            Sleep(3000);
            system("cls");
        }
        else if (key == 3) {
            string nam;
            int am = 0, count = 0;
            cout << "Please enter your first name: ";
            cin >> nam;

            ifstream u("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            ofstream f("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat1", ios::app);

            while (u.read((char*)&b, sizeof(b))) {
                if (nam == b.f_name) {
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    cout << "Please enter amount to withdraw: ";
                    cin >> am;
                    if (am <= b.amount) {
                        b.amount -= am;
                        cout << "New amount is: " << b.amount << endl;
                        count++;
                    } else {
                        cout << "Insufficient funds.\n";
                    }
                }
                f.write((char*)&b, sizeof(b));
            }
            f.close();
            u.close();

            if (count > 0) {
                remove("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
                rename("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat1", "C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            } else {
                cout << "Record not found.\n";
            }
            Sleep(3000);
            system("cls");
        }
        else if (key == 4) {
            string nam;
            cout << "Please enter your first name: ";
            cin >> nam;

            ifstream u("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            while (u.read((char*)&b, sizeof(b))) {
                if (nam == b.f_name) {
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    break;
                }
            }
            u.close();
            Sleep(3000);
            system("cls");
        }
        else if (key == 5) {
            string nam;
            int count = 0;
            char ke;
            cout << "Please enter your first name: ";
            cin >> nam;

            ifstream u("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            ofstream f("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat1", ios::app);

            while (u.read((char*)&b, sizeof(b))) {
                if (nam == b.f_name) {
                    b.display();
                    cout << "==============================================================\n";
                    cout << "To update first name (Press f). \nTo update last name (Press l). \n";
                    cout << "To update phone no. (Press p). \nTo update address (Press a). \nTo update CNIC (Press c). \n";
                    cin >> ke;

                    if (ke == 'f') {
                        cout << "Please enter your new first name: ";
                        cin >> b.f_name;
                    } else if (ke == 'l') {
                        cout << "Please enter your new last name: ";
                        cin >> b.l_name;
                    } else if (ke == 'p') {
                        cout << "Please enter your new phone number: ";
                        cin >> b.phone_no;
                    } else if (ke == 'a') {
                        cout << "Please enter your new address: ";
                        cin >> b.address;
                    } else if (ke == 'c') {
                        cout << "Please enter your new CNIC: ";
                        cin >> b.cnic;
                    } else {
                        cout << "Invalid option.\n";
                        continue;
                    }

                    count++;
                }
                f.write((char*)&b, sizeof(b));
            }
            f.close();
            u.close();

            if (count > 0) {
                remove("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
                rename("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat1", "C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            } else {
                cout << "Record not found.\n";
            }
            Sleep(3000);
            system("cls");
        }
        else if (key == 6) {
            string nam;
            int count = 0;
            char ke;
            cout << "Please enter your first name: ";
            cin >> nam;

            ifstream u("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            ofstream f("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat1", ios::app);

            while (u.read((char*)&b, sizeof(b))) {
                if (nam == b.f_name) {
                    b.display();
                    cout << "==============================================================\n";
                    cout << "Are you sure you want to delete your record? Press y for Yes and n for No: ";
                    cin >> ke;

                    if (ke == 'y' || ke == 'Y') {
                        cout << "Your record has been deleted.\n";
                        count++;
                        continue;
                    } else {
                        cout << "Your record is safe.\n";
                    }
                }
                f.write((char*)&b, sizeof(b));
            }
            f.close();
            u.close();

            if (count > 0) {
                remove("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
                rename("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat1", "C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            } else {
                cout << "Record not found.\n";
            }
            Sleep(3000);
            system("cls");
        }
        else if (key == 7) {
            string nam;
            cout << "Please enter your first name: ";
            cin >> nam;

            ifstream u("C:\\Users\\ddgup\\OneDrive\\Documents\\Bank Mangement Project\\Reg_users.dat");
            while (u.read((char*)&b, sizeof(b))) {
                if (nam == b.f_name) {
                    b.display();
                    break;
                }
            }
            u.close();
            Sleep(3000);
            system("cls");
        }
        else if (key == 8) {
            break;
        }
        else {
            cout << "Invalid option. Please try again.\n";
        }
    } while (key != 8);

    return 0;
}
