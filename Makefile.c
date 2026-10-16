a.out : main.o defines_push_pop.o infix_postfix.o
        gcc main.o defines_push_pop.o infix_postfix.o -o a.out
main.o : main.c
        gcc -c main.c
defines_push_pop.o : defines_push_pop.c
        gcc -c defines_push_pop.c
infix_postfix.o : infix_postfix.c
        gcc -c infix_postfix.c
