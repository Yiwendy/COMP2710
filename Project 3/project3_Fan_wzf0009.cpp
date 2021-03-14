/* FILE NAME:  Project3_Fan_wzf0009
 * AUTHOR: Wenzhuo Fan 
 * AUBURN USERID: wzf0009
 * DATE: 07/03/2020
 * I used project2 hint given in the file on Canvas for project2 
 * and source from https://blog.csdn.net/u010545732/article/details/24385701 
 * to know about vector, and sourse from 
 * https://stackoverflow.com/questions/29997096/bold-output-in-c to 
 * know honw to make the input bold.
 * Merges the numbers in two files and writes all the numbers 
 * into a third file
 * gcc game.c -o game -lncurses
 */  
#include <fstream> 
#include <iostream>
#include <vector>
using namespace std; 

/* declare your user-defined functions */
/*
 * check if the file is exited
 * param: file name to read.(String)
 */
bool check_file(string); 

/* do not forget to describe each function */ 
/* Return  a vector containing the numbers in a file.
 * Param: file name to read.(String)
 */
vector<int> read_file(string); 

/* 
 * Write the value of a vector in a file.
 * Param: file name to read. (String)
 * Param: v Vector containing values to display. (vector<int>)
 */
void write_file(string, vector<int>);  
 
/*
 * combine values from two vectors to one vector.
 * and sort values from small to large.
 */
vector<int> merge(vector<int>, vector<int>); 
  
/*  
* Display the values of a given vector.
*
* Param: file Name of file to display. (string)
* Param: v Vector containing values to display. (vector<int>) 
*/  
void to_string(string, vector<int>); 
  
/*  
* Merge the numbers in two specified files and write all the numbers 
* to a specified third file sorted in ascending order.
* 
* Return: 1 Program completed successfully. (int)
*/ 
 
int main() {
/* declare your variables */ 
   // Name of input file1, file2.
   string infile1, infile2;
   
   //Name of output file.
   string outfile;
   
   //Vector containing values from file1 and file2;
   vector<int> numbers1;
   vector<int> numbers2;
   
   //Vector containing values for write to output file.
   vector<int> numbers3;
   
   cout << "*** Welcome to "<< "\e[1m"<<"Fan"
      << "\e[0m"<<"'s sorting program ***\n";

/* Get name of file one. */ 
   do  { 
   /* user friendly interfaces */ 
      cout << "Enter the first input file name: "<< "\e[1m";
      cin >> infile1;
      cout <<  "\e[0m";
   }  while (cin.fail() || !check_file(infile1)); 

/* Get and display numbers from file one. */ 
   numbers1 = read_file(infile1); 
   to_string(infile1, numbers1);
   

/* Get name of file two. */ 
   do  { 
   /*   user friendly interfaces */ 
      cout <<"Enter the second input file name: " <<  "\e[1m";
      cin >> infile2;
      cout <<  "\e[0m";
   } while (cin.fail() || !check_file(infile2)); 

/* Get and display numbers from file two. */ 
   numbers2 = read_file(infile2); 
   to_string(infile2, numbers2);
   

/* Combine vectors and display the sorted result. */
/* sort the number from vector number1 and numbers2. */
   sort(numbers1.begin(),numbers1.end());
   sort(numbers2.begin(),numbers2.end());
   numbers3 = merge(numbers1, numbers2);
   cout << "The sorted list of " << numbers3.size() 
      << " numbers is: ";
      
   for (int i = 0; i < numbers3.size() - 1; i++) {
      cout << numbers3.at(i) << " ";
   }
   cout << numbers3.at(numbers3.size() - 1) << "\n";
   
/*   Get name of output file. */ 
   do{ 
    /* user friendly interfaces */
      cout << "Enter the output file name: " <<  "\e[1m";
      cin >> outfile;
      cout <<  "\e[0m"; 
   }  while (cin.fail());
   
   /* Write combined vector to output file. */ 
   write_file(outfile, numbers3); 
   cout << "*** Please check the new file - " << outfile << "***\n";
   cout << "*** Goodbye. ***\n";
   
   return 1; 
} 

bool check_file(string file) {  
   /* Input file stream. (ifstream) */
   ifstream stream;

   /* Check whether file exists. */ 
   stream.open(file.c_str()); 
   if  (stream.fail()) { 
      cerr << "File not found.\n\n";
      return false;
   } 
   stream.close();

   return true; 
} 

vector<int> read_file(string file) {  
   /* Input file stream. (ifstream) */
   ifstream stream;

   /* Vector containing numbers from file. (vector<int>) */
   vector<int> v;

   /* Integer read from file. (int) */
   int i;  

   /* Add each number in the file to a vector. */ 
   stream.open(file.c_str());
   while (stream.good()) { 
      stream >> i;
      v.push_back(i);
      
   }
   v.pop_back();
   stream.close();
   
   return v;
} 

void write_file(string file, vector<int> v) {  
   /* Output file stream. (ofstream) */ 
   ofstream stream;
   
   /* Vector iterator number. */
   unsigned short i;
   
   /* Write each number in the vector to the file.*/
   stream.open(file.c_str());
   for (i = 0; i < v.size() - 1; i++) {
      stream << v.at(i) << "\n";
   }
   stream << v.at(v.size() - 1);
   stream.close();
}



vector<int> merge(vector<int> v1, vector<int> v2) {  
   //variables
   vector<int> v3;
   
   /* Vector interator number.*/
   unsigned short i;
   
   /* Vector iterator size. (unsigned short) */
   unsigned short j;
   
   /*   Compare both vectors. */
   while (v1.size() > 0 && v2.size() > 0) { 
      if  (v1.at(0) < v2.at(0)) {
         v3.push_back(v1.at(0));
         v1.erase(v1.begin());
      } 
      else { 
         v3.push_back(v2.at(0));
         v2.erase(v2.begin());
      } 
   } 

/* Add any remaining numbers from vector one. */ 
   if  (v1.size() > 0) {  
      j = v1.size();
      for (i = 0; i < j; i++) {
         v3.push_back(v1.at(0));
         v1.erase(v1.begin());
      }
   }
    

/* Add any remaining numbers from vector two. */ 
   if  (v2.size() > 0) {  
      j = v2.size();
      for (i = 0; i < j; i++) {
         v3.push_back(v2.at(0));
         v2.erase(v2.begin());
      } 
   }
   return v3; 
} 

void to_string(string file, vector<int> v) { 
/* Vector interator number. (unsigned short) */ 
   unsigned short i; 
   
/* Display the numbers contained in a vector. */
   cout << "The list of " << v.size() 
      << " numbers " << "in file " << "\e[1m"
      << file <<  "\e[0m" << " is:\n";
   
   for (i = 0; i < v.size(); i++) {
      cout << v.at(i) << "\n";
   }
   cout << "\n";

}