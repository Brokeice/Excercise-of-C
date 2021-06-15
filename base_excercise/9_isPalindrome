bool isPalindrome(int x){
    int revertnumber = 0;

    if ((x < 0) || ((x % 10 == 0) && (x !=0)))
    {
        return false;
    }
    while (x > revertnumber)
    {
        revertnumber *= 10;
        revertnumber = revertnumber + x % 10;
        x /= 10;
        
    }
    if ((x == revertnumber) || (x == revertnumber / 10))
    {
        return true;
    }
    else 
    {
        return false;
    }       
}
