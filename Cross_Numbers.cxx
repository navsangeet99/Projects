#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   // c is the box index, q[c] is the number to fill in the box
   static int checklist[8][5] = {
      // write this together... -1 is when you stop looking for a neighbor
      //c's are the # that represent boxes and q[c]'s are numbers inside the boxes'
      {-1},                  // box 0's checklist
      {0, -1},               // box 1's checklist
      {1, -1},               // box 2's checklist
      {0, 1, 2, -1},         // box 3's checklist
      {1, 2, 3, -1},         // box 4's checklist
      {2, 4, -1},           // box 5's checklist
      {0, 3, 4, -1},        // box 6's checklist
      {3, 4, 5, 6, -1}    // box 7's checklist
   };
     /*even if the oredr of #'s change in the boxes 
     we look through array and what digit comes before 
     the current # even though it has diffrent more or less neighbors
     */
   // Test 1: Similar to row test in 8 Queens
   // If the number you are writing in box c has already been written to previous boxes
   for(int i=0; i<c; i++) {
       if (q[i]==q[c]) return false;
   }
 
   // Test 2: 
   // If the number you are writing in box c (q[c]) differs by 1 
   // from any of the numbers in box c's checklist before -1
   for(int i=0; checklist[c][i]!=-1; i++) {
       int neighbor=checklist[c][i];
       if (abs(q[c]-q[neighbor])==1) return false;
   }
   return true;
}

void backtrack(int q[], int& c){
    c--;
    if (c<0) exit(0);
    
}
void print(int q[]) {
   static int solution=1;
   cout << "solution# " << solution++ << ": "<<endl;
   cout << " " << " " << q[1] << q[2] << endl;
   cout << " " << q[0] << q[3] << q[4] << q[5] << endl;
   cout << " " << " " << q[6] << q[7] << endl;
   cout << "----------------" << endl;
}
 
int main() {
 
   // initialize…
	int q[8]={};
	int c=0;
	q[0]=1;
	
   while (c >= 0) { // BOX PART:
     c++;  // Move to the next box
    if (c==8){
        print(q);
        backtrack(q,c);
    }
    else q[c] = 0;
      // If you have passed the last index, you found a solution
      // call the print function and backtrack
      // Otherwise, reset number to 0, so you will start from number 1 in the inner loop
       
        while(c>=0){        // NUMBER PART:
            q[c]++;
             if(q[c]>=9) backtrack(q,c);
       else if(ok(q,c)==true){
          break;
      }
        }
         // Move to the next number
         // If you tried all number answers, backtrack
         // Otherwise, call the ok function.
         // If it returns true, go back to the box part.
         // otherwise continue this loop to next number
    }
}
 
