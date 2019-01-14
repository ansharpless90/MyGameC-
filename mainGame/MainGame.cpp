#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;
//random function Prototype
string randM(int);

int main ()
{
//Declare variables
    int monAT, monHP,
        playerHP = 70,
        playerAT = 6,
            gold = 20,
         potionQ = 0,
          offUpQ = 0,
       playerExp = 0,
       exp, step, place, randvalue;
//Variable for map
    const int length = 200;
    const int width  = 200;
          int mp [length][width];

    string direction,choice,cont = "Y", itemC = "U", mon, rMon, monN,saveC;

//Retrieve Intro File
    string fName = "intro.dat";
    string lin;
    ifstream introFile;

    introFile.open(fName.c_str());

    if (introFile.fail())
    {
        cout <<"\nThe file was not opened"
             <<"\nPlease check if file exists."
             <<endl;
    }


    while (getline(introFile,lin))
           cout <<lin<<endl;


//Retrieve save file
    string filename = "save.dat";
    string line;


    ifstream inFile;


    inFile.open(filename.c_str());

    if (inFile.fail())
    {
        cout <<"\nThe file was not opened"
             <<"\nPlease check if file exists."
             <<endl;
    }

    while (getline(inFile,line))
           cout <<line<<endl;

    inFile.close();
    cout<<endl;

//system("pause");
//Start of game code
while (cont != "N")
{

//Store code
int potion = 5, offUp = 20, gold = 50 ;

string choice, exit = "N" ;

while (exit != "X")
{
  if (gold <= 0)
     {
        cout <<"No gold left" <<endl;
     }
  if (gold > 0)
     {


    cout <<"What would you like to purchase? \n\n"<<endl;
    cout <<"potion for 5 gold \n" <<"offUp for 20 gold \n\n";

    cin >> choice;
    if (choice == "potion")
    {
      if (gold >= potion)
      {
          cout << string(50, '\n');
          cout<<"Quantity: "<<endl;
          cin>>potionQ;
          gold -= potion * potionQ;
          cout <<"Total gold is "<<gold<<endl;

      }
      else
       {
         cout<<"Not enough gold"<<endl;
      }
    }


///////////
    if (choice == "offUp")
    {
      if (gold >= offUp)
      {
          cout << string(50, '\n');
          cout<<"Quantity: "<<endl;
          cin>>offUpQ;
          gold -= offUp * offUpQ;
          cout <<"Total gold is "<<gold<<endl;
      }

      else
      {
          cout<<"Not enough gold"<<endl;
      }

    }
    if (choice == "X")
       {
        break;
       }
    }

cout<<"Do you want to exit? "<<endl;
cout<<"Type X to exit"<<endl;
cin >> exit;


}
cout<<"You now have, "<<potionQ<<" potions."<<endl;
cout<<"You now have, "<<offUpQ<<" offUp."<<endl;
system("pause");
cout << string(50, '\n');


//Battle Start

srand(time(NULL));
randvalue = rand() % (10 + 1);

randM(randvalue);//random function call
rMon = randM(randvalue);

if (rMon == "A")
    {
     monAT = 5;
     monHP = 10;
      monN = "Orb";
       exp = 5;
    }

if (rMon == "B")
    {
     monAT = 7;
     monHP = 15;
      monN = "Ghoul";
       exp = 7;
    }

if (rMon == "C")
    {
     monAT = 10;
     monHP = 20;
      monN = "Ghast";
       exp = 12;
    }
cout << string(50, '\n');
cout <<"Ryu is attacked by a " <<monN<<"!\n";
    while (playerHP > 0 and monHP > 0)
    {

        cout <<"------------------------------------------------------\n";
        cout <<"------------------------------------------------------\n";
        cout <<"Ryu's HP is, " << playerHP <<".\n";
        cout <<monN<<" HP is, "<<    monHP <<".\n";
        cout <<"------------------------------------------------------\n";
//Battle menu
         cout<<"Attack \n"<<"Defend \n"<<"Item \n";
         cout<<"Action: ";
         cin >> choice;
        cout <<"------------------------------------------------------\n";

      itemC = "g";
      if (choice == "Attack")
         {
           monHP -= playerAT;
           cout<<"Ryu attacks "<<monN <<"for " << playerAT <<" Hp."<<endl;
         }

      else if (choice == "Defend")
         {
           cout <<"Ryu defends " <<endl;
           playerHP -= monAT/2;
         }
//Interactive Item Menu

      else if (choice == "Item")
         {
           while (itemC != "X")
             {
               cout <<"Potion: " << potionQ <<endl;
               cout <<"OffUp: " <<offUpQ<<endl;
               cout <<"Choice: "<<endl;
                cin >>itemC;

              if (itemC == "Potion")
                  {
                    if (potionQ <= 0)
                        {
                         cout<<"Not enough potions" <<endl;
                        }
              else if (potionQ > 0)
                      {
                        cout <<"Ryu uses item\n\nHP + 20!\n\n";

                        playerHP +=20;
                        potionQ -=1;
                      }
                  }
              if (itemC == "OffUp")
                 {
                  if (offUpQ <= 0)
                     {
                      cout<<"Not enough offUp" <<endl;
                     }
                  else if (offUpQ > 0)
                     {
                       cout <<"Ryu uses item\n\nAtt + 20!\n\n";

                       playerAT += 20;
                       offUpQ -= 1;
                    }
                 }
             }
         }

//Interactive Item Menu End
//Determines if player is defeated
    if (playerHP <= 0)
       {
         cout <<"Ryu has been defeated."<<endl;

       }
//Determines if Defend works
    if (choice == "Defend")
     {
          playerHP -= monAT/2;
          cout<<"Ryu is attacked for, "<<monAT/2<<"HP."<<endl;
     }
     else
     {
       playerHP -= monAT;
       cout<<"Ryu is attacked for, "<<monAT<<"HP."<<endl;
     }
//cout << string(50, '\n');
//Determines if Victory
    if (playerHP > 0)
        {
          if (monHP <= 0 and playerHP > 0)
             {
               cout<<monN<<" has been vanquished."<<endl;
               gold += 10;
               playerExp += exp;
             }
        }


    }//end of while loop
   cout <<"You have, " <<gold <<" gold, \n"
        <<playerHP  <<" Hit points, \n"
        <<playerExp <<" Experience Points, \n";
   cout <<"Will you continue Y or N? " <<endl;
    cin >>cont;
   cout <<string(50, '\n');

}
//Saving File
cout<<"Would you like to save? Yes or No"<<endl;
cin>>saveC;

if (saveC == "Yes")
{
    ofstream outputFile;
    outputFile.open("save.dat");

    int playerHPS = playerHP;
    outputFile << playerHPS << endl;

    outputFile << gold << endl;

    outputFile << potionQ << endl;

    outputFile << offUpQ << endl;

    outputFile << playerExp << endl;



    outputFile.close();
    cout << "File Saved!\n";




}


}//end of program

string randM(int r)//Random Function
{
    string mon;



    if (r < 5)
    {
        mon = "A";
    }

    else if (r == 5 and r < 8)
    {
        mon = "B";
    }

    else
    {
        mon = "C";
    }

    return mon ;
}


