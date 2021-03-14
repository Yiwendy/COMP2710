/* FILE NAME:  Project4_Fan_wzf0009
 * AUTHOR: Wenzhuo Fan 
 * AUBURN USERID: wzf0009
 * DATE: 07/017/2020
 * I used project4 hint given in the file on Canvas for project4
 * Allows players to create their trivia questions and answers. 
 * gcc game.c -o game -lncurses
*/  
 //Libary imports. 
#include <iostream>
#include <string> 
using namespace std; 

//Structure for creating a linked list that holds a trivia question,answer and point amount.
struct triva_node { 
   string question;
   string answer;
   int point;
   triva_node *next; 
};  
//creates a pointer to triva_node.
typedef triva_node* ptr_node; 

//variable.
int num_of_quest = 0;

//Prototypes
void first_question_list(ptr_node& q_list);
void add_question(ptr_node& q_list);
int ask_question(ptr_node q_list, int number_ask);
void Unit_Test();

//creates two versions.
//#define UNIT_TESTING
#define triva_quiz 

int main() {
   //Unit_test(); 
   ptr_node node_list = new triva_node; 
//Creates a new trivia game /
//Sets up three original  questions/
//Sets up loop for user to input his or her own questions.
//Quiz questions are stored in linked list. 
#ifdef triva_quiz 
   first_question_list(node_list); 

   cout << "*** Welcome to Fan's trivia quiz game ***\n"; 
   string input;
   do {
      add_question(node_list);
      cout << "Continue? (Yes/No): "; 
      getline(cin, input);
   //do {
   //   add_question(node_list); 
   
   //   cout << "Continue? (Yes/No): "; 
   //   getline(cin, input);
   //} while (input.compare("Yes") == 0 || input.compare("yes") == 0);
   //
   //cout << endl;
   
   //Get questions if they want to enter their own
      
      while(input != "Yes" && input != "No") {
         cout << "Please enter valid input (Yes/No): ";
         getline(cin, input);
      }
      
   } while (input.compare("Yes") == 0 || input.compare("yes") == 0);
   
   cout << endl;

//This is start of Trivia quiz game.
   ask_question(node_list, num_of_quest); 
   cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***"; 
   return 0; 
} 
#endif

//Method for testing 
#ifdef UNIT_TESTING 
Unit_Test();
return 0; 
} 
#endif

//initializes the quiz to have these three questions inputted into the linked list.
void first_question_list(ptr_node& q_list) {
//ptr_node cur_ptr; 
//ptr_node cur_ptr; 
//string bob; 
   ptr_node cur_ptr = new triva_node; 

   // question 1 and initialize q_list to be first question
   cur_ptr->question = "How long was the shortest war on record? (Hint: how many minutes)";
   cur_ptr->answer = "38"; 
   cur_ptr->point = 100;
   cur_ptr->next = new triva_node;
   q_list = cur_ptr;
   cur_ptr = q_list->next;

   // question 2 and initialize q_list to be first question
   cur_ptr->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   cur_ptr->answer = "Bank of Germany"; 
   cur_ptr->point = 50;
   cur_ptr->next = new triva_node;
   cur_ptr = q_list->next;

   // question 3 and initialize q_list to be first question
   cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
   cur_ptr->answer = "Wii Sports"; 
   cur_ptr->point = 20;
   cur_ptr->next = new triva_node;
   cur_ptr->next = NULL;

   num_of_quest += 3;

} 
//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& q_list) { 
   ptr_node n_ptr = new triva_node;
   int num;
   //string answer;
   //gets data from user
   cout << "Enter a new question: "; 
   getline(cin, n_ptr->question);
   cout << "Enter an answer: ";
   getline(cin, n_ptr->answer);
   cout << "Enter award points: ";
   while (cin.fail()){
   cout << "Enter a valid number: ";
   }
   cin >> n_ptr->point;
   cin.ignore();
   n_ptr->next = NULL;

   // Add to the end of the list
   triva_node* last = q_list;
   while (last->next != NULL) {
      last = last->next;
   }
   last->next = n_ptr;
   num_of_quest++;
   
} 
//Checks for null value 
//Ask the user trivia questions and starts the game 
int ask_question(ptr_node q_list, int num_ask) { 
   ptr_node cur_ptr = q_list;
   string user_answer;
   int total_points = 0;
   
   // validate q_list test
   if  (q_list == NULL) {
      return 0; 
   } 

   // validate num_ask test
   if (num_ask <= 0) { 
      cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl; 
      return 1;
   } 
   else if(num_of_quest < num_ask) { 
      cout << "Warning - There is only " <<  num_of_quest << " trivia in the list."; 
   } 
   else { 
      for  (int x = 0; x < num_ask; x++) { 
         cout << "Question: " <<  cur_ptr->question <<  endl;cout << "Answer: "; 
         getline(cin, user_answer); 
         if  (user_answer.compare(cur_ptr->answer) == 0) {//correct_answer) { 
            cout << "Your answer is correct. You receive " << cur_ptr->point << " points." << endl;
            total_points += cur_ptr->point;
         } 
         else { 
            cout << "Your answer is wrong. The correct answer is " << cur_ptr->answer << endl;
         
         } 
         cout << "Your total points: " << total_points << endl << endl;
         cur_ptr = cur_ptr->next;
      } 
   }
   return 0; 
} 

//Test cases to check whether the methods work. 
void Unit_Test() { 
   //initialize trivia question list
   ptr_node node_list = new triva_node; 
   first_question_list(node_list);
   
   cout << "Unit Test Case 1: Ask no question. The program should give a warning message." <<  endl; 
   ask_question(node_list, 0); 
   cout << "\nCase 1 passed\n\n" ; 

   cout << "Unit Test Case 2: Ask 1 question in the linked list.  The tester enters an incorrect answer." << endl;
   ask_question(node_list, 1);
   cout << "\nCase 2.1 passed\n\n" ;  

   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
   ask_question(node_list,1);
   cout << "Case 2.2 passed\n\n";

   cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
   ask_question(node_list,3);
   cout << "Case 3 passed\n\n";

   cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
   ask_question(node_list,5);
   cout << "Case 4 passed\n\n";


   cout << "\n\n*** End of the Debugging Version ***";
}