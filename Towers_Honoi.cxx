#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    vector<int> t[3];  
    // t is an array of 3 vectors, each represent a tower
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
   
    int from = 0;   // set the first “from tower” as t index 0, ie. t[0], first vector
    int to; // set the first “to tower” to be the closer tower.
    if(n%2 == 1) to = 1; else to = 2; // if n is odd, right is closer, else if n is even, left is closer
    int candidate = 1;  // the ring id
    int move = 0;
 
    // add a base ring (n+1) to all three towers
    t[0].push_back(n+1);  
    t[1].push_back(n+1);  
    t[2].push_back(n+1);
    // put all the rings to tower 0, (first vector t[0])
    for(int i = n; i >= 1; --i) 
        t[0].push_back(i); 
 
    // your goal is to move all rings from t[0] to t[1]
    // while t[1] does not contain all of the rings
    while (t[1].size() != n+1) { 
        cout << "\nMove #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A');
    
        // Move the ring from "from tower" to the "to tower"
        // 1. get the ring "from tower", push it to "to tower"
        // 2. delete that ring from "from tower"
        
        t[to].push_back(candidate);
        t[from].pop_back();
        
        // new "from" = the tower(index) with the smallest ring that is not the previous "to" tower: (to+1)%3 or (to+2)%3
        if (t[(to+1)%3].back()<t[(to+2)%3].back())
            from =(to+1)%3;  
        else
            from =(to+2)%3;  
        
        // new candidate = the ring on top of the new "from tower".
        candidate = t[from].back();
        
        // new "to" = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
        if (n%2!=0) {  // if n is odd, make the "to tower" to be the one on the right of "from" first 
            if (t[(from+1)%3].back()<candidate)  // if candidate is larger then the one from the closer tower
                to =(from+2)%3; // set the new "to" to the other one.
            else
                to = (from+1)%3; // set the new "to" to the closer tower
        }
        else {  // if n is even, make the "to tower" to be the one on the left of "from" first
            // similiar to above…
            
            if(t[(from+2)%3].back()<candidate)
             to=(from+1)%3; 
             else to=(from+2)%3;
        
        }
    }
    return 0;
}
 









