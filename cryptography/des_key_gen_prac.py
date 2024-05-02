def hex_to_bin(hex_string):
    return ''.join(format(int(c, 16), '04b') for c in hex_string)
    
def bin_to_hex(bin_string):
    return hex(int(bin_string, 2))[2:]
    
def permute(input_key, permutation_table, length):
    return ''.join(input_key[i-1] for i in permutation_table[:length])
    
def left_shift(input_key, n_shifts):
    return input_key[n_shifts:]+input_key[:n_shifts]
    
def key_schedule(base_key, parity_drop_table, shift_table, key_compression_table):
    key = permute(base_key, parity_drop_table, 56)
    
    left = key[:28]
    right = key[28:]
    
    round_keys = []
    
    for i, shift in enumerate(shift_table):
        left = left_shift(left, shift)
        right = left_shift(right, shift)
        
        combined_key = left + right
        round_key = permute(combined_key, key_compression_table, 48)
        
        round_keys.append(round_key)
        
    return round_keys

parity_drop_table = [57, 49, 41, 33, 25, 17, 9,
                         1, 58, 50, 42, 34, 26, 18,
                         10, 2, 59, 51, 43, 35, 27,
                         19, 11, 3, 60, 52, 44, 36,
                         63, 55, 47, 39, 31, 23, 15,
                         7, 62, 54, 46, 38, 30, 22,
                         14, 6, 61, 53, 45, 37, 29,
                         21, 13, 5, 28, 20, 12, 4]

# parity drop table is the key permutation table
    
    # Number of bit shifts
shift_table = [1, 1, 2, 2,
                2, 2, 2, 2,
                1, 2, 2, 2,
                2, 2, 2, 1]

# Key- Compression Table : Compression of key from 56 bits to 48 bits
key_compression_table = [14, 17, 11, 24, 1, 5,
                            3, 28, 15, 6, 21, 10,
                            23, 19, 12, 4, 26, 8,
                            16, 7, 27, 20, 13, 2,
                            41, 52, 31, 37, 47, 55,
                            30, 40, 51, 45, 33, 48,
                            44, 49, 39, 56, 34, 53,
                            46, 42, 50, 36, 29, 32]

base_key = "AAAABBBBCCCCDDDD" #64 bit key

bin_key = hex_to_bin(base_key)

round_keys = key_schedule(bin_key, parity_drop_table, shift_table, key_compression_table)

for i, key in enumerate(round_keys):
    print(f"Round {i+1} key = {bin_to_hex(key)}")

    