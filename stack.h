class Stack {
public:
  Stack();
  Stack(const Stack& b);
  int pop();
  void push(int elem);
  void multiPop(int N);
  void show();
  bool isEmpty();
  Stack& operator=(const Stack& b);
  ~Stack();
private:
  int* st;
  int size1;
};

