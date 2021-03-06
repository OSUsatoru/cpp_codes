#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
/*
f 63.5 64
b 31.5 32
f 47.5 48
b
*/
typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;

const int PATTERN = 5;

void Solve()
{
    ifstream ifs("input.txt");
    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }
    int ans = 0;
    string str;
    while(getline(ifs, str)){
        int row_max=127,row_min = 0, col_max=7, col_min=0,middle;
        for(int i = 0; i < str.length(); ++i){
            switch(str[i]){
                case 'F':
                    if(row_max-row_min == 1){
                        row_max = row_min;
                    }
                    else{
                        middle = (row_max + row_min + 1)/2;
                        row_max = middle - 1;
                    }
                    break;
                case 'B':
                    if(row_max-row_min == 1){
                        row_min = row_max;
                    }else{
                        middle = (row_max + row_min + 1)/2;
                        row_min = middle;
                    }
                    break;
                case 'R':
                    if(col_max-col_min == 1){
                        col_min = col_max;
                    }else{
                        middle = (col_max + col_min + 1)/2;
                        col_min = middle;
                    }
                    break;
                case 'L':
                    if(col_max-col_min == 1){
                        col_max = col_min;
                    }else{
                        middle = (col_max + col_min + 1)/2;
                        col_max = middle - 1;
                    }
                    break;
            }
        }
        ans = max(ans, (row_max * 8 + col_max));

    }


    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }
    ofs << ans;

    ifs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}