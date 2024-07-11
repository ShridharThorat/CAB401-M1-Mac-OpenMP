//
//  main.cpp
//  test
//
//  Created by Shridhar Thorat on 11/7/2024.
//

#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){
    #pragma omp parallel num_threads(5)
    {
        printf("Hello from process: %d\n", omp_get_thread_num());
    }
    return 0;
}
