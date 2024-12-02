#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;



//Program to randomize operators in the video game Rainbow Six: Siege.
//My friends and I are always looking for randomizers for this game
//since we like using random operators in game modes other than Ranked
//so I made one myself.

void randomize(vector<string>& arr) {
    random_device rd;
    mt19937 g(rd());

    shuffle(arr.begin(), arr.end(), g);
}


int main() {

    string confirm = "";
    string selSide = "";
    vector<string> atkOps = {"Buck", "Ash", "Twitch", "Maverick", "Ace", "Flores", "Thatcher",
        "Sledge", "Striker", "Blackbeard","Iana", "Sens", "Thermite", "Montagne", "Zero", "Capitao",
        "IQ", "Blitz", "Osa", "Grim", "Ram", "Deimos", "Kali", "Amaru", "Gridlock", "Nomad", "Nokk", "Finka",
        "Lion", "Dokkaebi", "Glaz", "Fuze", "Hibana", "Jackal", "Ying", "Zofia", "Brava"};

    vector<string> defOps = {"Sentry", "Smoke", "Mute", "Castle", "Pulse", "Doc", "Rook", "Kapkan", "Tachanka", "Jäger",
        "Bandit", "Frost", "Valkyrie", "Caveira", "Echo", "Mira", "Lesion", "Ela", "Vigil", "Alibi", "Maestro", "Clash",
        "Kaid", "Mozzie", "Warden", "Goyo", "Wamai", "Oryx", "Melusi", "Aruni", "Thunderbird", "Thorn", "Azami", "Solis",
        "Fenrir", "Tubarao", "Skopos"};


    srand(static_cast<unsigned>(time(0)));



    do {
        cout << "Please type ATK or DEF to begin randomizing operators" << endl;

        while(true) {
            cin >> selSide;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << endl;


            if (selSide == "ATK" || selSide == "atk" || selSide == "Atk") {

                randomize(atkOps);

                for (int i = 0; i < 5; i++) {
                    cout << atkOps[i] << endl;
                }
                break;
            } else if (selSide == "DEF" || selSide == "Def" || selSide == "def") {
                randomize(defOps);
                for (int i = 0; i < 5; i++) {
                    cout << defOps[i] << endl;
                }
                break;
            } else {
                cout << "That is an invalid selection, please choose 'ATK' or 'DEF'." << endl;
                continue;
            }
        }

           cout << endl;
           cout << "Type 'R' to randomize again (You will have to select side again) or any other key to end the program" << endl;

            cin >> confirm;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;

        } while (confirm == "R" || confirm == "r");

    return 0;
}