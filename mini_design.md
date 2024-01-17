# Mini Design Document

## Tech Stack
The computations for the Mandelbrot set will use C++ and likely CUDA for parallel processing. Part of the reason for this is that GPU-based computation would likely speed up processing for hundreds or thousands of pixels at once. More importantly though, I want to. This program is more than anything an exercise for me to hone my C++ skills and to learn CUDA and parallel processing.


Some viable options to develop the GUI include using a framework such as QT or .NET, or interfacing with a different programming language that is easier to work with.

## Computing the Mandelbrot set

The Mandelbrot set is a set of complex numbers $c$ such that the absolute value of the sequence $z_{n+1} = z_n +  c$ does not converge to infinity when $z_0 = 0$.


Since this is an infinite sequence, the algorithm to check whether a point is in the mandelbrot set or not is only an approximation. The escape-time algorithm, which is a commonly used, does this by iterating a 
complex number through the recurrence a set number of times to see if it converges to infinity. If it does not, it is assumed to be a part of the Mandelbrot set.
If the absolute value of any $z$ is over 2, then that point is guaranteed to converge to infinity.


Pseudocode:
```
Mandelbrot(complex c, int max_iterations)
  z := 0
  for i in 0 to max_iterations:
    z := z^2 + c
    if abs(z) > 2
      return i
    i := i + 1
  return infinity
```

I will be referring to the series for each complex number as its trajectory for the rest of this document.

### Alternative algorithms

**Bhuddabrot** - This is an alternative visualization of the Mandelbrot set. It works by plotting a density distribution of pixels in random trajectories that converge to infinity. I might implement this if I feel like it.

**Derivative Bailout** - Accumulates the derivatives at each Z value. If this sum reaches a bailout value, the starting number is not in the set. This method is particularly useful for Julia Sets, which are related to the Mandelbrot set.

## Design Considerations

### Interactivity
The user should be able to pan and zoom into the Mandelbrot set. One particular consideration is that as the user zooms, more detail, and therefore more iterations may be required.

### Coloring
Rather than having two colors, one for points in the Mandelbrot set and points outside, coloring each point based on how many iterations they take to escape reveals some additional interesting structure.

### Optimizations
Computations for the entire screen could be sped up using parallel processing using a GPU. CUDA or OpenCL would be useful for this.
