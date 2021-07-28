# Command Pattern in C++

Using this pattern in C++, we can call a function without knowing its exact type beforehand. And based on that, we can decoupling a higher level procedural and the steps within it.

For example, we can extract the way of how a iterator traverses elements, and reuse that way on other elements regardless the types of the element, WITHOUT the needs to implement a `Iterable` interface.

I find this handy for making multiple wrappers with similar functionality, while the wrappee is so different from each other.

## The gist of the demo code

+ The `Executor` Class got the "higher level procedural"
+ The `Foo` Class got those "steps"
+ The `SimpleCommand` stores the object and the function pointer, because ["the member pointer will have to be used together with an object of its class"](https://stackoverflow.com/a/2402607).