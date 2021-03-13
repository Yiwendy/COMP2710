//Wenzhuo Fan
//wzf0009
//Project1_Fan_wzf0009
//The program will calculatehow many months it will take to pay 
//off this loan in particular and any loan in general.
//I look up https://www.cnblogs.com/hustxujinkang/p/4176191.html 
//about the line-up style.

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

   double loan, rate, monthlyPayments;
   double l,r,interestMonth, debtReduction,totalInterest;
   int i;
   //Showpoint for dollar formatting.
   cout.setf(ios::fixed,ios::floatfield);
   cout.precision(2);
   
   //User inputs data.
   cout<<"\nLoan Amount: ";
   cin>>loan;
   cout<<"Interest Rate (% per year): ";
   cin>>rate;
   cout<<"Monthly Payments: ";
   cin>>monthlyPayments;
   
   //CALCULATIONS
   r = rate/12;  
   l = loan;
   totalInterest = 0;
   //Divide by 100 to convert percentage into decimal
   interestMonth = (loan*r)/100;
   debtReduction = monthlyPayments-interestMonth;
   //OUTPUT
   using std::cout;
   cout.setf(std::ios::left);
   int w = cout.width();
   cout<<"**********************************************************";
   cout<<"\n\t\t\tAmortization Table";
   cout<<"\n**********************************************************";
   //First payment
   //Left lined-up style.
   cout.width(9);
   cout<<"\nMonth";
   cout.width(9);
   cout<<"Balance";
   cout.width(13);
   cout<<"Payment";
   cout.width(7);
   cout<<"Rate";
   cout.width(11);
   cout<<"\tInterest"<<"Principal\n";
   cout.width(8);
   cout<<i<<"$";
   cout.width(8);
   cout<<l;
   cout.width(13);
   cout<<"N/A";
   cout.width(9);
   cout<<"N/A";
   cout.width(10);
   cout<<"N/A"<<"N/A\n";
   //Second to next-to-last payment 
   for(i = 1; l > monthlyPayments; i++)
   {
     
      totalInterest =totalInterest+interestMonth;
      l = (l-debtReduction);
      
      cout.width(8);
      cout<<i<<"$";
      cout.width(8);
      cout<<l<<std::fixed<<std::setprecision(2)<<"$";
      cout.width(12);
      cout<<monthlyPayments;
      cout.width(9);
      cout<<r<<"$";
      cout.width(9);
      cout<<interestMonth<<"$";
      cout<<debtReduction;
      cout<<"\n";
      interestMonth = (l*r)/100;
      debtReduction =monthlyPayments-interestMonth;
   }
   totalInterest =totalInterest+interestMonth;
   //Last payment.
   cout.width(8);
   cout<<i;
   cout.width(9);
   cout<<"$0.00"<<"$";
   cout.width(12);
   cout<<interestMonth+l;
   cout.width(9);
   cout<<r<<"$";
   cout.width(9);
   cout<<interestMonth<<"$";
   cout<<l;
   cout<<"\n**********************************************************\n";
   cout<<"\nIt takes "<<i<<" months to pay off the loan.";
   cout<<"\nTotal interest paid is: $"<<totalInterest<<"\n";
   return 0;
}