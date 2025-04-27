int readNumber(const char* message);
void writeAnswer(int ans);

int main() {

  int num1 { readNumber("Enter a number: ") };
  int num2 { readNumber("Enter another number: ") };

  writeAnswer(num1 + num2);

  return 0;
}
