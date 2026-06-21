#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#define size 100 // Maximum size for all arrays in the program
#define MAX_ITEMS 100
#define max 200

struct ticket {
    int Aquantity[max], Cquantity[max], Gquantity[max];
    int ATP, CTP, GTP; //ticket prices for each type
    int aRev, cRev, gRev, tRev;

    // Constructor to initialize all values
    ticket() {
        ATP = 250;
        CTP = 100;
        GTP = 1000;
        for (int i = 0; i < max; i++) {
            Aquantity[i] = 0;
            Cquantity[i] = 0;
            Gquantity[i] = 0;
        }
    }
};

struct staffManagement // Struct that contains information fields related to staff members
{
    string names;
    string roles;
    long long contactInfo;
    string shiftSchedules;
};

staffManagement staffRecords[size]; // Global declaration

struct InventoryItem {
    string name;
    int quantity;
};

struct MaintenanceLog {
    string equipmentName;
    string taskAndSchedule;
};

InventoryItem inventory[MAX_ITEMS];
int inventoryCount = 0;

MaintenanceLog logs[MAX_ITEMS];
int logCount = 0;

int n; // Number of elements currently in arrays (will be input by user)

struct tank {//struct for tank variables
    int id;
    char waterT;
    float ph;
    float temp;
};
struct animalR {//short for animal records
    string species;
    int amount;
    int tankId;
    string time;
};

//input section start
void inputAni() {
    animalR any;
    fstream f, fl;
    string line, id2;
    bool found;


    f.open("animal.txt", ios::app);
    if (!f) {
        cout << "Error: Unable to open 'animal.txt' file!" << endl;
        return;
    }
    do {
        found = false;


        fl.open("tank.txt", ios::in);
        if (!fl) {
            cout << "Error: Unable to open 'tank.txt' file!" << endl;
            return;
        }

        cout << "\nEnter tank ID of animal: ";
        cin >> any.tankId;
        while (getline(fl, line)) {
            id2 = "";
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == '|') {
                    break;
                }
                id2 += line[i];
            }

            if (to_string(any.tankId) == id2) {
                found = true;
                break;
            }
        }

        fl.close();

        if (!found) {
            cout << "Tank ID does not exist. Please enter a valid tank ID." << endl;
        }

    } while (!found);

    cout << "\nEnter animal species: ";
    cin.ignore();
    getline(cin, any.species);
    cout << "Enter amount of animal in tank: ";
    cin >> any.amount;

    cout << "\nEnter time of animals feeding: ";
    cin >> any.time;


    f << any.tankId << "| " << any.species << " | " << any.time << " | " << any.amount << endl;
    f.close();
}
int inputTank()
{
    tank t;
    fstream fl;
    string line, id2;
    bool found;
    fl.open("tank.txt", ios::app);
    fl.close();
    do
    {
        fl.open("tank.txt", ios::in);
        found = false;
        cout << "\nEnter tank ID: ";
        cin >> t.id;
        if (!fl)
        {

            cout << "Error: file cant be opened.\n";
            break;
        }
        while (getline(fl, line))
        {
            id2 = "";
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == '|')
                {
                    break; // Stop reading at the first '|'
                }
                id2 += line[i];
            }

            if (to_string(t.id) == id2)
            {
                cout << "ID already exists. Enter a different ID." << endl;
                found = true;
                break;
            }
        }
        fl.close();
    } while (found);

    do {
        cout << "\nEnter water type (s for salt water or f for fresh water): ";
        cin >> t.waterT;
        if (t.waterT != 's' && t.waterT != 'f')
            cout << "\nEnter either s for salt water or f for fresh water" << endl;
    } while (t.waterT != 's' && t.waterT != 'f');
    do {
        cout << "Enter pH: ";
        cin >> t.ph;
        if (!(t.ph > 0 && t.ph < 15))
            cout << "Enter a ph between 1 and 14" << endl;
    } while (!(t.ph > 0 && t.ph < 15));
    cout << "Enter temperature: ";
    cin >> t.temp;
    fl.open("tank.txt", ios::app);
    if (!fl)
    {
        cout << "Error: Unable to open file!" << endl;
        return -1;
    }
    fl << t.id << "| " << t.waterT << " | " << t.ph << " | " << t.temp << endl;

    fl.close();
    return 0;
}

