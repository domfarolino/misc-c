# 05-constructor elision

This folder shows examples of copy- and move-constructor elision.
Basically this is when the compiler knows that a call to a copy-
or move-constructor is unnecessary, so it simply omits the call,
even if there are side-effects. It is an interesting thing to see
in action.

A really good stackoverflow post on this can be found
**[here](https://stackoverflow.com/questions/12953127)**.
