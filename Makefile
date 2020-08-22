CC = g++ -std=c++11

all: main.o bin_to_dec.o bin_to_hex.o compression_permutation.o dec_to_bin.o decrypt.o encrypt.o exor.o expansion_permutation.o final_permutation.o generate_key.o get_round_keys.o hex_to_bin.o initial_permutation.o key_parity_bit_drop.o key_shifting.o p_box_permutation.o permute.o s_box_substitution.o shift_left.o
	$(CC) main.o bin_to_dec.o bin_to_hex.o compression_permutation.o dec_to_bin.o decrypt.o encrypt.o exor.o expansion_permutation.o final_permutation.o generate_key.o get_round_keys.o hex_to_bin.o initial_permutation.o key_parity_bit_drop.o key_shifting.o p_box_permutation.o permute.o s_box_substitution.o shift_left.o 
main.o: main.cpp generate_key.h get_round_keys.h decrypt.o encrypt.h
	$(CC) -c main.cpp	
bin_to_dec.o: bin_to_dec.cpp bin_to_dec.h 
	$(CC) -c bin_to_dec.cpp
bin_to_hex.o: bin_to_hex.cpp bin_to_hex.h
	$(CC) -c bin_to_hex.cpp
compression_permutation.o: compression_permutation.cpp compression_permutation.h permute.h
	$(CC) -c compression_permutation.cpp
dec_to_bin.o: dec_to_bin.cpp dec_to_bin.h 
	$(CC) -c dec_to_bin.cpp	
decrypt.o: decrypt.cpp decrypt.h encrypt.h
	$(CC) -c decrypt.cpp	
encrypt.o: encrypt.cpp encrypt.h hex_to_bin.h bin_to_hex.h initial_permutation.h expansion_permutation.h exor.h s_box_substitution.h p_box_permutation.h final_permutation.h
	$(CC) -c encrypt.cpp
expansion_permutation.o: expansion_permutation.cpp expansion_permutation.h permute.h
	$(CC) -c expansion_permutation.cpp
exor.o: exor.cpp exor.h
	$(CC) -c exor.cpp
final_permutation.o: final_permutation.cpp final_permutation.h permute.h
	$(CC) -c final_permutation.cpp	
generate_key.o: generate_key.cpp generate_key.h
	$(CC) -c generate_key.cpp
get_round_keys.o: get_round_keys.cpp get_round_keys.h hex_to_bin.h bin_to_hex.h key_parity_bit_drop.h compression_permutation.h key_shifting.h
	$(CC) -c get_round_keys.cpp
hex_to_bin.o: hex_to_bin.cpp hex_to_bin.h
	$(CC) -c hex_to_bin.cpp
initial_permutation.o: initial_permutation.cpp initial_permutation.h permute.h
	$(CC) -c initial_permutation.cpp
key_parity_bit_drop.o: key_parity_bit_drop.cpp key_parity_bit_drop.h permute.h
	$(CC) -c key_parity_bit_drop.cpp
key_shifting.o: key_shifting.cpp key_shifting.h shift_left.h
	$(CC) -c key_shifting.cpp
p_box_permutation.o: p_box_permutation.cpp p_box_permutation.h permute.h
	$(CC) -c p_box_permutation.cpp
permute.o: permute.cpp permute.h
	$(CC) -c permute.cpp
s_box_substitution.o: s_box_substitution.cpp s_box_substitution.h bin_to_dec.h dec_to_bin.h
	$(CC) -c s_box_substitution.cpp
shift_left.o: shift_left.cpp shift_left.h 
	$(CC) -c shift_left.cpp		
clean:
	rm *.o
	rm a.out