int gcd(int x,int y){
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

