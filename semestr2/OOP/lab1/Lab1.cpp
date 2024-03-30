#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

class River { 
private: 
    string name; 
    string source; 
    int inflow; 
    double length; 

public: 
    River() {
        name = ""; 
        source = "";
        inflow = 0; 
        length = 0.0;
    }

    River(string n, string s, int i, double l) { 
        name = n;
        source = s; 
        inflow = i; 
        length = l; 
    }

    void printDetails() { 
        cout << "Name: " << name << endl; 
        cout << "Source: " << source << endl; 
        cout << "Inflows: " << inflow << endl; 
        cout << "Length: " << length << " km" << endl; 
    }

    double getLength() { 
        return length; 
    }

    int getInflows() { 
        return inflow; 
    }

    void writeToStream(ofstream& file) { 
        file << name << " " << source << " " << inflow << " " << length << endl;
    }
};

void inputRivers(River rivers[], int size) {
    for (int i = 0; i < size; ++i) { 
        string name, source; 
        int inflow; 
        double length; 

        cout << "Enter name of the river: ";
        cin >> name; 
        cout << "Enter source country: "; 
        cin >> source; 
        cout << "Enter number of inflow: "; 
        cin >> inflow; 
        cout << "Enter length of the river (in km): "; 
        cin >> length; 

        rivers[i] = River(name, source, inflow, length); 
    }
}

void addRiver(River rivers[], int& size) {
    string name, source;
    int inflow;
    double length;

    cout << "Enter name of the river: ";
    cin >> name;
    cout << "Enter source country: ";
    cin >> source;
    cout << "Enter number of inflow: ";
    cin >> inflow;
    cout << "Enter length of the river (in km): ";
    cin >> length;

    rivers[size] = River(name, source, inflow, length);
    size++;
}

void printRivers(River rivers[], int size) { 
    for (int i = 0; i < size; ++i) { 
        rivers[i].printDetails(); 
    }
}

void sortByLength(River rivers[], int size) { 
    for (int i = 0; i < size - 1; ++i) { 
        for (int j = 0; j < size - i - 1; ++j) { 
            if (rivers[j].getLength() > rivers[j + 1].getLength()) { 
                swap(rivers[j], rivers[j + 1]); 
            }
        }
    }
}

void printRiversInRange(River rivers[], int size, int a, int b) {
    cout << "Rivers with inflow in the range [" << a << ", " << b << "]:" << endl; 
    for (int i = 0; i < size; ++i) { 
        int inflow = rivers[i].getInflows(); 
        if (inflow >= a && inflow <= b) { 
            rivers[i].printDetails(); 
        }
    }
}



void deleteRiver(River rivers[], int& size, int k) { 
    if (k >= 0 && k < size) { 
        for (int i = k; i < size - 1; ++i) { 
            rivers[i] = rivers[i + 1];
        }
        size--; 
    }
    else { 
        cout << "Invalid position." << endl; 
    }
}

void writeToFile(River rivers[], int size, string filename) { 
    ofstream file(filename); 
    if (file.is_open()) { 
        for (int i = 0; i < size; ++i) { 
            rivers[i].writeToStream(file); 
        }
        file.close(); 
        cout << "Data has been written to file successfully." << endl; 
    }
    else { 
        cout << "Unable to open file." << endl; 
    }
}

void printLastFromFile(string filename) { 
    ifstream file(filename); 
    string line; 
    string lastLine; 
    if (file.is_open()) { 
        while (getline(file, line)) { 
            lastLine = line; 
        }
        file.close(); 
        cout << "Last river from file:" << endl; 
        cout << lastLine << endl; 
    }
    else { 
        cout << "Unable to open file." << endl; 
    }
}

int main() { 
    const int MAX_RIVERS = 100; 
    River rivers[MAX_RIVERS]; 
    int size = 0; 
    string filename = "rivers.txt"; 

    int choice; 
    do { 
        cout << "Menu: " << endl; 
        cout << "1. Input rivers" << endl; 
        cout << "2. Print rivers" << endl; 
        cout << "3. Sort by length" << endl; 
        cout << "4. Print rivers in range of inflow" << endl; 
        cout << "5. Add a new river" << endl; 
        cout << "6. Delete a river" << endl; 
        cout << "7. Write data to file" << endl; 
        cout << "8. Print last river from file" << endl; 
        cout << "0. Exit" << endl; 
        cin >> choice; 

        switch (choice) { 
        case 1: 
            inputRivers(rivers, 2); 
            break; 
        case 2: 
            printRivers(rivers, sizeof(rivers) / sizeof(rivers[0]));
            break; 
        case 3: 
            sortByLength(rivers, size); 
            break; 
        case 4: { 
            int a, b; 
            cout << "Enter range of inflow [a, b]: "; 
            cin >> a >> b; 
            printRiversInRange(rivers, size, a, b); 
            break; 
        }
        case 5: 
            addRiver(rivers, size); 
            break; 
        case 6: { 
            int k; 
            cout << "Enter position to delete: "; 
            cin >> k; 
            deleteRiver(rivers, size, k); 
            break; 
        }
        case 7: 
            writeToFile(rivers, size, filename); 
            break; 
        case 8: 
            printLastFromFile(filename); 
            break; 
        case 0: 
            cout << "Exiting program." << endl; 
            break; 
        default: 
            cout << "Invalid choice. Please try again." << endl; 
        }
    } while (choice != 0); 

    return 0; 
}
 