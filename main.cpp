#include <iostream>
#include <bitset>
#include <algorithm>
#include <string>
using namespace std;
const int size = 1000;
bitset<size> tot;
int pos_h, pos_t;
int m=3, b=20;
int f[100][100];
void init() {
    for(int i = 0; i <= 99; i++) {
        f[i][i] = f[i][0]=1;
    }
    for(int i = 1; i <= 99; i++)
        for(int j = 1; j < i; j++)
            f[i][j] = f[i-1][j] + f[i-1][j-1];
}
void change(int bar) {
    int last = 0;
    int mid = 0;
    bool flag_mid= false;
    bool flag_begin = false;
    int cnt = 0;
    // cout << bar << " " << pos_h << endl;
    for (int i = 0; i < pos_h; i++) {
        if (tot[i]) flag_begin = true;
        if (tot[i] == 0) cnt++;
        if (tot[i] == 0 and flag_begin) {
            for (int j = 1; j <= cnt; j++) tot[i-j] = 0;
            for (int j = cnt+1; i-j >= 0; j++) tot[i-j] = 1;
            tot[i] = 1;
            return;
        }
    }
    tot.reset();
    for (int i = 0; i < bar-1; i++) tot.set(i);
    tot.set(pos_h);
    pos_h++;
}


int main() 
{
    init();
    ios::sync_with_stdio(false);
    cout << "input m b:";
    cin >> m >> b;
    freopen("out.txt", "w" ,stdout);	
    int bar = m - 1;
    pos_h = bar;
    int cnt = 0;
    for (int i = 0; i < bar; i++) tot.set(i);
    while (true) {
        // cout << tot << endl;
        string tmp = tot.to_string();
        reverse(tmp.begin(), tmp.end());
        // cout << tmp << endl;
        int last_pos = 0;
        for (int j = 0; j < m+b-1; j++) {
            if(tmp[j] == '1') {
                if (last_pos == 0 and tmp[0] == '0') last_pos--;
                cout << max(0, j - last_pos - 1) << " ";
                last_pos = j;
            }
        }
        cout << m+b-last_pos-2 << endl;
        cnt++;
        change(bar);
        if (tot[m+b-1]) break;
    }
    int ans = f[m+b-1][m-1];
    cout << "cal with comb is: " << ans <<endl;
    cout << "list length is: " << cnt << endl;
    return 0;
}
