from cs50 import get_int

def main():
    while True:
        height = get_int("Positive height - ")
        width = height + 1
        if height >= 0 and height <= 23:
            break

    for i in range(1, height + 1):
        hash_num = i
        space_num = width - hash_num

        print(" " * space_num, end = " ")
        print("#" * hash_num)


if __name__ == "__main__":
    main()