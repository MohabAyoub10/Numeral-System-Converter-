#include <bits/stdc++.h>

using namespace std;

int main() {
  string no, out;
  double x = 0;
  int y = 0;
  bool f = 0;
  cout << "Enter the base of your input\n";
  int inbase;
  cin >> inbase;
  cout << "Enter the number\n";
  cin >> no;
  for (int i = 0; i < no.size(); i++) {
    if (no[i] == '.') {
      f = 1;
      for (int j = i + 1, k = -1; j < no.size(); j++, k--) {
        if (no[j] <= 9 + 48)
          x += (no[j] - 48) * pow(inbase, k);

        else
          x += (no[j] - 55) * pow(inbase, k);

      }

      for (int j = i - 1, k = 0; j >= 0; j--, k++) {
        if (no[j] <= 9 + 48)
          y += (no[j] - 48) * round(pow(inbase, k));
        else
          y += (no[j] - 55) * round(pow(inbase, k));
      }
    } else if (i == no.size() - 1 && f == 0) {
      for (int j = i, k = 0; j >= 0; j--, k++) {
        if (no[j] <= 9 + 48)
          y += (no[j] - 48) * round(pow(inbase, k));
        else
          y += (no[j] - 55) * round(pow(inbase, k));

      }

    }
  }

  cout << "Enter the base of your output\n";
  int base;
  cin >> base;

  while (y > 0) {
    if (y % base <= 9)
      out += to_string(y % base);
    else {
      out += y % base + 55;
    }
    y /= base;
  }

  reverse(out.begin(), out.end());
  if (f == 1) {
    out += '.';
    double z = x;
    while (1) {
      if (int(z * base) <= 9) {
        out += to_string(int(z * base));
      } else {
        out += int(z * base) + 55;
      }
      z = z * base - int(z * base);
      if (z * base - int(z * base) == 0) {
        out += to_string(int(z * base));
        break;
      }
    }
  }
  cout << out;

}
