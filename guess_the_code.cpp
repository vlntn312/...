#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>


using namespace std;

void clear() {
    system("cls");
    cout << "###################" << endl;
    cout << "   Guess The Code" << endl;
    cout << "###################" << endl << endl;
    return;
}

int menu() {
    clear();

    cout << "[1] start round" << endl << "[2] exit game" << endl;

    int selection;
    cin >> selection;
    return selection;
}

int main() {
    srand(time(0));
    bool running = true;

    while (running) {
        if (menu() == 2) {
            return 0;
        }
        clear();
        string code = to_string((rand() % 9999) + 1000);
        //cout << code << endl;
        string guess;

        bool round = true;
        
        while (round) {
            string guessedCode;

            for (int i = 0; i < 4; i++) {
                char cn = _getche();
                guessedCode += cn;
            }
        

            if (guessedCode == code) {
                cout << "   \033[1;32mCode right!\033[0;37m" << endl;
                cout << "\n[ENTER] back to home" << endl;
                cin.ignore();
                cin.get();
                break;
            } else {
                int correct = 0;
                int in = 0;

                for (int i = 0; i < 4; i++) {
                    if (guessedCode[i] == code[i]) {
                        correct++;
                        continue;
                    }
                    for (int ii = 0; ii < 4; ii++) {
                        if (guessedCode[ii] == code[i]) {
                            in++;
                        }
                    }
                }
                cout << "   \033[1;32m" << correct << "  \033[33m" << in << "\033[0;37m" << endl;
                correct = 0;
                in = 0;
            }
        }
    }
    
}