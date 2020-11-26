all:update run

.PHONY:all

update: ls.c rm.c date.c cat.c q2.c mkdir.c
		echo "Updating Files"
		gcc -o rm rm.c
		gcc -o ls ls.c
		gcc -o cat cat.c
		gcc -o date date.c
		gcc -o mkdir mkdir.c
		gcc -o q2 q2.c
run: q2
	echo "Running Shell"
	./q2