//input section stop
// display section start

void searchTD()
{

    string line, find;
    fstream f;
    f.open("tank.txt", ios::in);
    if (!f) {
        cout << "Error: Unable to open file!" << endl;

    }
    cout << "Enter code of tank :";
    cin >> find;
    bool found = false;


    while (getline(f, line)) {

        string tankCode = "";
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == '|') {
                break;
            }
            tankCode += line[i];
        }


        if (tankCode == find) {
            cout << "Found: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Tank not found." << endl;
    }
    f.close();
}

void searchAD()
{
    string line, find;
    fstream f;
    f.open("animal.txt", ios::in);
    if (!f) {
        cout << "Error: Unable to open file!" << endl;

    }
    cout << "Enter code of tank :";
    cin >> find;
    bool found = false;


    while (getline(f, line)) {
        string animalCode = "";
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == '|') {
                break;
            }
            animalCode += line[i];
        }


        if (animalCode == find) {
            cout << "Found: " << line << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Tank not found." << endl;
    }


    f.close();
}



void mainMenu() {
    cout << "MAIN MENU:" << endl;
    cout << string(40, '-') << endl;
    cout << "|" << setw(2) << " CODE" << setw(3) << "|" << setw(20) << "OPERATIONS" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  1 " << setw(4) << "|" << setw(21) << "Customer services" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  2 " << setw(4) << "|" << setw(21) << "Tank management" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  3 " << setw(4) << "|" << setw(22) << "Staff management" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  4 " << setw(4) << "|" << setw(23) << "Inventory management" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  5 " << setw(4) << "|" << setw(16) << "Exit" << endl << string(40, '-') << endl;
}

void Cmenu() { //Menu to choice different operations for customer services
    cout << string(40, '-') << endl;
    cout << "|" << setw(2) << " CODE" << setw(3) << "|" << setw(20) << "OPERATIONS" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  1 " << setw(4) << "|" << setw(20) << "Buy Tickets" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  2 " << setw(4) << "|" << setw(18) << "Revenue" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  3 " << setw(4) << "|" << setw(22) << "Clear Revenue" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  4 " << setw(4) << "|" << setw(22) << "Give Feedback" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  5 " << setw(4) << "|" << setw(23) << "Display Feedback" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  6 " << setw(4) << "|" << setw(16) << "Exit" << endl << string(40, '-') << endl;
}

void Tmenu() {//menu for tank management 
    cout << string(40, '-') << endl;
    cout << "|" << setw(2) << " CODE" << setw(3) << "|" << setw(20) << "OPERATIONS" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  1 " << setw(4) << "|" << setw(20) << "Input Tank Data" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  2 " << setw(4) << "|" << setw(21) << "Display Tank Data" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  3 " << setw(4) << "|" << setw(22) << "Input Animal Data" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  4 " << setw(4) << "|" << setw(23) << "Display Animal Data" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  5 " << setw(4) << "|" << setw(19) << "Find Tank Data" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  6 " << setw(4) << "|" << setw(22) << "Find Animal Data" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  7 " << setw(4) << "|" << setw(16) << "Exit" << endl << string(40, '-') << endl;
}

void Smenu() {//menu for staff management
    cout << string(40, '-') << endl;
    cout << "|" << setw(2) << " CODE" << setw(3) << "|" << setw(20) << "OPERATIONS" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  1 " << setw(4) << "|" << setw(22) << "Input Staff Data" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  2 " << setw(4) << "|" << setw(23) << "Display Staff Data" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  3 " << setw(4) << "|" << setw(21) << "Task Management" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  4 " << setw(4) << "|" << setw(16) << "Exit" << endl << string(40, '-') << endl;
}

