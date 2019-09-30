# 05-constructor elision

This folder shows examples of copy- and move-constructor elision.
Basically this is when the compiler knows that a call to a copy-
or move-constructor is unnecessary, so it simply omits the call,
even if there are side-effects. It is an interesting thing to see
in action.

TODO(domfarolino): This is a tricky topic, so add links to some
resources, as elaborate in this README.
