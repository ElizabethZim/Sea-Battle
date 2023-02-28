#include <iostream>
#include <cmath>

using namespace std;

bool check_ships_1(char shipFieldFirstPlayer[][10]){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (shipFieldFirstPlayer[i][j] == 'X') return true;
        }
    }
    return false;
}

void placement_of_ships1(char shipFieldFirstPlayer[][10], int arsenalFirstPlayer[][4]){
    int x1, y1, x2, y2;

    while(arsenalFirstPlayer[0][0] != 0){
        cout << "\nEnter the coordinates of the single-cell ships: ";
        cin >> x1 >> y1;
        while(x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || shipFieldFirstPlayer[x1][y1] != 'O') {
            cout << "\nTry again! ";
            cout << "\nEnter the coordinates of the single-cell ships: ";
            cin >> x1 >> y1;
        }
        arsenalFirstPlayer[0][0]--;
        shipFieldFirstPlayer[x1][y1] = 'X';

    }


    while(arsenalFirstPlayer[0][1] != 0) {
        cout << "\nEnter the coordinates of the two-cell ships: ";
        cin >> x1 >> y1 >> x2 >> y2;
        while ( x1 != x2 && y1 != y2 || x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9 ||
               shipFieldFirstPlayer[x1][y1] != 'O' || shipFieldFirstPlayer[x2][y2] != 'O' || ((abs(x1 - x2) != 1) &&
               (abs(y1 - y2) != 1))) {
            cout << "\nTry again! ";
            cout << "\nEnter the coordinates of the two-cell ships: ";
            cin >> x1 >> y1 >> x2 >> y2;
        }

        arsenalFirstPlayer[0][1]--;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                shipFieldFirstPlayer[i][j] = 'X';
            }
        }
    }

    while(arsenalFirstPlayer[0][2] != 0) {
        cout << "\nEnter the coordinates of the three-cell ships: ";
        cin >> x1 >> y1 >> x2 >> y2;
        while ( x1 != x2 && y1 != y2 || x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9 ||
                shipFieldFirstPlayer[x1][y1] != 'O' || shipFieldFirstPlayer[x2][y2] != 'O' ||
                (x1 == x2 && shipFieldFirstPlayer[x1][y1 + 1] != 'O' ) || (y1 == y2 && shipFieldFirstPlayer[x1 + 1][y1] != 'O' ) ||
                ((abs(x1 - x2) != 2) && (abs(y1 - y2) != 2))) {
            cout << "\nTry again! ";
            cout << "\nEnter the coordinates of the three-cell ships: ";
            cin >> x1 >> y1 >> x2 >> y2;
        }

        arsenalFirstPlayer[0][2]--;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                shipFieldFirstPlayer[i][j] = 'X';
            }
        }
    }
    shipFieldFirstPlayer[4][7] = 'X';

    while(arsenalFirstPlayer[0][3] != 0) {
        cout << "\nEnter the coordinates of the four-cell ships: ";
        cin >> x1 >> y1 >> x2 >> y2;
        while ( x1 != x2 && y1 != y2 || x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9 || x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9 ||
                shipFieldFirstPlayer[x1][y1] != 'O' || shipFieldFirstPlayer[x2][y2] != 'O' ||
                (x1 == x2 && (shipFieldFirstPlayer[x1][y1 + 1] != 'O' || shipFieldFirstPlayer[x1][y1 + 2] != 'O') ) ||
                (y1 == y2 &&( shipFieldFirstPlayer[x1 + 1][y1] != 'O' || shipFieldFirstPlayer[x1 + 2][y1] != 'O' )) ||
                ((abs(x1 - x2) != 3) && (abs(y1 - y2) != 3))) {
            cout << "\nTry again! ";
            cout << "\nEnter the coordinates of the four-cell ships: ";
            cin >> x1 >> y1 >> x2 >> y2;
        }

        arsenalFirstPlayer[0][3]--;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                shipFieldFirstPlayer[i][j] = 'X';
            }
        }
    }



}

void  Ataka_Player(char shipFieldSecondPlayer[][10], string player){
    int x, y;

    cout << "\nAttack of the" << player << " player: ";
    cin >> x >> y;
    if (x < 0 || x > 9 || y < 0 || y > 9) {
        cout << "\nTry again:  ";
        cin >> x >> y;
    }

    while (shipFieldSecondPlayer[x][y] == 'X' && check_ships_1(shipFieldSecondPlayer)){
        shipFieldSecondPlayer[x][y] = ' ';
        cout << "\nGot!";
        if (check_ships_1(shipFieldSecondPlayer)) {
            cout << "\nAttack of the" << player << " player: ";
            cin >> x >> y;
            if (x < 0 || x > 9 || y < 0 || y > 9) {
                cout << "\nTry again:  ";
                cin >> x >> y;
            }
        }
    }
    if (check_ships_1(shipFieldSecondPlayer)) cout << "\nYou are lose!";
}

int main(){
    char shipFieldFirstPlayer[10][10], shipFieldSecondPlayer[10][10];
    int arsenalFirstPlayer[][4] = {{4, 3, 2, 1},
                                   {1, 2, 3, 4}};
    int arsenalSecondPlayer[][4] = {{4, 3, 2, 1},
                                    {1, 2, 3, 4}};

    cout << "\nSea battle";
    cout << "\n The arrangement of the ships of the first player";

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            shipFieldFirstPlayer[i][j] = 'O';
            shipFieldSecondPlayer[i][j] = 'O';
        }
    }

    placement_of_ships1(shipFieldFirstPlayer, arsenalFirstPlayer);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << shipFieldFirstPlayer[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n The arrangement of the ships of the second player";

    placement_of_ships1(shipFieldSecondPlayer, arsenalSecondPlayer);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << shipFieldSecondPlayer[i][j] << " ";
        }
        cout << endl;
    }
string first = "first"; string second = "second";
while(check_ships_1(shipFieldFirstPlayer) && check_ships_1(shipFieldSecondPlayer)){
    Ataka_Player(shipFieldSecondPlayer, first);
    if (check_ships_1(shipFieldSecondPlayer)) Ataka_Player(shipFieldFirstPlayer, second);
}

    cout << ((check_ships_1(shipFieldFirstPlayer))? "\nThe First player won" : "\nThe Second player won");
}
