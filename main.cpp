#include <ctime>
#include <cstdio>
#include <cstring>

const int size = 50;
bool tot[size];
int pos_h;
int m, b;

int main() 
{
    clock_t startTime = clock();
    m = 10;
    b = 20;
    int ans = 0;
    int bar = m - 1;
    pos_h = bar;
    bool flag_begin = false;
    int cnt = 0;
    bool swap = false;
    memset(tot, true, sizeof(bool)*bar);
    while (true) {
        int last_pos = -(tot[0]==false);
        for (int j = 0; j < m+b-1; j++) {
            if(tot[j]) {
                int t = j - last_pos - 1;
                if (not j) t = t>0?t:0;
                printf("%d ", t);
                last_pos = j;
            }
        }
        printf("%d\n", m+b-last_pos-2);
        ans++;

        flag_begin = false;
        cnt = 0;
        swap = false;
        for (int i = 0; i < pos_h; i++) {
            if (not flag_begin and tot[i]) flag_begin = true;
            if (not tot[i]) cnt++;
            if (not tot[i] and flag_begin) {
                if (i - cnt - 1 >= 0) memset(tot, true, sizeof(bool)*(i-cnt));
                memset(tot+i-cnt, false, cnt*sizeof(bool));
                tot[i] = 1;
                swap = true;
                break;
            }
        }
        if (swap) continue;
        memset(tot, true, sizeof(bool)*(bar-1));
        memset(tot+bar-1, false, sizeof(bool)*(pos_h-bar+1));
        tot[pos_h] = true; 
        pos_h++;

        if (tot[m+b-1]) break;
    }
    printf("list length is: %d\n", ans);
    clock_t endTime = clock();
    printf("%f\n", double(endTime - startTime));
    return 0;
}
