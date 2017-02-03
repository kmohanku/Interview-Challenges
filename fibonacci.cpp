#include <iostream>

using namespace std; //Convenience as the program isn't complex enough to have ambiguity

//Reccursive function call
int fibonacci(int number){
    if(number<=0) //Tackle 0 and negative cases
    return 0;
	
    if(number == 1) //Tackle case where value is 1
    return 1;

    else
    return fibonacci(number-1) + fibonacci(number-2); //Return the sum of previous 2 numbers
 }


int main(){
//Accept input of length
    cout << "enter the length of the sequence" << endl;
    
    int len;
    int num; //To play around with return value
    
    cin >> len; //Accept input

//Print element after element upto the length input
    for(int iter = 0; iter < len; ++iter){
    bool prime = true; //Prime check. Assume prime until proven false
    num = fibonacci(iter); //Get number returned by fibonacci function

    if(num == 0){
    cout << "FizzBuzz" << " "; //0 is divisible by everything. So, I give preference to the highest factor 15
    continue;
    }

    else if(num == 1){ // 1 is not a prime. Special case.
    cout << "1" << " ";
    continue;
    }

    for(int iter2 =2; iter2< num/2; ++iter2){ //Primes are divisible by 1 and themselves. Any other factors means they aren't prime
    if(num % iter2 == 0){
    prime = false; //Declare as not prime
    break; //No need to iterate further
     }
   }

   if(prime){ //Priority given to prime numbers.
   cout << "BuzzFizz" << " ";
   continue;
   }

   else if((num % 3 == 0) && (num%5==0) && (num%15==0)) //Priority given to 15 if divisible by all and not prime
   cout << "FizzBuzz" << " ";

   else if((num % 3 == 0) && (num%5==0))//Priority given to 5 if divisible only by 3 and 5 and not prime
   cout << "Fizz" << endl;

   else if(num % 3 == 0)//If only divisible only by 3 and not prime
   cout << "Buzz"<< " ";

   else if(num % 5 == 0)//If only divisible only by 5 and not prime
   cout << "Fizz"<< " ";

   else if(num % 15 == 0)//If only divisible only by 15 and not prime
   cout << "FizzBuzz"<< " ";

   else cout << num << " "; //Printing those that are not prime and aren't divisible by 3, 5 or 15

 }

cout << endl;
//End of main
}


