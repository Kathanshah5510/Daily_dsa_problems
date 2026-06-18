#include <bits/stdc++.h>
using namespace std;

int main(){
    int hour, min;
    cin >> hour >> min;
    double hour_angle = (hour % 12) * 30 + (min / 60.0) * 30;
    double min_angle = (min / 60.0) * 360;
    double angle = abs(hour_angle - min_angle);
    if (angle > 180) {
        angle = 360 - angle;
    }
    cout << fixed << setprecision(1) << angle << endl;
    return 0;
}