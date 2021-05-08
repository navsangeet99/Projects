#include <iostream>
using namespace std;

int initialMiss=3, initialCann=3, finalMiss=0, finalCann=0, currboat=0, boat_group=0;
    
void display(char pass1, char pass2){ //pass1 and pass2=missionaries and cannibals
    cout << "\n\n\n";
    for (int i = 0; i < finalMiss; i++) //for missionaries, return M
        cout << " M "; 
    for (int i = 0; i < finalCann; i++) //for Cannibals, return C
        cout << " C "; 

    if (currboat == 0)
         cout << "     ~~~~~~~~~~~~WATER~~~~~~~~~<B0(" << pass1 << "," << pass2 << ")AT>  ";
    else
    cout << "     <BO(" << pass1 << "," << pass2 << ")AT> ~~~~~~~~~WATER~~~~~~~~~  ";
    for (int i = 0; i < initialMiss; i++)
        cout << " M ";
    for (int i = 0; i < initialCann; i++)
        cout << " C ";
    
}

int sol(){ //determine if you found a solution and won when miss, canns are all on other side, otherwise 1
    if(finalCann == 3 && finalMiss == 3) return 0;
    else return 1; 
}

void result(){ /* Get boat's current location
                * Determine passenger grouping
                * Make a trip
                * Determine if we find sol
                * Repeat until we find sol
                */
    while (sol()){
        if (currboat==0){
            switch (boat_group){
                case 1: display('C', ' ');
                        initialCann++;
                        break;
                case 2: display('C', 'M');
                        initialCann++; 
                        initialMiss++;    
                        break;   
            }
            
            if (((initialMiss - 2) >= initialCann && (finalMiss + 2) >= finalCann) || (initialMiss - 2) == 0){
                initialMiss = initialMiss - 2;
                boat_group = 1;
                display('M', 'M');
                currboat = 1;
            }
            else if ((initialCann - 2) < initialMiss && (finalMiss == 0 || (finalCann + 2) <= finalMiss) || initialMiss == 0){
                initialCann = initialCann - 2;
                boat_group = 2;
                display('C', 'C');
                currboat = 1;
            }
   
            else if ((initialCann--) <= (initialMiss--) && (finalMiss++) >= (finalCann++)){
                initialCann = initialCann - 1;
                initialMiss = initialMiss - 1;
                boat_group= 3;
                display('M', 'C');
                currboat = 1;
            }
        }
  
        else{
            switch (boat_group){
                case 1: display('M', 'M');
                        finalMiss = finalMiss + 2;
                        break;
                
                case 2: display('C', 'C');
                        finalCann = finalCann + 2;
                        break;   
                
                case 3:display('M', 'C');
                        finalCann = finalCann + 1;
                        finalMiss = finalMiss + 1;
                        break;
            }
   
            if (sol()){
                if (((finalCann > 1 && finalMiss == 0) || initialMiss == 0)){
                    finalCann--;
                    boat_group = 1;
                    display('C', ' ');
                    currboat = 0;
                }
                
                else if ((initialCann + 2) > initialMiss){
                    finalCann--; finalMiss--;
                    boat_group = 2;
                    display('C', 'M');
                    currboat = 0;
                }
            }
        }
    }

    /*initialmiss and cann=#of missionaries and cannibals on the right, finalmiss a
    nd cann=#of missionaries and cannibals on the left, side=0 is riht side, 
    currboat=boat on current side
    Initially the positions are : 0M , 0C and 3M , 3C (B)
    Now let’s send 2 Cannibals to left of bank : 0M , 2C (B) and 3M , 1C
    Send one cannibal from left to right : 0M , 1C and 3M , 2C (B)
    Now send the 2 remaining Cannibals to left : 0M , 3C (B) and 3M , 0C
    Send 1 cannibal to the right : 0M , 2C and 3M , 1C (B)
    Now send 2 missionaries to the left : 2M , 2C (B) and 1M . 1C
    Send 1 missionary and 1 cannibal to right : 1M , 1C and 2M , 2C (B)
    Send 2 missionaries to left : 3M , 1C (B) and 0M , 2C
    Send 1 cannibal to right : 3M , 0C and 0M , 3C (B)
    Send 2 cannibals to left : 3M , 2C (B) and 0M , 1C
    Send 1 cannibal to right : 3M , 1C and 0M , 2C (B)’
    Send 2 cannibals to left : 3M , 3C (B) and 0M , 0C
    */
}

int main(){
    cout<<"Missionaries and Cannibals ";
    display(' ', ' ');
    result();
    display(' ', ' ');
    cout<<"\n\n";
    return 0;
}
