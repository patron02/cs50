from cs50 import get_int

while True:
    height = get_int("what height will your stairs be?\n")
    if height >= 1 and height <= 8:
        break
    
for i in range(height):
    print((height - 1 - i) * " ", end="")
    print("#" * (i + 1))



        
