

#include <iostream>
#include <string>
#include <fstream>


std::string watchlist[10000];
int ws = 0; //nr de cuvinte

int main() {
    while(1) {
        for(int i=0; i < ws; i++) {
            std::cout << watchlist[i];
            std::cout << '\n';
        }
        std::cout << "\n\n\n> ";
        std::string s;
        std::cin >> s;
        system("clear");
        if(s == "exit") {
            break;
        }
        if(s == "add") {
            std::cin >> watchlist[ws];
            ws++;
        }
        if(s == "print") {
            for(int i=0; i < ws; i++) {
                std::cout << watchlist[i];
                std::cout << '\n';
            }
        }
        if(s == "delete") {
            std::string cuvant;
            std::cin >> cuvant;
            for(int i=0; i < ws; i++) {
                if(watchlist[i] == cuvant) {
                    watchlist[i] = watchlist[ws-1];
                    ws--;
                    i--;
                }
            }
        }
        if(s == "save") {
            std::ofstream fout;
            fout.open("save.txt");
            fout<< ws;
            fout<<'\n';
            for(int i=0; i<ws; i++) {
                fout<< watchlist[i];
                fout<< '\n';
            }
        }
        if(s == "load") {
            std::ifstream fin;
            fin.open("save.txt");
            fin>>ws;
            for(int i=0; i<ws; i++) {
                fin>> watchlist[i];
            }
        }
    }
}
