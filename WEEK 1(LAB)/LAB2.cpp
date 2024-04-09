#include <iostream>
#include <vector> 
using namespace std;

 void exactChange(int userTotal, vector<int>& coinVals){
     int numPennies, numNickels, numDimes, numQuarters;

     numQuarters = userTotal/25;
     userTotal %= 25;

     numDimes = userTotal/10;
     userTotal %= 10;

     numNickels = userTotal/5;
     userTotal %= 5;

     numPennies = userTotal;

     coinVals.at(3) = numQuarters;
     coinVals.at(2) = numDimes;
     coinVals.at(1) = numNickels;
     coinVals.at(0) = numPennies;

     if(numPennies>1){
         cout << numPennies << " pennies\n";
     }
     else if(numPennies >0){
         cout << numPennies << " penny\n";
     }

     if(numNickels>1){
         cout << numNickels << " nickels\n";
     }
     else if(numNickels >0){
         cout << numNickels << " nickel\n";
     }

     if(numDimes>1){
         cout << numDimes << " dimes\n";
     }
     else if(numDimes >0){
         cout << numDimes << " dime\n";
     }

     if(numQuarters>1){
         cout << numQuarters << " quarters\n";
     }
     else if(numQuarters >0){
         cout << numQuarters << " quarter\n";
     }
 }

int main() {
   int inputVal;
   vector<int> changeAmount(4); 
   
   cin >> inputVal;

   if (inputVal <= 0){
       cout << "no change\n";
   }
   else{
       exactChange(inputVal, changeAmount);
   }


   return 0;
}

/* Implement your function here */ 
