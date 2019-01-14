//Game Map

#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

void display(int[ROWS][COLS]); //function prototype
int main()
{

int val [ROWS][COLS] = {0,1,2,3,4,5,6,7,8,9,
                        10,11,12,13,14,15,26,17,18,19,
                        20,21,22,23,24,25,26,27,28,29,
                        30,31,32,33,34,35,36,37,38,39,
                        40,41,42,43,44,45,46,47,48,49,
                        50,52,52,53,54,55,56,57,58,59,
                        60,61,62,63,64,65,66,67,68,69,
                        70,71,72,73,74,75,76,77,78,79,
                        80,81,82,83,84,85,86,87,88,89,
                        90,91,92,93,94,95,96,97,98,99};

/*

         col1    col2    col3   col4   col5   col6   col7   col8   col9    col10

row1      00     01       02     03     04     05     06     07     08      09

row2      10     11       12     13     14     15     16     17     18      19

row3      20     21       22     23     24     25     26     27     28      29

row4      30     31       32     33     34     35     36     37     38      39

row5      40     41       42     43     44     45     46     47     48      49

row6      50     51       52     53     54     55     56     57     58      59

row7      60     61       62     63     64     65     66     67     68      69

row8      70     71       72     73     74     75     76     77     78      79

row9      80     81       82     83     84     85     86     87     88      89

row10     90     91       92     93     94     95     96     97     98      99


*/

display(val);
return 0;

}

void display(int nums[ROWS][COLS])
{
int rowNum, colNum;
for(colNum = 0; rowNum < ROWS; rowNum++)
   {
    for(colNum = 0; colNum < COLS; colNum++)
      cout << setw(4) << nums[rowNum][colNum];
     cout<<endl;
   }

return;
}
