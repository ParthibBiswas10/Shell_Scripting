gcd(){
    a=$1
    b=$2
   
    while [ $b -ne 0 ]
    do
        temp=$b
        b=$((a%b))
        a=$temp
    done
    echo $a

}
lcm(){

    a=$1
    b=$2
    ans=$(((a*b)/$(gcd $a $b)))
    echo $ans
}

read -p "Enter first number: " a
read -p "Enter second number: " b
echo "GCD is: $(gcd $a $b)"
echo "LCM is: $(lcm $a $b)"