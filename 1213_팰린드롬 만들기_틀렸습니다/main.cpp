#include <iostream>
#include <cstring>
#include <cstdio>

#define ALPHA_NUM   26

using namespace std;

char alpha[51];
int cnt_alpha[26], right_ch[51];

void sol() {
  // char ch;
  int cnt = 0, center = -1;
  for (int i = 0; i < ALPHA_NUM; i++) {
    if (cnt_alpha[i] % 2) {
      center = i;
      cnt++;
    }
  }
  if (cnt > 1) {
    cout << "I'm Sorry Hansoo\n";
    return;
  }

  cnt = 0;
  for (int i = 0; i < ALPHA_NUM; i++) {
    if (i == center) {
      cnt_alpha[i]--;
    }

    int j;
    for (j = 0; j < cnt_alpha[i]/2; j++) {
      printf("%c", i + 'A');
    }
    for (; j < cnt_alpha[i]; j++) {
      right_ch[cnt++] = i;
    }
  }
  if (center >= 0) {
    printf("%c", center + 'A');
  }
  for (int i = cnt - 1; i >= 0; i--) {
    printf("%c", right_ch[i] + 'A');
  }
  cout << "\n";
  return;
}

int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  cin >> alpha;
  for (int i = 0; alpha[i] != '\0'; i++) {
    cnt_alpha[alpha[i] - 'A']++;
  }

  sol();
  return 0;
}
