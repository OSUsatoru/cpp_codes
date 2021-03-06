#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;

void Solve()
{

    ifstream ifs("input.txt");
    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }
    vector<int> inputs;
    int n;
    while(ifs >> n){
        inputs.push_back(n);
    }

    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }

    sort(inputs.begin(),inputs.end());

    for(int i = 0; i < inputs.size()-2; ++i){
        for(int j = i+1; j < inputs.size()-1; ++j) {
            for(int k = j+1; k < inputs.size(); ++k) {
                if(inputs[i]+inputs[j]+inputs[k] == 2020){
                    cerr << inputs[i] << ' ' << inputs[j] << ' ' << inputs[k] << endl;
                    ofs << inputs[i]*inputs[j]*inputs[k] << endl;
                }else if(inputs[i]+inputs[j]+inputs[k] > 2020){
                    break;
                }
            }

        }
    }

    ifs.close();



}
int main()
{
    fastio;
    Solve();

    return 0;
}