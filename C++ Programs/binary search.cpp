int binarySearch(int values[], int len, int target)
{
    int max = (len - 1);
    int min = 0;
    int guess;  
    int step = 0; 
    while(max >= min)
    {
        guess = (max + min) / 2;
        step++;
        if(values[guess] ==  target)
        {
            printf("Number of steps required for search: %d \n", step);
            return guess;
        }
        else if(values[guess] >  target) 
        {
            max = (guess - 1);
        }
        else
        {
            min = (guess + 1);
        }
    }
    return -1;
}
int main(void)
{
    int values[] = {13, 21, 54, 81, 90};
    int n = sizeof(values) / sizeof(values[0]);
    int target = 81;
    int result = binarySearch(values, n, target);
    if(result == -1)
    {  
        printf("Element is not present in the given array.");
    }
    else
    {
        printf("Element is present at index: %d", result);
    }
    return 0;
}




//Expression: log2(n)
//- - - - - - - - - - - - - - -
//For n = 2:
//log2(21) = 1
//Output = 1
//- - - - - - - - - - - - - - -
//For n = 4
//log2(22) = 2
//Output = 2
//- - - - - - - - - - - - - - -
//For n = 8
//log2(23) = 3
//Output = 3
//- - - - - - - - - - - - - - -
//For n = 256
//log2(28) = 8
//Output = 8
//- - - - - - - - - - - - - - -
//For n = 2048
//log2(211) = 11
//Output = 11


