echo "Enter 2 numbers : ";
read a 
read b
echo "Enter the choice 1.Addition 2.Subtraction 3.Multiplication 4.Divison";
read ch
case $ch in
1) let "r=a+b"
   echo "The result is : $r"
   ;;
2) let "r=a-b"
   echo "The result is : $r" 
   ;;
3) let "r=a*b"
   echo "The result is : $r"
   ;;
4) let "r=a/b"
   echo "The result is : $r"
   ;;
*) "wrong choice"
   ;;
esac
