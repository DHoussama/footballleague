
#include "league.h"
#include "team.h"

using namespace std;

#include <iostream>
#include<fstream>
#include <string>
#include "player.h"
#include "human.h"
#include "coach.h"


int displaymenu1() {

    cout << "1)Display league menu" <<endl;
    cout << "2)Display teams" << endl;
    cout << "3)Exist" << endl;
    int x;
    cin >> x;
    return x;
}

int displaymenuleague() {
    cout << "1)Display league information" << endl;
    cout << "2)Display teams informations of this league" << endl;
    cout << "3)add team in this league" << endl;
    cout << "4)delete team in this league" << endl;
    cout << "5)Display rank of teams in this league" << endl;
    cout << "6)add match results of two teams in this league and display their new points" << endl;
    cout << "7)Compare teams" << endl;
    cout << "8)return back" << endl;
    int x;
    cin >> x;
    return x;

}

int displaymenuteam() {
    cout << "1)Display general team information" << endl;
    cout << "2)Display players information of this team" << endl;
    cout << "3)Display coachs informations of this team" << endl;
    cout << "4)Display the best coach of this team" << endl;
    cout << "5)Display the best player in this team" << endl;
    cout << "6)Display total salary of a given player " << endl;
    cout << "7)Display total salary of a given coach " << endl;
    cout << "8)return back" << endl;
    int x;
    cin >> x;
    return x;
}

void displayleagues() {
    cout << "choose The league you want from this " << endl;
    ifstream file;
    string line;
    file.open("leagues.txt", ios::out / ios::in);
    while (!file.eof()) {
        getline(file, line);
        cout << line << "\t";
    }
    cout << endl;
}

void displayteams() {
    cout << "choose The team you want from this " << endl;
    ifstream file;
    string line;
    file.open("teams.txt", ios::out / ios::in);
    while (!file.eof()) {
        getline(file, line);
        cout << line << "\t";
    }
    cout << endl;
}
   
void leagueoptions(string x) {
    ifstream file;

    file.open(x+".txt", ios::out / ios::in);
    try {
        if (!file) {
            throw 0;
        }
        else {
            string line;
            string  name = "";
            int yearofstart = 0;
            int  numberofteams = 0;
            // Read a Line from File


            getline(file, line);
            cout << line;
            cout << endl;
            getline(file, line);
            file >> name;
            file >> yearofstart;
            file >> numberofteams;
            getline(file, line);
            getline(file, line);

            team* p = new team[numberofteams];

            for (int i = 0; i < numberofteams; i++) {
                double yearoffoundation = 0;
                int nofplayers = 0;
                int points = 0;
                string name1 = "";
                file >> name1;
                file >> yearoffoundation;
                file >> nofplayers;
                file >> points;
                p[i] = team(name1, yearoffoundation, nofplayers, points);
            }
            league A(name, yearofstart, numberofteams, p);
            int option1;
            do {
                option1 = displaymenuleague();
                switch (option1) {
                case 1: {
                    cout << A << endl;
                    break;
                }
                case 2:
                    for (int i = 0; i < A.size(); i++) {
                        cout << "Team" << " " << i << " " << A.team1(i) << endl;
                    }
                    break;
                case 3: {
                    team s;
                    cin >> s;
                    A.insert(s);
                    break;
                }
                case 4:
                    int a;
                    cin >> a;
                    A.erase(a);
                    break;
                case 5: {
                    A.updaterank();
                    fstream f2;
                    f2.open("rank.txt", ios::out / ios::in);
                    f2 << "     Welcome to the rank of teams     " << endl;
                    int i = 0;
                    for (i = 0; i < A.getnumberofteams(); i++) {
                        f2 << i + 1 << "    " << A.team1(i).getname() << "    " << A.team1(i).thepoints() << endl;
                        cout << i + 1 << "    " << A.team1(i).getname() << "    " << A.team1(i).thepoints() << endl;
                    }

                    f2.close();
                    break;
                }
                case 6: {
                    cout << "enter the  number of the first team and its goals" << endl;
                    int n1, n2, goals1, goals2;
                    cin >> n1 >> goals1;
                    cout << "enter the  number of the second team  and its goals" << endl;
                    cin >> n2 >> goals2;
                    cout << endl;
                    team X = A.team1(n1);
                    team Y = A.team1(n2);
                    A.erase(X.thepoints());
                    A.erase(Y.thepoints());
                    A.updatepointsofteams(X, goals1, Y, goals2);
                    cout << X.thepoints() << Y.thepoints() << endl;
                    A.insert(X);
                    A.insert(Y);
                    A.updaterank();
                    int i = 0;
                    cout << endl;
                    for (i = 0; i < A.getnumberofteams(); i++) {
                        cout << i + 1 << "    " << A.team1(i).getname() << "    " << A.team1(i).thepoints() << endl;
                    }
                    break; }
                case 7: {
                    cout << "enter the  number of teams you want to compare" << endl;
                    int n1, n2;
                    cin >> n1 >> n2;
                    if (A.team1(n1) > A.team1(n2)) {
                        cout << "The first team has points more then the second" << endl;
                    }
                    else if (A.team1(n1) == A.team1(n2)) {
                        cout << "the teams are equal " << endl;
                    }
                    else {
                        cout << "The second team has points more then the first" << endl;
                    }
                    break; }

                default:
                    cout << "invalid option// try again please\n";
                }
            } while (option1 != 8);
        }
    }
        catch (int v) {
            cout << "file doesn't exist. Please next time choose a league from the liste above" << endl;
            displayleagues();
        }

   }

