read -p "Enter the radius value: " r
clear
for((i=0; i<=360; i++)); do
	th1=`echo "scale=3; 3.14/180*$i"|bc|awk '{print cos($1)}'`
	x=`echo "scale=3; $r*$th1"|bc|awk '{print int($1)}'`
	th2=`echo "scale=3; 3.14/180*$i"|bc|awk '{print sin($1)}'`
	y=`echo "scale=3; $r*$th2"|bc|awk '{print int($1)}'`
	x=$((5+x))
	y=$((20+y))
	tput cup $x $y
	echo "*"
done