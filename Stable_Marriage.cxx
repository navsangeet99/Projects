#include <iostream>
using namespace std;

bool ok(int q[], int c) {
    // c and q[c] are the current man and woman to be matched
    // i and q[i] are the man and woman already married
 
    // the smaller number means more preferable.
    // mp[man][woman] = the score that man given to that woman
    static int mp[3][3] = {{ 0,2,1 },   // Man#0's preferences
                           { 0,2,1 },   // Man#1's preferences
                           { 1,2,0 }};  // Man#2's preferences
    
    // wp[woman][man] = the score that woman given to that man
    static int wp[3][3] = {{ 2,1,0 },   // Woman#0's preferences
                           { 0,1,2 },   // Woman#1's preferences
                           { 2,0,1 }};  // Woman#2's preferences
 
// Test #1: Similar to row test in 8 queens 
    // Check if the current woman has already been married to other men.
    for(int i=0; i<c; i++){
        if(q[c]==q[i]) return false;
        
// Test #2:
    // Part A: Current man and other women
    // Check if the current man (c) likes any other woman (q[i]) more than current woman (q[c]).
    // mp[ c ][ q[i] ] < mp[ c ][ q[c] ] 
    // (Use <, since smaller number preferred)
    // At the same time, check if other women likes the current man more than their own husband.
    // wp[ q[i] ][ c ] < wp[ q[i] ][ i ]
    // If both occurs - that's an unstable marriage.        
    else if (mp[c][q[i]]< mp[c][q[c]] && wp[q[i]][c]< wp[q[i]][i]) return false;
        
    // Part B: Current woman and other men
    // Check if other men (i) like the current woman (q[c]) more than their own wifes (q[i]).
    // mp[ i ][ q[c] ] < mp[ i ][ q[i] ]   
    // At the same time, check if woman c likes any other man more than the current man.
    // wp[ q[c] ][ i ] < wp[ q[c] ][ c ]
    // If both occurs - that's an unstable marriage.
        else if (wp[q[c]][i]< wp[q[c]][c] && mp[i][q[c]]< mp[i][q[i]]) return false;
    }
    return true;
}
 
void print(int q[]) {
    static int solution = 0;
    cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
    for (int i = 0; i < 3; ++i)
        cout << i << "\t" << q[i] << "\n";
    cout << "\n";
}
 
int main() {
    // c indicates the new man and
    // q[c] is the new woman to be matched.
 
    // initialize...
    int c=0, q[3]={};
    q[0] = 0;  // Starting with matching woman 0 to man 0
    
    while(c>=0 ){  //next man 0-2
        c++;
        if(c>2){
         print (q);
        c--;
        }
        else q[c]=-1;
    while (c>=0){   //next woman man 0-2
        q[c]++; 
        if(q[c]>2) c--;
        else if (ok(q,c)) break;
    // Use your code similar to 8 Queens, except the condition to find a solution...
        }
    }
    return 0;
}




