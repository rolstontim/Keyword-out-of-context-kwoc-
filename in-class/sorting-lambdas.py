#!/usr/bin/env python3

li = [("Harry", 70), ("Elizabeth", 65), ("Jacob", 10), ("Anne", 17)]
print("Unsorted:")
print(li)
print("-" * 40)

li.sort()
print("Sort, default:")
print(li)
print("-" * 40)

li.sort(key = lambda t: t[1])
print("Sort, on integer:")
print(li)
print("-" * 40)

li.sort(key = lambda t: (len(t[0]), t[0]))
print("Sort, on length of string, tie-break on lexicographic order.")
print(li)
print("-" * 40)
