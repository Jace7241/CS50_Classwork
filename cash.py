from cs50 import get_float
from math import floor


def main():
    while True:
        change = get_float("Amount owed - ")
        total = floor(change * 100)

        if total > 0:
            break
# Quarter total
    Q = total // 25  # Quarter
    D = (total % 25) // 10  # Dime valu total
    N = ((total % 25) % 10) // 5  # Nickel total
    P = ((total % 25) % 10) % 5  # penny total (whats left_)
# Total coints at all
    print(f"{Q + D + N + P}")


# run program
if __name__ == "__main__":
    main()