from cs50 import get_float
from math import floor


def main():
    while True:
        change = get_float("Amount owed - ")
        total = floor(change * 100)

        if total > 0:
            break

    Q = total // 25
    D = (total%25) // 10
    N = ((total%25) % 10) // 5
    P = ((total%25) % 10) % 5

    print(f"{Q + D + N + P}")


if __name__ == "__main__":
    main()