void Imenu() {//menu for inventory management
    cout << string(40, '-') << endl;
    cout << "|" << setw(2) << " CODE" << setw(3) << "|" << setw(20) << "OPERATIONS" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  1 " << setw(4) << "|" << setw(25) << "Add/Update Inventory" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  2 " << setw(4) << "|" << setw(22) << "Search Inventory" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  3 " << setw(4) << "|" << setw(25) << "Delete Inventory Item" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  4 " << setw(4) << "|" << setw(22) << "View Inventory" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  5 " << setw(4) << "|" << setw(28) << "Log Equipment Maintenance" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  6 " << setw(4) << "|" << setw(24) << "View Maintenance Logs" << endl << string(40, '-') << endl;
    cout << "|" << setw(2) << "  7 " << setw(4) << "|" << setw(16) << "Exit" << endl << string(40, '-') << endl;
}

void Tbill(ticket& t, int index) { //to calculate the bill for the purchased tickets
    int abill = t.Aquantity[index] * t.ATP;
    int cbill = t.Cquantity[index] * t.CTP;
    int gbill = t.Gquantity[index] * t.GTP;
    int tbill = abill + cbill + gbill;
    cout << string(60, '-') << "\nFollowing is the Bill of the tickets bought: " << endl << string(60, '-');
    cout << endl << "|" << setw(5) << "TYPE" << setw(3) << "|" << setw(10) << "QUANTITY" << setw(7) << "|" << setw(10) << "PRICE" << setw(7) << "|" << setw(10) << "TOTAL" << setw(7) << "|" << endl << string(60, '-');
    if (t.Aquantity[index] > 0) {
        cout << endl << "|" << setw(5) << "ADULT" << setw(3) << "|" << setw(10) << t.Aquantity[index] << setw(7) << "|" << setw(10) << t.ATP << setw(7) << "|" << setw(10) << abill << setw(7) << "|" << endl << string(60, '-');
    }
    if (t.Cquantity[index] > 0) {
        cout << endl << "|" << setw(5) << "CHILD" << setw(3) << "|" << setw(10) << t.Cquantity[index] << setw(7) << "|" << setw(10) << t.CTP << setw(7) << "|" << setw(10) << cbill << setw(7) << "|" << endl << string(60, '-');
    }
    if (t.Gquantity[index] > 0) {
        cout << endl << "|" << setw(5) << "GROUP" << setw(3) << "|" << setw(10) << t.Gquantity[index] << setw(7) << "|" << setw(10) << t.GTP << setw(7) << "|" << setw(10) << gbill << setw(7) << "|" << endl << string(60, '=');
    }
    cout << endl << "|" << setw(5) << "TOTAL" << setw(3) << "|" << setw(26) << tbill << setw(25) << "|" << endl << string(60, '=') << endl;

    ofstream fout;
    fout.open("revenue.txt", ios::app);
    fout << tbill << endl;
    fout.close();

}

ticket TKmenu(ticket t, int index) { //Menu for buying tickets
    int option;
    do {
        cout << endl << string(40, '-') << "\nFollowing is the price of tickets\n" << string(40, '-');
        cout << endl << "|" << setw(2) << "CODE" << setw(1) << "|" << setw(10) << "TYPE" << setw(7) << "|" << setw(10) << "PRICE" << setw(7) << "|" << endl << string(40, '-');
        cout << endl << "|" << setw(2) << " 1" << setw(3) << "|" << setw(10) << "ADULT" << setw(7) << "|" << setw(10) << t.ATP << setw(7) << "|" << endl << string(40, '-');
        cout << endl << "|" << setw(2) << " 2" << setw(3) << "|" << setw(10) << "CHILD" << setw(7) << "|" << setw(10) << t.CTP << setw(7) << "|" << endl << string(40, '-');
        cout << endl << "|" << setw(2) << " 3" << setw(3) << "|" << setw(10) << "GROUP" << setw(7) << "|" << setw(10) << t.GTP << setw(7) << "|" << endl << string(40, '-');
        cout << "\n1 Group ticket will be counted as a pass for 5 people " << endl;
        cout << "\nEnter the code number of the ticket you want to buy: ";
        cin >> option;
        cout << endl;
        if (option > 3 || option < 1) {
            cout << "Invalid option. Try again" << endl;
        }
    } while (option > 3 || option < 1);
    do {
        if (option == 1) {
            cout << "Enter quantity of the Adults tickets: ";
            cin >> t.Aquantity[index];
        }
        else if (option == 2) {
            cout << "Enter the quantity of the Child tickets: ";
            cin >> t.Cquantity[index];
        }
        else if (option == 3) {
            cout << "Enter the quantity of the Group Tickets: ";
            cin >> t.Gquantity[index];
        }
        cout << "If you want to buy more tickets then enter the code of its type (if not then enter '-1'):  ";
        cin >> option;
    } while (option != -1);
    cout << endl;
    return t;
}

