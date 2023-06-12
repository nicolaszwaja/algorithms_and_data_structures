TEXT_FILES = 1_23.txt 2_3.txt 3_8.txt 4_1000.txt 5_500.txt 6_2.txt 7_31.txt 8_5041.txt

all: $(TEXT_FILES)
$(TEXT_FILES): %: vaults
	./vaults < $@

vaults: Vaults.cpp
	g++ -o vaults Vaults.cpp

clean:
	rm -f vaults $(TEXT_FILES)
