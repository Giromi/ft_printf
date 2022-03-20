echo "@@@@@@@@@@ printf @@@@@@@@@@"
cp main_ft_printf.c main_printf.c
sed -i "" 's/ft_printf/printf/g' main_printf.c
echo
gcc main_printf.c -Ilibft/ -Imandatory -o printf.out
./printf.out > printf.txt
grep -aw "cnt" printf.txt
echo
#head -c 20 printf.txt | cat -e
echo
#grep -aw "abc" printf.txt
#cat -e printf.txt