void revenue(ticket t, int index) { //function to calculate revenue
    string l;
    int s, sum = 0;
    ifstream fin;
    fin.open("revenue.txt", ios::app);
    while (getline(fin, l)) {
        s = stoi(l);
        sum = sum + s;
    }
    fin.close();
    cout << string(60, '-') << "\nFollowing is the revenue: " << endl << string(60, '-');
    cout << endl << "|" << setw(5) << "TOTAL" << setw(3) << "|" << setw(16) << sum << setw(35) << setw(10) << setw(10) << "|" << endl << string(60, '=') << endl;

}

void clearev() {
    ofstream fout;
    fout.open("revenue.txt", ios::out);
    if (!fout) {
        cout << "File does not exist" << endl;
        return;
    }
    else
        cout << "\nCleared revenue file successfully" << endl;
    fout.close();
}

int inFDB() {
    int stars;
    string feedback;
    cout << "Please rate us (1 to 5 stars): ";
    cin >> stars;
    if (stars < 1 || stars>5) {
        cout << "Invalid rating. Try again." << endl;
        return 1;
    }

    cin.ignore();
    cout << "Enter your feedback: ";
    getline(cin, feedback);
    ofstream fout;
    if (stars == 1) {
        fout.open("1_star.txt", ios::app);
    }
    else if (stars == 2) {
        fout.open("2_star.txt", ios::app);
    }
    else if (stars == 3) {
        fout.open("3_star.txt", ios::app);
    }
    else if (stars == 4) {
        fout.open("4_star.txt", ios::app);
    }
    else if (stars == 5) {
        fout.open("5_star.txt", ios::app);
    }
    if (!fout) {
        cout << "Error: Could not open the file for storing feedback." << endl;
        return 1;
    }
    fout << feedback << endl;
    fout.close();

    cout << "Thank you for your feedback!" << endl;
    return 0;
}

int displayFDB(int c) {
    int stars;
    string line;
    int lCount = 0;
    if (c == 0) {
        cout << "There are no feedbacks to display." << endl;
        cout << endl << string(60, '=') << endl;
        return 1;

    }
    cout << "Please select a star rating (1 to 5) to view feedback: ";
    cin >> stars;
    while (stars < 1 || stars > 5) {
        cout << "Invalid input! Please enter a rating between 1 and 5: ";
        cin >> stars;
    }

    ifstream fin;
    if (stars == 1) {
        fin.open("1_star.txt");
    }
    else if (stars == 2) {
        fin.open("2_star.txt");
    }
    else if (stars == 3) {
        fin.open("3_star.txt");
    }
    else if (stars == 4) {
        fin.open("4_star.txt");
    }
    else if (stars == 5) {
        fin.open("5_star.txt");
    }

    if (!fin) {
        cout << "Error: Could not open the file for reading feedback." << endl;
        return 1;
    }

    cout << "\nFeedback for " << stars << "-star rating:" << endl;


    while (getline(fin, line)) {
        cout << "- " << line << endl;
        lCount++;
    }

    if (lCount == 0) {
        cout << "No feedback found for this rating." << endl;
    }

    fin.close();


    cout << endl << string(60, '=') << endl;
    return 0;
}

