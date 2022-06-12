SOME_VAR = 10

def some_function():
    SOME_VAR = 999

def main():
    print("Make some NOISE")
    SOME_VAR = 777
    print(SOME_VAR)
    print("Make even more NOISE")

if __name__ == "__main__":
    main()
