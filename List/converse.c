void converse(int num, int ary)
{
    if (num / ary == 0) {
        printf("%d", num % ary);
        return;
    }
    converse(num / ary, ary);
    printf("%d", num % ary);
}
