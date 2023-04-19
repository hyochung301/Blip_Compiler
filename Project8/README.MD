A compiler built with C++
The compiler can parse a text file, read in commands, and execute the Blip program in polish notation (using recursion and binary tree).
Commands implemented included variable assignments, arithmetic operations, conditionals, and loops.

**text statements** result in a text message being displayed on the screen. The text message
can be either a single word, or a quoted string. The following are examples of legal text
statements
```
text Hello
text "Hello World"
```

**output statements** result in a number being displayed on the screen. The number
displayed is the result of evaluating any legal Blip expression. For now, Blip only
supports integer variables, and so only integer values can be displayed. The following are
examples of output statements. For more information on Blip expressions, see below
```
output 42
output + 1 1 output * x x
output + * x x * y y
```

**var statements** initialize a new variable. The variable must be set to the value of a legal
Blip expression. The syntax is: “var <varName> <expr>”. The following are
examples of legal var expressions
  
```
var x 42 var y + x 1
```
  
**set statements **are just like var statements, except a set statement should be used to
re-assign a new value to an existing variable. The following are
examples of legal set expressions

```
set x 42 set x + x 1
```

# Usage
To execute the compiler, use set_input() command with .blip file, and execute it with run() command.
The following is the example usage of the compiler. 

```
set_input("test_grader.blip");
run();
```
