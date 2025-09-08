# Static Variable Demo Program in C

This program demonstrates how a static variable retains its value between function calls.

## How it works

1. The function `fuc` has a static variable `b` initialized to 34.  
2. Every time the function is called, it prints the current value of `b`.  
3. The variable `b` is then incremented by 4.  
4. Because `b` is static, it **does not reset** to 34 on subsequent calls.  
5. The program calls `fuc` three times to show how `b` changes with each call.

## How to use

1. Run the program.  
2. Observe the printed value of `b` for each function call.  
3. Notice how `b` keeps its previous value instead of resetting.