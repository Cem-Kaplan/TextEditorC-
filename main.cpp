#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void create_file(string file_name) {
    fstream datei_1(file_name + ".txt", ios::out);
    cout << "datei: " << file_name << " erstellt" << endl;
    datei_1.close();
};

void read_file(string file_name) {
    fstream datei_1(file_name + ".txt", ios::in);
    string line;

    if (!datei_1) {
        cout << "Datei nicht vorhanden" << endl;
    }
    while(getline(datei_1, line)) {
        cout << line << endl;
    };
    datei_1.close();
};

void write_file(string file_name) {
    ofstream datei_1(file_name + ".txt", ios::out);

    if(!datei_1.is_open()) {
        cout << "Datei kann nicht geöffnet werden" << endl;
    } else {
        cout << "Inhalt ersetzen mit: " << endl;
        string inhalt;
        cin >> inhalt;
        datei_1 << inhalt;
    }
        datei_1.close();
}

int main() {
    
    bool running = true;
    while (running) {
        int num;
        cout << endl << "1 - datei erstellen" << endl << "2 - datei lesen" << endl << "3 - datei beschreiben" << endl << "4 - Programm schliessen" << endl;
        cin >> num;
        switch(num) {
            case 1: {
                string file_name;
                cout << "datei name eingeben: " << endl;
                cin >> file_name;
                create_file(file_name);
                break;
            }
            case 2: {
                string file_name;
                cout << "datei name eingeben: " << endl;
                cin >> file_name;
                read_file(file_name);
                break;
            }
            case 3: {
                string file_name;
                cout << "datei name eingeben: " << endl;
                cin >> file_name;
                write_file(file_name);
                break;
            }
            case 4: running = false; break; 
        }
    }
    return 0;
}