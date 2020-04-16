# [1: Introduction][ci-introduction], Challenge 2

> Get a “Hello, world!” program written and running in Java. Set up whatever Makefiles or IDE projects you need to get it working. If you have a debugger, get comfortable with it and step through your program as it runs.
>
> **Do the same thing for C**. To get some practice with pointers, define a doubly-linked list of heap-allocated strings. Write functions to insert, find, and delete items from it. Test them.

I was able to get the ["Hello World" program][source-hello-world-c] working with the help of [RIP Tutorial][resource-hello-world-c].

I was able to get the [doubly-linked-list program][source-doubly-linked-list-c] working with the help of a few resources. Since I don't program in C, I got some [starter code from TutorialsPoint][resource-doubly-linked-list-sample-c]. I was able to edit the code for the most part, and removed the code that I didn't need there. I had to add two functions, and I looked up some resources about how to compile a C program. I had some issues with [copying strings][resource-copy-strings-c], [comparing strings][resource-compare-strings-c], and [printing strings][resource-printf-c] in C, and then "refactored" with a best practice that I found [to not cast the result of `malloc`][resource-cast-result-of-malloc-c].


[ci-introduction]: http://craftinginterpreters.com/introduction.html#challenges
[source-hello-world-c]: ./helloworld.c
[resource-hello-world-c]: https://riptutorial.com/c/example/795/hello-world
[source-doubly-linked-list-c]: ./doubly-linked-list.c
[resource-doubly-linked-list-sample-c]: https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_program_in_c.htm
[resource-compare-strings-c]: https://www.wikihow.com/Compare-Two-Strings-in-C-Programming
[resource-printf-c]: https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm
[resource-copy-strings-c]: https://stackoverflow.com/questions/20767524/doubly-linked-list-with-strings
[resource-cast-result-of-malloc-c]: https://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc/605858#605858
