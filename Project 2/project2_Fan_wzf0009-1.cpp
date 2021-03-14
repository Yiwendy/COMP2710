/* FILE NAME:  Project2_Fan_wzf0009
 * AUTHOR: Wenzhuo Fan 
 * AUBURN USERID: wzf0009
 * DATE: 06/12/2020
 * I used project2 hint given in the file on Canvas for project2.
 * Use random numbers and the probabilities given in the problem to determine 
 * whether a shooter hits his target.

 */ 
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

//constants variables
const double PROBABILITY_AARON = 1.0/3.0;
const double PROBABILITY_BOB = 0.5;
const double PROBABILITY_CHARLIE = 1.0;
const int TOTAL_RUNS = 10000;
int A_Wins1, A_Wins2, B_Wins1, B_Wins2, C_Wins1, C_Wins2 = 0;
bool A_alive, B_alive, C_alive = true;


/* 
* Input: A_alive indicates Aaron is alive true for alive, false for dead
*        B_alive indicates Bob is alive
*        C_alive indicates Charlie is alive
* Return: true if at least two are alive otherwise return false
*/ 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   return ((A_alive && B_alive)|| (B_alive && C_alive) || (A_alive && C_alive));
}

/* 
 * Call by reference* Strategy 1: Everyone shoots to kill the highest accuracy player alive
 * Input: B_alive indicates Bob is alive or dead
 *        C_alive indicates Aaron is alive or dead
 * Return: Change B_alive into false if Bob is killed
 *         Change C_alive into false if Charlie is killed
 */ 
void Aaron_shoots1(bool& B_alive, bool& C_alive){
   double random_shoot = rand() % 100;
   double SHOOTS_AARON = PROBABILITY_AARON * 100;
   if (random_shoot <= SHOOTS_AARON) {
      if (C_alive) {
         C_alive = false;
      }
      else {
         B_alive = false;
      }
   }
}
          
 /* 
 * Call by reference
 * Input: A_alive indicates Aaron is alive or dead
 *        C_alive indicates Charlie is alive or dead
 * Return: Change A_alive into false if Aaron is killed
 *         Change C_alive into false if Charlie is killed
*/ 
void Bob_shoots(bool& A_alive, bool& C_alive){
   double random_shoot = rand() % 100;
   double SHOOTS_BOB = PROBABILITY_BOB * 100;
   if (random_shoot <= SHOOTS_BOB) {
      if (C_alive) {
         C_alive = false;
      }
      else {
         A_alive = false;
      }
   }
}
   

/* * Call by reference
* Input: A_alive indicates Aaron is alive or dead
*        B_alive indicates Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed
*         Change B_alive into false if Bob is killed
*/ 
void Charlie_shoots(bool& A_alive, bool& B_alive){
   double random_shoot = rand() % 100;
   double SHOOTS_CHARLIE = PROBABILITY_CHARLIE * 100;
   if (random_shoot <= SHOOTS_CHARLIE) {
      if (B_alive) {
         B_alive = false;
      }
      else {
         A_alive = false;
      }
   }
}
   

/* 
* Call by reference
* Strategy 2: Aaron intentionally misses if both are alive
* Input: B_alive indicates Bob is alive or dead
*        C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
*         Change C_alive into false if Charlie is killed
*/ 
void Aaron_shoots2(bool& B_alive, bool& C_alive){
   double SHOOTS_AARON = PROBABILITY_AARON * 100;
   int random_shoot = rand() % 100;
   
   if (C_alive && B_alive) { 
   }
   else {
      Aaron_shoots1(B_alive, C_alive);
   }
}
   

//TEST PROTOTYPES
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);


//Simple method to implement pause function in linux
void Press_any_key(void);

