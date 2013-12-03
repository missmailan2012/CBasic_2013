all: extab.run
extab.run: tn1.o singly_linked_list.o
	gcc tn1.o singly_linked_list.o -o extab.run
tn1.o: tn1.c
	gcc -c tn1.c
push: clean
	git push
pull: clean
	git pull
clean:
	rm -rf *o *.run *~ *.a *.out
shutdown:
	sudo shutdown now
nhap:
	gcc nhap.c -o nhap.run
reboot:
	git add . && git push && sudo reboot
stack_temp: stack_temp.run
stack_temp.run: singly_linked_list.o stack.o stack_temp.o
	gcc singly_linked_list.o stack.o stack_temp.o -o stack_temp.run 
singly_linked_list.o: singly_linked_list.c singly_linked_list.h
	gcc -c singly_linked_list.c
stack.o: stack.c
	gcc -c stack.c
