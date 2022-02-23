// https://youtu.be/4VSjkEhZ2yA

class Solution {
  public:
    long long stoll(string s){
        long long ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            ans = ans * 10;
            ans += (s[i] - '0');
        }
        return ans;
    }
    
    long long smallestNumber(long long num) {
      if (num < 0) {
        num = num * -1; // make the number positive
        string s;

        while (num) {
          int rem = num % 10;
          s += to_string(rem);
          num /= 10;
        }

        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());

        return stoll(s) * -1;
      }

      string s;

      while (num) {
        int rem = num % 10;
        s += to_string(rem);
        num /= 10;
      }

      sort(s.begin(), s.end());

      if (s[0] != '0')
        return stoll(s);

      int i = 0;
      while (s[i] == '0') {
        i++;
      }

      swap(s[0], s[i]);

      return stoll(s);
    }
};