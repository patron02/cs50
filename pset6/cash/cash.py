from cs50 import get_float

#prompt for answer
while True:
    change = get_float("how much change is owed?\n")
    if change >= 0:
        break

#define coins and cents
cents = round(change * 100)
coins = 0
denominations = [25, 10, 5, 1]

#print
for denom in denominations:
    coins += cents // denom
    cents %= denom
print(coins)
