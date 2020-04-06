#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool sumsTo(uint32_t array[], uint32_t size, uint32_t num, uint32_t sum) {
    // if the sum is zero and the num is zero then true
    if(sum == 0 && num == 0){
        return true;
    }

    // sum was too high or there are too many numbers
    if((sum != 0 && num <= 0)||(size == 0)){
        return false;
    }

    // add the current last number to summ
    return sumsTo(array,size-1,num-1,sum-array[size-1]) ||
           // dont add current last number to sum
           sumsTo(array,size-1,num,sum);
}

int main(void) {
    uint32_t array[] = {1, 8, 6, 4, 3};
    uint32_t num = 3;// num of elements to create sum
    uint32_t sum = 9;
    uint32_t size = 5;

    printf(sumsTo(array,size,num,sum) ? "true\n" : "false\n");

    num = 2;
    sum = 9;
    printf(sumsTo(array,size,num,sum) ? "true\n" : "false\n");

    return 0;
}