void teamoptions(string x) {
    ifstream file;

    file.open(x + ".txt", ios::out / ios::in);
    try {
        if (!file) {
            throw 0;
        }
        else {
    string line;

    string  name = "";
    int yearofstart = 0;
    int  numberofhumans = 0;
    int points = 0;
    getline(file, line);
    cout << line;
    cout << endl;
    file >> name;
    file >> yearofstart;
    file >> numberofhumans;
    file >> points;
    getline(file, line);
    getline(file, line);
    getline(file, line);
    team A(name, yearofstart, numberofhumans, points);
    human **p = new human*[numberofhumans];
    for (int i = 0; i < numberofhumans-3; i++) {
        int age = 0;
        int basesalary = 0;
        int specialsalary = 0;
        int goals = 0;
        string name1 = "";
        file >> name1;
        file >> age;
        file >> basesalary;
        file >> specialsalary;
        file >> goals;
        
        p[i] =new player(name1, age, basesalary, specialsalary, goals); ;
    }
    getline(file, line);
    getline(file, line);
    getline(file, line);
    for (int i = numberofhumans-3; i < numberofhumans ; i++) {
        int age = 0;
        int basesalary = 0;
        int specialsalary = 0;
        int experience = 0;
        string name1 = "";
        file >> name1;
        file >> age;
        file >> basesalary;
        file >> specialsalary;
        file >> experience;
        
        p[i] = new coach (name1, age, basesalary, specialsalary, experience);;
    }
    int option1;
    do {
        option1 = displaymenuteam();
        switch (option1) {
        case 1: {
            cout << A << endl;
            break;
        }
        case 2:
            for (int i = 0; i < numberofhumans-3; i++) {
                p[i]->print();
                cout << endl;
            }
            break;
        case 3: {
            for (int i = numberofhumans-3; i < numberofhumans ; i++) {
               p[i]->print();
                cout << endl;
            }
            break;
        }
              
        case 4: {
            int m =  ((coach*)p[numberofhumans - 3])->getexperience();
            int j = numberofhumans - 3;
            for (int i = numberofhumans - 2; i < numberofhumans; i++) {
                if (m < ((coach*)p[i])->getexperience()) {
                    m = ((coach*)p[i])->getexperience();
                    j = i;
                }
            }
            cout << "the best coach is " << p[j]->getname() << " with " << ((coach*)p[j])->getexperience() << " years of experience" << endl;
            break; } 
        case 5: {
             int n = ((player*)p[0])->getgoals();
             int s = 0;
            for (int i = 0; i < numberofhumans-3; i++) {
                if (n < ((player*)p[i])->getgoals()) {
                    n = ((player*)p[i])->getgoals();
                    s = i;
                }
            }
            cout << "the best player is " << p[s]->getname() << " with " << ((player*)p[s])->getgoals() << " goals" << endl;
            break;
        }
        case 6: {
            cout << "give the number of the player you want" << endl;
            int x;
            cin >> x;
            cout << "The total salary of " << p[x]->getname() << " is " << p[x]->displaysalary() << endl;
            break; }
        case 7: {
            cout << "give the number of the coach you want" << endl;
            int x;
            cin >> x;
            cout << "The total salary of " << p[x]->getname() << " is " << p[x]->displaysalary() << endl;
            break; }
        
        default:
            cout << "invalid option// try again please\n"; 
        }
    }  while (option1 != 8);
      }
    }
    catch (int v) {
        cout << "file doesn't exist. Please next time choose a team from the liste above" << endl;
        displayteams();
    }

   }

