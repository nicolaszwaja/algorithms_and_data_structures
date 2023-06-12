# Lista plików tekstowych, z którymi chcesz wywołać program

TEXT_FILES = 1_23.txt 2_3.txt 3_8.txt 4_1000.txt 5_500.txt 6_2.txt 7_31.txt 8_5041.txt

# Reguła domyślna

all: $(TEXT_FILES)
$(TEXT_FILES): %: vaults
	./vaults < $@

# Reguła kompilacji programu

vaults: Vaults.cpp
	g++ -o vaults Vaults.cpp

# Reguła czyszczenia

clean:
	rm -f vaults $(TEXT_FILES)