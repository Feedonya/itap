#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Printer {
public:
  virtual void print(int value) = 0;
};

class OstreamPrinter : public Printer {
private:
  ostream& out;
public:
  OstreamPrinter(ostream& out) : out(out) {}

  void print(int value) override {
    out << value << ' ';
  }
};

class Command {
public:
  virtual void execute(vector<stack<int>>& stacks) = 0;
};

class Push : public Command {
private:
  int stack_id;
  int value;
  Printer& printer;

public:
  Push(
    int stack_id, 
    int value, 
    Printer& printer
  ) : stack_id(stack_id), 
      value(value), 
      printer(printer) {}

  void execute(vector<stack<int>>& stacks) override {
    stacks[stack_id - 1].push(value);
  }

  int get_stack_id() const {
    return stack_id;
  }

  int get_value() const {
    return value;
  }
};

class PopCommand : public Command {
private:
  int stack_id;
  Printer& printer;

public:
  PopCommand(
    int stack_id, 
    Printer& printer
  ) : stack_id(stack_id), 
      printer(printer) {}

  void execute(vector<stack<int>>& stacks) override {
    printer.print(stacks[stack_id - 1].top());
    stacks[stack_id - 1].pop();
  }

  int get_stack_id() const {
    return stack_id;
  }
};

class TopCommand : public Command {
private:
  int stack_id;
  Printer& printer;

public:
  TopCommand(
    int stack_id, 
    Printer& printer
  ) : stack_id(stack_id), 
      printer(printer) {}

  void execute(vector<stack<int>>& stacks) override {
    printer.print(stacks[stack_id - 1].top());
  }

  int get_stack_id() const {
    return stack_id;
  }
};

class UnnableToParse : public exception {
public:
  string what() {
    return "Unnable to parse";
  }
};

class Parser {
private:
  Printer& printer;

  Push* parse_push(const string& cmd_str) {
    int stack_id, value;
    if (sscanf(cmd_str.c_str(), "PUSH(%d,%d)", &stack_id, &value) != 2) {
      throw UnnableToParse();
    }
    return new Push(stack_id, value, printer);
  }

  TopCommand* parse_top(const string& cmd_str) {
    int stack_id;
    if (sscanf(cmd_str.c_str(), "TOP(%d)", &stack_id) != 1) {
      throw UnnableToParse();
    }
    return new TopCommand(stack_id, printer);
  }

  PopCommand* parse_pop(const string& cmd_str) {
    int stack_id;
    if (sscanf(cmd_str.c_str(), "POP(%d)", &stack_id) != 1) {
      throw UnnableToParse();
    }
    return new PopCommand(stack_id, printer);
  }

public:
  Parser(Printer& printer) : printer(printer) {}

  Command* parse_command(const string& cmd_str) {
    if (cmd_str.substr(0, 4) == "PUSH") {
      return parse_push(cmd_str);
    }

    if (cmd_str.substr(0, 3) == "TOP") {
      return parse_top(cmd_str);
    }

    if (cmd_str.substr(0, 3) == "POP") {
      return parse_pop(cmd_str);
    }

    throw UnnableToParse();
  }
};

int main() {
  auto printer = OstreamPrinter(cout);
  auto parse = Parser(printer);
  
  int stacks_count, operations_count;
  cin >> stacks_count >> operations_count;
  cin.get();

  string line;
  vector<stack<int>> stacks(stacks_count);

  for (int i = 0; i < operations_count; i++) {
    getline(cin, line);
    auto command = parse.parse_command(line);
    command->execute(stacks);
    delete command;
  }

  for (stack<int>& s : stacks) {
    while (!s.empty()) {
      s.pop();
    }
  }
}