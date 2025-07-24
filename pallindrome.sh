
read -p "Enter Number: " num
reverse=0
original=$num
while [ $num -gt 0 ]
do
    reverse=$((reverse*10 + num%10))
    num=$((num/10))
done
if [ $original -eq $reverse ]
then
    echo "$original is Palindrome"
else 
    echo "Not Palindrome"
fi