int main() {
   //Initializes Random number generator's seed and calls test functions
   //constant variables for main.
   
   bool A_alive, B_alive, C_alive;
   
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(2);

   cout << "*** Welcome to Fan's Duel Simulator ***\n";
   //random number genrator.
   srand(time(0));
   //test cases.
   test_at_least_two_alive(); 
   Press_any_key();
         
   test_Aaron_shoots1();
   Press_any_key();
   
   test_Bob_shoots();
   Press_any_key();
   
   test_Charlie_shoots();
   Press_any_key();
   
   test_Aaron_shoots2();
   Press_any_key();
      
      
   //Starts strategy 1 and runs 10,000 times
   cout << "\nReady to test strategy 1 (run 10000 times):\n";
   Press_any_key();
   
   //calculate the win percent for strategy 2.  
   for (int i = 0; i < TOTAL_RUNS; i++ ){
      A_alive = true;
      B_alive = true;
      C_alive = true;
      
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive) {
            Aaron_shoots1(B_alive, C_alive);
         }
         if (B_alive) {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive) {
            Charlie_shoots(B_alive, A_alive);
         } 
      } 
      
      // Checks winner.
      if (A_alive) {
         A_Wins1 ++;
      } 
      else if (B_alive){
         B_Wins1++;
      } 
      else if (C_alive){
         C_Wins1++;
      }
      
   } 
   
   //Calculates the Win percentage calculations of stratagy 1
   double A_Wins_Percent = (double) A_Wins1 / TOTAL_RUNS * 100;
   double B_Wins_Percent = (double) B_Wins1 / TOTAL_RUNS * 100;
   double C_Wins_Percent = (double) C_Wins1 / TOTAL_RUNS * 100;
   
   cout << "\nAaron won " << A_Wins1 << "/10000 duels or " << A_Wins_Percent << "%\n"     
      << "Bob won " << B_Wins1 << "/10000 duels or " << B_Wins_Percent << "%\n"      
      << "Charlie won " << C_Wins1 << "/10000 duels or " << C_Wins_Percent << "%\n"      
      << endl;

//Reinitializes variables and starts strategy 2 to run 10,000 times

//Starts strategy 2 and runs 10,000 times
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   Press_any_key();
   
   //calculate the win percent for strategy 2.   
   for (int i = 0; i < TOTAL_RUNS; i++ ){
      A_alive = true;
      B_alive = true;
      C_alive = true;
      
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive) {
            Aaron_shoots2(B_alive, C_alive);
         }
         if (B_alive) {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive) {
            Charlie_shoots(A_alive, B_alive);
         } 
      } 
      
      // Checks winner.
      if (A_alive) {
         A_Wins2++;
      } 
      else if (B_alive){
         B_Wins2++;
      } 
      else if (C_alive){
         C_Wins2++;
      }
      
   } 
   
   //Calculates the Win percentage calculations of stratagy 2   
   double A_Wins_Percents = (double) A_Wins2 / TOTAL_RUNS * 100;
   double B_Wins_Percents = (double) B_Wins2 / TOTAL_RUNS * 100;
   double C_Wins_Percents = (double) C_Wins2 / TOTAL_RUNS * 100;
   

   cout << "\nAaron won " << A_Wins2 << "/10000 duels or " << A_Wins_Percents<< "%\n"      
      << "Bob won " << B_Wins2 << "/10000 duels or " << B_Wins_Percents << "%\n"      
      << "Charlie won " << C_Wins2 << "/10000 duels or " << C_Wins_Percents<< "%\n"      
      << endl;
  
   //Compare whether stratagy 1 or 2 is better for aaron   
   if (A_Wins_Percent == A_Wins_Percents) {
      cout << "Strategy 1 is equal to strategy 2."<< endl;
   } 
   else if (A_Wins_Percent > A_Wins_Percents) {
      cout << "Strategy 1 is better than strategy 2." << endl;
   } 
   else { 
      cout << "Strategy 2 is better than strategy 1." << endl;
   } 
   return 0;
} 

//Implementation of functions. Look above for documentation of them.

//testing unit 1.
void test_at_least_two_alive(void)  {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
} 

