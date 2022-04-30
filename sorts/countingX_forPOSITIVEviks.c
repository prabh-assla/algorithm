#include <stdio.h>

int getMax(int arr[], const size_t n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countX(int n, int inpt_arr[n]){

    int max = getMax(inpt_arr, n);

    const size_t freqSize = max + 1;
    int frequency[freqSize];

    for (int i = 0; i < freqSize; ++i)
        frequency[i] = 0;

    // inpt_arr[] = {1, 3, 0, 6, 9, 8}
    // frequency[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

    // Now, counting the frequency of an element's occurance

    for(int i = 0; i<n; i++)
        ++frequency[inpt_arr[i]];

    // frequency[] = {1, 1, 0, 1, 0, 0, 1, 0, 1, 1}

    // Now finding the commulative sum
    // But Why!?
    // 1. It's helping us assign the index to the number
    // 2. if the next frequency is 0, it just get's passed on
    // 3. that's how we keep track of next index

    for(int i = 1; i < freqSize; i++)
        frequency[i] += frequency[i - 1];

    // frequency[] = {1, 2, 2, 3, 3, 3, 4, 4, 5, 6}
    // Now, this gave us the index of the numbers starting from 1
    // That's why we are subtracting 1 below to shift it left 1 step
    //
    // Actually, now it would be more appropriate to call it 
    // indexes[] or address[] instead of frequency[]
    //
    // we can think of the algorithm as:
    //
    // 1. traverse through inpt_arr[]
    // 2. take current element
    // 3. search it's position from frequency[]
    // 4. place it in outpt_arr[]
    // 4. decrement the value of frequency[cur] so that next
    //    time when asked for the same number, it fills
    //    the number to the left of the previously placed index
    //    and the data is not over-written
    // 5. goto 1 if not end

    int outpt_arr[n]; 

    // from 0 to n-1
    //
    // cur = inpt_arr[0] = 1
    // index = frequency[cur]-1 = 1
    // outpt_arr[index] = cur
    // outpt_arr[1] = 1
    //
    // frequency[] = {1, 1, 2, 3, 3, 3, 4, 4, 5, 6}
    // outpt_arr[] = {0, 1, 0, 0, 0, 0}
    //
    // cur = 3
    // index = 2
    // outpt_arr[index] = cur
    // outpt_arr[2] = 3
    //
    // frequency[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6}
    // outpt_arr[] = {0, 1, 3, 0, 0, 0}
    //
    // cur = 0
    // index = 0
    // outpt_arr[index] = cur
    // outpt_arr[0] = 0
    //
    // frequency[] = {0, 1, 2, 2, 3, 3, 4, 4, 5, 6}
    // outpt_arr[] = {0, 1, 3, 0, 0, 0}
    //
    // So on and so forth...

    for(int i = 0; i<n; i++){

        int cur = inpt_arr[i];
        int index = frequency[cur] - 1;

        outpt_arr[index] = cur;
        --frequency[cur];
    }

    // why subtract index
    //
    // if you had similiar elements
    //
    // like arr = {3, 1, 1}
    // then freq = {0, 2, 2, 3}
    //
    // then
    //
    // output[freq[arr[0]] - 1] = 3  -> output[2] = 3
    // output[freq[arr[1]] - 1] = 1  -> output[1] = 1
    // output[freq[arr[2]] - 1] = 1  -> output[0] = 1
    //
    // had we not decremented the value, the next number
    // with the same value would have over-written the value
    //
    // Also note, we can forget what other indexes are in freq
    // other than number we require
    //
    // like, freq can also be {1213, 2, 332233, 3}
    // doesn't matter
    //
    // as long as the number we are searching for are in correct order
    
    for(int i=0; i<n; i++)
        inpt_arr[i] = outpt_arr[i];
}

int main() {

    int arr[] = {1, 3, 0, 6, 9, 8};
    const size_t n = sizeof(arr) / sizeof(arr[0]);

    countX(n, arr);

    for(int i=0; i<n; i++)
        printf("%d  ", arr[i]);

    return 0;
}
