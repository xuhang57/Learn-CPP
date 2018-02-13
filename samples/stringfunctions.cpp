// Copyright 2017 EC327/Carruthers jbc@bu.edu

// stringfunctions solution
// error  output  is coded as follows:

// w - is_word
// p - is_palindrome
// a - add
// c - convertbase
// m - multibase

#include <iostream>
#include <string>
using std::string;
using std::cerr;
using std::cout;
using std::cin;

bool islower(char c) {
  return c - 'a' >= 0 and c - 'a' <= 25;
}

bool isupper(char c) {
  return c - 'A' >= 0 and c - 'A' <= 25;
}

bool isdigit(char c) {
  return c - '0' >= 0 and c - '0' <= 9;
}

bool is_word(string s) {
  // empty is not a word
  if (s.empty()) return false;

  // check for all letters
  for (auto c : s) {
    if (not islower(c) and not isupper(c)) return false;
  }

  // one letter is a word
  if (s.size() == 1) return true;

  // check lower
  if (islower(s[0])) {
    for (auto c : s)
      if (not islower(c)) return false;
    return true;
  } else {  // upper or capital, 2 thru n must match
    bool match = islower(s[1]);
    for (int i = 2; i < s.size(); i++)
      if (islower(s[i]) != match) return false;
  }
  return true;
}

bool reversible(string num) {
  for (int i = 0, j = num.size() - 1; i < j; i++, j--)
    if (num[i] != num[j]) return false;
  return true;
}
bool is_palindrome(string num, bool * error) {
  *error = true;
  // check for error conditions
  if (num.empty() or (num[0] == '0' and num.size() > 1) )
    return false;

  // check for digits
  for (auto c : num)
    if (not isdigit(c))
      return false;

  // no errors, lets check palindromicity
  *error = false;
  return reversible(num);
}


void equalize(string *a, string *b, const string&num1, const string& num2) {
  int diff = num1.size() - num2.size();
  if (diff > 0) {
    *a = num1;
    *b = string(diff, '0') + num2;
  } else if (diff < 0) {
    *a = num2;
    *b = string(-diff, '0') + num1;
  } else {
    *a = num1;
    *b = num2;
  }
}

string add(const string& num1, const string& num2) {
  string a, b;
  equalize(&a, &b, num1, num2);
  string result(b.size(), '0');
  int carry = 0;
  int digit;
  for (int i = a.size() - 1; i >= 0; i --) {
    digit = a[i] + b[i] - '0' - '0' + carry;
    carry = digit / 10;
    digit = digit % 10;
    result[i] += digit;
  }
  if (carry)
    result = "1" + result;

  return result;
}


string convertbase(const string& numstr, const int frombase, const int tobase) {
  // num is a string in base frombase.
  // return the same number as a string in tobase
  // each digit is represented by the ASCII character digitvalue+'0'
  int number = 0;
  int factor = 1;
  for (int i = numstr.size() - 1; i >= 0; i--) {
    number += (numstr[i] - '0') * factor;
    factor *= frombase;
  }
  string s;
  char digit;
  while (number > 0) {
    digit = (number % tobase) + '0';
    number /= tobase;
    s = digit + s;
  }
  return s;
}

string multibase(int x) {
  // return all the bases in which x is palindromic, from 2 to x-1 inclusive
  // each palindromic base should be separated from the previous one by a space
  string s = std::to_string(x);
  string result;
  for (int base = 2; base < x; base++) {
    if (reversible(convertbase(s, 10, base)))
      result += std::to_string(base) + " ";
  }
  return result.substr(0, result.size() - 1);
}