//testing unit 2.
void test_Aaron_shoots1(void) {
   cout << "\nUnit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

   //testing case 1.
   
   cout << "\tCase 1: Bob alive, Charlie alive\n"      
      << "\t\tAaron is shooting at Charlie\n";
   B_alive = true;
   C_alive = true;
   assert(true == B_alive);
   Aaron_shoots1(B_alive, C_alive);

   //testing case 2.
   cout << "\tCase 2: Bob dead, Charlie alive\n"      
      << "\t\tAaron is shooting at Charlie\n";
   B_alive = false;
   C_alive = true;
   assert(false == B_alive);
   Aaron_shoots1(B_alive, C_alive);

   //testing case3.
   cout << "\tCase 3: Bob alive, Charlie dead\n"      
      << "\t\tAaron is shooting at Bob\n";
   B_alive = true;
   C_alive = false;
   assert(false == C_alive);
   Aaron_shoots1(B_alive, C_alive);
} 

//testing Unit 3.
void test_Bob_shoots(void) {
   cout << "\nUnit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

   //testing case 1.
   cout << "\tCase 1: Aaron alive, Charlie alive\n"      
      << "\t\tBob is shooting at Charlie\n";
   A_alive = true;
   C_alive = true;
   assert(true == A_alive);
   Aaron_shoots1(A_alive, C_alive);

   //testing case 2.
   cout << "\tCase 2: Aaron dead, Charlie alive\n"      
      << "\t\tBob is shooting at Charlie\n";
   A_alive = false;
   C_alive = true;
   assert(false == A_alive);
   Aaron_shoots1(A_alive, C_alive);


   //testing case 3.
   cout << "\tCase 3: Aaron alive, Charlie dead\n"      
      << "\t\tBob is shooting at Aaron\n";
   A_alive = true;
   C_alive = false;
   assert(false == C_alive);
   Aaron_shoots1(A_alive, C_alive);
   
} 

//testing Unit 4.
void test_Charlie_shoots(void) {
   cout << "\nUnit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

   //testing case 1.
   cout << "\tCase 1: Aaron alive, Bob alive\n"      
      << "\t\tCharlie is shooting at Bob\n";
   A_alive = true;
   B_alive = true;
   assert(true == A_alive);
   Aaron_shoots1(A_alive, B_alive);

   //testing case2.
   cout << "\tCase 2: Aaron dead, Bob alive\n"      
      << "\t\tCharlie is shooting at Bob\n";
   A_alive = false;
   B_alive = true;
   assert(false == A_alive);
   Aaron_shoots1(A_alive, B_alive);


   //testing case3.
   cout << "\tCase 3: Aaron alive, Bob dead\n"      
      << "\t\tCharlie is shooting at Aaron\n";
   A_alive = true;
   B_alive = false;
   assert(false == B_alive);
   Aaron_shoots1(A_alive, B_alive);
   
} 

//testing Unit 5.
void test_Aaron_shoots2(void) {
   cout << "\nUnit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   //testing case 1.
   cout << "\tCase 1: Bob alive, Charlie alive\n"      
      << "\t\tAaron intentionally misses his first shot\n"
      << "\t\tBoth Bob and Charlie are alive\n";
   B_alive = true;
   C_alive = true;
   assert(true == C_alive);
   Aaron_shoots2(B_alive, C_alive);
   
   //testing case 2.
   cout << "\tCase 2: Bob dead, Charlie alive\n"      
      << "\t\tAaron is shooting at Charlie\n";
   B_alive = false;
   C_alive = true;
   assert(false == B_alive);
   Aaron_shoots2(B_alive, C_alive);
   // testing case 3.
   cout << "\tCase 3: Bob alive, Charlie dead\n"      
      << "\t\tAaron is shooting at Bob\n";
   B_alive = true;
   C_alive = false;
   assert(false == C_alive);
   Aaron_shoots2(B_alive, C_alive);
} 

//user enter any character from keyboard and 
//it should move to next line of code.
void Press_any_key(void) {
   cout << "Press any key to continue...";
   cin.get(); 
}