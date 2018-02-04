#include <iostream>
#include <cstring>
#include <cstdio>

#define MAX_RANGE   50
using namespace std;

int n, m;
int map[51][51];

int sol() {
  int len = 1, ret = 0;
  for (int t = 0; t < MAX_RANGE; t++) {
    bool isChecked = false;
    // cout << "t : " << t << "       ";
    // cout << "len : " << len << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // cout << "이중 for문 (i,j) : " << i << ", " << j << endl;
        if (i+len >= n || j+len >= m) {
          // cout << "continue (i,j) : " << i << ", " << j << endl;
          continue;
        }

        if (map[i][j] == map[i][j+len] && map[i][j+len] == map[i+len][j+len] &&
          map[i+len][j+len] == map[i+len][j]) {
            // cout << "(i , j , len) : " << i << ", " << j << ", " << len << endl;
            ret = max(ret, len);
            isChecked = true;
            break;
          }
      }
      if (isChecked) {
        break;
      }
    }
    // t++ 될 때마다, 확인할 정사각형의 한 변의 길이를 늘림.
    len++;
  }

  return ret + 1;
}


int main(int argc, char const *argv[]) {
  // freopen("input.txt", "r", stdin);
  int ret = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &map[i][j]);
    }
  }

  ret = sol();
  cout << ret * ret << "\n";
  return 0;
}


// #include <iostream>
// #include <cstring>
// #include <cstdio>
//
// using namespace std;
// int arr[200][200];
// int main(int argc, char const *argv[]) {
//   int n, m;
//   scanf("%d %d", &n, &m);
//
//   memset(arr, -1, sizeof(arr));
//   for (int i = 0; i < n; i++)
//       for (int j = 0; j < m; j++)
//           scanf("%1d", &arr[i][j]);
//
//   int ans = 0;
//   // 크기
//   int x = 1;
//   for (int idx = 0; idx <= 50; idx++)
//   {
//       bool chk = false;
//       for (int i = 0; i < n; i++)
//       {
//           for (int j = 0; j < m; j++)
//               if (arr[i][j] == arr[i][j + x] && arr[i][j + x] == arr[i + x][j] && arr[i][j] == arr[i + x][j + x])
//               {
//                   ans = max(ans, x);
//                   chk = true;
//                   break;
//               }
//           if (chk)
//               break;
//       }
//       x++;
//   }
//
//   ans++;
//   printf("%d", ans * ans);
//
//   return 0;
// }
//
//
// // #include <iostream>
// // using namespace std;
// // int n, m;
// // char map[51][51];
// //
// //
// // // vertical move
// // void move_ver(int r, int c) {
// //
// //
// // }
// //
// // // horizontal move
// // void move_hor(int r, int c) {
// //
// //
// //
// // }
// //
// //
// //
// // int sol (int r, int c) {
// //   int cnt = 0;
// //   for (int i = c; i < m; i++) {
// //     cnt++;
// //     if (i <  m) {
// //
// //     }
// //   }
// //
// //
// //   return 0;
// // }
// //
// // int main(int argc, char const *argv[]) {
// //   freopen("input.txt", "r", stdin);
// //   cin >> n >> m;
// //   for (int i = 0; i < n; i++) {
// //     for (int j = 0; j < m; j++) {
// //       cin >> map[i][j];
// //     }
// //   }
// //
// //   for (int i = 0; i < n; i++) {
// //     for (int j = 0; j < m; j++) {
// //       sol(i, j);
// //     }
// //   }
// //
// //   return 0;
// // }
//
// // #include <iostream>
// // using namespace std;
// //
// // int n,m, start_r, start_c;
// // char map[51][51];
// // int dx[4] = {0, 0, 1, -1};  // 동 서 남 북
// // int dy[4] = {1, -1, 0 ,0};
// // bool isVisited[51][51], isDirected[5];
// //
// // void dfs (int r, int c, int ret, int dir) {
// //   start_r = r;
// //   start_c = c;
// //
// //   for (int i = 0; i < 4; i++) {
// //     int nr = r + dx[i];
// //     int nc = c + dy[i];
// //
// //     if (nr < 0 || nc < 0 || nr >= n || nc >= m || isVisited[nr][nc]) {
// //       continue;
// //     }
// //     cout << "nr, nc  : " << nr << ", " << nc << endl;
// //
// //
// //   }
// //
// //
// // }
// //
// //
// // int main(int argc, char const *argv[]) {
// //   freopen("input.txt", "r", stdin);
// //   cin >> n >> m;
// //   for (int i = 0; i < n; i++) {
// //     for (int j = 0; j < m; j++) {
// //       cin >> map[i][j];
// //     }
// //   }
// //
// //   for (int i = 0; i < n; i++) {
// //     for (int j = 0; j < m; j++) {
// //       cout << map[i][j] << " ";
// //     }
// //     cout << endl;
// //   }
// //
// //   for (int i = 0; i < n; i++) {
// //     for (int j = 0; j < m; j++) {
// //       for (int k = 0; k < 4; k++) {
// //         int nr = i + dx[k];
// //         int nc = j + dy[k];
// //         if (!isVisited[i][j]) {
// //           dfs(i, j, 0, k);
// //       }
// //       }
// //     }
// //   }
// //
// //   return 0;
// // }
