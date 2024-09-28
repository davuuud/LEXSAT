all:
	$(MAKE) -C "src/"
	mv src/lexsat .
clean:
	$(MAKE) -C "src/" clean
	rm lexsat
.PHONEY: all clean