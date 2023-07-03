#include <iostream>
#include<locale.h>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
void autor(void) {
    cout << endl;
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "Autor programu: Simon Dudek\n\n";
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "\n\n";
}

int main() {
    ostringstream nazwa_pliku;
    string wpisane;
    string mies;
    string rok;
    setlocale(LC_ALL, "");
    autor();
    nazwa_pliku << "Probka_";
    cout << "Podaj kod składający się z maksymalnie 5-ciu cyfr." << endl;
    cin >> wpisane;
    while (wpisane.size() > 5) {
        cout << "Zbyt duża ilość cyfr. Proszę wpisać ponownie kod."<<endl;
        cin >> wpisane;
    }
    nazwa_pliku << setfill('0') << setw(5)<<wpisane<<"_z_";
    cout << "Podaj dzień miesiąca." << endl;
    cin >> wpisane;
    while (stoi(wpisane) > 31 || stoi(wpisane)<1) {
        cout << "Nie ma takiego dnia miesiąca. Proszę ponownie wpisać dzień miesiąca." << endl;
        cin>>wpisane;
    }
    nazwa_pliku << setfill('0') << setw(2) << wpisane<<"_";
    cout << "Podaj numer miesiąca." << endl;
    cin >> mies;
    while(stoi(mies)>12 || stoi(mies)<1 || stoi(mies) == 2 && stoi(wpisane) > 29){
        cout << "Nie ma takiej daty. Proszę ponownie wpisać numer miesiąca." << endl;
        cin >> mies;
    }
    nazwa_pliku << setfill('0') << setw(2) << mies << "_";
    cout << "Podaj rok." << endl;
    cin >> rok;
    while (stoi(rok) % 4 != 0 && stoi(mies) == 2 && stoi(wpisane) == 29 || rok.size()!=4) {
        cout << "Nie ma takiej daty. Prosze ponownie wpisać rok" << endl;
        cin >> rok;
    }
    nazwa_pliku << rok << ".dta";
    cout << nazwa_pliku.str() << endl;
    system("pause");
    return 0;
}