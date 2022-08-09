#include "header.h"
#include "tictactoe.h"
#include "CasinoGame.h"
#include "hangman.h"


#define TOTAL_GAMES 3
using namespace std;

class gameInfo
{
public:
    string game_name;

    string game_made_by;
    string about_game;
};

// This class inherit's data members from class gameInfo Through Single inheritance
class gameInformation : public gameInfo
{
public:
    gameInformation()
    {
        game_name = "";
        game_made_by = "";
        about_game = "";
    }
};

gameInformation all_games_info[TOTAL_GAMES];

class gameManager
{
public:
    //  used a default constructor
    gameManager()
    {
     cout << "\n\n\t\t____(@-@)___(@-@)_____(@-@)_____(@-@)____(@-@)___(@-@)_____(@-@)_____(@-@)______(@-@)_______(@-@)_______(@-@)__";
     cout << "\n\n\t\t                                                                    ";
     cout << "\n\n\t\t        WELCOME_TO_GAME_MANAGEMENT_SYSTEM";
     cout << "\n\n\t\t                                                  -BY Satvik Bhor";
     cout << "\n\n\t\t                                                                    ";
     cout << "\n\n\t\t        Game Data is getting Initilize ... Wait for one moment please";
    cout << "\n\n\t\t____(@-@)___(@-@)_____(@-@)_____(@-@)____(@-@)___(@-@)_____(@-@)_____(@-@)______(@-@)_______(@-@)_______(@-@)_______";

        sleep(8);

        // GAME 1 INFO
        fstream myfile;
        myfile.open("hangman.txt", ios::in);
        getline(myfile, all_games_info[0].game_name);
        getline(myfile, all_games_info[0].game_made_by);
        getline(myfile, all_games_info[0].about_game);
        myfile.close();

        // GAME 2 INFO
        myfile.open("tictactoe.txt", ios::in);
        getline(myfile, all_games_info[1].game_name);
        getline(myfile, all_games_info[1].game_made_by);
        getline(myfile, all_games_info[1].about_game);
        myfile.close();

        // GAME 3 INFO
        myfile.open("casino.txt", ios::in);
        getline(myfile, all_games_info[2].game_name);
        getline(myfile, all_games_info[2].game_made_by);
        getline(myfile, all_games_info[2].about_game);
        myfile.close();

        
    }
    
    gameManager(gameInformation &obj1, gameInformation &obj2, gameInformation &obj3, gameInformation &obj4)
    {
        cout << "\n\n\t\tGame Data is geting Initilize ... Wait for one moment please";
        sleep(3);
        all_games_info[0] = obj1;
        all_games_info[1] = obj2;
        all_games_info[2] = obj3;
        all_games_info[3] = obj4;
    }
    void in_game(int game_id)
    {
        char choice;
        system("cls");
        cout << "\n\n\t\t\t" << all_games_info[game_id - 1].game_name << "\n\n\n";
        cout << "\t" << setw(50) << setfill('#');
        cout << "\n\n\t1. Play Game\n";
        cout << "\t2. Game Info\n";
        cout << "\t3. GO BACK\n\n";
        cout << "\t" << setw(50) << setfill('#');
        cout << "\n\n\t[+] Enter Your Choice (1-3): ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            if (game_id == 1)
                hangman();
            else if (game_id == 2)
                tictactoe();
            else if (game_id == 3)
                casino();

            else
                game_menu();
            in_game(game_id);
        case '2':
            system("cls");
            cout << "\n\n\t\t\t" << "!!_____"<<all_games_info[game_id - 1].game_name<<"_____!!"
                 << "\n\n\n";
            cout << "\t" << setfill('@') << setw(140);
            cout << "\n\n\t[+] Made By: " << all_games_info[game_id - 1].game_made_by << "\n";
            cout << "\t[+] About Game: " << all_games_info[game_id - 1].about_game << "\n\t";
            system("pause");
            in_game(game_id);
        case '3':
            game_menu();
        default:
            cout << "\a";
            in_game(game_id);
        }
    }
    void game_menu()
    {
        char choice;
        system("cls");
        cout << "\n\n\t\t\t!!___Game Console___!!\n\n\n";
        // cout << "\t" << setw(50) << setfill('*');
         cout << "\t" "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        cout << "\n\n\t1. Hangman Game\n";
        cout << "\t2. Tic Tac Toe\n";
        cout << "\t3. Casino Number Gussing\n";
        // cout << "\t4. Hangman Game\n";
        cout << "\t4. EXIT\n\n";
        // cout << "\t" << setw(50) << setfill('*');
        cout << "\t" "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        cout << "\n\n\t[+] Enter Your Choice (1-4): ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            in_game(1);
        case '2':
            in_game(2);
        case '3':
            in_game(3);
        case '4':
        cout << "                                                                            \n\n";
        cout << "                       Thanks For Playing With us...Have A Nice Day..!!\n\n";
        cout << "!!!_________!!!_____________!!!__________!!!__________ !!!_________!!!_____________!!!__________!!!__________!!!\n\n";
            exit(0);
            
        default:
            cout << "\a";
            game_menu();
        }
    }
    // This destructor will get called when the scope of object is over
    ~gameManager()
    {
        cout << "Thanks For Playing With us...Have A Nice Day..!!\n\n";
        system("pause");
    }
};
int main()
{
    gameManager manager;
    manager.game_menu();
    return 0;
}
