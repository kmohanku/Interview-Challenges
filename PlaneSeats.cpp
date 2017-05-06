//Given N rows of seats in an aeroplane, with each row having 10 seats in 3-4-3 arrangement and a string of reserved seats,
//find the number of 3 member families that can sit together (all next to each other, no aisle separation allowed) on the plane.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int findtripletseats(int N, string& reserved_seats){
  vector< vector<char> > tracker(N, vector<char>());
  string parser;
  int seat_count = 0;

//If no seats are reserved, return 3 family seating available per row
  if(reserved_seats.empty())
   return N*3;

  for(auto i = reserved_seats.begin(); i< reserved_seats.end();++i){
    //parse string until a space and process it 
    while(!isspace(*i) && i< reserved_seats.end()){
        parser.push_back(*i);
        i++;
    }

    if(parser.size() == 2){
        auto temp = parser.begin();
        tracker[(int(*temp) -int('0'))-1].push_back(*(temp + 1)); //vector always fills from 0. For every row, push reserved seat
    }

      else{                         //handle 3 character strings such as 21B
        string double_digit;
        auto temp = parser.begin();
        double_digit.push_back(*temp);
        temp++;
        double_digit.push_back(*temp);
        temp++;
        //cout << double_digit << endl;
        //cout << *temp << endl;
        tracker[stoi(double_digit)-1].push_back(*temp);
      }

    parser.clear();
 }

  for(int j = 0; j < N; ++j){

    if(tracker[j].empty()){
      cout << "All 3 seats available for row: " << j << endl;
      seat_count+=3;
    }

    else{
      //if none of the set of 3 seats are occupied, they can seat 1 family
      if((find(tracker[j].begin(),tracker[j].end(), 'A') == tracker[j].end()) && (find(tracker[j].begin(),tracker[j].end(),'B') == tracker[j].end()) && (find(tracker[j].begin(),tracker[j].end(),'C') == tracker[j].end())){
      // cout << "A B C seats available for row: " << j+1 << endl;
        seat_count++;
      }
    
      if((find(tracker[j].begin(),tracker[j].end(), 'H') == tracker[j].end()) && (find(tracker[j].begin(),tracker[j].end(),'J') == tracker[j].end()) && (find(tracker[j].begin(),tracker[j].end(),'K') == tracker[j].end())){
        // cout << "H J K  seats available for row: " << j+1 << endl;
        seat_count++;
      }
      //The middle 2 seats need to be madatorily vacant and atleast 1 of the corner seats should be vacant to house a family
      if(((find(tracker[j].begin(),tracker[j].end(), 'E')==tracker[j].end()) && (find(tracker[j].begin(),tracker[j].end(),'F')==tracker[j].end())) && ((find(tracker[j].begin(),tracker[j].end(),'D')==tracker[j].end())||(find(tracker[j].begin(),tracker[j].end(),'G')==tracker[j].end()))){
        // cout << "E F G|D available for row: " << j+1 << endl;
        seat_count++;
      }

     }
    }

  return seat_count;
}


int main(){

  string reservedSeats;
  int N;

  cout << "Enter the number of rows" << endl; 
  cin >> N;
  cin.ignore();
  cout << "Enter reserved seats separated by a space" << endl;
  getline(std::cin,reservedSeats);
  int count = findtripletseats(N, reservedSeats);
  cout << "Total families of 3 that can contiguously fit in the plane are: " << count << endl;
  return 0;
}
