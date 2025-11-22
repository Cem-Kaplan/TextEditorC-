#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void create_file(string file_name) {
    fstream datei_1(file_name + ".txt", ios::out);
    cout << "datei: " << file_name << " erstellt" << endl;
};

void read_file(string file_name) {
    fstream datei_1(file_name + ".txt");
    string line;

    if (!datei_1) cout << "error" << endl;

    while(getline(datei_1, line)) {
        cout << line << endl;
    };
    datei_1.close();
};

void write_file(string file_name) {
    fstream datei_1(file_name + ".txt");
    datei_1.close();
}

int main() {
    int num;
    cout << "main.cpp geladen" << endl << "1 - datei erstellen" << endl << "2 - datei lesen" << endl << "3 - datei neu schreiben" << endl << "4 - datei loeschen" << endl << "5 - Programm schliessen" << endl;
    
    bool running = true;
    while (running) {
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
            case 3: break;
            case 4: running = false; break; 
        }
    }
    return 0;
}