echo @@@@@@@@@@ ft_printf @@@@@@@@@@
make all
gcc main_ft_printf.c -Ilibft/ -Imandatory -L./ -lftprintf -o ft_printf.out
./ft_printf.out > ft_printf.txt
echo
grep -aw "cnt" ft_printf.txt
echo
#head -c 20 ft_printf.txt | cat -e
#grep -aw "abc" ft_printf.txt
#cat -e ft_printf.txt
