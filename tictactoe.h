#include "header.h"

int checkwin(char *);
void board(char *);

void tictactoe()
{
    char square[] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player = 1, i, choice;

    char mark;
    do
    {
        board(square);
        player = (player % 2) ? 1 : 2;

        cout << "\t\tPlayer " << player << ", enter a number:  ";
        cin >> choice;

        mark = (player == 1) ? '#' : '$';//for player 1 # symbol for player 2 $ symbol
         //checking for which box will be mark according to input from the user
        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout << "Please Enter the number again "; //executes when user will enter wrong input

            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin(square);

        player++;
    } while (i == -1);
    board(square);
    if (i == 1)

        cout << "==>\aPlayer " << --player << " ***********Win this Game************* ";
    else
        cout << "==>\a***********************Game has been draw***********************************";

    cin.ignore();
    cin.get();
}
//checking the same symbol in one direction to declare the winner
int checkwin(char *square)
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void board(char *square)//creating 3 x 3 matrices(board)
{
    system("cls");
    cout << "\n\t\t\t\tTic Tac Toe\n";

    cout << "\n\n\t\t\tPlayer 1  vs  Player 2 " << endl
         << endl;
    cout << endl;
    cout << "\t\t\t ------------------" << endl;
    cout << "\t\t\t | " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  |   " << endl;
    cout << "\t\t\t -----------------" << endl;
    cout << "\t\t\t | " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  |   " << endl;
    cout << "\t\t\t -----------------" << endl;
    cout << "\t\t\t | " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  |   " << endl;
    cout << "\t\t\t-------------------" << endl;
}
