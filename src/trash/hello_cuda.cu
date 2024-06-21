// hello_cuda.cu
#include <stdio.h>

__global__ void hello_cuda() {
    int a = 0;
    while(true){
        a = 100/3;
    }

}

int main() {
    // Launch kernel
    hello_cuda<<<1, 1>>>();
    cudaDeviceSynchronize(); // Wait for the GPU to finish
    return 0;
}
