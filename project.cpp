#include <iostream>
#include <cmath>

#include <cstdlib>  

#include <ctime>
#include <algorithm>

#include <random>

#include <functional>
using namespace std;


void tapEnter() {
  cout << "Press Enter to continue...";
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');  
  cin.get();  
  system("clear");
}

void playMemoryGame() {
  srand(time(0));
  int lenght, attempts = 0;
  bool isWon = false;
  cout << "Welcome to the memory game!\n Enter the size of an array (6-20): ";
  cin >> lenght;
  
  if (lenght % 2 == 0 && (lenght >= 6 && lenght <= 20)) {
    int arr[lenght];
    string questionArr[lenght];

    for (int i = 0; i < lenght; i += 2) {
      int k = rand() % 10 + 1;
      arr[i] = k;
      arr[i + 1] = k;
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(arr, arr + lenght, g);

    for (int i = 0; i < lenght; i++) {
      questionArr[i] = "?";
    }

    while (!isWon) {
      int first, second, cheking = 0;
      cout << "Here is the array: ";
      for (int i = 0; i < lenght; i++) {
        cout << questionArr[i] << " ";
      }
      cout << "\nEnter the index : ";
      cin >> first;
      cout << "The card at index " << first << " is: " << arr[first];

      cout << "\nEnter the second index : ";
      cin >> second;
      cout << "The card at the index " << second << " is: " << arr[second] << endl;

      attempts++;

      for (int i = 0; i < lenght; i++) {
        if (i == first || i == second) {
          cout << arr[i] << " ";
        } else {
          cout << questionArr[i] << " ";
        }
      }

      if (arr[first] == arr[second]) {
        cout << "\nGreat! The cards are matched. Continue...\n" << endl;
        questionArr[first] = to_string(arr[first]);
        questionArr[second] = to_string(arr[second]);
      } else {
        cout << "\nThe cards do not match Try again!\n" << endl;
      }

      for (int i = 0; i < lenght; i++) {
        if (questionArr[i] != "?") {
          cheking++;
        }
      }

      if (cheking == lenght) {
        cout << " You won! Here's the amount of your attempts: " << attempts << "\n";
        isWon = true;
      } else {
        tapEnter();
        cout << "\n\n";
      }
    }
  } else {
    cout << "Please, enter an even number from 6 to 20 range";
  }
}

int main() {
  playMemoryGame();
  return 0;
}
