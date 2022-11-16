arr[0]= "level1/"
arr[1]= "level2/"
arr[2]="level3/"
arr[3]="level4/"

RANDOM=$$$(date +%s)
rand=$[$RANDOM % ${#arr[@]}]

echo ${arr[$rand]}
