#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {

  // LIFO
  stack<char> testStack;
  testStack.push('a');
  testStack.push('b');
  testStack.push('c');
  testStack.push('d');
  testStack.push('e');

  cout << testStack.top() << endl;
  testStack.pop();
  cout << testStack.top() << endl;

  // FIFO
  queue<char> testQueue;
  testQueue.push('a');
  testQueue.push('b');
  testQueue.push('c');
  testQueue.push('d');
  testQueue.push('e');

  cout << testQueue.front() << endl;
  cout << testQueue.back() << endl;
  testQueue.pop();
  cout << testQueue.front() << endl;

  return 0;
}
