/*
* A sequential (CPU) implementation of the escape time algorithm to benchmark against the CUDA implementation for performance.
*/

#include "Seq_escape_time.hpp"

void sequential_escape_time(double* real, double* imaginary, int real_len, int imaginary_len, double** escape_time, int max_iter) {
	for (int real_idx = 0; real_idx < real_len; real_idx++) {
		for (int imaginary_idx = 0; imaginary_idx < imaginary_len; imaginary_idx++) {
			escape_time[real_idx][imaginary_idx] = point_escape_time(real[real_idx], imaginary[imaginary_idx], max_iter)
		}
	}
}

double point_escape_time(double real, double imaginary, int max_iter) {

}