void displayTD()//TD stanD for Tank Data
{
    string l;
    fstream fl;
    fl.open("tank.txt", ios::in);
    cout << left << "ID |  water type | ph | temperature | Inahbiitant " << endl;
    cout << setfill('=') << setw(50) << " " << endl;
    cout << setfill(' ') << endl;
    while (getline(fl, l)) {

        cout << left << l << " | " << endl;
    }
    cout << setfill('=') << setw(50) << " " << endl;
    cout << setfill(' ') << endl;
    fl.close();
}

void displayAD()
{
    string l;
    ifstream f;
    f.open("animal.txt", ios::in);
    if (!f.is_open()) {
        cout << "Error: Could not open file 'animal.txt'.\n";
    }
    cout << "\ndata storage scheme: tankId| species | time | amount" << endl;
    cout << setfill('=') << setw(50) << " " << endl;
    cout << setfill(' ') << endl;
    while (getline(f, l)) {
        cout << left << l << endl;
    }
    cout << setfill('=') << setw(50) << " " << endl;
    cout << setfill(' ') << endl;
    f.close();
}

// Function that takes input from the user for the staff information
void staffInfo(staffManagement staffRecords[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin.ignore(); // Clear input buffer
        cout << "Enter the name: ";
        getline(cin, staffRecords[i].names); // Considers space a character for ease of user
        cout << "Enter the role: ";
        getline(cin, staffRecords[i].roles);
        cout << "Enter the contact info: ";
        cin >> staffRecords[i].contactInfo;
        cin.ignore(); // Clear buffer before reading the next line
        cout << "Enter the shift Schedule: ";
        getline(cin, staffRecords[i].shiftSchedules);
    }
}


