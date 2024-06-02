echo "ENTER THE NUMBER"
read n
r=$(($n % 2))
if [ $r -eq 0 ]
then
echo "EVEN"
else
echo "ODD"
fi
