//Author: Khan, Zahir
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void generateArray(int arr[][7], int x, int y) {
  for(int i=0; i<x; i++) {
    for(int j=0; j<y; j++) {
      arr[i][j] = rand()%(70-20+1)+20; //Max temp 70, min 20
    }
  }
}

void printArray(int arr[][7], int x, int y) {
  for(int i=0; i<x; i++) {
    cout << "Week " << i+1 << ": ";
    for(int j=0; j<y; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

string dayOfWeek (int x) {
  if(x==0) return "Sunday";
  if(x==1) return "Monday";
  if(x==2) return "Tuesday";
  if(x==3) return "Wednesday";
  if(x==4) return "Thursday";
  if(x==5) return "Friday";
  if(x==6) return "Saturday";
  return " ";
}

void weeklyData(int arr[][7], int x, int y) {
  for(int i=0; i<x; i++) {
    int maxTemp = arr[i][0], minTemp = arr[i][0], sum = 0;
    double avgTemp;
    string maxDay = "Sunday", minDay = "Sunday";
    cout << "---" << " Week " << i+1 << "---" << endl;
    for(int j=0; j<y; j++) {
      sum+=arr[i][j];
      if (arr[i][j] < minTemp) {
        minTemp = arr[i][j];
        minDay = dayOfWeek(j);
      }
      if (arr[i][j] > maxTemp) {
        maxTemp = arr[i][j];
        maxDay = dayOfWeek(j);
      }
    }
    cout << "Highest Tempature: " << maxTemp << " (" << maxDay << ")" << endl;
    cout << "Lowest Temperature: " << minTemp << " (" << minDay << ")" << endl;
    avgTemp = sum/7.0;
    cout <<"Average Temperature: " << avgTemp << endl;
  }
}

void weekdayAvg (int arr[][7], int x, int y) {
  for(int j=0; j<y; j++) {
    int sum = 0;
    double avg;
    for(int i=0; i<x; i++) {
      sum += arr[i][j];
    }
    avg = sum/4.0;
    cout << dayOfWeek(j) << ": " << avg << endl;
  }
}

int main() {
  srand(time(0));
  int tempData[4][7];
  generateArray(tempData, 4, 7);
  cout << "Temperature Data in Fahrenheit: " << endl;
  printArray(tempData, 4, 7);
  cout << endl;
  weeklyData(tempData,4,7);
  cout << endl;
  cout << "--- Average By Weekday ---" << endl;
  weekdayAvg(tempData, 4,7);
  return 0;
}