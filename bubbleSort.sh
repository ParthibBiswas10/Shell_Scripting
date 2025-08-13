read -p "Enter numbers separated by space: " -a arr

n=${#arr[@]} 

echo "Original array: ${arr[@]}"

for ((i = 0; i < n-1; i++)); do
    for ((j = 0; j < n-i-1; j++)); do
        if (( arr[j] > arr[j+1] )); then
            # Swap
            temp=${arr[j]}
            arr[j]=${arr[j+1]}
            arr[j+1]=$temp
        fi
    done
done

echo "Sorted array:   ${arr[@]}"