void taskAssignment(string staffTasks[], int n)
{
    int option;
    char ch;
    string newName;

    cout << endl;

    // Loop to assign tasks to the members and store them in the array staffTasks
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the task for staff member " << staffRecords[i].names << ": ";
        if (i == 0)
            cin.ignore();
        getline(cin, staffTasks[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nCurrent task for " << staffRecords[i].names << ": " << staffTasks[i] << endl;
        cout << "Enter an option for task management (1: Feeding, 2: Tank Cleaning, 3: Health Checks, 4: Exit): ";
        cin >> option;

        while (option < 1 || option > 4)
        {
            cout << "Invalid option. Please try again: ";
            cin >> option;
        }

        if (option >= 1 && option <= 3)
        {
            cout << "Task assigned to " << staffRecords[i].names << ": ";
            switch (option)
            {
            case 1:
                staffTasks[i] = "Feeding";
                break;
            case 2:
                staffTasks[i] = "Tank Cleaning";
                break;
            case 3:
                staffTasks[i] = "Health Checks";
                break;
            }
            cout << staffTasks[i] << endl;

            cout << "Do you want to update the task assignment? (Y/N): ";
            cin >> ch;

            if (ch == 'Y' || ch == 'y')
            {
                cout << "Enter the name of the staff member to whom you want to assign the task: ";
                cin.ignore(); // Clear buffer before getline
                getline(cin, newName); // Read new name

                bool found = false;
                for (int j = 0; j < n; j++)
                {
                    if (staffRecords[j].names == newName)
                    {
                        cout << "Task reassigned from " << staffRecords[i].names << " to " << staffRecords[j].names << endl;
                        staffTasks[j] = staffTasks[i]; // Transferring the task
                        staffTasks[i] = ""; // Clearing the task from the previous person
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Staff member " << newName << " not found. Task assignment not updated." << endl;
                }
            }
        }
        else if (option == 4)
        {
            cout << "Exiting task management for " << staffRecords[i].names << endl;
            continue;
        }
    }
}


// Function for inventory and maintenance management
void inventoryManagement(InventoryItem inventory[], int inventoryCount, MaintenanceLog logs[], int logCount)
{
    string r;
    string findItem;
    int choice;
    do {
        Imenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        system("CLS");

        switch (choice) {
        case 1: { // Add or update inventory item
            string itemName;
            int quantity;
            cout << "Enter the item name: ";
            getline(cin, itemName);
            cout << "Enter the quantity: ";
            cin >> quantity;
            cin.ignore();

            bool found = false;
            for (int i = 0; i < inventoryCount; i++) {
                if (inventory[i].name == itemName) {
                    inventory[i].quantity = quantity;
                    found = true;
                    cout << "Item updated successfully.\n";
                    break;
                }
            }

            if (!found) {
                if (inventoryCount < MAX_ITEMS) {
                    inventory[inventoryCount].name = itemName;
                    inventory[inventoryCount].quantity = quantity;
                    inventoryCount++;
                    cout << "Item added successfully.\n";
                }
                else {
                    cout << "Inventory is full. Cannot add more items.\n";
                }
            }
            cout << endl << "Enter any random character to continue:\t";
            cin >> r;
            system("CLS");
            break;
        }
        case 2:
        {
            cout << "Enter the name of the item you want to search : ";
            getline(cin, findItem);
            bool found = false;
            for (int i = 0; i < inventoryCount; i++)
            {
                if (inventory[i].name == findItem)
                {
                    cout << "Item : " << inventory[i].name << ", Quantity : " << inventory[i].quantity << endl;
                    found = true;
                    cout << "Item successfully found." << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Item not found. Please try again" << endl;
            }
            cout << endl << "Enter any random character to continue:\t";
            cin >> r;
            system("CLS");
            break;
        }

        case 3: { // Delete inventory item
            string itemName;
            cout << "Enter the item name to delete: ";
            getline(cin, itemName);

            bool found = false;
            for (int i = 0; i < inventoryCount; i++) {
                if (inventory[i].name == itemName) {
                    for (int j = i; j < inventoryCount - 1; j++) {
                        inventory[j] = inventory[j + 1];
                    }
                    inventoryCount--;
                    found = true;
                    cout << "Item deleted successfully.\n";
                    break;
                }
            }
            if (!found) {
                cout << "Item not found.\n";
            }
            cout << endl << "Enter any random character to continue:\t";
            cin >> r;
            system("CLS");
            break;
        }

        case 4: { // View inventory
            cout << "\nCurrent Inventory:\n";
            for (int i = 0; i < inventoryCount; i++) {
                cout << "Item: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << endl;
                if (inventory[i].quantity < 5) {
                    cout << "Warning: Low stock for " << inventory[i].name << "!\n";
                }
            }
            cout << endl << "Enter any random character to continue:\t";
            cin >> r;
            system("CLS");
            break;
        }

        case 5: { // Log equipment maintenance
            string equipmentName, task, schedule;
            cout << "Enter the equipment name: ";
            getline(cin, equipmentName);
            cout << "Enter the maintenance task: ";
            getline(cin, task);
            cout << "Enter the maintenance schedule: ";
            getline(cin, schedule);

            if (logCount < MAX_ITEMS) {
                logs[logCount].equipmentName = equipmentName;
                logs[logCount].taskAndSchedule = "Task: " + task + ", Schedule: " + schedule;
                logCount++;
                cout << "Maintenance task logged successfully.\n";
            }
            else {
                cout << "Log storage is full. Cannot add more logs.\n";
            }
            cout << endl << "Enter any random character to continue:\t";
            cin >> r;
            system("CLS");
            break;
        }

        case 6: { // View maintenance logs
            cout << "\nEquipment Maintenance Logs:\n";
            for (int i = 0; i < logCount; i++) {
                cout << "Equipment: " << logs[i].equipmentName
                    << ", " << logs[i].taskAndSchedule << endl;
            }
            cout << endl << "Enter any random character to continue:\t";
            cin >> r;
            system("CLS");
            break;
        }

        case 7:
            cout << string(60, '=') << "\nReturning to MAIN MENU" << endl;
            cout << string(60, '=') << endl << endl;
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

// Function to write staff data to a file
void writeData()
{
    ofstream fout;
    fout.open("Staff Information.txt", ios::app);
    if (!fout)
    {
        cout << "File does not exist.";
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fout << "Information for Member " << i + 1 << endl;
            fout << "Name: " << staffRecords[i].names << endl;
            fout << "Role: " << staffRecords[i].roles << endl;
            fout << "Contact Info: " << staffRecords[i].contactInfo << endl;
            fout << "Shift Schedule: " << staffRecords[i].shiftSchedules << endl;
            fout << "-------------------------\n";
        }
        fout.close();
    }
}

// Function to read staff data from a file
void readData()
{
    ifstream fin;
    fin.open("Staff Information.txt", ios::in);
    if (!fin)
    {
        cout << "File does not exist.";
        return;
    }
    else
    {
        string output;
        while (getline(fin, output))
        {
            cout << output << endl;
        }
        fin.close();
    }
}

int main() {
    int mOption, cOption, sOption, tOption, iOption, index = 0, count = 0;
    ticket t;
    string r, staffTasks[size];
    do {
        mainMenu();
        cout << "Enter the code of the option you want to perform: ";
        cin >> mOption;
        system("CLS");
        if (mOption == 1) {
            do {
                Cmenu();
                cout << "Enter the code of the option you want to perform: ";
                cin >> cOption;
                system("CLS");
                if (cOption == 1) {
                    t = TKmenu(t, index);
                    system("CLS");
                    Tbill(t, index);
                    index++;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (cOption == 2) {
                    revenue(t, index);
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (cOption == 3) {
                    clearev();
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (cOption == 4) {
                    inFDB();
                    count++;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (cOption == 5) {
                    displayFDB(count);
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (cOption == 6) {
                    cout << string(60, '=') << "\nReturning to MAIN MENU" << endl;
                    cout << string(60, '=') << endl << endl;
                }
            } while (cOption != 6);
        }
        else if (mOption == 2) {
            do {
                Tmenu();
                cout << "Enter the code of the option you want to perform: ";
                cin >> tOption;
                system("CLS");
                if (tOption == 1) {
                    inputTank();
                    cout << endl << string(60, '=') << endl;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (tOption == 2) {
                    displayTD();
                    cout << endl << string(60, '=') << endl;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (tOption == 3) {
                    inputAni();
                    cout << endl << string(60, '=') << endl;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (tOption == 4) {
                    displayAD();
                    cout << endl << string(60, '=') << endl;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (tOption == 5) {
                    searchTD();
                    cout << endl << string(60, '=') << endl;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (tOption == 6) {
                    searchAD();
                    cout << endl << string(60, '=') << endl;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (tOption == 7) {
                    cout << string(60, '=') << "\nReturning to MAIN MENU" << endl;
                    cout << string(60, '=') << endl << endl;
                }

            } while (tOption != 7);
        }
        else if (mOption == 3) {
            do {
                Smenu();
                cout << "Enter the code of the option you want to perform: ";
                cin >> sOption;
                system("CLS");
                if (sOption == 1) {
                    do {
                        cout << "Enter the number of staff members: ";
                        cin >> n;
                        if (n <= 0 || n > size) {
                            cout << "Invalid number of staff members. Try again.\n";
                        }
                    } while (n <= 0 || n > size);
                    staffInfo(staffRecords, n);
                    cout << endl;
                    writeData();
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (sOption == 2) {
                    readData();
                    cout << endl << string(60, '=') << endl;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (sOption == 3) {
                    taskAssignment(staffTasks, n);
                    cout << endl << string(60, '=') << endl;
                    cout << "Enter any random character to continue:\t";
                    cin >> r;
                    system("CLS");
                }
                else if (sOption == 4) {
                    cout << string(60, '=') << "\nReturning to MAIN MENU" << endl;
                    cout << string(60, '=') << endl << endl;
                }
            } while (sOption != 4);
        }
        else if (mOption == 4) {
            inventoryManagement(inventory, inventoryCount, logs, logCount);
            cout << endl;

        }
        else if (mOption == 5) {
            cout << string(60, '=') << "\n\tGOODBYE" << endl;
            cout << string(60, '=') << endl << endl;
        }
    } while (mOption != 5);

    system("pause");
    return 0;
}
