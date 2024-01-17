# Mini Design Document

## Computing the Mandelbrot set

The Mandelbrot set is a set of complex numbers $c$ such that the absolute value of the sequence $z_{n+1} = z_n +  c$ does not converge to infinity when $z_0 = 0$.

Since this is an infinite sequence, the algorithm to check whether a point is in the mandelbrot set or not is only an approximation. The escape-time algorithm, which is a commonly used, does this by iterating a complex number through the recurrence a set number of times to see if it converges to infinity. If it does not, it is assumed to be a part of the Mandelbrot set.
If the absolute value of any $z$ is over 2, then that point is guaranteed to converge to infinity.

Pseudocode:
```

```