// leave this line and everything below as is
int main() {
  bool error;

  cout << std::boolalpha;

  cout << "Quick Examples\n";
  cout << "Word: " << is_word("Test") << "\n";
  cout << "Pal: " << is_palindrome("123456777654321", &error) << "\n";
  cout << "Add: " << add("123", "456") << "\n";
  cout << "Convert: " << convertbase("1111", 2, 4) << "\n";
  cout << "Multi: " << multibase(21) << "\n";

  cout << "Now running basic tests, errors printed to stderr.\n";
  cerr << std::boolalpha;

  // is_word basic tests
  if (not is_word("test")) cerr << "we1\n";
  if (not is_word("Test")) cerr << "we2\n";
  if (not is_word("TEST")) cerr << "we3\n";
  if (not is_word("thisisaword")) cerr << "we4\n";

  if (is_word("123")) cerr << "we5\n";
  if (is_word("")) cerr << "we6\n";
  if (is_word("abc123abc")) cerr << "we7\n";
  if (is_word("tEst")) cerr << "we8\n";
  if (is_word("tEst")) cerr << "we9\n";
  if (is_word("TESTer")) cerr << "we10\n";


  // is_palindrome basic tests
  if (not is_palindrome("12321", &error) or error) cerr << "pe1\n";
  if (not is_palindrome("9009", &error) or error) cerr  << "pe2\n";
  if (not is_palindrome("9", &error) or error)  cerr << "pe3\n";
  if (not is_palindrome("123456777654321", &error) or error) cerr << "pe4\n";

  if (is_palindrome("abcba", &error) or not error) cerr << "pe5\n";
  if (is_palindrome("12321 a", &error) or not error) cerr << "pe6\n";
  if (is_palindrome("0012100", &error) or not error) cerr << "pe7\n";

  if (is_palindrome("123", &error) or error) cerr << "pe8\n";
  if (is_palindrome("123211", &error) or error) cerr << "pe9\n";
  if (not is_palindrome("0", &error) or error)  cerr << "pe10\n";

  // add basic tests
  if (add("123", "456") != "579") cerr << "ae1\n";
  if (add("123", "4") != "127") cerr << "ae2\n";
  if (add("1234", "9") != "1243") cerr << "ae3\n";
  if (add("88", "12") != "100") cerr << "ae4\n";
  if (add("1234567890123456789", "10000000000000999")
      != "1244567890123457788") cerr << "ae5\n";

  string longone(120, '2');
  longone[0] = '3';
  string longother(123, '1');
  longother[0] = '4';
  longother[3] = '2';
  string longresult(123, '3');
  longresult[0] = '4';
  longresult[1] = '1';
  longresult[2] = '1';
  longresult[3] = '5';

  if (add(longone, longother) != longresult ) cerr << "ae6\n";

  // convertbase tests

  if (convertbase("1111", 2, 10) != "15" ) cerr << "ce1\n";
  if (convertbase("255", 10, 16) != "??")  cerr << "ce2\n";
  if (convertbase("755", 8, 2) != "111101101") cerr << "ce3\n";

  if (convertbase("987123", 30, 30) != "987123" ) cerr << "ce4\n";
  if (convertbase("azbc", 100, 10) != "49745051") cerr << "ce5\n";

  if (convertbase("azbc", 100, 2) != "10111101110000110010011011")
    cerr << "be6\n";

  // multibase tests

  if (multibase(121) != "3 7 8 10 120") cerr << "me1\n";
  if (multibase(45) != "2 8 14 44") cerr << "me2\n";
  if (multibase(63) != "2 4 8 20 62") cerr << "me3\n";
  if (multibase(10) != "3 4 9") cerr << "me4\n";

  string asktype;
  bool res;
  string userinput, num1, num2;
  int mbase, frombase, tobase;



  while (cin >> asktype) {
    if (asktype == "w") {  // is_word
      std::cin >> userinput;
      cout << is_word(userinput) << "\n";
    } else if (asktype == "p") {  // p - is_palindrome
      std::cin >> userinput;
      res = is_palindrome(userinput, &error);
      cout << res << " " << error << "\n";
    } else if (asktype == "a") {  // a - add
      std::cin >> num1 >> num2;
      cout << add(num1, num2) << "\n";
    } else if (asktype == "c") {  // c - convertbase
      std::cin >> userinput >> frombase >> tobase;
      cout << convertbase(userinput, frombase, tobase) << "\n";
    } else if (asktype == "m") {  // m - multibase
      std::cin >> mbase;
      cout << multibase(mbase) << "\n";
    } else {
      return 0;
    }
  }

  return 0;
}
