#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int fac[10][4]={{0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0}, {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}};

    int minDigits(int a, int b, int c, int d){
        int cnt = c + d;
        cnt += a / 3;
        a %= 3;
        cnt += b / 2;
        b %= 2;

        if(a && b){
            cnt++;
            a--;
            b--;
        }

        if(a > 0)
            cnt++;

        if(b > 0)
            cnt++;

        return cnt;
    }

    string build(int a, int b, int c, int d, int len){
        vector<int> digits;

        while(c > 0){
            digits.push_back(5);
            c--;
        }

        while(d > 0){
            digits.push_back(7);
            d--;
        }

        while(a >= 3){
            digits.push_back(8);
            a -= 3;
        }

        while(b >= 2){
            digits.push_back(9);
            b -= 2;
        }

        if(a > 0 && b > 0){
            digits.push_back(6);
            a--;
            b--;
        }

        if(a == 2){
            digits.push_back(4);
            a = 0;
        }
        else if(a == 1){
            digits.push_back(2);
            a = 0;
        }

        if(b == 1){
            digits.push_back(3);
            b = 0;
        }

        int ones = len - (int)digits.size();
        string result(ones, '1');
        sort(digits.begin(), digits.end());
        for (int digit : digits)
            result += char('0' + digit);

        return result;
    }

    string smallestNumber(string num, long long t){
        int need[4] = {0, 0, 0, 0};
        int primes[4] = {2, 3, 5, 7};

        for(int i = 0; i < 4; i++){
            while(t % primes[i] == 0){
                need[i]++;
                t /= primes[i];
            }
        }

        if(t != 1)
            return "-1";
        int n = num.size();
        vector<array<int, 4>> pref(n + 1);
        pref[0] = {0, 0, 0, 0};
        int firstZero = n;

        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i];
            int digit = num[i] - '0';
            if(digit == 0){
                firstZero = min(firstZero, i);
            }
            else{
                for(int j = 0; j < 4; j++){
                    pref[i + 1][j] += fac[digit][j];
                }
            }
        }

        if(firstZero == n){
            bool valid = true;
            for(int j = 0; j < 4; j++){
                if(pref[n][j] < need[j]){
                    valid = false;
                    break;
                }
            }

            if(valid)
                return num;
        }

        int start = min(n - 1, firstZero);
        for(int i = start; i >= 0; i--){
            int original = num[i] - '0';
            for(int digit = max(1, original + 1); digit <= 9; digit++) {

                int rem[4];

                for(int j = 0; j < 4; j++){
                    int have = pref[i][j] + fac[digit][j];
                    rem[j] = max(0, need[j] - have);
                }

                int remainingPositions = n - i - 1;
                if(minDigits(rem[0], rem[1], rem[2], rem[3]) <= remainingPositions){
                    string ans;
                    ans += num.substr(0, i);
                    ans += char('0' + digit);
                    ans += build(rem[0], rem[1], rem[2], rem[3], remainingPositions);

                    return ans;
                }
            }
        }

        int required = minDigits(need[0], need[1], need[2], need[3]);
        int len = max(n + 1, required);
        return build(need[0], need[1], need[2], need[3], len);
    }
};

int main(){
    string num;
    long long t;
    cout << "Enter num: ";
    cin >> num;
    cout << "Enter t: ";
    cin >> t;
    Solution obj;
    string answer = obj.smallestNumber(num, t);
    cout << "Smallest number: " << answer << endl;

    return 0;
}