int main()
{
    

    cout << "     WELCOME TO OUR DATABASE OF LEAGUE    " << endl;
    int k=0;
    while (k < 13) {
        for (int i = 0; i < k; i++) {
            cout << " ";
        }
        cout << " \\\\";
        for (int i = k; i < 40-k; i++) {
            cout << "*";
        }
        cout << " //" << endl;
        k = k + 3;
    }

    int option1;
    do {
        option1 = displaymenu1();
        switch (option1) {
        case 1: {
            displayleagues();
            string x;
            cin >> x;
            leagueoptions(x);
            break; 
        }
        case 2: {
            displayteams();
            string x;
            cin >> x;
            teamoptions(x);
            break;
        }
         default:
             cout << "invalid option// try again please\n";
    }
    } while (option1 != 3);

        

    
    /*     some tests of the program
    ifstream file;

    file.open("league.txt", ios::out / ios::in );
    string line;
   
        string  name = "";
        int yearofstart = 0;
        int  numberofteams = 0;
        // Read a Line from File
   
        
            getline(file, line);
            cout << line;
            cout << endl;
            getline(file, line);
            file >> name;
            file >> yearofstart;
            file >> numberofteams;
            getline(file, line);
            getline(file, line);
        
        team* p = new team[numberofteams];
       
        for (int i = 0; i < numberofteams; i++) {
            double yearoffoundation = 0;
            int nofplayers = 0;
            int points = 0;
            string name1="";
            file >> name1;
            file >> yearoffoundation;
            file >> nofplayers;
            file >> points;
            p[i] = team(name1, yearoffoundation, nofplayers, points);
        }
        league A(name, yearofstart, numberofteams, p);
        
        // test copy constructor of a league and the operator overloaded << in both league and teams 
        cout << " Test copy constructor of a league and the operator overloaded << in both league and teams  "<< endl;
        league B = A;
        cout << B << endl;
        cout << "end of test" << endl;
        // end of test 
    
        /*
        //create team and add it to league 
        team s;
        cin >> s; 
        cout << s << endl;
        cout << "test the creation of team" << endl ;
        cout << s << endl;
        cout << "test the the new league with the new team" << endl;
        A.insert(s);
        cout << A << endl;
        cout << "end of test" << endl;
        cout << "end of test" << endl;
        //end of test  */
        
        /*
        cout << "test the the new league without team" << endl;
        int a;
        cin >> a;
        A.erase(a);
        cout << A << endl;
        cout << "end of test" << endl;
        cout << "end of test" << endl;
        //end of test */

        //rank of teams 
        /*A.updaterank();
        fstream f2;
        f2.open("rank.txt", ios::out / ios::in);
        f2 << "     Welcome to the rank of teams     " << endl;
        int i = 0;
        for (i = 0; i < A.getnumberofteams(); i++) {
            f2 << i + 1 << "    " << A.team1(i).getname() << "    "<< A.team1(i).thepoints() << endl;
            cout << i + 1 << "    " << A.team1(i).getname() << "    " << A.team1(i).thepoints() << endl;
        } 

        f2.close(); */

        //add result 
       /* cout << "enter the  number of teams and the score" << endl;
        int n1, n2, goals1, goals2;
        cin >> n1 >> n2 >> goals1 >> goals2;
        cout << endl;
        team X = A.team1(n1);
        team Y = A.team1(n2);
        A.erase(X.thepoints());
        A.erase(Y.thepoints());
        A.updatepointsofteams(X, goals1,Y, goals2);
        cout << X.thepoints() << Y.thepoints() << endl;
        A.insert(X);
        A.insert(Y);
        A.updaterank();
         int i = 0;
        cout << endl;
        for (i = 0; i < A.getnumberofteams(); i++) {
            cout << i + 1 << "    " << A.team1(i).getname() << "    " << A.team1(i).thepoints() << endl;
        }  */
        
     

/*



    file.close();

    

  
    */
  



 return 0;
}
