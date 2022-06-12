#!/usr/bin/env python3

# This code is far, far to sketchy to be used in practice.
# However, it is crafted this way to make a point.

# Also: This code assumes there is a file named 
# "to_be_imported.py" in the current directory. You can
# create such a file by constructing a symbolic link
# to this name from one of the _BAD, _BETTER, or _BEST variants.

print("BEFORE THE IMPORT")
import to_be_imported
print("AFTER THE IMPORT")

def main():
    print("-" * 40)

    print("Alone. So alone.")

    to_be_imported.some_function()

    print("Within 'using.py':", to_be_imported.SOME_VAR)

if __name__ == "__main__":
    main()
