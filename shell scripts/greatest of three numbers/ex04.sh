echo "ENTER THE VALUES:"
read a b c
if [ $a -gt $b ] && [ $a -gt $c ]
then
echo "$a IS GREATEST"
elif [ $b -gt $c ]
then
echo "$b IS GREATEST"
else
echo "$c IS GREATEST"
fi
