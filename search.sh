search(){
    key=$1
    shift
    arr=("$@")
    echo ${arr[@]}
    for((i=0;i<${#arr[@]};i++));do
        if [ ${arr[i]} -eq ${key} ];then
            echo "${key} present in $((i+1)) position"
            return 
        fi
    done
    echo "Not Present"
    return 0

}
read -p "Enter numbers separated by spaces: " -a nums
read -p "Enter key to Search:: " key
search $key ${nums[@]}