echo "FACTORIAL OF A GIVEN NUMBER"
echo "ENTER THE NUMBER"
read num
i=1
fact=1
while [ $i -le $num ]
do
fact=$(($fact * $i))
i=$(($i + 1))
done
echo "FACTORIAL OF $num IS $fact"
