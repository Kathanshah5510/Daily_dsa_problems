#include <bits/stdc++.h>
using namespace std;

int main(){
    int mass, n;
    cout << "Enter the mass of the spaceship: ";
    cin >> mass;
    cout << "Enter the number of asteroids: ";
    cin >> n;
    vector<int> asteroids(n);
    cout << "Enter the sizes of the asteroids: ";
    for(int i = 0; i < n; i++){
        cin >> asteroids[i];
    }

    long long currMass = mass;
    sort(asteroids.begin(), asteroids.end());
    for(int i = 0; i < n; i++){
        if(currMass >= asteroids[i]){
            currMass += asteroids[i];
        } 
        else{
            cout << "The spaceship cannot destroy all the asteroids." << endl;
            return 0;
        }
    }
    cout << "The spaceship can destroy all the asteroids." << endl;


    return 0;
}