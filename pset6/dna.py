from sys import argv, exit
import csv

def get_max_sub(s, sub):
    #calculation for substrings
    #figure out max length of substrings
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    return max(ans)

def print_match(reader, actual):
    for line in reader:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == actual:
            print(person)
            return
    print("No match")
            
    
def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)
        
    csv_path = argv[1]
    with open(csv_path) as csv_file:
        reader = csv.reader(csv_file)
        #eliminate header, make continuous 
        all_sequences = next(reader)[1:]
        #calculate consecutive repetitions
        txt_path = argv[2]
        with open(txt_path) as txt_file:
            s = txt_file.read()
            actual = [get_max_sub(s, seq) for seq in all_sequences]
        print_match(reader, actual)
    
if __name__ == "__main__":
    main()
        
        
