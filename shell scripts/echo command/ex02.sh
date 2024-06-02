echo "1. WHO AM I?"
echo "2. WHO IS LOGGED ON?"
echo "3. DATE"
read n

case $n in
    1) whoami ;;
    2) who ;;
    3) date ;;
    *) echo "Invalid choice. Please select 1, 2, or 3." ;;
esac
