#include <functional>
#include <iostream>
#include <vector>

class ICommand {
public:
  virtual ~ICommand() {}
  virtual void Execute() const = 0;
};

class SimpleCommand : public ICommand {
private:
  void *obj_;
  std::function<void()> func_;

public:
  template <typename T>
  SimpleCommand(void *object, void (T::*func)()) : obj_(object) {
    func_ = std::bind(func, static_cast<T *>(obj_));
  }

  void Execute() const override { func_(); }
};

class Foo {
public:
  int count_ = 0;

  void Add() { count_++; }
  void Print() { std::cout << "count = " << count_ << "\n"; }
};

class Executor {
public:
  std::vector<ICommand *> commands;

  void ExecuteAll() {
    for (auto &command : commands) {
      (*command).Execute();
    }
  }
};

int main() {
  Foo foo;

  SimpleCommand add_command((void *)&foo, &Foo::Add);
  SimpleCommand print_command((void *)&foo, &Foo::Print);

  Executor e;
  e.commands.push_back(&print_command);
  e.commands.push_back(&add_command);
  e.commands.push_back(&print_command);
  e.commands.push_back(&add_command);
  e.commands.push_back(&add_command);
  e.commands.push_back(&print_command);

  e.ExecuteAll();

  return 0;
}